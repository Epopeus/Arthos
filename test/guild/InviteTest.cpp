#include <gtest/gtest.h>
#include <common/network/ClientPacket.h>
#include <game/guild/AcceptInviteCommand.h>
#include <game/guild/InviteCommand.h>
#include <game/character/CharacterRepository.h>
#include "game/guild/Invite.h"
#include "game/guild/EventPacket.h"

class FakePacketDeliveryServer : public PacketDeliveryServer {
public:
    FakePacketDeliveryServer():sentPackets() {
    }

    virtual void send(std::unique_ptr<ServerPacket> packet) {
        sentPackets.push_back(std::move(packet));
    }

    std::vector<std::unique_ptr<ServerPacket>> sentPackets;
};


namespace Guild {
    class InviteTest : public ::testing::Test {
    public:
        InviteTest() :
                invitedPlayerId(Guid(123)),
                invitedPlayerName("Test"),
                invitedPlayerCurrentRoster(Roster()),
                invitedPlayerFaction(Faction(0)),

                invitingPlayerId(Guid(456)),
                invitingPlayerRoster(Roster()),
                invitingPlayerFaction(Faction(0)),

                clock(Clock()),
                log(Log(clock)),
                packetDeliveryServer(FakePacketDeliveryServer()),
                invite(getInviteObject()) {

        }

        Invite* getInviteObject() {
            return new Invite(invitingPlayerId, invitingPlayerRoster, invitingPlayerFaction, invitedPlayerId, invitedPlayerName, invitedPlayerCurrentRoster, invitedPlayerFaction, log, packetDeliveryServer);
        }

        Guid invitedPlayerId;
        Name invitedPlayerName;
        Roster invitedPlayerCurrentRoster;
        Faction invitedPlayerFaction;

        Guid invitingPlayerId;
        Roster invitingPlayerRoster;
        Faction invitingPlayerFaction;

        Clock clock;
        Log log;
        FakePacketDeliveryServer packetDeliveryServer;

        Invite* invite;
    };

    TEST_F(InviteTest, CallsCommandWhenSent) {
        /**
         * Test that raw binary data (char*) is correctly handled by every command.
         * In other words, test that char* is correctly casted to the corresponding Command class.
         * For other tests, directly use a Command class.
         */
        /*
         BinaryData clientData = BinaryData();

        clientData << Opcode::GUILD_ACCEPT_INVITE;
        clientData << 8;
        clientData << "MyPlayerName"


            class MyCommand {
            public:
                MyCommand(uint8 x_, std::string y_, bool z_):x(x_), y(y_), z(z_) {

                }

                uint8 x;
                std::string y;
                bool z;

            };

            MyCommand command = std::make_from_tuple<MyCommand>(std::make_tuple(12, "Test", true));
         */

        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, InitsInviteWhenSent) {
        CharacterRepository charRepo = CharacterRepository();
        charRepo.add(Character(Guid(789), "Test"));

        invitingPlayerId = Guid(0);
        invite = getInviteObject();

        Guid commandSender = Guid(123);
        InviteCommand command(commandSender);

        InviteCommandArgs args;
        args.invitedCharName = "Test";

        command.run(args);

        //ASSERT_EQ(Guid(789), invitingPlayer->id);
    }

    TEST_F(InviteTest, LogsWhenSent) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, NotifyTargetWhenSent) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, CallsCommandWhenAccepted) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, AddsMemberToRosterWhenAccepted) {
        AcceptInviteCommand command(invitingPlayerId);
        command.run();

        ASSERT_TRUE(invitingPlayerRoster.hasMember(invitedPlayerId));
    }

    TEST_F(InviteTest, LogsWhenAccepted) {
        invite->accept();

        LogEvent *event = (LogEvent *) log.getEvents().at(0).get();
        ASSERT_EQ(LogEvent::Type::NEW_MEMBER, event->type);
        ASSERT_EQ(invitedPlayerId, event->playerGuid1);
    }

    TEST_F(InviteTest, NotifyRosterWhenAccepted) {
        invite->accept();
        if (invitedPlayerCurrentRoster.hasMember(invitedPlayerId))
            return;

        if (invitedPlayerFaction != invitingPlayerFaction)
            return;

        invitingPlayerRoster.add(invitedPlayerId);

        log.logEvent(std::make_unique<LogEvent>(LogEvent::Type::NEW_MEMBER, invitedPlayerId));

        packetDeliveryServer.send(std::make_unique<EventPacket>(EventPacket::Type::NEW_MEMBER, invitedPlayerId, invitedPlayerName));
        EventPacket *packet = (EventPacket *) packetDeliveryServer.sentPackets.at(0).get();

        ASSERT_EQ(EventPacket::Type::NEW_MEMBER, packet->type);
        ASSERT_EQ(invitedPlayerId, *packet->playerGuid);
        ASSERT_EQ(invitedPlayerName, packet->miscStrings.at(0));
    }

    TEST_F(InviteTest, FailsWhenNoInviteSent) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, FailsWhenPlayerIsMember) {
        invitingPlayerRoster.add(invitedPlayerId);

        invite->accept();

        ASSERT_EQ(1, invitingPlayerRoster.getNumberOfMembers());
    }

    TEST_F(InviteTest, FailsWhenPlayerIsInOtherGuild) {
        invitedPlayerCurrentRoster.add(invitedPlayerId);

        invite->accept();

        ASSERT_FALSE(invitingPlayerRoster.hasMember(invitedPlayerId));
    }

    TEST_F(InviteTest, FailsWhenPlayerBelongsToOtherFaction) {
        invitedPlayerFaction = Faction(1);

        invite->accept();

        ASSERT_FALSE(invitingPlayerRoster.hasMember(invitedPlayerId));
    }
}