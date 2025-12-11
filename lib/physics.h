#ifndef PHYSICS_H
#define PHYSICS_H

#include "player.h"
#include <utility>
#include "app.h"
#include "tilemap.h"
#include "tile.h"
#include "structmap.h"
#include "structure.h"
#include "enemy.h"

class Physics {
    public:
        static void CollideTile(Tilemap* tilemap, Structmap* structmap, Player* entity, Tile* tile); // Collision with a single tile
        static void CollideStructure(Tilemap* tilemap, Structmap* structmap, Player* entity, Structure* structure); // Collision with a single structure
        static bool CollideEnemy(Player* entity, Enemy* enemy); // Collision with enemy
};

#endif