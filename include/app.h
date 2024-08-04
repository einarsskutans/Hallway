#ifndef APP_H
#define APP_H

#include <utility>
#include <raylib.h>
#include "player.h"
#include "physics.h"

const std::pair<int, int> SCREENSIZE = {540, 540};

class App {
    public:
        void Init(std::pair<int, int> newScreensize, int fps, bool debug);
        void Run();

    private:
        std::pair<int, int> screensize;
};

#endif