#pragma once

#include <common/service/ServiceSettings.h>
#include <common/di/Factory.h>
#include <common/service/Launchable.h>
#include "NetworkClient.h"
#include "NetworkServer.h"
#include "NetworkConnections.h"
#include "NetworkConnectionIdFactory.h"

class NetworkInterface : public Launchable {
public:
    NetworkInterface(ServiceSettings& settings, NetworkClient& client, NetworkServer& server, NetworkConnectionIdFactory& connectionIdFactory, NetworkConnections& connections);

    void launch() override;
    void shutdown() override;

private:
    void onConnect(NetworkConnection& connection, NetworkConnectionType type);
    void onBytesReceived(NetworkConnectionId connectionId, Bytes& bytes);

    ServiceSettings& settings;
    NetworkClient& client;
    NetworkServer& server;

    NetworkConnectionIdFactory& connectionIdFactory;
    NetworkConnections& connections;
};