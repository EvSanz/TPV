#pragma once

#include "Command.h"

class WaveCommand : public Command
{
    //Booleano de wave (W) 
    bool bUp = false;

public:

    //Informacion que aparecera en el panel de ayuda
    const string INFO_STRING = "[W] to activate the wave";

    WaveCommand() {
        info_string = INFO_STRING;
    };
    ~WaveCommand() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;
};

