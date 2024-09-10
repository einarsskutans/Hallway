#include "app.h"

std::pair<int, int> operator/(const std::pair<int, int>&a, const int&b) {
    return std::make_pair(a.first/b, a.second/b);
}

void App::Init(std::pair<int, int> newScreensize, int fps, bool debug) {
    screensize = newScreensize;
    InitWindow(screensize.first, screensize.second, "test");
    SetTargetFPS(fps);
}
void App::Run() { // Main loop
    int vel = 16;
    Velocity defaultvel = {{-vel, true}, {-vel, true}, {vel, true}, {vel, true}};
    Player* player1 = new Player(SCREENSIZE/2, {64, 64}, defaultvel);

    while (WindowShouldClose() == false){
        // Events
        Physics::CollideBounds(player1, {128, 32}, true);
        if (IsKeyDown(KEY_RIGHT) && player1->GetVel().right.second) player1 -> Move({player1->GetVel().right.first, 0});
        if (IsKeyDown(KEY_LEFT) && player1->GetVel().left.second) player1 -> Move({player1->GetVel().left.first, 0});
        if (IsKeyDown(KEY_UP) && player1->GetVel().top.second) player1 -> Move({0, player1->GetVel().top.first});
        if (IsKeyDown(KEY_DOWN) && player1->GetVel().bottom.second) player1 -> Move({0, player1->GetVel().bottom.first});

        // Draw
        BeginDrawing();
        ClearBackground(GRAY);

        player1->Draw();

        EndDrawing();
    }
    CloseWindow();
}