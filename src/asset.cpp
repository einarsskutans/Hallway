#include "asset.h"

Asset::Asset() {
}

Asset::Asset(Texture2D texture, std::string path, std::string name, int id) {
    texture = texture;
    path = path;
    name = name;
    id = id;
}
