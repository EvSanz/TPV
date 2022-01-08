//Includes
#include "Shooter.h"

void Shooter::execute() {
    if (bUp) {
        if (game->spendMoney(1)) { 
            GameObjectGenerator::generateBullet(game);
        }
    }
}

bool Shooter::parse(SDL_Event& event) {
    
    //Comprobamos si hay una tecla pulsada o no 
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        
        //Almacenamos en un bool si ha sido pulsada o no
        bool v = (event.type == SDL_KEYDOWN);
        
        //Guardamos el valor de la tecla en una variable 
        SDL_Keycode key = event.key.keysym.sym;

        //Dependiendo de la tecla, cambiamos el valor del bool 
        //que detecta si se ha pulsado arriba o abajo
       switch (key) {
        case SDLK_s:
            bUp = v;
            return true;
        default:
            break;
        }
    }
    return false;
}
