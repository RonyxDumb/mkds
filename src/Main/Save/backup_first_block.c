#include "Main/Save/backup_first_block.h"
#include "Main/Save/backup_write_copies.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "code_0214d018.h"

#pragma thumb on

void WriteBackupFirstBlock(void *block) {
    u32 *buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        enum { K0 = 0x53444b4d } firstWord;
        enum { K1 = 0x30315653 } secondWord;
        MI_CpuCopy8(block, buffer, 0x100);
        firstWord = K0;
        secondWord = K1;
        buffer[0] = firstWord;
        buffer[1] = secondWord;
        buffer[2] = 0x59534b4e;
        StartBackupWriteTwoCopies(0, 0x30f00, buffer, 0x100, NULL, 1);
    }
}

#pragma thumb off
