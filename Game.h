#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include "TextureManager.h"


using namespace std;

class Game
{
public:
    void init(const char* title, int x, int y, int width, int height, bool fullscreen);
    void handleEvents();
    void render(); 
    bool running() {return isRunning;}
    void clean();

    static SDL_Renderer *renderer;

    void levelCheck();
    void colidedWithCoin();
    void bonus();
    
private:
    bool isRunning = true;
    SDL_Window *window = NULL;
    int cnt;
    SDL_Texture *texture = NULL;
    SDL_Rect camera;
    int windowWidth, windowHeight;
    int bgWidth, bgHeight;
    const Uint8 *getKeyState;
    bool col = false;
    bool colBonus = false;
    int score = 0;
    int randomX, randomY;
    float health = 100.0;
    float time = 0.01;
    float bigCoinTime = 10.0;
    int coinGain = 3;
    
};


