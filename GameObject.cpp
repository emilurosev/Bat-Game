#include "GameObject.h"
#include "TextureManager.h"
#include <cmath>

GameObject::GameObject(const char* sheet, int x, int y, bool enemy) 
{
    texture = TextureManager::loadTexture(sheet);
    
    dest.x = x;
    dest.y = y;

    dest.w = dest.h = 64;

    if(enemy) {
        keys[0] = SDL_SCANCODE_W;
        keys[1] = SDL_SCANCODE_S;
        keys[2] = SDL_SCANCODE_A;
        keys[3] = SDL_SCANCODE_D;
        keys[4] = SDL_SCANCODE_Q;
        keys[5] = SDL_SCANCODE_E;
        keys[6] = SDL_SCANCODE_Z;
        keys[7] = SDL_SCANCODE_C;
        keys[8] = SDL_SCANCODE_X;     
    }
    else {
        keys[0] = SDL_SCANCODE_KP_8;
        keys[1] = SDL_SCANCODE_KP_2;
        keys[2] = SDL_SCANCODE_KP_4;
        keys[3] = SDL_SCANCODE_KP_6;
        keys[4] = SDL_SCANCODE_KP_7;
        keys[5] = SDL_SCANCODE_KP_9;
        keys[6] = SDL_SCANCODE_KP_1;
        keys[7] = SDL_SCANCODE_KP_3;   
        keys[8] = SDL_SCANCODE_KP_5;  
    }
   
}

void GameObject::move(int dx, int dy) {
    
    dest.x += dx;
    dest.y += dy;
  
    
    if(dest.x <= -dest.w) {
        dest.x = screenWidth - dest.w;
    }
    if(dest.y <= -dest.h) {
        dest.y = screenHeight - dest.h;
    }
    if(dest.x > screenWidth) {
       dest.x = 0;   
    }
    if(dest.y > screenHeight) {
        dest.y = 0;
    }

}

void GameObject::drawPlayer(SDL_Rect cam) {
    drawingRect = {dest.x - cam.x, dest.y - cam.y, dest.w, dest.h};
    SDL_RenderCopy(Game::renderer, texture, NULL, &drawingRect);
}

void GameObject::stop() {
    dest.x = dest.x;
    dest.y = dest.y;
}

void GameObject::update(const Uint8 *keyState) {
    if(keyState[keys[0]]) {
        moveUp();
    }
    else if(keyState[keys[1]]) {
        moveDown();
    }
    else if(keyState[keys[2]]) {
        moveLeft();      
    }
    else if(keyState[keys[3]]) {
        moveRight();
    }
    else if(keyState[keys[4]]) {
        moveUpLeft();
    }
    else if(keyState[keys[5]]) {
        moveUpRight();
    }
    else if(keyState[keys[6]]) {
        moveDownLeft();
    }
    else if(keyState[keys[7]]) {
        moveDownRight();
    }
}

GameObject::~GameObject() {
    SDL_DestroyTexture(texture);
}

void GameObject::setScreenWidth(int sw) {
    screenWidth = sw;
}

void GameObject::setScreenHeight(int sh) {
    screenHeight = sh;
}