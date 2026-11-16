#include "03/Menu/menu_pair_objects.h"
#include "03/Menu/menu_pair_objects_slide_in.h"
#include "03/Net/usb_scan.h"
#include "sound_archive_load_result.h"
#include "03/Sound/sound_seq.h"
#include "03/Graphics/oam_range_set.h"
#include "03/Graphics/oam_range.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/System/tasks.h"
#include "03/Graphics/nce_oam.h"
#include "03/Graphics/oam_range_entry.h"
#include "03/System/exp_heap.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "tick_counter.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/Menu/menu_pair_objects_slide_out.h"
#include "03/Graphics/nce_file.h"
#include "thread_scheduler.h"
#include "arena_cache_init.h"
#include "vram_load_2d_graphics.h"
#include "03/System/wifi_utility_archive.h"
#include "03/Menu/menu_pair_loading.h"

const u8 gMenuPairObjectPaletteIds[3][5] = {{2, 1, 3, 1, 3}, {5, 1, 4, 1, 5}, {7, 1, 7, 1, 6}};
char *gMenuPairScreenMapPaths[5] = {"char/jtStep1.nsc.l", "char/jtStep2.nsc.l", "char/jtStep3.nsc.l",
                                    "char/jtOption.nsc.l", "char/jtTop.nsc.l"};
const u8 gMenuPairObjectImageIds[3][5] = {{1, 0, 5, 0, 6}, {4, 0, 2, 0, 6}, {4, 0, 5, 0, 3}};
const MenuPairObjectPosition gMenuPairObjectPositions[5] = {
    {0x20, 0x21}, {0x50, 0x30}, {0x68, 0x21}, {0x98, 0x30}, {0xb0, 0x21}};
void *gMenuPairScreenMap;
struct MenuPairObjects *gMenuPairObjects;

void AdvanceUsbScanReport(TaskEntry *task, void *arg) {
    u32 flagSetFound;
    UsbScan *scan;
    u32 flagClearFound;
    s32 entryIndex;
    u64 tick = Os_GetTick();
    scan = gUsbScan;
    if (tick >= scan->mStartTick + 0x17f898) {
        flagClearFound = 0;
        flagSetFound = 0;
        for (entryIndex = 0; entryIndex < 0x10; entryIndex++) {
            if (StructDC_SomeFn_6(scan->mEntries[entryIndex].mBssid, gUsbScanEmptyBssid, 6) != 0) {
                if (scan->mEntries[entryIndex].mFlag != 0) {
                    flagSetFound = 1;
                } else {
                    flagClearFound = 1;
                }
            }
        }
        if (flagSetFound != 0 && flagClearFound != 0) {
            if (scan->mResultCallback != NULL) {
                scan->mResultCallback(USB_SCAN_RESULT_MIXED);
            }
        } else if (flagSetFound != 0) {
            if (scan->mResultCallback != NULL) {
                scan->mResultCallback(USB_SCAN_RESULT_FLAGGED);
            }
        } else if (flagClearFound == 0) {
            if (scan->mResultCallback != NULL) {
                scan->mResultCallback(USB_SCAN_RESULT_NONE);
            }
        }
        gUsbScan->mReportTask = 0;
        gUsbScan->mReported = 1;
        RequestTaskRemoval(0, task);
    }
}

void CreateMenuPairObjects(u32 row) {
    s32 objectIndex;
    gMenuPairObjects = AllocZeroedExpHeapBlock(0x1c, 4);
    for (objectIndex = 0; objectIndex < 5; objectIndex++) {
        gMenuPairObjects->mObjects[objectIndex] =
            CreateOamRangeFromNceImage(1, gMenuPairObjectImageIds[row][objectIndex], 1);
        SetOamRangePriority(gMenuPairObjects->mObjects[objectIndex], -1, 0);
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, -0x2a,
                            gMenuPairObjectPositions[objectIndex].mY);
        SetOamRangeMode(gMenuPairObjects->mObjects[objectIndex], -1, 0, gMenuPairObjectPaletteIds[row][objectIndex]);
    }
    gMenuPairObjects->mTask = AddTask(0, AdvanceMenuPairObjectSlideIn0, NULL, 0x78);
    LoadMenuPairScreenMap(row);
    StartSoundSeq(0xd);
}

void AdvanceMenuPairObjectSlideIn0(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[0], 0, &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[0].mX || xPos > 0x100) {
        for (objectIndex = 0; objectIndex < 5; objectIndex++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                                gMenuPairObjectPositions[objectIndex].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[0].mX;
    for (objectIndex = 0; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideIn1);
}

void AdvanceMenuPairObjectSlideIn1(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[1], 0, &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[1].mX || xPos > 0x100) {
        for (objectIndex = 1; objectIndex < 5; objectIndex++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                                gMenuPairObjectPositions[objectIndex].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[1].mX;
    for (objectIndex = 1; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideIn2);
}

void AdvanceMenuPairObjectSlideIn2(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[2], 0, &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[2].mX || xPos > 0x100) {
        for (objectIndex = 2; objectIndex < 5; objectIndex++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                                gMenuPairObjectPositions[objectIndex].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[2].mX;
    for (objectIndex = 2; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideIn3);
}

void AdvanceMenuPairObjectSlideIn3(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[3], 0, &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[3].mX || xPos > 0x100) {
        for (objectIndex = 3; objectIndex < 5; objectIndex++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                                gMenuPairObjectPositions[objectIndex].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[3].mX;
    for (objectIndex = 3; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideIn4);
}

void AdvanceMenuPairObjectSlideIn4(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[4], 0, &xPos, &yPos);
    xPos += 8;
    if (xPos < gMenuPairObjectPositions[4].mX || xPos > 0x100) {
        for (objectIndex = 4; objectIndex < 5; objectIndex++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                                gMenuPairObjectPositions[objectIndex].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[4].mX;
    for (objectIndex = 4; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectsSlideInEnd);
}

void AdvanceMenuPairObjectsSlideInEnd(TaskEntry *task, void *arg) {
    RequestTaskRemoval(0, task);
    gMenuPairObjects->mTask = 0;
}

void StartMenuPairObjectsSlideOut(void) {
    gMenuPairObjects->mSlidingOut = 1;
    gMenuPairObjects->mTask = AddTask(0, AdvanceMenuPairObjectSlideOut4, NULL, 0x78);
}

void ChangeMenuPairObjectImages(u32 row) {
    s32 objectIndex;
    for (objectIndex = 0; objectIndex < 5; objectIndex += 2) {
        CopyNceImageToOamEntries(1, gMenuPairObjectImageIds[row][objectIndex],
                                 GetOamRangeEntry(gMenuPairObjects->mObjects[objectIndex], 0));
        SetOamRangePriority(gMenuPairObjects->mObjects[objectIndex], -1, 0);
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, gMenuPairObjectPositions[objectIndex].mX,
                            gMenuPairObjectPositions[objectIndex].mY);
        SetOamRangeMode(gMenuPairObjects->mObjects[objectIndex], -1, 0, gMenuPairObjectPaletteIds[row][objectIndex]);
    }
    LoadMenuPairScreenMap(row);
}

BOOL IsMenuPairObjectsSliding(void) {
    if (gMenuPairObjects->mTask != 0) {
        return 1;
    }
    return 0;
}

void AdvanceMenuPairObjectSlideOut4(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[4], 0, &xPos, &yPos);
    xPos -= 8;
    if (xPos > gMenuPairObjectPositions[3].mX) {
        for (objectIndex = 4; objectIndex < 5; objectIndex++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                                gMenuPairObjectPositions[objectIndex].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[3].mX;
    for (objectIndex = 4; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideOut3);
}

void AdvanceMenuPairObjectSlideOut3(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[3], 0, &xPos, &yPos);
    xPos -= 8;
    if (xPos > gMenuPairObjectPositions[2].mX) {
        for (objectIndex = 3; objectIndex < 5; objectIndex++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                                gMenuPairObjectPositions[objectIndex].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[2].mX;
    for (objectIndex = 3; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideOut2);
}

void AdvanceMenuPairObjectSlideOut2(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[2], 0, &xPos, &yPos);
    xPos -= 8;
    if (xPos > gMenuPairObjectPositions[1].mX) {
        for (objectIndex = 2; objectIndex < 5; objectIndex++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                                gMenuPairObjectPositions[objectIndex].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[1].mX;
    for (objectIndex = 2; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideOut1);
}

void AdvanceMenuPairObjectSlideOut1(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[1], 0, &xPos, &yPos);
    xPos -= 8;
    if (xPos > gMenuPairObjectPositions[0].mX) {
        for (objectIndex = 1; objectIndex < 5; objectIndex++) {
            SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                                gMenuPairObjectPositions[objectIndex].mY);
        }
        return;
    }
    xPos = gMenuPairObjectPositions[0].mX;
    for (objectIndex = 1; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    SetTaskCallback(taskEntry, AdvanceMenuPairObjectSlideOut0);
}

void AdvanceMenuPairObjectSlideOut0(TaskEntry *taskEntry, void *arg) {
    s32 objectIndex;
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gMenuPairObjects->mObjects[0], 0, &xPos, &yPos);
    xPos -= 8;
    for (objectIndex = 0; objectIndex < 5; objectIndex++) {
        SetOamRangePosition(gMenuPairObjects->mObjects[objectIndex], -1, xPos,
                            gMenuPairObjectPositions[objectIndex].mY);
    }
    if (xPos <= 0x1d6 && xPos >= 0x100) {
        RequestTaskRemoval(0, taskEntry);
        for (objectIndex = 0; objectIndex < 5; objectIndex++) {
            DeleteOamRange(gMenuPairObjects->mObjects[objectIndex]);
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
    gMenuPairScreenMap = LoadFile(BuildFilePathWithLanguage((u8 *) gMenuPairScreenMapPaths[pathIndex]), NULL, 4);
    AddTask(1, AdvanceUploadMenuPairScreenMap, NULL, 0x78);
}

void AdvanceUploadMenuPairScreenMap(TaskEntry *task, void *arg) {
    Arm_FlushRange(gMenuPairScreenMap, (0x00000600u));
    TEQSub_Fn25Impl(gMenuPairScreenMap, 0, (0x00000600u));
    DeleteLoadedFile(gMenuPairScreenMap);
    RequestTaskRemoval(1, task);
}
