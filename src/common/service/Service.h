#pragma once

#include "ServiceSettingsRepository.h"
#include "Launchable.h"
#include "Loadable.h"
#include <common/network/NetworkInterface.h>
#include <common/service/SignalListener.h>

class Service {
public:
    Service(ServiceSettingsRepository& settingsRepository, Loadable& resources, Launchable& networkInterface, SignalListener& signalListener);

    void run();

protected:
    ServiceSettingsRepository& settingsRepository;
    Loadable& resources;
    Launchable& networkInterface;
    SignalListener& signalListener;
};

