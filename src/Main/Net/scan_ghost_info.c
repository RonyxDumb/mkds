#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/wireless_block_requests.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"

#pragma thumb on

void EndWbtStep(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_STOPPING_BLOCK_TRANSFER;
    g_GlobalZE->mRequestPending = 1;
    WBT_End();
    g_GlobalZE->mFlags &= ~CONNECTION_FLAG_BLOCK_TRANSFER;
    g_GlobalZE->mRequestPending = 0;
}

void SetScanGhostInfo(u32 entryIndex, UserGameInfo *gameInfo) {
    g_GlobalZE->mScanGhostInfos[entryIndex].mKartIndex = gameInfo->mGameInfoPart.mKartIndex;
    g_GlobalZE->mScanGhostInfos[entryIndex].mCharacterIndex = gameInfo->mCharacterIndex;
    g_GlobalZE->mScanGhostInfos[entryIndex].mCourseId = GetSomeInternalCourseId(gameInfo->mCupCourseIndex);
    g_GlobalZE->mScanGhostInfos[entryIndex].mMinute = gameInfo->mMinute;
    g_GlobalZE->mScanGhostInfos[entryIndex].mSecond = gameInfo->mSecond;
    g_GlobalZE->mScanGhostInfos[entryIndex].mMillisecond = gameInfo->mMillisecond;
}

static inline u32 ChildNameGetConnectionMode(void) {
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

BOOL TryGetScanGhostInfo(u8 entryIndex, void *destination, u8 *kartIndex, u8 *characterIndex, u8 *courseId, u8 *minute,
                         u8 *second, u16 *millisecond) {
    if (TryGetScanSlotName(entryIndex, destination) == 0) {
        return FALSE;
    }
    *kartIndex = g_GlobalZE->mScanGhostInfos[entryIndex].mKartIndex;
    *characterIndex = g_GlobalZE->mScanGhostInfos[entryIndex].mCharacterIndex;
    *courseId = g_GlobalZE->mScanGhostInfos[entryIndex].mCourseId;
    *minute = g_GlobalZE->mScanGhostInfos[entryIndex].mMinute;
    *second = g_GlobalZE->mScanGhostInfos[entryIndex].mSecond;
    *millisecond = g_GlobalZE->mScanGhostInfos[entryIndex].mMillisecond;
    return TRUE;
}

BOOL CopySingleChildName(void *destination) {
    BOOL found;
    u8 index;
    u8 childMask;
    u32 childCount;

    found = FALSE;
    if (ChildNameGetConnectionMode() == CONNECTION_MODE_PARENT) {
        if ((g_GlobalZE->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
            childCount = g_GlobalZE->mWaitToSendCount;
        } else {
            childCount = g_GlobalZE->mChildren.mChildCount;
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
    childMask = g_GlobalZE->mChildren.mChildMask;
    do {
        if (BIT_IS_SET(childMask, index)) {
            Mem_CpuCopy8(&g_GlobalZE->mPlayerRecords[index], destination, PLAYER_NAME_BYTES);
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
    g_GlobalZE->mStep = CONNECTION_STEP_SEND_WORD_REQUEST;
    g_GlobalZE->mRequestPending = 1;
    if (WBT_PutUserData(indexMask, &valueCopy, 4, SendWordRequestCallback) == 0) {
        g_GlobalZE->mRequestPending = 0;
    }
}

void SendWordRequestCallback(WBTCommand *record) {
    if (record->mCommand == XFER_COMMAND_SEND_CUSTOM) {
        if (record->mEvent == XFER_EVENT_CUSTOM_ENDED) {
            g_GlobalZE->mRequestPending = 0;
            return;
        }
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    } else {
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    }
}

#pragma thumb off
