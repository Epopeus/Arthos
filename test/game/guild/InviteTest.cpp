#include <gtest/gtest.h>
#include <common/network/PacketDeliveryServer.h>
#include <game/guild/Invite.h>
#include <game/guild/AcceptInviteCommand.h>
#include <game/guild/InviteCommand.h>
#include <game/guild/EventPacket.h>
/*
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
                entityManager(),
                invitingCharacterId(123),
                invitingCharacterRoster(),
                invitingCharacterFaction(0),

                invitedCharacterId(456),
                invitedCharacterName("Test"),
                invitedCharacterRoster(),
                invitedCharacterFaction(0),
                invitedCharacter(invitedCharacterId, invitedCharacterFaction, invitedCharacterRoster, invitedCharacterName),

                clock(),
                log(clock),

                packetDeliveryServer(),

                invite(invitedCharacter, log, packetDeliveryServer) {
        }

        void sendInvite() {
            invite.setInvitingCharacter(std::ref<InvitingCharacter>(invitingCharacterId, invitingCharacterFaction, invitingCharacterRoster));
        }

        EntityManager entityManager;
        Guid invitingCharacterId;
        Roster invitingCharacterRoster;
        Faction invitingCharacterFaction;

        Guid invitedCharacterId;
        Name invitedCharacterName;
        Roster invitedCharacterRoster;
        Faction invitedCharacterFaction;
        InvitedCharacter invitedCharacter;

        Clock clock;
        Log log;

        FakePacketDeliveryServer packetDeliveryServer;

        Invite invite;
    };

    // SENDING

    TEST_F(InviteTest, CallsCommandWhenSent) {
        /**
         * Test that raw binary data (char*) is correctly handled by  every command.
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
         

        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, ReceivesInviteWhenSent) {
        //Inviting
        Guid commandSender = Guid(123);

        // Invited
        Entity characterToBeInvited = entityManager.create();
        entityManager.assign<NameComponent>(characterToBeInvited.id, "Test");

        InviteCommandArgs args("Test");
        InviteCommand command(commandSender, entityManager);

        command.run(args);

        ASSERT_TRUE(entityManager.);
        //ASSERT_EQ(nullptr, invitingCharacter->roster);
        //ASSERT_EQ(nullptr, invitingCharacter->faction);
    }

    TEST_F(InviteTest, LogsWhenSent) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, NotifyTargetWhenSent) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, FailsWhenTargetDoesntExist) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, FailsWhenInvitingIsntInGuild) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, FailsWhenTargetIgnoresInviting) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, FailsWhenTargetBelongsToOtherFaction) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, FailsWhenTargetIsInAnotherGuild) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, FailsWhenTargetIsAlreadyInvited) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, FailsWhenInvitingHasNoRights) {
        ASSERT_TRUE(false);
    }





    // ACCEPTING


    TEST_F(InviteTest, CallsCommandWhenAccepted) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, AddsMemberToRosterWhenAccepted) {
        AcceptInviteCommand command(invitingCharacterId);
        command.run();

        ASSERT_TRUE(invitingCharacterRoster.hasMember(invitedCharacterId));
    }

    TEST_F(InviteTest, LogsWhenAccepted) {
        sendInvite();
        invite.accept();

        LogEvent *event = (LogEvent *) log.getEvents().at(0).get();
        ASSERT_EQ(LogEvent::Type::NEW_MEMBER, event->type);
        ASSERT_EQ(invitedCharacterId, event->playerGuid1);
    }

    TEST_F(InviteTest, NotifyRosterWhenAccepted) {
        sendInvite();
        invite.accept();
        if (invitedCharacterRoster.hasMember(invitedCharacterId))
            return;

        if (invitedCharacterFaction != invitingCharacterFaction)
            return;

        invitingCharacterRoster.add(invitedCharacterId);

        log.logEvent(std::make_unique<LogEvent>(LogEvent::Type::NEW_MEMBER, invitedCharacterId));

        packetDeliveryServer.send(std::make_unique<EventPacket>(EventPacket::Type::NEW_MEMBER, invitedCharacterId, invitedCharacterName));
        EventPacket *packet = (EventPacket *) packetDeliveryServer.sentPackets.at(0).get();

        ASSERT_EQ(EventPacket::Type::NEW_MEMBER, packet->type);
        ASSERT_EQ(invitedCharacterId, *packet->playerGuid);
        ASSERT_EQ(invitedCharacterName, packet->miscStrings.at(0));
    }

    TEST_F(InviteTest, FailsWhenNoInviteSent) {
        ASSERT_TRUE(false);
    }

    TEST_F(InviteTest, FailsWhenInvitedIsMember) {
        sendInvite();
        invitingCharacterRoster.add(invitedCharacterId);

        invite.accept();

        ASSERT_EQ(1, invitingCharacterRoster.getNumberOfMembers());
    }

    TEST_F(InviteTest, FailsWhenInvitedIsInOtherGuild) {
        sendInvite();
        invitedCharacterRoster.add(invitedCharacterId);

        invite.accept();

        ASSERT_FALSE(invitingCharacterRoster.hasMember(invitedCharacterId));
    }

    TEST_F(InviteTest, FailsWhenInvitedBelongsToOtherFaction) {
        sendInvite();
        invitedCharacterFaction = Faction(1);

        invite.accept();

        ASSERT_FALSE(invitingCharacterRoster.hasMember(invitedCharacterId));
    }
}*/