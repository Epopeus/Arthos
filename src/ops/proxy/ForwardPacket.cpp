#include "ForwardPacket.h"

ForwardPacket::ForwardPacket(NetworkSessionId& clientSessionId_, Bytes& bytes_):clientSessionId(clientSessionId_), bytes(bytes_) {

}

Bytes& ForwardPacket::toBytes() {
    return bytes;
}
