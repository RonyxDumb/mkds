#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/code_02057294.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "01/code_021956dc.h"

#pragma thumb on

void ResetBackupAndStartWrite(void) {
    ResetBackupFirstBlockAndRecords(gBootInfo->mBootType == 2);
    if (gBootInfo->mBootType != 2) {
        SetBackupBusy();
        QueueThreadFunction(WriteBackupFirstBlockAndRecords);
        gThreadFunctionQueue->mRunRequested = 1;
    }
}

void ReadBackupFirstBlockAndRecords(void) {
    u16 failedBlockBits;

    failedBlockBits = 0;
    gBackupBuffers->mReadStatus = 0;
    ReadBackupFirstBlock(gBackupBuffers->mFirstBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        if (gBackupAccess->mErrorCode == 4) {
            gBackupBuffers->mFailedBlockBits = 0xffff;
            gBackupBuffers->mReadStatus = 4;
            ClearBackupBusy();
            return;
        }
        failedBlockBits |= 1;
    }
    ReadBackupEmblemRecord(gBackupBuffers->mEmblemRecord);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 2;
    }
    ReadBackupGrandPrixRecordBlock(gBackupBuffers->mGrandPrixRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 4;
    }
    ReadBackupCourseTimeRecordBlock(gBackupBuffers->mCourseTimeRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 8;
    }
    ReadBackupMissionRecordBlock(gBackupBuffers->mMissionRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 0x10;
    }
    ReadBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 0x20;
    }
    if (gBackupBuffers->mReadStatus == 0) {
        if (failedBlockBits != 0) {
            gBackupBuffers->mReadStatus = 3;
        } else {
            gBackupBuffers->mReadStatus = 0;
        }
    }
    gBackupBuffers->mFailedBlockBits = failedBlockBits;
    ClearBackupBusy();
}

void StartReadBackupFirstBlockAndRecords(void) {
    gBackupBuffers->mUnk_44_0 = 1;
    gBackupBuffers->mUnk_3c = 0;
    gBackupBuffers->mFailedBlockBits = 0;
    SetBackupBusy();
    QueueThreadFunction(ReadBackupFirstBlockAndRecords);
    gThreadFunctionQueue->mRunRequested = 1;
}

void ResetFailedBackupBlocks(void) {
    if (gBackupBuffers->mFailedBlockBits & 2) {
        ClearEmblemRecord();
        WriteBackupEmblemRecord(gBackupBuffers->mEmblemRecord);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & 4) {
        ClearGrandPrixRecordBlock();
        WriteBackupGrandPrixRecordBlock(gBackupBuffers->mGrandPrixRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & 8) {
        ClearCourseTimeRecordBlock();
        WriteBackupCourseTimeRecordBlock(gBackupBuffers->mCourseTimeRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & 0x10) {
        ClearMissionRecordBlock();
        WriteBackupMissionRecordBlock(gBackupBuffers->mMissionRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & 0x20) {
        ClearBuddyRecordBlock();
        WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & 1) {
        ResetBackupFirstBlock(gBootInfo->mBootType == 2);
        WriteBackupFirstBlock(gBackupBuffers->mFirstBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    gBackupBuffers->mFailedBlockBits = 0;
    ClearBackupBusy();
}

void StartResetFailedBackupBlocks(void) {
    SetBackupBusy();
    QueueThreadFunction(ResetFailedBackupBlocks);
    gThreadFunctionQueue->mRunRequested = 1;
}

void SetBackupFlag(s32 flagIndex) {
    u8 *flagBytes;

    flagBytes = gBackupBuffers->mFirstBlock->mFlags;
    flagBytes[flagIndex >> 3] |= 1 << (flagIndex & 7);
}

BOOL IsBitSetInBytes(s32 bitIndex, u8 *bytes) {
    u32 isSet;

    isSet = 1;
    if (((1 << (bitIndex & 7)) & bytes[bitIndex >> 3]) == 0) {
        isSet = 0;
    }
    return isSet;
}

BOOL IsBackupFlagSet(u32 flagIndex) {
    return IsBitSetInBytes(flagIndex, gBackupBuffers->mFirstBlock->mFlags);
}

u8 GetKartAppearLimitFromBits(u8 *bytes) {
    u8 result;

    result = 1;
    if (IsBitSetInBytes(0x13, bytes)) {
        result = 4;
    } else if (IsBitSetInBytes(0x12, bytes)) {
        result = 3;
    } else if (IsBitSetInBytes(0x11, bytes)) {
        result = 2;
    }
    return result;
}

u8 GetKartAppearLimit(void) {
    return GetKartAppearLimitFromBits(gBackupBuffers->mFirstBlock->mFlags);
}

void RaiseKartAppearLimit(u32 value) {
    u8 *flagBytes;

    if (value > 3) {
        flagBytes = gBackupBuffers->mFirstBlock->mFlags;
        flagBytes[2] |= 8;
    }
    if (value > 2) {
        flagBytes = gBackupBuffers->mFirstBlock->mFlags;
        flagBytes[2] |= 4;
    }
    if (value > 1) {
        flagBytes = gBackupBuffers->mFirstBlock->mFlags;
        flagBytes[2] |= 2;
    }
}

#pragma thumb off
