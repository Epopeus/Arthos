#pragma once

#include "NetworkConnectionId.h"
#include "NetworkConnection.h"
#include "NetworkConnectionController.h"

struct NetworkConnectionEntry {
    NetworkConnectionId id;
    NetworkConnection& connection;
    NetworkConnectionType type;
    NetworkConnectionController controller;

    NetworkConnectionEntry(NetworkConnectionId id, NetworkConnection& connection, NetworkConnectionType type, NetworkConnectionController controller) : id(id), connection(connection), type(type), controller(controller) {

    }
};

using NetworkConnectionEntryFactory = Factory<NetworkConnectionEntry, NetworkConnectionId, NetworkConnection&, NetworkConnectionType>;

class NetworkConnectionRepository {
public:
    virtual NetworkConnectionEntry& add(NetworkConnectionEntry connectionEntry) = 0;
    virtual NetworkConnectionEntry& getById(NetworkConnectionId& id) = 0;
};