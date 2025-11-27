#include "lib/structmap.h"

Structmap::Structmap() {
    std::srand(time({}));
    pos.absolute.x = 0;
    pos.absolute.y = 0;
    pos.relative.x = 0;
    pos.relative.y = 0;
}

std::vector<std::vector<int>> Structmap::readStructmap(const std::string& filename) {
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

std::vector<Asset*> Structmap::readAssets(const std::string& filename) {
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

void Structmap::GenerateStructmap(const std::string& filename, Point mapSize) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }

    int r = 0;

    for (int row = 0; row < mapSize.y; row++) {
        for (int col = 0; col < mapSize.x; col++) {
            r = GetRandomValue(3, 64*10);
            if (r == 3) {
                file << "4,";
            } 
            else {
                file << "0,";
            }
        }
        file << "\n";
    }

    file.close();
}

void Structmap::LoadAssets(int n) {
    assetsStored = readAssets("src/assets.csv");
    for (int i = 0; i < assetsStored.size(); i++) {
        Image image = LoadImage(assetsStored[i]->path.c_str()); // Load image in CPU memory (RAM)

        Texture2D texture = LoadTextureFromImage(image); // Image converted to texture, uploaded to GPU memory (VRAM)

        assetsStored[i]->texture = texture;

        UnloadImage(image);
    }
}

void Structmap::LoadStructures() {
    for (int j = 0; j < textureMap.size(); j++) {
        for (int i = 0; i < textureMap[j].size(); i++) {
            Structure* newstruct = new Structure();
            if (textureMap[j][i] != 0) {
                for (Asset* asset : assetsStored) {
                    if (asset->id == textureMap[j][i]) {
                        newstruct->texture = asset->texture;
                        newstruct->solid = asset->solid;
                    }
                }

                newstruct->pos.absolute.x += i*tilesize - textureMap[j].size()/4*tilesize;
                newstruct->pos.absolute.y += j*tilesize - textureMap.size()/4*tilesize;
                structuresStored.push_back(newstruct);
            }
            else if (textureMap[j][i] == 0) {
                newstruct->pos.absolute.x += i*tilesize - textureMap[j].size()/4*tilesize;
                newstruct->pos.absolute.y += j*tilesize - textureMap.size()/4*tilesize;
            }
        }
    }
}

void Structmap::UnloadAssets() {
    
}

void Structmap::Load() {
    structuresStored = {};

    GenerateStructmap("src/map2.csv", {64, 64});
    auto data = readStructmap("src/map2.csv");
    
    for (const auto& row : data) {
        std::vector<int> newrow;
        for (const auto& cell : row) {
            newrow.push_back(cell);
            std::cout << cell;
        }
        textureMap.push_back(newrow);
        std::cout << std::endl;
    }
    
    LoadStructures(); // Assign tile types, append tiles
}
void Structmap::Render() {
    Color color; // Substitute for textures
    for (Structure* structure : structuresStored) {
        structure->Draw();
    }
}

void Structmap::Move(Point newpos) {
    for (Structure* structure : structuresStored) {
        structure->pos.absolute.x += newpos.x;
        structure->pos.absolute.y += newpos.y;
    }
}
