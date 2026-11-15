#pragma once

#include "types.h"
#include "00/unk_021b4000.h"
#include "00/code_021a6fa8.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/unk_021b5000.h"
#include "00/Lib/DWC/code_0218a064.h"

// Objects whose layout isn't known yet.
extern u32 SOCLiResultCodeInConnecting;
extern SOCLSocketParam SOCLSocketParamTCP;
extern SOCLSocketParam SOCLSocketParamUDPSend;
extern struct SOCLSocket *SOCLiSocketListTrash;
extern void *(*AllocFunc_SOC)(u32 a, u32 b);
extern u32 hostip;
// Objects whose layout isn't known yet.
extern SocketFreeFn FreeFunc_SOC;
extern struct SOCLSocket *SOCLiSocketList;
extern u32 *hostAddrList[2];
extern SOCHostEnt hostent;
extern char sInetNtoABuffer[16];
extern SOCLConfig soclConfig;
extern s8 entName[0x104];
