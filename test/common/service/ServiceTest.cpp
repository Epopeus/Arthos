#include <gtest/gtest.h>
#include <boost/asio/io_service.hpp>
#include <common/service/Service.h>
#include "../network/FakeTcpServer.h"
#include "../network/FakeTcpClient.h"
#include "../storage/InMemoryDataSource.h"
#include <vector>
#include <any>

class FakeService : public Service {
public:
    FakeService(ServiceSettingsRepository& settingsRepository_, ServiceSettings& settings_, TcpServer& tcpServer_, TcpClient& tcpClient_, SignalListener& signalListener_):Service(settingsRepository_, settings_, tcpServer_, tcpClient_, signalListener_) {

    }

    bool startedUp = false;
    std::vector<uint8> lastReceivedCommand;

protected:
    void startUp() override {
        startedUp = true;
    }

    void handleRemoteCommand(std::vector<uint8> args) override {
        lastReceivedCommand = args;
    }
};

class FakeServiceSettingsRepository : public ServiceSettingsRepository {
public:
    FakeServiceSettingsRepository(ServiceSettings& settings):ServiceSettingsRepository(settings), storedSettings(-1, "", -1) {}

    void loadFromDataSource() override {
        settings = storedSettings;
    }

    void store(ServiceSettings& serviceSettings) override {
        storedSettings = serviceSettings;
    }

private:
    ServiceSettings storedSettings;
};

class ServiceTest : public ::testing::Test {
protected:

    ServiceSettings EXPECTED_SETTINGS = ServiceSettings(1234, "abc", 4321);
    uint8_t EXPECTED_COMMAND = 123;

    FakeServiceSettingsRepository settingsRepository;
    ServiceSettings settings;

    FakeTcpServer tcpServer;
    FakeTcpClient tcpClient;

    SignalListener signalListener;
    boost::asio::io_service ioService;

    FakeService service;

    ServiceTest() : settings(-1, "", -1),
                    settingsRepository(settings),
                    signalListener(ioService),
                    service(settingsRepository, settings, tcpServer, tcpClient, signalListener) {
        settingsRepository.store(EXPECTED_SETTINGS);
    }
};

TEST_F(ServiceTest, ShouldStartUpService) {
    service.run();

    ASSERT_TRUE(service.startedUp);
}

TEST_F(ServiceTest, ShouldLoadSettingsFromDataSource) {
    service.run();

    ASSERT_EQ(EXPECTED_SETTINGS.listenPort, settings.listenPort);
    ASSERT_EQ(EXPECTED_SETTINGS.connectAddress, settings.connectAddress);
    ASSERT_EQ(EXPECTED_SETTINGS.connectPort, settings.connectPort);
}


TEST_F(ServiceTest, ShouldStartTCPServerWithProperSettings) {
    service.run();

    ASSERT_TRUE(tcpServer.started);
    ASSERT_EQ(EXPECTED_SETTINGS.listenPort, tcpServer.port);
}

TEST_F(ServiceTest, ShouldHandleRemoteCommandFromTCPServer) {
    service.run();

    tcpServer.receiveCommand(EXPECTED_COMMAND);

    ASSERT_EQ(EXPECTED_COMMAND, service.lastReceivedCommand.at(0));
}

TEST_F(ServiceTest, ShouldStartTCPClientWithProperSettings) {
    service.run();

    ASSERT_TRUE(tcpClient.connected);
    ASSERT_EQ(EXPECTED_SETTINGS.connectAddress, tcpClient.connectIp);
    ASSERT_EQ(EXPECTED_SETTINGS.connectPort, tcpClient.connectPort);
}

/*
 * TODO : this is problematic because signals are global and hard to test.
 * Figure out a elegant way to test that the server proberly stops when receiving SIGTERM, SIGINT, etc.

TEST_F(ServiceTest, ShouldStopTcpServerWhenTerminated) {
    service.run();
    ioService.run();

    raise(SIGTERM);
    ASSERT_TRUE(tcpServer.stopped);
}

TEST_F(ServiceTest, ShouldStopTcpServerWhenInterrupted) {
    service.run();
    ioService.run();

    raise(SIGINT);
    ASSERT_TRUE(tcpServer.stopped);
}
 */