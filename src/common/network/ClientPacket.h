#pragma once
#include <vector>
#include "common/type/numbers.h"

class ClientPacket {
public:
    ClientPacket(std::vector<uint8> rawData);
    ClientPacket();

    ~ClientPacket();

    uint8 getOpcode();

private:
    std::vector<uint8> m_rawData;
};

