#include "03/code_021cdd28.h"

#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1770.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/code_021ce110.h"
#include "03/code_021d1c18.h"
#include "03/code_021cdcb8.h"
#include "03/code_021d1970.h"
#include "03/code_021d3000.h"

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
        func_ov003_021d1790(gMenuPairObjects->mObjects[i], -1, 0);
        SetOamRangePosition(gMenuPairObjects->mObjects[i], -1, gMenuPairObjectPositions[i].mX,
                            gMenuPairObjectPositions[i].mY);
        func_ov003_021d1890(gMenuPairObjects->mObjects[i], -1, 0, gMenuPairObjectPaletteIds[row][i]);
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
