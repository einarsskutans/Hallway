#ifndef APP_H
#define APP_H

#include <utility>

class App {
    public:
        void Init(std::pair<int, int> newScreensize, int fps, bool debug);
        void Run();

    private:
        std::pair<int, int> screensize;
};

#endif