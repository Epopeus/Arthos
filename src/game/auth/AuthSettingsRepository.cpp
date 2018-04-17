#include "AuthSettingsRepository.h"

AuthSettingsRepository::AuthSettingsRepository(DbClient &dbClient_) : dbClient(dbClient_) {
}

AuthSettingsRepository::~AuthSettingsRepository() {
}

const AuthSettings AuthSettingsRepository::getAuthSettings() const {
    const AuthSettings settings;
    return settings;
}