#pragma once

#include <common/service/Service.h>

class ProxyService : public Service {
public:
    ProxyService(ServiceSettingsRepository& settingsRepository, ServiceSettings& settings, NetworkInterface& networkInterface, SignalListener& signalListener);

protected:
    void startUp() override;
};

