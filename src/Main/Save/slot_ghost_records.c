#include "Main/Save/slot_ghost_records.h"
#include "Main/Unknown/code_0206152c.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_ghost_head.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/unk_0217a000.h"

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
            if (gBackupAccess->mErrorCode != 0) {
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
