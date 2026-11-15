#pragma once

#include "types.h"
#include "00/Lib/DWC/dwc_match_work.h"

void DWCi_SetMatchCommonParam(u8 matchType, u8 numEntry, DWCMatchedCallback matchedCallback, u32 matchedParam);
void DWCi_ResetMatchParam(s32 level);
u32 DWCi_IsShutdownMatch(void);
u32 DWCi_GPSetServerStatus(void);
u32 DWCi_GetValidAIDList(u8 **aidList);
u32 DWCi_GetAllAIDList(u8 **output);
void DWCi_SetNumValidConnection(void);
u8 DWCi_GetNumValidConnection(void);
u8 DWCi_GetNumAllConnection(void);
u32 DWCi_DeleteHostByIndex(s32 position, s32 count);
u32 DWCi_DeleteHostByProfileID(int profileId, int count);
void DWCi_ProcessMatchSCClosing(u32 clientPid);
