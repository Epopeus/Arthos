#pragma once
#include <string>
#include "DbConnectionURI.h"

class DbClient {
public:

    DbClient(DbConnectionURI &dbConnectionURI);

    ~DbClient();

    void save();
private:
    DbConnectionURI& dbConnectionURI;
};

