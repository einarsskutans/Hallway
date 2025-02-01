#include "tilemap.h"

Tilemap::Tilemap() {

}

void Tilemap::Load(std::vector<std::vector<int>> map) {
    currentMap = map;
}
void Tilemap::Render() {
    std::pair<int, int> posRelative = {0, 0};
    Color color; // Substitute for textures
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
            DrawRectangle(pos.first + posRelative.first, pos.second + posRelative.second, 64, 64, color);
            posRelative.first += 64;
        }
        posRelative.first = 0;
        posRelative.second += 64;
    }
}

void Tilemap::Move(std::pair<int, int> newpos) {
    pos.first = pos.first + newpos.first;
    pos.second = pos.second + newpos.second;
}
