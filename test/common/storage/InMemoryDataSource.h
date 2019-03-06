#pragma once

#include <any>
#include <vector>
#include <common/storage/DataSource.h>

class InMemoryDataSource : public DataSource {
public:
    InMemoryDataSource():entities() {

    }

    void put(std::any entity) {
        entities.push_back(entity);
    }

    std::vector<std::any> getAll() {
        return entities;
    }
private:
    std::vector<std::any> entities;
};