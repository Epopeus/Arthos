#include "Roster.h"

namespace Guild {
    Roster::Roster() {
    }

    Roster::~Roster() {
    }

    void Roster::add(Guid &newMember) {
        members.insert(newMember);
    }

    void Roster::remove(Guid &member) {

    }

    bool Roster::hasMember(Guid &searchedMember) {
        return members.count(searchedMember);
    }

    int Roster::getNumberOfMembers() {
        return members.size();
    }
}