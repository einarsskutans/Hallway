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
    int player_speed = 1;
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

    int frame = 0;
    int decider;
    srand(time(0));

    Menu();

    while (WindowShouldClose() == false) {
        frame++;
        if (frame > 60) {frame = 0; player_speed = 1;}

        // Events; Player moves by moving the Tilemap itself
        camera.target = (Vector2) {player1->pos.absolute.x - static_cast<float>(SCREENSIZE.x/8), player1->pos.absolute.y - static_cast<float>(SCREENSIZE.y/8)};
        decider = GetRandomValue(1, 1024);

        // Player movement & keydowns
        player1->vel = {0, 0, 0, 0};
        if (IsKeyDown(KEY_RIGHT)) {
            player1->vel = {0, 0, player_speed, 0};
            if (!player1->orientationLock) player1->orientation = {0, 0, 1, 0};

            if (IsKeyDown(KEY_UP)) {
                player1->vel = {-player_speed, 0, 1, 0};
            }
            if (IsKeyDown(KEY_DOWN)) {
                player1->vel = {0, 0, player_speed, player_speed};
            }
        }
        else if (IsKeyDown(KEY_LEFT)) {
            player1->vel = {0, -player_speed, 0, 0};
            if (!player1->orientationLock) player1->orientation = {0, 1, 0, 0};

            if (IsKeyDown(KEY_UP)) {
                player1->vel = {-player_speed, -player_speed, 0, 0};
            }
            if (IsKeyDown(KEY_DOWN)) {
                player1->vel = {0, -player_speed, 0, player_speed};
            }
        }
        if (IsKeyDown(KEY_UP)) {
            player1->vel = {-player_speed, 0, 0, 0};
            if (!player1->orientationLock) player1->orientation = {1, 0, 0, 0};

            if (IsKeyDown(KEY_RIGHT)) {
                player1->vel = {-player_speed, 0, player_speed, 0};
            }
            if (IsKeyDown(KEY_LEFT)) {
                player1->vel = {-player_speed, -player_speed, 0, 0};
            }
        }
        else if (IsKeyDown(KEY_DOWN)) {
            player1->vel = {0, 0, 0, player_speed};
            if (!player1->orientationLock) player1->orientation = {0, 0, 0, 1};

            if (IsKeyDown(KEY_RIGHT)) {
                player1->vel = {0, 0, player_speed, player_speed};
            }
            if (IsKeyDown(KEY_LEFT)) {
                player1->vel = {0, -player_speed, 0, player_speed};
            }
        }

        if (IsKeyDown(KEY_SPACE) && player1->damageBoxTime <= 0) {
            player1->Attack(15, structmap);
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
            Enemy* newenemy = new Enemy({32, 32}, {32, 32}, defaultvel);
            newenemy->health = {100, 100};
            newenemy->pos.absolute = {GetRandomValue(0, structmap->mapSize.x), GetRandomValue(0, structmap->mapSize.y)};
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
        for (unsigned int i = 0; i < tilemap->tilesStored.size(); i++) {
            if (tilemap->tilesStored[i]->solid) {
                Physics::CollideTile(tilemap, structmap, player1, tilemap->tilesStored[i]);
            }
        }

        for (unsigned int i = 0; i < tilemap->tilesStored.size(); i++) {
            if (tilemap->tilesStored[i]->tile_type == "water") {
                if (player1->iframes <= 0 && Physics::CollideSpriteCheck(player1, tilemap->tilesStored[i])) {
                    player1->iframes = 120;
                    player1->health.x -= 10;
                    if (frame%2 == 0) player_speed = 0;
                    else {player_speed = 1;}
                }
                else if (Physics::CollideSpriteCheck(player1, tilemap->tilesStored[i])) {
                    if (frame%2 == 0) player_speed = 0;
                    else {player_speed = 1;}
                }
            }
        }
        
        for (unsigned int i = 0; i < structmap->structuresStored.size(); i++) {
            if (structmap->structuresStored[i]->solid) {
                Physics::CollideStructure(tilemap, structmap, player1, structmap->structuresStored[i]);
            }
        }
        for (Enemy* enemy : structmap->enemiesStored) {
            if (player1->iframes <= 0 && Physics::CollideEnemy(player1, enemy)) {
                player1->iframes = 120;
                player1->health.x -= 10;
            }
            enemy->iframes--;
        }

        if (player1->health.x <= 0) {
            structmap->enemiesStored = {};
            Menu();
        }

        player1->UpdateAnimation(structmap);

        // Draw
        BeginDrawing();
        ClearBackground(BLUE);
        BeginMode2D(camera);
        
        tilemap->Render();
        structmap->Render();
        
        player1->Draw();
        player1->damageBox->Draw();

        for (Enemy* enemy : structmap->enemiesStored) {
            enemy->Draw();
        }

        if (debug) {
            
        }

        EndDrawing();
    }
    CloseWindow();
}