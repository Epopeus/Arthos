#include "OpcodeCommandRouter.h"

OpcodeCommandRouter::OpcodeCommandRouter(BytesCommandsMap& commandsMap):commandsMap(commandsMap) {

}

void OpcodeCommandRouter::route(Bytes& bytes) {
    int opcode;
    bytes >> opcode;

    commandsMap.at(opcode).get().run(bytes);
}
