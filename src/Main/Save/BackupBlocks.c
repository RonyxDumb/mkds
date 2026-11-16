#include "Main/Save/BackupBlocks.h"
#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void savd_readNksy(void *block) {
    if (gSaveCore->mBackupEnabled != 0) {
        gSaveCore->mReadTarget = block;
        savc_readWithBackup(0, 0x30f00, gSaveCore->mBuffer, 0x100, CopyBackupReadToBlock, 0x59534b4e, 1);
    }
}

void savd_writeNkem(EmblemRecord *block) {
    u32 *buffer;
    buffer = gSaveCore->mBuffer;
    if (gSaveCore->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0x300);
        *buffer = 0x4d454b4e;
        savc_writeWithBackup(0x100, 0x31000, buffer, 0x300, NULL, 0);
    }
}

void savd_readNkem(void *block) {
    if (gSaveCore->mBackupEnabled != 0) {
        gSaveCore->mReadTarget = block;
        savc_readWithBackup(0x100, 0x31000, gSaveCore->mBuffer, 0x300, CopyBackupReadToBlock, 0x4d454b4e, 0);
    }
}

void savd_writeNkgp(GrandPrixRecordBlock *block) {
    u32 *buffer;
    buffer = gSaveCore->mBuffer;
    if (gSaveCore->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0x400);
        *buffer = 0x50474b4e;
        savc_writeWithBackup(0x400, 0x31300, buffer, 0x400, NULL, 0);
    }
}

void savd_readNkgp(void *block) {
    if (gSaveCore->mBackupEnabled != 0) {
        gSaveCore->mReadTarget = block;
        savc_readWithBackup(0x400, 0x31300, gSaveCore->mBuffer, 0x400, CopyBackupReadToBlock, 0x50474b4e, 0);
    }
}

void savd_writeNkta(CourseTimeRecordBlock *block) {
    u32 *buffer;
    buffer = gSaveCore->mBuffer;
    if (gSaveCore->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0x1600);
        *buffer = 0x41544b4e;
        savc_writeWithBackup(0x800, 0x31700, buffer, 0x1600, NULL, 0);
    }
}

void savd_readNkta(void *block) {
    if (gSaveCore->mBackupEnabled != 0) {
        gSaveCore->mReadTarget = block;
        savc_readWithBackup(0x800, 0x31700, gSaveCore->mBuffer, 0x1600, CopyBackupReadToBlock, 0x41544b4e, 0);
    }
}

void savd_writeNkmr(MissionRecordBlock *block) {
    u32 *buffer;
    buffer = gSaveCore->mBuffer;
    if (gSaveCore->mBackupEnabled != 0) {
        MI_CpuCopy8(block, buffer, 0x100);
        *buffer = 0x524d4b4e;
        savc_writeWithBackup(0x1e00, 0x32d00, buffer, 0x100, NULL, 0);
    }
}

void savd_readNkmr(void *block) {
    if (gSaveCore->mBackupEnabled != 0) {
        gSaveCore->mReadTarget = block;
        savc_readWithBackup(0x1e00, 0x32d00, gSaveCore->mBuffer, 0x100, CopyBackupReadToBlock, 0x524d4b4e, 0);
    }
}

#pragma thumb off
