#include "Main/Unknown/code_02057524.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void InitBackupBuffers(void *heap) {
    gBackupBuffers = HeapAlloc(heap, 0x48);
    gBackupBuffers->mFirstBlock = HeapAllocAligned(heap, 0x100, 0x20);
    gBackupBuffers->mEmblemRecord = HeapAllocAligned(heap, 0x300, 0x20);
    gBackupBuffers->mGrandPrixRecordBlock = HeapAllocAligned(heap, 0x400, 0x20);
    gBackupBuffers->mCourseTimeRecordBlock = HeapAllocAligned(heap, 0x1600, 0x20);
    gBackupBuffers->mMissionRecordBlock = HeapAllocAligned(heap, 0x100, 0x20);
    gBackupBuffers->mCourseGhostRecord = HeapAllocAligned(heap, 0xe00, 0x20);
    gBackupBuffers->mSlotGhostRecords[0] = HeapAllocAligned(heap, 0x1000, 0x20);
    gBackupBuffers->mSlotGhostRecords[1] = HeapAllocAligned(heap, 0x1000, 0x20);
    gBackupBuffers->mBuddyRecordBlock = HeapAllocAligned(heap, 0xc00, 0x20);
    gBackupBuffers->mEmblemBlockData = HeapAllocAligned(heap, 0xb00, 0x20);
    gBackupBuffers->mReadDestination = NULL;
    ResetBackupFirstBlockAndRecords(1);
    gBackupBuffers->mFailedBlockBits = 0;
    gBackupBuffers->mReadStatus = 0;
    gBackupBuffers->mUnk_44 &= ~1;
    gBackupBuffers->mBusy = 0;
}

#pragma thumb off
