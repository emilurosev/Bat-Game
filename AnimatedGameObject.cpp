#include "AnimatedGameObject.h"

AnimatedGameObject::AnimatedGameObject(const char* sheet, int x, int y, bool enemy, int numOfFrames_V, int numOfFrames_H, int frameSkip) : GameObject(sheet, x, y, enemy) {
    this->frameSkip = frameSkip;

    SDL_QueryTexture(texture, NULL, NULL, &sheetWidth, &sheetHeight);

    frameWidth = sheetWidth / numOfFrames_H;
    frameHeight = sheetHeight / numOfFrames_V;

    source.w = frameWidth;
    source.h = frameHeight;
    source.x = 0;
    source.y = 2*frameHeight;
    
}

void AnimatedGameObject::move(int dx, int dy) {
    GameObject::move(dx, dy);
}

void AnimatedGameObject::moveLeft() {
    move(-4,0);
    source.y = frameHeight; 
}

void AnimatedGameObject::moveRight() {
    move(4,0);
    source.y = 3*frameHeight;
}

void AnimatedGameObject::moveUp() {
    move(0,-4);
    source.y = 0;
}

void AnimatedGameObject::moveDown() {
    move(0,4);
    source.y = 2*frameHeight;
}

void AnimatedGameObject::moveUpLeft() {
    GameObject::moveUpLeft();
    source.y = frameHeight;
}

void AnimatedGameObject::moveDownLeft() {
    GameObject::moveDownLeft();
    source.y = frameHeight;
}

void AnimatedGameObject::moveUpRight() {
    GameObject::moveUpRight();
    source.y = 3*frameHeight;
}

void AnimatedGameObject::moveDownRight() {
    GameObject::moveDownRight();
    source.y = 3*frameHeight;
}

void AnimatedGameObject::drawPlayer(SDL_Rect cam) {
    drawingRect = {dest.x - cam.x, dest.y - cam.y, dest.w, dest.h};
    SDL_RenderCopy(Game::renderer, texture, &source, &drawingRect);

    frameCount++;
    if(frameCount > frameSkip) {
        frameCount = 0;
        source.x += frameWidth;
        if(source.x >= sheetWidth) {
            source.x = 0;
        }
    }
}