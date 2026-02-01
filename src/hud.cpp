#include "lib/hud.h"

Hud::Hud(Sprite* entity) {
    target = entity;
}

void Hud::Load() {
    Image image1 = LoadImage("textures/heart.png");
    textureHeart = LoadTextureFromImage(image1);
    UnloadImage(image1);
}

void Hud::DrawHealth() {
    for (int i = 1; i < target->health.x+1; i++) {
        DrawTexture(textureHeart, pos.absolute.x - SCREENSIZE.x/SCALE/2 + 10*i, pos.absolute.y - SCREENSIZE.y/SCALE/2 + 4, WHITE);
    }
}
void Hud::DrawArmor() {
}
void Hud::DrawInventory() {
}
void Hud::Draw() {
    pos = target->pos;
    DrawHealth();
}
