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
    if (gWiFiSession->mStateMachine.mState != WIFI_SESSION_STATE_RACE) {
        return;
    }
    if (gWiFiSession->mRaceSyncEnabled == FALSE) {
        return;
    }
    if (DoesMessageHeaderMatch(message, size, fromIndex, DWC_GetMyAID()) != FALSE) {
        return;
    }
    ReceiveWiFiRaceSyncPacket(fromIndex, message, size, 0);
}

void WriteChangedWiFiBuddies(void) {
    if (gWiFiSession->mBuddiesChanged == FALSE) {
        return;
    }
    CopyWiFiBuddiesToRecordBlock(&gWiFiSession->mBuddies[0]);
    RefreshNotYetBuddyFlags();
    WriteBackupBuddyRecords();
    while (gBackupBuffers->mBusy == 0 ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0) : 1) {
    }
    gWiFiSession->mBuddiesChanged = FALSE;
}

void RequestWiFiSessionLogin(void) {
    StateMachine *stateMachine;

    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_LOGIN;
    stateMachine->mNextStateRequested = 1;
}

void ReleaseWiFiConnectionWrapper(void) {
    DWC_ShutdownFriendsMatch();
}

BOOL UpdateWiFiSessionRelease(void) {
    StateMachine *stateMachine;

    if (gWiFiSession->mStateMachine.mState == WIFI_SESSION_STATE_OFF) {
        return 1;
    }
    if (DWC_CleanupInetAsync() == FALSE) {
        return 0;
    }
    ResetWiFiSession();
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
    return 1;
}

s32 GetWiFiSessionLoginResult(void) {
    switch (gWiFiSession->mLogin.mStep) {
        case WIFI_LOGIN_STEP_DONE:
            return 1;
        case WIFI_LOGIN_STEP_FAILED:
            return -1;
        default:
            return 0;
    }
}

void ReleaseWiFiSession(void) {
    StateMachine *stateMachine;

    DWC_ShutdownFriendsMatch();
    DWC_CleanupInet();
    ResetWiFiSession();
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
}

void SetupWiFiSessionLogin(void) {
    u8 buddyIndex;
    WiFiSession *session;

    MI_CpuFill8(&gWiFiSession->mLogin, 0, sizeof(gWiFiSession->mLogin));
    MI_CpuFill8(&gWiFiSession->mUserData, 0, 0x350);
    MI_CpuFill8(&gWiFiSession->mConnection, 0, 0xe24);
    if (CheckUserDataValidConsole() != 0) {
        MI_CpuCopy8(&gBackupBuffers->mFirstBlock->mUserData, &gWiFiSession->mUserData, sizeof(gWiFiSession->mUserData));
    } else {
        DWC_CreateUserData(&gWiFiSession->mUserData, 0x414d434a);
    }
    CopyBuddyFriendDataList(&gWiFiSession->mBuddies[0]);
    DWC_InitInet(&gWiFiSession->mLogin);
    DWC_SetAuthServer(AUTH_SERVER_NO_TEST_OR_DEV_LABEL);
    DWC_ConnectInetAsync();
    buddyIndex = 0;
    if (DWC_GetNumFriend(&gWiFiSession->mBuddies[0], WIFI_BUDDY_COUNT) > 0) {
        do {
            buddyIndex++;
        } while (buddyIndex < DWC_GetNumFriend(&gWiFiSession->mBuddies[0], WIFI_BUDDY_COUNT));
    }
    session = gWiFiSession;
    DWC_InitFriendsMatch(&session->mConnection, &session->mUserData, 0x4d6, "mariokartds", "yeJ3x8", 0, 0,
                         &session->mBuddies[0], WIFI_BUDDY_COUNT);
    gWiFiSession->mErrorKind = 0;
    gWiFiSession->mErrorCode = 0;
    gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_WAIT_INET;
}

void AdvanceWiFiSessionLoginStep1(void) {
    if (DWC_CheckInet() == 0) {
        DWC_ProcessInet();
        return;
    }
    switch (DWC_GetInetStatus()) {
        case INET_STATUS_ONLINE:
            DWC_LoginAsync(0, 0, WiFiSessionLoginCallback, 0);
            gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_WAIT_LOGIN;
            break;
        case INET_STATUS_FAILED_LARGE_CODE:
            gWiFiSession->mErrorKind = DWC_GetLastError(&gWiFiSession->mErrorCode);
            DWC_ShutdownFriendsMatch();
            DWC_CleanupInet();
            gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_FAILED;
            break;
        case INET_STATUS_FAILED_SMALL_CODE:
            break;
    }
}

u32 UpdateWiFiSessionLogin(void) {
    switch (gWiFiSession->mLogin.mStep) {
        case WIFI_LOGIN_STEP_WAIT_INET:
            AdvanceWiFiSessionLoginStep1();
            break;
        case WIFI_LOGIN_STEP_WAIT_BACKUP:
            if (gBackupBuffers->mBusy == 0 ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0)
                                           : 1) {
                break;
            }
            DWC_ReportUserData(&gWiFiSession->mUserData);
            if (DWC_UpdateServersAsync(NULL, WiFiSessionBuddySyncCallback, NULL, SetBuddyStatus, NULL,
                                       WiFiSessionEntryMergedCallback, NULL) == 0) {
                gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_FAILED;
            }
            DWC_SetBuddyFriendCallback(BuddyChangedCallback, NULL);
            gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_WAIT_BUDDY_UPDATE;
            break;
        case WIFI_LOGIN_STEP_LOGIN_FAILED:
            DWC_ShutdownFriendsMatch();
            DWC_CleanupInet();
            gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_FAILED;
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
        if (DWCi_Acc_IsDirty(&gWiFiSession->mUserData) != 0) {
            DWCi_Acc_ClearDirty(&gWiFiSession->mUserData);
            MI_CpuCopy8(&gWiFiSession->mUserData, &gBackupBuffers->mFirstBlock->mUserData,
                        sizeof(gBackupBuffers->mFirstBlock->mUserData));
            WriteBackupFirstBlockWrapper();
        }
        gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_WAIT_BACKUP;
    } else {
        gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_LOGIN_FAILED;
    }
}

void WiFiSessionBuddySyncCallback(s32 result, s32 changed) {
    u8 buddyIndex;

    if (result == 0) {
        if (changed != 0) {
            gWiFiSession->mBuddiesChanged = TRUE;
        }
        buddyIndex = 0;
        if (DWC_GetNumFriend(&gWiFiSession->mBuddies[0], WIFI_BUDDY_COUNT) > 0) {
            do {
                DWC_ReportFriendData(&gWiFiSession->mUserData, &gWiFiSession->mBuddies[buddyIndex]);
                buddyIndex++;
            } while (buddyIndex < DWC_GetNumFriend(&gWiFiSession->mBuddies[0], WIFI_BUDDY_COUNT));
        }
        gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_DONE;
    } else {
        DWC_ShutdownFriendsMatch();
        DWC_CleanupInet();
        gWiFiSession->mLogin.mStep = WIFI_LOGIN_STEP_FAILED;
    }
}

void WiFiSessionEntryMergedCallback(u32 mergedIndex, u32 keptIndex) {
    MergeBuddyRecords(keptIndex, mergedIndex);
    CopyWiFiBuddiesToRecordBlock(&gWiFiSession->mBuddies[0]);
    RefreshNotYetBuddyFlags();
    WriteBackupBuddyRecords();
    while (gBackupBuffers->mBusy == 0 ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0) : 1) {
    }
}

void SetBuddyStatus(u32 index, u8 status) {
    gWiFiSession->mBuddyStatuses[index] = status;
}
