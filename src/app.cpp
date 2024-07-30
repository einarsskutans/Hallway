#include <raylib.h>
#include "include/app.h"

void App::Init(std::pair<int, int> newScreensize, int fps, bool debug) {
    screensize = newScreensize;
    InitWindow(screensize.first, screensize.second, "test");
    SetTargetFPS(fps);
}
void App::Run() { // Main loop
    Player* player1 = new Player({50, 50}, {25, 25}, {0, 0});

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(WHITE);

        player1->Draw();

        EndDrawing();
    }
}