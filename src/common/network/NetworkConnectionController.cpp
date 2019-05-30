#include "NetworkConnectionController.h"

NetworkConnectionController::NetworkConnectionController(NetworkConnection& connection, CommandRouter<Bytes&>& commandRouter) : connection(connection), commandRouter(commandRouter) {}

void NetworkConnectionController::waitForInput() {
    connection.read([&] (Bytes& bytes) {
       receivedBytesQueue.push(bytes);
    });
}

void NetworkConnectionController::processReceivedPackets() {
    while (!receivedBytesQueue.empty()) {
        Bytes& bytes = receivedBytesQueue.front();

        commandRouter.route(bytes);

        receivedBytesQueue.pop();
    }
}