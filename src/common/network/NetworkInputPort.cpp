#include "NetworkInputPort.h"

NetworkInputPort::NetworkInputPort(NetworkConnection& connection_, ReceivedBytesQueue& receivedBytesQueue_) : connection(connection_), receivedBytesQueue(receivedBytesQueue_) {}

void NetworkInputPort::waitForInput() {
    connection.read([&] (Bytes& bytes) {
       receivedBytesQueue.push(bytes);
    });
}

void NetworkInputPort::processReceivedPackets() {

}
