#include "00/Lib/DWC/matching_result_codes.h"
#include "00/Lib/DWC/buddy_status_error.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/login_process.h"
#include "00/Lib/DWC/login_control.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/DWC/login_state.h"
#include "00/Lib/DWC/buddy_request_callbacks.h"
#include "00/Lib/DWC/buddy_friends.h"

#pragma opt_rebuildconditionals off

u32 DWCi_GetFriendBuddyStatus(void *friendData, GpBuddyStatus *status) {
    s32 profileId;
    s32 buddyIndex = 0;
    if (gWiFiBuddySync == NULL || DWCi_CheckLogin() == 0) {
        return 0;
    }
    profileId = DWC_GetGsProfileId(DWCi_GetUserData(), friendData);
    if (profileId > 0 && gpGetBuddyIndex(gWiFiBuddySync->mGpConnection, profileId, &buddyIndex) != 0) {
        return 0;
    }
    if (profileId <= 0 || buddyIndex == -1) {
        return 0;
    }
    if (gpGetBuddyStatus(gWiFiBuddySync->mGpConnection, buddyIndex, status) != 0) {
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
        case GP_MEMORY_ERROR:
            errorKind = 11;
            errorCode = -1;
            break;
        case GP_PARAMETER_ERROR:
            errorKind = 11;
            errorCode = -2;
            break;
        case GP_NETWORK_ERROR:
            errorKind = 6;
            errorCode = -10;
            break;
        case GP_SERVER_ERROR:
            errorKind = 6;
            errorCode = -20;
            break;
    }
    DWCi_StopFriendProcess(errorKind, errorCode - 0x11558);
    return result;
}

// Maps a InitStatsConnection result (1, 2, 3, 5, 7, else 11 / -9) to (kind, code - 0x11940) and calls DWCi_StopFriendProcess;
// returns the result.
int DWCi_HandlePersError(int error) {
    s32 errorKind;
    s32 errorCode;
    if (error == 0) {
        return 0;
    }
    switch (error) {
        case GE_NOSOCKET:
            errorKind = 6;
            errorCode = -50;
            break;
        case GE_NODNS:
            errorKind = 6;
            errorCode = -30;
            break;
        case GE_NOCONNECT:
            errorKind = 6;
            errorCode = -20;
            break;
        case GE_DATAERROR:
            errorKind = 6;
            errorCode = -40;
            break;
        case GE_TIMEDOUT:
            errorKind = 6;
            errorCode = -70;
            break;
        default:
            errorKind = 11;
            errorCode = -9;
            break;
    }
    DWCi_StopFriendProcess(errorKind, errorCode - 0x11940);
    return error;
}
