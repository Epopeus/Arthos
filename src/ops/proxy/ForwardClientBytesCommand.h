#pragma once

#include <common/network/NetworkConnection.h>
#include <common/network/NetworkConnectionId.h>
#include <common/command/Command.h>

class ForwardClientBytesCommand : public Command<Bytes&> {
public:
    ForwardClientBytesCommand(NetworkConnectionId& clientConnectionId, NetworkConnection& serverConnection);
    void run(Bytes& bytes) override;

private:
    NetworkConnectionId& clientConnectionId;
    NetworkConnection& serverConnection;
};

