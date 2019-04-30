#include "FakeNetworkInterface.h"

void FakeNetworkInterface::connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect) {
    connectEndpoints.emplace(Endpoint(ip, port), onConnect);
}

void FakeNetworkInterface::startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect) {
    listenPorts.emplace(port, onConnect);
}

void FakeNetworkInterface::stopAcceptingConnections() {
}

void FakeNetworkInterface::simulateNewConnectionFromConnect(Endpoint& endpoint, NetworkConnection& connection) {
    connectEndpoints.at(endpoint)(connection);
}

void FakeNetworkInterface::simulateNewConnectionFromListen(int port, NetworkConnection& connection) {
    listenPorts.at(port)(connection);
}