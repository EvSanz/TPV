#pragma once

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"

class MenuState: public State
{
public:

	MenuState(Game* game) : State(game) {};
	~MenuState() = default;
	void update() {}; 
	void draw();
	void next();
	void registerCommands() override; 

	string getStateName() const {
		return "Menu state";
	}
};

#endif


