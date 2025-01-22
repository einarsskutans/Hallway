#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "sprite.h"
#include "app.h"
#include "string"
#include "velocity.h"

class Player : public Sprite {
    public:
        Player(std::pair<int, int> newpos, std::pair<int, int> newsize, Velocity newvel);
        void Draw();
    private:
        std::string name;
};

#endif