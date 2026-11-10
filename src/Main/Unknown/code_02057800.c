#include "Main/Unknown/code_02057800.h"
#include "Main/Unknown/code_020578d0.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "01/code_021956dc.h"

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
