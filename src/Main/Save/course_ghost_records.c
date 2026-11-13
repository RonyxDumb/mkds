#include "Main/Save/course_ghost_records.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_ghost_head.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Save/ghost_record_file.h"

GhostRecordHead *CreateCourseGhostRecords(void *heap) {
    return HeapAlloc(heap, 0x600u);
}

void ReadCourseGhostRecords(void) {
    u8 ghostIndex;
    GhostRecordHead *records;
    GhostRecordHead *record;

    records = gBackupBuffers->mReadDestination;
    for (ghostIndex = 0; ghostIndex < 0x20; ghostIndex++) {
        record = records + ghostIndex;
        if (IsCourseGhostBitSet(ghostIndex) != 0) {
            ReadBackupGhostRecordHead(1, ghostIndex, record);
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
    gBackupBuffers->mReadDestination = NULL;
    ClearBackupBusy();
}

void StartReadCourseGhostRecords(void *records) {
    gBackupBuffers->mReadDestination = records;
    SetBackupBusy();
    QueueThreadFunction(ReadCourseGhostRecords);
    gThreadFunctionQueue->mRunRequested = 1;
}
