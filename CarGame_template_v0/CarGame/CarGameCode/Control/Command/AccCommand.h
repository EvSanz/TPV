#pragma once

#include "Command.h"

class AccCommand : public Command
{
    bool bLeft = false;
    bool bRight = false;
public:

    const string INFO_STRING = "[RIGHT/LEFT] to move";

    AccCommand() {
        info_string = INFO_STRING;
    };
    ~AccCommand() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;
};

