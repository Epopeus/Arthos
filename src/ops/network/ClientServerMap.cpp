#include "ClientServerMap.h"

NetworkConnectionId& ClientServerMap::getLinkedServer(NetworkConnectionId& clientSessionId) {
    return map.at(clientSessionId);
}

void ClientServerMap::add(NetworkConnectionId& clientSessionId, NetworkConnectionId& serverSessionId) {
    map.insert({ {clientSessionId, serverSessionId} });
}
