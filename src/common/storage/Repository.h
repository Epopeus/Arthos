#pragma once


#include "DataSource.h"

class Repository {
public:
    virtual void loadFromDataSource() = 0;
};

