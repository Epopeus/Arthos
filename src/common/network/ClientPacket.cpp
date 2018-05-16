#include "ClientPacket.h"

ClientPacket::ClientPacket(std::vector<uint8> rawData):m_rawData(rawData) {
}

ClientPacket::~ClientPacket() {
}

uint8 ClientPacket::getOpcode() {
    return m_rawData.at(0);
}