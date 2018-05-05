#pragma once

class Faction {
public:
    Faction(int intValue_);

    int getIntValue() const;
    bool equals(const Faction& f) const;
private:
    int intValue;
};

bool operator==(const Faction& f1, const Faction& f2);
bool operator!=(const Faction& f1, const Faction& f2);