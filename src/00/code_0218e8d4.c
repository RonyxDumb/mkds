#include "00/code_0218e8d4.h"
#include "00/code_02194000.h"

#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_0218d818.h"
#include "00/code_0218e2dc.h"
#include "00/code_021965a0.h"
#include "00/code_02190ff8.h"
#include "00/code_02196000.h"
#include "00/code_021906e4.h"
#include "00/code_02196590.h"
#include "00/code_02196594.h"
#include "00/unk_021b23b0.h"
#include "code_0200f5ac.h"
#include "00/code_021947e4.h"
#include "00/code_0218f15c.h"
#include "00/code_02194808.h"
#include "00/code_021948f8.h"
#include "string.h"
#include "00/code_0219218c.h"
#include "00/code_02193000.h"
#include "00/unk_021b3000.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"
#include "00/code_02192d64.h"

void GpDisconnect(GpConnection *connection) {
    if (connection != NULL && connection->mGpiConnection != NULL && connection->mGpiConnection->mSimulation == 0) {
        GpiCloseConnection(connection, 1);
        GpiResetConnection(connection);
    }
}

u32 GpProfileSearchA(GpConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                     s32 icquin, u32 blocking, GpProfileSearchCb callback, u32 param) {
    GpiConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (callback == NULL) {
        GpiSetErrorMessage(connection, gNoCallbackErrorString);
        return 2;
    }
    if (gpState->mSimulation != 0) {
        ProfileSearchReply arg = {0};
        arg.mMore = 0x601;
        callback(connection, &arg, param);
        return 0;
    }
    return gpiProfileSearch(connection, nick, uniquenick, email, firstname, lastname, icquin, 0, blocking,
                                (u32) callback, param);
}

u32 GpGetInfo(GpConnection *connection, u32 profile, s32 checkCache, u32 blocking, GpGetInfoCb callback, u32 param) {
    GpiConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL || profile == 0) {
        return 2;
    }
    if (callback == NULL) {
        GpiSetErrorMessage(connection, gNoCallbackErrorString);
        return 2;
    }
    if (gpState->mSimulation != 0) {
        GetInfoReply arg = {0};
        callback(connection, &arg, param);
        return 0;
    }
    if (gpState->mConnectState == 4) {
        GpiSetErrorMessage(connection, gConnectionDisconnectedErrorString);
        return 2;
    }
    return gpiGetInfo(connection, profile, checkCache, blocking, (u32) callback, param);
}

u32 GpSetInfosA(GpConnection *connection, s32 info, const s8 *value) {
    GpiConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == 4) {
        GpiSetErrorMessage(connection, gConnectionDisconnectedErrorString);
        return 2;
    }
    return gpiSetInfos(connection, info, value);
}

u32 GpWriteAddbuddy(GpConnection *connection, u32 profile, const char *reason) {
    GpiConnection *gpState;
    char reasonCopy[0x401];
    s8 *cursor;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == 4) {
        GpiSetErrorMessage(connection, gConnectionDisconnectedErrorString);
        return 2;
    }
    if (reason == NULL) {
        GpiSetErrorMessage(connection, gInvalidReasonErrorString);
        return 2;
    }
    GpiCopyString(reasonCopy, reason, 0x401);
    if (*(s8 *) reasonCopy != 0) {
        cursor = (s8 *) reasonCopy;
        do {
            if (*cursor == 0x5c) {
                *cursor = 0x2f;
            }
            cursor++;
        } while (*cursor != 0);
    }
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gAddbuddyKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gSesskeyKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gNewprofileidKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, profile);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gReasonKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, reasonCopy);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gFinalKey);
    return 0;
}

u32 GpAuthBuddyRequest(GpConnection *connection, u32 profile) {
    GpiConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == 4) {
        GpiSetErrorMessage(connection, gConnectionDisconnectedErrorString);
        return 2;
    }
    return gpiAuthBuddyRequest(connection, profile);
}

u32 GpDenyBuddyRequest(GpConnection *connection, int profile) {
    int found;
    int canFree;
    GpiConnection *gpState;
    GpiProfile *profileEntry;
    if ((connection == NULL) || (gpState = connection->mGpiConnection, gpState == NULL)) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == 4) {
        GpiSetErrorMessage(connection, gConnectionDisconnectedErrorString);
        return 2;
    }
    found = GpiFindProfile(connection, profile, &profileEntry);
    if (found == 0) {
        return 0;
    }
    profileEntry->mRequestCount = profileEntry->mRequestCount + -1;
    if ((gpState->mInfoCaching == 0) && (profileEntry->mRequestCount <= 0)) {
        DWCi_GsFree(profileEntry->mAuthSig);
        profileEntry->mAuthSig = NULL;
        canFree = GpiIsProfileEmpty(profileEntry);
        if (canFree != 0) {
            GpiRemoveProfile(connection, profileEntry);
        }
    }
    return 0;
}

s32 GpGetBuddyCount(GpConnection *object, s32 *output) {
    GpiConnection *state;
    if (object == NULL || object->mGpiConnection == NULL) {
        return 2;
    }
    state = object->mGpiConnection;
    if (state->mSimulation != 0) {
        *output = 0;
        return 0;
    }
    *output = state->mBuddyCount;
    return 0;
}

u32 GpGetBuddyStatus(GpConnection *connection, s32 index, GpBuddyStatus *status) {
    GpiConnection *gpState;
    GpiProfile *profileRec;
    GpiBuddyStatus *buddyInfo;
    void *string;
    s32 num;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        memset(status, 0, 0x210);
        return 0;
    }
    if (status == NULL) {
        GpiSetErrorMessage(connection, gInvalidStatusErrorString);
        return 2;
    }
    num = gpState->mBuddyCount;
    if (index < 0 || index >= num) {
        GpiSetErrorMessage(connection, gInvalidIndexErrorString);
        return 2;
    }
    profileRec = GpiFindProfileByBuddyIndex(connection, index);
    if (profileRec == NULL) {
        GpiSetErrorMessage(connection, gInvalidIndexErrorString);
        return 2;
    }
    buddyInfo = profileRec->mBuddyStatus;
    if (buddyInfo == NULL) {
        AssertionFailed(gBuddyStatusAssertion, gGpFileName, NULL, 0x5cf);
    }
    status->mProfileId = profileRec->mProfileId;
    status->mStatus = buddyInfo->mStatus;
    string = buddyInfo->mStatusString;
    if (string != NULL) {
        GpiCopyString(status->mStatusString, string, 0x100);
    } else {
        *(u8 *) string = 0;
    }
    string = buddyInfo->mLocationString;
    if (string != NULL) {
        GpiCopyString(status->mLocationString, string, 0x100);
    } else {
        *(u8 *) string = 0;
    }
    status->mIp = buddyInfo->mIp;
    status->mPort = buddyInfo->mPort;
    return 0;
}

u32 GpGetBuddyIndex(GpConnection *connection, u32 profile, s32 *index) {
    GpiConnection *gpState;
    GpiProfile *profileEntry;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        *index = 0;
        return 0;
    }
    if (GpiFindProfile(connection, profile, &profileEntry) != 0 && profileEntry->mBuddyStatus != NULL) {
        *index = profileEntry->mBuddyStatus->mIndex;
    } else {
        *index = -1;
    }
    return 0;
}

u32 GpIsBuddy(GpConnection *connection, u32 profile) {
    int found;
    GpiProfile *pProfile[1];
    if ((connection == NULL) || (connection->mGpiConnection == NULL)) {
        return 0;
    }
    if (connection->mGpiConnection->mSimulation != 0) {
        return 0;
    }
    found = GpiFindProfile(connection, profile, pProfile);
    if ((found != 0) && (pProfile[0]->mBuddyStatus != NULL)) {
        return 1;
    }
    return 0;
}

u32 GpDeleteBuddy(GpConnection *connection, u32 profile) {
    GpiConnection *gpState;
    u32 result;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == 4) {
        GpiSetErrorMessage(connection, gConnectionDisconnectedErrorString);
        return 2;
    }
    result = GpiWriteDelbuddyAndRemoveBuddy(connection, profile);
    if (result == 0) {
        return 0;
    }
    return result;
}

u32 GpSetStatus(GpConnection *connection, s32 status, const char *statusString, const char *locationString) {
    GpiConnection *gpState;
    char statusCopy[0x100];
    char locationCopy[0x100];
    s8 *cursor;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == 4) {
        GpiSetErrorMessage(connection, gConnectionDisconnectedErrorString);
        return 2;
    }
    if (statusString == NULL) {
        GpiSetErrorMessage(connection, gInvalidStatusStringErrorString);
        return 2;
    }
    if (locationString == NULL) {
        GpiSetErrorMessage(connection, gInvalidLocationStringErrorString);
        return 2;
    }
    GpiCopyString(statusCopy, statusString, 0x100);
    if (*(s8 *) statusCopy != 0) {
        cursor = (s8 *) statusCopy;
        do {
            if (*cursor == 0x5c) {
                *cursor = 0x2f;
            }
            cursor++;
        } while (*cursor != 0);
    }
    GpiCopyString(locationCopy, locationString, 0x100);
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
    GpiCopyString(gpState->mStatusString, statusCopy, 0x100);
    GpiCopyString(gpState->mLocationString, locationCopy, 0x100);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gStatusKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, status);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gSesskeyKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gStatstringKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, statusCopy);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gLocstringKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, locationCopy);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gFinalKey);
    return 0;
}

u32 GpSendMessage(GpConnection *connection, s32 profileRec, const char *message) {
    GpiConnection *gpState;
    if (connection == NULL || (gpState = connection->mGpiConnection) == NULL) {
        return 2;
    }
    if (gpState->mSimulation != 0) {
        return 0;
    }
    if (gpState->mConnectState == 4) {
        GpiSetErrorMessage(connection, gConnectionDisconnectedErrorString);
        return 2;
    }
    if (message == NULL) {
        GpiSetErrorMessage(connection, gInvalidMessageErrorString);
        return 2;
    }
    return gpiSendBuddyMessage(connection, profileRec, 1, message);
}
