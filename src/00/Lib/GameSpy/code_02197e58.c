#include "00/Lib/GameSpy/code_02197e58.h"

#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/Lib/GameSpy/gt2Socket.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_0218dd8c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/Lib/GameSpy/code_02198a8c.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/unk_021b3000.h"

void gti2CloseConnection(Gt2Connection *connection, int hard) {
    if (hard != 0) {
        if (connection->mState < GT2_CONNECTION_CLOSED) {
            gti2ConnectionClosed(connection);
            gti2SendClosed(connection);
            gti2ClosedCallback(connection, NULL);
            gti2FreeSocketConnection(connection);
        }
    } else {
        connection->mState = GT2_CONNECTION_CLOSING;
        gti2SendClose(connection);
    }
}

void gti2ConnectionClosed(Gt2Connection *connection, ...) {
    if (connection->mState != GT2_CONNECTION_CLOSED) {
        connection->mState = GT2_CONNECTION_CLOSED;
        HashtableRemove(connection->mSocket->mConnections, &connection);
        DarrayAppend(connection->mSocket->mConnectionsToFree, &connection);
    }
}

void gti2ConnectionCleanup(Gt2Connection *connection) {
    if (connection->mInitialMessage.mData != NULL) {
        DWCi_GsFree(connection->mInitialMessage.mData);
    }
    if (connection->mIncomingBuffer.mData != NULL) {
        DWCi_GsFree(connection->mIncomingBuffer.mData);
    }
    if (connection->mSendBuffer.mData != NULL) {
        DWCi_GsFree(connection->mSendBuffer.mData);
    }
    if (connection->mIncomingBufferMessages != NULL) {
        DarrayDelete(connection->mIncomingBufferMessages);
    }
    if (connection->mOutgoingBufferMessages != NULL) {
        DarrayDelete(connection->mOutgoingBufferMessages);
    }
    if (connection->mSendFilters != NULL) {
        DarrayDelete(connection->mSendFilters);
    }
    if (connection->mReceiveFilters != NULL) {
        DarrayDelete(connection->mReceiveFilters);
    }
    DWCi_GsFree(connection);
}

BOOL gti2SocketErrorCallback(Gt2Socket *socket) {
    if (socket == NULL) {
        AssertionFailed("socket", "gt2Callback.c", NULL, 0x1b);
    }
    if (socket == NULL) {
        return TRUE;
    }
    if (socket->mSocketErrorCallback == NULL) {
        return TRUE;
    }
    socket->mRunningCallbackCount++;
    socket->mSocketErrorCallback(socket);
    socket->mRunningCallbackCount--;
    if (socket->mDeletePending != FALSE && socket->mRunningCallbackCount == 0) {
        DeleteSocket(socket);
        return FALSE;
    }
    return TRUE;
}

BOOL CallIncomingConnectionCallback(Gt2Socket *socket, Gt2Connection *connection, int address, int port, int latency,
                                    const u8 *message, int len) {
    if (socket == NULL || connection == NULL) {
        AssertionFailed("socket && connection", "gt2Callback.c", NULL, 0x3d);
    }
    if (socket == NULL || connection == NULL) {
        return TRUE;
    }
    if (socket->mIncomingConnectionCallback == NULL) {
        return TRUE;
    }
    if (len == 0 || message == 0) {
        message = NULL;
        len = 0;
    }
    socket->mRunningCallbackCount++;
    connection->mCallbackLevel++;
    socket->mIncomingConnectionCallback(socket, connection, address, port, latency, message, len);
    socket->mRunningCallbackCount--;
    connection->mCallbackLevel--;
    if (socket->mDeletePending != FALSE && socket->mRunningCallbackCount == 0) {
        DeleteSocket(socket);
        return FALSE;
    }
    return TRUE;
}

BOOL Gt2SetResultAndCallResultCallback(Gt2Connection *connection, int result, void *message, int len) {
    if (connection == NULL) {
        AssertionFailed("connection", "gt2Callback.c", NULL, 0x69);
    }
    if (connection == NULL) {
        return TRUE;
    }
    connection->mResult = result;
    if (connection->mCallbacks.mResultCallback == NULL) {
        return TRUE;
    }
    if (len == 0 || message == NULL) {
        message = NULL;
        len = 0;
    }
    connection->mCallbackLevel++;
    connection->mSocket->mRunningCallbackCount++;
    connection->mCallbacks.mResultCallback(connection, result, message, len);
    connection->mCallbackLevel--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != FALSE && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL Gt2CallDataCallback(Gt2Connection *connection, void *message, int len, int reliable) {
    if (connection == NULL) {
        AssertionFailed("connection", "gt2Callback.c", NULL, 0x94);
    }
    if (connection == NULL) {
        return TRUE;
    }
    if (connection->mCallbacks.mDataCallback == NULL) {
        return TRUE;
    }
    if (len == 0 || message == NULL) {
        message = NULL;
        len = 0;
    }
    connection->mCallbackLevel++;
    connection->mSocket->mRunningCallbackCount++;
    connection->mCallbacks.mDataCallback(connection, message, len, reliable);
    connection->mCallbackLevel--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != FALSE && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL gti2ClosedCallback(Gt2Connection *connection, void *reason) {
    if (connection == NULL) {
        AssertionFailed("connection", "gt2Callback.c", NULL, 0xba);
    }
    if (connection == NULL) {
        return TRUE;
    }
    if (connection->mCallbacks.mClosedCallback == NULL) {
        return TRUE;
    }
    connection->mCallbackLevel++;
    connection->mSocket->mRunningCallbackCount++;
    connection->mCallbacks.mClosedCallback(connection, reason);
    connection->mCallbackLevel--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != FALSE && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL Gt2CallElapsedTimeCallback(Gt2Connection *connection, s32 latency) {
    if (connection == NULL) {
        AssertionFailed("connection", "gt2Callback.c", NULL, 0xd9);
    }
    if (connection == NULL) {
        return TRUE;
    }
    if (connection->mCallbacks.mElapsedTimeCallback == NULL) {
        return TRUE;
    }
    connection->mCallbackLevel++;
    connection->mSocket->mRunningCallbackCount++;
    connection->mCallbacks.mElapsedTimeCallback(connection, latency);
    connection->mCallbackLevel--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != FALSE && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL gti2SendFilterCallback(Gt2Connection *connection, s32 filterId, s32 message, void *len, s32 reliable) {
    Gt2Filter *filter;
    if (connection == NULL) {
        AssertionFailed("connection", "gt2Callback.c", NULL, 0x101);
    }
    if (connection == NULL) {
        return TRUE;
    }
    filter = DarrayGetElement(connection->mSendFilters, filterId);
    if (filter == NULL) {
        return TRUE;
    }
    if (len == NULL || message == 0) {
        message = 0;
        len = NULL;
    }
    connection->mCallbackLevel++;
    connection->mSocket->mRunningCallbackCount++;
    filter->mCallback(connection, filterId, message, len, reliable);
    connection->mCallbackLevel--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != FALSE && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

BOOL gti2ReceiveFilterCallback(Gt2Connection *connection, s32 filterId, void *message, s32 len, s32 reliable) {
    Gt2Filter *filter;
    if (connection == NULL) {
        AssertionFailed("connection", "gt2Callback.c", NULL, 0x12d);
    }
    if (connection == NULL) {
        return TRUE;
    }
    filter = DarrayGetElement(connection->mReceiveFilters, filterId);
    if (filter == NULL) {
        return TRUE;
    }
    if (len == 0 || message == NULL) {
        message = NULL;
        len = 0;
    }
    connection->mCallbackLevel++;
    connection->mSocket->mRunningCallbackCount++;
    filter->mCallback(connection, filterId, message, len, reliable);
    connection->mCallbackLevel--;
    connection->mSocket->mRunningCallbackCount--;
    if (connection->mSocket->mDeletePending != FALSE && connection->mSocket->mRunningCallbackCount == 0) {
        DeleteSocket(connection->mSocket);
        return FALSE;
    }
    return TRUE;
}

u32 gti2DumpCallback(Gt2Socket *socket, Gt2Connection *connection, u32 address, u32 port, u32 reset, int message,
                     int len, int send) {
    UnkWordFunc *callback;
    if (socket == NULL) {
        AssertionFailed("socket", "gt2Callback.c", NULL, 0x160);
    }
    if (socket == NULL) {
        return 1;
    }
    if (send != 0) {
        callback = socket->mSentCallback;
    } else {
        callback = socket->mReceiveDumpCallback;
    }
    if (callback == NULL) {
        return 1;
    }
    if (len == 0 || message == 0) {
        message = 0;
        len = 0;
    }
    socket->mRunningCallbackCount++;
    if (connection != NULL) {
        connection->mCallbackLevel++;
    }
    callback(socket, connection, address, port, reset, message, len);
    socket->mRunningCallbackCount--;
    if (connection != NULL) {
        connection->mCallbackLevel--;
    }
    if (socket->mDeletePending != FALSE && socket->mRunningCallbackCount == 0) {
        DeleteSocket(socket);
        return 0;
    }
    return 1;
}

BOOL CallUnmatchedDataCallback(Gt2Socket *socket, s32 address, s32 port, void *message, s32 len, s32 *handled) {
    *handled = 0;
    if (socket == NULL) {
        AssertionFailed("socket", "gt2Callback.c", NULL, 0x197);
    }
    if (socket == NULL) {
        return TRUE;
    }
    if (socket->mUnmatchedDataCallback == NULL) {
        return TRUE;
    }
    if (len == 0 || message == NULL) {
        message = NULL;
        len = 0;
    }
    socket->mRunningCallbackCount++;
    *handled = socket->mUnmatchedDataCallback(socket, address, port, message, len);
    socket->mRunningCallbackCount--;
    if (socket->mDeletePending != FALSE && socket->mRunningCallbackCount == 0) {
        DeleteSocket(socket);
        return FALSE;
    }
    return TRUE;
}
