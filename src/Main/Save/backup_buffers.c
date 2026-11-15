#include "Main/Save/backup_buffers.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_first_block_records.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void InitBackupBuffers(void *heap) {
    gBackupBuffers = HeapAlloc(heap, sizeof(BackupBuffers));
    gBackupBuffers->mFirstBlock = HeapAllocAligned(heap, sizeof(BackupFirstBlock), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mEmblemRecord = HeapAllocAligned(heap, sizeof(EmblemRecord), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mGrandPrixRecordBlock = HeapAllocAligned(heap, sizeof(GrandPrixRecordBlock), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mCourseTimeRecordBlock =
        HeapAllocAligned(heap, sizeof(CourseTimeRecordBlock), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mMissionRecordBlock = HeapAllocAligned(heap, sizeof(MissionRecordBlock), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mCourseGhostRecord = HeapAllocAligned(heap, sizeof(GhostRecord), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mSlotGhostRecords[0] = HeapAllocAligned(heap, sizeof(SlotGhostRecord), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mSlotGhostRecords[1] = HeapAllocAligned(heap, sizeof(SlotGhostRecord), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mBuddyRecordBlock = HeapAllocAligned(heap, sizeof(BuddyRecordBlock), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mEmblemBlockData = HeapAllocAligned(heap, sizeof(EmblemBlockData), HEAP_ALIGN_CACHE_LINE);
    gBackupBuffers->mReadDestination = NULL;
    ResetBackupFirstBlockAndRecords(1);
    gBackupBuffers->mFailedBlockBits = 0;
    gBackupBuffers->mReadStatus = 0;
    gBackupBuffers->mUnk_44 &= ~1;
    gBackupBuffers->mBusy = 0;
}

#pragma thumb off
