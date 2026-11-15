#pragma once

#include "types.h"
#include "00/Lib/NitroWiFi/code_021a6fa8.h"

s32 SOCL_InetAtoH(const char *hostname);
s32 SOCL_Resolve(const char *hostname);
s32 SOCLi_GetReadBufferOccpiedSize(SOCLSocket *socket);
u32 SOCL_GetStatus(SOCLSocket *socket);
u32 SOCLi_RoundUp4(int size);
BOOL SOCL_SocketIsInTrash(SOCLSocket *node);
