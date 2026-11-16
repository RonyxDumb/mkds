#include "Main/Net/wifi_session_login.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/Net/buddy_changed_callback.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Save/buddy_records_write.h"
#include "Main/Save/buddy_friend_data_list.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/Lib/DWC/friend_status.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/error_state.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/DWC/internet_connection.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "friend_user_data.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_record_file.h"

void WiFiRaceSyncReceiveCallback(u32 fromIndex, void *message, u32 size) {
    if (g_GlobalB->mStateMachine.mState != WIFI_SESSION_STATE_RACE) {
        return;
    }
    if (g_GlobalB->mRaceSyncEnabled == FALSE) {
        return;
    }
    if (DoesMessageHeaderMatch(message, size, fromIndex, DWC_GetMyAID()) != FALSE) {
        return;
    }
    ReceiveWiFiRaceSyncPacket(fromIndex, message, size, 0);
}

void WriteSaveFriendCodes(void) {
    if (g_GlobalB->mBuddiesChanged == FALSE) {
        return;
    }
    CopyFriendCodesToSaveData(&g_GlobalB->mBuddies[0]);
    RefreshNotYetBuddyFlags();
    WriteFriendListSaveDataSection();
    while (g_SaveDataHolder->mBusy == 0 ? (g_SaveDataIoManager->mBackupEnabled != 0 ? g_SaveDataIoManager->mCommandRunning : 0) : 1) {
    }
    g_GlobalB->mBuddiesChanged = FALSE;
}

void RequestWiFiSessionLogin(void) {
    StateMachine *stateMachine;

    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_LOGIN;
    stateMachine->mNextStateRequested = 1;
}

void ReleaseWiFiConnectionWrapper(void) {
    DWC_ShutdownFriendsMatch();
}

BOOL UpdateWiFiSessionRelease(void) {
    StateMachine *stateMachine;

    if (g_GlobalB->mStateMachine.mState == WIFI_SESSION_STATE_OFF) {
        return 1;
    }
    if (DWC_CleanupInetAsync() == FALSE) {
        return 0;
    }
    ResetWiFiSession();
    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
    return 1;
}

s32 GetWiFiSessionLoginResult(void) {
    switch (g_GlobalB->mLogin.mStep) {
        case WIFI_LOGIN_STEP_DONE:
            return 1;
        case WIFI_LOGIN_STEP_FAILED:
            return -1;
        default:
            return 0;
    }
}

void OnSomeMultiplayError(void) {
    StateMachine *stateMachine;

    DWC_ShutdownFriendsMatch();
    DWC_CleanupInet();
    ResetWiFiSession();
    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
}

void GlobalB_E7Fn_1AImpl(void) {
    u8 buddyIndex;
    WiFiSession *session;

    Mem_CpuFill8(&g_GlobalB->mLogin, 0, sizeof(g_GlobalB->mLogin));
    Mem_CpuFill8(&g_GlobalB->mUserData, 0, 0x350);
    Mem_CpuFill8(&g_GlobalB->mConnection, 0, 0xe24);
    if (CheckUserDataValidConsole() != 0) {
        Mem_CpuCopy8(&g_SaveDataHolder->mFirstBlock->mUserData, &g_GlobalB->mUserData, sizeof(g_GlobalB->mUserData));
    } else {
        j_PlayerProfileInfo_Create_from_thumb(&g_GlobalB->mUserData, 0x414d434a);
    }
    GlobalZ_CopyNKFLOther1(&g_GlobalB->mBuddies[0]);
    DWC_InitInet(&g_GlobalB->mLogin);
    DWC_SetAuthServer(2);
    DWC_ConnectInetAsync();
    buddyIndex = 0;
    if (DWC_GetNumFriend(&g_GlobalB->mBuddies[0], 0x3c) > 0) {
        do {
            buddyIndex++;
        } while (buddyIndex < DWC_GetNumFriend(&g_GlobalB->mBuddies[0], 0x3c));
    }
    session = g_GlobalB;
    DWC_InitFriendsMatch(&session->mConnection, &session->mUserData, 0x4d6, "mariokartds", "yeJ3x8", 0, 0,
                         &session->mBuddies[0], 0x3c);
    g_GlobalB->mErrorKind = 0;
    g_GlobalB->mErrorCode = 0;
    g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_WAIT_INET;
}

void AdvanceWiFiSessionLoginStep1(void) {
    if (DWC_CheckInet() == 0) {
        DWC_ProcessInet();
        return;
    }
    switch (DWC_GetInetStatus()) {
        case INET_STATUS_ONLINE:
            DWC_LoginAsync(0, 0, WiFiSessionLoginCallback, 0);
            g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_WAIT_LOGIN;
            break;
        case INET_STATUS_FAILED_LARGE_CODE:
            g_GlobalB->mErrorKind = DWC_GetLastError(&g_GlobalB->mErrorCode);
            DWC_ShutdownFriendsMatch();
            DWC_CleanupInet();
            g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_FAILED;
            break;
        case INET_STATUS_FAILED_SMALL_CODE:
            break;
    }
}

u32 UpdateWiFiSessionLogin(void) {
    switch (g_GlobalB->mLogin.mStep) {
        case WIFI_LOGIN_STEP_WAIT_INET:
            AdvanceWiFiSessionLoginStep1();
            break;
        case WIFI_LOGIN_STEP_WAIT_BACKUP:
            if (g_SaveDataHolder->mBusy == 0 ? (g_SaveDataIoManager->mBackupEnabled != 0 ? g_SaveDataIoManager->mCommandRunning : 0)
                                           : 1) {
                break;
            }
            PlayerProfileInfo_SomeFn_2_from_thumb(&g_GlobalB->mUserData);
            if (DWC_UpdateServersAsync(NULL, WiFiSessionBuddySyncCallback, NULL, SetBuddyStatus, NULL,
                                       WiFiSessionEntryMergedCallback, NULL) == 0) {
                g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_FAILED;
            }
            DWC_SetBuddyFriendCallback(BuddyChangedCallback, NULL);
            g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_UPDATE_BUDDIES;
            break;
        case WIFI_LOGIN_STEP_LOGIN_FAILED:
            DWC_ShutdownFriendsMatch();
            DWC_CleanupInet();
            g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_FAILED;
            break;
        case WIFI_LOGIN_STEP_DONE:
            return 1;
        case WIFI_LOGIN_STEP_FAILED:
            break;
    }
    return 0;
}

void WiFiSessionLoginCallback(s32 result, u32 profileId, u32 arg) {
    if (result == 0) {
        if (PlayerProfileInfo_NeedsSaving_from_thumb(&g_GlobalB->mUserData) != 0) {
            PlayerProfileInfo_PrepareForSave_from_thumb(&g_GlobalB->mUserData);
            Mem_CpuCopy8(&g_GlobalB->mUserData, &g_SaveDataHolder->mFirstBlock->mUserData,
                        sizeof(g_SaveDataHolder->mFirstBlock->mUserData));
            WriteSaveDataSectionHeaderToSaveData_from_thumb();
        }
        g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_WAIT_BACKUP;
    } else {
        g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_LOGIN_FAILED;
    }
}

void WiFiSessionBuddySyncCallback(s32 result, s32 changed) {
    u8 buddyIndex;

    if (result == 0) {
        if (changed != 0) {
            g_GlobalB->mBuddiesChanged = TRUE;
        }
        buddyIndex = 0;
        if (DWC_GetNumFriend(&g_GlobalB->mBuddies[0], 0x3c) > 0) {
            do {
                PlayerProfileInfo_SomeFn_3_from_thumb(&g_GlobalB->mUserData, &g_GlobalB->mBuddies[buddyIndex]);
                buddyIndex++;
            } while (buddyIndex < DWC_GetNumFriend(&g_GlobalB->mBuddies[0], 0x3c));
        }
        g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_DONE;
    } else {
        DWC_ShutdownFriendsMatch();
        DWC_CleanupInet();
        g_GlobalB->mLogin.mStep = WIFI_LOGIN_STEP_FAILED;
    }
}

void WiFiSessionEntryMergedCallback(u32 mergedIndex, u32 keptIndex) {
    OI_JoinInSlot1FreeSlot2(keptIndex, mergedIndex);
    CopyFriendCodesToSaveData(&g_GlobalB->mBuddies[0]);
    RefreshNotYetBuddyFlags();
    WriteFriendListSaveDataSection();
    while (g_SaveDataHolder->mBusy == 0 ? (g_SaveDataIoManager->mBackupEnabled != 0 ? g_SaveDataIoManager->mCommandRunning : 0) : 1) {
    }
}

void SetBuddyStatus(u32 index, u8 status) {
    g_GlobalB->mBuddyStatuses[index] = status;
}
