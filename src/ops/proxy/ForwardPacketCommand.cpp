#include "ForwardPacketCommand.h"

ForwardPacketCommand::ForwardPacketCommand(NetworkConnectionRepository& sessions_, ClientServerMap& clientServerMap_):sessions(sessions_), clientServerMap(clientServerMap_) {

}

void ForwardPacketCommand::run(NetworkConnectionId& sendingSessionId, Bytes& bytes) {

}
