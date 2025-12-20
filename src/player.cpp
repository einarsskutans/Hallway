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

void Player::Attack(int init, int frame, Structmap* structmap) {
    if (init) {
        int damageBoxTime = 15;
        init = 0;
    }

    Tile* damageBox = new Tile(BLACK);
        damageBox->sides = 4;
        damageBox->framesPerSide = 3;
        damageBox->LoadAnimationFrames("textures/swipe", damageBox->framesPerSide);

        damageBox->texture = damageBox->textureFrames[0];
        int damageBoxTime = 0;

    if (orientation.top) {
        damageBox->pos.absolute = {pos.absolute.x, pos.absolute.y - 8};
        damageBox->size = {16, 8};
    }
    else if (orientation.bottom) {
        damageBox->pos.absolute = {pos.absolute.x, pos.absolute.y + 8};
        damageBox->size = {16, 8};
    }
    else if (orientation.left) {
        damageBox->pos.absolute = {pos.absolute.x - 8, pos.absolute.y};
        damageBox->size = {8, 16};
    }
    else if (orientation.right) {
        damageBox->pos.absolute = {pos.absolute.x + 8, pos.absolute.y};
        damageBox->size = {8, 16};
    }

    if (damageBoxTime > 0) {
        for (int i = 0; i < structmap->enemiesStored.size(); i++) {
            if (structmap->enemiesStored[i]->iframes <= 0 && Physics::CollideEnemyDamage(structmap->enemiesStored[i], damageBox)) {
                structmap->enemiesStored[i]->iframes = 120;
                structmap->enemiesStored[i]->health.x -= 10;
                if (structmap->enemiesStored[i]->health.x <= 0) {
                    structmap->enemiesStored.erase(structmap->enemiesStored.begin() + i);
                }
            }
        }
        
        if (damageBoxTime <= 5) {
            if (orientation.top) {
                damageBox->texture = damageBox->textureFrames[2 + damageBox->framesPerSide*0];
            }
            else if (orientation.right) {
                damageBox->texture = damageBox->textureFrames[2 + damageBox->framesPerSide*3];
            }
            else if (orientation.left) {
                damageBox->texture = damageBox->textureFrames[2 + damageBox->framesPerSide*2];
            }
            else if (orientation.bottom) {
                damageBox->texture = damageBox->textureFrames[2 + damageBox->framesPerSide*1];
            }
        }
        else if (damageBoxTime <= 10) {
            if (orientation.top) {
                damageBox->texture = damageBox->textureFrames[1 + damageBox->framesPerSide*0];
            }
            else if (orientation.right) {
                damageBox->texture = damageBox->textureFrames[1 + damageBox->framesPerSide*3];
            }
            else if (orientation.left) {
                damageBox->texture = damageBox->textureFrames[1 + damageBox->framesPerSide*2];
            }
            else if (orientation.bottom) {
                damageBox->texture = damageBox->textureFrames[1 + damageBox->framesPerSide*1];
            }
        }
        else if (damageBoxTime <= 15) {
            if (orientation.top) {
                damageBox->texture = damageBox->textureFrames[0 + damageBox->framesPerSide*0];
            }
            else if (orientation.right) {
                damageBox->texture = damageBox->textureFrames[0 + damageBox->framesPerSide*3];
            }
            else if (orientation.left) {
                damageBox->texture = damageBox->textureFrames[0 + damageBox->framesPerSide*2];
            }
            else if (orientation.bottom) {
                damageBox->texture = damageBox->textureFrames[0 + damageBox->framesPerSide*1];
            }
        }
        damageBoxTime--;
    
    } 
    else if (damageBoxTime <= 0) {
        damageBox->pos.absolute = {-128, -128};
        init = 1;
    }

    delete damageBox;
}