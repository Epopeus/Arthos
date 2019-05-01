#pragma once

#include <string>

class NetworkConnectionId {
public:
    NetworkConnectionId();
    NetworkConnectionId(std::string value);

    const std::string& toString() const;
private:
    std::string value;
};

struct NetworkConnectionIdHash {
    std::size_t operator()(const NetworkConnectionId& id) const ;
};

bool operator==(const NetworkConnectionId& id1, const NetworkConnectionId& id2);