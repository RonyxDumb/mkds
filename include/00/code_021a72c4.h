#pragma once

#include "types.h"
#include "00/code_021a6fb4.h"
#include "00/unk_021b4000.h"

s32 SOCLi_GetSizeSocket(SOCLSocketParam *param);
SOCLSocket *SOCLi_StartupSocket(SOCLSocketParam *param);
s32 SOCLi_CreateSocketCallBack(SOCLiCommandPacket *command);
