#include "Main/Save/buddy_record_reset.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"

#pragma thumb on
// Sets a buddy record to empty: counts zero, date year 0 month 1 day 1, no name, flags clear.
void StructOI_Initialize_from_thumb(BuddyRecord *record) {
    Mem_CpuFill8(record, 0, 36);
    record->mResultCounts[0][0] = 0;
    record->mResultCounts[0][1] = 0;
    record->mResultCounts[1][0] = 0;
    record->mResultCounts[1][1] = 0;
    record->mResultCounts[2][0] = 0;
    record->mResultCounts[2][1] = 0;
    record->mYear = 0;
    record->mMonth = 1;
    record->mDay = 1;
    Mem_CpuFill8(record->mName, 0, 20);
    record->mFilled = 0;
    record->mNotYetBuddy = 0;
    record->mHasEmblem = 0;
    record->mFlagged = 0;
}
#pragma thumb off
