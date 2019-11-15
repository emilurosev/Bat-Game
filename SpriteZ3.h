#pragma once

#include "AnimatedGameObject.h"
#include "cstdlib"
#include "util.h"

class SpriteZ3 : public AnimatedGameObject {
    public:
    SpriteZ3();
    virtual void move(int dx, int dy);
    //virtual void drawSpriteZ3();

    protected:
    int targetX, targetY;
    int currentX, currentY;
    int moved;
    MoveStates currentState;
    MoveStates prevState;
    virtual void nextState();


};