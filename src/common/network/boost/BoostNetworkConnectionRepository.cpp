#include "BoostNetworkConnectionRepository.h"

NetworkConnectionEntry& BoostNetworkConnectionRepository::add(NetworkConnectionEntry connectionEntry) {
    return const_cast<NetworkConnectionEntry&>(*index.insert(connectionEntry).first);
}

NetworkConnectionEntry& BoostNetworkConnectionRepository::getById(NetworkConnectionId& id) {
    return const_cast<NetworkConnectionEntry&>(*index.get<IndexById>().find(id));
}
