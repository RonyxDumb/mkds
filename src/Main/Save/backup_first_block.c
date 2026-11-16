#include "Main/Save/backup_first_block.h"
#include "Main/Save/backup_write_copies.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "cpu_copy_fill.h"

#pragma thumb on

void WriteSaveDataSection_Header_from_thumb(BackupFirstBlock *block) {
    u32 *buffer = g_SaveDataIoManager->mBuffer;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        enum { BACKUP_MAGIC_MKDS = 0x53444b4d } firstWord;
        enum { BACKUP_MAGIC_SV10 = 0x30315653 } secondWord;
        Mem_CpuCopy8(block, buffer, sizeof(BackupFirstBlock));
        firstWord = BACKUP_MAGIC_MKDS;
        secondWord = BACKUP_MAGIC_SV10;
        buffer[0] = firstWord;
        buffer[1] = secondWord;
        buffer[2] = 0x59534b4e;
        SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(0, 0x30f00, buffer, 0x100, NULL, 1);
    }
}

#pragma thumb off
