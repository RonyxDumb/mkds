#pragma once

#include "types.h"

// csfx_sSfxOverrides is addressed in rows of eight words.
typedef struct Unk0217cd30 {
    /* 0 */ u32 field0[8];
} Unk0217cd30;

#include "code_0212d214.h"

// Addressed at the byte offset NNSFndList.mLinkOffset of the pointer passed to list_remove.
typedef struct Unk0210bc54 {
    /* 0 */ u8 field0[8];
    /* 8 */ void *field8;
} Unk0210bc54;

u32 csfx_getWallSfx(s32 entryIndex, s32 rowIndex, s32 columnIndex);
u32 csfx_getFloorSfx(s32 entryIndex, s32 surfaceKind, s32 surfaceVariant);
void csfx_init(void);
void list_remove(NNSFndList *list, void *object);
u32 list_append(void *list, void *object);
