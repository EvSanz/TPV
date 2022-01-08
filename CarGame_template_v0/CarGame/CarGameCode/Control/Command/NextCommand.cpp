//Includes
#include "NextCommand.h"

void NextCommand::execute() {

    //Llamamos al metodo del game que cambiara el estado 
    game->changeState(); 
}

bool NextCommand::parse(SDL_Event& event) {
    
    //Si hemos pulsado Espacio, pasamos a la siguiente instruccion 
    if (event.type == SDL_KEYDOWN) {
        bool v = (event.type == SDL_KEYDOWN);
        SDL_Keycode key = event.key.keysym.sym;
        if (key == SDLK_SPACE)
            return true; 
    }

    return false;
}

