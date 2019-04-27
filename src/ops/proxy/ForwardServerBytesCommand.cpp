#include <iostream>
#include "ForwardServerBytesCommand.h"

ForwardServerBytesCommand::ForwardServerBytesCommand(NetworkConnectionRepository& connectionsRepo_) : connectionsRepo(connectionsRepo_) {

}

void ForwardServerBytesCommand::run(Bytes& args) {
    std::string connectionIdString;
    args >> connectionIdString;

    NetworkConnectionId connectionId = NetworkConnectionId(connectionIdString);

    NetworkConnectionEntry& connectionEntry = connectionsRepo.getById(connectionId);
    connectionEntry.connection.send(args);
}

