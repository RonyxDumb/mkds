#pragma once

#include "types.h"
#include "00/unk_021b4000.h"

typedef struct SOCSockAddrIn SOCSockAddrIn;
typedef struct SbServer SbServer;


s32 FloatKeyCompare(SbServer **entry1, SbServer **entry2);
s32 IntKeyCompare(SbServer **entry1, SbServer **entry2);
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
