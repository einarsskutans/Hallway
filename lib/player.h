#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "sprite.h"
#include "string"
#include "velocity.h"
#include "tilemap.h"
#include "tile.h"
#include "structmap.h"
#include "structure.h"

class Player : public Sprite {
    public:
        Player(Point newpos, Point newsize, Velocity newvel);
        void LoadAsset();
        void Draw();
        void Move(Tilemap* tilemap, Structmap* structmap, Point newpos);
        void Attack(int frame);

        Velocity orientation; // Velocity class just to figure out sides
    private:
        std::string name;
        Texture2D textureDefault;
        Texture2D textureLeft;
        Texture2D textureDown;
        Texture2D textureRight;
};

#endif