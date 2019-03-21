#include "NetworkInterface.h"
#include <functional>

NetworkInterface::NetworkInterface(ServiceSettings& settings_, NetworkClient& client_, NetworkServer& server_, NetworkSessionFactory& sessionFactory_, NetworkSessionIdFactory& sessionIdFactory_, NetworkSessions& sessions_) : settings(settings_), client(client_), server(server_), sessionFactory(sessionFactory_), sessionIdFactory(sessionIdFactory_), sessions(sessions_) {

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
    NetworkSession& session = sessionFactory.create(connection);
    NetworkSessionId sessionId = sessionIdFactory.create();

    connection.read([&] (Bytes& bytes) { onBytesReceived(sessionId, bytes); });

    sessions.add(sessionId, session);
}

void NetworkInterface::onBytesReceived(NetworkSessionId sessionId, Bytes& bytes) {

}
