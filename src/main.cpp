#include <raylib.h>
#include "app.h"

int main () {
    App* app = new App();
    app->Init(SCREENSIZE, 60, false);
    app->Run(false); 
    return 0;
}