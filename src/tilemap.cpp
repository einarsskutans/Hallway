#include "tilemap.h"

Tilemap::Tilemap() {
    std::srand(std::time({}));
    pos.absolute.x = 0;
    pos.absolute.y = 0;
    pos.relative.x = 0;
    pos.relative.y = 0;
}

void Tilemap::readCSV() {
    std::fstream fin;

    // Open an existing file
    fin.open("src/map1.csv", std::ios::in);

    // Read the Data from the file
    // as String Vector
    std::vector<std::vector<std::string>> newdata;
    std::vector<std::string> row;
    std::string line, word, temp;

    while (fin >> temp)
    {
        row.clear();
        getline(fin, line);

        
        std::stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        newdata.push_back(row);
    }
    for (std::vector<std::string> rowp : newdata) {
        std::vector<int> newvector;
        for (std::string s : rowp) {
            newvector.push_back(std::stoi(s));
        }
        textureMap.push_back(newvector);
    }
    fin.close();
}

void Tilemap::Load()
{
    tilesStored = {};
    Color randcolor = BLACK;

    readCSV();
    //textureMap = data;

    /* Randomly generate texturemap (test only)
    for (int i = 0; i < size; i++) {
        std::vector<int> column = {};
        for (int j = 0; j < size; j++) {
            int randint = std::rand()%10;
            column.push_back(randint);
        }
        textureMap.push_back(column);
    }*/

    // Render tilemap -> tiles -> colors
    for (int j = 0; j < textureMap.size(); j++) {
        for (int i = 0; i < textureMap[j].size(); i++) {
            switch (textureMap[j][i]) {
            case 0:
                randcolor = GREEN;
                break;
            case 1:
                randcolor = BLUE;
                break;
            case 2:
                randcolor = GREEN;
                break;
            case 3:
                randcolor = BLACK;
                break;
            default:
                randcolor = YELLOW;
                break;
            }
            Tile* newtile = new Tile(randcolor);
            newtile->pos.absolute.x += i*32;
            newtile->pos.absolute.y += j*32;
            tilesStored.push_back(newtile);
        }
    }
}
void Tilemap::Render() {
    Color color; // Substitute for textures
    for (Tile* tile : tilesStored) {
        tile->Draw();
    }
}

void Tilemap::Move(Point newpos) {
    for (Tile* tile : tilesStored) {
        tile->pos.absolute.x += newpos.x;
        tile->pos.absolute.y += newpos.y;
    }
}
