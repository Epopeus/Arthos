#pragma once


#include <common/network/NetworkConnectionId.h>
#include <unordered_map>

class ClientServerMap {
public:
    NetworkConnectionId& getLinkedServer(NetworkConnectionId& clientSessionId);
    void add(NetworkConnectionId& clientSessionId, NetworkConnectionId& serverSessionId);
private:
    std::unordered_map<NetworkConnectionId, NetworkConnectionId> map;
};


