#pragma once
#include "Game.h"

class Map
{
    public:
        Map();
        ~Map();
    
        void drawMap();
        void loadMapLVL1(int arr[20][25]);

    private:
        SDL_Rect src, dest;
        SDL_Texture *dirt = NULL;
        SDL_Texture *grass = NULL;
        SDL_Texture *water = NULL;
        int tileWidth = 32;
        int tileHeight = 32;

        int mapa[20][25];
};
