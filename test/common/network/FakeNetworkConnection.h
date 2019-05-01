#pragma once
#include <common/network/NetworkConnection.h>

class FakeNetworkConnection : public NetworkConnection {
public:
    void read(VoidCallback<Bytes&> onBytesReceived) override;
    void send(Bytes& bytes) override;

    void simulateReceivedBytes(Bytes& bytes);

    std::vector<Bytes> sentBytes;
    bool startedReading = false;
    VoidCallback<Bytes&> onBytesReceived;
};

