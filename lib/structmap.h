#ifndef STRUCTMAP_H
#define STRUCTMAP_H

#include <raylib.h>
#include "sprite.h"
#include "structure.h"
#include "structmap.h"
#include "asset.h"

#include "string"
#include "iostream"
#include "sstream" // for reading CSV
#include "fstream"

class Structmap {
    public:
        Structmap();
        std::vector<std::vector<int>> readStructmap(const std::string& filename);
        std::vector<Asset*> readAssets(const std::string& filename);
        void GenerateStructmap(const std::string& filename, Point mapSize);
        void LoadAssets(int n);
        void LoadStructures();
        void UnloadAssets();
        void Load();
        void Render();
        void Move(Point newpos);
        Pos pos;
        std::vector<Structure*> structuresStored;
        std::vector<std::vector<int>> textureMap;
        std::vector<std::vector<int>> data;

        std::vector<Asset*> assetsStored;

        int tilesize = 8;

        enum tileTypes {
            GRASS = 0,
            STONE = 1,
            STONE_WALL_BOTTOM = 2,
            WATER = 3
        };
    private:
};

#endif
