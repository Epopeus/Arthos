#pragma once


#include <common/network/NetworkConnectionRepository.h>
#include <ops/network/ClientServerMap.h>

class ForwardBytesCommand {
public:
    ForwardBytesCommand(NetworkConnectionId& clientConnectionId, NetworkConnection& serverConnection);
    void run(Bytes& bytes);

private:
    NetworkConnectionId& clientConnectionId;
    NetworkConnection& serverConnection;
};

