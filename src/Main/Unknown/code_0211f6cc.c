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

void func_0211fef4(u32 fromIndex, void *message, u32 size) {
    if (gStruct217D384->field8.mState != 5) {
        return;
    }
    if (gStruct217D384->field1F38 == FALSE) {
        return;
    }
    if (DoesMessageHeaderMatch(message, size, fromIndex, func_ov000_0219bb50()) != FALSE) {
        return;
    }
    func_0205b504(fromIndex, message, size, 0);
}

void func_0211fe44(void) {
    if (gStruct217D384->mBuddiesChanged == FALSE) {
        return;
    }
    CopyWiFiBuddiesToRecordBlock(&gStruct217D384->mBuddies[0]);
    RefreshNotYetBuddyFlags();
    WriteBackupBuddyRecords();
    while (gSaveData->mBusy == 0 ? (gSaveCore->mBackupEnabled != 0 ? gSaveCore->mCommandRunning : 0) : 1) {
    }
    gStruct217D384->mBuddiesChanged = FALSE;
}

void RequestWiFiSessionLogin(void) {
    StateMachine *stateMachine;

    stateMachine = &gStruct217D384->field8;
    stateMachine->mNextState = 1;
    stateMachine->mNextStateRequested = 1;
}

void func_0211fe18(void) {
    ReleaseWiFiConnection();
}

u32 func_0211fda8(void) {
    StateMachine *stateMachine;

    if (gStruct217D384->field8.mState == 0) {
        return 1;
    }
    if (func_ov000_021a377c() == FALSE) {
        return 0;
    }
    ResetWiFiSession();
    stateMachine = &gStruct217D384->field8;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
    return 1;
}

s32 GetWiFiSessionLoginResult(void) {
    switch (gStruct217D384->mLogin.mStep) {
        case 5:
            return 1;
        case 7:
            return -1;
        default:
            return 0;
    }
}

void func_0211fd28(void) {
    StateMachine *stateMachine;

    ReleaseWiFiConnection();
    func_ov000_021a37dc();
    ResetWiFiSession();
    stateMachine = &gStruct217D384->field8;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}

void SetupWiFiSessionLogin(void) {
    u8 i;
    WiFiSession *session;

    MI_CpuFill8(&gStruct217D384->mLogin, 0, 0x10);
    MI_CpuFill8(&gStruct217D384->mUserData, 0, 0x350);
    MI_CpuFill8(&gStruct217D384->mConnection, 0, 0xe24);
    if (CheckUserDataValidConsole() != 0) {
        MI_CpuCopy8(&gSaveData->mFirstBlock->mUserData, &gStruct217D384->mUserData, 0x40);
    } else {
        DWC_CreateUserData((DWCAccUserData *) &gStruct217D384->mUserData, 0x414d434a);
    }
    CopyBuddyFriendDataList(&gStruct217D384->mBuddies[0]);
    func_ov000_021a39c4(&gStruct217D384->mLogin);
    func_ov000_021a397c(2);
    func_ov000_021a3910();
    i = 0;
    if (func_ov000_0219d9b0(&gStruct217D384->mBuddies[0], 0x3c) > 0) {
        do {
            i++;
        } while (i < func_ov000_0219d9b0(&gStruct217D384->mBuddies[0], 0x3c));
    }
    session = gStruct217D384;
    InitWiFiConnection(&session->mConnection, &session->mUserData, 0x4d6, "mariokartds", "yeJ3x8", 0, 0,
                       &session->mBuddies[0], 0x3c);
    gStruct217D384->field1F44 = 0;
    gStruct217D384->field1F48 = 0;
    gStruct217D384->mLogin.mStep = 1;
}

void func_0211fa70(void) {
    if (func_ov000_021a38d8() == 0) {
        func_ov000_021a3884();
        return;
    }
    switch (func_ov000_021a3810()) {
        case 4:
            StartWiFiLogin(0, 0, WiFiSessionLoginCallback, 0);
            gStruct217D384->mLogin.mStep = 2;
            break;
        case 7:
            gStruct217D384->field1F44 = func_ov000_0219c3cc(&gStruct217D384->field1F48);
            ReleaseWiFiConnection();
            func_ov000_021a37dc();
            gStruct217D384->mLogin.mStep = 7;
            break;
        case 8:
            break;
    }
}

u32 UpdateWiFiSessionLogin(void) {
    switch (gStruct217D384->mLogin.mStep) {
        case 1:
            func_0211fa70();
            break;
        case 3:
            if (gSaveData->mBusy == 0 ? (gSaveCore->mBackupEnabled != 0 ? gSaveCore->mCommandRunning : 0)
                                          : 1) {
                break;
            }
            DWC_ReportUserData((DWCAccUserData *) &gStruct217D384->mUserData);
            if (StartWiFiBuddySync(NULL, WiFiSessionBuddySyncCallback, NULL, SetBuddyStatus, NULL, func_0211f6e8,
                                   NULL) == 0) {
                gStruct217D384->mLogin.mStep = 7;
            }
            SetBuddyChangedCallback((void *) BuddyChangedCallback, NULL);
            gStruct217D384->mLogin.mStep = 4;
            break;
        case 6:
            ReleaseWiFiConnection();
            func_ov000_021a37dc();
            gStruct217D384->mLogin.mStep = 7;
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
        if (DWCi_Acc_IsDirty((DWCAccUserData *) &gStruct217D384->mUserData) != 0) {
            DWCi_Acc_ClearDirty((DWCAccUserData *) &gStruct217D384->mUserData);
            MI_CpuCopy8(&gStruct217D384->mUserData, &gSaveData->mFirstBlock->mUserData, 0x40);
            savd_flushNksy();
        }
        gStruct217D384->mLogin.mStep = 3;
    } else {
        gStruct217D384->mLogin.mStep = 6;
    }
}

void WiFiSessionBuddySyncCallback(s32 result, s32 changed) {
    u8 i;

    if (result == 0) {
        if (changed != 0) {
            gStruct217D384->mBuddiesChanged = TRUE;
        }
        i = 0;
        if (func_ov000_0219d9b0(&gStruct217D384->mBuddies[0], 0x3c) > 0) {
            do {
                DWC_ReportFriendData((DWCAccUserData *) &gStruct217D384->mUserData,
                                     (DWCAccFriendData *) &gStruct217D384->mBuddies[i]);
                i++;
            } while (i < func_ov000_0219d9b0(&gStruct217D384->mBuddies[0], 0x3c));
        }
        gStruct217D384->mLogin.mStep = 5;
    } else {
        ReleaseWiFiConnection();
        func_ov000_021a37dc();
        gStruct217D384->mLogin.mStep = 7;
    }
}

void func_0211f6e8(u32 a, u32 b) {
    MergeBuddyRecords(b, a);
    CopyWiFiBuddiesToRecordBlock(&gStruct217D384->mBuddies[0]);
    RefreshNotYetBuddyFlags();
    WriteBackupBuddyRecords();
    while (gSaveData->mBusy == 0 ? (gSaveCore->mBackupEnabled != 0 ? gSaveCore->mCommandRunning : 0) : 1) {
    }
}

void SetBuddyStatus(u32 index, u8 status) {
    gStruct217D384->mBuddyStatuses[index] = status;
}
