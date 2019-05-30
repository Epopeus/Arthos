#include "FakeCommandsMap.h"

FakeCommandsMap::FakeCommandsMap(FakeCommandAdapter& adapter):adapter(adapter) {

}

CommandAdapter<Bytes&>& FakeCommandsMap::getAdapterForRequest(Bytes& request) {
    return adapter;
}
