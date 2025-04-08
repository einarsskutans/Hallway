#include "player.h"

Player::Player(Point newpos, Point newsize, Velocity newvel) {
    SetPos(newpos);
    SetSize(newsize);
    SetVel(newvel);
}

void Player::Draw() {
    DrawRectangle(GetPos().absolute.x-GetSize().x/2, GetPos().absolute.y-GetSize().y/2, GetSize().x, GetSize().y, BLACK);
}

void Player::Move(Tilemap* tilemap, Point newpos) {
    tilemap->Move(newpos);
}
