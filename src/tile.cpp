#include "tile.h"

Tile::Tile(Color newcolor) {
    color = newcolor;
}

void Tile::Draw() {
    DrawRectangle(GetPos().absolute.x, GetPos().absolute.y , 32, 32, color);
}