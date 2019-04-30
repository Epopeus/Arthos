#include "NetworkModule.h"

NetworkModule::NetworkModule(Settings& settings_, NetworkInterface& networkInterface_, NetworkConnectionIdFactory& connectionIdFactory_, NetworkConnectionRepository& connectionsRepo_) : settings(settings_), networkInterface(networkInterface_), connectionIdFactory(connectionIdFactory_), connectionsRepo(connectionsRepo_) {

}
void NetworkModule::launch() {
    for (auto& it : settings.listenPorts)
        networkInterface.startAcceptingConnections(it.second, [&] (NetworkConnection& connection) { onConnect(connection, it.first); });

    for (auto& it : settings.connectEndpoints)
        networkInterface.connect(it.second.address, it.second.port, [&] (NetworkConnection& connection) { onConnect(connection, it.first); });
}

void NetworkModule::shutdown() {
    networkInterface.stopAcceptingConnections();
    // TODO
    // networkModule.disconnect();
}

void NetworkModule::onConnect(NetworkConnection& connection, NetworkConnectionType type) {
    NetworkConnectionEntry& connectionEntry = connectionsRepo.add(NetworkConnectionEntry(connectionIdFactory.create(), connection, type));
    
    connection.read([&] (Bytes& bytes) {
        onBytesReceived(connectionEntry, bytes);
    });
}

void NetworkModule::onBytesReceived(NetworkConnectionEntry& connectionEntry, Bytes& bytes) {
    connectionEntry.receivedBytesQueue.push(bytes);
}