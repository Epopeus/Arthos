#pragma once
#include "common/network/BinaryData.h"
#include "Opcode.h"

class ClientPacket {
public:
    ClientPacket();
    ClientPacket(BinaryData& binaryData_);

    ~ClientPacket();

    Opcode opcode;
private:
    BinaryData& binaryData;
};

