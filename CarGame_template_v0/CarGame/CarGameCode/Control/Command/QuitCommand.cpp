//Includes
#include "QuitCommand.h"

bool QuitCommand::parse(SDL_Event& event) {

    //Si se ha ejecutado un evento de salida, devolvemos true  
    if (event.type == SDL_QUIT)
        return true;

    //Si se ha pulsado la tecla de escape, devolvemos true
    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;
        if (key == SDLK_ESCAPE)
            return true;
    }
    return false;
}

void QuitCommand::execute() {

    //Llamamos al metodo de game para salir de la partida 
    game->setUserExit();
}
