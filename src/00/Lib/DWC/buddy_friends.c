#include "00/Lib/DWC/buddy_friends.h"
#include "00/Lib/DWC/matching_result_codes.h"

#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/DWC/persist_callback_level.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/login_state.h"
#include "00/Lib/DWC/buddy_request_callbacks.h"
#include "narrow_string_functions.h"
#include "00/Lib/DWC/buddy_friend_callback.h"
#include "Main/Net/friend_data_from_profile.h"
#include "friend_data_account_fields.h"
#include "cpu_copy_fill.h"
#include "00/Lib/DWC/login_control.h"
#include "00/Lib/DWC/buddy_status_error.h"
#include "tick_counter.h"
#include "float_subtract_int64_muldiv.h"
#include "friend_user_data.h"
#include "00/Lib/DWC/friend_status.h"
#include "00/Lib/DWC/error_state.h"
#include "00/Lib/DWC/login_init.h"
#include "00/Lib/GameSpy/persistent_stats.h"

WiFiBuddySync *gWiFiBuddySync = NULL;

void DWC_SetBuddyFriendCallback(DWCBuddyFriendCallback callback, void *param) {
    if (gWiFiBuddySync != NULL) {
        gWiFiBuddySync->mBuddyChangedCallback = callback;
        gWiFiBuddySync->mBuddyChangedCallbackArg = param;
    }
}

// Runs from DWC_InitFriendsMatch, per login.
void DWCi_FriendInit(WiFiBuddySync *buddySync, struct GPConnection *gpConnection, char *playerName,
                     DWCAccFriendData *friendList, s32 friendListLength) {
    WiFiBuddySync *loadedSync;
    gWiFiBuddySync = buddySync;
    buddySync->mState = BUDDY_SYNC_STATE_NONE;
    gWiFiBuddySync->mGpConnection = gpConnection;
    gWiFiBuddySync->mPollCount = 0;
    loadedSync = gWiFiBuddySync;
    loadedSync->mLastPollTime = 0;
    loadedSync->mBuddyEntryCount = friendListLength;
    gWiFiBuddySync->mBuddies = friendList;
    gWiFiBuddySync->mSyncIndex = 0;
    gWiFiBuddySync->mBuddiesChanged = 0;
    gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_START;
    gWiFiBuddySync->mCompletedParts = 0;
    gWiFiBuddySync->mPendingStatsRequestCount = 0;
    gWiFiBuddySync->mProfileId = 0;
    gWiFiBuddySync->mPlayerName = playerName;
    gWiFiBuddySync->mResultCallback = NULL;
    gWiFiBuddySync->mResultCallbackArg = NULL;
    gWiFiBuddySync->mBuddyStatusCallback = NULL;
    gWiFiBuddySync->mBuddyStatusCallbackArg = NULL;
    gWiFiBuddySync->mEntryMergedCallback = NULL;
    gWiFiBuddySync->mEntryMergedCallbackArg = NULL;
    gWiFiBuddySync->mBuddyChangedCallback = NULL;
    gWiFiBuddySync->mBuddyChangedCallbackArg = NULL;
    gWiFiBuddySync->mSaveCallback = NULL;
    gWiFiBuddySync->mUnk_50 = 0;
}

// In connection states 3 to 6, unless mBuddies is NULL or an error is set, it calls DWCi_GPProcess (gpProcess at most
// every 300 ms) while the GP connection exists; with mPollCount above 7 and the list update not done it also runs it.
void DWCi_FriendProcess(void) {
    if (gWiFiBuddySync == NULL) {
        return;
    }
    if (gWiFiBuddySync->mBuddies == NULL) {
        return;
    }
    if (DWCi_IsError() != 0) {
        return;
    }
    if (DWCi_GetPersCallbackLevel() != 0 && PersistThink() == FALSE) {
        DWCi_StopFriendProcess(6, -0x1194a);
        return;
    }
    if (gWiFiBuddySync->mGpConnection != NULL && gWiFiBuddySync->mGpConnection->mGpiConnection != NULL) {
        if (ReportBuddySyncGpResult(DWCi_GPProcess()) != 0) {
            return;
        }
        if (gWiFiBuddySync->mBuddies != NULL && gWiFiBuddySync->mBuddyUpdateState != BUDDY_UPDATE_STATE_DONE &&
            gWiFiBuddySync->mPollCount > 7) {
            if (gWiFiBuddySync->mBuddyUpdateState <= BUDDY_UPDATE_STATE_SYNC_ENTRIES) {
                DWCi_UpdateFriendReq(gWiFiBuddySync->mBuddies, gWiFiBuddySync->mBuddyEntryCount);
            }
            if (gWiFiBuddySync->mSyncIndex >= gWiFiBuddySync->mBuddyEntryCount) {
                gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_DONE;
                gWiFiBuddySync->mCompletedParts++;
            }
        }
    }
    if (gWiFiBuddySync->mCompletedParts >= 2) {
        gWiFiBuddySync->mCompletedParts = 0;
        DWCi_EndUpdateServers();
    }
}

void StartBuddySync(const char *authToken, const char *partnerChallenge, void (*updateCallback)(s32, u8, void *),
                    void *updateParam, void (*statusCallback)(s32, u8, void *, void *), void *statusParam,
                    void (*deleteCallback)(s32, s32, void *), void *deleteParam) {
    s32 attemptIndex;
    s32 statsAttempt;
    s32 statsResult;
    char statsRequestText[0x28];
    gWiFiBuddySync->mResultCallback = updateCallback;
    gWiFiBuddySync->mResultCallbackArg = updateParam;
    gWiFiBuddySync->mBuddyStatusCallback = statusCallback;
    gWiFiBuddySync->mBuddyStatusCallbackArg = statusParam;
    gWiFiBuddySync->mEntryMergedCallback = deleteCallback;
    gWiFiBuddySync->mEntryMergedCallbackArg = deleteParam;
    attemptIndex = 0;
    gWiFiBuddySync->mBuddiesChanged = 0;
    gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_START;
    gWiFiBuddySync->mCompletedParts = 0;
    gWiFiBuddySync->mState = BUDDY_SYNC_STATE_UPDATING;
    if (((s8 *) gWiFiBuddySync->mPlayerName)[attemptIndex] != 0) {
        statsAttempt = attemptIndex;
        for (; attemptIndex < 5; attemptIndex++) {
            statsResult = InitStatsConnection(statsAttempt);
            if (statsResult == STATS_CONNECT_OK) {
                break;
            }
            if (statsResult != STATS_CONNECT_HOST_LOOKUP || attemptIndex == 4) {
                DWCi_HandlePersError(statsResult);
                return;
            }
        }
        GenerateAuthA((const char *) GetChallenge(NULL), partnerChallenge, statsRequestText);
        PreAuthenticatePlayerPartner(0, authToken, statsRequestText, BuddySyncStatsAuthCallback, 0);
        DWCi_AddPersCallbackLevel();
    } else {
        gWiFiBuddySync->mCompletedParts++;
    }
}

// Does nothing when the sync object is NULL or error is 0. Otherwise stores (error, errorCode) with DWCi_SetError,
// calls mResultCallback with error while mState is BUDDY_SYNC_STATE_UPDATING, and closes the stats link (mState back to
// BUDDY_SYNC_STATE_NONE). Also called from the GP and stats error mappers and the matching code.
void DWCi_StopFriendProcess(s32 error, s32 errorCode) {
    if (gWiFiBuddySync != NULL && error != 0) {
        DWCi_SetError(error, errorCode);
        if (gWiFiBuddySync->mState != BUDDY_SYNC_STATE_NONE && gWiFiBuddySync->mState != BUDDY_SYNC_STATE_FINISHED) {
            gWiFiBuddySync->mResultCallback(error, gWiFiBuddySync->mBuddiesChanged, gWiFiBuddySync->mResultCallbackArg);
        }
        CloseStatsAndResetBuddySync();
    }
}

// GP callback slot 1 (request): an incoming add-buddy request. When the saved list exists it asks for the sender's
// info, and DWCi_GPGetInfoCallback_RecvBuddyRequest authorizes the request and adds the sender back
// (DWCi_GPSendBuddyRequest) when the list holds an entry with that name or id; otherwise the request is dropped locally
// (no message is sent).
void DWCi_GPRecvBuddyRequestCallback(GPConnection *connection, u32 *arg) {
    if (gWiFiBuddySync->mBuddies != NULL) {
        GpGetInfo(connection, *arg, 0, 0, DWCi_GPGetInfoCallback_RecvBuddyRequest, 0);
    }
}

u32 DWCi_GPRecvBuddyAuthCallback(GPConnection *connection, BuddyMessageData *arg, u32 param) {
    int compareResult;
    compareResult = strcmp(arg->mUnk_08, "I have authorized your request to add me to your list");
    if (compareResult == 0) {
        GpGetInfo(connection, arg->mProfile, 0, 0, DWCi_GPGetInfoCallback_RecvAuthMessage, 0);
        return 1;
    }
    return 0;
}

// GP callback slot 2 (status): when mBuddyStatusCallback is set and the profile is in the list, calls it with the list
// index and the new status.
void DWCi_GPRecvBuddyStatusCallback(struct GPConnection *connection, s32 *arg) {
    GpBuddyStatus status;
    u32 listIndex;
    WiFiBuddySync *wiFiBuddySync;
    if (gWiFiBuddySync->mBuddyStatusCallback != NULL) {
        listIndex = DWCi_GetFriendListIndex(arg[0]);
        if (listIndex != -1) {
            gpGetBuddyStatus(connection, arg[2], &status);
            wiFiBuddySync = gWiFiBuddySync;
            wiFiBuddySync->mBuddyStatusCallback(listIndex, status.mStatus, status.mLocationString,
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

// 0 when the entry has no GP profile id (this includes an entry that holds only a login id).
int DWCi_GetProfileIDFromList(int index) {
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
u32 DWCi_GetFriendListIndex(u32 profileId) {
    s32 index;
    if (gWiFiBuddySync == NULL || profileId == 0) {
        return -1;
    }
    for (index = 0; index < gWiFiBuddySync->mBuddyEntryCount; index++) {
        if (profileId == DWCi_GetProfileIDFromList(index)) {
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
    return gpSetStatusA(gWiFiBuddySync->mGpConnection, status, statusString, locationString);
}

void DWCi_CallBuddyFriendCallback(s32 index) {
    GpBuddyStatus buddyStatus;
    if (gWiFiBuddySync->mBuddyChangedCallback != NULL && gWiFiBuddySync->mState != BUDDY_SYNC_STATE_UPDATING) {
        gWiFiBuddySync->mBuddyChangedCallback(index, gWiFiBuddySync->mBuddyChangedCallbackArg);
    }
    if (gWiFiBuddySync->mBuddyStatusCallback != NULL) {
        WiFiBuddySync *wiFiBuddySync;
        u8 friendStatus = DWC_GetFriendStatus(&gWiFiBuddySync->mBuddies[index], buddyStatus.mLocationString);
        wiFiBuddySync = gWiFiBuddySync;
        wiFiBuddySync->mBuddyStatusCallback(index, friendStatus, buddyStatus.mLocationString,
                                            wiFiBuddySync->mBuddyStatusCallbackArg);
    }
}

void DWCi_ShutdownFriend(void) {
    gWiFiBuddySync = NULL;
}

int DWCi_GPProcess(void) {
    WiFiBuddySync *buddySync = gWiFiBuddySync;
    if ((OS_GetTick() - buddySync->mLastPollTime) * 64 / 0x82ea >= 300) {
        buddySync->mPollCount = buddySync->mPollCount + 1;
        gpProcess(gWiFiBuddySync->mGpConnection);
        gWiFiBuddySync->mLastPollTime = OS_GetTick();
    }
    return 0;
}

void CloseStatsAndResetBuddySync(void) {
    if (gWiFiBuddySync != NULL) {
        CloseStatsConnection();
        gWiFiBuddySync->mState = BUDDY_SYNC_STATE_NONE;
    }
}

void DWCi_UpdateFriendReq(DWCAccFriendData *friendList, s32 friendListLength) {
    s32 buddyCount;
    s32 buddyIndex;
    s32 friendIndex;
    char searchName[0x18];
    GpBuddyStatus buddyStatus;
    s32 profileId;
    if (gWiFiBuddySync->mBuddyUpdateState == BUDDY_UPDATE_STATE_START) {
        ReportBuddySyncGpResult(gpGetNumBuddies(gWiFiBuddySync->mGpConnection, &buddyCount));
        for (buddyIndex = 0; buddyIndex < buddyCount; buddyIndex++) {
            ReportBuddySyncGpResult(gpGetBuddyStatus(gWiFiBuddySync->mGpConnection, buddyIndex, &buddyStatus));
            for (friendIndex = 0; friendIndex < friendListLength; friendIndex++) {
                if (buddyStatus.mProfileId == DWCi_GetProfileIDFromList(friendIndex)) {
                    if (DWC_IsBuddyFriendData((DWCAccFriendData *) friendList + friendIndex) == 0) {
                        InitFriendDataFromGsProfileId(&friendList[friendIndex], buddyStatus.mProfileId);
                        DWCi_SetBuddyFriendData(&friendList[friendIndex]);
                        gWiFiBuddySync->mBuddiesChanged = 1;
                    }
                    break;
                }
            }
            if (friendIndex == friendListLength) {
                ReportBuddySyncGpResult(GpDeleteBuddy(gWiFiBuddySync->mGpConnection, buddyStatus.mProfileId));
                buddyCount--;
                buddyIndex--;
            }
        }
        gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_SYNC_ENTRIES;
    }
    for (; gWiFiBuddySync->mSyncIndex < friendListLength; gWiFiBuddySync->mSyncIndex++) {
        profileId = DWCi_GetProfileIDFromList(gWiFiBuddySync->mSyncIndex);
        if (profileId != 0) {
            if (DWCi_RefreshFriendListForth(friendList, gWiFiBuddySync->mSyncIndex, profileId) == FALSE &&
                DWC_IsBuddyFriendData(&friendList[gWiFiBuddySync->mSyncIndex]) == 0) {
                ReportBuddySyncGpResult(gpGetBuddyIndex(gWiFiBuddySync->mGpConnection, profileId, &buddyIndex));
                if (buddyIndex == -1) {
                    DWCi_GPSendBuddyRequest(profileId);
                }
            }
        } else if (DWC_GetGsProfileId(DWCi_GetUserData(), &friendList[gWiFiBuddySync->mSyncIndex]) == -1) {
            DWC_LoginIdToUserName(DWCi_GetUserData(), &friendList[gWiFiBuddySync->mSyncIndex], searchName);
            GpProfileSearchA(gWiFiBuddySync->mGpConnection, NULL, NULL, NULL, NULL, (s8 *) searchName, 0, 0,
                             DWCi_GPProfileSearchCallback, gWiFiBuddySync->mSyncIndex);
            gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_WAIT_PROFILE_SEARCH;
            return;
        }
    }
}

// The step DWCi_FriendProcess runs when both parts have ended: reports success (code 0) to the result callback and sets
// the finished state (mState 2).
void DWCi_EndUpdateServers(void) {
    gWiFiBuddySync->mResultCallback(0, gWiFiBuddySync->mBuddiesChanged, gWiFiBuddySync->mResultCallbackArg);
    gWiFiBuddySync->mState = BUDDY_SYNC_STATE_FINISHED;
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
        otherProfileId = DWCi_GetProfileIDFromList(otherIndex);
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
            currentProfileId = DWCi_GetProfileIDFromList(index);
            if (currentProfileId != 0) {
                if (currentProfileId == profileId) {
                    foundIndex = index;
                }
                laterIndex = index + 1;
                if (laterIndex < friendListLength) {
                    laterEntry = &friendList[laterIndex];
                    do {
                        if (currentProfileId == DWCi_GetProfileIDFromList(laterIndex)) {
                            if (GetFriendDataType(typeCheckEntry) == ACCOUNT_DATA_TYPE_FRIEND_KEY &&
                                GetFriendDataType(laterEntry) == ACCOUNT_DATA_TYPE_GS_PROFILE_ID) {
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

// Sends the GP add-buddy request for a profile id (gpSendBuddyRequestA with mPlayerName as the reason text), runs the
// error check and returns the send result.
u32 DWCi_GPSendBuddyRequest(u32 profileId) {
    u32 sendResult;
    sendResult = gpSendBuddyRequestA(gWiFiBuddySync->mGpConnection, profileId, gWiFiBuddySync->mPlayerName);
    ReportBuddySyncGpResult(sendResult);
    return sendResult;
}
