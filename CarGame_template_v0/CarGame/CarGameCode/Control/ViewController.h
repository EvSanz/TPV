//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_VIEWCONTROLLER_H
#define CARGAME_VIEWCONTROLLER_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "CommandFactory.h"

#include "../Logic/Game.h"
#include "../View/Infobar.h"

const int FRAME_RATE = 30;

class ViewController {
private:
    Game *game;
    QuitCommand* quit; 
    CommandFactory* commandFactory = nullptr; 
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool startGame = false;

    void initSDL();
public:
    enum { Menu, Playing, GameOver } state;

    ViewController(Game *game);

    ~ViewController();

    void run();
    void handleEvents();
    void clearBackground();

    unsigned int frameDuration();
};


#endif //CARGAME_VIEWCONTROLLER_H
