//Includes
#include "AccCommand.h"

void AccCommand::execute() {
    
    //Si solo pulsamos la flecha izquierda, frenamos
    if (bLeft && !bRight)
        game->carSpeedo(false);
    //Si solo pulsamos la flecha derecha, aceleramos
    else if (!bLeft && bRight)
        game->carSpeedo(true);
}


bool AccCommand::parse(SDL_Event& event) {
    
    //Comprobamos si hay una tecla pulsada o no 
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        
        //Almacenamos en un bool si ha sido pulsada o no 
        bool v = (event.type == SDL_KEYDOWN);

        //Guardamos el valor de la tecla en una variable 
        SDL_Keycode key = event.key.keysym.sym;

        //Dependiendo de la tecla, cambiamos el valor del bool 
        //que detecta si se ha pulsado la flecha izquierda o derecha
        switch (key) {
        case SDLK_LEFT:
            bLeft = v;
            return true;
        case SDLK_RIGHT:
            bRight = v;
            return true;
        default:
            break;
        }
    }
    return false;
}
