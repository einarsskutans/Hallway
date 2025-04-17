#ifndef APP_H
#define APP_H

#include <utility>
#include <raylib.h>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "physics.h"
#include "sprite.h"
#include "tilemap.h"
#include "tile.h"

const Point SCREENSIZE = {540, 540};

class App {
    public:
        void Init(Point newScreensize, int fps, bool debug);
        void Run();
    private:
        Point screensize;
};

#endif