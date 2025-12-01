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
        void GenerateTileMap(const std::string& filename);
        void LoadAssets(int n);
        void LoadTiles();
        void UnloadAssets();
        void Load();
        void Render();
        void Move(Point newpos);
        Pos pos;
        Point mapSize = {128, 128};
        Point tilemapSize {mapSize.x*tilesize, mapSize.y*tilesize};
        std::vector<Tile*> tilesStored;
        std::vector<std::vector<int>> textureMap;
        std::vector<std::vector<int>> data;

        std::vector<Asset*> assetsStored;

        int tilesize = 8;
};

#endif
