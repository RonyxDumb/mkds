#include "00/Lib/GameSpy/connection_lifecycle.h"
#include "00/Lib/GameSpy/challenge_response.h"
#include "00/Lib/GameSpy/protocol_messages.h"
#include "00/Lib/GameSpy/socket_connections.h"
#include "00/Lib/GameSpy/message_check.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/connection_events.h"
#include "00/Lib/DWC/connection_error_strings.h"

int gti2NewOutgoingConnection(void *socket, Gt2Connection **connection, int address, u32 port) {
    int result = gti2NewSocketConnection(socket, connection, address, port);
    if (result != 0) {
        return result;
    }
    (*connection)->mState = GT2_CONNECTION_OFFER_SENT;
    (*connection)->mInitiated = TRUE;
    return 0;
}

int gti2NewIncomingConnection(void *socket, Gt2Connection **connection, int address, u32 port) {
    int result = gti2NewSocketConnection(socket, connection, address, port);
    if (result != 0) {
        return result;
    }
    (*connection)->mState = GT2_CONNECTION_AWAIT_OFFER;
    (*connection)->mInitiated = FALSE;
    return 0;
}

BOOL gti2StartConnectionAttempt(Gt2Connection *connection, void *message, int len, Gt2ConnectionCallbacks *callbacks) {
    u8 challengeBytes[0x24];
    gti2MessageCheck((const char **) &message, &len);
    if (len > 0) {
        connection->mInitialMessageData = DWCi_GsMalloc(len);
        if (connection->mInitialMessageData == NULL) {
            return TRUE;
        }
        memcpy(connection->mInitialMessageData, message, len);
        connection->mInitialMessageSize = len;
    }
    if (callbacks != NULL) {
        connection->mCallbacks = *callbacks;
    }
    gti2GetChallenge(challengeBytes);
    gti2GetResponse(connection->mResponse, challengeBytes);
    gti2SendClientChallenge(connection, challengeBytes);
    connection->mState = GT2_CONNECTION_OFFER_SENT;
    return FALSE;
}

BOOL gti2AcceptConnection(Gt2Connection *connection, Gt2ConnectionCallbacks *callbacks) {
    if (connection->mFreeAtAcceptReject != FALSE) {
        connection->mFreeAtAcceptReject = FALSE;
        return FALSE;
    }
    connection->mFreeAtAcceptReject = FALSE;
    if (connection->mState != GT2_CONNECTION_AWAIT_DECISION) {
        return FALSE;
    }
    gti2SendAccept(connection);
    connection->mState = GT2_CONNECTION_CONNECTED;
    if (callbacks != NULL) {
        connection->mCallbacks = *callbacks;
    }
    return TRUE;
}

void gti2RejectConnection(Gt2Connection *connection, void *message, u32 len, ...) {
    connection->mFreeAtAcceptReject = FALSE;
    if (connection->mState == GT2_CONNECTION_AWAIT_DECISION) {
        gti2MessageCheck((const char **) &message, (s32 *) &len);
        gti2SendReject(connection, message, len);
        connection->mState = GT2_CONNECTION_CLOSING;
    }
}

u32 gti2ConnectionSendData(Gt2Connection *connection, u8 *data, u32 length) {
    int sendResult;
    u32 elapsedMilliseconds;
    sendResult = gti2SocketSend(connection->mSocket, connection->mAddress, connection->mPort,
                                (u32) data, length);
    if (sendResult == 0) {
        return 0;
    }
    elapsedMilliseconds = current_time();
    connection->mLastSendTime = elapsedMilliseconds;
    return 1;
}

BOOL gti2CheckTimeout(Gt2Connection *connection, u32 now) {
    if (connection->mState < GT2_CONNECTION_CONNECTED) {
        BOOL hasExpired = FALSE;
        if (connection->mInitiated != FALSE) {
            if (connection->mTimeSinceCreateLimit != 0 &&
                now - connection->mCreateTime > connection->mTimeSinceCreateLimit) {
                hasExpired = TRUE;
            }
        } else if (connection->mState < GT2_CONNECTION_AWAIT_DECISION) {
            if (now - connection->mCreateTime > GTI2_SERVER_TIMEOUT) {
                hasExpired = TRUE;
            }
        }
        if (hasExpired != FALSE) {
            gti2SendClosed(connection);
            gti2ConnectionClosed(connection);
            if (gti2ConnectedCallback(connection, 6, NULL, 0) == 0) {
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
    len = ArrayLength(connection->mOutgoingBufferMessages);
    for (index = 0; index < len; index++) {
        message = ArrayNth(connection->mOutgoingBufferMessages, index);
        if (now - message->mLastSend > GTI2_RESEND_TIME) {
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
    if (now - connection->mPendingAckTime > GTI2_PENDING_ACK_TIME) {
        if (gti2SendAck(connection) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

BOOL gti2CheckKeepAlive(Gt2Connection *connection, u32 now) {
    if (now - connection->mLastSendTime > GTI2_KEEP_ALIVE_TIME) {
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
