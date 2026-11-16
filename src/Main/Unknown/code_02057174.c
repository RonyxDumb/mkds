#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/code_02057260.h"
#include "Main/Unknown/code_02057294.h"
#include "Main/Save/GhostBits.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Save/BackupBlocks.h"
#include "Main/Unknown/code_02057ca4.h"
#include "01/code_021956dc.h"

#pragma thumb on

void savd_initSections(u32 copyOwnerName) {
    savd_initNkem();
    savd_initNkgp();
    savd_initNkta();
    savd_initNkmr();
    savd_initGhosts();
    savd_initNkfl();
    savd_initNksy(copyOwnerName);
}

void savd_eraseAllTask(void) {
    savd_writeNkem(gSaveData->mEmblemRecord);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    savd_writeNkgp(gSaveData->mGrandPrixRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    savd_writeNkta(gSaveData->mCourseTimeRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    savd_writeNkmr(gSaveData->mMissionRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    savd_writeNkfl(gSaveData->mBuddyRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    savd_writeNksy(gSaveData->mFirstBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    savd_endOperation();
}

#pragma thumb off
