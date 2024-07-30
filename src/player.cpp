#include "include/player.h"

Player::Player() {}
Player::Player(std::pair<int, int> newpos, std::pair<int, int> newsize, std::pair<int, int> newvel) {
    SetPos(newpos);
    SetSize(newsize);
    SetVel(newvel);
}

void Player::Draw() {
    DrawRectangle(GetPos().first, GetPos().second, GetSize().first, GetSize().second, BLACK);
}