#ifndef TILE_H
#define TILE_H

#include <raylib.h>
#include "sprite.h"

class Tile : public Sprite {
    public:
        Tile(Color newcolor);
        void Draw();
        Color color;
    private:
        int texture; // temp
};

#endif