#ifndef VELOCITY_H
#define VELOCITY_H

#include <utility>

class Velocity {
    public:
        Velocity();
        Velocity(int newtop, int newleft, int newright, int newbottom);
        int top;
        int left;
        int right;
        int bottom;
};

#endif