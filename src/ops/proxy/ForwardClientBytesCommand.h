#pragma once

#include <common/network/NetworkConnection.h>
#include <common/network/NetworkConnectionId.h>

class ForwardClientBytesCommand {
public:
    ForwardClientBytesCommand(NetworkConnectionId& clientConnectionId, NetworkConnection& serverConnection);
    void run(Bytes& bytes);

private:
    NetworkConnectionId& clientConnectionId;
    NetworkConnection& serverConnection;
};

