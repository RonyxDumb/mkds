#include "Main/Save/course_ghost_records.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_ghost_head.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Save/ghost_record_file.h"

GhostRecordHead *AllocateStructYE(void *heap) {
    return Mem_AllocateHeap(heap, 0x600u);
}

void TaskFunction_StructYE(void) {
    u8 ghostIndex;
    GhostRecordHead *records;
    GhostRecordHead *record;

    records = g_SaveDataHolder->mReadDestination;
    for (ghostIndex = 0; ghostIndex < 0x20; ghostIndex++) {
        record = records + ghostIndex;
        if (MaybeHasPersonalGhostForCourse_from_thumb(ghostIndex) != 0) {
            ReadBackupGhostRecordHead(1, ghostIndex, record);
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
    g_SaveDataHolder->mReadDestination = NULL;
    ResetSaveDataHolderTaskPendingFlag_from_thumb();
}

void SetStructYE_RunATFunction(void *records) {
    g_SaveDataHolder->mReadDestination = records;
    EnableMKDSSVSomeFlag_from_thumb();
    WorkerInsertTask(TaskFunction_StructYE);
    g_WorkerContext->mRunRequested = 1;
}
