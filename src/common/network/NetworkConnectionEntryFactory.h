#pragma once

#include "NetworkConnectionRepository.h"
#include <common/di/Factory.h>

using NetworkConnectionEntryFactory = Factory<NetworkConnectionEntry&, NetworkConnection&, NetworkConnectionType>;