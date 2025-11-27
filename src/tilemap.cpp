#include "lib/tilemap.h"

Tilemap::Tilemap() {
    std::srand(time({}));
    pos.absolute.x = 0;
    pos.absolute.y = 0;
    pos.relative.x = 0;
    pos.relative.y = 0;
}

std::vector<std::vector<int>> Tilemap::readTilemap(const std::string& filename) {
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

std::vector<Asset*> Tilemap::readAssets(const std::string& filename) {
    std::vector<Asset*> data;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        Asset* asset = new Asset();
        std::stringstream ss(line);
        std::string cell;
        
        std::getline(ss, cell, ',');
        asset->path = cell.c_str();
        std::getline(ss, cell, ',');
        asset->name = cell;
        std::getline(ss, cell, ',');
        asset->id = std::stoi(cell);
        std::getline(ss, cell, ',');
        asset->solid = std::stoi(cell);

        data.push_back(asset);
    }

    file.close();

    return data;
}

void Tilemap::GenerateTileMap(const std::string& filename, Point mapSize) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }

    for (int row = 0; row < mapSize.y; row++) {
        for (int col = 0; col < mapSize.x; col++) {
            file << GetRandomValue(1, 3) << ",";
        }
        file << "\n";
    }

    file.close();
}

void Tilemap::LoadAssets(int n) {
    assetsStored = readAssets("src/assets.csv");
    for (int i = 0; i < assetsStored.size(); i++) {
        Image image = LoadImage(assetsStored[i]->path.c_str()); // Load image in CPU memory (RAM)

        Texture2D texture = LoadTextureFromImage(image); // Image converted to texture, uploaded to GPU memory (VRAM)

        assetsStored[i]->texture = texture;

        UnloadImage(image);
    }
}

void Tilemap::LoadTiles() {
    Color color = BLACK;
    for (int j = 0; j < textureMap.size(); j++) {
        for (int i = 0; i < textureMap[j].size(); i++) {

            Tile* newtile = new Tile(color);
            for (Asset* asset : assetsStored) {
                if (asset->id == textureMap[j][i]) {
                    newtile->texture = asset->texture;
                    newtile->solid = asset->solid;
                }
            }

            newtile->pos.absolute.x += i*tilesize - textureMap[j].size()/4*tilesize;
            newtile->pos.absolute.y += j*tilesize - textureMap.size()/4*tilesize;
            tilesStored.push_back(newtile);
        }
    }
}

void Tilemap::UnloadAssets() {
    
}

void Tilemap::Load() {
    tilesStored = {};

    GenerateTileMap("src/map1.csv", {64, 64});
    auto data = readTilemap("src/map1.csv");
    
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
