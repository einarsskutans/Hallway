#ifndef SPRITE_H
#define SPRITE_H

#include "utility"

class Sprite {
    public:
        void Move(std::pair<int, int> newpos);
        void SetPos(std::pair<int, int> newpos);
        void SetSize(std::pair<int, int> newsize);
        void SetVel(std::pair<int, int> newvel);
        void SetDrawable(bool newdrawable);
        void SetMovable(bool newmovable);
        std::pair<int, int> GetPos();
        std::pair<int, int> GetSize();
        std::pair<int, int> GetVel();
        bool GetDrawable();
        bool GetMovable();
    private:
        std::pair<int, int> pos;
        std::pair<int, int> size;
        std::pair<int, int> vel;
        bool drawable;
        bool movable;
};

#endif