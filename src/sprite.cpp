#include "include/sprite.h"

void Sprite::Move(std::pair<int, int> newpos) {
    pos.first = pos.first + newpos.first;
    pos.second = pos.second + newpos.second;
}
void Sprite::SetPos(std::pair<int, int> newpos) {
    pos = newpos;
}
void Sprite::SetSize(std::pair<int, int> newsize) {
    size = newsize;
}
void Sprite::SetVel(std::pair<int, int> newvel) {
    vel = newvel;
}
void Sprite::SetDrawable(bool newdrawable) {
    drawable = newdrawable;
}
void Sprite::SetMovable(bool newmovable) {
    movable = newmovable;
}

std::pair<int, int> Sprite::GetPos() {
    return pos;
}
std::pair<int, int> Sprite::GetSize() {
    return size;
}
std::pair<int, int> Sprite::GetVel() {
    return vel;
}
bool Sprite::GetDrawable() {
    return drawable;
}
bool Sprite::GetMovable() {
    return movable;
}

void Draw() {};