#pragma once

#include "types.h"

extern char gNumPlayersKey[];
extern char gMaxPlayersKey[];

u32 DWCi_HandleQR2Error(u32 error);
u32 DWCi_HandleSBError(u32 result);
u32 ReportMatchingGpResult(u32 result);
void DWCi_ProcessOptMinComp(void);
void DWCi_InitOptMinCompParam(s32 reset);
u32 DWCi_GetAIDBitmask(s32 valid);
s32 DWCi_GetAIDFromProfileID(u32 profileId, s32 b);
s32 DWCi_CheckDWCServer(u32 server);
u8 DWCi_GetAIDFromList(void);
void DWCi_ClearGameMatchKeys(void);
