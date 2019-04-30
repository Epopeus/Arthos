#include "App.h"

App::App(SettingsRepository& settingsRepository_, Launchable& networkModule_, SignalListener& signalListener_):settingsRepository(settingsRepository_), networkModule(networkModule_), signalListener(signalListener_) {

}

void App::run() {
    settingsRepository.loadFromDataSource();

    networkModule.launch();

    signalListener.startListeningForSignals({SIGTERM, SIGINT}, [&]() {
        networkModule.shutdown();
    });
}