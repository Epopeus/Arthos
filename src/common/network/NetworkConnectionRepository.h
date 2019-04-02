#pragma once

#include "NetworkConnectionId.h"
#include "NetworkConnection.h"
#include "ReceivedBytesQueue.h"

struct NetworkConnectionEntry {
    NetworkConnectionId id;
    NetworkConnection& connection;
    NetworkConnectionType type;
    ReceivedBytesQueue receivedBytesQueue;

    NetworkConnectionEntry(const NetworkConnectionId& id, NetworkConnection& connection, NetworkConnectionType type) : id(id), connection(connection), type(type), receivedBytesQueue() {

    }
};

class NetworkConnectionRepository {
public:
    virtual NetworkConnectionEntry& add(NetworkConnectionEntry connectionEntry) = 0;
    virtual NetworkConnectionEntry& getById(NetworkConnectionId& id) = 0;
};