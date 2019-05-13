#include "NetworkConnectionId.h"

NetworkConnectionId::NetworkConnectionId() {

}

NetworkConnectionId::NetworkConnectionId(UUID uuid_):uuid(uuid_) {

}

const std::string& NetworkConnectionId::toString() const {
    return uuid;
}

std::size_t NetworkConnectionIdHash::operator()(const NetworkConnectionId& id) const {
    return std::hash<std::string>{}(id.toString());
}

bool operator==(const NetworkConnectionId& id1, const NetworkConnectionId& id2) {
    return id1.toString() == id2.toString();
}