#include "lib/app.h"

Point operator/(const Point&a, const int&b) {
    return Point{a.x/b, a.y/b};
}

void App::Init(Point newScreensize, int fps, bool debug) {
    screensize = newScreensize;
    InitWindow(screensize.x, screensize.y, "Hallway");
    SetTargetFPS(fps);
}
void App::Run(bool debug) { // Main loop
    int vel = 1; // SPEED
    Velocity defaultvel = {-vel, -vel, vel, vel};
    Player* player1 = new Player(SCREENSIZE/8, {8, 8}, defaultvel);
    Camera2D camera ({0});
    camera.target = (Vector2) {player1->pos.absolute.x + 1.0f, player1->pos.absolute.y + 1.0f};
    camera.zoom = 4.0f;
    Tilemap* tilemap = new Tilemap();
    tilemap->pos.absolute = SCREENSIZE/2; // Player spawn
    tilemap->LoadAssets(4);
    tilemap->Load();

    srand(time(0));

    while (WindowShouldClose() == false){
        // Events; Player moves by moving the Tilemap itself
        camera.target = (Vector2) {player1->pos.absolute.x - static_cast<float>(SCREENSIZE.x/8), player1->pos.absolute.y - static_cast<float>(SCREENSIZE.y/8)};

        player1->vel = {0, 0, 0, 0};
        if (IsKeyDown(KEY_RIGHT)) {
            player1->vel = {0, 0, vel, 0};

            if (IsKeyDown(KEY_UP)) {
                player1->vel = {-vel, 0, 1, 0};
            }
            if (IsKeyDown(KEY_DOWN)) {
                player1->vel = {0, 0, vel, vel};
            }
        }
        else if (IsKeyDown(KEY_LEFT)) {
            player1->vel = {0, -vel, 0, 0};

            if (IsKeyDown(KEY_UP)) {
                player1->vel = {-vel, -vel, 0, 0};
            }
            if (IsKeyDown(KEY_DOWN)) {
                player1->vel = {0, -vel, 0, vel};
            }
        }
        if (IsKeyDown(KEY_UP)) {
            player1->vel = {-vel, 0, 0, 0};

            if (IsKeyDown(KEY_RIGHT)) {
                player1->vel = {-vel, 0, vel, 0};
            }
            if (IsKeyDown(KEY_LEFT)) {
                player1->vel = {-vel, -vel, 0, 0};
            }
        }
        else if (IsKeyDown(KEY_DOWN)) {
            player1->vel = {0, 0, 0, vel};

            if (IsKeyDown(KEY_RIGHT)) {
                player1->vel = {0, 0, vel, vel};
            }
            if (IsKeyDown(KEY_LEFT)) {
                player1->vel = {0, -vel, 0, vel};
            }
        }

        player1->Move(tilemap, {-player1->GetVel().left, 0});
        player1->Move(tilemap, {-player1->GetVel().right, 0});
        player1->Move(tilemap, {0, -player1->GetVel().top});
        player1->Move(tilemap, {0, -player1->GetVel().bottom});

        for (int i = 0; i < tilemap->tilesStored.size(); i++) {
            if (tilemap->tilesStored[i]->solid) {
                Physics::CollideTile(tilemap, player1, tilemap->tilesStored[i]);
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLUE);

        BeginMode2D(camera);
        
        tilemap->Render();
        player1->Draw();

        if (debug) {
            DrawRectangle(1, 1, 60, 42, GRAY);
            DrawRectangle(1+1, 1+1, 60-2, 42-2, WHITE);
            DrawText(TextFormat("TOP: %i", player1->vel.top), 1+1, 2, 1, BLACK);
            DrawText(TextFormat("BOTTOM: %i", player1->vel.bottom), 1+1, 12, 1, BLACK);
            DrawText(TextFormat("LEFT: %i", player1->vel.left), 1+1, 22, 1, BLACK);
            DrawText(TextFormat("RIGHT: %i", player1->vel.right), 1+1, 32, 1, BLACK);
        }

        EndDrawing();
    }
    CloseWindow();
}