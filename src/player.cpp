#include "include/player.h"

Player::Player(std::pair<int, int> newpos, std::pair<int, int> newsize, Velocity newvel) {
    SetPos(newpos);
    SetSize(newsize);
    SetVel(newvel);
}

void Player::Draw() {
    DrawRectangle(GetPos().first-GetSize().first/2, GetPos().second-GetSize().second/2, GetSize().first, GetSize().second, BLACK);
}