#include "00/code_0219cb00.h"
#include "00/code_0219d934.h"
#include "00/code_0219d128.h"

#pragma opt_propagation off

void BuddySyncStatsSaveCallback(u32 localId, u32 profileId, s32 type, u32 index, s32 success, u32 modified,
                                u32 instance) {
    u32 flag;
    flag = instance;
    RemovePendingStatsRequest();
    if (flag == 0x80000001) {
        if (success != 0) {
            if (gWiFiBuddySync->mState == 1) {
                gWiFiBuddySync->mCompletedParts++;
            } else {
                flag = 0;
            }
        } else {
            ReportBuddySyncError(6, -72220);
        }
    }
    if ((flag & 0x80000000) == 0) {
        if (success != 0) {
            if (gWiFiBuddySync->mUnk_4c != NULL) {
                gWiFiBuddySync->mUnk_4c(1, (u32) (type - 2) <= 1 ? 1 : 0, instance);
            }
        } else {
            ReportBuddySyncError(6, -72220);
            if (gWiFiBuddySync->mUnk_4c != NULL) {
                gWiFiBuddySync->mUnk_4c(0, 0, instance);
            }
        }
    }
}

// Counts one more stats request in flight (mPendingStatsRequestCount++); reports error (0xb, -70009) instead when the
// count would wrap. Called for each request sent (code_0219cc00.c:155, code_0219d128.c:139).
void AddPendingStatsRequest(void) {
    WiFiBuddySync *wiFiBuddySync = gWiFiBuddySync;
    if (wiFiBuddySync->mPendingStatsRequestCount == -1) {
        ReportBuddySyncError(0xb, -70009);
        return;
    }
    wiFiBuddySync->mPendingStatsRequestCount++;
}

// Counts one stats request less (mPendingStatsRequestCount--); reports error (0xb, -70009) instead when it is already
// 0. Called first in each stats reply handler (code_0219cb00.c:10, code_0219cc00.c:144).
void RemovePendingStatsRequest(void) {
    WiFiBuddySync *wiFiBuddySync = gWiFiBuddySync;
    if (wiFiBuddySync->mPendingStatsRequestCount == 0) {
        ReportBuddySyncError(0xb, -70009);
        return;
    }
    wiFiBuddySync->mPendingStatsRequestCount--;
}
