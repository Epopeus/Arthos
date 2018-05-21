#pragma once
#include <common/entity/Guid.h>
#include <unordered_set>

namespace Guild {
    class Roster {
    public:
        Roster();

        ~Roster();

        void add(Guid &newMember);

        void remove(Guid &member);

        bool hasMember(Guid &searchedMember);

        int getNumberOfMembers();

    private:
        std::unordered_set<Guid, GuidHasher, GuidComparator> members;
    };
}