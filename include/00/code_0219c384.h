#pragma once

#include "types.h"

extern s32 stDwcLastError;
extern s32 stDwcErrorCode;

void DWCi_SetError(s32 error, s32 errorCode);
u32 DWCi_IsError(void);
void DWC_ClearError(void);
s32 DWC_GetLastError(s32 *errorCode);
