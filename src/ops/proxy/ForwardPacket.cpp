#include "ForwardPacket.h"

ForwardPacket::ForwardPacket(NetworkConnectionId& clientSessionId_, Bytes& bytes_):PacketToSend(bytes_), clientSessionId(clientSessionId_) {

}

Bytes& ForwardPacket::toBytes() {
    return bytes;
}
