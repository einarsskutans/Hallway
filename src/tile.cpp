#include "lib/tile.h"

Tile::Tile(Color newcolor) {
    color = newcolor;
}

void Tile::Draw() {
    DrawTexture(texture, pos.absolute.x-size.x/2, pos.absolute.y-size.y/2, WHITE);
}