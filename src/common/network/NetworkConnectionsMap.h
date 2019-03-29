#pragma once

#include <unordered_map>
#include "NetworkConnections.h"
#include "NetworkConnection.h"
#include <functional>

class NetworkConnectionsMap : public NetworkConnections {
public:
    void add(NetworkConnectionId id, NetworkConnection& connection) override;
    NetworkConnection& getById(NetworkConnectionId& id) override;

private:
    std::unordered_map<NetworkConnectionId, NetworkConnection&, NetworkConnectionIdHash> connectionsMap;
};