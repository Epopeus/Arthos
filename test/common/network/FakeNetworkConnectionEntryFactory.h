#pragma once

#include <common/network/NetworkConnectionEntryFactory.h>
#include <common/uuid/UUID.h>

class FakeNetworkConnectionEntryFactory : public NetworkConnectionEntryFactory {
public:
    FakeNetworkConnectionEntryFactory(UUIDFactory& uuidFactory);

    NetworkConnectionEntry& create(NetworkConnection& connection, NetworkConnectionType type) override;

private:
    UUIDFactory& uuidFactory;
};
