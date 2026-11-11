#pragma once

#include "types.h"
#include "03/code_021cdd28.h"
#include "03/unk_021da000.h"
#include "03/code_021d3488.h"

// Entry of the table at offset 0x1300 of the object at gUsbScan.
typedef struct Unk021ce4d4_1300 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mUnk_06;
} Unk021ce4d4_1300;

// Object at gUsbScan, as far as AdvanceUsbScanReport uses it.
typedef struct Unk021ce4d4 {
    /* 0000 */ u8 mUnk_0000[0x1300];
    /* 1300 */ Unk021ce4d4_1300 mEntries[0x10];
    /* 1370 */ void (*mResultCallback)(s32);
    /* 1374 */ u8 mUnk_1374[0x800];
    /* 1b74 */ u32 mStartTick[2];
    /* 1b7c */ u32 mReportTask;
    /* 1b80 */ u8 mUnk_1b80[2];
    /* 1b82 */ u8 mReported;
} Unk021ce4d4;

extern u8 gMenuPairObjectImageIds[][5];
extern u8 gMenuPairObjectPaletteIds[][5];

void AdvanceMenuPairObjectSlideIn4(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideIn3(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideIn2(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideIn1(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideIn0(TaskEntry *taskEntry);

void CreateMenuPairObjects(u32 row);
void AdvanceUsbScanReport(u32 task);
