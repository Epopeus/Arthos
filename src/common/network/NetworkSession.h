#pragma once

#include "NetworkConnection.h"
#include "PacketToSend.h"

class NetworkSession {
public:
    NetworkSession(NetworkConnection& connection);

    void send(PacketToSend& packet);
private:
    NetworkConnection& connection;
};