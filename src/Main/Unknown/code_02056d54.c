#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/code_02057294.h"
#include "Main/Save/GhostBits.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Save/BackupBlocks.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "01/code_021956dc.h"

#pragma thumb on

void savd_eraseAllAsync(void) {
    savd_initSections(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        savd_beginOperation();
        bgwkr_enqueueTask(savd_eraseAllTask);
        gBgWkrState->mRunRequested = 1;
    }
}

void savd_loadTask(void) {
    u16 failedBlockBits;

    failedBlockBits = 0;
    gSaveData->mReadStatus = 0;
    savd_readNksy(gSaveData->mFirstBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        if (gSaveCore->mErrorCode == 4) {
            gSaveData->mFailedBlockBits = 0xffff;
            gSaveData->mReadStatus = 4;
            savd_endOperation();
            return;
        }
        failedBlockBits |= 1;
    }
    savd_readNkem(gSaveData->mEmblemRecord);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        failedBlockBits |= 2;
    }
    savd_readNkgp(gSaveData->mGrandPrixRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        failedBlockBits |= 4;
    }
    savd_readNkta(gSaveData->mCourseTimeRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        failedBlockBits |= 8;
    }
    savd_readNkmr(gSaveData->mMissionRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        failedBlockBits |= 0x10;
    }
    savd_readNkfl(gSaveData->mBuddyRecordBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        failedBlockBits |= 0x20;
    }
    if (gSaveData->mReadStatus == 0) {
        if (failedBlockBits != 0) {
            gSaveData->mReadStatus = 3;
        } else {
            gSaveData->mReadStatus = 0;
        }
    }
    gSaveData->mFailedBlockBits = failedBlockBits;
    savd_endOperation();
}

void savd_loadAsync(void) {
    gSaveData->mUnk_44_0 = 1;
    gSaveData->mUnk_3c = 0;
    gSaveData->mFailedBlockBits = 0;
    savd_beginOperation();
    bgwkr_enqueueTask(savd_loadTask);
    gBgWkrState->mRunRequested = 1;
}

void savd_repairErrorsTask(void) {
    if (gSaveData->mFailedBlockBits & 2) {
        savd_initNkem();
        savd_writeNkem(gSaveData->mEmblemRecord);
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gSaveData->mFailedBlockBits & 4) {
        savd_initNkgp();
        savd_writeNkgp(gSaveData->mGrandPrixRecordBlock);
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gSaveData->mFailedBlockBits & 8) {
        savd_initNkta();
        savd_writeNkta(gSaveData->mCourseTimeRecordBlock);
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gSaveData->mFailedBlockBits & 0x10) {
        savd_initNkmr();
        savd_writeNkmr(gSaveData->mMissionRecordBlock);
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gSaveData->mFailedBlockBits & 0x20) {
        savd_initNkfl();
        savd_writeNkfl(gSaveData->mBuddyRecordBlock);
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gSaveData->mFailedBlockBits & 1) {
        savd_initNksy(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2);
        savd_writeNksy(gSaveData->mFirstBlock);
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    gSaveData->mFailedBlockBits = 0;
    savd_endOperation();
}

void savd_repairErrorsAsync(void) {
    savd_beginOperation();
    bgwkr_enqueueTask(savd_repairErrorsTask);
    gBgWkrState->mRunRequested = 1;
}

void savd_setUnlockBit(s32 flagIndex) {
    u8 *flagBytes;

    flagBytes = gSaveData->mFirstBlock->mFlags;
    flagBytes[flagIndex >> 3] |= 1 << (flagIndex & 7);
}

BOOL savd_isBitSet2(s32 bitIndex, u8 *bytes) {
    u32 isSet;

    isSet = 1;
    if (((1 << (bitIndex & 7)) & bytes[bitIndex >> 3]) == 0) {
        isSet = 0;
    }
    return isSet;
}

BOOL savd_isUnlockBitSet(u32 flagIndex) {
    return savd_isBitSet2(flagIndex, gSaveData->mFirstBlock->mFlags);
}

u8 savd_calcKartUnlockLevel(u8 *bytes) {
    u8 result;

    result = 1;
    if (savd_isBitSet2(0x13, bytes)) {
        result = 4;
    } else if (savd_isBitSet2(0x12, bytes)) {
        result = 3;
    } else if (savd_isBitSet2(0x11, bytes)) {
        result = 2;
    }
    return result;
}

u8 savd_getKartUnlockLevel(void) {
    return savd_calcKartUnlockLevel(gSaveData->mFirstBlock->mFlags);
}

void savd_setKartUnlockLevel(u32 value) {
    u8 *flagBytes;

    if (value > 3) {
        flagBytes = gSaveData->mFirstBlock->mFlags;
        flagBytes[2] |= 8;
    }
    if (value > 2) {
        flagBytes = gSaveData->mFirstBlock->mFlags;
        flagBytes[2] |= 4;
    }
    if (value > 1) {
        flagBytes = gSaveData->mFirstBlock->mFlags;
        flagBytes[2] |= 2;
    }
}

#pragma thumb off
