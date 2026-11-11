#include "00/code_0219d128.h"

#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0219cb00.h"
#include "00/code_0219d000.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c93c.h"
#include "00/code_0219cc00.h"
#include "00/code_0218f15c.h"
#include "code_02139f70.h"
#include "00/code_0219d934.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152468.h"
#include "Main/Unknown/code_02152a1c.h"
#include "code_0214d018.h"
#include "00/code_0219c954.h"
#include "00/code_0219cfc0.h"
#include "00/code_02197000.h"
#include "code_0200f5ac.h"
#include "code_021329f8.h"
#include "code_021522a0.h"
#include "code_02152934.h"
#include "00/code_0219daa8.h"
#include "00/code_0219c000.h"
#include "00/code_0219c384.h"
#include "00/code_0219caac.h"
#include "00/code_0219742c.h"
#include "code_02152a24.h"

// Stores the callback and its argument in mBuddyChangedCallback / mBuddyChangedCallbackArg of gWiFiBuddySync when the
// object exists.
void SetBuddyChangedCallback(void *callback, void *param) {
    if (gWiFiBuddySync != NULL) {
        gWiFiBuddySync->mBuddyChangedCallback = callback;
        gWiFiBuddySync->mBuddyChangedCallbackArg = param;
    }
}

// Runs from InitWiFiConnection, per login.
void InitBuddySync(WiFiBuddySync *buddySync, struct GpConnection *gpConnection, char *playerName,
                   DWCAccFriendData *friendList, s32 friendListLength) {
    WiFiBuddySync *q;
    gWiFiBuddySync = buddySync;
    buddySync->mState = 0;
    gWiFiBuddySync->mGpConnection = gpConnection;
    gWiFiBuddySync->mPollCount = 0;
    q = gWiFiBuddySync;
    q->mLastPollTime = 0;
    q->mBuddyEntryCount = friendListLength;
    gWiFiBuddySync->mBuddies = friendList;
    gWiFiBuddySync->mSyncIndex = 0;
    gWiFiBuddySync->mBuddiesChanged = 0;
    gWiFiBuddySync->mUnk_1e = 0;
    gWiFiBuddySync->mCompletedParts = 0;
    gWiFiBuddySync->mPendingStatsRequestCount = 0;
    gWiFiBuddySync->mUnk_24 = 0;
    gWiFiBuddySync->mUnk_28 = playerName;
    gWiFiBuddySync->mResultCallback = NULL;
    gWiFiBuddySync->mResultCallbackArg = NULL;
    gWiFiBuddySync->mBuddyStatusCallback = NULL;
    gWiFiBuddySync->mBuddyStatusCallbackArg = NULL;
    gWiFiBuddySync->mEntryMergedCallback = NULL;
    gWiFiBuddySync->mEntryMergedCallbackArg = NULL;
    gWiFiBuddySync->mBuddyChangedCallback = NULL;
    gWiFiBuddySync->mBuddyChangedCallbackArg = NULL;
    gWiFiBuddySync->mUnk_4c = NULL;
    gWiFiBuddySync->mUnk_50 = 0;
}

// Also the only pump of the GP connection: every call in states 3 to 6 reaches DWCi_GPProcess, which calls
// GpUpdate every 300 ms, whether or not a sync was started; the list part runs after more than 7 polls.
void UpdateBuddySync(void) {
    if (gWiFiBuddySync == NULL) {
        return;
    }
    if (gWiFiBuddySync->mBuddies == NULL) {
        return;
    }
    if (DWCi_IsError() != 0) {
        return;
    }
    if (GetPendingStatsRequestCount() != 0 && PersistThink() == FALSE) {
        ReportBuddySyncError(6, -0x1194a);
        return;
    }
    if (gWiFiBuddySync->mGpConnection != NULL && gWiFiBuddySync->mGpConnection->mGpiConnection != NULL) {
        if (ReportBuddySyncGpResult(DWCi_GPProcess()) != 0) {
            return;
        }
        if (gWiFiBuddySync->mBuddies != NULL && gWiFiBuddySync->mUnk_1e != 3 && gWiFiBuddySync->mPollCount > 7) {
            if (gWiFiBuddySync->mUnk_1e <= 1) {
                DWCi_UpdateFriendReq(gWiFiBuddySync->mBuddies, gWiFiBuddySync->mBuddyEntryCount);
            }
            if (gWiFiBuddySync->mSyncIndex >= gWiFiBuddySync->mBuddyEntryCount) {
                gWiFiBuddySync->mUnk_1e = 3;
                gWiFiBuddySync->mCompletedParts++;
            }
        }
    }
    if (gWiFiBuddySync->mCompletedParts >= 2) {
        gWiFiBuddySync->mCompletedParts = 0;
        FinishBuddySync();
    }
}

void StartBuddySync(s32 authToken, const char *partnerChallenge, void (*updateCallback)(s32, u8, void *),
                    void *updateParam, void (*statusCallback)(s32, u8, void *, void *), void *statusParam,
                    void (*deleteCallback)(s32, s32, void *), void *deleteParam) {
    s32 attemptIndex;
    s32 j;
    s32 statsResult;
    s8 statsRequestText[0x28];
    gWiFiBuddySync->mResultCallback = updateCallback;
    gWiFiBuddySync->mResultCallbackArg = updateParam;
    gWiFiBuddySync->mBuddyStatusCallback = statusCallback;
    gWiFiBuddySync->mBuddyStatusCallbackArg = statusParam;
    gWiFiBuddySync->mEntryMergedCallback = deleteCallback;
    gWiFiBuddySync->mEntryMergedCallbackArg = deleteParam;
    attemptIndex = 0;
    gWiFiBuddySync->mBuddiesChanged = 0;
    gWiFiBuddySync->mUnk_1e = 0;
    gWiFiBuddySync->mCompletedParts = 0;
    gWiFiBuddySync->mState = 1;
    if (((s8 *) gWiFiBuddySync->mUnk_28)[attemptIndex] != 0) {
        j = attemptIndex;
        for (; attemptIndex < 5; attemptIndex++) {
            statsResult = GstatsConnect(j);
            if (statsResult == 0) {
                break;
            }
            if (statsResult != 2 || attemptIndex == 4) {
                ReportBuddySyncStatsResult(statsResult);
                return;
            }
        }
        GenerateAuthA((const char *) GetChallenge(NULL), partnerChallenge, statsRequestText);
        PreAuthenticatePlayerPartner(0, authToken, (s32) statsRequestText, BuddySyncStatsAuthCallback, 0);
        AddPendingStatsRequest();
    } else {
        gWiFiBuddySync->mCompletedParts++;
    }
}

// Records the (error kind, code) pair in the error store of the layer (DWCi_SetError), calls the result callback
// with the code only while the sync runs (mState is 1) and closes the stats link. Not only the sync calls it: also the
// connection's GP error mapper, the stats code and the matching code.
void ReportBuddySyncError(s32 error, s32 errorCode) {
    if (gWiFiBuddySync != NULL && error != 0) {
        DWCi_SetError(error, errorCode);
        if (gWiFiBuddySync->mState != 0 && gWiFiBuddySync->mState != 2) {
            gWiFiBuddySync->mResultCallback(error, gWiFiBuddySync->mBuddiesChanged, gWiFiBuddySync->mResultCallbackArg);
        }
        CloseStatsAndResetBuddySync();
    }
}

// GP callback slot 1 (request): an incoming add-buddy request. The reply handler
// DWCi_GPGetInfoCallback_RecvBuddyRequest authorizes it and adds the sender back (AddBuddy) when the list holds an
// entry with that name or id; otherwise the request is dropped locally (no message is sent).
void WiFiGpBuddyRequestCallback(GpConnection *connection, u32 *arg) {
    if (gWiFiBuddySync->mBuddies != NULL) {
        GpGetInfo(connection, *arg, 0, 0, (Unk0218eff8Cb) DWCi_GPGetInfoCallback_RecvBuddyRequest, 0);
    }
}

u32 DWCi_GPRecvBuddyAuthCallback(GpConnection *connection, u32 *arg, u32 param) {
    int compareResult;
    compareResult = strcmp((const char *) (arg[2]), gBuddyAuthorizedMessage);
    if (compareResult == 0) {
        GpGetInfo(connection, *arg, 0, 0, (Unk0218eff8Cb) DWCi_GPGetInfoCallback_RecvAuthMessage, 0);
        return 1;
    }
    return 0;
}

// GP callback slot 2 (status): looks up the list entry and calls mBuddyStatusCallback.
void WiFiGpBuddyStatusCallback(struct GpConnection *connection, s32 *arg) {
    GpBuddyStatus status;
    u32 friendSlot;
    WiFiBuddySync *wiFiBuddySync;
    if (gWiFiBuddySync->mBuddyStatusCallback != NULL) {
        friendSlot = FindBuddyEntryIndex(arg[0]);
        if (friendSlot != -1) {
            GpGetBuddyStatus(connection, arg[2], &status);
            wiFiBuddySync = gWiFiBuddySync;
            wiFiBuddySync->mBuddyStatusCallback(friendSlot, status.mUnk_004, status.mUnk_108,
                                                wiFiBuddySync->mBuddyStatusCallbackArg);
        }
    }
}

s32 DWCi_GetFriendListLen(void) {
    if (gWiFiBuddySync != NULL) {
        return gWiFiBuddySync->mBuddyEntryCount;
    }
    return 0;
}

// 0 when the entry holds no id.
int GetBuddyEntryProfileId(int index) {
    DWCAccUserData *userData;
    u32 profileId;
    userData = DWCi_GetUserData();
    profileId = DWC_GetGsProfileId(userData, &gWiFiBuddySync->mBuddies[index]);
    if ((profileId == 0) || (profileId == -1)) {
        profileId = 0;
    }
    return profileId;
}

// Index of the entry with this GP profile id, or -1.
u32 FindBuddyEntryIndex(u32 profileId) {
    s32 index;
    if (gWiFiBuddySync == NULL || profileId == 0) {
        return -1;
    }
    for (index = 0; index < gWiFiBuddySync->mBuddyEntryCount; index++) {
        if (profileId == GetBuddyEntryProfileId(index)) {
            return index;
        }
    }
    return -1;
}

void DWCi_InitGPProcessCount(void) {
    if (gWiFiBuddySync != NULL) {
        gWiFiBuddySync->mPollCount = 0;
        gWiFiBuddySync->mLastPollTime = OS_GetTick();
    }
}

u32 DWCi_SetGPStatus(s32 status, void *statusString, void *locationString) {
    if (gWiFiBuddySync == NULL || gWiFiBuddySync->mGpConnection == NULL) {
        return 0;
    }
    if (status == -1) {
        status = gWiFiBuddySync->mGpConnection->mGpiConnection->mStatus;
    }
    if (statusString == NULL) {
        statusString = gWiFiBuddySync->mGpConnection->mGpiConnection->mStatusString;
    }
    if (locationString == NULL) {
        locationString = gWiFiBuddySync->mGpConnection->mGpiConnection->mLocationString;
    }
    return GpSetStatus(gWiFiBuddySync->mGpConnection, status, statusString, locationString);
}

void DWCi_CallBuddyFriendCallback(s32 index) {
    GpBuddyStatus buddyStatus;
    if (gWiFiBuddySync->mBuddyChangedCallback != NULL && gWiFiBuddySync->mState != 1) {
        ((void (*)(s32, void *)) gWiFiBuddySync->mBuddyChangedCallback)(index,
                                                                        gWiFiBuddySync->mBuddyChangedCallbackArg);
    }
    if (gWiFiBuddySync->mBuddyStatusCallback != NULL) {
        WiFiBuddySync *wiFiBuddySync;
        u8 friendStatus = DWC_GetFriendStatus(&gWiFiBuddySync->mBuddies[index], buddyStatus.mUnk_108);
        wiFiBuddySync = gWiFiBuddySync;
        wiFiBuddySync->mBuddyStatusCallback(index, friendStatus, buddyStatus.mUnk_108,
                                            wiFiBuddySync->mBuddyStatusCallbackArg);
    }
}

void DWCi_ShutdownFriend(void) {
    *(u32 *) &gWiFiBuddySync = 0;
}

int DWCi_GPProcess(void) {
    WiFiBuddySync *buddySync = gWiFiBuddySync;
    if ((OS_GetTick() - buddySync->mLastPollTime) * 64 / 0x82ea >= 300) {
        buddySync->mPollCount = buddySync->mPollCount + 1;
        GpUpdate(gWiFiBuddySync->mGpConnection);
        gWiFiBuddySync->mLastPollTime = OS_GetTick();
    }
    return 0;
}

void CloseStatsAndResetBuddySync(void) {
    if (gWiFiBuddySync != NULL) {
        GstatsClose();
        gWiFiBuddySync->mState = 0;
    }
}

void DWCi_UpdateFriendReq(DWCAccFriendData *friendList, s32 friendListLength) {
    s32 buddyCount;
    s32 buddyIndex;
    s32 friendIndex;
    char searchName[0x18];
    GpBuddyStatus buddyInfo;
    s32 profileId;
    if (gWiFiBuddySync->mUnk_1e == 0) {
        ReportBuddySyncGpResult(GpGetBuddyCount(gWiFiBuddySync->mGpConnection, &buddyCount));
        for (buddyIndex = 0; buddyIndex < buddyCount; buddyIndex++) {
            ReportBuddySyncGpResult(GpGetBuddyStatus(gWiFiBuddySync->mGpConnection, buddyIndex, &buddyInfo));
            for (friendIndex = 0; friendIndex < friendListLength; friendIndex++) {
                if (buddyInfo.mUnk_000 == GetBuddyEntryProfileId(friendIndex)) {
                    if (DWC_IsBuddyFriendData((DWCAccFriendData *) friendList + friendIndex) == 0) {
                        InitFriendDataFromGsProfileId(&friendList[friendIndex], buddyInfo.mUnk_000);
                        DWCi_SetBuddyFriendData(&friendList[friendIndex]);
                        gWiFiBuddySync->mBuddiesChanged = 1;
                    }
                    break;
                }
            }
            if (friendIndex == friendListLength) {
                ReportBuddySyncGpResult(GpDeleteBuddy(gWiFiBuddySync->mGpConnection, buddyInfo.mUnk_000));
                buddyCount--;
                buddyIndex--;
            }
        }
        gWiFiBuddySync->mUnk_1e = 1;
    }
    for (; gWiFiBuddySync->mSyncIndex < friendListLength; gWiFiBuddySync->mSyncIndex++) {
        profileId = GetBuddyEntryProfileId(gWiFiBuddySync->mSyncIndex);
        if (profileId != 0) {
            if (DWCi_RefreshFriendListForth(friendList, gWiFiBuddySync->mSyncIndex, profileId) == FALSE &&
                DWC_IsBuddyFriendData(&friendList[gWiFiBuddySync->mSyncIndex]) == 0) {
                ReportBuddySyncGpResult(GpGetBuddyIndex(gWiFiBuddySync->mGpConnection, profileId, &buddyIndex));
                if (buddyIndex == -1) {
                    AddBuddy(profileId);
                }
            }
        } else if (DWC_GetGsProfileId(DWCi_GetUserData(), &friendList[gWiFiBuddySync->mSyncIndex]) == -1) {
            DWC_LoginIdToUserName(DWCi_GetUserData(), &friendList[gWiFiBuddySync->mSyncIndex], searchName);
            GpProfileSearchA(gWiFiBuddySync->mGpConnection, NULL, NULL, NULL, NULL, (s8 *) searchName, 0, 0,
                             (Unk0218f0a8Cb) DWCi_GPProfileSearchCallback, gWiFiBuddySync->mSyncIndex);
            gWiFiBuddySync->mUnk_1e = 2;
            return;
        }
    }
}

// The step UpdateBuddySync runs when both parts have ended: reports success (code 0) to the result callback and sets
// the finished state (mState 2).
void FinishBuddySync(void) {
    gWiFiBuddySync->mResultCallback(0, gWiFiBuddySync->mBuddiesChanged, gWiFiBuddySync->mResultCallbackArg);
    gWiFiBuddySync->mState = 2;
}

void DWCi_DeleteFriendFromList(DWCAccFriendData *friendData, s32 deleteIndex, s32 otherIndex) {
    if (gWiFiBuddySync != NULL) {
        MI_CpuFill8(&friendData[deleteIndex], 0, 12);
        if (gWiFiBuddySync->mEntryMergedCallback != NULL) {
            gWiFiBuddySync->mEntryMergedCallback(deleteIndex, otherIndex, gWiFiBuddySync->mEntryMergedCallbackArg);
        }
    }
}

BOOL DWCi_RefreshFriendListForth(DWCAccFriendData *friendList, s32 index, s32 profileId) {
    s32 otherIndex;
    s32 otherProfileId;
    for (otherIndex = 0; otherIndex < index; otherIndex++) {
        otherProfileId = GetBuddyEntryProfileId(otherIndex);
        if (otherProfileId != 0 && otherProfileId == profileId) {
            if (DWC_IsBuddyFriendData(&friendList[index]) != 0 && DWC_IsBuddyFriendData(&friendList[otherIndex]) == 0) {
                DWCi_DeleteFriendFromList(friendList, otherIndex, index);
            } else {
                DWCi_DeleteFriendFromList(friendList, index, otherIndex);
            }
            gWiFiBuddySync->mBuddiesChanged = 1;
            return TRUE;
        }
    }
    return FALSE;
}

s32 DWCi_RefreshFriendListAll(DWCAccFriendData *friendList, s32 friendListLength, s32 profileId) {
    s32 foundIndex;
    s32 index;
    s32 laterIndex;
    s32 currentProfileId;
    DWCAccFriendData *typeCheckEntry;
    DWCAccFriendData *updatedEntry;
    DWCAccFriendData *laterEntry;
    index = 0;
    foundIndex = -1;
    if (friendListLength - 1 > 0) {
        typeCheckEntry = friendList;
        updatedEntry = friendList;
        do {
            currentProfileId = GetBuddyEntryProfileId(index);
            if (currentProfileId != 0) {
                if (currentProfileId == profileId) {
                    foundIndex = index;
                }
                laterIndex = index + 1;
                if (laterIndex < friendListLength) {
                    laterEntry = &friendList[laterIndex];
                    do {
                        if (currentProfileId == GetBuddyEntryProfileId(laterIndex)) {
                            if (GetFriendDataType(typeCheckEntry) == 2 && GetFriendDataType(laterEntry) == 3) {
                                InitFriendDataFromGsProfileId(updatedEntry, currentProfileId);
                            }
                            if (DWC_IsBuddyFriendData(laterEntry) != 0) {
                                DWCi_SetBuddyFriendData(updatedEntry);
                            }
                            DWCi_DeleteFriendFromList(friendList, laterIndex, index);
                            gWiFiBuddySync->mBuddiesChanged = 1;
                        }
                        laterEntry++;
                        laterIndex++;
                    } while (laterIndex < friendListLength);
                }
            }
            typeCheckEntry++;
            updatedEntry++;
            index++;
        } while (index < friendListLength - 1);
    }
    return foundIndex;
}

// Sends the GP add-buddy request for a profile id (GpWriteAddbuddy with mUnk_28 as the reason text) and runs the
// error check; the buddy exists only once the other side authorizes.
u32 AddBuddy(u32 profileId) {
    u32 gpReturn;
    gpReturn = GpWriteAddbuddy(gWiFiBuddySync->mGpConnection, profileId, gWiFiBuddySync->mUnk_28);
    ReportBuddySyncGpResult(gpReturn);
    return gpReturn;
}
