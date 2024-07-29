#include <raylib.h>
#include "app.h"

int main () {
    App* app = new App();
    app->Init({540, 540}, 60, false);
    app->Run();
    CloseWindow();
    return 0;
}