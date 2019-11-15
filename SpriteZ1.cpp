#include "SpriteZ1.h"
#include "GameObject.h"

SpriteZ1::SpriteZ1() : AnimatedGameObject("assets/bat.png", 200, 200, false, 4, 3, 8) {

    currentState = upLeftState;

}

void SpriteZ1::upRight() {
    if(currentState == upLeftState) {
        currentState = upRightState;
    }
}

void SpriteZ1::downRight() {
    if(currentState == upRightState) {
        currentState = downRightState;
    }
}

void SpriteZ1::downLeft() {
    if(currentState == downRightState) {
        currentState = downLeftState;
    }
}

void SpriteZ1::upLeft() {
    if(currentState == downLeftState) {
        currentState = upLeftState;
    }
}

void SpriteZ1::stop_state() {
    currentState = stopState;
}

void SpriteZ1::move() {

    dest.x += 1;
    dest.y += 1;

    if(currentState == upLeftState) {
        AnimatedGameObject::moveUpLeft();
    } 
    else if(currentState == upRightState) {
        AnimatedGameObject::moveUpRight();
    }
    else if(currentState == downLeftState) {
        AnimatedGameObject::moveDownLeft();
    }
    else if(currentState == downRightState) {
        AnimatedGameObject::moveDownRight();
    }
    else if(currentState == stopState) {
        GameObject::stop();
    }
    
}

void SpriteZ1::update(const Uint8 *keyState) {
    if(keyState[keys[4]]) {
        upLeft();
    }
    else if(keyState[keys[5]]) {
        upRight();
    }
    else if(keyState[keys[6]]) {
        downLeft();
    }
    else if(keyState[keys[7]]) {
        downRight();
    }
    else if(keyState[keys[8]]) {
        stop_state();
    }
}