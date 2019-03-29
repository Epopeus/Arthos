#include "NetworkConnectionId.h"

NetworkConnectionId::NetworkConnectionId() {

}

NetworkConnectionId::NetworkConnectionId(std::string value_):value(value_) {

}

const std::string& NetworkConnectionId::toString() const {
    return value;
}

std::size_t NetworkConnectionIdHash::operator()(const NetworkConnectionId& id) const {
    return std::hash<std::string>{}(id.toString());
}

bool operator==(const NetworkConnectionId& id1, const NetworkConnectionId& id2) {
    return id1.toString() == id2.toString();
}