#pragma once

#include <common/entity/Guid.h>
#include "KeyValueStore.h"

template<class V>
using GuidValueStore = KeyValueStore<Guid, V, uint64>;