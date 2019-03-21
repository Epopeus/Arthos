#pragma once

#include <unordered_map>
#include "NetworkSessions.h"

class NetworkSessionsMap : public NetworkSessions {
public:
    void add(NetworkSessionId id, NetworkSession& session) override;
    NetworkSession& getById(NetworkSessionId& id) override;

private:
    std::unordered_map<NetworkSessionId, NetworkSession&> sessionsMap;
};