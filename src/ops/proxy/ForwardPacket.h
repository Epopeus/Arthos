#pragma once

#include <common/network/PacketToSend.h>
#include <common/network/NetworkSessionId.h>

class ForwardPacket : public PacketToSend {
public:
    ForwardPacket(NetworkSessionId& clientSessionId, Bytes& bytes);
    Bytes& toBytes() override;

private:
    NetworkSessionId& clientSessionId;
    Bytes& bytes;
};

