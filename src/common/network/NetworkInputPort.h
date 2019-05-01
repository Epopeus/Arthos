#pragma once

#include "NetworkConnection.h"
#include "ReceivedBytesQueue.h"

class NetworkInputPort {
public:
    NetworkInputPort(NetworkConnection& connection, ReceivedBytesQueue& receivedBytesQueue);

    void waitForInput();
    void processReceivedPackets();
public:
private:
    NetworkConnection& connection;
    ReceivedBytesQueue& receivedBytesQueue;
};
