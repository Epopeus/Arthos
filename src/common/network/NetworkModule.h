#pragma once

#include <common/app/Launchable.h>
#include <common/app/Settings.h>
#include "NetworkInterface.h"
#include "NetworkConnectionIdFactory.h"
#include "NetworkConnectionRepository.h"

class NetworkModule : public Launchable {
public:
    NetworkModule(Settings& settings, NetworkInterface& networkInterface, NetworkConnectionIdFactory& connectionIdFactory, NetworkConnectionRepository& connectionsRepo);

    void launch() override;
    void shutdown() override;

private:
    void onConnect(NetworkConnection& connection, NetworkConnectionType type);
    void onBytesReceived(NetworkConnectionEntry& connectionEntry, Bytes& bytes);

    Settings& settings;
    NetworkInterface& networkInterface;
    NetworkConnectionIdFactory& connectionIdFactory;
    NetworkConnectionRepository& connectionsRepo;
};