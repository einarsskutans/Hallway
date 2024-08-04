#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "include/sprite.h"
#include "include/app.h"
#include "string"

class Player : public Sprite {
    public:
        Player(std::pair<int, int> newpos, std::pair<int, int> newsize, std::pair<int, int> newvel);
        void Draw();
    private:
        std::string name;
};

#endif