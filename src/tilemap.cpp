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

void Tilemap::Load()
{
    tilesStored = {};
    Color randcolor = BLACK;

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
    
    // Render tilemap -> tiles -> colors
    for (int j = 0; j < textureMap.size(); j++) {
        for (int i = 0; i < textureMap[j].size(); i++) {
            switch (textureMap[j][i]) {
            case 0: // default mud
                randcolor = GREEN;
                break;
            case 1: // default water
                randcolor = BLUE;
                break;
            case 2: // default solid
                randcolor = GREEN;
                break;
            case 3:
                randcolor = BLACK;
                break;
            default:
                randcolor = YELLOW;
                break;
            }
            Tile* newtile = new Tile(randcolor);
            newtile->pos.absolute.x += i*newtile->size.x;
            newtile->pos.absolute.y += j*newtile->size.y;
            tilesStored.push_back(newtile);
        }
    }
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
