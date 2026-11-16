#pragma once

#include "types.h"

typedef struct Unk0201ea30 Unk0201ea30;

// 0x40-byte entry that mutil2_setElementPositionFromBnll and mutil2_setElementPositionFromBncl fill.
typedef struct Unk02025bb4Entry {
    /* 00 */ u8 field0[8];
    /* 08 */ u32 field8;
    /* 0c */ s16 fieldC;
    /* 0e */ s16 fieldE;
    /* 10 */ u8 field10[0x30];
} Unk02025bb4Entry;

void RectTableSetEntryXY(int id, int x, int y, Unk0201ea30 *graphics);
void mutil2_setElementPositionFromBnll(u32 entryId, void *outputPointer, Unk0201ea30 *labelLayout);
void mutil2_setElementPositionFromBncl(u32 entryId, void *outputPointer, Unk0201ea30 *cellLayout);
void func_02025c48(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout);
void func_02025c6c(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout);
void func_02025c94(int id, int x, int y, Unk0201ea30 *graphics);
