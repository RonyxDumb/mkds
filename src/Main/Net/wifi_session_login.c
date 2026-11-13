#include "Main/Net/wifi_session_login.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Net/wifi_race_sync_advance.h"
#include "00/code_0219b000.h"
#include "00/code_0219c000.h"
#include "00/code_0219d000.h"
#include "Main/Net/buddy_changed_callback.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Save/buddy_records_write.h"
#include "Main/Save/buddy_friend_data_list.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/code_0218d000.h"
#include "00/Lib/DWC/dwc_friend.h"
#include "00/unk_021b5000.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "00/code_021a3000.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/DWC/dwc_connectinet.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0214d018.h"
#include "code_021522a0.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_record_file.h"

void WiFiRaceSyncReceiveCallback(u32 fromIndex, void *message, u32 size) {
    if (gWiFiSession->mStateMachine.mState != 5) {
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
    stateMachine->mNextState = 1;
    stateMachine->mNextStateRequested = 1;
}

void ReleaseWiFiConnectionWrapper(void) {
    DWC_ShutdownFriendsMatch();
}

BOOL UpdateWiFiSessionRelease(void) {
    StateMachine *stateMachine;

    if (gWiFiSession->mStateMachine.mState == 0) {
        return 1;
    }
    if (DWC_CleanupInetAsync() == FALSE) {
        return 0;
    }
    ResetWiFiSession();
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
    return 1;
}

s32 GetWiFiSessionLoginResult(void) {
    switch (gWiFiSession->mLogin.mStep) {
        case 5:
            return 1;
        case 7:
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
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}

void SetupWiFiSessionLogin(void) {
    u8 buddyIndex;
    WiFiSession *session;

    MI_CpuFill8(&gWiFiSession->mLogin, 0, 0x10);
    MI_CpuFill8(&gWiFiSession->mUserData, 0, 0x350);
    MI_CpuFill8(&gWiFiSession->mConnection, 0, 0xe24);
    if (CheckUserDataValidConsole() != 0) {
        MI_CpuCopy8(&gBackupBuffers->mFirstBlock->mUserData, &gWiFiSession->mUserData, 0x40);
    } else {
        DWC_CreateUserData(&gWiFiSession->mUserData, 0x414d434a);
    }
    CopyBuddyFriendDataList(&gWiFiSession->mBuddies[0]);
    DWC_InitInet(&gWiFiSession->mLogin);
    DWC_SetAuthServer(2);
    DWC_ConnectInetAsync();
    buddyIndex = 0;
    if (DWC_GetNumFriend(&gWiFiSession->mBuddies[0], 0x3c) > 0) {
        do {
            buddyIndex++;
        } while (buddyIndex < DWC_GetNumFriend(&gWiFiSession->mBuddies[0], 0x3c));
    }
    session = gWiFiSession;
    DWC_InitFriendsMatch(&session->mConnection, &session->mUserData, 0x4d6, "mariokartds", "yeJ3x8", 0, 0,
                         &session->mBuddies[0], 0x3c);
    gWiFiSession->mErrorKind = 0;
    gWiFiSession->mErrorCode = 0;
    gWiFiSession->mLogin.mStep = 1;
}

void AdvanceWiFiSessionLoginStep1(void) {
    if (DWC_CheckInet() == 0) {
        DWC_ProcessInet();
        return;
    }
    switch (DWC_GetInetStatus()) {
        case 4:
            DWC_LoginAsync(0, 0, WiFiSessionLoginCallback, 0);
            gWiFiSession->mLogin.mStep = 2;
            break;
        case 7:
            gWiFiSession->mErrorKind = DWC_GetLastError(&gWiFiSession->mErrorCode);
            DWC_ShutdownFriendsMatch();
            DWC_CleanupInet();
            gWiFiSession->mLogin.mStep = 7;
            break;
        case 8:
            break;
    }
}

u32 UpdateWiFiSessionLogin(void) {
    switch (gWiFiSession->mLogin.mStep) {
        case 1:
            AdvanceWiFiSessionLoginStep1();
            break;
        case 3:
            if (gBackupBuffers->mBusy == 0 ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0)
                                           : 1) {
                break;
            }
            DWC_ReportUserData(&gWiFiSession->mUserData);
            if (DWC_UpdateServersAsync(NULL, WiFiSessionBuddySyncCallback, NULL, SetBuddyStatus, NULL,
                                       WiFiSessionEntryMergedCallback, NULL) == 0) {
                gWiFiSession->mLogin.mStep = 7;
            }
            DWC_SetBuddyFriendCallback((void *) BuddyChangedCallback, NULL);
            gWiFiSession->mLogin.mStep = 4;
            break;
        case 6:
            DWC_ShutdownFriendsMatch();
            DWC_CleanupInet();
            gWiFiSession->mLogin.mStep = 7;
            break;
        case 5:
            return 1;
        case 7:
            break;
    }
    return 0;
}

void WiFiSessionLoginCallback(s32 result) {
    if (result == 0) {
        if (DWCi_Acc_IsDirty(&gWiFiSession->mUserData) != 0) {
            DWCi_Acc_ClearDirty(&gWiFiSession->mUserData);
            MI_CpuCopy8(&gWiFiSession->mUserData, &gBackupBuffers->mFirstBlock->mUserData, 0x40);
            WriteBackupFirstBlockWrapper();
        }
        gWiFiSession->mLogin.mStep = 3;
    } else {
        gWiFiSession->mLogin.mStep = 6;
    }
}

void WiFiSessionBuddySyncCallback(s32 result, s32 changed) {
    u8 buddyIndex;

    if (result == 0) {
        if (changed != 0) {
            gWiFiSession->mBuddiesChanged = TRUE;
        }
        buddyIndex = 0;
        if (DWC_GetNumFriend(&gWiFiSession->mBuddies[0], 0x3c) > 0) {
            do {
                DWC_ReportFriendData(&gWiFiSession->mUserData, &gWiFiSession->mBuddies[buddyIndex]);
                buddyIndex++;
            } while (buddyIndex < DWC_GetNumFriend(&gWiFiSession->mBuddies[0], 0x3c));
        }
        gWiFiSession->mLogin.mStep = 5;
    } else {
        DWC_ShutdownFriendsMatch();
        DWC_CleanupInet();
        gWiFiSession->mLogin.mStep = 7;
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
