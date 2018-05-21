#include "GuildEvent.h"

GuildEvent::GuildEvent():GuildEvent(Type::DISBAND, nullptr, {}) {

}

GuildEvent::GuildEvent(std::string& motd):GuildEvent(Type::MOTD, nullptr, { motd }) {

}

GuildEvent::GuildEvent(Type type_, Name& promoterOrDemoterName, Name& promotedOrDemotedName, std::string& newRankName):GuildEvent(type_, nullptr, { promoterOrDemoterName(), promotedOrDemotedName() }) {

}

GuildEvent::GuildEvent(Type type_, Guid& playerGuid_, Name& playerName):GuildEvent(type_, &playerGuid_, { playerName() }) {

}

GuildEvent::GuildEvent(Type type_, Name& kickerOrOldLeaderName, Name& kickedOrNewLeaderName):GuildEvent(type_, nullptr, { kickerOrOldLeaderName(), kickedOrNewLeaderName() }) {

}

GuildEvent::GuildEvent(Type type_, Guid* playerGuid_, std::vector<std::string> miscStrings_):ServerPacket(Opcode::GUILD_EVENT), type(type_), playerGuid(playerGuid_), miscStrings(miscStrings_) {
}

GuildEvent::~GuildEvent() {
}