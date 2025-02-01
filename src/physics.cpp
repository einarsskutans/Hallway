#include "physics.h"

void Physics::CollideBounds(Sprite* entity, Point boundspos, bool drawlines) {
    /*
    if (entity->pos.x - entity->size.x/2 < boundspos.x) entity->vel.left.y = false;
    else entity->vel.left.y = true;
    if (entity->pos.x + entity->size.x/2 > SCREENSIZE.x - boundspos.x) entity->vel.right.y = false;
    else entity->vel.right.y = true;
    if (entity->pos.y - entity->size.y/2 < boundspos.y) entity->vel.top.y = false;
    else entity->vel.top.y = true;
    if (entity->pos.y + entity->size.y/2 > SCREENSIZE.y - boundspos.y) entity->vel.bottom.y = false;
    else entity->vel.bottom.y = true;
    */
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