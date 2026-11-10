#pragma once

#include "types.h"

void MBi_CheckWmErrcode(u16 command, s32 resultCode);
u32 MBi_IsStarted(void);
u8 MBi_GetAttribute(void);
u16 MBi_GetTgid(void);
unsigned int MBi_GetGgid(void);
