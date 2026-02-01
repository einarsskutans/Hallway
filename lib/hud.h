#ifndef HUD_H
#define HUD_H

#include "player.h"

class Hud {
    public:
        Hud(Sprite* entity);
        void Load();
        void DrawHealth();
        void DrawArmor();
        void DrawInventory();
        void Draw();
    private:
        Sprite* target;
        Texture2D textureHeart;
};

#endif