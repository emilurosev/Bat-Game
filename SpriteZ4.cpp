#include "SpriteZ4.h"



SpriteZ4::SpriteZ4() : AnimatedGameObject("resources/creatures/bat.png", 100, 100, false, 4, 3, 8)
{
    currentState = jumpState;

    angle = 180;
    rScale = 4;
    r = dest.h * rScale;
    AnimatedGameObject::move(0, 240);
    centerX = dest.x + r;
    centerY = dest.y;
}

void SpriteZ4::nextState()
{
    if(currentState == stopState) {
        currentState = jumpState;
    }
    else if((currentState == jumpState) && (angle <= 0) && (r/2 >= dest.h)) {
        currentState = stopState;
        angle = 180;
        r /= 2;
        centerX = dest.x + r;
        centerY = dest.y;
    }
    else if(currentState == jumpState && r/2 < dest.h)
    {
        currentState = rightState;
    }
}

void SpriteZ4::move(int dx, int dy)
{
    nextState();
    if(currentState == jumpState) {
        int y = -sin((angle*3.14)/180.0) * r + centerY;
        int x = cos((angle*3.14)/180.0) * r + centerX;
        angle -= rScale/(r/dest.h);
        dest.x = x;
        dest.y = y;
    }
    else if(rightState) {
        AnimatedGameObject::moveRight();
    }
}

/*
void SpriteZ4::draw(SDL_Renderer * const renderer)
{
    currentRow = 3;
    AnimatedSprite::draw(renderer);
}
*/