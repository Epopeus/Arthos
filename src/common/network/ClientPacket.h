#pragma once
#include "common/network/BinaryData.h"

class ClientPacket {
public:
    ClientPacket();
    ClientPacket(BinaryData& binaryData_);

    ~ClientPacket();

private:
    BinaryData& binaryData;
};

