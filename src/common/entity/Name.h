#pragma once

#include <string>

class Name {
public:
    Name(std::string stringValue_);

    ~Name();

    const std::string& operator()() const;
    bool equals(const Name& otherName) const;

private:
    std::string stringValue;
};

bool operator==(const Name& n1, const Name& n2);

