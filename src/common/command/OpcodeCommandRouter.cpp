#include "OpcodeCommandRouter.h"

OpcodeCommandRouter::OpcodeCommandRouter(BytesCommandsMap& commandsMap):commandsMap(commandsMap) {

}

void OpcodeCommandRouter::route(Bytes& bytes) {
    int opcode;
    bytes >> opcode;

    BytesCommandGateway& gateway = commandsMap.at(opcode).get();
    gateway.run(bytes);
}
