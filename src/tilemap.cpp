#include "tilemap.h"

Tilemap::Tilemap() {
    pos.absolute.x = 0;
    pos.absolute.y = 0;
    pos.relative.x = 0;
    pos.relative.y = 0;
}

void Tilemap::Load(int size) {
    tilesStored = {};
    Color randcolor = BLACK;
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < size; i++) {
            if (i > 5) {
                randcolor = GREEN;
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
