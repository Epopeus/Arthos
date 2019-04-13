#pragma once

#include "SettingsRepository.h"
#include "Launchable.h"
#include "Loadable.h"
#include <common/network/NetworkInterface.h>
#include <common/app/SignalListener.h>

class App {
public:
    App(SettingsRepository& settingsRepository, Loadable& resources, Launchable& networkInterface, SignalListener& signalListener);

    void run();

protected:
    SettingsRepository& settingsRepository;
    Loadable& resources;
    Launchable& networkInterface;
    SignalListener& signalListener;
};

using ServiceFactory = Factory<App>;
