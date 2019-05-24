#pragma once

#include "SettingsRepository.h"

class BoostSettingsRepository : public SettingsRepository {
public:
    BoostSettingsRepository(Settings& settings);
    void loadFromDataSource() override;

    void store(Settings& appSettings) override;
};
