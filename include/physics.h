#ifndef PHYSICS_H
#define PHYSICS_H

#include <utility>
#include "sprite.h"
#include "app.h"

class Physics {
    public:
        static void CollideBounds(Sprite* entity, std::pair<int, int> boundspos, bool drawlines); // Creates symmetrical "lines" to define game bounds
};

#endif