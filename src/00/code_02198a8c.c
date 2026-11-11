#include "00/code_02198a8c.h"

#include "00/code_02198714.h"
#include "00/code_02198d04.h"
#include "00/code_0219903c.h"
#include "00/code_0219a000.h"
#include "00/code_0219a01c.h"
#include "00/code_0219a044.h"
#include "00/code_0219a09c.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a3f4.h"
#include "00/code_021988e8.h"
#include "00/code_0219a430.h"
#include "00/unk_021b3000.h"
#include "00/code_02197b34.h"
#include "00/code_02197e58.h"
#include "00/code_02197000.h"
#include "00/code_02197ddc.h"
#include "string.h"
#include "code_02134398.h"

static inline void func_ov000_02198ba8_inline(void *destination, const void *source) {
    u8 *destinationBytes = destination;
    const u8 *sourceBytes = source;
    destinationBytes[0] = sourceBytes[0];
    destinationBytes[1] = sourceBytes[1];
}

BOOL gti2SendAppUnreliable(Gt2Connection *connection, u8 *message, int len) {
    int totalLength;
    u8 *start;
    if (len < 2 || memcmp(message, gGti2MagicString, 2) != 0) {
        if (SendConnectionBytes(connection, message, len) == 0) {
            return FALSE;
        }
        return TRUE;
    }
    totalLength = len + 2;
    if (GetBufferUnusedSize(&connection->mSendBuffer) < totalLength) {
        return TRUE;
    }
    start = connection->mSendBuffer.mData + connection->mSendBuffer.mLength;
    AppendBufferBytes(&connection->mSendBuffer, gGti2MagicString, 2);
    AppendBufferBytes(&connection->mSendBuffer, message, len);
    if (SendConnectionBytes(connection, start, totalLength) == 0) {
        return FALSE;
    }
    RemoveBufferBytes(&connection->mSendBuffer, -1, totalLength);
    return TRUE;
}

BOOL gti2SendAck(Gt2Connection *connection) {
    u8 buffer[3];
    func_ov000_02198ba8_inline(buffer, gGti2MagicString);
    buffer[2] = 0x64;
    func_ov000_0219a01c(buffer, 3, connection->mExpectedSerialNumber);
    if (SendConnectionBytes(connection, buffer, 5) == 0) {
        return FALSE;
    }
    connection->mPendingAck = 0;
    return TRUE;
}

BOOL gti2SendNack(Gt2Connection *connection, u16 firstNumber, u16 lastNumber) {
    u8 buffer[7];
    int pos;
    pos = 0;
    func_ov000_02198ba8_inline(buffer, gGti2MagicString);
    buffer[2] = 0x65;
    func_ov000_0219a01c(buffer, 3, firstNumber);
    pos += 5;
    if (firstNumber != lastNumber) {
        func_ov000_0219a01c(buffer, pos, lastNumber);
        pos += 2;
    }
    if (SendConnectionBytes(connection, buffer, pos) == 0) {
        return FALSE;
    }
    return TRUE;
}

u32 gti2SendPong(u32 connection, u32 message, u32 len) {
    u32 value0 = connection;
    u32 value1 = message;
    u32 value2 = len;
    u32 value3;
    value3 = 103u;
    *(u8 *) ((value1) + 2u) = value3;
    value3 = (u32) &SendConnectionBytes;
    value0 = SendConnectionBytes((Gt2Connection *) value0, (u8 *) value1, value2);
    return value0;
}

int gti2SendClosed(Gt2Connection *connection) {
    return gti2SendClosedOnSocket(connection->mSocket, connection->mAddress, connection->mPort);
}

BOOL gti2SendClosedOnSocket(Gt2Socket *socket, u32 address, int port) {
    u8 buffer[3];

    __memcpy(buffer, gGti2MagicString, 2);
    buffer[2] = 0x68;
    if (func_ov000_0219a110((u32 *) socket, address, port, (u32) buffer, 3) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL gti2ResendMessage(Gt2Connection *connection, Unk02198af4 *message) {
    func_ov000_0219a01c(connection->mSendBuffer.mData, message->mUnk_00 + 5, connection->mExpectedSerialNumber);
    if (SendConnectionBytes(connection, connection->mSendBuffer.mData + message->mUnk_00, message->mUnk_04) == 0) {
        return FALSE;
    }
    message->mUnk_0c = connection->mLastSendTime;
    if (connection->mSendBuffer.mData[message->mUnk_00 + 2] == 2) {
        connection->mChallengeTime = connection->mLastSendTime;
    }
    return TRUE;
}

int gti2Send(Gt2Connection *connection, u8 *message, int len, int reliable) {
    if (reliable != 0) {
        return gti2SendAppReliable(connection, message, len);
    }
    return gti2SendAppUnreliable(connection, message, len);
}

u32 gt2CreateSocket(Gt2Socket **socket, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                    u32 callback) {
    return CreateSocket(socket, localAddress, outgoingBufferSize, incomingBufferSize, callback);
}

void gt2CloseSocket(Gt2Socket *socket) {
    gt2CloseAllConnectionsHard(socket);
    DeleteSocket(socket);
}

void gt2Think(Gt2Socket *socket) {
    if (gti2ReceiveMessages(socket) != 0) {
        if (func_ov000_0219a09c(socket) != 0) {
            func_ov000_0219a06c(socket);
        }
    }
}
