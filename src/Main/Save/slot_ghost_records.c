#include "Main/Save/slot_ghost_records.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_ghost_head.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

GhostListEntry *CreateSlotGhostRecords(void *heap) {
    return HeapAlloc(heap, 0x15e0u);
}

void ReadSlotGhostRecords(void) {
    u8 slotIndex;
    GhostListEntry *records;
    GhostRecordHead *record;

    records = gBackupBuffers->mReadDestination;
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        record = &records[slotIndex].mHead;
        if (IsSlotGhostBitSet(slotIndex) != 0) {
            ReadBackupGhostListEntry(0, slotIndex, record);
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
            if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
                record->mFilled = 0;
            }
        } else {
            record->mFilled = 0;
        }
    }
    ClearBackupBusy();
    gBackupBuffers->mReadDestination = NULL;
}

void StartReadSlotGhostRecords(void *records) {
    gBackupBuffers->mReadDestination = records;
    SetBackupBusy();
    QueueThreadFunction(ReadSlotGhostRecords);
    gThreadFunctionQueue->mRunRequested = 1;
}
