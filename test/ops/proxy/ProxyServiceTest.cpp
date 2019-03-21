#include <gtest/gtest.h>
#include <ops/proxy/ProxyService.h>
#include "../../common/network/FakeTcpServer.h"
#include "../../common/network/FakeTcpClient.h"
#include "../../common/service/FakeServiceSettingsRepository.h"
#include "../../common/di/FakeFactory.h"
#include "../../common/network/FakeNetworkConnection.h"
#include <ops/network/Opcode.h>
#include <ops/network/ServerCommand.h>
#include <common/network/Bytes.h>
#include <ops/network/SwitchGameServerCommand.h>
#include <unordered_map>
#include <common/command/GameClientCommand.h>
#include <unordered_map>
#include <utility>
#include <ops/proxy/ForwardPacketCommand.h>

class ProxyServiceTest : public ::testing::Test {
protected:

    ServiceSettings EXPECTED_SETTINGS = ServiceSettings({123}, {{"abc", 123}});
    Bytes EXPECTED_BYTES = {123, 244, 'l'};

    FakeServiceSettingsRepository settingsRepository;
    ServiceSettings settings;

    FakeTcpServer tcpServer;
    FakeTcpClient tcpClient;

    SignalListener signalListener;
    boost::asio::io_context ioContext;

    ProxyService service;

    std::unordered_map<FakeNetworkConnection, FakeNetworkConnection> clientToServerMappingConnections;

    FakeFactory<NetworkSession&, FakeNetworkConnection&> sessionFactory;
    NetworkSessionsMap& sessions;
    NetworkInterface& networkInterface;

    ProxyServiceTest() : settings({-1}, {}),
                         settingsRepository(settings),
                         signalListener(ioContext),
                         networkInterface(settings, tcpClient, tcpServer, sessionFactory, sessions),
                         service(settingsRepository, settings, networkInterface, signalListener) {
        service.run();

    }
};

TEST_F(ProxyServiceTest, ShouldForwardClientPacketsToCorrespondingServer) {
    ForwardPacketCommand command = ForwardPacketCommand();
}

TEST_F(ProxyServiceTest, ShouldForwardServerPacketsToCorrespondingClient) {
    for (auto const& [clientConnection, serverConnection] : clientToServerMappingConnections) {
        serverConnection.simulateReceivedBytes(EXPECTED_BYTES);
        ASSERT_EQ(EXPECTED_BYTES, clientConnection.sentBytes.at(0));
    }
}

TEST_F(ProxyServiceTest, ShouldAskGameRouterForGameServerWhenNewConnectionOccurs) {

}

TEST_F(ProxyServiceTest, ShouldSwitchGameServerWhenRequested) {
    SwitchGameServerCommand command = SwitchGameServerCommand(EXPECTED_SETTINGS.connectAddress, EXPECTED_SETTINGS.connectPort);
    tcpClient.receiveCommand({command});
    ASSERT_TRUE(tcpClient.connected);
    ASSERT_EQ(EXPECTED_SETTINGS.connectAddress, tcpClient.connectIp);
    ASSERT_EQ(EXPECTED_SETTINGS.connectPort, tcpClient.connectPort);
}