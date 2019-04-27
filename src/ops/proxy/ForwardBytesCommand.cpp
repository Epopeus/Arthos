#include "ForwardBytesCommand.h"

ForwardBytesCommand::ForwardBytesCommand(NetworkConnectionId& clientConnectionId_, NetworkConnection& serverConnection_):clientConnectionId(clientConnectionId_), serverConnection(serverConnection_) {

}

void ForwardBytesCommand::run(Bytes& bytes) {
    bytes.prepend(clientConnectionId.toString());
    serverConnection.send(bytes);
}
