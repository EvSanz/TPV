#ifndef CARGAME_VIEWCONTROLLER_H
#define CARGAME_VIEWCONTROLLER_H

//Includes
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "CommandFactory.h"
#include "../Logic/Game.h"
#include "../View/Infobar.h"


const int FRAME_RATE = 30;

class ViewController {

private:

    //Variable del juego 
    Game *game;

    //Comando de salir 
    QuitCommand* quit; 

    //Barra de comandos nula
    CommandFactory* commandFactory = nullptr; 

    //Ventana SDL nula 
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    //Booleano para empezar el juego, iniciado a falso
    bool startGame = false;

    void initSDL();

public:

    ViewController(Game *game);
    ~ViewController();

    void run();
    void handleEvents();
    void clearBackground();

    unsigned int frameDuration();
};


#endif //CARGAME_VIEWCONTROLLER_H
