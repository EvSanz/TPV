#pragma once

#include "Command.h"

class WaveCommand : public Command
{
    bool bUp = false;

public:
    const string INFO_STRING = "[W] to activate the wave";

    WaveCommand() {
        info_string = INFO_STRING;
    };
    ~WaveCommand() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;
};

