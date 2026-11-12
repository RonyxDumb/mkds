#include "Main/Save/backup_emblem_block.h"
#include "Main/Save/backup_write_copies.h"
#include "Main/Save/backup_read_copies.h"
#include "Main/Save/backup_read_copy.h"
#include "01/Menu/record_time_attack.h"
#include "code_0214d018.h"

#pragma thumb on

void WriteBackupEmblemBlock(EmblemBlockData *blockData, s32 blockIndex) {
    s32 blockOffset = blockIndex * 0xb00;
    u32 *buffer;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(blockData, buffer, 0xb00);
        buffer[0] = 0x45464b4e;
        StartBackupWriteTwoCopies(blockOffset + 0x2b00, blockOffset + 0x33a00, buffer, 0xb00, NULL, 0);
    }
}

void ReadBackupEmblemBlock(EmblemBlockData *blockData, s32 blockIndex) {
    s32 blockOffset = blockIndex * 0xb00;
    if (gBackupAccess->mBackupEnabled != 0) {
        gBackupAccess->mReadTarget = blockData;
        gBackupAccess->mUnk_5c = -1;
        StartBackupReadTwoCopies(blockOffset + 0x2b00, blockOffset + 0x33a00, gBackupAccess->mBuffer, 0xb00,
                                 CopyBackupReadToBlock, 0x45464b4e, 0);
    }
}

#pragma thumb off
