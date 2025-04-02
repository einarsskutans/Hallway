#ifndef TILEMAP_H
#define TILEMAP_H

#include <raylib.h>
#include "sprite.h"
#include "app.h"
#include "tile.h"
#include "string"
#include "iostream"

#include "sstream" // for reading CSV
#include "fstream"


class Tilemap {
    public:
        Tilemap();
        void GenerateMap(int bg, int size);
        void readCSV();
        void Load();
        void Render();
        void Move(Point newpos);
        Pos pos;
        std::vector<Tile*> tilesStored = {};
        std::vector<std::vector<int>> textureMap = {};
        std::vector<std::vector<int>> data;
    private:
};

#endif

// {1, 1, 1, 0, 1, 1}
// {0, 0, 0, 1, 1, 0}