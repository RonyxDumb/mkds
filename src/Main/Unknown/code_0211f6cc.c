#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02120000.h"
#include "Main/Unknown/code_02121000.h"
#include "Main/Unknown/code_02152000.h"
#include "00/code_0219b000.h"
#include "00/code_0219c000.h"
#include "00/code_0219d000.h"
#include "Main/Unknown/code_0211f6b0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02060c38.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "00/code_0218d000.h"
#include "00/code_0219d948.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c384.h"
#include "00/code_021a3000.h"
#include "01/code_021956dc.h"
#include "00/code_0219b580.h"
#include "03/code_021b94b8.h"
#include "00/code_021a3760.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_021522a0.h"

void WiFiRaceSyncReceiveCallback(u32 fromIndex, void *message, u32 size) {
    if (gWiFiSession->mStateMachine.mState != 5) {
        return;
    }
    if (gWiFiSession->mRaceSyncEnabled == FALSE) {
        return;
    }
    if (DoesMessageHeaderMatch(message, size, fromIndex, GetOwnParticipantIndex()) != FALSE) {
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
    ReleaseWiFiConnection();
}

BOOL UpdateWiFiSessionRelease(void) {
    StateMachine *stateMachine;

    if (gWiFiSession->mStateMachine.mState == 0) {
        return 1;
    }
    if (func_ov000_021a377c() == FALSE) {
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

    ReleaseWiFiConnection();
    func_ov000_021a37dc();
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
    func_ov000_021a39c4(&gWiFiSession->mLogin);
    func_ov000_021a397c(2);
    func_ov000_021a3910();
    buddyIndex = 0;
    if (DWC_GetNumFriend(&gWiFiSession->mBuddies[0], 0x3c) > 0) {
        do {
            buddyIndex++;
        } while (buddyIndex < DWC_GetNumFriend(&gWiFiSession->mBuddies[0], 0x3c));
    }
    session = gWiFiSession;
    InitWiFiConnection(&session->mConnection, &session->mUserData, 0x4d6, "mariokartds", "yeJ3x8", 0, 0,
                       &session->mBuddies[0], 0x3c);
    gWiFiSession->mErrorKind = 0;
    gWiFiSession->mErrorCode = 0;
    gWiFiSession->mLogin.mStep = 1;
}

void AdvanceWiFiSessionLoginStep1(void) {
    if (func_ov000_021a38d8() == 0) {
        func_ov000_021a3884();
        return;
    }
    switch (func_ov000_021a3810()) {
        case 4:
            StartWiFiLogin(0, 0, WiFiSessionLoginCallback, 0);
            gWiFiSession->mLogin.mStep = 2;
            break;
        case 7:
            gWiFiSession->mErrorKind = DWC_GetLastError(&gWiFiSession->mErrorCode);
            ReleaseWiFiConnection();
            func_ov000_021a37dc();
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
            if (StartWiFiBuddySync(NULL, WiFiSessionBuddySyncCallback, NULL, SetBuddyStatus, NULL,
                                   WiFiSessionEntryMergedCallback, NULL) == 0) {
                gWiFiSession->mLogin.mStep = 7;
            }
            SetBuddyChangedCallback((void *) BuddyChangedCallback, NULL);
            gWiFiSession->mLogin.mStep = 4;
            break;
        case 6:
            ReleaseWiFiConnection();
            func_ov000_021a37dc();
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
        ReleaseWiFiConnection();
        func_ov000_021a37dc();
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
