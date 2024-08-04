#include "include/physics.h"

void Physics::CollideBounds(Sprite* entity, std::pair<int, int> boundspos) {
    if (entity->GetPos().first-entity->GetSize().first/4 <= boundspos.first) entity->Move({entity->GetVel().first, 0});
    if (entity->GetPos().first+entity->GetSize().first/4 >= SCREENSIZE.first-boundspos.first) entity->Move({-entity->GetVel().first, 0});
    if (entity->GetPos().second-entity->GetSize().second/4 <= boundspos.second) entity->Move({0, entity->GetVel().second});
    if (entity->GetPos().second+entity->GetSize().second/4 >= SCREENSIZE.second-boundspos.second) entity->Move({0, -entity->GetVel().second});
}