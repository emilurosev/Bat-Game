#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::loadTexture(const char* path) {
    SDL_Surface *surface = IMG_Load(path);
    if(surface == NULL) {
        cerr << "Greksa prilikom pravljenja povrsine. " << IMG_GetError() << endl;
    }
    else {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
        if(texture == NULL) {
            cerr << "Greska prilikom pravljenja texture. " << SDL_GetError() << endl;
        }
        else {
            return texture;
        }
    }

    SDL_FreeSurface(surface);

}


