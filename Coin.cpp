#include "Coin.h"

Coin::Coin(int x, int y, int coinW, int coinH) : GameObject("assets/coin.png", 100, 100, false)  {
    source.y = source.x = 0;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    frameHeight = textureHeight;
    frameWidth = textureWidth / 10;

    dest.x = x;
    dest.y = y;

    source.w = frameWidth;
    source.h = frameHeight;
    source.y = source.x = 0;
    
 
    dest.w = coinW;
    dest.h = coinH;

    radius = 32;


}

void Coin::drawCoin(SDL_Rect cam) {
    drawingRect = {dest.x - cam.x, dest.y - cam.y, dest.w, dest.h};

    SDL_RenderCopy(Game::renderer, texture, &source, &drawingRect);

    frameCount++;
    if(frameCount > 12) {
        frameCount = 0;
        source.x += frameWidth;
        if(source.x >= textureWidth) {
            source.x = 0;
        }
    }
}

bool Coin::collisionRect(AnimatedGameObject &a) {
    if(dest.x + dest.w <= a.getDestX() || dest.x >= a.getDestX() + a.getSpriteWidth() || 
    dest.y + dest.h <= a.getDestY() || dest.y >= a.getCentreY() + a.getSpriteHeight()) {
        SDL_SetTextureColorMod(texture, 255, 255, 255);
        colided = false;
    }
    else {
        SDL_SetTextureColorMod(texture, 255, 0, 0);
        colided = true;
    }

    return colided;
}

bool Coin::collisionCircle(AnimatedGameObject &a) {
    if(sqrt (pow(getCentreX() - a.getCentreX(), 2) + pow(getCentreY() - a.getCentreY(), 2)) >= radius) {
        SDL_SetTextureColorMod(texture, 255, 255, 255);
        colided = false;
    }
    else {
        SDL_SetTextureColorMod(texture, 0, 0, 255);
        colided = true;
    }

    return colided;
}