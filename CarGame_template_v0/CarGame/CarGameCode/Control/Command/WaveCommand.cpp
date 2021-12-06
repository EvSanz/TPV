#include "WaveCommand.h"

void WaveCommand::execute() {
    if (bUp)
        game->carWave();
}

bool WaveCommand::parse(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        bool v = (event.type == SDL_KEYDOWN);
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