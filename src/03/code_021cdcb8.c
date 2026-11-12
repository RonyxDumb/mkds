#include "03/code_021cdcb8.h"
#include "03/code_021ce110.h"
#include "03/code_021ce5b8.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021d1000.h"
#include "03/code_021d3488.h"
#include "03/code_021d1770.h"
#include "03/code_021d1970.h"
#include "03/code_021d27d8.h"
#include "string.h"
#include "code_02134398.h"
#include "os_tick.h"
#include "03/unk_021d6000.h"
#include "03/code_021cdd28.h"
#include "03/code_021d1c18.h"
#include "03/code_021d3000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "gx_load2d.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"

void AdvanceUsbScanReport(u32 task) {
    u32 flagSetFound;
    UsbScan *scan;
    u32 flagClearFound;
    s32 i;
    u64 tick = OS_GetTick();
    scan = gUsbScan;
    if (tick >= *(u64 *) &scan->mStartTickLow + 0x17f898) {
        flagClearFound = 0;
        flagSetFound = 0;
        for (i = 0; i < 0x10; i++) {
            if (memcmp(scan->mEntries[i].mBssid, gUsbScanEmptyBssid, 6) != 0) {
                if (scan->mEntries[i].mFlag != 0) {
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
        gUsbScan->mReportTask = 0;
        gUsbScan->mReported = 1;
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

void AdvanceMenuPairObjectsSlideInEnd(u32 task) {
    RequestTaskRemoval(0, task);
    gMenuPairObjects->mTask = 0;
}

void StartMenuPairObjectsSlideOut(void) {
    gMenuPairObjects->mSlidingOut = 1;
    gMenuPairObjects->mTask = AddTask(0, AdvanceMenuPairObjectSlideOut4, NULL, 0x78);
}

void ChangeMenuPairObjectImages(u32 row) {
    s32 i;
    for (i = 0; i < 5; i += 2) {
        CopyNceImageToOamEntries(1, gMenuPairObjectImageIds[row][i],
                                 GetOamRangeEntry(gMenuPairObjects->mObjects[i], 0));
        SetOamRangePriority(gMenuPairObjects->mObjects[i], -1, 0);
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, gMenuPairObjectPositions[i].mX,
                            gMenuPairObjectPositions[i].mY);
        SetOamRangeMode(gMenuPairObjects->mObjects[i], -1, 0, gMenuPairObjectPaletteIds[row][i]);
    }
    LoadMenuPairScreenMap(row);
}

BOOL IsMenuPairObjectsSliding(void) {
    if (gMenuPairObjects->mTask != 0) {
        return 1;
    }
    return 0;
}

void AdvanceMenuPairObjectSlideOut4(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[4], 0, (u32 *) &xPos, &yPos);
    xPos -= 8;
    if (xPos > gMenuPairObjectPositions[3].mX) {
        for (i = 4; i < 5; i++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[3].mX;
    for (i = 4; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideOut3);
}

void AdvanceMenuPairObjectSlideOut3(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[3], 0, (u32 *) &xPos, &yPos);
    xPos -= 8;
    if (xPos > gMenuPairObjectPositions[2].mX) {
        for (i = 3; i < 5; i++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[2].mX;
    for (i = 3; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideOut2);
}

void AdvanceMenuPairObjectSlideOut2(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[2], 0, (u32 *) &xPos, &yPos);
    xPos -= 8;
    if (xPos > gMenuPairObjectPositions[1].mX) {
        for (i = 2; i < 5; i++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[1].mX;
    for (i = 2; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideOut1);
}

void AdvanceMenuPairObjectSlideOut1(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[1], 0, (u32 *) &xPos, &yPos);
    xPos -= 8;
    if (xPos > gMenuPairObjectPositions[0].mX) {
        for (i = 1; i < 5; i++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[0].mX;
    for (i = 1; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideOut0);
}

void AdvanceMenuPairObjectSlideOut0(TaskEntry *taskEntry) {
    s32 i;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[0], 0, (u32 *) &xPos, &yPos);
    xPos -= 8;
    for (i = 0; i < 5; i++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, xPos, gMenuPairObjectPositions[i].mY);
    }
    if (xPos <= 0x1d6 && xPos >= 0x100) {
        RequestTaskRemoval(0, (u32) taskEntry);
        for (i = 0; i < 5; i++) {
            DeleteOamRange(gMenuPairObjects->mObjects[i]);
        }
        FreeExpHeapBlockAndClearPointer(&gMenuPairObjects);
    }
}

BOOL IsMenuPairObjectsNotSlidingOut(void) {
    if (gMenuPairObjects == NULL) {
        return 1;
    }
    if (gMenuPairObjects->mSlidingOut == 0) {
        return 1;
    }
    return 0;
}

void LoadMenuPairScreenMap(u32 pathIndex) {
    gMenuPairScreenMap = LoadFile(BuildFilePathWithLanguage(gMenuPairScreenMapPaths[pathIndex]), NULL, 4);
    AddTask(1, AdvanceUploadMenuPairScreenMap, NULL, 0x78);
}

void AdvanceUploadMenuPairScreenMap(u32 task) {
    DC_FlushRange(gMenuPairScreenMap, (0x00000600u));
    GXS_LoadBG1Scr(gMenuPairScreenMap, 0, (0x00000600u));
    DeleteLoadedFile(gMenuPairScreenMap);
    RequestTaskRemoval(1, task);
}
