#include "00/Lib/DWC/buddy_request_callbacks.h"
#include "00/Lib/GameSpy/persistent_stats.h"
#include "00/Lib/DWC/buddy_status_error.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/buddy_friends.h"
#include "00/Lib/DWC/login_state.h"
#include "00/Lib/DWC/buddy_friend_callback.h"

#include "00/Lib/DWC/login_control.h"
#include "00/Lib/DWC/persist_callback_level.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/wifi_library_globals.h"
#include "formatted_text_to_buffer.h"
#include "narrow_string_functions.h"
#include "friend_data_account_fields.h"
#include "friend_user_data.h"
#include "Main/Net/friend_data_from_profile.h"

void DWCi_GPProfileSearchCallback(GPConnection *connection, ProfileSearchReply *arg, u32 friendIdx) {
    s32 matchSlot;
    s32 zero;
    s32 buddyIndex;
    if (arg->mResult == PROFILE_REQUEST_OK && arg->mNumMatches != 0 &&
        GetFriendDataType(&gWiFiBuddySync->mBuddies[friendIdx]) != 0) {
        if (gWiFiBuddySync->mState == BUDDY_SYNC_STATE_UPDATING) {
            gWiFiBuddySync->mBuddiesChanged = 1;
            for (matchSlot = 0; matchSlot < arg->mNumMatches; matchSlot++) {
                if (DWCi_RefreshFriendListForth(gWiFiBuddySync->mBuddies, friendIdx,
                                                arg->mMatches[matchSlot].mProfile) != FALSE) {
                    gWiFiBuddySync->mSyncIndex++;
                    gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_SYNC_ENTRIES;
                    arg->mMore = PROFILE_SEARCH_MORE_DONE;
                    return;
                }
            }
            zero = 0;
            for (matchSlot = 0; matchSlot < arg->mNumMatches; matchSlot++) {
                ReportBuddySyncGpResult(gpGetBuddyIndex(connection, arg->mMatches[matchSlot].mProfile, &buddyIndex));
                if (buddyIndex == ~zero) {
                    DWCi_GPSendBuddyRequest(arg->mMatches[matchSlot].mProfile);
                } else {
                    InitFriendDataFromGsProfileId(&gWiFiBuddySync->mBuddies[friendIdx], arg->mMatches[0].mProfile);
                    DWCi_SetBuddyFriendData(&gWiFiBuddySync->mBuddies[friendIdx]);
                    DWCi_CallBuddyFriendCallback(friendIdx);
                    gWiFiBuddySync->mSyncIndex++;
                    gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_SYNC_ENTRIES;
                    arg->mMore = PROFILE_SEARCH_MORE_DONE;
                    return;
                }
            }
            if (arg->mMore != PROFILE_SEARCH_MORE_CONTINUE) {
                gWiFiBuddySync->mSyncIndex++;
                gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_SYNC_ENTRIES;
            }
        }
    } else {
        if (arg->mResult != PROFILE_REQUEST_OK) {
            if (ReportBuddySyncGpResult(arg->mResult) != 0) {
                return;
            }
        } else if (gWiFiBuddySync->mState == BUDDY_SYNC_STATE_UPDATING ||
                   GetFriendDataType(&gWiFiBuddySync->mBuddies[friendIdx]) == 0) {
            gWiFiBuddySync->mSyncIndex++;
            gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_SYNC_ENTRIES;
        }
    }
}

void DWCi_GPGetInfoCallback_RecvBuddyRequest(GPConnection *connection, GetInfoReply *arg, u32 param) {
    GPConnection *gpConnection = connection;
    s32 index;
    BOOL approve;
    char friendName[0x18];
    u32 profileId;
    approve = FALSE;
    index = 0;
    for (; index < gWiFiBuddySync->mBuddyEntryCount; index++) {
        if (GetFriendDataType(&gWiFiBuddySync->mBuddies[index]) == 1) {
            DWC_LoginIdToUserName(DWCi_GetUserData(), &gWiFiBuddySync->mBuddies[index], friendName);
            if (strcmp(friendName, arg->mLastname) == 0) {
                GpAuthBuddyRequest(gpConnection, arg->mProfile);
                InitFriendDataFromGsProfileId(&gWiFiBuddySync->mBuddies[index], arg->mProfile);
                approve = TRUE;
            }
        } else if (GetFriendDataType(&gWiFiBuddySync->mBuddies[index]) == 3 ||
                   GetFriendDataType(&gWiFiBuddySync->mBuddies[index]) == 2) {
            profileId = arg->mProfile;
            if (profileId == DWC_GetGsProfileId(DWCi_GetUserData(), &gWiFiBuddySync->mBuddies[index])) {
                GpAuthBuddyRequest(gpConnection, profileId);
                approve = TRUE;
            }
        }
    }
    if (approve != FALSE) {
        DWCi_GPSendBuddyRequest(arg->mProfile);
    } else {
        GpDenyBuddyRequest(gpConnection, arg->mProfile);
    }
}

void DWCi_GPGetInfoCallback_RecvAuthMessage(GPConnection *connection, GetInfoReply *arg, u32 param) {
    s32 index;
    BOOL matched;
    char friendName[0x1c];
    u32 profileId;
    matched = FALSE;
    index = 0;
    for (; index < gWiFiBuddySync->mBuddyEntryCount; index++) {
        if (GetFriendDataType(&gWiFiBuddySync->mBuddies[index]) == 1) {
            DWC_LoginIdToUserName(DWCi_GetUserData(), &gWiFiBuddySync->mBuddies[index], friendName);
            if (strcmp(friendName, arg->mLastname) == 0) {
                InitFriendDataFromGsProfileId(&gWiFiBuddySync->mBuddies[index], arg->mProfile);
                DWCi_SetBuddyFriendData(&gWiFiBuddySync->mBuddies[index]);
                matched = TRUE;
            }
        } else if (GetFriendDataType(&gWiFiBuddySync->mBuddies[index]) == 3 ||
                   GetFriendDataType(&gWiFiBuddySync->mBuddies[index]) == 2) {
            profileId = arg->mProfile;
            if (profileId == DWC_GetGsProfileId(DWCi_GetUserData(), &gWiFiBuddySync->mBuddies[index])) {
                InitFriendDataFromGsProfileId(&gWiFiBuddySync->mBuddies[index], profileId);
                DWCi_SetBuddyFriendData(&gWiFiBuddySync->mBuddies[index]);
                matched = TRUE;
            }
        }
    }
    if (matched != FALSE) {
        DWCi_CallBuddyFriendCallback(
            DWCi_RefreshFriendListAll(gWiFiBuddySync->mBuddies, gWiFiBuddySync->mBuddyEntryCount, arg->mProfile));
        gWiFiBuddySync->mBuddiesChanged = 1;
    }
}

void BuddySyncStatsAuthCallback(u32 localId, u32 profileId, u32 authenticated, const void *data, u32 instance) {
    char keyValues[0x40];
    DWCi_SubPersCallbackLevel();
    if (authenticated == 0 || localId != 0) {
        DWCi_StopFriendProcess(6, -72200);
        return;
    }
    gWiFiBuddySync->mProfileId = profileId;
    OS_SNPrintf(keyValues, 0x40, "\\dwc_name\\%s", gWiFiBuddySync->mPlayerName);
    DWCi_SetPersistDataValuesAsync(gWiFiBuddySync->mProfileId, 3, keyValues, 0x80000001);
}

void DWCi_SetPersistDataValuesAsync(u32 profileId, u32 type, const char *valueString, u32 param) {
    DWCi_AddPersCallbackLevel();
    SetPersistDataValuesA(0, profileId, type, 0, valueString, BuddySyncStatsSaveCallback, param);
}
