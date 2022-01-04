#pragma once

#ifndef STATE_H
#define STATE_OIL_H

#include "CommandFactory.h"

class Game;
class State {

protected:
	Game* game = nullptr;
	CommandFactory* commandFactory = nullptr;
public:
	State(Game* game) : game(game) {
		commandFactory = new CommandFactory(game);
	};
	virtual ~State() {
		delete commandFactory;
	};

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void next() = 0;
	virtual void jump(State ∗state);
	bool doQuit();
	void handleEvents();
	virtual void registerCommands() = 0;
	void resetInitTime();
};

#endif
