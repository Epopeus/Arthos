#include "FakeNetworkServer.h"

void FakeNetworkServer::startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect_) {
    ports.insert(port);
    onConnect = onConnect_;
}

void FakeNetworkServer::stopAcceptingConnections() {
}

FakeNetworkConnection& FakeNetworkServer::simulateNewConnection(NetworkConnectionType type) {
    FakeNetworkConnection* connection = new FakeNetworkConnection();

    onConnect(*connection);

    return *connection;
}
