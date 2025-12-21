#ifndef TILE_H
#define TILE_H

#include <raylib.h>
#include <string>
#include "sprite.h"

class Tile : public Sprite {
    public:
        Tile(std::string tile_type);
        void Draw();
        bool solid = false;
        Color color;
        Texture2D texture;
        Point size = {8, 8};
        std::string tile_type;
};

#endif