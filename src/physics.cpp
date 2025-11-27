#include "lib/physics.h"

void Physics::CollideTile(Tilemap* tilemap, Structmap* structmap, Player* entity, Tile* tile, Structure* structure) {
    if (
        (
            entity->pos.absolute.x + entity->size.x/2 > tile->pos.absolute.x - tile->size.x/2 &&
            entity->pos.absolute.x - entity->size.x/2 < tile->pos.absolute.x + tile->size.x/2 &&
            entity->pos.absolute.y + entity->size.y/2 > tile->pos.absolute.y - tile->size.y/2 &&
            entity->pos.absolute.y - entity->size.y/2 < tile->pos.absolute.y + tile->size.y/2
        ) ||
        (
            entity->pos.absolute.x + entity->size.x/2 > structure->pos.absolute.x - structure->size.x/2 &&
            entity->pos.absolute.x - entity->size.x/2 < structure->pos.absolute.x + structure->size.x/2 &&
            entity->pos.absolute.y + entity->size.y/2 > structure->pos.absolute.y - structure->size.y/2 &&
            entity->pos.absolute.y - entity->size.y/2 < structure->pos.absolute.y + structure->size.y/2
        )
    ) {
        
        if (entity->vel.top < 0) {
            entity->Move(tilemap, structmap, {0, entity->vel.top});
        }
        if (entity->vel.right > 0) {
            entity->Move(tilemap, structmap, {entity->vel.right, 0});
        }
        if (entity->vel.left < 0) {
            entity->Move(tilemap, structmap, {entity->vel.left, 0});
        }
        if (entity->vel.bottom > 0) {
            entity->Move(tilemap, structmap, {0, entity->vel.bottom});
        }
    }
}
