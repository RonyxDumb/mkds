#pragma once

#include "types.h"
#include "00/Lib/wifi_library_globals.h"

typedef struct SOCSockAddrIn SOCSockAddrIn;
typedef struct SbServer SbServer;


s32 FloatKeyCompare(SbServer **entry1, SbServer **entry2);
s32 IntKeyCompare(SbServer **entry1, SbServer **entry2);
// Type byte of the availability check: the first byte of the request packet and the third byte of the reply header.
#define AVAILABLE_PACKET_TYPE 9

s32 GSIAvailableCheckThink(void);
BOOL HandlePacket(const s8 *packet, s32 len, SOCSockAddrIn *address, u32 *disabledservices);
void GSIStartAvailableCheckA(const char *gamename);
void AvailableSendPacket(void);
BOOL get_sockaddrin(const char *hostname, u32 port, SOCSockAddrIn *address);

extern struct SbServerList *gSortServerList;
extern s32 gGsiAcResult;
extern char gGsiAcHostname[0x40];
extern GsiAvailableCheck gGsiAvailableCheck;
extern char gGsiAcGamename[0x40];

extern u8 gAvailablePacketHeader[4];
