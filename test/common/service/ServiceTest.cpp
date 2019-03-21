#include <gtest/gtest.h>
#include <common/service/Service.h>
#include "FakeServiceSettingsRepository.h"
#include "FakeLaunchable.h"
#include "FakeLoadable.h"

class ServiceTest : public ::testing::Test {
protected:

    ServiceSettings EXPECTED_SETTINGS = ServiceSettings(
            { { NetworkConnectionType::GAME_CLIENT, 1234 }, { NetworkConnectionType::AUTH_CLIENT, 5678 } },
            { { NetworkConnectionType::GAME_SERVER, Endpoint("abc", 9123) }, { NetworkConnectionType::GAME_ROUTER, Endpoint("def", 4567) } }
    );

    ServiceSettings settings;
    FakeServiceSettingsRepository settingsRepository;

    FakeLoadable resources;
    FakeLaunchable networkInterface;

    boost::asio::io_context ioContext;
    SignalListener signalListener;

    Service service;

    ServiceTest() : settings({}, {}),
                    settingsRepository(settings),
                    signalListener(ioContext),
                    service(settingsRepository, resources, networkInterface, signalListener) {
        settingsRepository.store(EXPECTED_SETTINGS);
        service.run();
    }
};

TEST_F(ServiceTest, ShouldLoadSettingsFromDataSource) {
    ASSERT_EQ(EXPECTED_SETTINGS.listenPorts, settings.listenPorts);
    ASSERT_EQ(EXPECTED_SETTINGS.connectEndpoints, settings.connectEndpoints);
}

TEST_F(ServiceTest, ShouldLoadServiceResources) {
    ASSERT_TRUE(resources.loaded);
}


TEST_F(ServiceTest, ShouldLaunchNetworkInterface) {
    ASSERT_TRUE(networkInterface.launched);
}


/*
 * TODO : this is problematic because signals are global and hard to test.
 * Figure out a elegant way to test that the server properly stops when receiving SIGTERM, SIGINT, etc.

TEST_F(ServiceTest, ShouldStopTcpServerWhenTerminated) {
    service.run();
    ioService.run();

    raise(SIGTERM);
    ASSERT_TRUE(networkServer.stopped);
}

TEST_F(ServiceTest, ShouldStopTcpServerWhenInterrupted) {
    service.run();
    ioService.run();

    raise(SIGINT);
    ASSERT_TRUE(networkServer.stopped);
}
 */