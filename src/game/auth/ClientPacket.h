#pragma once
#include <vector>

class ClientPacket {
public:
    ClientPacket(std::vector<uint8_t> rawData);
    ClientPacket();

    ~ClientPacket();

    uint8_t getOpcode();

private:
    std::vector<uint8_t> m_rawData;
};

