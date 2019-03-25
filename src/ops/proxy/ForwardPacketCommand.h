#pragma once


#include <common/network/NetworkConnections.h>
#include <ops/network/ClientServerMap.h>

class ForwardPacketCommand {
public:
    ForwardPacketCommand(NetworkConnections& sessions, ClientServerMap& clientServerMap);
    void run(NetworkConnectionId& sendingSessionId, Bytes& bytes);

private:
    NetworkConnections& sessions;
    ClientServerMap& clientServerMap;
};

