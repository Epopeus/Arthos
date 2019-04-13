#pragma once

#include <common/app/SettingsRepository.h>

class FakeServiceSettingsRepository : public SettingsRepository {
public:
    FakeServiceSettingsRepository(Settings& settings):SettingsRepository(settings), storedSettings({}, {}) {}

    void loadFromDataSource() override {
        settings = storedSettings;
    }

    void store(Settings& appSettings) override {
        storedSettings = appSettings;
    }

private:
    Settings storedSettings;
};