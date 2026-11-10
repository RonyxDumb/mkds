#pragma once

#include "types.h"

void MBi_CheckWmErrcode(u16 command, s32 resultCode);
u32 MBi_IsStarted(void);
u8 GetGameInfoAttr(void);
u16 GetTgid(void);
unsigned int GetGgid(void);
