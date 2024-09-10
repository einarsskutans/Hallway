#include "physics.h"

void Physics::CollideBounds(Sprite* entity, std::pair<int, int> boundspos, bool drawlines) {
    if (entity->pos.first - entity->size.first/2 < boundspos.first) entity->vel.left.second = false;
    else entity->vel.left.second = true;
    if (entity->pos.first + entity->size.first/2 > SCREENSIZE.first - boundspos.first) entity->vel.right.second = false;
    else entity->vel.right.second = true;
    if (entity->pos.second - entity->size.second/2 < boundspos.second) entity->vel.top.second = false;
    else entity->vel.top.second = true;
    if (entity->pos.second + entity->size.second/2 > SCREENSIZE.second - boundspos.second) entity->vel.bottom.second = false;
    else entity->vel.bottom.second = true;
    if (drawlines) {
        DrawLine(boundspos.first, 0, boundspos.first, SCREENSIZE.second, WHITE);
        DrawLine(SCREENSIZE.first-boundspos.first, 0, SCREENSIZE.first-boundspos.first, SCREENSIZE.second, WHITE);
        DrawLine(0, boundspos.second, SCREENSIZE.first, boundspos.second, WHITE);
        DrawLine(0, SCREENSIZE.second-boundspos.second, SCREENSIZE.first, SCREENSIZE.second-boundspos.second, WHITE);

        DrawLine(boundspos.first+entity->GetSize().first/2, 0, boundspos.first+entity->GetSize().first/2, SCREENSIZE.second, {179, 179, 179, 179});
        DrawLine(SCREENSIZE.first-boundspos.first-entity->GetSize().first/2, 0, SCREENSIZE.first-boundspos.first-entity->GetSize().first/2, SCREENSIZE.second, {179, 179, 179, 179});
        DrawLine(0, boundspos.second+entity->GetSize().second/2, SCREENSIZE.first, boundspos.second+entity->GetSize().second/2, {179, 179, 179, 179});
        DrawLine(0, SCREENSIZE.second-boundspos.second-entity->GetSize().second/2, SCREENSIZE.first, SCREENSIZE.second-boundspos.second-entity->GetSize().second/2, {179, 179, 179, 179});
    }
}