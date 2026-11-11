#pragma once

#include "types.h"

extern char gNumPlayersKey[];
extern char gMaxPlayersKey[];

u32 DWCi_HandleQR2Error(u32 error);
u32 ReportMatchingServerListResult(u32 result);
u32 ReportMatchingGpResult(u32 result);
void DWCi_ProcessOptMinComp(void);
void DWCi_InitOptMinCompParam(s32 reset);
u32 GetMatchingParticipantMaskExceptFirst(s32 valid);
s32 GetMatchingParticipantIndexByProfileId(u32 profileId, s32 b);
s32 GetSbServerProfileIdIfComplete(u32 server);
u8 FindFreeMatchingParticipantIndex(void);
void ReleaseMatchingKeys(void);
