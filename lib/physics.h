#ifndef PHYSICS_H
#define PHYSICS_H

#include "player.h"
#include <utility>
#include "app.h"
#include "tilemap.h"
#include "tile.h"
#include "structmap.h"
#include "structure.h"

class Physics {
    public:
        static void CollideTile(Tilemap* tilemap, Structmap* structmap, Player* entity, Tile* tile); // Collision with a single tiles
};

#endif