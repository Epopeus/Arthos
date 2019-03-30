#include "FakeUUIDFactory.h"

UUID FakeUUIDFactory::create() {
    return std::to_string(++count);
}
