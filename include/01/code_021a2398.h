#pragma once

#include "types.h"

u8 *GetEmblemRecordBytes(void);
u16 *GetEmblemSBPalette(void);
void AdvanceEmblemDisplayWrapper(void);
BOOL AdvanceEmblemAndCheckDone(void);
void InitEmblemAndAdvanceKartList(void);
