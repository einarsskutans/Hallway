#ifndef APP_H
#define APP_H

#include <utility>
#include <raylib.h>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <math.h>

#include "physics.h"
#include "sprite.h"
#include "tilemap.h"
#include "tile.h"
#include "asset.h"
#include "structure.h"
#include "structmap.h"
#include "enemy.h"
#include "hud.h"

const Point SCREENSIZE = {1440, 720};
const float SCALE = 4;

class App {
    public:
        void Init(int fps, bool debug);
        void Menu();
        void Run(bool debug);
    private:
        bool mainloop = false;
};

#endif