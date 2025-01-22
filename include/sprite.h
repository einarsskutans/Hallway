#ifndef SPRITE_H
#define SPRITE_H

#include <utility>
#include <raylib.h>
#include "velocity.h"

class Sprite {
    public:    
        void Move(std::pair<int, int> newpos);
        void SetPos(std::pair<int, int> newpos);
        void SetSize(std::pair<int, int> newsize);
        void SetVel(Velocity newvel);
        void SetDrawable(bool newdrawable);
        void SetMovable(bool newmovable);
        std::pair<int, int> GetPos();
        std::pair<int, int> GetSize();
        Velocity GetVel();
        bool GetDrawable();
        bool GetMovable();
        virtual void Draw();
        friend class Physics;
    private:
        Velocity vel;
        std::pair<int, int> pos;
        std::pair<int, int> size;
        bool drawable;
        bool movable;
};

#endif