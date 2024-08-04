#ifndef PHYSICS_H
#define PHYSICS_H

#include <utility>
#include "app.h"
#include "sprite.h"

class Physics {
    public:
        static void CollideBounds(Sprite* entity, std::pair<int, int> boundspos); // Creates symmetrical "lines" to define game bounds
};

#endif