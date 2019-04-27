#pragma once


#include <common/network/NetworkConnectionRepository.h>
#include <ops/network/ClientServerMap.h>

class ForwardClientBytesCommand {
public:
    ForwardClientBytesCommand(NetworkConnectionId& clientConnectionId, NetworkConnection& serverConnection);
    void run(Bytes& bytes);

private:
    NetworkConnectionId& clientConnectionId;
    NetworkConnection& serverConnection;
};

