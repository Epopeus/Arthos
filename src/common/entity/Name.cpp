#include "Name.h"

Name::Name(std::string stringValue_) : stringValue(stringValue_) {
}

Name::~Name() {
}

bool Name::equals(const Name& otherName) const {
    return otherName() == operator()();
}

const std::string& Name::operator()() const {
    return stringValue;
}

bool operator==(const Name& n1, const Name& n2) {
    return n1.equals(n2);
}