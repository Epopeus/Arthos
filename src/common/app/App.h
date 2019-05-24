#pragma once

#include "SettingsRepository.h"
#include "Launchable.h"
#include <common/network/NetworkModule.h>
#include <common/app/SignalListener.h>

class App {
public:
    App(SettingsRepository& settingsRepository, Launchable& networkModule, SignalListener& signalListener);

    void run();

protected:
    SettingsRepository& settingsRepository;
    Launchable& networkModule;
    SignalListener& signalListener;
};