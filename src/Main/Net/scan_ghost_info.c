#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/wbt_requests.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void EndWbtStep(void) {
    gConnectionWork->mStep = CONNECTION_STEP_STOPPING_BLOCK_TRANSFER;
    gConnectionWork->mRequestPending = 1;
    WBT_End();
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_BLOCK_TRANSFER;
    gConnectionWork->mRequestPending = 0;
}

void SetScanGhostInfo(u32 entryIndex, UserGameInfo *gameInfo) {
    gConnectionWork->mScanGhostInfos[entryIndex].mKartIndex = gameInfo->mGameInfoPart.mKartIndex;
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
    if (ChildNameGetConnectionMode() == CONNECTION_MODE_PARENT) {
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
    if (ChildNameGetConnectionMode() != CONNECTION_MODE_PARENT) {
        return FALSE;
    }
    index = 1;
    childMask = gConnectionWork->mChildren.mChildMask;
    do {
        if (BIT_IS_SET(childMask, index)) {
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
    gConnectionWork->mStep = CONNECTION_STEP_SEND_WORD_REQUEST;
    gConnectionWork->mRequestPending = 1;
    if (WBT_PutUserData(indexMask, &valueCopy, 4, SendWordRequestCallback) == 0) {
        gConnectionWork->mRequestPending = 0;
    }
}

void SendWordRequestCallback(WBTCommand *record) {
    if (record->mCommand == XFER_COMMAND_SEND_CUSTOM) {
        if (record->mEvent == XFER_EVENT_CUSTOM_ENDED) {
            gConnectionWork->mRequestPending = 0;
            return;
        }
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    } else {
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    }
}

#pragma thumb off
