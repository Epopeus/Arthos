#pragma once

#include "common/storage/DbClient.h"
#include "AuthSettings.h"

class AuthSettingsRepository {
public:
    AuthSettingsRepository(DbClient &dbClient_);

    ~AuthSettingsRepository();

    const AuthSettings getAuthSettings() const;

private:
    DbClient& dbClient;
};

