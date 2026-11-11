#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"

// The 0x64 bytes SOCL_Resolve hands to CPS_SocRegister: two blocks of a size and a start address.
typedef struct CPSSoc {
    /* 00 */ u8 mUnk_00[0x3c];
    /* 3c */ SizedBuffer mReceiveBuffer;
    /* 44 */ u8 mUnk_44[4];
    /* 48 */ SizedBuffer mSendBuffer;
    /* 50 */ u8 mUnk_50[0x14];
} CPSSoc;

s32 SOCL_InetAtoH(u32 hostname);
s32 SOCL_Resolve(const char *hostname);
s32 SOCLi_GetReadBufferOccpiedSize(SOCLSocket *socket);
u32 SOCL_GetStatus(SOCLSocket *socket);
u32 SOCLi_RoundUp4(int size);
BOOL SOCL_SocketIsInTrash(SOCLSocket *node);
