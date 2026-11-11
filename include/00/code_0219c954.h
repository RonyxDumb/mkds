#pragma once

#include "types.h"
#include "00/code_0219c93c.h"

void DWCi_ShutdownLogin(void);
void DWCi_StopLogin(s32 error, s32 errorCode);
DWCAccUserData *DWCi_GetUserData(void);
void DWCi_LoginProcess(void);
void DWCi_LoginAsync(void);
