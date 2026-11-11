#include "03/code_021ce110.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021cdcb8.h"
#include "03/code_021d1000.h"
#include "03/code_021d3488.h"
#include "03/code_021d1770.h"
#include "03/code_021d1970.h"
#include "03/code_021d27d8.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0200f5ac.h"
#include "03/unk_021d6000.h"

void AdvanceUsbScanReport(u32 task) {
    u32 flagSetFound;
    Unk021ce4d4 *scan;
    u32 flagClearFound;
    s32 i;
    u64 tick = OS_GetTick();
    scan = (Unk021ce4d4 *) gUsbScan;
    if (tick >= *(u64 *) scan->mStartTick + 0x17f898) {
        flagClearFound = 0;
        flagSetFound = 0;
        for (i = 0; i < 0x10; i++) {
            if (memcmp(scan->mEntries[i].mUnk_00, gUsbScanEmptyBssid, 6) != 0) {
                if (scan->mEntries[i].mUnk_06 != 0) {
                    flagSetFound = 1;
                } else {
                    flagClearFound = 1;
                }
            }
        }
        if (flagSetFound != 0 && flagClearFound != 0) {
            if (scan->mResultCallback != NULL) {
                scan->mResultCallback(2);
            }
        } else if (flagSetFound != 0) {
            if (scan->mResultCallback != NULL) {
                scan->mResultCallback(1);
            }
        } else if (flagClearFound == 0) {
            if (scan->mResultCallback != NULL) {
                scan->mResultCallback(0);
            }
        }
        ((Unk021ce4d4 *) gUsbScan)->mReportTask = 0;
        ((Unk021ce4d4 *) gUsbScan)->mReported = 1;
        RequestTaskRemoval(0, task);
    }
}

void CreateMenuPairObjects(u32 row) {
    s32 i;
    gMenuPairObjects = AllocZeroedExpHeapBlock(0x1c, 4);
    for (i = 0; i < 5; i++) {
        gMenuPairObjects->mObjects[i] = CreateOamRangeFromNceImage(1, gMenuPairObjectImageIds[row][i], 1);
        SetOamRangePriority(gMenuPairObjects->mObjects[i], -1, 0);
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, -0x2a, gMenuPairObjectPositions[i].mY);
        SetOamRangeMode(gMenuPairObjects->mObjects[i], -1, 0, gMenuPairObjectPaletteIds[row][i]);
    }
    gMenuPairObjects->mTask = AddTask(0, AdvanceMenuPairObjectSlideIn0, NULL, 0x78);
    LoadMenuPairScreenMap(row);
    StartSoundSeq(0xd);
}

void AdvanceMenuPairObjectSlideIn0(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[0], 0, (u32 *) &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[0].mX || xPos > 0x100) {
        for (i = 0; i < 5; i++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[0].mX;
    for (i = 0; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideIn1);
}

void AdvanceMenuPairObjectSlideIn1(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[1], 0, (u32 *) &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[1].mX || xPos > 0x100) {
        for (i = 1; i < 5; i++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[1].mX;
    for (i = 1; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideIn2);
}

void AdvanceMenuPairObjectSlideIn2(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[2], 0, (u32 *) &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[2].mX || xPos > 0x100) {
        for (i = 2; i < 5; i++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[2].mX;
    for (i = 2; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideIn3);
}

void AdvanceMenuPairObjectSlideIn3(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[3], 0, (u32 *) &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[3].mX || xPos > 0x100) {
        for (i = 3; i < 5; i++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[3].mX;
    for (i = 3; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideIn4);
}

void AdvanceMenuPairObjectSlideIn4(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[4], 0, (u32 *) &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[4].mX || xPos > 0x100) {
        for (i = 4; i < 5; i++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[4].mX;
    for (i = 4; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectsSlideInEnd);
}
