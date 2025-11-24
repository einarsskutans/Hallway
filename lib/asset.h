#ifndef ASSET_H
#define ASSET_H

#include <raylib.h>
#include <string>

class Asset {
    public:
        Asset();
        Asset(Texture2D texture, std::string path, std::string name, int id, bool solid);

        Texture2D texture;
        std::string path;
        std::string name;
        int id;
        bool solid;
};

#endif
