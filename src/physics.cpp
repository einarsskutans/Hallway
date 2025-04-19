#include "physics.h"

void Physics::CollideBounds(Sprite* entity, Point boundspos, bool drawlines) {
    if (drawlines) {
        DrawLine(boundspos.x, 0, boundspos.x, SCREENSIZE.y, WHITE);
        DrawLine(SCREENSIZE.x-boundspos.x, 0, SCREENSIZE.x-boundspos.x, SCREENSIZE.y, WHITE);
        DrawLine(0, boundspos.y, SCREENSIZE.x, boundspos.y, WHITE);
        DrawLine(0, SCREENSIZE.y-boundspos.y, SCREENSIZE.x, SCREENSIZE.y-boundspos.y, WHITE);

        DrawLine(boundspos.x+entity->GetSize().x/2, 0, boundspos.x+entity->GetSize().x/2, SCREENSIZE.y, {179, 179, 179, 179});
        DrawLine(SCREENSIZE.x-boundspos.x-entity->GetSize().x/2, 0, SCREENSIZE.x-boundspos.x-entity->GetSize().x/2, SCREENSIZE.y, {179, 179, 179, 179});
        DrawLine(0, boundspos.y+entity->GetSize().y/2, SCREENSIZE.x, boundspos.y+entity->GetSize().y/2, {179, 179, 179, 179});
        DrawLine(0, SCREENSIZE.y-boundspos.y-entity->GetSize().y/2, SCREENSIZE.x, SCREENSIZE.y-boundspos.y-entity->GetSize().y/2, {179, 179, 179, 179});
    }
}

void Physics::CollideTile(Tilemap* tilemap, Player* entity, Tile* tile) {
    // Log
    if (entity->pos.absolute.x + entity->size.x/2 > tile->pos.absolute.x - tile->size.x/2) {
        DrawText(TextFormat("MORE THAN TILE X: %i", 1), 10, 10, 20, BLACK);
    }
    if (entity->pos.absolute.y + entity->size.y/2 > tile->pos.absolute.y - tile->size.y/2) {
        DrawText(TextFormat("MORE THAN TILE Y: %i", 1), 10, 30, 20, BLACK);
    }
    if (entity->pos.absolute.x - entity->size.x/2 < tile->pos.absolute.x + tile->size.x/2) {
        DrawText(TextFormat("LESS THAN TILE X: %i", 1), 10, 50, 20, BLACK);
    }
    if (entity->pos.absolute.y - entity->size.y/2 < tile->pos.absolute.y + tile->size.y/2) {
        DrawText(TextFormat("LESS THAN TILE Y: %i", 1), 10, 70, 20, BLACK);
    }
    
    if (
        entity->pos.absolute.x + entity->size.x/2 > tile->pos.absolute.x - tile->size.x/2 &&
        entity->pos.absolute.x - entity->size.x/2 < tile->pos.absolute.x + tile->size.x/2 &&
        entity->pos.absolute.y + entity->size.y/2 > tile->pos.absolute.y - tile->size.y/2 &&
        entity->pos.absolute.y - entity->size.y/2 < tile->pos.absolute.y + tile->size.y/2
    ) {
        DrawText(TextFormat("MOVED: %i", 1), 10, 90, 20, BLACK);
        
        if (entity->vel.top < 0) {
            //entity->Move(tilemap, {entity->pos.relative.x, entity->vel.top});
            entity->vel.top = -entity->vel.top;
        }
        if (entity->vel.right > 0) {
            //entity->Move(tilemap, {entity->vel.right, entity->pos.relative.y});
            entity->vel.right = -entity->vel.right;
        }
        if (entity->vel.left < 0) {
            //entity->Move(tilemap, {entity->vel.left, entity->pos.relative.y});
            entity->vel.left = -entity->vel.left;
        }
        if (entity->vel.bottom > 0) {
            //entity->Move(tilemap, {entity->pos.relative.x, entity->vel.bottom});
            entity->vel.bottom = -entity->vel.bottom;
        }
    }

    /*
    if (
        entity->pos.absolute.x + entity->size.x/2 > tile->pos.absolute.x - tile->size.x/2 &&
        entity->pos.absolute.y + entity->size.y/2 > tile->pos.absolute.y - tile->size.y/2 &&
        entity->pos.absolute.y - entity->size.y/2 < tile->pos.absolute.y + tile->size.y/2
    ) {
        DrawText(TextFormat("MOVED X: %i", 1), 10, 90, 20, BLACK);
        entity->Move(tilemap, {entity->vel.right.first, entity->pos.relative.y});
    }
    if (
        entity->pos.absolute.y + entity->size.y/2 > tile->pos.absolute.y - tile->size.y/2 &&
        entity->pos.absolute.x + entity->size.x/2 > tile->pos.absolute.x - tile->size.x/2 &&
        entity->pos.absolute.x - entity->size.x/2 < tile->pos.absolute.x + tile->size.x/2
    ) {
        DrawText(TextFormat("MOVED Y: %i", 1), 10, 120, 20, BLACK);
        entity->Move(tilemap, {entity->pos.relative.x, entity->vel.top.first});
    }*/
}
