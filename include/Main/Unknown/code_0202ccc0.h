#pragma once

#include "types.h"

// Argument of gsend_render: a halfword is set at 4.
typedef struct Unk0202cdf4 {
    /* 00 */ u8 field0[4];
    /* 04 */ u16 field4;
} Unk0202cdf4;

void gsend_vblank(void);
void gsend_finish(void);
s32 gsend_render(Unk0202cdf4 *advanceArg);
void gsend_create(void *parentHeap, void *mainOam, void *subOam);
void SetGhostSendCellsOffsetY(void);
void func_0202d5c0(void);
void func_0202d5f8(s32 messageIndex, s32 withButton);
void func_0202d674(void);
void PrintSelectedGhostSendRecord(void);
void gsend_initCounterLabels(void);
void func_0202d82c(void);
void RefreshGhostListRows(s32 action, s32 slot, s32 row, s32 selectedSlot);
