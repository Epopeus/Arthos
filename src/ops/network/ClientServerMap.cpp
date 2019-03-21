#include "ClientServerMap.h"

NetworkSessionId& ClientServerMap::getLinkedServer(NetworkSessionId& clientSessionId) {
    return map.at(clientSessionId);
}

void ClientServerMap::add(NetworkSessionId& clientSessionId, NetworkSessionId& serverSessionId) {
    map.insert({ {clientSessionId, serverSessionId} });
}
