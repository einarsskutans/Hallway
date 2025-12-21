#include "lib/tile.h"

Tile::Tile(std::string tile_type) {
    this->tile_type = tile_type;
}

void Tile::Draw() {
    DrawTexture(texture, pos.absolute.x-size.x/2, pos.absolute.y-size.y/2, WHITE);
}