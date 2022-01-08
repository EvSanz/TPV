#pragma once

//Includes
#include "Command.h"

class Shooter: public Command
{
    //Booleano de disparo (S) 
    bool bUp = false;

public:

    //Informacion que aparecera en el panel de ayuda
    const string INFO_STRING = "[S] to shoot";

    Shooter() {
        info_string = INFO_STRING;
    };
    ~Shooter() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;  
};


