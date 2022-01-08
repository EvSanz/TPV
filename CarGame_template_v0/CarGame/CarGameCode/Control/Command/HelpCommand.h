#pragma once

//Includes
#include "Command.h"

class HelpCommand: public Command
{

public:

    //Informacion que aparecera en el panel de ayuda
    const string INFO_STRING = "[h] to toggle help";

    HelpCommand() {
        info_string = INFO_STRING;
    };
    ~HelpCommand() = default;
    bool parse(SDL_Event & event) override;
    void execute() override {};
};

