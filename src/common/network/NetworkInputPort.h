#pragma once

#include <common/command/CommandRouter.h>
#include "NetworkConnection.h"
#include "ReceivedBytesQueue.h"

class NetworkInputPort {
public:
    NetworkInputPort(NetworkConnection& connection, CommandRouter<Bytes&>& commandRouter);

    void waitForInput();
    void processReceivedPackets();
private:
    NetworkConnection& connection;
    ReceivedBytesQueue receivedBytesQueue;
    CommandRouter<Bytes&>& commandRouter;
};