#include "Main/Save/backup_ghost_head.h"
#include "Main/Save/backup_read_copy.h"
#include "Main/Save/backup_write_copies.h"
#include "Main/Save/backup_read_copies.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "cpu_copy_fill.h"

#pragma thumb on

void WriteSaveChunk_NKPG_from_thumb(u32 index, const GhostRecord *record) {
    u32 offset;
    void *buffer;

    offset = index * 0xe00;
    buffer = g_SaveDataIoManager->mBuffer;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        Mem_CpuCopy8(record, buffer, sizeof(GhostRecord));
        *(u32 *) buffer = 0x47504b4e;
        SV_MaybeCompressWriteNoFlagsBC_from_thumb(offset + 0xaf00, buffer, 0xe00, 0);
    }
}

void ReadBackupCourseGhost(u8 index, GhostRecord *ghostRecord) {
    u32 offset;
    BackupAccess *backupAccess;
    void *buffer;

    offset = index * 0xe00;
    backupAccess = g_SaveDataIoManager;
    buffer = backupAccess->mBuffer;
    if (backupAccess->mBackupEnabled != 0) {
        backupAccess->mReadTarget = ghostRecord;
        ReadSaveChunkImpl2_from_thumb(offset + 0xaf00, buffer, 0xe00, CopyToSXSomePtr_from_thumb, 0x47504b4e);
    }
}

void WriteBackupSlotGhost(s32 index, const void *record) {
    u32 offset;
    void *buffer;

    offset = TO_FIXED12(index);
    buffer = g_SaveDataIoManager->mBuffer;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        Mem_CpuCopy8(record, buffer, sizeof(SlotGhostRecord));
        *(u32 *) buffer = 0x47444b4e;
        SV_MaybeCompressWriteNoFlagsBC_from_thumb(offset + 0x26f00, buffer, 0x1000, 0);
    }
}

void ReadBackupSlotGhost(u32 index, SlotGhostRecord *ghostRecord) {
    u32 offset;
    BackupAccess *backupAccess;
    s32 backupEnabled;

    offset = TO_FIXED12(index);
    backupAccess = g_SaveDataIoManager;
    backupEnabled = backupAccess->mBackupEnabled;
    if (backupEnabled != 0) {
        backupAccess->mReadTarget = ghostRecord;
        g_SaveDataIoManager->mSlotGhostIndex = index;
        ReadSaveChunkImpl2_from_thumb(offset + 0x26f00, g_SaveDataIoManager->mBuffer, 0x1000, CopyToSXSomePtr_from_thumb, 0x47444b4e);
    }
}

#pragma thumb off

#pragma thumb on
void CopyToSXSomePtr0x30_from_thumb(u32 *buffer, u32 length) {
    Mem_CpuCopy8(buffer, g_SaveDataIoManager->mReadTarget, 48u);
}
#pragma thumb off

#pragma thumb on
void CopyToSXSomePtr0x230_from_thumb(u32 *buffer, u32 length) {
    Mem_CpuCopy8(buffer, g_SaveDataIoManager->mReadTarget, 0x230u);
}
#pragma thumb off

#pragma thumb on

void ReadBackupGhostRecordHead(u32 isCourseGhost, u32 index, GhostRecordHead *ghostRecord) {
    BackupAccess *backupAccess;
    u32 sectionOffset;
    u32 recordOffset;
    u32 recordSize;
    u32 magic;
    void *buffer;

    backupAccess = g_SaveDataIoManager;
    if (backupAccess->mBackupEnabled != 0) {
        if (isCourseGhost != 0) {
            sectionOffset = 0;
            recordSize = 0xe00;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47504b4e;
        } else {
            sectionOffset = 0x1c000;
            recordSize = 0x1000;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47444b4e;
        }
        backupAccess->mReadTarget = ghostRecord;
        ReadSaveChunkImpl2_from_thumb(recordOffset + (sectionOffset + 0xaf00), buffer, recordSize,
                               CopyToSXSomePtr0x30_from_thumb, magic);
    }
}

// The only caller passes isCourseGhost 0; for 1 the course record head is copied instead.
void ReadBackupGhostListEntry(u32 isCourseGhost, u32 index, GhostRecordHead *ghostRecord) {
    void (*readCallback)(u32 *, u32);
    BackupAccess *backupAccess;
    u32 sectionOffset;
    u32 recordOffset;
    u32 recordSize;
    u32 magic;
    void *buffer;

    backupAccess = g_SaveDataIoManager;
    if (backupAccess->mBackupEnabled != 0) {
        if (isCourseGhost != 0) {
            sectionOffset = 0;
            recordSize = 0xe00;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47504b4e;
            readCallback = CopyToSXSomePtr0x30_from_thumb;
        } else {
            sectionOffset = 0x1c000;
            recordSize = 0x1000;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47444b4e;
            readCallback = CopyToSXSomePtr0x230_from_thumb;
        }
        backupAccess->mReadTarget = ghostRecord;
        ReadSaveChunkImpl2_from_thumb(recordOffset + (sectionOffset + 0xaf00), buffer, recordSize, readCallback, magic);
    }
}

#pragma thumb off
