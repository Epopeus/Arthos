#pragma once

#include <common/app/Settings.h>
#include <common/di/Factory.h>
#include <common/app/Launchable.h>
#include "NetworkClient.h"
#include "NetworkServer.h"
#include "NetworkConnectionRepository.h"
#include "NetworkConnectionIdFactory.h"
#include "ReceivedBytesQueue.h"

class NetworkInterface : public Launchable {
public:
    NetworkInterface(Settings& settings, NetworkClient& client, NetworkServer& server, NetworkConnectionIdFactory& connectionIdFactory, NetworkConnectionRepository& connectionsRepo);

    void launch() override;
    void shutdown() override;

private:
    void onConnect(NetworkConnection& connection, NetworkConnectionType type);
    void onBytesReceived(NetworkConnectionId& connectionId, Bytes& bytes);

    Settings& settings;
    NetworkClient& client;
    NetworkServer& server;

    NetworkConnectionIdFactory& connectionIdFactory;
    NetworkConnectionRepository& connectionsRepo;
};