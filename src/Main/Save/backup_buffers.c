#include "Main/Save/backup_buffers.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_first_block_records.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void InitializeSaveDataHolder_from_thumb(void *heap) {
    g_SaveDataHolder = Mem_AllocateHeap(heap, sizeof(BackupBuffers));
    g_SaveDataHolder->mFirstBlock = Mem_AllocateHeapAligned(heap, sizeof(BackupFirstBlock), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mEmblemRecord = Mem_AllocateHeapAligned(heap, sizeof(EmblemRecord), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mGrandPrixRecordBlock = Mem_AllocateHeapAligned(heap, sizeof(GrandPrixRecordBlock), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mCourseTimeRecordBlock =
        Mem_AllocateHeapAligned(heap, sizeof(CourseTimeRecordBlock), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mMissionRecordBlock = Mem_AllocateHeapAligned(heap, sizeof(MissionRecordBlock), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mCourseGhostRecord = Mem_AllocateHeapAligned(heap, sizeof(GhostRecord), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mSlotGhostRecords[0] = Mem_AllocateHeapAligned(heap, sizeof(SlotGhostRecord), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mSlotGhostRecords[1] = Mem_AllocateHeapAligned(heap, sizeof(SlotGhostRecord), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mBuddyRecordBlock = Mem_AllocateHeapAligned(heap, sizeof(BuddyRecordBlock), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mEmblemBlockData = Mem_AllocateHeapAligned(heap, sizeof(EmblemBlockData), HEAP_ALIGN_CACHE_LINE);
    g_SaveDataHolder->mReadDestination = NULL;
    ClearAllSaveDataSections_from_thumb(1);
    g_SaveDataHolder->mFailedBlockBits = 0;
    g_SaveDataHolder->mReadStatus = 0;
    g_SaveDataHolder->mUnk_44 &= ~1;
    g_SaveDataHolder->mBusy = 0;
}

#pragma thumb off
