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

const Point SCREENSIZE = {1280, 720};

class App {
    public:
        void Init(Point newScreensize, int fps, bool debug);
        void Run(bool debug);
    private:
        Point screensize;
};

#endif