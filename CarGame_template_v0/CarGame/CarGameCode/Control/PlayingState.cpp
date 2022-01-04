#include "PlayingState.h"

void PlayingState::update() {
	totalTime += (SDL_GetTicks() - initTime);
	game->setElapsedTime(totalTime);
	resetInitTime();
	if (game->gameFinished())
		next();
	game->update();
}
