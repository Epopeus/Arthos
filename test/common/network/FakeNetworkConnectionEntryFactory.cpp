#include "FakeNetworkConnectionEntryFactory.h"

FakeNetworkConnectionEntryFactory::FakeNetworkConnectionEntryFactory(UUIDFactory& uuidFactory_):uuidFactory(uuidFactory_) {
}
NetworkConnectionEntry& FakeNetworkConnectionEntryFactory::create(NetworkConnection& connection, NetworkConnectionType type) {
    ReceivedBytesQueue* queue = new ReceivedBytesQueue();

    return (*new NetworkConnectionEntry(uuidFactory.create(), connection, type, NetworkInputPort(connection, *queue)));
}
