#ifndef ASSET_H
#define ASSET_H

#include <raylib.h>
#include <string>

class Asset {
    public:
        Asset();
        Asset(Texture2D texture, std::string name, int id);

        Texture2D texture;
        std::string name;
        int id;
};

#endif
