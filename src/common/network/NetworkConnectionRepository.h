#pragma once

#include "NetworkConnectionId.h"
#include "NetworkConnection.h"
#include "ReceivedBytesQueue.h"
#include "NetworkInputPort.h"

struct NetworkConnectionEntry {
    NetworkConnectionId id;
    NetworkConnection& connection;
    NetworkConnectionType type;
    NetworkInputPort inputPort;

    NetworkConnectionEntry(NetworkConnectionId id, NetworkConnection& connection, NetworkConnectionType type, NetworkInputPort inputPort) : id(id), connection(connection), type(type), inputPort(inputPort) {

    }
};

using NetworkConnectionEntryFactory = Factory<NetworkConnectionEntry, NetworkConnectionId, NetworkConnection&, NetworkConnectionType>;

class NetworkConnectionRepository {
public:
    virtual NetworkConnectionEntry& add(NetworkConnectionEntry connectionEntry) = 0;
    virtual NetworkConnectionEntry& getById(NetworkConnectionId& id) = 0;
};