//Includes
#include "WaveCommand.h"

void WaveCommand::execute() {

    //Si hemos pulsado la W y tenemos dinero...
    if (bUp && game->spendMoney(3)) {
        
        //Llamamos al metodo wave de todos los 
        //objetos con colisiones
        for (Collider* i : game->getCollisions())
        {
            i->wave();  
        }
    }
}

bool WaveCommand::parse(SDL_Event& event) {

    //Comprobamos si hay una tecla pulsada o no 
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        
        //Almacenamos en un bool si ha sido pulsada o no
        bool v = (event.type == SDL_KEYDOWN);

        //Comprobamos si se ha pulsado la tecla W 
        SDL_Keycode key = event.key.keysym.sym;
        switch (key) {
        case SDLK_w:
            bUp = v;
            return true;
        default:
            break;
        }
    }
    return false;
}