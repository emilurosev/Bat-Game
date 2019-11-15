#pragma once

#include <cmath>

#include "AnimatedGameObject.h"
#include "util.h"

class SpriteZ4 : public AnimatedGameObject {
    public:
        SpriteZ4();
        virtual void move(int dx, int dy);
        //virtual void draw();
    protected:
        MoveStates currentState;
        int rScale = 1;
        double angle = 0;
        double r = 0;
        double centerX = 0;
        double centerY = 0;
        virtual void nextState();
};

