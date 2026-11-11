#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/code_02057260.h"
#include "Main/Unknown/code_02057294.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/code_02057ca4.h"
#include "01/code_021956dc.h"

#pragma thumb on

void ResetBackupFirstBlockAndRecords(u32 copyOwnerName) {
    ClearEmblemRecord();
    ClearGrandPrixRecordBlock();
    ClearCourseTimeRecordBlock();
    ClearMissionRecordBlock();
    ClearCourseAndFirstSlotGhost();
    ClearBuddyRecordBlock();
    ResetBackupFirstBlock(copyOwnerName);
}

void WriteBackupFirstBlockAndRecords(void) {
    WriteBackupEmblemRecord(gBackupBuffers->mEmblemRecord);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupGrandPrixRecordBlock(gBackupBuffers->mGrandPrixRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupCourseTimeRecordBlock(gBackupBuffers->mCourseTimeRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupMissionRecordBlock(gBackupBuffers->mMissionRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupFirstBlock(gBackupBuffers->mFirstBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    ClearBackupBusy();
}

#pragma thumb off
