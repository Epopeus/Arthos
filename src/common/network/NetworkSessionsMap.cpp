#include <functional>
#include "NetworkSessionsMap.h"

NetworkSession& NetworkSessionsMap::getById(NetworkSessionId& id) {
    return sessionsMap.at(id);
}

void NetworkSessionsMap::add(NetworkSessionId id, NetworkSession& session) {
    sessionsMap.insert({ {id, std::ref(session)} });
}
