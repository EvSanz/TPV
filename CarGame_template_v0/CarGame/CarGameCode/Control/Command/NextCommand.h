#pragma once

//Includes
#include "Command.h"

class NextCommand: public Command
{

public:

    //Informacion que aparecera en el panel de ayuda
    const string INFO_STRING = "[SPACE] to start the game";

    NextCommand() {
        info_string = INFO_STRING;
    };

    ~NextCommand() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;
};

