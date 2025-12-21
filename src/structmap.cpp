#include "lib/structmap.h"

Structmap::Structmap() {
    std::srand(time({}));
    pos.absolute.x = 0;
    pos.absolute.y = 0;
    pos.relative.x = 0;
    pos.relative.y = 0;
    structmapSize = {mapSize.x*tilesize, mapSize.y*tilesize};
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

void Structmap::GenerateStructmap(const std::string& filename) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }

    int r;

    for (int row = 0; row < mapSize.y; row++) {
        for (int col = 0; col < mapSize.x; col++) {

            // Reading chance percentages
            r = GetRandomValue(1, 100*mapSize.x);
            if (r <= CHANCE_HOUSE) {
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
    for (unsigned int i = 0; i < assetsStored.size(); i++) {
        Image image = LoadImage(assetsStored[i]->path.c_str()); // Load image in CPU memory (RAM)

        Texture2D texture = LoadTextureFromImage(image); // Image converted to texture, uploaded to GPU memory (VRAM)

        assetsStored[i]->texture = texture;

        UnloadImage(image);
    }
}

void Structmap::LoadStructures() {
    for (unsigned int j = 0; j < textureMap.size(); j++) {
        for (unsigned int i = 0; i < textureMap[j].size(); i++) {
            Structure* newstruct = new Structure();
            if (textureMap[j][i] != 0) {
                for (Asset* asset : assetsStored) {
                    if (asset->id == textureMap[j][i]) {
                        newstruct->texture = asset->texture;
                        newstruct->solid = asset->solid;
                    }
                }

                newstruct->pos.absolute.x = i*tilesize + pos.absolute.x;
                newstruct->pos.absolute.y = j*tilesize + pos.absolute.y;
                structuresStored.push_back(newstruct);
            }
            else if (textureMap[j][i] == 0) {
                newstruct->pos.absolute.x = i*tilesize  + pos.absolute.x;
                newstruct->pos.absolute.y = j*tilesize  + pos.absolute.y;
            }
        }
    }
}

void Structmap::UnloadAssets() {
    
}

void Structmap::Load() {
    structuresStored = {};

    GenerateStructmap("src/datamapStructures.csv");
    auto data = readStructmap("src/datamapStructures.csv");
    
    for (const auto& row : data) {
        std::vector<int> newrow;
        for (const auto& cell : row) {
            newrow.push_back(cell);
            //std::cout << cell;
        }
        textureMap.push_back(newrow);
        //std::cout << std::endl;
    }
    
    LoadStructures(); // Assign structure types, append structures
}
void Structmap::Render() {
    for (Structure* structure : structuresStored) {
        structure->Draw();
    }
    //DrawRectangleLines(pos.absolute.x-8, pos.absolute.y-8, structmapSize.x, structmapSize.y, RED);
}

void Structmap::Move(Point newpos) {
    for (Structure* structure : structuresStored) {
        structure->pos.absolute.x += newpos.x; // Move structuremap contents
        structure->pos.absolute.y += newpos.y;
    }
    pos.absolute.x += newpos.x; // Move structuremap
    pos.absolute.y += newpos.y;
}
