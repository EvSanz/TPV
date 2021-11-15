#include "HelpCommand.h"

bool HelpCommand::parse(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;
        if (key == SDLK_h) {
            bUp = !bUp;
        }
    }
    return false;
}

void HelpCommand::execute() {
    if (bUp) {
        //infoBar->drawHelp();
    }
}

