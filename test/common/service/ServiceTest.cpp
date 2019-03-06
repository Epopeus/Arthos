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

protected:
    void startUp() override {}
    void handleRemoteCommand(std::vector<uint8> args) override {}
};

class FakeServiceSettingsRepository : public ServiceSettingsRepository {
public:
    FakeServiceSettingsRepository(InMemoryDataSource& dataSource_, ServiceSettings& settings):dataSource(dataSource_), ServiceSettingsRepository(settings) {}

    void loadFromDataSource() override {
        ServiceSettings savedSettings = std::any_cast<ServiceSettings>(dataSource.getAll().at(0));

        settings.connectAddress = savedSettings.connectAddress;
        settings.connectPort = savedSettings.connectPort;
        settings.listenPort = savedSettings.listenPort;
    }

private:
    InMemoryDataSource& dataSource;
};
class ServiceTest : public ::testing::Test {
protected:

    const ServiceSettings EXPECTED_SETTINGS = ServiceSettings(1234, "abc", 4321);

    InMemoryDataSource dataSource;
    FakeServiceSettingsRepository settingsRepository;
    ServiceSettings settings;

    FakeTcpServer tcpServer;
    FakeTcpClient tcpClient;

    SignalListener signalListener;
    boost::asio::io_service ioService;

    FakeService service;

    ServiceTest() : settings(-1, "", -1),
                    settingsRepository(dataSource, settings),
                    signalListener(ioService),
                    service(settingsRepository, settings, tcpServer, tcpClient, signalListener) {
    }
};

TEST_F(ServiceTest, ShouldLoadSettingsFromDataSource) {
    dataSource.put(EXPECTED_SETTINGS);

    service.run();

    ASSERT_EQ(EXPECTED_SETTINGS.listenPort, settings.listenPort);
    ASSERT_EQ(EXPECTED_SETTINGS.connectAddress, settings.connectAddress);
    ASSERT_EQ(EXPECTED_SETTINGS.connectPort, settings.connectPort);
}
TEST_F(ServiceTest, ShouldStartTCPServerWithProperSettings) {
    dataSource.put(settings);

    service.run();

    ASSERT_TRUE(tcpServer.started);
    ASSERT_EQ(EXPECTED_SETTINGS.listenPort, tcpServer.port);
}


TEST_F(ServiceTest, ShouldStartTCPClientWithProperSettings) {
    ASSERT_TRUE(false);
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