#include "NetworkInputPort.h"

NetworkInputPort::NetworkInputPort(NetworkConnection& connection, CommandRouter<Bytes&>& commandRouter) : connection(connection),commandRouter(commandRouter) {}

void NetworkInputPort::waitForInput() {
    connection.read([&] (Bytes& bytes) {
       receivedBytesQueue.push(bytes);
    });
}

void NetworkInputPort::processReceivedPackets() {
    while (!receivedBytesQueue.empty()) {
        Bytes& bytes = receivedBytesQueue.front();

        commandRouter.route(bytes);

        receivedBytesQueue.pop();
    }
}
