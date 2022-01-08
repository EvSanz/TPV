#pragma once

//Includes
#include "Command.h"

class AccCommand : public Command
{
    //Booleano de frenado (Flecha izquierda) 
    bool bLeft = false;
    //Booleano de aceleracion (Flecha derecha) 
    bool bRight = false;

public:

    //Informacion que aparecera en el panel de ayuda
    const string INFO_STRING = "[RIGHT/LEFT] to speed up";

    AccCommand() {
        info_string = INFO_STRING;
    };
    ~AccCommand() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;
};

