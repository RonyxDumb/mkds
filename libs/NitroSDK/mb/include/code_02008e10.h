#pragma once

#include "types.h"
#include "code_02008934.h"
#include "code_02008dbc.h"

void MBi_AnalyzeBeacon(u8 *scanBlock, u32 entryIndex, u32 value);
void MB_CountGameInfoLifetime(EntryCallbackFunc callback, u32 value);
void MBi_CheckCompleteGameInfoFlagments(u32 entryIndex, EntryCallbackFunc callback);
s32 MBi_GetStoreElement(const u8 *scanBlock, EntryCallbackFunc callback);

void MBi_SetSSIDToBssDesc(u16 *scanBlock, u32 p1);
