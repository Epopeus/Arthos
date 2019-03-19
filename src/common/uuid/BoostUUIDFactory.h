#pragma once

#include "UUIDFactory.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

class BoostUUIDFactory : public UUIDFactory {
public:
    BoostUUIDFactory(boost::uuids::random_generator& generator);

    UUID create() override;


private:
    boost::uuids::random_generator& generator;
};

