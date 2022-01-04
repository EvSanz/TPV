#pragma once

#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "State.h"

class PlayingState: public State
{
	float totalTime, initTime; 

	PlayingState(Game* game);
	~PlayingState() = default;
	void update() {};
	void draw();
	void next();

	string getStateName() const {
		return "Playing state";
	}
};

#endif

