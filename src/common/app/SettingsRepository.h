#pragma once

#include <common/storage/Repository.h>
#include "Settings.h"

class SettingsRepository : public Repository {
public:
    SettingsRepository(Settings& appSettings);

    virtual void loadFromDataSource() = 0;
    virtual void store(Settings& appSettings) = 0;
protected:
    Settings& settings;
};