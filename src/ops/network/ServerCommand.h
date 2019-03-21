#pragma once

#include <common/network/Bytes.h>

class ServerCommand {
public:
    ServerCommand(Opcode opcode, Bytes& args);

private:
    Opcode opcode;
    Bytes& args;
};

