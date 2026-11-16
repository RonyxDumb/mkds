#include "Main/Save/GhostTimes.h"
#include "Main/Save/GhostBits.h"
#include "Main/Save/BackupGhosts.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Save/BackupBlocks.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_02152490.h"

#pragma thumb on

void savd_loadDownloadGhost(u32 slotIndex) {
    GhostRecord *ghostRecord;

    ghostRecord = gSaveData->mGhostRecords[1];
    if (savd_isDownloadGhostAvailable(slotIndex) == 0) {
        ghostRecord->mFilled = 0;
    } else {
        savd_readNkdg(slotIndex, ghostRecord);
    }
}

s32 savd_getGhostLapTimeDirect(GhostRecord *ghostRecord, s32 lapNumber, MinuteSecondMillisecondTime *lapTime) {
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

BOOL savd_getGhostTimeDirect(GhostRecord *ghostRecord, MinuteSecondMillisecondTime *finishTime) {
    if (ghostRecord->mFilled == 0) {
        return FALSE;
    }
    finishTime->mMinute = ghostRecord->mMinute;
    finishTime->mSecond = ghostRecord->mSecond;
    finishTime->mMillisecond = ghostRecord->mMillisecond;
    return TRUE;
}

s32 savd_getGhostLapTime(s32 ghostRecordIndex, s32 lapNumber, MinuteSecondMillisecondTime *lapTime) {
    s32 result;

    result = 0;
    switch (ghostRecordIndex) {
        case 0:
            result = savd_getGhostLapTimeDirect(gSaveData->mGhostRecords[0], lapNumber, lapTime);
            break;
        case 1:
            result = savd_getGhostLapTimeDirect(gSaveData->mGhostRecords[1], lapNumber, lapTime);
            break;
        case 2:
            break;
    }
    return result;
}

s32 savd_getGhostTime(s32 ghostRecordIndex, MinuteSecondMillisecondTime *finishTime) {
    s32 result;

    result = 0;
    switch (ghostRecordIndex) {
        case 0:
            result = savd_getGhostTimeDirect(gSaveData->mGhostRecords[0], finishTime);
            break;
        case 1:
            result = savd_getGhostTimeDirect(gSaveData->mGhostRecords[1], finishTime);
            break;
        case 2:
            break;
    }
    return result;
}

void FillPlayerRecord(Unk0217aa00_45c *a) {
    MI_CpuCopy8(gSaveData->mFirstBlock->mPlayerName, a->mUnk_000, 0x14);
    if (gSaveData->mEmblemRecord->mFilled != 0 && gSaveData->mFirstBlock->mUnk_31_3 == 0) {
        a->mUnk_214 = 1;
        MI_CpuCopy8(gSaveData->mEmblemRecord->mEmblemData, &a->mUnk_014, 0x200);
    } else {
        a->mUnk_214 = 0;
        MI_CpuFill8(&a->mUnk_014, 0, 0x200);
    }
    MI_CpuCopy8(gSaveData->mFirstBlock->mFlags, a->mBits, 4);
    a->mUnk_228_0 = gSystemData->mUnk_00;
    a->mUnk_228_4 = gSystemData->mLanguageIndex;
    a->mUnk_216 = gSaveData->mFirstBlock->mElo;
    a->mUnk_229 = func_02056208();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        MI_CpuFill8(&a->mUnk_218, 0, 0xc);
    } else {
        DWC_CreateExchangeToken((DWCAccUserData *) gSaveData->mFirstBlock->mUserData,
                                (DWCAccFriendData *) &a->mUnk_218);
    }
}

#pragma thumb off
