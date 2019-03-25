#pragma once

#include "ServiceSettingsRepository.h"

class RealServiceSettingsRepository : public ServiceSettingsRepository {
public:
    RealServiceSettingsRepository(ServiceSettings& settings);
    void loadFromDataSource() override;

    void store(ServiceSettings& serviceSettings) override;
};
