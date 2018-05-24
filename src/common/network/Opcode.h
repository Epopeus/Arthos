#pragma once

/**
 * All here to ensure no duplication
 * Naming convention : moduleName_opcodeName
 * The corresponding packet classes are in the moduleName namespace, and named (opcodeName)Packet
 */
enum class Opcode {
    GUILD_ACCEPT_INVITE         = 0x084,
    GUILD_EVENT                 = 0x092,
};