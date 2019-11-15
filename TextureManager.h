#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

using namespace std;


class TextureManager
{
    public:
        static SDL_Texture* loadTexture(const char* path);
};

