#ifndef TILEMAP_H
#define TILEMAP_H

#include <raylib.h>
#include "sprite.h"
#include "tile.h"
#include "tilemap.h"
#include "asset.h"

#include "string"
#include "iostream"
#include "sstream" // for reading CSV
#include "fstream"

class Tilemap {
    public:
        Tilemap();
        std::vector<std::vector<int>> readTilemap(const std::string& filename);
        std::vector<Asset*> readAssets(const std::string& filename);
        void GenerateTileMap(const std::string& filename, Point mapSize);
        void LoadAssets(int n);
        void LoadTiles();
        void UnloadAssets();
        void Load();
        void Render();
        void Move(Point newpos);
        Pos pos;
        std::vector<Tile*> tilesStored;
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
