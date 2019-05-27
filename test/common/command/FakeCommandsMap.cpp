#include "FakeCommandsMap.h"

FakeCommandsMap::FakeCommandsMap(FakeCommandGateway& gateway):gateway(gateway) {

}

CommandGateway<Bytes&>& FakeCommandsMap::getGatewayForRequest(Bytes& request) {
    return gateway;
}
