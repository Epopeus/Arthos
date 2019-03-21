#include "Service.h"

Service::Service(ServiceSettingsRepository& settingsRepository_, Loadable& resources_, Launchable& networkInterface_, SignalListener& signalListener_):settingsRepository(settingsRepository_), resources(resources_), networkInterface(networkInterface_), signalListener(signalListener_) {

}

void Service::run() {
    settingsRepository.loadFromDataSource();

    resources.load();

    networkInterface.launch();

    signalListener.startListeningForSignals({SIGTERM, SIGINT}, [&]() {
        networkInterface.shutdown();
    });
}