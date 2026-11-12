#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218e2dc.h" // SOCHostEnt

extern u32 SOCLiDhcpState;

void SOCLi_DhcpTimeout(void);
void SOCLi_TrashSocket(void);
SOCHostEnt *SOC_GetHostByName(const char *hostname);
s32 SOC_Bind(s32 descriptor, const void *address);
