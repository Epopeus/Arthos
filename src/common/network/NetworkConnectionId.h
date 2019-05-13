#pragma once

#include <string>
#include <common/uuid/UUID.h>

class NetworkConnectionId {
public:
    NetworkConnectionId();
    NetworkConnectionId(UUID uuid);

    const std::string& toString() const;
private:
    const UUID uuid;
};

struct NetworkConnectionIdHash {
    std::size_t operator()(const NetworkConnectionId& id) const ;
};

bool operator==(const NetworkConnectionId& id1, const NetworkConnectionId& id2);