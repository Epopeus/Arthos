#include <iostream>
#include "NetworkInterface.h"

NetworkInterface::NetworkInterface(ServiceSettings& settings_, NetworkClient& client_, NetworkServer& server_, NetworkConnectionIdFactory& connectionIdFactory, NetworkConnectionRepository& connectionsRepo_) : settings(settings_), client(client_), server(server_), connectionIdFactory(connectionIdFactory), connectionsRepo(connectionsRepo_) {

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
    NetworkConnectionEntry& entry = connectionsRepo.add(NetworkConnectionEntry(connectionIdFactory.create(), connection, type));

    connection.read([&] (Bytes& bytes) {
        onBytesReceived(entry.id, bytes);
    });
}

void NetworkInterface::onBytesReceived(NetworkConnectionId& connectionId, Bytes& bytes) {
    connectionsRepo.getById(connectionId).receivedBytesQueue.push(bytes);
}
