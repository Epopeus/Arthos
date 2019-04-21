#pragma once

#include "common/network/NetworkConnectionRepository.h"
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>

using namespace boost::multi_index;

struct IndexById {};
struct IndexByType {};

using NetworkConnectionEntryIndex = boost::multi_index_container<
        NetworkConnectionEntry,
        indexed_by<
        hashed_unique<tag<IndexById>, member<NetworkConnectionEntry, NetworkConnectionId, &NetworkConnectionEntry::id>, NetworkConnectionIdHash>,
        hashed_non_unique<tag<IndexByType>, member<NetworkConnectionEntry, NetworkConnectionType, &NetworkConnectionEntry::type>>
        >
        >;

class BoostNetworkConnectionRepository : public NetworkConnectionRepository {
public:
    NetworkConnectionEntry& add(NetworkConnectionEntry connectionEntry) override;
    NetworkConnectionEntry& getById(NetworkConnectionId& id) override;

private:
    NetworkConnectionEntryIndex index;
};
