#pragma once

#include <common/VoidCallback.h>
#include "Bytes.h"

enum class NetworkConnectionType {
    AUTH_CLIENT,
    GAME_CLIENT,
    AUTH_SERVER,
    GAME_SERVER,
    GAME_ROUTER,
};

class NetworkConnection {
public:
    virtual void read(VoidCallback<Bytes&> onBytesReceived) = 0;
    virtual void send(Bytes& bytes) = 0;
};
