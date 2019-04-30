#include "FakeNetworkInterface.h"

void FakeNetworkInterface::connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect_) {
    connectEndpoints.emplace(ip, port);
    onConnect = onConnect_;
}

void FakeNetworkInterface::startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect_) {
    listenPorts.insert(port);
    onConnect = onConnect_;
}

void FakeNetworkInterface::stopAcceptingConnections() {
}

FakeNetworkConnection& FakeNetworkInterface::simulateNewConnection(NetworkConnectionType type) {
    FakeNetworkConnection* connection = new FakeNetworkConnection();

    onConnect(*connection);

    return *connection;
}

