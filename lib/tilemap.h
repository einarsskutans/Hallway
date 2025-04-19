#ifndef TILEMAP_H
#define TILEMAP_H

#include <raylib.h>
#include "sprite.h"
#include "tile.h"
#include "tilemap.h"

#include "string"
#include "iostream"
#include "sstream" // for reading CSV
#include "fstream"

class Tilemap {
    public:
        Tilemap();
        std::vector<std::vector<int>> readCSV(const std::string& filename);
        void LoadAssets(int n);
        void UnloadAssets();
        void Load();
        void Render();
        void Move(Point newpos);
        Pos pos;
        std::vector<Tile*> tilesStored = {};
        std::vector<std::vector<int>> textureMap;
        std::vector<std::vector<int>> data;

        std::vector<Texture2D> assetMap;
    private:
};

#endif

// {1, 1, 1, 0, 1, 1}
// {0, 0, 0, 1, 1, 0}