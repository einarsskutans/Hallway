#include "tile.h"

Tile::Tile(Color newcolor) {
    color = newcolor;
}

void Tile::Draw() {
    DrawRectangle(GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, size.x, size.y, color);
    DrawTexture(texture, GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, WHITE);
    //GetPos().absolute.x-GetSize().x/2, GetPos().absolute.y-GetSize().y/2, GetSize().x, GetSize().y
}