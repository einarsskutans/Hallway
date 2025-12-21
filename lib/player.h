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
#include "physics.h"

class Physics;

class Player : public Sprite {
    public:
        Player(Point newpos, Point newsize, Velocity newvel);
        void LoadAsset();
        void Draw();
        void Move(Tilemap* tilemap, Structmap* structmap, Point newpos);
        void Attack(int time, Structmap* structmap);
        void UpdateAnimation(Structmap* structmap);
        int hit_init;
        int damageBoxTime;
        Velocity orientation; // Velocity class just to figure out sides
        Tile* damageBox = new Tile(BLACK);
    private:
        std::string name;
        Texture2D textureDefault;
        Texture2D textureLeft;
        Texture2D textureDown;
        Texture2D textureRight; 
};

#endif