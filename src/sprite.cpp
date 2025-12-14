#include "lib/sprite.h"

void Sprite::Move(Point newpos) {
    pos.relative.x = pos.relative.x + newpos.x;
    pos.relative.y = pos.relative.y + newpos.y;
}
void Sprite::SetPos(Point newpos) {
    pos.absolute = newpos;
}
void Sprite::SetSize(Point newsize) {
    size = newsize;
}
void Sprite::SetVel(Velocity newvel) {
    vel = newvel;
}
void Sprite::SetDrawable(bool newdrawable) {
    drawable = newdrawable;
}
void Sprite::SetMovable(bool newmovable) {
    movable = newmovable;
}
void Sprite::LoadAnimationFrames(char* pathToFolder, int n) {
    for (int i = 0; i < 12; i++) {
        Image image = LoadImage(TextFormat("%s/frame000%i.png", pathToFolder, i));
        Texture2D texture = LoadTextureFromImage(image);
        textureFrames.push_back(texture);
        UnloadImage(image);
    }
}
Pos Sprite::GetPos() {
    return pos;
}
Point Sprite::GetSize() {
    return size;
}
Velocity Sprite::GetVel() {
    return vel;
}
bool Sprite::GetDrawable() {
    return drawable;
}
bool Sprite::GetMovable() {
    return movable;
}
void Sprite::Draw() {}