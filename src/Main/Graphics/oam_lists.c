#include "Main/Graphics/oam_lists.h"
#include "thread_scheduler.h"
#include "arena_cache_init.h"
#include "dma_copy_fill_wait.h"

#pragma optimize_for_size on

#pragma thumb on

void OamBuffer_SomeFn_from_thumb(void *mainOam, void *subOam) {
    OamEntryList *mainOamList = mainOam;
    OamEntryList *subOamList = subOam;

    if (mainOamList != NULL) {
        mainOamList->mOamCount = 0;
        mainOamList->mMatrixCount = 0;
        Mem_DmaFill32(3, mainOamList, 0xc0, 0x400);
    }
    if (subOamList != NULL) {
        subOamList->mOamCount = 0;
        subOamList->mMatrixCount = 0;
        Mem_DmaFill32(3, subOamList, 0xc0, 0x400);
    }
}

void OamBuffer_ResetValues16_from_thumb(void *mainOam, void *subOam) {
    OamEntryList *mainOamList = mainOam;
    OamEntryList *subOamList = subOam;

    if (mainOamList != NULL) {
        mainOamList->mOamCount = 0;
        mainOamList->mMatrixCount = 0;
    }
    if (subOamList != NULL) {
        subOamList->mOamCount = 0;
        subOamList->mMatrixCount = 0;
    }
}

// Hides every entry past the used count in both lists.
void OamBuffer_SomeFn2_from_thumb(void *mainOam, void *subOam) {
    OamEntryList *mainOamList = mainOam;
    OamEntryList *subOamList = subOam;
    u16 usedEntryCount;
    s32 hiddenIndex;

    if (mainOamList != NULL) {
        usedEntryCount = mainOamList->mOamCount;
        Arm_FlushRange(mainOamList, 0x400);
        for (hiddenIndex = 0; hiddenIndex < 0x80 - usedEntryCount; hiddenIndex++) {
            mainOamList->mEntries[usedEntryCount + hiddenIndex].mUnk_00 =
                (mainOamList->mEntries[usedEntryCount + hiddenIndex].mUnk_00 & ~OAM_ENTRY_X_MASK) | OAM_ENTRY_HIDDEN_X;
            mainOamList->mEntries[usedEntryCount + hiddenIndex].mYPos = OAM_ENTRY_HIDDEN_Y;
        }
    }
    if (subOamList != NULL) {
        usedEntryCount = subOamList->mOamCount;
        Arm_FlushRange(subOamList, 0x400);
        for (hiddenIndex = 0; hiddenIndex < 0x80 - usedEntryCount; hiddenIndex++) {
            subOamList->mEntries[usedEntryCount + hiddenIndex].mUnk_00 =
                (subOamList->mEntries[usedEntryCount + hiddenIndex].mUnk_00 & ~OAM_ENTRY_X_MASK) | OAM_ENTRY_HIDDEN_X;
            subOamList->mEntries[usedEntryCount + hiddenIndex].mYPos = OAM_ENTRY_HIDDEN_Y;
        }
    }
}

#pragma thumb off
