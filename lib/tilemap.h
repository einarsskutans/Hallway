#ifndef TILEMAP_H
#define TILEMAP_H

#include <raylib.h>
#include "sprite.h"
#include "app.h"
#include "tile.h"

class Tilemap {
    public:
        Tilemap();
        void Load(int size);
        void Render();
        void Move(Point newpos);
        Pos pos;
        std::vector<Tile*> tilesStored = {};
    private:
};

#endif

// {1, 1, 1, 0, 1, 1}
// {0, 0, 0, 1, 1, 0}