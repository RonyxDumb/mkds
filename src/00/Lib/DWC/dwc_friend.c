#include "00/Lib/DWC/dwc_friend.h"
#include "00/Lib/DWC/code_0219cfc0.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/code_0219c3e4.h"
#include "00/Lib/DWC/code_0219c954.h"
#include "00/Lib/DWC/code_021a3264.h"
#include "code_0213a460.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "dwc_account.h"

u8 DWC_GetFriendStatus(void *friendData, char *statusString) {
    return DWC_GetFriendStatusSC(friendData, NULL, NULL, statusString);
}

u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString) {
    char valueText[4];
    GpBuddyStatus status;
    if (DWCi_GetFriendBuddyStatus(friendData, &status) != 0) {
        if (status.mStatus == DWC_STATUS_MATCH_SC_SV) {
            if (maxEntry != NULL) {
                if (DWC_GetCommonValueString("SCM", valueText, status.mStatusString, 0x2f) > 0) {
                    *maxEntry = strtoul(valueText, NULL, 10);
                } else {
                    *maxEntry = 0;
                }
            }
            if (numEntry != NULL) {
                if (DWC_GetCommonValueString("SCN", valueText, status.mStatusString, 0x2f) > 0) {
                    *numEntry = strtoul(valueText, NULL, 10);
                } else {
                    *numEntry = 0;
                }
            }
        } else {
            if (maxEntry != NULL) {
                *maxEntry = 0;
            }
            if (numEntry != NULL) {
                *numEntry = 0;
            }
        }
        if (statusString != NULL) {
            strcpy(statusString, status.mLocationString);
        }
        return status.mStatus;
    }
    if (maxEntry != NULL) {
        *maxEntry = 0;
    }
    if (numEntry != NULL) {
        *numEntry = 0;
    }
    return 0;
}

s32 DWC_GetNumFriend(void *friendList, s32 friendListLength) {
    s32 count;
    s32 index;
    DWCAccFriendData *entry;
    count = 0;
    entry = friendList;
    if (friendList == NULL) {
        return 0;
    }
    for (index = 0; index < friendListLength; index++) {
        if (IsFriendDataTypeNonZeroWrapper(entry) != 0) {
            count++;
        }
        entry++;
    }
    return count;
}

// Deletes the GP buddy of the entry (if GP lists it) and zeroes the 12-byte entry; the argument is the save data's
// entry, not the sync's list.
void DWC_DeleteBuddyFriendData(void *friendData) {
    s32 profileId;
    if (gWiFiBuddySync != NULL && DWCi_CheckLogin() != 0 && DWCi_GetUserData() != NULL) {
        profileId = DWC_GetGsProfileId(DWCi_GetUserData(), friendData);
        if (profileId != 0 && profileId != -1 && GpIsBuddy(gWiFiBuddySync->mGpConnection, profileId) != 0) {
            GpDeleteBuddy(gWiFiBuddySync->mGpConnection, profileId);
        }
    }
    MI_CpuFill8(friendData, 0, 12);
}
