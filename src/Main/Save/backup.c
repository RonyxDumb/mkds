#include "Main/Save/backup.h"
#include "Main/Save/backup_write_copies.h"
#include "Main/Save/backup_read_copies.h"
#include "Main/Save/backup_read_copy.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "cpu_copy_fill.h"

#pragma thumb on

void ReadSaveDataSection_Header_from_thumb(void *block) {
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        g_SaveDataIoManager->mReadTarget = block;
        ReadSaveChunkImpl_from_thumb(0, 0x30f00, g_SaveDataIoManager->mBuffer, 0x100, CopyToSXSomePtr_from_thumb, 0x59534b4e, 1);
    }
}

void WriteSaveDataSection_Emblem_from_thumb(EmblemRecord *block) {
    u32 *buffer;
    buffer = g_SaveDataIoManager->mBuffer;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        Mem_CpuCopy8(block, buffer, sizeof(EmblemRecord));
        *buffer = 0x4d454b4e;
        SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(0x100, 0x31000, buffer, 0x300, NULL, 0);
    }
}

void ReadSaveDataSection_Emblem_from_thumb(void *block) {
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        g_SaveDataIoManager->mReadTarget = block;
        ReadSaveChunkImpl_from_thumb(0x100, 0x31000, g_SaveDataIoManager->mBuffer, 0x300, CopyToSXSomePtr_from_thumb, 0x4d454b4e, 0);
    }
}

void WriteSaveDataSection_GrandPrix_from_thumb(GrandPrixRecordBlock *block) {
    u32 *buffer;
    buffer = g_SaveDataIoManager->mBuffer;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        Mem_CpuCopy8(block, buffer, sizeof(GrandPrixRecordBlock));
        *buffer = 0x50474b4e;
        SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(0x400, 0x31300, buffer, 0x400, NULL, 0);
    }
}

void ReadSaveDataSection_GrandPrix_from_thumb(void *block) {
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        g_SaveDataIoManager->mReadTarget = block;
        ReadSaveChunkImpl_from_thumb(0x400, 0x31300, g_SaveDataIoManager->mBuffer, 0x400, CopyToSXSomePtr_from_thumb, 0x50474b4e, 0);
    }
}

void WriteSaveDataSection_TimeTrials_from_thumb(CourseTimeRecordBlock *block) {
    u32 *buffer;
    buffer = g_SaveDataIoManager->mBuffer;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        Mem_CpuCopy8(block, buffer, sizeof(CourseTimeRecordBlock));
        *buffer = 0x41544b4e;
        SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(0x800, 0x31700, buffer, 0x1600, NULL, 0);
    }
}

void ReadSaveDataSection_TimeTrial_from_thumb(void *block) {
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        g_SaveDataIoManager->mReadTarget = block;
        ReadSaveChunkImpl_from_thumb(0x800, 0x31700, g_SaveDataIoManager->mBuffer, 0x1600, CopyToSXSomePtr_from_thumb, 0x41544b4e, 0);
    }
}

void WriteSaveDataSection_MissionRun_from_thumb(MissionRecordBlock *block) {
    u32 *buffer;
    buffer = g_SaveDataIoManager->mBuffer;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        Mem_CpuCopy8(block, buffer, sizeof(MissionRecordBlock));
        *buffer = 0x524d4b4e;
        SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(0x1e00, 0x32d00, buffer, 0x100, NULL, 0);
    }
}

void ReadSaveDataSection_MissionRun_from_thumb(void *block) {
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        g_SaveDataIoManager->mReadTarget = block;
        ReadSaveChunkImpl_from_thumb(0x1e00, 0x32d00, g_SaveDataIoManager->mBuffer, 0x100, CopyToSXSomePtr_from_thumb, 0x524d4b4e, 0);
    }
}

#pragma thumb off
