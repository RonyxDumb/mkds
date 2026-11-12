#include "00/gt2Connection.h"
#include "00/code_02197b34.h"
#include "00/code_02198d04.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a61c.h"
#include "00/code_021a3690.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218d818.h"
#include "00/code_02197e58.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/code_02198a8c.h"

int gti2NewOutgoingConnection(void *socket, Gt2Connection **connection, int address, u32 port) {
    int result = gti2NewSocketConnection(socket, connection, address, port);
    if (result != 0) {
        return result;
    }
    (*connection)->mState = 0;
    (*connection)->mInitiated = TRUE;
    return 0;
}

int gti2NewIncomingConnection(void *socket, Gt2Connection **connection, int address, u32 port) {
    int result = gti2NewSocketConnection(socket, connection, address, port);
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
        connection->mInitialMessage.mData = DWCi_GsMalloc(len);
        if (connection->mInitialMessage.mData == NULL) {
            return TRUE;
        }
        memcpy(connection->mInitialMessage.mData, message, len);
        connection->mInitialMessage.mSize = len;
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

u32 SendConnectionBytes(Gt2Connection *a, u8 *b, u32 c) {
    int v1;
    u32 v2;
    v1 = gti2SocketSend((u32 *) a->mSocket, a->mAddress, a->mPort, (u32) b, c);
    if (v1 == 0) {
        return 0;
    }
    v2 = GetElapsedMilliseconds();
    a->mLastSendTime = v2;
    return 1;
}

BOOL gti2CheckTimeout(Gt2Connection *connection, u32 now) {
    if (connection->mState < 5) {
        BOOL hasExpired = FALSE;
        if (connection->mInitiated != FALSE) {
            if (connection->mTimeSinceCreateLimit != 0 &&
                now - connection->mCreateTime > connection->mTimeSinceCreateLimit) {
                hasExpired = TRUE;
            }
        } else if (connection->mState < 4) {
            if (now - connection->mCreateTime > 60000) {
                hasExpired = TRUE;
            }
        }
        if (hasExpired != FALSE) {
            gti2SendClosed(connection);
            gti2ConnectionClosed(connection);
            if (Gt2SetResultAndCallResultCallback(connection, 6, NULL, 0) == 0) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

BOOL gti2SendRetries(Gt2Connection *connection, u32 now) {
    int len;
    int index;
    GTI2OutgoingBufferMessage *message;
    len = DarrayGetCount((u32 *) connection->mOutgoingBufferMessages);
    for (index = 0; index < len; index++) {
        message = DarrayGetElement(connection->mOutgoingBufferMessages, index);
        if (now - message->mLastSend > 1000) {
            if (gti2ResendMessage(connection, message) == 0) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

BOOL gti2CheckPendingAck(Gt2Connection *connection, u32 now) {
    if (connection->mPendingAck == 0) {
        return TRUE;
    }
    if (now - connection->mPendingAckTime > 100) {
        if (gti2SendAck(connection) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

BOOL gti2CheckKeepAlive(Gt2Connection *connection, u32 now) {
    if (now - connection->mLastSendTime > 30000) {
        if (gti2SendKeepAlive(connection) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

u32 gti2ConnectionThink(Gt2Connection *connection, u32 now) {
    int result;
    result = gti2CheckTimeout(connection, now);
    if (result == 0) {
        return 0;
    }
    result = gti2CheckKeepAlive(connection, now);
    if (result == 0) {
        return 0;
    }
    result = gti2SendRetries(connection, now);
    if (result == 0) {
        return 0;
    }
    result = gti2CheckPendingAck(connection, now);
    if (result != 0) {
        return 1;
    }
    return 0;
}
