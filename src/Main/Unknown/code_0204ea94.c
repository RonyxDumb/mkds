#include "Main/Unknown/code_0204ea94.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void StopBlockTransferStep(void) {
    gConnectionWork->mStep = 0x2d;
    gConnectionWork->mRequestPending = 1;
    WBT_End();
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_BLOCK_TRANSFER;
    gConnectionWork->mRequestPending = 0;
}

void SetScanGhostInfo(u32 entryIndex, UserGameInfo *gameInfo) {
    gConnectionWork->mScanGhostInfos[entryIndex].mKartIndex = gameInfo->mUnk_0e.mKartIndex;
    gConnectionWork->mScanGhostInfos[entryIndex].mCharacterIndex = gameInfo->mCharacterIndex;
    gConnectionWork->mScanGhostInfos[entryIndex].mCourseId = GetCupCourseIdAtIndex((u8) gameInfo->mCupCourseIndex);
    gConnectionWork->mScanGhostInfos[entryIndex].mMinute = gameInfo->mMinute;
    gConnectionWork->mScanGhostInfos[entryIndex].mSecond = gameInfo->mSecond;
    gConnectionWork->mScanGhostInfos[entryIndex].mMillisecond = gameInfo->mMillisecond;
}

static inline u32 ChildNameGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

BOOL TryGetScanGhostInfo(u8 entryIndex, void *destination, u8 *kartIndex, u8 *characterIndex, u8 *courseId, u8 *minute,
                         u8 *second, u16 *millisecond) {
    if (TryGetScanSlotName(entryIndex, destination) == 0) {
        return FALSE;
    }
    *kartIndex = gConnectionWork->mScanGhostInfos[entryIndex].mKartIndex;
    *characterIndex = gConnectionWork->mScanGhostInfos[entryIndex].mCharacterIndex;
    *courseId = gConnectionWork->mScanGhostInfos[entryIndex].mCourseId;
    *minute = gConnectionWork->mScanGhostInfos[entryIndex].mMinute;
    *second = gConnectionWork->mScanGhostInfos[entryIndex].mSecond;
    *millisecond = gConnectionWork->mScanGhostInfos[entryIndex].mMillisecond;
    return TRUE;
}

BOOL CopySingleChildName(void *destination) {
    BOOL found;
    u8 index;
    u8 childMask;
    u32 childCount;

    found = FALSE;
    if (ChildNameGetConnectionMode() == 1) {
        if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
            childCount = gConnectionWork->mWaitToSendCount;
        } else {
            childCount = gConnectionWork->mChildren.mChildCount;
        }
    } else {
        childCount = 0;
    }
    if (childCount != 1) {
        return FALSE;
    }
    if (ChildNameGetConnectionMode() != 1) {
        return FALSE;
    }
    index = 1;
    childMask = gConnectionWork->mChildren.mChildMask;
    do {
        if ((childMask & (1 << index)) != 0) {
            MI_CpuCopy8(&gConnectionWork->mPlayerRecords[index], destination, 0x14);
            found = TRUE;
            break;
        }
        index = index + 1;
    } while (index < 8);
    return found;
}

void StartSendWordRequest(u16 indexMask, s32 value) {
    s32 valueCopy;

    valueCopy = value;
    gConnectionWork->mStep = 0x2e;
    gConnectionWork->mRequestPending = 1;
    if (WBT_PutUserData(indexMask, &valueCopy, 4, SendWordRequestCallback) == 0) {
        gConnectionWork->mRequestPending = 0;
    }
}

void SendWordRequestCallback(WBTCommand *record) {
    if (record->mCommand == 10) {
        if (record->mEvent == 11) {
            gConnectionWork->mRequestPending = 0;
            return;
        }
        SetRequestErrorCode(8);
    } else {
        SetRequestErrorCode(8);
    }
}

#pragma thumb off
