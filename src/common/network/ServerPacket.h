#pragma once

#include "Opcode.h"
#include "common/network/BinaryData.h"

class ServerPacket {
    public:
    ServerPacket(Opcode opcode_);
    virtual ~ServerPacket();
    BinaryData& getBinaryData() const;

    protected:
    Opcode opcode;
    BinaryData args;
};