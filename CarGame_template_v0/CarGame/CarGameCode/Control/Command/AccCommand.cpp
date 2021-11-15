#include "AccCommand.h"

void AccCommand::execute() {
    if (bLeft && !bRight)
        game->carUse("decl");
    else if (bLeft && !bRight)
        game->carUse("accl");
}

bool AccCommand::parse(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        bool v = (event.type == SDL_KEYDOWN);
        SDL_Keycode key = event.key.keysym.sym;
        switch (key) {
        case SDLK_UP:
            bLeft = v;
            return true;
        case SDLK_DOWN:
            bRight = v;
            return true;
        default:
            break;
        }
    }
    return false;
}
