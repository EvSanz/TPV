#pragma once

#ifndef CARGAME_COMMANDFACTORY_H
#define CARGAME_COMMANDFACTORY_H

#include "Command/QuitCommand.h"
#include "Command/MoveCommand.h"
//#include "CarGameCode/Control/Commands/DebugCommand.h"
#include "Command/HelpCommand.h"
#include "Command/AccCommand.h"
#include "Command/NextCommand.h"
#include <vector>
#include <SDL.h>
#include "Command/Command.h"
#include "../Logic/Game.h"


class CommandFactory {

    vector<Command*> availableCommands;
    Game* game;
public:
    CommandFactory(Game* g) {
        game = g;
        //game->clearHelp();
    }

    ~CommandFactory() {
        for (auto c : availableCommands)
            delete c;
    }

    Command* getCommand(SDL_Event& event) {
        for (auto c : availableCommands) {
            if (c->parse(event)) return c;
        }
        return nullptr;
    }

    void add(Command* c) {
        c->bind(game);
        availableCommands.push_back(c);
    }
};

#endif //CARGAME_COMMANDFACTORY_H

