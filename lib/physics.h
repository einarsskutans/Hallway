#ifndef PHYSICS_H
#define PHYSICS_H

#include "player.h"
#include <utility>
#include "app.h"
#include "tilemap.h"
#include "tile.h"

class Physics {
    public:
        static void CollideBounds(Sprite* entity, Point boundspos, bool drawlines); // Creates symmetrical "lines" to define game bounds
        static void CollideTile(Tilemap* tilemap, Player* entity, Tile* tile); // Collision with a single tiles
};

#endif