#pragma once

#include "GameObject.h"
#include "Game.h"

class AnimatedGameObject : public GameObject {
    public:
    AnimatedGameObject(const char* sheet, int x, int y, bool enemy, int numOfFrames_V, int numOfFrame_H, int frameSkip);
    
    virtual void move(int dx, int dy);
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUp();
    virtual void moveDown();
    virtual void moveUpLeft();
    virtual void moveUpRight();
    virtual void moveDownLeft();
    virtual void moveDownRight();
    
    virtual void drawPlayer(SDL_Rect cam);

    protected:
    SDL_Rect source;
    int frameSkip;
    int sheetWidth, sheetHeight;
    int frameWidth, frameHeight;
    int frameCount = 0;

};