#pragma once

#include "Command.h"

class NextCommand: public Command
{
public:

    const string INFO_STRING = "[SPACE] to start the game";

    NextCommand() {
        info_string = INFO_STRING;
    };
    ~NextCommand() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;
};

