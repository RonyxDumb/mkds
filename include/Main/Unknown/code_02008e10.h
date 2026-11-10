#pragma once

#include "types.h"
#include "Main/Unknown/code_02008934.h"
#include "Main/Unknown/code_02008dbc.h"
#include "Main/Unknown/code_020091e0.h"

void MBi_AnalyzeBeacon(u8 *scanBlock, u32 entryIndex, u32 c);
void MB_CountGameInfoLifetime(EntryCallbackFunc callback, u32 b);
void MBi_CheckCompleteGameInfoFlagments(u32 entryIndex, EntryCallbackFunc callback);
s32 MBi_GetStoreElement(const u8 *scanBlock, EntryCallbackFunc callback);

// Declared here until the code that defines it is decompiled.
