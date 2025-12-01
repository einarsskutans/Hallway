#include "lib/structure.h"

Structure::Structure() {

}

void Structure::Draw() {
    DrawTexture(texture, pos.absolute.x-size.x/2, pos.absolute.y-size.y/2, WHITE);
}