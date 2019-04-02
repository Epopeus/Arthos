#pragma once


#include <common/network/NetworkConnectionRepository.h>
#include <ops/network/ClientServerMap.h>

class ForwardPacketCommand {
public:
    ForwardPacketCommand(NetworkConnectionRepository& sessions, ClientServerMap& clientServerMap);
    void run(NetworkConnectionId& sendingSessionId, Bytes& bytes);

private:
    NetworkConnectionRepository& sessions;
    ClientServerMap& clientServerMap;
};

