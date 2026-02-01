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
    for (int i = 0; i < target->health.x; i++) {
        DrawTexture(textureHeart, -SCREENSIZE.x/2 + 8*i, -SCREENSIZE.y/2 + 8, WHITE);
    }
}
void Hud::DrawArmor() {
}
void Hud::DrawInventory() {
}
void Hud::Draw() {
}
