#pragma once

#include "types.h"
#include "00/code_0219c93c.h"

void ReleaseWiFiLogin(void);
void ReportWiFiLoginError(s32 error, s32 errorCode);
DWCAccUserData *DWCi_GetUserData(void);
void UpdateWiFiLogin(void);
void DWCi_LoginAsync(void);
