#pragma once

#include <common/app/Settings.h>
#include "NetworkInterface.h"
#include "NetworkConnectionRepository.h"
#include "NetworkConnectionIdFactory.h"

class NetworkModule {
public:
    NetworkModule(Settings& settings, NetworkInterface& networkInterface, NetworkConnectionIdFactory& connectionIdFactory, NetworkConnectionEntryFactory& connectionEntryFactory, NetworkConnectionRepository& connectionsRepo);

    void launch();
    void shutdown();

private:
    void onConnect(NetworkConnection& connection, NetworkConnectionType type);

    Settings& settings;
    NetworkInterface& networkInterface;
    NetworkConnectionIdFactory& connectionIdFactory;
    NetworkConnectionEntryFactory& connectionEntryFactory;
    NetworkConnectionRepository& connectionsRepo;
};