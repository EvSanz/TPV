#include "Shooter.h"

void Shooter::execute() {
    if (bUp) {
        if (game->spendMoney(1)) { 
            GameObjectGenerator::generateBullet(game);
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
