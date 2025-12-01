#ifndef TILE_H
#define TILE_H

#include <raylib.h>
#include "sprite.h"
#include "tilemap.h"

class Tile : public Sprite {
    public:
        Tile(Color newcolor);
        void Draw();
        bool solid = false;
        Color color;
        Texture2D texture;
        Point size = {8, 8};
};

#endif