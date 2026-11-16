#pragma once

#include "types.h"
#include "00/Lib/GameSpy/negotiator_free.h" // NatNegotiator
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/query_reporting.h"

// Six bytes at NNMagicData, written at the start of each buffer.
typedef struct NNMagic {
    /* 0 */ u8 mUnk_00[6];
} NNMagic;

// Port types of an init message (NN_PT_*): NAT_PORT_TYPE_GAME_SOCKET is sent from the game socket to the first matchup
// server, NAT_PORT_TYPE_MATCHUP1 from the negotiation socket to the first, NAT_PORT_TYPE_MATCHUP2 from the negotiation
// socket to the second; each is answered by its own acknowledgement (mInitAckRecv).
#define NAT_PORT_TYPE_GAME_SOCKET 0
#define NAT_PORT_TYPE_MATCHUP1 1
#define NAT_PORT_TYPE_MATCHUP2 2

// How a negotiation ends (NAT_CONNECT_FINISHED_*, the mFinished byte of a connect message), the port of the matchup
// servers, how often and how long (milliseconds) the init and ping messages are sent again, and how long a pinged
// entry waits before it is cancelled.
#define NAT_CONNECT_FINISHED_NO_ERROR 0
#define NAT_CONNECT_FINISHED_DEADBEAT_PARTNER 1
#define NAT_CONNECT_FINISHED_INIT_TIMEOUT 2
#define MATCHUP_SERVER_PORT 0x6cfd
#define NAT_INIT_RETRY_MS 500
#define NAT_INIT_MAX_RETRY_COUNT 30
#define NAT_PING_RETRY_MS 700
#define NAT_PING_MAX_RETRY_COUNT 12
#define NAT_PINGED_CANCEL_DELAY_MS 5000

// Value of the mVersion byte of every message.
#define NAT_PACKET_VERSION 2

// Values of the mPacketType byte (offset 7 of every message). Types 0 to 3 are InitPacket messages, 5 to 7 are
// ConnectPacket messages (6 is an InitPacket sent back).
enum {
    NAT_PACKET_INIT = 0,
    NAT_PACKET_INIT_ACK = 1,
    NAT_PACKET_ECHO_REQUEST = 2,
    NAT_PACKET_ECHO_REPLY = 3,
    NAT_PACKET_CONNECT = 5,
    NAT_PACKET_CONNECT_ACK = 6,
    NAT_PACKET_PING = 7,
};

// The NAT negotiation connect message: cookie, remote address and port, the got-your-data flag and the finished code.
typedef struct ConnectPacket {
    /* 00 */ NNMagic mMagic;
    /* 06 */ u8 mVersion;
    /* 07 */ u8 mPacketType;
    /* 08 */ u8 mCookie[4];
    /* 0c */ u8 mRemoteIp[4];
    /* 10 */ u8 mRemotePort[2];
    /* 12 */ u8 mGotYourData;
    /* 13 */ u8 mFinished;
} ConnectPacket;

// The short NAT negotiation message (init acknowledgement, echo request and reply, connect acknowledgement): cookie,
// port type and client index.
typedef struct InitPacket {
    /* 00 */ NNMagic mMagic;
    /* 06 */ u8 mVersion;
    /* 07 */ u8 mPacketType;
    /* 08 */ u8 mCookie[4];
    /* 0c */ u8 mPortType;
    /* 0d */ u8 mClientIndex;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11;
    /* 12 */ u8 mUnk_12;
    /* 13 */ u8 mUnk_13;
    /* 14 */ u8 mUnk_14;
} InitPacket;

// The NAT negotiation init message with the local address and the game name.
typedef struct InitPacketWithGamename {
    /* 00 */ NNMagic mMagic;
    /* 06 */ u8 mVersion;
    /* 07 */ u8 mPacketType;
    /* 08 */ u8 mCookie[4];
    /* 0c */ u8 mPortType;
    /* 0d */ u8 mClientIndex;
    /* 0e */ u8 mUseGamePort;
    /* 0f */ u8 mLocalIpFirstByte;
    /* 10 */ u8 mLocalIpSecondByte;
    /* 11 */ u8 mLocalIpThirdByte;
    /* 12 */ u8 mLocalIpFourthByte;
    /* 13 */ u8 mLocalPortHighByte;
    /* 14 */ u8 mLocalPortLowByte;
    /* 15 */ char mGameName[0x40];
} InitPacketWithGamename;

void NNProcessData(u8 *data, s32 length, void *fromAddress);
void ProcessInitPacket(NatTraversalEntry *negotiator, InitPacket *packet, SOCSockAddrIn *fromAddress);
void ProcessPingPacket(NatTraversalEntry *negotiator, ConnectPacket *packet, SOCSockAddrIn *fromAddress);
void ProcessConnectPacket(NatTraversalEntry *negotiator, ConnectPacket *packet, SOCSockAddrIn *fromAddress);
void SendConnectAck(NatTraversalEntry *negotiator, SOCSockAddrIn *toaddr);
void NNThink(void);
void NegotiateThink(NatTraversalEntry *negotiator);
void NNCancel(u32 cookie);
s32 NNBeginNegotiationWithSocket(
    u32 gamesocket, u32 cookie, u32 clientNumber, void (*progressCallback)(s32 gamesocket, void *cookie),
    void (*completedCallback)(s32 gamesocket, s32 cookie, void *clientNumber, void *progressCallback), void *userdata);
BOOL ResolveServers(void);
u32 ResolveServer(char *overrideHostname, const char *defaultHostname);
u32 NameToIp(const char *name);
void SendPingPacket(NatTraversalEntry *negotiator);
void SendInitPackets(NatTraversalEntry *negotiator);
u16 GetLocalPort(u32 sock);
u32 GetLocalIP(void);
void SendNegotiatorPacket(u32 sock, u32 toaddr, u16 toport, void *data, s32 length);
BOOL CheckMagic(const u8 *data);
void NNFreeNegotiateList(void);
void RemoveNegotiator(NatTraversalEntry *negotiator);
NatTraversalEntry *AddNegotiator(void);
