#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218e2dc.h" // SOCHostEnt
#include "00/unk_021b5000.h"
#include "00/code_021a6fa8.h"

void SOCLi_DhcpTimeout(void);
void SOCLi_TrashSocket(void);
SOCHostEnt *SOC_GetHostByName(const char *hostname);
s32 SOC_Bind(s32 descriptor, const void *address);

extern u8 SOCLiYieldWait[4];
extern struct SOCLConfig *SOCLiConfigPtr;
extern struct SOCLSocket *SOCLiUDPSendSocket;
extern u32 SOCLiRequestedIP;
extern u32 SOCLiDhcpState;
extern CPSConfig SOCLiCPSConfig;
