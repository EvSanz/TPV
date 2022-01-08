#include "HelpCommand.h"

bool HelpCommand::parse(SDL_Event& event) {
    
    //Si se ha pulsado una tecla...
    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;
        
        //Y esa tecla corresponde a la h, llamamos
        //al metodo en game que crea el panel de ayuda
        if (key == SDLK_h) {
            game->toggleHelp();
        }
    }

    return false;
}


