#include "ClientPacket.h"
#include <vector>

ClientPacket::ClientPacket(std::vector<uint8_t> rawData):m_rawData(rawData) {
}

ClientPacket::~ClientPacket() {
}

uint8_t ClientPacket::getOpcode() {
    return m_rawData[0];
}