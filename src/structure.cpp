#include "lib/structure.h"

Structure::Structure() {

}

void Structure::Draw() {
    DrawTexture(texture, GetPos().absolute.x-size.x/2, GetPos().absolute.y-size.y/2, WHITE);
}