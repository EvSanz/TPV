#pragma once

#include "Command.h"

class Shooter: public Command
{
    bool bUp = false;

public:
    const string INFO_STRING = "[S] to shoot";

    Shooter() {
        info_string = INFO_STRING;
    };
    ~Shooter() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;  
};


