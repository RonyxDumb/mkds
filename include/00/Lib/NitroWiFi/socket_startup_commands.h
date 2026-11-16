#pragma once

#include "types.h"
#include "00/Lib/NitroWiFi/socket_command_packet.h"
#include "00/Lib/wifi_library_work_objects.h"

void SOCLi_SetMyIP(void);
void SOCLi_StartupCPS(void);
s32 SOCLi_StartupSOCL(void);
s32 SOCL_Startup(SOCLConfig *config);
void SOCLi_CommandPacketHandler(void *queueArgument);
s32 SOCLi_ExecCommandPacketInCtrlPipe(SOCLSocket *socket, SOCLiCommandPacket *packet);
