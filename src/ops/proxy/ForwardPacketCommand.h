#pragma once


#include <common/network/NetworkSessions.h>
#include <ops/network/ClientServerMap.h>

class ForwardPacketCommand {
public:
    ForwardPacketCommand(NetworkSessions& sessions, ClientServerMap& clientServerMap);
    void run(NetworkSessionId& sendingSessionId, Bytes& bytes);

private:
    NetworkSessions& sessions;
    ClientServerMap& clientServerMap;
};

