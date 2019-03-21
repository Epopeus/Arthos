#include <iostream>
#include "ProxyService.h"

ProxyService::ProxyService(ServiceSettingsRepository& settingsRepository_, ServiceSettings& settings_, NetworkInterface& networkInterface_, SignalListener& signalListener_):Service(settingsRepository_, settings_, networkInterface_, signalListener_) {
}

void ProxyService::startUp() {
}