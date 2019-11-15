#include "SpriteZ3.h"

SpriteZ3::SpriteZ3() : AnimatedGameObject("assets/bat.png", 100, 100, false, 4, 3, 8) {
    srand(SDL_GetTicks());
    currentState = leftState;


}

void SpriteZ3::nextState()
{
    if(moved >= 10 && currentState != moveToPointState) {
        int choice = rand()%6;
        if(choice == 0) {
            if(currentState != stopState) {
                prevState = currentState;
            }
            currentState = stopState;
        }
        else if(currentState == stopState){
            if(choice == 1){
                currentState = leftState;
            }
            else if(choice == 2) {
                currentState = rightState;
            }
            else if(choice == 3) {
                currentState = upState;
            }
            else if(choice == 4) {
                currentState = downState;
            }
            else if(choice == 5) {
                currentState = moveToPointState;
                currentX = dest.x;
                currentY = dest.y;
                targetX = rand()%640;
                targetY = rand()%480;
            }
        }
        moved = 0;
    }
    else if(currentState == moveToPointState) {
        if(dest.x == targetX && dest.y == targetY) {
            prevState = currentState;
            currentState = stopState;
            moved = 0;
        }
    }
}

void SpriteZ3::move(int dx, int dy)
{
    moved++;
    nextState();
    if(currentState == stopState) {
        AnimatedGameObject::move(0, 0);
    }
    else if(currentState == leftState) {
        AnimatedGameObject::moveLeft();
    }
    else if(currentState == rightState) {
        AnimatedGameObject:moveRight();
    }
    else if(currentState == upState) {
        AnimatedGameObject::moveUp();
    }
    else if(currentState == downState) {
        AnimatedGameObject::moveDown();
    }
    else if(currentState == moveToPointState) {
        if(targetX < currentX)
            dest.x -= 1;
        else
            dest.x += 1;
        int y = currentY + (dest.x - currentX) * (targetY-currentY)/(targetX-currentX);
        dest.y = y;
    }
}