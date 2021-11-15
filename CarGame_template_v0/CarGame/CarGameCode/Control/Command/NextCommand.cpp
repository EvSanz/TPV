#include "NextCommand.h"

void NextCommand::execute() {
    
}

bool NextCommand::parse(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        bool v = (event.type == SDL_KEYDOWN);
        SDL_Keycode key = event.key.keysym.sym;
        if (key == SDLK_SPACE)
            return true; 
    }
    return false;
}

