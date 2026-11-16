#pragma once

#include "types.h"

// The 0x1e8 bytes at the start of the object behind gRaceMultiConfig, taken from 0x1e8.
typedef struct RaceSetupBlock {
    /* 000 */ u32 field0[0x7a];
} RaceSetupBlock;

u16 rconf_getLapCount(void);
void ResetTimeAttackNextEntries(void);
void Scene_Menu2_FinalizeImpl(void);
void rconf_setupNext(void);
BOOL rconf_loadStaffGhost(s32 courseId, s32 entryIndex);
s32 rconf_loadDownloadGhost(s32 courseId, s32 entryIndex);
BOOL rconf_loadPersonalGhost(s32 courseId, s32 entryIndex);
void sub_2044FC0(void);
void SetCurrentEntryPlayer(s32 entryIndex);
void rconf_reset(void);
