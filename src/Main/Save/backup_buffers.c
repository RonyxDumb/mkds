#include "Main/Save/backup_buffers.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_first_block_records.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void InitBackupBuffers(void *heap) {
    gBackupBuffers = HeapAlloc(heap, 0x48);
    gBackupBuffers->mFirstBlock = HeapAllocAligned(heap, sizeof(BackupFirstBlock), 0x20);
    gBackupBuffers->mEmblemRecord = HeapAllocAligned(heap, sizeof(EmblemRecord), 0x20);
    gBackupBuffers->mGrandPrixRecordBlock = HeapAllocAligned(heap, sizeof(GrandPrixRecordBlock), 0x20);
    gBackupBuffers->mCourseTimeRecordBlock = HeapAllocAligned(heap, sizeof(CourseTimeRecordBlock), 0x20);
    gBackupBuffers->mMissionRecordBlock = HeapAllocAligned(heap, sizeof(MissionRecordBlock), 0x20);
    gBackupBuffers->mCourseGhostRecord = HeapAllocAligned(heap, sizeof(GhostRecord), 0x20);
    gBackupBuffers->mSlotGhostRecords[0] = HeapAllocAligned(heap, 0x1000, 0x20);
    gBackupBuffers->mSlotGhostRecords[1] = HeapAllocAligned(heap, 0x1000, 0x20);
    gBackupBuffers->mBuddyRecordBlock = HeapAllocAligned(heap, sizeof(BuddyRecordBlock), 0x20);
    gBackupBuffers->mEmblemBlockData = HeapAllocAligned(heap, sizeof(EmblemBlockData), 0x20);
    gBackupBuffers->mReadDestination = NULL;
    ResetBackupFirstBlockAndRecords(1);
    gBackupBuffers->mFailedBlockBits = 0;
    gBackupBuffers->mReadStatus = 0;
    gBackupBuffers->mUnk_44 &= ~1;
    gBackupBuffers->mBusy = 0;
}

#pragma thumb off
