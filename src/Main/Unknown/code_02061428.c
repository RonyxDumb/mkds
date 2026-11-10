#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057800.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/unk_0217a000.h" // GhostListEntry

void ReadSlotGhostRecords(void) {
    u8 i;
    GhostListEntry *records;
    GhostRecordHead *record;

    records = data_0217aa08->mReadDestination;
    for (i = 0; i < 10; i++) {
        record = &records[i].mHead;
        if (IsSlotGhostBitSet(i) != 0) {
            func_02057800(0, i, record);
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
    data_0217aa08->mReadDestination = NULL;
}

void StartReadSlotGhostRecords(void *records) {
    data_0217aa08->mReadDestination = records;
    SetBackupBusy();
    QueueThreadFunction(ReadSlotGhostRecords);
    gThreadFunctionQueue->mRunRequested = 1;
}
