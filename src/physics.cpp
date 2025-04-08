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

void Physics::CollideTile(Sprite *entity, Tile *tile) {
    if (entity->pos.absolute.x+entity->size.x/2 > tile->pos.absolute.x-tile->size.x/2) {
        DrawText(TextFormat("MORE THAN TILE X: %i", 1), 10, 10, 20, BLACK);
    }
    if (entity->pos.absolute.y+entity->size.y/2 > tile->pos.absolute.y-tile->size.y/2) {
        DrawText(TextFormat("MORE THAN TILE Y: %i", 1), 10, 30, 20, BLACK);
    }
    if (entity->pos.absolute.x-entity->size.x/2 < tile->pos.absolute.x+tile->size.x/2) {
        DrawText(TextFormat("LESS THAN TILE X: %i", 1), 10, 50, 20, BLACK);
    }
    if (entity->pos.absolute.y-entity->size.y/2 < tile->pos.absolute.y+tile->size.y/2) {
        DrawText(TextFormat("LESS THAN TILE Y: %i", 1), 10, 70, 20, BLACK);
    }
}
