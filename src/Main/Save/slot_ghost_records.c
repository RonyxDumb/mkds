#include "Main/Save/slot_ghost_records.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_ghost_head.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

GhostListEntry *AllocateFX(void *heap) {
    return Mem_AllocateHeap(heap, 0x15e0u);
}

void Task_StructFXRelated(void) {
    u8 slotIndex;
    GhostListEntry *records;
    GhostRecordHead *record;

    records = g_SaveDataHolder->mReadDestination;
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        record = &records[slotIndex].mHead;
        if (IsSlotGhostBitSet(slotIndex) != 0) {
            ReadBackupGhostListEntry(0, slotIndex, record);
            if (g_SaveDataIoManager->mBackupEnabled != 0) {
                j_WaitForPendingCardOperation();
            }
            if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
                record->mFilled = 0;
            }
        } else {
            record->mFilled = 0;
        }
    }
    ResetSaveDataHolderTaskPendingFlag_from_thumb();
    g_SaveDataHolder->mReadDestination = NULL;
}

void RunSomeATFunction(void *records) {
    g_SaveDataHolder->mReadDestination = records;
    EnableMKDSSVSomeFlag_from_thumb();
    WorkerInsertTask(Task_StructFXRelated);
    g_WorkerContext->mRunRequested = 1;
}
