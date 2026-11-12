#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_020566a8.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_02152490.h"

#pragma thumb on

void WriteSlotGhostRecord(u32 index, SlotGhostRecord *source) {
    int slotBit;
    SlotGhostRecord *destination;
    destination = gBackupBuffers->mSlotGhostRecords[0];
    source->mHead.mUnk_08 = source->mHead.mUnk_08 & 0xfffffffe | 1;
    MI_CpuCopy8(source, destination, (0x00001000u));
    WriteBackupSlotGhost(index, destination);
    slotBit = IsSlotGhostBitSet(index);
    if (slotBit == 0) {
        SetBitArrayBit(index, gBackupBuffers->mFirstBlock->mSlotGhostBits, 2);
        StartWriteBackupFirstBlock();
    }
}

#pragma thumb off

#pragma thumb on

void ReadSlotGhostRecord(u32 slotIndex) {
    SlotGhostRecord *ghostRecord;

    ghostRecord = gBackupBuffers->mSlotGhostRecords[0];
    if (IsSlotGhostBitSet(slotIndex) == 0) {
        ghostRecord->mHead.mFilled = 0;
    } else {
        ReadBackupSlotGhost(slotIndex, ghostRecord);
    }
}

s32 GetGhostLapTime(GhostRecordHead *ghostRecord, s32 lapNumber, MinuteSecondMillisecondTime *lapTime) {
    u8 byteOffset;
    u32 packedTime;

    byteOffset = (lapNumber - 1) * 3;
    packedTime = 0;
    if (ghostRecord->mFilled == 0) {
        return packedTime;
    }
    packedTime |= ghostRecord->mLapTimes[byteOffset] << 16;
    packedTime |= ghostRecord->mLapTimes[byteOffset + 1] << 8;
    packedTime |= ghostRecord->mLapTimes[byteOffset + 2];
    lapTime->mMinute = (packedTime >> 17) & 0x7f;
    lapTime->mSecond = (packedTime >> 10) & 0x7f;
    lapTime->mMillisecond = packedTime & 0x3ff;
    return 1;
}

BOOL GetGhostFinishTime(GhostRecordHead *ghostRecord, MinuteSecondMillisecondTime *finishTime) {
    if (ghostRecord->mFilled == 0) {
        return FALSE;
    }
    finishTime->mMinute = ghostRecord->mMinute;
    finishTime->mSecond = ghostRecord->mSecond;
    finishTime->mMillisecond = ghostRecord->mMillisecond;
    return TRUE;
}

s32 GetGhostLapTimeByIndex(s32 ghostRecordIndex, s32 lapNumber, MinuteSecondMillisecondTime *lapTime) {
    s32 result;

    result = 0;
    switch (ghostRecordIndex) {
        case 0:
            result = GetGhostLapTime(&gBackupBuffers->mCourseGhostRecord->mHead, lapNumber, lapTime);
            break;
        case 1:
            result = GetGhostLapTime(&gBackupBuffers->mSlotGhostRecords[0]->mHead, lapNumber, lapTime);
            break;
        case 2:
            break;
    }
    return result;
}

s32 GetGhostFinishTimeByIndex(s32 ghostRecordIndex, MinuteSecondMillisecondTime *finishTime) {
    s32 result;

    result = 0;
    switch (ghostRecordIndex) {
        case 0:
            result = GetGhostFinishTime(&gBackupBuffers->mCourseGhostRecord->mHead, finishTime);
            break;
        case 1:
            result = GetGhostFinishTime(&gBackupBuffers->mSlotGhostRecords[0]->mHead, finishTime);
            break;
        case 2:
            break;
    }
    return result;
}

void FillPlayerRecord(PlayerRecord *a) {
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mPlayerName, a->mName, 0x14);
    if (gBackupBuffers->mEmblemRecord->mFilled != 0 && gBackupBuffers->mFirstBlock->mEmblemOff == 0) {
        a->mHasEmblem = 1;
        MI_CpuCopy8(gBackupBuffers->mEmblemRecord->mEmblemData, a->mEmblem, 0x200);
    } else {
        a->mHasEmblem = 0;
        MI_CpuFill8(a->mEmblem, 0, 0x200);
    }
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mFlags, a->mBits, 4);
    a->mRegion = gStartupWork->mRegion;
    a->mLanguageIndex = gStartupWork->mLanguageIndex;
    a->mElo = gBackupBuffers->mFirstBlock->mElo;
    a->mLowestGrandPrixRecordValue = GetLowestGrandPrixRecordValue();
    if (gBootInfo->mBootType == 2) {
        MI_CpuFill8(&a->mFriendData, 0, 0xc);
    } else {
        DWC_CreateExchangeToken(&gBackupBuffers->mFirstBlock->mUserData, &a->mFriendData);
    }
}

#pragma thumb off
