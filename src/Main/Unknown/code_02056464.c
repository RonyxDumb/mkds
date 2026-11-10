#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_02152490.h"

#pragma thumb on

void ReadSlotGhostRecord(u32 slotIndex) {
    SlotGhostRecord *ghostRecord;

    ghostRecord = data_0217aa08->mSlotGhostRecords[0];
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
            result = GetGhostLapTime(&data_0217aa08->mCourseGhostRecord->mHead, lapNumber, lapTime);
            break;
        case 1:
            result = GetGhostLapTime(&data_0217aa08->mSlotGhostRecords[0]->mHead, lapNumber, lapTime);
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
            result = GetGhostFinishTime(&data_0217aa08->mCourseGhostRecord->mHead, finishTime);
            break;
        case 1:
            result = GetGhostFinishTime(&data_0217aa08->mSlotGhostRecords[0]->mHead, finishTime);
            break;
        case 2:
            break;
    }
    return result;
}

void FillPlayerRecord(PlayerRecord *a) {
    MI_CpuCopy8(data_0217aa08->mFirstBlock->mPlayerName, a->mName, 0x14);
    if (data_0217aa08->mEmblemRecord->mFilled != 0 && data_0217aa08->mFirstBlock->mUnk_31_3 == 0) {
        a->mHasEmblem = 1;
        MI_CpuCopy8(data_0217aa08->mEmblemRecord->mEmblemData, a->mEmblem, 0x200);
    } else {
        a->mHasEmblem = 0;
        MI_CpuFill8(a->mEmblem, 0, 0x200);
    }
    MI_CpuCopy8(data_0217aa08->mFirstBlock->mFlags, a->mBits, 4);
    a->mRegion = data_021759d0->mRegion;
    a->mUnk_228_4 = data_021759d0->mLanguageIndex;
    a->mElo = data_0217aa08->mFirstBlock->mElo;
    a->mUnk_229 = GetLowestGrandPrixRecordValue();
    if (gBootInfo->mUnk_00 == 2) {
        MI_CpuFill8(&a->mFriendData, 0, 0xc);
    } else {
        DWC_CreateExchangeToken(&data_0217aa08->mFirstBlock->mUserData, &a->mFriendData);
    }
}

#pragma thumb off
