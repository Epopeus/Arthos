#include "FakeLaunchable.h"

void FakeLaunchable::launch() {
    launched = true;
}

void FakeLaunchable::shutdown() {
    launched = false;
}
