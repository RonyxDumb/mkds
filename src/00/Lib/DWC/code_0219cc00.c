#include "00/Lib/DWC/code_0219cc00.h"
#include "00/Lib/GameSpy/code_02196960.h"
#include "00/code_02197000.h"
#include "00/code_0219c000.h"
#include "00/Lib/DWC/code_0219cfc0.h"
#include "00/code_0219d000.h"
#include "00/unk_021b5000.h"
#include "00/Lib/DWC/code_0219d128.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"

#include "00/code_0219c954.h"
#include "00/Lib/DWC/code_0219cb00.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/code_02196000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/unk_021b4000.h"
#include "os_printf.h"
#include "code_02139f70.h"
#include "dwc_account.h"
#include "code_021522a0.h"
#include "Main/Net/friend_data_from_profile.h"

void DWCi_GPProfileSearchCallback(GpConnection *connection, ProfileSearchReply *arg, u32 friendIdx) {
    s32 matchSlot;
    s32 zero;
    s32 buddyIndex;
    if (arg->mResult == GP_REQUEST_OK && arg->mNumMatches != 0 &&
        GetFriendDataType(&gWiFiBuddySync->mBuddies[friendIdx]) != 0) {
        if (gWiFiBuddySync->mState == 1) {
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
                ReportBuddySyncGpResult(GpGetBuddyIndex(connection, arg->mMatches[matchSlot].mProfile, &buddyIndex));
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
        if (arg->mResult != GP_REQUEST_OK) {
            if (ReportBuddySyncGpResult(arg->mResult) != 0) {
                return;
            }
        } else if (gWiFiBuddySync->mState == 1 || GetFriendDataType(&gWiFiBuddySync->mBuddies[friendIdx]) == 0) {
            gWiFiBuddySync->mSyncIndex++;
            gWiFiBuddySync->mBuddyUpdateState = BUDDY_UPDATE_STATE_SYNC_ENTRIES;
        }
    }
}

void DWCi_GPGetInfoCallback_RecvBuddyRequest(GpConnection *connection, GetInfoReply *arg, u32 param) {
    GpConnection *gpConnection = connection;
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

void DWCi_GPGetInfoCallback_RecvAuthMessage(GpConnection *connection, GetInfoReply *arg, u32 param) {
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

void BuddySyncStatsAuthCallback(u32 localId, u32 profileId, u32 authenticated) {
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
