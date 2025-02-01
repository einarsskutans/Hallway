#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "sprite.h"
#include "app.h"
#include "string"
#include "velocity.h"
#include "app.h"
#include "string"
#include "velocity.h"

class Player : public Sprite {
    public:
        Player(Point newpos, Point newsize, Velocity newvel);
        void Draw();
    private:
        std::string name;
};

#endif