#include "00/Lib/DWC/code_0219cb00.h"
#include "00/code_0219d934.h"
#include "00/Lib/DWC/code_0219d128.h"

#pragma opt_propagation off

void BuddySyncStatsSaveCallback(u32 localId, u32 profileId, s32 type, u32 index, s32 success, u32 modified,
                                u32 instance) {
    u32 flag;
    flag = instance;
    DWCi_SubPersCallbackLevel();
    if (flag == 0x80000001) {
        if (success != 0) {
            if (gWiFiBuddySync->mState == BUDDY_SYNC_STATE_UPDATING) {
                gWiFiBuddySync->mCompletedParts++;
            } else {
                flag = 0;
            }
        } else {
            DWCi_StopFriendProcess(6, -72220);
        }
    }
    if ((flag & 0x80000000) == 0) {
        if (success != 0) {
            if (gWiFiBuddySync->mSaveCallback != NULL) {
                gWiFiBuddySync->mSaveCallback(1, (u32) (type - 2) <= 1 ? 1 : 0, instance);
            }
        } else {
            DWCi_StopFriendProcess(6, -72220);
            if (gWiFiBuddySync->mSaveCallback != NULL) {
                gWiFiBuddySync->mSaveCallback(0, 0, instance);
            }
        }
    }
}

// Counts one more stats request in flight (mPendingStatsRequestCount++); reports error (0xb, -70009) instead when the
// count would wrap. Called for each request sent.
void DWCi_AddPersCallbackLevel(void) {
    WiFiBuddySync *wiFiBuddySync = gWiFiBuddySync;
    if (wiFiBuddySync->mPendingStatsRequestCount == -1) {
        DWCi_StopFriendProcess(0xb, -70009);
        return;
    }
    wiFiBuddySync->mPendingStatsRequestCount++;
}

// Counts one stats request less (mPendingStatsRequestCount--); reports error (0xb, -70009) instead when it is already
// 0. Called first in each stats reply handler.
void DWCi_SubPersCallbackLevel(void) {
    WiFiBuddySync *wiFiBuddySync = gWiFiBuddySync;
    if (wiFiBuddySync->mPendingStatsRequestCount == 0) {
        DWCi_StopFriendProcess(0xb, -70009);
        return;
    }
    wiFiBuddySync->mPendingStatsRequestCount--;
}
