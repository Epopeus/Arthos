#pragma once


#include <common/storage/Repository.h>
#include "ServiceSettings.h"

class ServiceSettingsRepository : public Repository {
public:
    ServiceSettingsRepository(ServiceSettings& serviceSettings);

    virtual void loadFromDataSource() = 0;
protected:
    ServiceSettings& settings;
};
