#pragma once

#include "types.h"
#include "00/code_021a6fb4.h"
#include "00/unk_021b5000.h"

void SOCLi_SetMyIP(void);
void SOCLi_StartupCPS(void);
s32 SOCLi_StartupSOCL(void);
s32 SOCL_Startup(SOCLConfig *config);
void SOCLi_CommandPacketHandler(void *queueArgument);
s32 SOCLi_ExecCommandPacketInCtrlPipe(SOCLSocket *socket, SOCLiCommandPacket *packet);
