#include "BoostUUIDFactory.h"
#include <boost/uuid/uuid_io.hpp>

BoostUUIDFactory::BoostUUIDFactory(boost::uuids::random_generator& generator_):generator(generator_) {
}

UUID BoostUUIDFactory::create() {
    return boost::uuids::to_string(generator());
}
