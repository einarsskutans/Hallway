#include "lib/tile.h"

Tile::Tile(Color newcolor) {
    color = newcolor;
}

void Tile::Draw() {
    DrawTexture(texture, GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, WHITE);
}