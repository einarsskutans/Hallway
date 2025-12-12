#include <raylib.h>
#include "lib/app.h"

int main() {
    App* app = new App();
    app->Init(SCREENSIZE, 60, false);
    app->Run(true);

    return 0;
}