#pragma once

#include "types.h"

void SetupMatching(u8 matchType, u8 numEntry, UnkFunc *matchedCallback, u32 matchedParam);
void ResetMatching(s32 level);
u32 IsMatchingPointerNull(void);
u32 DWCi_GPSetServerStatus(void);
u32 GetMatchingMaskedParticipantIndices(void **aidList);
u32 GetMatchingParticipantIndices(void **output);
void RefreshMatchingLastMaskedParticipantPos(void);
u8 GetMatchingLastMaskedParticipantPos(void);
u8 GetMatchingLastParticipantPos(void);
u32 RemoveMatchingParticipant(s32 position, s32 count);
u32 RemoveMatchingParticipantByProfileId(int profileId, int count);
void DWCi_ProcessMatchSCClosing(u32 clientPid);
