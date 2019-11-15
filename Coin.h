#pragma once


#include "GameObject.h"
#include "AnimatedGameObject.h"

class Coin : public GameObject {
    public:
    Coin(int x, int y, int coinW, int coinH);
    void drawCoin(SDL_Rect cam);
    bool collisionRect(AnimatedGameObject &a);
    bool collisionCircle(AnimatedGameObject &a);
    int getCoinCentreX() {return dest.x + dest.w/2;};
    int getCoinCentreY() {return dest.y + dest.h/2;};

    protected:
    int frameHeight, frameWidth;
    int textureHeight, textureWidth;
    SDL_Rect source;
    int frameCount = 0;
    SDL_Rect drawingRect;
    bool colided = false;
    
    int radius;
   


};