#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"
#include <raylib.h>
#include "sprite.h"
#include "app.h"
#include "string"
#include "velocity.h"
#include "app.h"

class Player : public Sprite {
    public:
        Player(std::pair<int, int> newpos, std::pair<int, int> newsize, Velocity newvel);
        void Draw();
    private:
        std::string name;
};

#endif