#ifndef ENEMY_H
#define ENEMY_H

#include <raylib.h>
#include "sprite.h"
#include "string"
#include "velocity.h"
#include "tilemap.h"
#include "tile.h"
#include "structmap.h"
#include "structure.h"

class Enemy : public Sprite {
    public:
        Enemy(Point newpos, Point newsize, Velocity newvel);
        void LoadAsset();
        void Draw();
        void Move(Tilemap* tilemap, Structmap* structmap, Point newpos);
        Velocity orientation; // Velocity class just to figure out sides
    private:
        std::string name;
        Texture2D textureDefault;
};

#endif