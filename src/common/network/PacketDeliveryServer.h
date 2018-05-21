#pragma once

#include <memory>
#include "ServerPacket.h"

class PacketDeliveryServer {
public:
    PacketDeliveryServer();

    ~PacketDeliveryServer();

    virtual void send(std::unique_ptr<ServerPacket> packet);
};

