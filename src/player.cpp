#include "lib/player.h"

Player::Player(Point newpos, Point newsize, Velocity newvel) {
    SetPos(newpos);
    SetSize(newsize);
    SetVel(newvel);
}

void Player::LoadAsset() {
        Image image1 = LoadImage("textures/player1.png"); // Load image in CPU memory (RAM)
        Image image2 = LoadImage("textures/player1_left.png"); // Load image in CPU memory (RAM)
        Image image3 = LoadImage("textures/player1_down.png"); // Load image in CPU memory (RAM)
        Image image4 = LoadImage("textures/player1_right.png"); // Load image in CPU memory (RAM)
        textureDefault = LoadTextureFromImage(image1); // Image converted to texture, uploaded to GPU memory (VRAM)
        textureLeft = LoadTextureFromImage(image2);
        textureDown = LoadTextureFromImage(image3);
        textureRight = LoadTextureFromImage(image4);
        UnloadImage(image1);
        UnloadImage(image2);
        UnloadImage(image3);
        UnloadImage(image4);
}

void Player::Draw() {
    if (orientation.top == 1) {
        DrawTexture(textureDefault, GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, WHITE);
    }
    else if (orientation.bottom == 1) {
        DrawTexture(textureDown, GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, WHITE);
    }
    else if (orientation.left == 1) {
        DrawTexture(textureLeft, GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, WHITE);
    }
    else if (orientation.right == 1) {
        DrawTexture(textureRight, GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, WHITE);
    }

    else {
        DrawTexture(textureDown, GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, WHITE);
    }
}

void Player::Move(Tilemap* tilemap, Structmap* structmap, Point newpos) {
    pos.relative = {-newpos.x, -newpos.y};
    tilemap->Move(newpos);
    structmap->Move(newpos);
}
