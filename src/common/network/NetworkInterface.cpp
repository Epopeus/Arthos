#include "NetworkInterface.h"

NetworkInterface::NetworkInterface(ServiceSettings& settings_, NetworkClient& client_, NetworkServer& server_, NetworkConnectionIdFactory& connectionIdFactory, NetworkConnections& connections) : settings(settings_), client(client_), server(server_), connectionIdFactory(connectionIdFactory), connections(connections) {

}
void NetworkInterface::launch() {
    for (auto& it : settings.listenPorts)
        server.startAcceptingConnections(it.second, [&] (NetworkConnection& connection) { onConnect(connection, it.first); });

    for (auto& it : settings.connectEndpoints)
        client.connect(it.second.address, it.second.port, [&] (NetworkConnection& connection) { onConnect(connection, it.first); });
}

void NetworkInterface::shutdown() {
    server.stopAcceptingConnections();
    // TODO
    // client.disconnect();
}

void NetworkInterface::onConnect(NetworkConnection& connection, NetworkConnectionType type) {
    NetworkConnectionId connectionId = connectionIdFactory.create();

    connection.read([&] (Bytes& bytes) { onBytesReceived(connectionId, bytes); });

    connections.add(connectionId, connection);
}

void NetworkInterface::onBytesReceived(NetworkConnectionId connectionId, Bytes& bytes) {

}
