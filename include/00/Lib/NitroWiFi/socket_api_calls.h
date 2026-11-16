#pragma once

#include "types.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/NitroWiFi/socket_objects.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/socket_config.h"

extern u32 SOCLiResultCodeInConnecting;
extern SOCLSocketParam SOCLSocketParamTCP;
extern SOCLSocketParam SOCLSocketParamUDPSend;
extern struct SOCLSocket *SOCLiSocketListTrash;
extern SocketAllocFn AllocFunc_SOC;
extern u32 hostip;
extern SocketFreeFn FreeFunc_SOC;
extern struct SOCLSocket *SOCLiSocketList;
extern u32 *hostAddrList[2];
extern SOCHostEnt hostent;
extern char sInetNtoABuffer[16];
extern SOCLConfig soclConfig;
extern s8 entName[0x104];
