#include "lib/app.h"

Point operator/(const Point&a, const int&b) {
    return Point{a.x/b, a.y/b};
}
Point operator-(const Point&a) {
    return Point{-a.x, -a.y};
}

void App::Init(Point newScreensize, int fps, bool debug) {
    screensize = newScreensize;
    InitWindow(screensize.x, screensize.y, "Hallway");
    SetTargetFPS(fps);
}

void App::Menu() {

    Image image1 = LoadImage("textures/menu.png");
    Texture2D textureMenu = LoadTextureFromImage(image1);
    UnloadImage(image1);

    while (WindowShouldClose() == false) {
        if (IsKeyDown(KEY_SPACE)) {
            break;
        }

        BeginDrawing();
        ClearBackground(BLUE);

        DrawTexture(textureMenu, 0, 0, WHITE);
        DrawText(TextFormat("Press space to play"), SCREENSIZE.x/8, SCREENSIZE.y/2-SCREENSIZE.x/12, SCREENSIZE.x/24, WHITE);

        EndDrawing();
    }
}

void App::Run(bool debug) { // Main loop
    int vel = 1; // SPEED
    Velocity defaultvel = {-vel, -vel, vel, vel};
    Player* player1 = new Player({0, 0}, {4, 8}, defaultvel);
    player1->health = {100, 100};
    player1->LoadAsset();
    Camera2D camera ({0});
    camera.target = (Vector2) {player1->pos.absolute.x + 1.0f, player1->pos.absolute.y + 1.0f};
    camera.zoom = 4.0f;

    Tilemap* tilemap = new Tilemap();
    tilemap->pos.absolute = {-(tilemap->tilemapSize.x/2), -(tilemap->tilemapSize.y/2)}; // Player spawn (center)
    tilemap->LoadAssets(8);
    tilemap->Load();
    
    Structmap* structmap = new Structmap();
    structmap->pos.absolute = {-(structmap->structmapSize.x/2)+8, -(structmap->structmapSize.y/2)+8};
    structmap->LoadAssets(8);
    structmap->Load();

    // Damage box and animation (MOVE OUTSIDE THIS CLASS PLEASE)
    Tile* damageBox = new Tile(BLACK);
    Image image1 = LoadImage("textures/swipe/frame0000.png");
    Image image2 = LoadImage("textures/swipe/frame0001.png");
    Image image3 = LoadImage("textures/swipe/frame0002.png");
    Texture2D swipetexture1 = LoadTextureFromImage(image1);
    Texture2D swipetexture2 = LoadTextureFromImage(image2);
    Texture2D swipetexture3 = LoadTextureFromImage(image3);
    UnloadImage(image1);
    UnloadImage(image2);
    UnloadImage(image3);

    Image image4 = LoadImage("textures/swipe/right/frame0000.png");
    Image image5 = LoadImage("textures/swipe/right/frame0001.png");
    Image image6 = LoadImage("textures/swipe/right/frame0002.png");
    Texture2D swipetexture1R = LoadTextureFromImage(image4);
    Texture2D swipetexture2R = LoadTextureFromImage(image5);
    Texture2D swipetexture3R = LoadTextureFromImage(image6);
    UnloadImage(image4);
    UnloadImage(image5);
    UnloadImage(image6);

    Image image7 = LoadImage("textures/swipe/left/frame0000.png");
    Image image8 = LoadImage("textures/swipe/left/frame0001.png");
    Image image9 = LoadImage("textures/swipe/left/frame0002.png");
    Texture2D swipetexture1L = LoadTextureFromImage(image7);
    Texture2D swipetexture2L = LoadTextureFromImage(image8);
    Texture2D swipetexture3L = LoadTextureFromImage(image9);
    UnloadImage(image7);
    UnloadImage(image8);
    UnloadImage(image9);

    Image image10 = LoadImage("textures/swipe/down/frame0000.png");
    Image image11 = LoadImage("textures/swipe/down/frame0001.png");
    Image image12 = LoadImage("textures/swipe/down/frame0002.png");
    Texture2D swipetexture1D = LoadTextureFromImage(image10);
    Texture2D swipetexture2D = LoadTextureFromImage(image11);
    Texture2D swipetexture3D = LoadTextureFromImage(image12);
    UnloadImage(image10);
    UnloadImage(image11);
    UnloadImage(image12);

    damageBox->texture = swipetexture1;
    int damageBoxTime = 0;

    int decider;
    srand(time(0));

    Menu();

    while (WindowShouldClose() == false) {
        // Events; Player moves by moving the Tilemap itself
        camera.target = (Vector2) {player1->pos.absolute.x - static_cast<float>(SCREENSIZE.x/8), player1->pos.absolute.y - static_cast<float>(SCREENSIZE.y/8)};
        decider = GetRandomValue(1, 1024);

        player1->vel = {0, 0, 0, 0};
        if (IsKeyDown(KEY_RIGHT)) {
            player1->vel = {0, 0, vel, 0};
            player1->orientation = {0, 0, 1, 0};

            if (IsKeyDown(KEY_UP)) {
                player1->vel = {-vel, 0, 1, 0};
            }
            if (IsKeyDown(KEY_DOWN)) {
                player1->vel = {0, 0, vel, vel};
            }
        }
        else if (IsKeyDown(KEY_LEFT)) {
            player1->vel = {0, -vel, 0, 0};
            player1->orientation = {0, 1, 0, 0};

            if (IsKeyDown(KEY_UP)) {
                player1->vel = {-vel, -vel, 0, 0};
            }
            if (IsKeyDown(KEY_DOWN)) {
                player1->vel = {0, -vel, 0, vel};
            }
        }
        if (IsKeyDown(KEY_UP)) {
            player1->vel = {-vel, 0, 0, 0};
            player1->orientation = {1, 0, 0, 0};

            if (IsKeyDown(KEY_RIGHT)) {
                player1->vel = {-vel, 0, vel, 0};
            }
            if (IsKeyDown(KEY_LEFT)) {
                player1->vel = {-vel, -vel, 0, 0};
            }
        }
        else if (IsKeyDown(KEY_DOWN)) {
            player1->vel = {0, 0, 0, vel};
            player1->orientation = {0, 0, 0, 1};

            if (IsKeyDown(KEY_RIGHT)) {
                player1->vel = {0, 0, vel, vel};
            }
            if (IsKeyDown(KEY_LEFT)) {
                player1->vel = {0, -vel, 0, vel};
            }
        }

        if (IsKeyDown(KEY_SPACE) && damageBoxTime <= 0) {
            damageBoxTime = 16;
            if (player1->orientation.top) {
                damageBox->pos.absolute = {player1->pos.absolute.x, player1->pos.absolute.y - 8};
                damageBox->size = {16, 8};
            }
            else if (player1->orientation.bottom) {
                damageBox->pos.absolute = {player1->pos.absolute.x, player1->pos.absolute.y + 8};
                damageBox->size = {16, 8};
            }
            else if (player1->orientation.left) {
                damageBox->pos.absolute = {player1->pos.absolute.x - 8, player1->pos.absolute.y};
                damageBox->size = {8, 16};
            }
            else if (player1->orientation.right) {
                damageBox->pos.absolute = {player1->pos.absolute.x + 8, player1->pos.absolute.y};
                damageBox->size = {8, 16};
            }

        }

        player1->Move(tilemap, structmap, {-player1->GetVel().left, 0});
        player1->Move(tilemap, structmap, {-player1->GetVel().right, 0});
        player1->Move(tilemap, structmap, {0, -player1->GetVel().top});
        player1->Move(tilemap, structmap, {0, -player1->GetVel().bottom});

        // Enemy movement
        for (Enemy* enemy : structmap->enemiesStored) {
            enemy->Move({-player1->GetVel().left, 0});
            enemy->Move({-player1->GetVel().right, 0});
            enemy->Move({0, -player1->GetVel().top});
            enemy->Move({0, -player1->GetVel().bottom});
            enemy->iframes--;
        }

        if (decider == 1 && structmap->enemiesStored.size() < 3) {
            Enemy* newenemy = new Enemy({16, 16}, {32, 32}, defaultvel);
            newenemy->health = {100, 100};
            newenemy->pos.absolute = {32, 32};
            newenemy->LoadAsset();
            structmap->enemiesStored.push_back(newenemy);
        }
        if (decider <= 512) {
            for (Enemy* enemy : structmap->enemiesStored) {
                if (player1->GetPos().absolute.x < enemy->GetPos().absolute.x) {             
                    enemy->Move({-vel, 0});           
                }
                else if (player1->GetPos().absolute.x > enemy->GetPos().absolute.x) {
                    enemy->Move({vel, 0});              
                }
                if (player1->GetPos().absolute.y < enemy->GetPos().absolute.y) {            
                    enemy->Move({0, -vel});                    
                }
                else if (player1->GetPos().absolute.y > enemy->GetPos().absolute.y) {
                    enemy->Move({0, vel});                   
                }
            }
        }

        player1->iframes--;

        // Physics
        for (int i = 0; i < tilemap->tilesStored.size(); i++) {
            if (tilemap->tilesStored[i]->solid) {
                Physics::CollideTile(tilemap, structmap, player1, tilemap->tilesStored[i]);
            }
        }
        for (int i = 0; i < structmap->structuresStored.size(); i++) {
            if (structmap->structuresStored[i]->solid) {
                Physics::CollideStructure(tilemap, structmap, player1, structmap->structuresStored[i]);
            }
        }
        for (Enemy* enemy : structmap->enemiesStored) {
            if (player1->iframes <= 0 && Physics::CollideEnemy(player1, enemy)) {
                player1->iframes = 120;
                player1->health.x -= 10;
                if (player1->health.x <= 0) {
                    structmap->enemiesStored = {};
                    Menu();
                }
            }
            enemy->iframes--;
        }
        if (damageBoxTime > 0) {
            for (int i = 0; i < structmap->enemiesStored.size(); i++) {
                if (structmap->enemiesStored[i]->iframes <= 0 && Physics::CollideEnemyDamage(structmap->enemiesStored[i], damageBox)) {
                    structmap->enemiesStored[i]->iframes = 120;
                    damageBoxTime = 0;
                    structmap->enemiesStored[i]->health.x -= 10;
                    if (structmap->enemiesStored[i]->health.x <= 0) {
                        structmap->enemiesStored.erase(structmap->enemiesStored.begin() + i);
                    }
                }
            }
            
            if (damageBoxTime <= 4) {
                if (player1->orientation.top) {
                    damageBox->texture = swipetexture3;
                }
                else if (player1->orientation.right) {
                    damageBox->texture = swipetexture3R;
                }
                else if (player1->orientation.left) {
                    damageBox->texture = swipetexture3L;
                }
                else if (player1->orientation.bottom) {
                    damageBox->texture = swipetexture3D;
                }
            }
            else if (damageBoxTime <= 10) {
                if (player1->orientation.top) {
                    damageBox->texture = swipetexture2;
                }
                else if (player1->orientation.right) {
                    damageBox->texture = swipetexture2R;
                }
                else if (player1->orientation.left) {
                    damageBox->texture = swipetexture2L;
                }
                else if (player1->orientation.bottom) {
                    damageBox->texture = swipetexture2D;
                }
            }
            else if (damageBoxTime <= 16) {
                if (player1->orientation.top) {
                    damageBox->texture = swipetexture1;
                }
                else if (player1->orientation.right) {
                    damageBox->texture = swipetexture1R;
                }
                else if (player1->orientation.left) {
                    damageBox->texture = swipetexture1L;
                }
                else if (player1->orientation.bottom) {
                    damageBox->texture = swipetexture1D;
                }
            }
            damageBoxTime--;
            
        } else if (damageBoxTime <= 0) {
            damageBox->pos.absolute = {-128, -128};
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLUE);

        BeginMode2D(camera);
        
        tilemap->Render();
        structmap->Render();
        
        player1->Draw();

        damageBox->Draw();
        //DrawRectangleLines(damageBox->pos.absolute.x - damageBox->size.x/2, damageBox->pos.absolute.y - damageBox->size.y/2, damageBox->size.x, damageBox->size.y, WHITE);

        DrawRectangle(-SCREENSIZE.x/8 + 2, -SCREENSIZE.y/8 + 2, player1->health.y/4, 4, GRAY);
        DrawRectangle(-SCREENSIZE.x/8 + 2, -SCREENSIZE.y/8 + 2, player1->health.x/4, 4, RED);

        for (Enemy* enemy : structmap->enemiesStored) {
            enemy->Draw();
        }

        if (debug) {
            DrawText(TextFormat("HEALTH: %i", player1->health.x), -100, 64, 1, BLACK);
        }

        EndDrawing();
    }
    CloseWindow();
}