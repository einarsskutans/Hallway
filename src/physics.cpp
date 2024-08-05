#include "include/physics.h"

void Physics::CollideBounds(Sprite* entity, std::pair<int, int> boundspos, bool drawlines) {
    if (entity->GetPos().first-entity->GetSize().first <= boundspos.first+entity->GetSize().first/2) entity->SetPos(entity->GetPos());
    if (entity->GetPos().first+entity->GetSize().first/2 > SCREENSIZE.first-boundspos.first) entity->Move({-entity->GetSize().first, 0});
    if (entity->GetPos().second-entity->GetSize().second/2 < boundspos.second) entity->Move({0, entity->GetSize().second});
    if (entity->GetPos().second+entity->GetSize().second/2 > SCREENSIZE.second-boundspos.second) entity->Move({0, -entity->GetSize().second});
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