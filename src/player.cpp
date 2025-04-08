#include "player.h"

Player::Player(Point newpos, Point newsize, Velocity newvel) {
    SetPos(newpos);
    SetSize(newsize);
    SetVel(newvel);
}

void Player::Draw() {
    DrawRectangle(GetPos().absolute.x-GetSize(), GetPos().absolute.y-GetSize(), GetSize().x, GetSize().y, BLACK);
}

void Player::Move(Tilemap* tilemap, Point newpos) {
    pos.relative = {-newpos.x, -newpos.y};
    tilemap->Move(newpos);
}
