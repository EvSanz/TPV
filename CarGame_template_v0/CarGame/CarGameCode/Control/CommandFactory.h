#pragma once

#ifndef CARGAME_COMMANDFACTORY_H
#define CARGAME_COMMANDFACTORY_H

//Includes 
#include "Command/QuitCommand.h"
#include "Command/MoveCommand.h"
#include "Command/HelpCommand.h"
#include "Command/AccCommand.h"
#include "Command/NextCommand.h"
#include "Command/Shooter.h"
#include "Command/WaveCommand.h"
#include <vector>
#include <SDL.h>
#include "Command/Command.h"
#include "../Logic/Game.h"


class CommandFactory {

    //Vector de comandos disponibles 
    vector<Command*> availableCommands;
    
    Game* game;

public:
    CommandFactory(Game* g) {
        game = g;
    }

    ~CommandFactory() {
        for (auto c : availableCommands)
            delete c;
    }

    //Metodo para devolver un comando del vector de comandos
    Command* getCommand(SDL_Event& event) {
        for (auto c : availableCommands) {
            if (c->parse(event)) return c;
        }
        return nullptr;
    }

    //Metodo para añadir comandos, metiendolos 
    //en el vector de comandos disponibles 
    void add(Command* c) {
        c->bind(game);
        availableCommands.push_back(c);
    }
};

#endif //CARGAME_COMMANDFACTORY_H

