#ifndef VELOCITY_H
#define VELOCITY_H

#include <utility>
#include <vector>

enum sides {
    TOP = 0,
    LEFT = 1,
    RIGHT = 2,
    BOTTOM = 3
};

class Velocity {
    public:
        Velocity();
        Velocity(int newtop, int newleft, int newright, int newbottom);
        int top;
        int left;
        int right;
        int bottom;

        std::vector<int> active = {0, 0, 0, 0};
};

#endif