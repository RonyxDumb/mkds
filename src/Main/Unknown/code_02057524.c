#include "Main/Unknown/code_02057524.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void savd_init(void *heap) {
    gSaveData = heap_alloc(heap, 0x48);
    gSaveData->mFirstBlock = heap_allocEx(heap, 0x100, 0x20);
    gSaveData->mEmblemRecord = heap_allocEx(heap, 0x300, 0x20);
    gSaveData->mGrandPrixRecordBlock = heap_allocEx(heap, 0x400, 0x20);
    gSaveData->mCourseTimeRecordBlock = heap_allocEx(heap, 0x1600, 0x20);
    gSaveData->mMissionRecordBlock = heap_allocEx(heap, 0x100, 0x20);
    gSaveData->mGhostRecords[0] = heap_allocEx(heap, 0xe00, 0x20);
    gSaveData->mGhostRecords[1] = heap_allocEx(heap, 0x1000, 0x20);
    gSaveData->mGhostRecords[2] = heap_allocEx(heap, 0x1000, 0x20);
    gSaveData->mBuddyRecordBlock = heap_allocEx(heap, 0xc00, 0x20);
    gSaveData->mEmblemBlockData = heap_allocEx(heap, 0xb00, 0x20);
    gSaveData->mReadDestination = NULL;
    savd_initSections(1);
    gSaveData->mFailedBlockBits = 0;
    gSaveData->mReadStatus = 0;
    gSaveData->field44 &= ~1;
    gSaveData->mBusy = 0;
}

#pragma thumb off
