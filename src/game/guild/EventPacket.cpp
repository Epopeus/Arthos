#include "EventPacket.h"

namespace Guild {
    EventPacket::EventPacket() : EventPacket(Type::DISBAND, nullptr, {}) {

    }

    EventPacket::EventPacket(std::string &motd) : EventPacket(Type::MOTD, nullptr, {motd}) {

    }

    EventPacket::EventPacket(Type type_, Name &promoterOrDemoterName, Name &promotedOrDemotedName, std::string &newRankName) : EventPacket(type_, nullptr, {promoterOrDemoterName.getValue(), promotedOrDemotedName.getValue()}) {

    }

    EventPacket::EventPacket(Type type_, Guid &playerGuid_, Name &playerName) : EventPacket(type_, &playerGuid_, {playerName.getValue()}) {

    }

    EventPacket::EventPacket(Type type_, Name &kickerOrOldLeaderName, Name &kickedOrNewLeaderName) : EventPacket(type_, nullptr, {kickerOrOldLeaderName.getValue(), kickedOrNewLeaderName.getValue()}) {

    }

    EventPacket::EventPacket(Type type_, Guid *playerGuid_, std::vector<std::string> miscStrings_) : ServerPacket(Opcode::GUILD_EVENT), type(type_), playerGuid(playerGuid_), miscStrings(miscStrings_) {
    }

    EventPacket::~EventPacket() {
    }
}