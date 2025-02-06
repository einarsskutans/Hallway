#include "tilemap.h"

Tilemap::Tilemap() {
    std::srand(std::time({}));
    pos.absolute.x = 0;
    pos.absolute.y = 0;
    pos.relative.x = 0;
    pos.relative.y = 0;
}
void Tilemap::Load(int size) {
    tilesStored = {};
    Color randcolor = BLACK;

    // Randomly generate texturemap (test only)
    for (int i = 0; i < size; i++) {
        std::vector<int> column = {};
        for (int j = 0; j < size; j++) {
            int randint = std::rand()%10;
            column.push_back(randint);
        }
        textureMap.push_back(column);
    }

    // Render tilemap -> tiles -> colors
    for (int j = 0; j < textureMap.size(); j++) {
        for (int i = 0; i < textureMap[j].size(); i++) {
            switch (textureMap[j][i]) {
            case 1:
                randcolor = BLUE;
                break;
            case 2:
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
            newtile->pos.absolute.x += i*32;
            newtile->pos.absolute.y += j*32;
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
