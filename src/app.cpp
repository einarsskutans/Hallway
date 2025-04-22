#include "app.h"

Point operator/(const Point&a, const int&b) {
    return Point{a.x/b, a.y/b};
}

void App::Init(Point newScreensize, int fps, bool debug) {
    screensize = newScreensize;
    InitWindow(screensize.x, screensize.y, "test");
    SetTargetFPS(fps);
}
void App::Run(bool debug) { // Main loop
    int vel = 2; // SPEED
    Velocity defaultvel = {-vel, -vel, vel, vel};
    Player* player1 = new Player(SCREENSIZE/2, {32, 32}, defaultvel);
    Tilemap* tilemap = new Tilemap();
    tilemap->pos.absolute = SCREENSIZE/2; // Player spawn
    tilemap->LoadAssets(4);
    tilemap->Load();

    srand(time(0));

    while (WindowShouldClose() == false){
        // Events; Player moves by moving the Tilemap itself
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
        ClearBackground(GRAY);
        
        tilemap->Render();
        player1->Draw();

        if (debug) {
            DrawRectangle(5, 5, 145, 100, GRAY);
            DrawRectangle(5+2, 5+2, 145-4, 100-4, WHITE);
            DrawText(TextFormat("TOP: %i", player1->vel.top), 5+4, 10, 20, BLACK);
            DrawText(TextFormat("BOTTOM: %i", player1->vel.bottom), 5+4, 30, 20, BLACK);
            DrawText(TextFormat("LEFT: %i", player1->vel.left), 5+4, 50, 20, BLACK);
            DrawText(TextFormat("RIGHT: %i", player1->vel.right), 5+4, 70, 20, BLACK);
        }

        EndDrawing();
    }
    CloseWindow();
}