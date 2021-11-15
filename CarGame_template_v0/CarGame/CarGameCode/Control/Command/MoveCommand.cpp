#include "MoveCommand.h"


void MoveCommand::execute() {
    if (bUp && !bDown)
        game->carUpDown(true);
    //game->carUse("TurnL");
    else if (bDown && !bUp)
        game->carUpDown(false);
        //game->carUse("TurnR");
}

bool MoveCommand::parse(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        bool v = (event.type == SDL_KEYDOWN);
        SDL_Keycode key = event.key.keysym.sym;
        switch (key) {
        case SDLK_UP:
            bUp = v;
            return true;
        case SDLK_DOWN:
            bDown = v;
            return true;
        default:
            break;
        }
    }
    return false;
}
