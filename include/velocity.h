#ifndef VELOCITY_H
#define VELOCITY_H

#include <utility>

class Velocity {
    public:
        Velocity();
        Velocity(std::pair<int, bool> newtop, std::pair<int, bool> newleft, std::pair<int, bool> newright, std::pair<int, bool> newbottom);
        std::pair<int, bool> top;
        std::pair<int, bool> left;
        std::pair<int, bool> right;
        std::pair<int, bool> bottom;
};

#endif