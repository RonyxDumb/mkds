#include "Main/Save/backup_buddy_record_block.h"
#include "Main/Save/backup_write_copies.h"
#include "Main/Save/backup_read_copies.h"
#include "Main/Save/backup_read_copy.h"
#include "01/Menu/record_time_attack.h"
#include "code_0214d018.h"

#pragma thumb on

void WriteBackupBuddyRecordBlock(void *block) {
    u32 *buffer;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0xc00);
        *buffer = 0x4c464b4e;
        StartBackupWriteTwoCopies(0x1f00, 0x32e00, buffer, 0xc00, NULL, 0);
    }
}

void ReadBackupBuddyRecordBlock(void *block) {
    if (gBackupAccess->mBackupEnabled != 0) {
        gBackupAccess->mReadTarget = block;
        gBackupAccess->mUnk_5c = -1;
        StartBackupReadTwoCopies(0x1f00, 0x32e00, gBackupAccess->mBuffer, 0xc00, CopyBackupReadToBlock, 0x4c464b4e, 0);
    }
}

#pragma thumb off
