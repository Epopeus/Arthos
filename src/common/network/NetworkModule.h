#pragma once

#include <common/app/Launchable.h>
#include <common/app/Settings.h>
#include "NetworkInterface.h"
#include "NetworkConnectionRepository.h"
#include "NetworkConnectionIdFactory.h"

class NetworkModule : public Launchable {
public:
    NetworkModule(Settings& settings, NetworkInterface& networkInterface, NetworkConnectionIdFactory& connectionIdFactory, NetworkConnectionEntryFactory& connectionEntryFactory, NetworkConnectionRepository& connectionsRepo);


    void launch() override;
    void shutdown() override;

private:
    void onConnect(NetworkConnection& connection, NetworkConnectionType type);

    Settings& settings;
    NetworkInterface& networkInterface;
    NetworkConnectionIdFactory& connectionIdFactory;
    NetworkConnectionEntryFactory& connectionEntryFactory;
    NetworkConnectionRepository& connectionsRepo;
};