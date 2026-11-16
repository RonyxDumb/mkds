#include "Main/Unknown/code_0202dd9c.h"

#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Ui/KartIcon.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0202e274.h"
#include "Main/Unknown/code_0202e43c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_0206152c.h"
#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02061644.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_021172a8.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_02153bec.h"
#include "Main/Unknown/unk_02162c74.h"
#include "code_0214d018.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025cd0.h"
#include "registers.h"

#pragma thumb on

void ghost_create(void *heap) {
    Unk02125de0Arg arg;
    u8 *displaySettings;
    s32 i;
    u32 courseId;
    u8 *courseRecords;
    s32 cupCourseIndex;
    sGhostSceneState = heap_alloc(heap, 0x8dc);
    MemFillWordsByBlock_inline(sGhostSceneState, 0x8dc);
    sGhostSceneState->mCourseGhostBuffer = heap_allocEx(heap, 0xe00, 0x20);
    sGhostSceneState->mSlotGhostBuffer = heap_allocEx(heap, 0x1000, 0x20);
    displaySettings = dc_createDisplayConfig(heap, ghost_sDisplayConfigBase);
    dc_setBg0Config(displaySettings + 0x28, 1, 0, 0, 0, 0, 1, 0);
    dc_setBg3Config(displaySettings + 0x70, 2, 0, 0, 0, 0xf, 0);
    dc_setDisplayConfig(displaySettings);
    ghost_loadFiles();
    arg.field0 = 1;
    arg.field4 = m2d_getFont(1);
    arg.field8 = 1;
    arg.fieldC = 1;
    arg.field10 = 0;
    arg.field14 = 0;
    arg.field18 = NULL;
    arg.field1C = 1;
    arg.field20 = 1;
    arg.field24 = 0;
    gmenu_unpackData();
    gmenu_init(heap, &arg);
    SetTxtSystemMode(1);
    InitLinkLevelIcons(heap, sGhostSceneState);
    kic_initForGhost(heap);
    for (i = 0; i < 0x20; i++) {
        sGhostSceneState->mCupCourseIndices[i] = -1;
    }
    for (i = 0; i < 10; i++) {
        sGhostSceneState->mSlotIndices[i] = -1;
    }
    sGhostSceneState->mCourseGhostRecords = (u8 *) ghdat_allocPersonalGhostsStruct((u32) heap);
    ghdat_loadPersonalGhostsAsync(sGhostSceneState->mCourseGhostRecords);
    bgwkr_waitForCompletion();
    for (i = 0; i < 0x20; i++) {
        courseId = ghost_getCourseId(i);
        courseRecords = sGhostSceneState->mCourseGhostRecords;
        cupCourseIndex = rconf_getCourseNumber(courseId);
        if (ghdat_getIsGhostValid(courseRecords + cupCourseIndex * 0x30) != FALSE) {
            sGhostSceneState->mCupCourseIndices[sGhostSceneState->mCourseGhostCount] = i;
            sGhostSceneState->mGhostCount++;
            sGhostSceneState->mCourseGhostCount++;
        }
    }
    sGhostSceneState->mSlotGhostRecords = (u8 *) ghdat_allocDownloadGhostsStruct((u32) heap);
    ghdat_loadDownloadGhostsAsync(sGhostSceneState->mSlotGhostRecords);
    bgwkr_waitForCompletion();
    for (i = 0; i < 10; i++) {
        if (ghdat_getIsGhostValid(sGhostSceneState->mSlotGhostRecords + (u8) i * 0x230) != FALSE) {
            sGhostSceneState->mSlotIndices[sGhostSceneState->mSlotGhostCount] = i;
            sGhostSceneState->mGhostCount++;
            sGhostSceneState->mSlotGhostCount++;
        }
    }
    oam_clearResetBuffers(sGhostSceneState, sGhostSceneState->mSubOam);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    switch (gStruct217B488->mGhostSceneInitialCallbacksIndex) {
        case 0:
            sGhostSceneState->mRequestedCallbacksIndex = 0;
            break;
        case 1:
            sGhostSceneState->mRequestedCallbacksIndex = 1;
            break;
    }
    sGhostSceneState->mCurrentCallbacksIndex = sGhostSceneState->mRequestedCallbacksIndex;
    sGhostSceneState->mCurrentCallbacks = sGhostSceneFuncs[sGhostSceneState->mRequestedCallbacksIndex];
    sGhostSceneState->mHeap = heap_createSubExpHeap(heap);
    sGhostSceneState->mCurrentCallbacks->mInit(sGhostSceneState->mHeap, sGhostSceneState, sGhostSceneState->mSubOam);
}

void ghost_render(s32 sceneNumbers) {
    s32 requestedIndex;
    s32 currentIndex;
    s32 nextIndex;
    GhostSceneCallbacks *oldCallbacks;
    requestedIndex = sGhostSceneState->mRequestedCallbacksIndex;
    currentIndex = sGhostSceneState->mCurrentCallbacksIndex;
    if (currentIndex != requestedIndex) {
        oldCallbacks = sGhostSceneState->mCurrentCallbacks;
        sGhostSceneState->mCurrentCallbacks = sGhostSceneFuncs[requestedIndex];
        sGhostSceneState->mCurrentCallbacksIndex = sGhostSceneState->mRequestedCallbacksIndex;
        oldCallbacks->mRelease();
        sGhostSceneState->mCurrentCallbacks->mInit(sGhostSceneState->mHeap, sGhostSceneState, sGhostSceneState->mSubOam);
    } else {
        oam_resetBuffers(sGhostSceneState, sGhostSceneState->mSubOam);
        nextIndex = sGhostSceneState->mCurrentCallbacks->mAdvance(sceneNumbers);
        if (nextIndex != -1) {
            sGhostSceneState->mRequestedCallbacksIndex = nextIndex;
        }
        oam_prepareBuffers(sGhostSceneState, sGhostSceneState->mSubOam);
    }
    gmenu_render();
    AdvanceLinkLevelIcons();
}

void ghost_finish(void) {
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    gmenu_finish();
    ClearLinkLevelIconsPointer();
    kic_free();
    LEDBlink_NoPattern();
}

void ghost_vblank(void) {
    gmenu_vblank();
    sGhostSceneState->mCurrentCallbacks->fieldC();
    oam_applyBuffers(sGhostSceneState, sGhostSceneState->mSubOam);
}

#pragma thumb off

#pragma thumb on

void PrintGhostRecordInfo(SelectCharacter *fileSets, s16 (*labelRows)[4], void *name, s32 characterIndex, s32 kartIndex,
                          s32 courseId, MinuteSecondMillisecondTime *time) {
    u16 timeText[10];
    u16 terminatedName[11];
    CellFileSet *cellFileSet;
    cellFileSet = &fileSets->field38;
    jn_ui_212426C(0, labelRows[0][0], fileSets->field0.mLabelLayout,
                  jn_msg_getMessage(fileSets->field58, mutil2_getCourseNameCommonMsgId(courseId)), fileSets->field0.mCellLayout,
                  fileSets->field0.mCellTable);
    mutil2_timeToString((s16 *) timeText, time->mMinute, time->mSecond, time->mMillisecond);
    jn_ui_2124224(0, labelRows[1][0], fileSets->field0.mLabelLayout, timeText, fileSets->field0.mCellLayout,
                  fileSets->field0.mCellTable, 7);
    MIi_CpuCopy16(name, terminatedName, 0x14);
    terminatedName[10] = 0;
    jn_ui_212426C(0, labelRows[2][0], fileSets->field0.mLabelLayout, terminatedName, fileSets->field0.mCellLayout,
                  fileSets->field0.mCellTable);
    QueueCellCharsAndFirstPalette(characterIndex, cellFileSet->mCells, fileSets->field38.mChars, cellFileSet->mPalette,
                                  cellFileSet->mCellLayout, 0, labelRows[0][3], fileSets->field0.mCells,
                                  fileSets->field0.mCellLayout);
    kic_putIconInLayout(kartIndex, fileSets->field0.mCells, fileSets->field0.mCellLayout, labelRows[1][3],
                  GetCellPaletteIndex(labelRows[1][3], fileSets->field0.mCells, fileSets->field0.mCellLayout), 0);
}

#pragma thumb off

#pragma thumb on

void *GetCourseGhostBuffer(void) {
    return sGhostSceneState->mCourseGhostBuffer;
}

u32 GetSlotGhostBuffer(void) {
    return ((u32) sGhostSceneState->mSlotGhostBuffer);
}

u32 ghost_getTotalGhostCount(void) {
    return (sGhostSceneState->mGhostCount);
}

u32 ghost_getMyGhostCount(void) {
    return (sGhostSceneState->mCourseGhostCount);
}

u32 ghost_getDlGhostCount(void) {
    return (sGhostSceneState->mSlotGhostCount);
}

#pragma thumb off
