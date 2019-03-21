#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <common/network/NetworkSession.h>

struct Endpoint {
    Endpoint(std::string address_, int port_):address(address_), port(port_) {
    }

    std::string address;
    int port;

    bool operator ==(const Endpoint &o) const {
        return address == o.address && port == o.port;
    }
};

class ServiceSettings {
public:
    ServiceSettings(std::unordered_map<NetworkConnectionType, int> listenPorts_, std::unordered_map<NetworkConnectionType, Endpoint> connectEndpoints_) : listenPorts(listenPorts_), connectEndpoints(connectEndpoints_) {
    }

    std::unordered_map<NetworkConnectionType, int> listenPorts;
    std::unordered_map<NetworkConnectionType, Endpoint> connectEndpoints;
};

