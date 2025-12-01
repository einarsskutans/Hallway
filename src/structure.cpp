#include "lib/structure.h"

Structure::Structure() {

}

void Structure::Draw(Pos structmapPos) {
    DrawTexture(texture, structmapPos.absolute.x + GetPos().absolute.x-size.x/2, structmapPos.absolute.y + GetPos().absolute.y-size.y/2, WHITE);
}