#pragma once

#include "NetworkSession.h"
#include "NetworkSessionId.h"
#include <boost/di/extension/scopes/session.hpp>
class NetworkSessions {
public:
    virtual void add(NetworkSessionId, NetworkSession& session) = 0;
    virtual NetworkSession& getById(NetworkSessionId& id) = 0;
};