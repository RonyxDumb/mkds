#include "00/Lib/GameSpy/presence_api.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_connection.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/callback_queue.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "narrow_string_functions.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/login_connect.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/operation_queue.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/GameSpy/profile_walk.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/wifi_library_globals.h"
#include "scan_text_random.h"
#include "00/Lib/GameSpy/availability_check.h"
#include "tick_counter.h"
#include "00/Lib/GameSpy/profile_find_by_buddy.h"
#include "00/Lib/GameSpy/profile_info_set.h"

u32 gpInitialize(GPConnection *connection, s32 productID, s32 namespaceID) {
    if (gGsiAcResult != 1) {
        return 2;
    }
    if (connection == NULL) {
        return 2;
    }
    return gpiInitialize(connection, productID, namespaceID);
}

void GpDestroy(GPConnection *connection) {
    if (connection != NULL && connection->mGpiConnection != NULL) {
        gpiDestroy(connection);
    }
}

u32 gpProcess(GPConnection *connection) {
    GPIConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    return gpiProcess(connection, 0);
}

u32 GpSetCallback(GPConnection *connection, s32 func, void (*callback)(void *connection, void *func, u32 callback),
                  u32 param) {
    GPIConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (func < 0 || func >= 6) {
        gpiSetErrorString(connection, "Invalid func.");
        return 2;
    }
    gpState->mCallbacks[func].mCallback = callback;
    gpState->mCallbacks[func].mParam = param;
    return 0;
}

u32 GpConnectPreAuthenticatedA(GPConnection *connection, s8 *authtoken, s8 *partnerchallenge, s32 firewall,
                               s32 blocking, ConnectCallback callback, u32 param) {
    GPIConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (authtoken == NULL || *authtoken == 0) {
        return 2;
    }
    if (partnerchallenge == NULL || *partnerchallenge == 0) {
        return 2;
    }
    if (callback == NULL) {
        gpiSetErrorString(connection, "No callback.");
        return 2;
    }
    if (gpState->mSimulation != 0) {
        ConnectReply arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    return GpiStartConnect(connection, "", "", "",
                           "", authtoken, partnerchallenge, NULL, firewall, 0, blocking,
                           (GPCallback) callback, param);
}

void gpDisconnect(GPConnection *connection) {
    if (connection != NULL && connection->mGpiConnection != NULL && connection->mGpiConnection->mSimulation == 0) {
        gpiDisconnect(connection, 1);
        gpiReset(connection);
    }
}

u32 GpProfileSearchA(GPConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                     s32 icquin, u32 blocking, ProfileSearchCallback callback, u32 param) {
    GPIConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (callback == NULL) {
        gpiSetErrorString(connection, "No callback.");
        return 2;
    }
    if (gpState->mSimulation != 0) {
        ProfileSearchReply arg = {0};
        arg.mMore = PROFILE_SEARCH_MORE_DONE;
        callback(connection, &arg, param);
        return 0;
    }
    return gpiProfileSearch(connection, nick, uniquenick, email, firstname, lastname, icquin, 0, blocking,
                                (GPCallback) callback, param);
}

u32 GpGetInfo(GPConnection *connection, u32 profile, s32 checkCache, u32 blocking, GetInfoCallback callback, u32 param) {
    GPIConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL || profile == 0) {
        return 2;
    }
    if (callback == NULL) {
        gpiSetErrorString(connection, "No callback.");
        return 2;
    }
    if (gpState->mSimulation != 0) {
        GetInfoReply arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        gpiSetErrorString(connection, "The connection has already been disconnected.");
        return 2;
    }
    return gpiGetInfo(connection, profile, checkCache, blocking, (GPCallback) callback, param);
}

u32 GpSetInfosA(GPConnection *connection, s32 info, const s8 *value) {
    GPIConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        gpiSetErrorString(connection, "The connection has already been disconnected.");
        return 2;
    }
    return gpiSetInfos(connection, info, value);
}

u32 gpSendBuddyRequestA(GPConnection *connection, u32 profile, const char *reason) {
    GPIConnection *gpState;
    char reasonCopy[0x401];
    s8 *cursor;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        gpiSetErrorString(connection, "The connection has already been disconnected.");
        return 2;
    }
    if (reason == NULL) {
        gpiSetErrorString(connection, "Invalid reason.");
        return 2;
    }
    CopyStringWithTerminator(reasonCopy, reason, 0x401);
    if (*(s8 *) reasonCopy != 0) {
        cursor = (s8 *) reasonCopy;
        do {
            if (*cursor == 0x5c) {
                *cursor = 0x2f;
            }
            cursor++;
        } while (*cursor != 0);
    }
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\addbuddy\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\sesskey\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\newprofileid\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, profile);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\reason\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, reasonCopy);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\final\\");
    return 0;
}

u32 GpAuthBuddyRequest(GPConnection *connection, u32 profile) {
    GPIConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        gpiSetErrorString(connection, "The connection has already been disconnected.");
        return 2;
    }
    return gpiAuthBuddyRequest(connection, profile);
}

u32 GpDenyBuddyRequest(GPConnection *connection, int profile) {
    int found;
    int canFree;
    GPIConnection *gpState;
    GPIProfile *profileEntry;
    if ((connection == NULL) || (gpState = connection->mGpiConnection, gpState == NULL)) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        gpiSetErrorString(connection, "The connection has already been disconnected.");
        return 2;
    }
    found = gpiGetProfile(connection, profile, &profileEntry);
    if (found == 0) {
        return 0;
    }
    profileEntry->mRequestCount = profileEntry->mRequestCount + -1;
    if ((gpState->mInfoCaching == 0) && (profileEntry->mRequestCount <= 0)) {
        DWCi_GsFree(profileEntry->mAuthSig);
        profileEntry->mAuthSig = NULL;
        canFree = gpiCanFreeProfile(profileEntry);
        if (canFree != 0) {
            gpiRemoveProfile(connection, profileEntry);
        }
    }
    return 0;
}

s32 gpGetNumBuddies(GPConnection *connection, s32 *numBuddies) {
    GPIConnection *gpState;
    if (connection == NULL || connection->mGpiConnection == NULL) {
        return 2;
    }
    gpState = connection->mGpiConnection;
    if (gpState->mSimulation != 0) {
        *numBuddies = 0;
        return 0;
    }
    *numBuddies = gpState->mBuddyCount;
    return 0;
}

u32 gpGetBuddyStatus(GPConnection *connection, s32 index, GpBuddyStatus *status) {
    GPIConnection *gpState;
    GPIProfile *profileEntry;
    GPIBuddyStatus *buddyInfo;
    void *string;
    s32 num;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        memset(status, 0, sizeof(*status));
        return 0;
    }
    if (status == NULL) {
        gpiSetErrorString(connection, "Invalid status.");
        return 2;
    }
    num = gpState->mBuddyCount;
    if (index < 0 || index >= num) {
        gpiSetErrorString(connection, "Invalid index.");
        return 2;
    }
    profileEntry = gpiFindBuddy(connection, index);
    if (profileEntry == NULL) {
        gpiSetErrorString(connection, "Invalid index.");
        return 2;
    }
    buddyInfo = profileEntry->mBuddyStatus;
    if (buddyInfo == NULL) {
        AssertionFailed("buddyStatus", "gp.c", NULL, 0x5cf);
    }
    status->mProfileId = profileEntry->mProfileId;
    status->mStatus = buddyInfo->mStatus;
    string = buddyInfo->mStatusString;
    if (string != NULL) {
        CopyStringWithTerminator(status->mStatusString, string, 0x100);
    } else {
        *(u8 *) string = 0;
    }
    string = buddyInfo->mLocationString;
    if (string != NULL) {
        CopyStringWithTerminator(status->mLocationString, string, 0x100);
    } else {
        *(u8 *) string = 0;
    }
    status->mIp = buddyInfo->mIp;
    status->mPort = buddyInfo->mPort;
    return 0;
}

u32 gpGetBuddyIndex(GPConnection *connection, u32 profile, s32 *index) {
    GPIConnection *gpState;
    GPIProfile *profileEntry;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        *index = 0;
        return 0;
    }
    if (gpiGetProfile(connection, profile, &profileEntry) != 0 && profileEntry->mBuddyStatus != NULL) {
        *index = profileEntry->mBuddyStatus->mIndex;
    } else {
        *index = -1;
    }
    return 0;
}

u32 gpIsBuddy(GPConnection *connection, u32 profile) {
    int found;
    GPIProfile *pProfile[1];
    if ((connection == NULL) || (connection->mGpiConnection == NULL)) {
        return 0;
    }
    if (connection->mGpiConnection->mSimulation != 0) {
        return 0;
    }
    found = gpiGetProfile(connection, profile, pProfile);
    if ((found != 0) && (pProfile[0]->mBuddyStatus != NULL)) {
        return 1;
    }
    return 0;
}

u32 GpDeleteBuddy(GPConnection *connection, u32 profile) {
    GPIConnection *gpState;
    u32 result;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        gpiSetErrorString(connection, "The connection has already been disconnected.");
        return 2;
    }
    result = gpiDeleteBuddy(connection, profile);
    if (result == 0) {
        return 0;
    }
    return result;
}

u32 gpSetStatusA(GPConnection *connection, s32 status, const char *statusString, const char *locationString) {
    GPIConnection *gpState;
    char statusCopy[0x100];
    char locationCopy[0x100];
    s8 *cursor;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        gpiSetErrorString(connection, "The connection has already been disconnected.");
        return 2;
    }
    if (statusString == NULL) {
        gpiSetErrorString(connection, "Invalid statusString.");
        return 2;
    }
    if (locationString == NULL) {
        gpiSetErrorString(connection, "Invalid locationString.");
        return 2;
    }
    CopyStringWithTerminator(statusCopy, statusString, 0x100);
    if (*(s8 *) statusCopy != 0) {
        cursor = (s8 *) statusCopy;
        do {
            if (*cursor == 0x5c) {
                *cursor = 0x2f;
            }
            cursor++;
        } while (*cursor != 0);
    }
    CopyStringWithTerminator(locationCopy, locationString, 0x100);
    if (*(s8 *) locationCopy != 0) {
        cursor = (s8 *) locationCopy;
        do {
            if (*cursor == 0x5c) {
                *cursor = 0x2f;
            }
            cursor++;
        } while (*cursor != 0);
    }
    if (status == gpState->mStatus && strcmp(statusCopy, gpState->mStatusString) == 0 &&
        strcmp(locationCopy, gpState->mLocationString) == 0) {
        return 0;
    }
    gpState->mStatus = status;
    CopyStringWithTerminator(gpState->mStatusString, statusCopy, 0x100);
    CopyStringWithTerminator(gpState->mLocationString, locationCopy, 0x100);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\status\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, status);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\sesskey\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\statstring\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, statusCopy);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\locstring\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, locationCopy);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\final\\");
    return 0;
}

u32 gpSendBuddyMessageA(GPConnection *connection, s32 profile, const char *message) {
    GPIConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        gpiSetErrorString(connection, "The connection has already been disconnected.");
        return 2;
    }
    if (message == NULL) {
        gpiSetErrorString(connection, "Invalid message.");
        return 2;
    }
    return gpiSendBuddyMessage(connection, profile, GPI_BM_MESSAGE, message);
}

static void UnusedLiteralsConnection(GPConnection *connection) {
    gpiSetErrorString(connection, "The connection has already been disconnected.");
    gpiAppendStringToBuffer(connection, &connection->mGpiConnection->mOutputBuffer, "\\sesskey\\");
    gpiAppendStringToBuffer(connection, &connection->mGpiConnection->mOutputBuffer, "\\final\\");
    gpiSetErrorString(connection, "No callback.");
}
