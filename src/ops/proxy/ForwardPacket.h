#pragma once

#include <common/network/PacketToSend.h>
#include <common/network/NetworkConnectionId.h>

class ForwardPacket : public PacketToSend {
public:
    ForwardPacket(NetworkConnectionId& clientSessionId, Bytes& bytes);
    Bytes& toBytes() override;

private:
    NetworkConnectionId& clientSessionId;
};

