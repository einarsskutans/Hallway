#include "include/app.h"

void App::Init(std::pair<int, int> newScreensize, int fps, bool debug) {
    screensize = newScreensize;
    InitWindow(screensize.first, screensize.second, "test");
    SetTargetFPS(fps);
}
void App::Run() { // Main loop
    Player* player1 = new Player({270, 270}, {64, 64}, {16, 16});

    while (WindowShouldClose() == false){
        // Events
        if (IsKeyDown(KEY_RIGHT)) player1 -> Move({player1->GetVel().first, 0});
        if (IsKeyDown(KEY_LEFT)) player1 -> Move({-player1->GetVel().first, 0});
        if (IsKeyDown(KEY_UP)) player1 -> Move({0, -player1->GetVel().second});
        if (IsKeyDown(KEY_DOWN)) player1 -> Move({0, player1->GetVel().second});
        Physics::CollideBounds(player1, {32, 32});

        // Draw
        BeginDrawing();
        ClearBackground(GRAY);

        DrawLine(32, 0, 32, SCREENSIZE.second, GREEN);
        DrawLine(SCREENSIZE.first-32, 0, SCREENSIZE.first-32, SCREENSIZE.second, GREEN);
        DrawLine(0, 32, SCREENSIZE.first, 32, GREEN);
        DrawLine(0, SCREENSIZE.second-32, SCREENSIZE.first, SCREENSIZE.second-32, GREEN);
        player1->Draw();

        EndDrawing();
    }
    CloseWindow();
}