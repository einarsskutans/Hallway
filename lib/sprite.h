#ifndef SPRITE_H
#define SPRITE_H

#include <utility>
#include <raylib.h>
#include <string>
#include "velocity.h"

class Point {
    public:
        signed int x = 0;
        signed int y = 0;
};

class Pos {
    public:
        Point absolute;
        Point relative;
};

class Sprite {
    public:    
        void Move(Point newpos);
        void SetPos(Point newpos);
        void SetSize(Point newsize);
        void SetVel(Velocity newvel);
        void SetDrawable(bool newdrawable);
        void SetMovable(bool newmovable);
        void LoadAnimationFrames(const char* pathToFolder, int n);
        Pos GetPos();
        Point GetSize();
        Velocity GetVel();
        bool GetDrawable();
        bool GetMovable();
        virtual void Draw();
        friend class Physics;

        Velocity vel;
        Velocity blocked;
        Pos pos;
        Point size;
        Point health;
        std::vector<Texture2D> textureFrames;

        int sides = 1;
        int framesPerSide = 1;
        int iframes = 0;
        bool drawable;
        bool movable;
};

#endif