#include "Main/Unknown/code_020576b8.h"
#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void savd_writeNkfe(EmblemBlockData *blockData, s32 blockIndex) {
    s32 blockOffset = blockIndex * 0xb00;
    u32 *buffer;
    buffer = gSaveCore->mBuffer;
    if (gSaveCore->mBackupEnabled != 0) {
        MI_CpuCopy8(blockData, buffer, 0xb00);
        buffer[0] = 0x45464b4e;
        savc_writeWithBackup(blockOffset + 0x2b00, blockOffset + 0x33a00, buffer, 0xb00, NULL, 0);
    }
}

void savd_readNkfe(EmblemBlockData *blockData, s32 blockIndex) {
    s32 blockOffset = blockIndex * 0xb00;
    if (gSaveCore->mBackupEnabled != 0) {
        gSaveCore->mReadTarget = blockData;
        gSaveCore->field5C = -1;
        savc_readWithBackup(blockOffset + 0x2b00, blockOffset + 0x33a00, gSaveCore->mBuffer, 0xb00,
                                 CopyBackupReadToBlock, 0x45464b4e, 0);
    }
}

#pragma thumb off
