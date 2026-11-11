#include "00/code_02198748.h"
#include "00/code_02197b34.h"
#include "00/code_02198d04.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a61c.h"
#include "00/code_021a3690.h"
#include "string.h"
#include "code_02134398.h"

int gti2NewOutgoingConnection(void *socket, Gt2Connection **connection, int address, u32 port) {
    int result = CreateConnection(socket, connection, address, port);
    if (result != 0) {
        return result;
    }
    (*connection)->mState = 0;
    (*connection)->mInitiated = TRUE;
    return 0;
}

int gti2NewIncomingConnection(void *socket, Gt2Connection **connection, int address, u32 port) {
    int result = CreateConnection(socket, connection, address, port);
    if (result != 0) {
        return result;
    }
    (*connection)->mState = 2;
    (*connection)->mInitiated = FALSE;
    return 0;
}

BOOL gti2StartConnectionAttempt(Gt2Connection *connection, void *message, int len, Gt2ConnectionCallbacks *callbacks) {
    s8 challengeBytes[0x24];
    gti2MessageCheck((const char **) &message, &len);
    if (len > 0) {
        connection->mUnk_38.mData = DWCi_GsMalloc(len);
        if (connection->mUnk_38.mData == NULL) {
            return TRUE;
        }
        memcpy(connection->mUnk_38.mData, message, len);
        connection->mUnk_38.mSize = len;
    }
    if (callbacks != NULL) {
        connection->mCallbacks = *callbacks;
    }
    gti2GetChallenge(challengeBytes);
    gti2GetResponse((s8 *) connection->mResponse, challengeBytes);
    gti2SendClientChallenge(connection, challengeBytes);
    connection->mState = 0;
    return FALSE;
}

BOOL gti2AcceptConnection(Gt2Connection *connection, Gt2ConnectionCallbacks *callbacks) {
    if (connection->mFreeAtAcceptReject != FALSE) {
        connection->mFreeAtAcceptReject = FALSE;
        return FALSE;
    }
    connection->mFreeAtAcceptReject = FALSE;
    if (connection->mState != 4) {
        return FALSE;
    }
    gti2SendAccept(connection);
    connection->mState = 5;
    if (callbacks != NULL) {
        connection->mCallbacks = *callbacks;
    }
    return TRUE;
}

void gti2RejectConnection(Gt2Connection *connection, void *message, u32 len, ...) {
    connection->mFreeAtAcceptReject = FALSE;
    if (connection->mState == 4) {
        gti2MessageCheck((const char **) &message, (s32 *) &len);
        gti2SendReject(connection, message, len);
        connection->mState = 6;
    }
}
