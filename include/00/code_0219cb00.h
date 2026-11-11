#pragma once

#include "types.h"

void DWCi_SubPersCallbackLevel(void);
void DWCi_AddPersCallbackLevel(void);
void BuddySyncStatsSaveCallback(u32 localId, u32 profileId, s32 type, u32 index, s32 success, u32 modified,
                                u32 instance);
