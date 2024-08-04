#include <raylib.h>
#include "include/app.h"

int main () {
    App* app = new App();
    app->Init(SCREENSIZE, 60, false);
    app->Run();
    return 0;
}