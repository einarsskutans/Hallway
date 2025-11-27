#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <raylib.h>
#include "sprite.h"

class Structure : public Sprite {
    public:
        Structure();
        void Draw();
        bool solid = false;
        Color color;
        Texture2D texture;
        Point size = {32, 32};
};

#endif