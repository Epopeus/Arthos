#pragma once

#include <common/service/ServiceSettingsRepository.h>

class FakeServiceSettingsRepository : public ServiceSettingsRepository {
public:
    FakeServiceSettingsRepository(ServiceSettings& settings):ServiceSettingsRepository(settings), storedSettings({}, {}) {}

    void loadFromDataSource() override {
        settings = storedSettings;
    }

    void store(ServiceSettings& serviceSettings) override {
        storedSettings = serviceSettings;
    }

private:
    ServiceSettings storedSettings;
};