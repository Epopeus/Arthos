#include <functional>
#include "NetworkConnectionsMap.h"

NetworkConnection& NetworkConnectionsMap::getById(NetworkConnectionId& id) {
    return connectionsMap.at(id);
}

void NetworkConnectionsMap::add(NetworkConnectionId id, NetworkConnection& connection) {
    connectionsMap.insert({ {id, std::ref(connection)} });
}
