#include "ForwardPacketCommand.h"

ForwardPacketCommand::ForwardPacketCommand(NetworkSessions& sessions_, ClientServerMap& clientServerMap_):sessions(sessions_), clientServerMap(clientServerMap_) {

}

void ForwardPacketCommand::run(NetworkSessionId& sendingSessionId, Bytes& bytes) {

}
