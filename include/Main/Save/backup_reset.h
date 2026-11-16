#pragma once

#include "types.h"

void SetMKDSSVExtraKartUnlockFlagsByState_from_thumb(u32 value);
u8 CheckExtraKartUnlockFlags_from_thumb(void);
u8 CheckExtraKartUnlockFlagsWith_from_thumb(u8 *bytes);
BOOL CheckSavedSecretFlag_from_thumb(u32 flagIndex);
BOOL CheckSecretFlagWith_from_thumb(s32 bitIndex, u8 *bytes);
void SetSavedSecretFlag_from_thumb(s32 flagIndex);
void EraseNonGhostSaveDataSections_from_thumb(void);
void Task_EraseNonGhostSaveDataSections_from_thumb(void);
void ReadSaveData_NonGhost_from_thumb(void);
void Task_ReadNonGhostSaveData_from_thumb(void);
void OverwriteEmptySaveData_from_thumb(void);
