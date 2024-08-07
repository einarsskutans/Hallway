#include "include/velocity.h"

Velocity::Velocity() {}
Velocity::Velocity(std::pair<int, bool> newtop, std::pair<int, bool> newleft, std::pair<int, bool> newright, std::pair<int, bool> newbottom) {
    top = newtop;
    left = newleft;
    right = newright;
    bottom = newbottom;
}