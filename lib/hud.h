#ifndef HUD_H
#define HUD_H

#include "app.h"

class Hud : public Sprite{
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