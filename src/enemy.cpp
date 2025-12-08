#include "lib/enemy.h"

Enemy::Enemy(Point newpos, Point newsize, Velocity newvel) {
    SetPos(newpos);
    SetSize(newsize);
    SetVel(newvel);
}

void Enemy::LoadAsset() {
    Image image1 = LoadImage("textures/enemy1_default.png"); // Load image in CPU memory (RAM)
    textureDefault = LoadTextureFromImage(image1); // Image converted to texture, uploaded to GPU memory (VRAM)
    UnloadImage(image1);
}

void Enemy::Draw() {
    DrawTexture(textureDefault, GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, WHITE);
}

void Enemy::Move(Tilemap* tilemap, Structmap* structmap, Point newpos) {
    pos.relative = {-newpos.x, -newpos.y};
    pos.absolute.x += newpos.x;
    pos.absolute.y += newpos.y;
}
