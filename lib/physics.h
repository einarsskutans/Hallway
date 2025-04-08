#ifndef PHYSICS_H
#define PHYSICS_H

#include <utility>
#include "sprite.h"
#include "tilemap.h"
#include "tile.h"
#include "app.h"

class Physics {
    public:
        static void CollideBounds(Sprite* entity, Point boundspos, bool drawlines); // Creates symmetrical "lines" to define game bounds
        static void CollideTile(Sprite* entity, Tile* tile); // Collision with a single tiles
};

#endif