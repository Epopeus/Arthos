#include <gtest/gtest.h>
#include <common/app/App.h>
#include "FakeServiceSettingsRepository.h"
#include "FakeLaunchable.h"
#include "FakeLoadable.h"

class AppTest : public ::testing::Test {
protected:

    Settings EXPECTED_SETTINGS = Settings(
            { { NetworkConnectionType::GAME_CLIENT, 1234 }, { NetworkConnectionType::AUTH_CLIENT, 5678 } },
            { { NetworkConnectionType::GAME_SERVER, Endpoint("abc", 9123) }, { NetworkConnectionType::GAME_ROUTER, Endpoint("def", 4567) } }
    );

    Settings settings;
    FakeServiceSettingsRepository settingsRepository;

    FakeLoadable resources;
    FakeLaunchable networkInterface;

    boost::asio::io_context ioContext;
    SignalListener signalListener;

    App app;

    AppTest() : settings({}, {}),
                    settingsRepository(settings),
                    signalListener(ioContext),
                    app(settingsRepository, resources, networkInterface, signalListener) {
        settingsRepository.store(EXPECTED_SETTINGS);
        app.run();
    }
};

TEST_F(AppTest, ShouldLoadSettingsFromDataSource) {
    ASSERT_EQ(EXPECTED_SETTINGS.listenPorts, settings.listenPorts);
    ASSERT_EQ(EXPECTED_SETTINGS.connectEndpoints, settings.connectEndpoints);
}

TEST_F(AppTest, ShouldLoadServiceResources) {
    ASSERT_TRUE(resources.loaded);
}

TEST_F(AppTest, ShouldLaunchNetworkInterface) {
    ASSERT_TRUE(networkInterface.launched);
}

TEST_F(AppTest, ShouldStopTcpServerWhenTerminated) {
    std::raise(SIGTERM);

    ASSERT_FALSE(networkInterface.launched);
}

TEST_F(AppTest, ShouldStopTcpServerWhenInterrupted) {
    std::raise(SIGINT);

    ASSERT_FALSE(networkInterface.launched);
}