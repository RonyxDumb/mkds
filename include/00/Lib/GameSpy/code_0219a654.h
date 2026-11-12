#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0219b1d4.h" // NatTraversalEntry
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021a3a18.h"

// Six bytes at NNMagicData, written at the start of each buffer.
typedef struct NNMagic {
    /* 0 */ u8 mUnk_00[6];
} NNMagic;

// Message of 0x14 bytes; made of bytes so a copy of it is bytewise.
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

// Message of 0x15 bytes.
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

// Message of 0x15 bytes followed by a string.
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

BOOL gt2StringToAddress(const char *string, u32 *ipOut, u16 *portOut);
u32 gt2AddressToString(u32 ipAddress, u32 port, char *buffer);
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
