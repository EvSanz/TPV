#pragma once

#include "Command.h"

class HelpCommand: public Command
{
    bool bUp = false;
public:

    const string INFO_STRING = "[h] to toggle help";

    HelpCommand() {
        info_string = INFO_STRING;
    };
    ~HelpCommand() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;
};

