#pragma once

#include <common/service/ServiceSettings.h>
#include <common/di/Factory.h>
#include <common/service/Launchable.h>
#include "NetworkClient.h"
#include "NetworkServer.h"
#include "NetworkSession.h"
#include "NetworkSessions.h"
#include "NetworkSessionIdFactory.h"

using NetworkSessionFactory = Factory<NetworkSession&, NetworkConnection&>;

class NetworkInterface : public Launchable {
public:
    NetworkInterface(ServiceSettings& settings, NetworkClient& client, NetworkServer& server, NetworkSessionFactory& sessionFactory, NetworkSessionIdFactory& sessionIdFactory, NetworkSessions& sessions);

    void launch() override;
    void shutdown() override;

private:
    void onConnect(NetworkConnection& connection, NetworkConnectionType type);
    void onBytesReceived(NetworkSessionId sessionId, Bytes& bytes);

    ServiceSettings& settings;
    NetworkClient& client;
    NetworkServer& server;

    NetworkSessionFactory& sessionFactory;
    NetworkSessionIdFactory& sessionIdFactory;
    NetworkSessions& sessions;
};