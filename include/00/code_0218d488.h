#pragma once

#include "types.h"

typedef struct SOCSockAddrIn SOCSockAddrIn;


s32 FloatKeyCompare(u32 *entry1, u32 *entry2);
s32 IntKeyCompare(u32 *entry1, u32 *entry2);
s32 GSIAvailableCheckThink(void);
BOOL HandlePacket(const s8 *packet, s32 len, u8 *address, u32 *disabledservices);
void GSIStartAvailableCheckA(const char *gamename);
void AvailableSendPacket(void);
BOOL get_sockaddrin(const char *hostname, u32 port, SOCSockAddrIn *address);
