#include "ForwardClientBytesCommand.h"

ForwardClientBytesCommand::ForwardClientBytesCommand(NetworkConnectionId& clientConnectionId_, NetworkConnection& serverConnection_):clientConnectionId(clientConnectionId_), serverConnection(serverConnection_) {

}

void ForwardClientBytesCommand::run(Bytes& bytes) {
    bytes.prepend(clientConnectionId.toString());
    serverConnection.send(bytes);
}
