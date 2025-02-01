#include "tilemap.h"

Tilemap::Tilemap() {
    pos.absolute.x = 0;
    pos.absolute.y = 0;
    pos.relative.x = 0;
    pos.relative.y = 0;
}

void Tilemap::Load(std::vector<std::vector<int>> map) {
    currentMap = map;
}
void Tilemap::Render() {
    Color color; // Substitute for textures
    pos.relative.x = 0;
    pos.relative.y = 0;
    for (std::vector<int> stateY : currentMap) {
        for (int stateX : stateY) {
            switch (stateX)
            {
            case 0:
                color = GREEN;
                break;
            case 1:
                color = BLUE;
                break;
            default:
                color  = BLACK;
                break;
            }
            DrawRectangle(pos.absolute.x + pos.relative.x, pos.absolute.y + pos.relative.y, 32, 32, color);
            pos.relative.x += 32;
        }
        pos.relative.x = 0;
        pos.relative.y += 32;
    }
}

void Tilemap::Move(Point newpos) {
    pos.absolute.x = pos.absolute.x + newpos.x;
    pos.absolute.y = pos.absolute.y + newpos.y;
}
