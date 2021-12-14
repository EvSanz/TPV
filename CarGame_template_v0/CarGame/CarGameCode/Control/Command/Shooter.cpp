#include "Shooter.h"

void Shooter::execute() {
    //if (bUp)
        //game->carShoot();
    if (bUp) {
        if (game->car->getCoins() > 0) { //Falta lo de coins
            GameObjectGenerator::generateBullet(game);
            game->car->spentCoins(1);
        }
    }
}

bool Shooter::parse(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        bool v = (event.type == SDL_KEYDOWN);
        SDL_Keycode key = event.key.keysym.sym;
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
