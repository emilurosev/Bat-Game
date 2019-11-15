#pragma once

#include "AnimatedGameObject.h"
#include "util.h"

class SpriteZ1 : public AnimatedGameObject {
    protected:
    MoveStates currentState;

    public:
    SpriteZ1();
    virtual void move();
    virtual void update(const Uint8 *keyState);
    virtual void upLeft();
    virtual void upRight();
    virtual void downLeft();
    virtual void downRight();
    void stop_state();

};