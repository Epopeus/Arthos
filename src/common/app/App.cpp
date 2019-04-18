#include "App.h"

App::App(SettingsRepository& settingsRepository_, Launchable& networkInterface_, SignalListener& signalListener_):settingsRepository(settingsRepository_), networkInterface(networkInterface_), signalListener(signalListener_) {

}

void App::run() {
    settingsRepository.loadFromDataSource();

    networkInterface.launch();

    signalListener.startListeningForSignals({SIGTERM, SIGINT}, [&]() {
        networkInterface.shutdown();
    });
}