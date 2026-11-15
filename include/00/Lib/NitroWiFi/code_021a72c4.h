#pragma once

#include "types.h"
#include "00/Lib/NitroWiFi/code_021a6fb4.h"
#include "00/Lib/wifi_library_globals.h"

s32 SOCLi_GetSizeSocket(SOCLSocketParam *param);
SOCLSocket *SOCLi_StartupSocket(SOCLSocketParam *param);
s32 SOCLi_CreateSocketCallBack(SOCLiCommandPacket *command);
