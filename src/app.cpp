#include <raylib.h>
#include "include/app.h"

void App::Init(std::pair<int, int> newScreensize, int fps, bool debug) {
    screensize = newScreensize;
    InitWindow(screensize.first, screensize.second, "test");
    SetTargetFPS(fps);
}
void App::Run() {
    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(WHITE);

        

        EndDrawing();
    }
}