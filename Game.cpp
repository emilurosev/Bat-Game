#include "Game.h"
#include "GameObject.h"
#include "Map.h"
#include "AnimatedGameObject.h" 
#include "SpriteZ1.h"
#include "SpriteZ3.h"
#include "SpriteZ4.h"
#include "Coin.h"
#include "cstdlib"

AnimatedGameObject *player;
Map *tileMap;
TextureManager *background;
SpriteZ1 *z1;
SpriteZ3 *z3;
SpriteZ4 *z4;
Coin *coin1;
Coin *coin2;

SDL_Renderer *Game::renderer = NULL;

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
    windowWidth = width;
    windowHeight = height;
    SDL_Init(SDL_INIT_EVERYTHING);
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr << "Greska prilikom inicijalizacije SDL-a. " << SDL_GetError() << endl;
        isRunning = false;
    }
    else {
        int flags = 0;
        if(fullscreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        }
        window = SDL_CreateWindow(title, x, y, windowWidth, windowHeight, flags);
        if(window == NULL) {
            cerr << "Greska prilikom pravljenja prozora. " << SDL_GetError() << endl;
            isRunning = false;
        }
        else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer == NULL) {
                cerr << "Greska prilikom pravljenja renderera. " << SDL_GetError() << endl;
                isRunning = false;
             }
             else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                player = new AnimatedGameObject("assets/bat.png", 200 , 500, false, 4, 3, 8);
                tileMap = new Map();
                texture = background->loadTexture("assets/cave_bg_by_chromel-dawceo1 (copy).png");
                SDL_QueryTexture(texture, NULL, NULL, &bgWidth, &bgHeight);
                camera.w = windowWidth;
                camera.h = windowHeight;
                
                z1 =  new SpriteZ1();
                z3 = new SpriteZ3();
                z4 = new SpriteZ4();
                
                randomX = rand() % (bgWidth-40);
                randomY = rand() % (bgHeight-40);
                coin1 = new Coin(randomX, randomY, 40, 40);
                
             }
        }
    }
}

void Game::handleEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        isRunning = false;
                        break;
            
                }
        }
        getKeyState = SDL_GetKeyboardState(NULL);        
        player->update(getKeyState);
    }    
        
    
    
    colidedWithCoin();
    
    levelCheck();

    //bonus();
    
    
    camera.x = player->getCentreX() - windowWidth/2;
    camera.y = player->getCentreY() - windowHeight/2;
    

    if(camera.x <= 0) {
        camera.x = 0;
    }
    if(camera.y <= 0) {
        camera.y = 0;
    }
    if(camera.x + windowWidth >= bgWidth) { 
        camera.x = bgWidth - windowWidth;
    } 
    if(camera.y + windowHeight >= bgHeight) { 
        camera.y = bgHeight - windowHeight;
    }

    health -= time;

    cout << health << endl;

    if(health < 0.01) {
        isRunning = false;
    }

}

void Game::render() {
    SDL_RenderClear(renderer);
    
    //tileMap->drawMap();
    SDL_RenderCopy(renderer, texture, &camera, NULL);
    
    player->drawPlayer(camera);
    
    coin1->drawCoin(camera);
    //coin2->drawCoin(camera);
  
    
    SDL_RenderPresent(renderer);
}

void Game::levelCheck() {
    if(score == 5) {
        texture = background->loadTexture("./assets/background+scene+corridor002.png");
        SDL_QueryTexture(texture, NULL, NULL, &bgWidth, &bgHeight);
        player->setScreenHeight(bgHeight);
        player->setScreenWidth(bgWidth);
        time = 0.05;
        coinGain = 5;
    }
    else if(score == 9) {
        texture = background->loadTexture("./assets/maxresdefault.png");
        SDL_QueryTexture(texture, NULL, NULL, &bgWidth, &bgHeight);
        player->setScreenHeight(bgHeight);
        player->setScreenWidth(bgWidth);
        time = 0.09;
        coinGain = 9;
    }
}

void Game::colidedWithCoin() {
    col = coin1->collisionCircle(*player);
    if(col == true) {
        delete coin1;
        score++;
        health += coinGain;

        randomX = rand() % bgWidth;
        randomY = rand() % bgHeight;
        coin1 = new Coin(randomX, randomY, 40, 40);
        
        col = coin1->collisionCircle(*player);
            
    }
}

void Game::bonus() {
    if(score == 5 || score == 10 || score == 15 || score == 20) {
        coin2 = new Coin(bgWidth/2, bgHeight/2, 100, 100);
        colBonus = coin2->collisionCircle(*player);
        if(colBonus == true) {
            score += 5;
            health += 10;
            delete coin2;
        }
    }
}


void Game::clean() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    cout << endl << endl << endl << endl << endl;
    cout << "GAME OVER!" << endl;
    cout << "Score: " << score << endl;
    
}
