#include "tilemap.h"

Tilemap::Tilemap() {
    std::srand(std::time({}));
    pos.absolute.x = 0;
    pos.absolute.y = 0;
    pos.relative.x = 0;
    pos.relative.y = 0;
}

std::vector<std::vector<int>> Tilemap::readCSV(const std::string& filename) {
    std::vector<std::vector<int>> data;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stoi(cell));
        }

        data.push_back(row);
    }

    file.close();
    return data;
}

void Tilemap::LoadAssets(int n) {
    for (int i = 1; i < n+1; i++) {
        Image image = LoadImage(TextFormat("textures/asset%i.png", i)); // Load image in CPU memory (RAM)
        Texture2D texture = LoadTextureFromImage(image); // Image converted to texture, uploaded to GPU memory (VRAM)

        assetMap.push_back(texture);

        UnloadImage(image);
    }
}

void Tilemap::LoadTiles() {
    Color color = BLACK;
    bool solid = false;
    Texture2D texture = assetMap[0];

    for (int j = 0; j < textureMap.size(); j++) {
        for (int i = 0; i < textureMap[j].size(); i++) {
            solid = false;
            switch (textureMap[j][i]) {
            case GRASS:
                texture = assetMap[0];
                break;
            case STONE:
                texture = assetMap[1];
                solid = true;
                break;
            case STONE_WALL_BOTTOM:
                texture = assetMap[2];
                solid = true;
                break;
            case WATER:
                texture = assetMap[3];
                solid = true;
                break;
            default:
                color = BLACK;
                break;
            }
            Tile* newtile = new Tile(color);
            newtile->pos.absolute.x += i*newtile->size.x - textureMap[j].size()/4*newtile->size.x;
            newtile->pos.absolute.y += j*newtile->size.y - textureMap.size()/4*newtile->size.y;
            newtile->solid = solid;
            newtile->texture = texture;
            tilesStored.push_back(newtile);
        }
    }
}

void Tilemap::UnloadAssets() {
    
}

void Tilemap::Load() {
    tilesStored = {};

    auto data = readCSV("src/map1.csv");
    
    for (const auto& row : data) {
        std::vector<int> newrow;
        for (const auto& cell : row) {
            newrow.push_back(cell);
            std::cout << cell;
        }
        textureMap.push_back(newrow);
        std::cout << std::endl;
    }
    
    LoadTiles(); // Assign tile types, append tiles
}
void Tilemap::Render() {
    Color color; // Substitute for textures
    for (Tile* tile : tilesStored) {
        tile->Draw();
    }
}

void Tilemap::Move(Point newpos) {
    for (Tile* tile : tilesStored) {
        tile->pos.absolute.x += newpos.x;
        tile->pos.absolute.y += newpos.y;
    }
}
