#include "app.h"

Point operator/(const Point&a, const int&b) {
    return Point{a.x/b, a.y/b};
}

void App::Init(Point newScreensize, int fps, bool debug) {
    screensize = newScreensize;
    InitWindow(screensize.x, screensize.y, "test");
    SetTargetFPS(fps);
}
void App::Run() { // Main loop
    int vel = 4; // SPEED
    Velocity defaultvel = {{-vel, true}, {-vel, true}, {vel, true}, {vel, true}};
    Player* player1 = new Player(SCREENSIZE/2, {32, 32}, defaultvel);
    Tilemap* tilemap = new Tilemap();
    tilemap->Load();
    Point bounds = {64, 64};
    srand(time(0));

    while (WindowShouldClose() == false){
        /* Events; Player moves by moving the Tilemap itself
        Physics::CollideBounds(player1, bounds, true);
        if (IsKeyDown(KEY_RIGHT) && player1->GetVel().right.second) tilemap -> Move({player1->GetVel().left.first, 0});
        if (IsKeyDown(KEY_LEFT) && player1->GetVel().left.second) tilemap -> Move({player1->GetVel().right.first, 0});
        if (IsKeyDown(KEY_UP) && player1->GetVel().top.second) tilemap -> Move({0, player1->GetVel().bottom.first});
        if (IsKeyDown(KEY_DOWN) && player1->GetVel().bottom.second) tilemap -> Move({0, player1->GetVel().top.first});
        */
        if (IsKeyDown(KEY_RIGHT) && player1->GetVel().right.second) player1 -> Move(tilemap, {player1->GetVel().left.first, 0});
        if (IsKeyDown(KEY_LEFT) && player1->GetVel().left.second) player1 -> Move(tilemap, {player1->GetVel().right.first, 0});
        if (IsKeyDown(KEY_UP) && player1->GetVel().top.second) player1 -> Move(tilemap, {0, player1->GetVel().bottom.first});
        if (IsKeyDown(KEY_DOWN) && player1->GetVel().bottom.second) player1 -> Move(tilemap, {0, player1->GetVel().top.first});
        // Draw
        BeginDrawing();
        ClearBackground(GRAY);

        DrawText(TextFormat("Tilemap pos %i %i %i %i", tilemap->pos.absolute.x, tilemap->pos.absolute.y, tilemap->pos.relative.x, tilemap->pos.relative.y), 10, 10, 20, BLACK);
        DrawText(TextFormat("Tilemap size %i", tilemap->textureMap.size()), 10, 30, 20, BLACK);
        DrawText(TextFormat("Tilemap element %i", tilemap->textureMap[0][1]), 10, 50, 20, BLACK);
        DrawText(TextFormat("DATA %i", tilemap->data.size()), 10, 80, 20, BLACK);

        tilemap->Render();
        player1->Draw();

        EndDrawing();
    }
    CloseWindow();
}