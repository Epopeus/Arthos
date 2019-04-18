#pragma once

#include <common/app/SettingsRepository.h>

class FakeSettingsRepository : public SettingsRepository {
public:
    FakeSettingsRepository(Settings& settings):SettingsRepository(settings), storedSettings({}, {}) {}

    void loadFromDataSource() override {
        settings = storedSettings;
    }

    void store(Settings& appSettings) override {
        storedSettings = appSettings;
    }

private:
    Settings storedSettings;
};