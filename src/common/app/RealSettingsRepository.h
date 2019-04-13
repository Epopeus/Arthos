#pragma once

#include "SettingsRepository.h"

class RealSettingsRepository : public SettingsRepository {
public:
    RealSettingsRepository(Settings& settings);
    void loadFromDataSource() override;

    void store(Settings& appSettings) override;
};
