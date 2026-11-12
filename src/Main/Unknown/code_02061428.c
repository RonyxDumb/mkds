#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_0206152c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057800.h"
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
