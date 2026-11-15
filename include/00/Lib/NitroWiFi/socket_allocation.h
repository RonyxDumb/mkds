#pragma once

#include "types.h"
#include "00/Lib/NitroWiFi/socket_command_packet.h"
#include "00/Lib/wifi_library_globals.h"

s32 SOCLi_GetSizeSocket(SOCLSocketParam *param);
SOCLSocket *SOCLi_StartupSocket(SOCLSocketParam *param);
s32 SOCLi_CreateSocketCallBack(SOCLiCommandPacket *command);
