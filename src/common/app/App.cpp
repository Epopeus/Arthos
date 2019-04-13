#include "App.h"

App::App(SettingsRepository& settingsRepository_, Loadable& resources_, Launchable& networkInterface_, SignalListener& signalListener_):settingsRepository(settingsRepository_), resources(resources_), networkInterface(networkInterface_), signalListener(signalListener_) {

}

void App::run() {
    settingsRepository.loadFromDataSource();

    resources.load();

    networkInterface.launch();

    signalListener.startListeningForSignals({SIGTERM, SIGINT}, [&]() {
        networkInterface.shutdown();
    });
}