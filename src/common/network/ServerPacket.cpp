#include "ServerPacket.h"

ServerPacket::ServerPacket(Opcode opcode_):opcode(opcode_), args() {
}

ServerPacket::~ServerPacket() {
}

BinaryData& ServerPacket::getBinaryData() const {

}