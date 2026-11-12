#include "Main/Save/backup_ghost_head.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Save/backup_read_copy.h"
#include "Main/Save/backup_write_copies.h"
#include "Main/Save/backup_read_copies.h"
#include "Main/Unknown/code_0214d000.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_020578d0.h"

#pragma thumb on

void WriteBackupCourseGhost(u32 index, const void *record) {
    u32 offset;
    void *buffer;

    offset = index * 0xe00;
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(record, buffer, 0xe00);
        *(u32 *) buffer = 0x47504b4e;
        StartBackupWriteOneCopy(offset + 0xaf00, buffer, 0xe00, 0);
    }
}

void ReadBackupCourseGhost(u8 index, GhostRecord *ghostRecord) {
    u32 offset;
    BackupAccess *backupAccess;
    void *buffer;

    offset = index * 0xe00;
    backupAccess = gBackupAccess;
    buffer = backupAccess->mBuffer;
    if (backupAccess->mBackupEnabled != 0) {
        backupAccess->mReadTarget = ghostRecord;
        StartBackupReadOneCopy(offset + 0xaf00, buffer, 0xe00, CopyBackupReadToBlock, 0x47504b4e);
    }
}

void WriteBackupSlotGhost(s32 index, const void *record) {
    u32 offset;
    void *buffer;

    offset = TO_FIXED12(index);
    buffer = gBackupAccess->mBuffer;
    if (gBackupAccess->mBackupEnabled != 0) {
        MI_CpuCopy8(record, buffer, 0x1000);
        *(u32 *) buffer = 0x47444b4e;
        StartBackupWriteOneCopy(offset + 0x26f00, buffer, 0x1000, 0);
    }
}

void ReadBackupSlotGhost(u32 index, SlotGhostRecord *ghostRecord) {
    u32 offset;
    BackupAccess *backupAccess;
    s32 backupEnabled;

    offset = TO_FIXED12(index);
    backupAccess = gBackupAccess;
    backupEnabled = backupAccess->mBackupEnabled;
    if (backupEnabled != 0) {
        backupAccess->mReadTarget = ghostRecord;
        gBackupAccess->mUnk_6c = index;
        StartBackupReadOneCopy(offset + 0x26f00, gBackupAccess->mBuffer, 0x1000, CopyBackupReadToBlock, 0x47444b4e);
    }
}

#pragma thumb off

#pragma thumb on
void CopyBackupReadToGhostRecordHead(u32 *buffer, u32 length) {
    MI_CpuCopy8(buffer, gBackupAccess->mReadTarget, 48u);
}
#pragma thumb off

#pragma thumb on
void CopyBackupReadToGhostListEntry(u32 *buffer, u32 length) {
    MI_CpuCopy8(buffer, gBackupAccess->mReadTarget, 0x230u);
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

    backupAccess = gBackupAccess;
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
        StartBackupReadOneCopy(recordOffset + (sectionOffset + 0xaf00), buffer, recordSize,
                               CopyBackupReadToGhostRecordHead, magic);
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

    backupAccess = gBackupAccess;
    if (backupAccess->mBackupEnabled != 0) {
        if (isCourseGhost != 0) {
            sectionOffset = 0;
            recordSize = 0xe00;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47504b4e;
            readCallback = CopyBackupReadToGhostRecordHead;
        } else {
            sectionOffset = 0x1c000;
            recordSize = 0x1000;
            recordOffset = index * recordSize;
            buffer = backupAccess->mBuffer;
            magic = 0x47444b4e;
            readCallback = CopyBackupReadToGhostListEntry;
        }
        backupAccess->mReadTarget = ghostRecord;
        StartBackupReadOneCopy(recordOffset + (sectionOffset + 0xaf00), buffer, recordSize, readCallback, magic);
    }
}

#pragma thumb off
