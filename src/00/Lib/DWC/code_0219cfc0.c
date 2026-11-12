#include "00/Lib/DWC/code_0219cfc0.h"
#include "00/unk_021b5000.h"
#include "00/Lib/DWC/code_0219c3e4.h"
#include "00/code_0219c954.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/code_0219c93c.h"
#include "00/Lib/DWC/code_0219cc00.h"
#include "00/Lib/DWC/code_0219d128.h"
#include "Main/Unknown/code_02152000.h"

#pragma opt_rebuildconditionals off

u32 DWCi_GetFriendBuddyStatus(void *friendData, GpBuddyStatus *status) {
    s32 profileId;
    s32 buddyIndex = 0;
    if (gWiFiBuddySync == NULL || DWCi_CheckLogin() == 0) {
        return 0;
    }
    profileId = DWC_GetGsProfileId(DWCi_GetUserData(), friendData);
    if (profileId > 0 && GpGetBuddyIndex(gWiFiBuddySync->mGpConnection, profileId, &buddyIndex) != 0) {
        return 0;
    }
    if (profileId <= 0 || buddyIndex == -1) {
        return 0;
    }
    if (GpGetBuddyStatus(gWiFiBuddySync->mGpConnection, buddyIndex, status) != 0) {
        return 0;
    }
    return 1;
}

// Maps a GP result 1 to 4 to (kind, code - 0x11558) and calls DWCi_StopFriendProcess; returns the result, 0 passes
// through.
int ReportBuddySyncGpResult(int result) {
    s32 errorKind;
    s32 errorCode;
    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            errorKind = 11;
            errorCode = -1;
            break;
        case 2:
            errorKind = 11;
            errorCode = -2;
            break;
        case 3:
            errorKind = 6;
            errorCode = -10;
            break;
        case 4:
            errorKind = 6;
            errorCode = -20;
            break;
    }
    DWCi_StopFriendProcess(errorKind, errorCode - 0x11558);
    return result;
}

// Maps a GstatsConnect result (1, 2, 3, 5, 7, else 11 / -9) to (kind, code - 0x11940) and calls DWCi_StopFriendProcess;
// returns the result.
int DWCi_HandlePersError(int error) {
    s32 errorKind;
    s32 detail;
    if (error == 0) {
        return 0;
    }
    switch (error) {
        case 1:
            errorKind = 6;
            detail = -50;
            break;
        case 2:
            errorKind = 6;
            detail = -30;
            break;
        case 3:
            errorKind = 6;
            detail = -20;
            break;
        case 5:
            errorKind = 6;
            detail = -40;
            break;
        case 7:
            errorKind = 6;
            detail = -70;
            break;
        default:
            errorKind = 11;
            detail = -9;
            break;
    }
    DWCi_StopFriendProcess(errorKind, detail - 0x11940);
    return error;
}
