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
void App::Run(bool debug) { // Main loop
    int vel = 1; // SPEED
    Velocity defaultvel = {-vel, -vel, vel, vel};
    Player* player1 = new Player({0, 0}, {8, 8}, defaultvel);
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

    srand(time(0));

    while (WindowShouldClose() == false){
        // Events; Player moves by moving the Tilemap itself
        camera.target = (Vector2) {player1->pos.absolute.x - static_cast<float>(SCREENSIZE.x/8), player1->pos.absolute.y - static_cast<float>(SCREENSIZE.y/8)};

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

        player1->Move(tilemap, structmap, {-player1->GetVel().left, 0});
        player1->Move(tilemap, structmap, {-player1->GetVel().right, 0});
        player1->Move(tilemap, structmap, {0, -player1->GetVel().top});
        player1->Move(tilemap, structmap, {0, -player1->GetVel().bottom});

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

        // Draw
        BeginDrawing();
        ClearBackground(BLUE);

        BeginMode2D(camera);
        
        tilemap->Render();
        structmap->Render();
        
        player1->Draw();

        if (debug) {
            DrawText(TextFormat("TILEX: %i", tilemap->tilesStored[0]->pos.absolute.x), -100, 32, 1, BLACK);
        }

        EndDrawing();
    }
    CloseWindow();
}