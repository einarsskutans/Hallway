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
        void GenerateStructmap(const std::string& filename);
        void LoadAssets(int n);
        void LoadStructures();
        void UnloadAssets();
        void Load();
        void Render();
        void Move(Point newpos);
        Pos pos;
        Point mapSize = {32, 32};
        Point structmapSize = {mapSize.x*tilesize, mapSize.y*tilesize};
        std::vector<Structure*> structuresStored;
        std::vector<std::vector<int>> textureMap;
        std::vector<std::vector<int>> data;

        std::vector<Asset*> assetsStored;

        int tilesize = 8;

        enum structureSpawnRate { // 0 - 100 as in %
            CHANCE_HOUSE = 4,
            CHANCE_BUSH = 100,
        };
};

#endif
