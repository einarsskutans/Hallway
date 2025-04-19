#include "asset.h"

Asset::Asset() {
}

Asset::Asset(Texture2D texture, std::string name, int id) {
    texture = texture;
    name = name;
    id = id;
}
