#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "sprite.h"
#include "string"
#include "velocity.h"
#include "tilemap.h"
#include "tile.h"

class Player : public Sprite {
    public:
        Player(Point newpos, Point newsize, Velocity newvel);
        void Draw();
        void Move(Tilemap* tilemap, Point newpos);
    private:
        std::string name;
};

#endif