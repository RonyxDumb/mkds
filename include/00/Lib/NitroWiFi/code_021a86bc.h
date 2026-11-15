#pragma once

#include "types.h"
#include "00/Lib/NitroWiFi/code_021a6fa8.h"

BOOL SOCL_IsClosed(SOCLSocket *socket);
s32 SOCL_CalmDown(void);
s32 SOCL_CloseAll(void);
s32 SOCL_Cleanup(void);
s32 SOCL_GetHostID(void);
