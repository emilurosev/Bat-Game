#pragma once
#include "Game.h"

class GameObject
{
    public:
        GameObject(const char* sheet, int x, int y, bool enemy);
        virtual ~GameObject();

        virtual void move(int dx, int dy);
        virtual void moveLeft() {move(-4,0);};
        virtual void moveRight() {move(4,0);};
        virtual void moveUp() {move(0,-4);};
        virtual void moveDown() {move(0,4);};
        virtual void moveUpRight() {move(4,-4);};
        virtual void moveUpLeft() {move(-4,-4);};
        virtual void moveDownRight() {move(4,4);};
        virtual void moveDownLeft() {move(-4,4);};

        void stop();

        int getCentreX() {return dest.x + 32;};
        int getCentreY() {return dest.y + 32;};
        int getDestX() {return dest.x;};
        int getDestY() {return dest.y;};
        int getSpriteWidth() {return dest.w;};
        int getSpriteHeight() {return dest.h;};

        virtual void drawPlayer(SDL_Rect cam);

        virtual void update(const Uint8 *keyState);

        void setScreenWidth(int sw);
        void setScreenHeight(int sh);

    protected:
       
        SDL_Texture *texture = NULL;

        int screenWidth = 1280;
        int screenHeight = 720;
      
        SDL_Rect dest;
        SDL_Rect drawingRect;

        SDL_Scancode keys[9];
               
};
