#ifndef TILE_H
#define TILE_H

#include <raylib.h>
#include "sprite.h"

class Tile : public Sprite {
    public:
        Tile(Color newcolor);
        void Draw();
        bool collide = false;
        Color color;
        Texture2D texture;
        Point size = {32, 32};
};

#endif