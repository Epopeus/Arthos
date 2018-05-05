#include "Faction.h"

Faction::Faction(int intValue_):intValue(intValue_) {
}

bool Faction::equals(const Faction& f) const {
    return intValue == f.getIntValue();
}

int Faction::getIntValue() const {
    return intValue;
}

bool operator==(const Faction& f1, const Faction& f2) {
    return f1.equals(f2);
}

bool operator!=(const Faction& f1, const Faction& f2) {
    return !(f1 == f2);
}