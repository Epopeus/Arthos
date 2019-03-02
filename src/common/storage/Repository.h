#pragma once

#include "DbClient.h"

class Repository {
public:
    Repository(DbClient& dbClient);

    template<class T>
    const T& get() const {

    }
private:
    DbClient& dbClient;
};

