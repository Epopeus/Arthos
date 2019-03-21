#pragma once


#include <common/network/NetworkSessionId.h>
#include <unordered_map>
#include <common/network/NetworkSession.h>

class ClientServerMap {
public:
    NetworkSessionId& getLinkedServer(NetworkSessionId& clientSessionId);
    void add(NetworkSessionId& clientSessionId, NetworkSessionId& serverSessionId);
private:
    std::unordered_map<NetworkSessionId, NetworkSessionId> map;
};


