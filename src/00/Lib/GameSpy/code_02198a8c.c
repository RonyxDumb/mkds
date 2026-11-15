#include "00/Lib/GameSpy/code_02198a8c.h"
#include "00/Lib/GameSpy/gt2Connection.h"
#include "00/Lib/GameSpy/gt2Main.h"
#include "00/Lib/GameSpy/code_02197e58.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_02197b08.h"
#include "00/Lib/GameSpy/code_02197b34.h"
#include "00/Lib/GameSpy/code_02197ddc.h"
#include "code_021382a8.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/code_02199000.h"
#include "00/code_02197000.h"
#include "00/Lib/GameSpy/gt2Socket.h"
#include "00/unk_021b3000.h"
#include "00/unk_021b4000.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/Lib/GameSpy/code_02196480.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_02194bb8.h"
#include "00/Lib/GameSpy/code_02193b88.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/code_0219a000.h"

u8 gGti2MagicString[2] = {0xfe, 0xfe};
char gPingTimeId[] = "time";

u32 gti2UShortFromBuffer(const u8 *buffer, s32 offset) {
    u16 value = (buffer[offset] << 8) & 0xff00;
    return value | buffer[offset + 1];
}

void gti2UShortToBuffer(u8 *buffer, s32 offset, u16 value) {
    buffer[offset] = value >> 8;
    buffer[offset + 1] = value;
}

int gti2SNDiff(int serialNumber1, int serialNumber2) {
    return (serialNumber1 - serialNumber2) * 0x10000 >> 0x10;
}

u32 gti2ConnectionError(Gt2Connection *connection, u32 result, u32 reason) {
    s32 state = connection->mState;
    if (state < GT2_CONNECTION_CONNECTED) {
        if (connection->mInitiated != FALSE) {
            gti2ConnectionClosed(connection);
            if (Gt2SetResultAndCallResultCallback(connection, result, NULL, 0) == FALSE) {
                return 0;
            }
        } else {
            if (state == GT2_CONNECTION_AWAIT_DECISION) {
                connection->mFreeAtAcceptReject = TRUE;
            }
            gti2ConnectionClosed(connection);
        }
    } else if (state != GT2_CONNECTION_CLOSED) {
        gti2ConnectionClosed(connection);
        if (gti2ClosedCallback(connection, (void *) reason) == FALSE) {
            return 0;
        }
    }
    return 1;
}

u32 gti2ConnectionCommunicationError(Gt2Connection *connection) {
    u32 result;
    u32 errorResult;
    u32 closeReason;
    u32 errorHandler;
    errorResult = 7u;
    closeReason = 2u;
    errorHandler = (u32) &gti2ConnectionError;
    result = gti2ConnectionError(connection, errorResult, closeReason);
    return result;
}

u32 gti2ConnectionMemoryError(Gt2Connection *connection) {
    int sentClosed;
    u32 result;
    sentClosed = gti2SendClosed(connection);
    if (sentClosed != 0) {
        result = gti2ConnectionError(connection, 1, 4);
        return result;
    }
    return 0;
}

enum { K0, K1 };

u32 gti2HandleESN(Gt2Connection *connection, u32 esn) {
    s32 messageCount;
    s32 index;
    s32 trimBytes;
    GTI2OutgoingBufferMessage *message;
    messageCount = DarrayGetCount(connection->mOutgoingBufferMessages);
    if (messageCount == 0) {
        return 1;
    }
    for (index = 0; index < messageCount; index++) {
        message = DarrayGetElement(connection->mOutgoingBufferMessages, index);
        if (gti2SNDiff(message->mSerialNumber, esn) >= 0) {
            break;
        }
    }
    if (index == 0) {
        return 1;
    }
    while (index-- != 0) {
        DarrayRemove(connection->mOutgoingBufferMessages, index);
    }
    messageCount = DarrayGetCount(connection->mOutgoingBufferMessages);
    if (messageCount == 0) {
        connection->mSendBuffer.mLength = 0;
        return 1;
    }
    message = DarrayGetElement(connection->mOutgoingBufferMessages, 0);
    trimBytes = message->mStart;
    for (index = 0; index < messageCount; index++) {
        message = DarrayGetElement(connection->mOutgoingBufferMessages, index);
        message->mStart -= trimBytes;
    }
    RemoveBufferBytes(&connection->mSendBuffer, 0, trimBytes);
    return 1;
}

u32 gti2HandleAppUnreliable(Gt2Connection *connection, const u8 *message, s32 length) {
    if (connection->mState != GT2_CONNECTION_CONNECTED && connection->mState != GT2_CONNECTION_CLOSING) {
        return 1;
    }
    if (DarrayGetCount(connection->mReceiveFilters) != 0) {
        if (gti2ReceiveFilterCallback(connection, 0, message, length, 0) != FALSE) {
            return 1;
        }
        return 0;
    }
    if (Gt2CallDataCallback(connection, message, length, 0) != FALSE) {
        return 1;
    }
    return 0;
}

u32 gti2HandleAppReliable(Gt2Connection *connection, const u8 *message, u32 length) {
    if (connection->mState != GT2_CONNECTION_CONNECTED && connection->mState != GT2_CONNECTION_CLOSING) {
        if (gti2ConnectionCommunicationError(connection) == 0) {
            return 0;
        }
    } else {
        if (DarrayGetCount(connection->mReceiveFilters) != 0) {
            if (gti2ReceiveFilterCallback(connection, 0, message, length, 1) != FALSE) {
                return 1;
            }
            return 0;
        }
        if (Gt2CallDataCallback(connection, message, length, 1) == FALSE) {
            return 0;
        }
    }
    return 1;
}

u32 gti2HandleClientChallenge(Gt2Connection *connection, const u8 *message, int length) {
    s8 peerAnswer[0x20];
    s8 ownChallenge[0x20];
    if (connection->mState != GT2_CONNECTION_AWAIT_OFFER) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (length < 0x20) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    gti2GetResponse(peerAnswer, (const s8 *) message);
    gti2GetChallenge(ownChallenge);
    gti2GetResponse((s8 *) connection->mResponse, ownChallenge);
    if (gti2SendServerChallenge(connection, (const u8 *) peerAnswer, (const u8 *) ownChallenge) == 0) {
        return 0;
    }
    connection->mState = GT2_CONNECTION_CHALLENGE_SENT;
    return 1;
}

u32 gti2HandleServerChallenge(Gt2Connection *connection, const u8 *message, int length) {
    s8 clientAnswer[0x20];
    if (connection->mState != GT2_CONNECTION_OFFER_SENT) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (length < 0x40) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2CheckResponse(message, connection->mResponse) == FALSE) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    gti2GetResponse(clientAnswer, (const s8 *) (message + 0x20));
    if (gti2SendClientResponse(connection, (const u8 *) clientAnswer, connection->mInitialMessage.mData,
                               connection->mInitialMessage.mSize) == 0) {
        return 0;
    }
    if (connection->mInitialMessage.mData != NULL) {
        DWCi_GsFree(connection->mInitialMessage.mData);
        connection->mInitialMessage.mData = NULL;
    }
    connection->mState = GT2_CONNECTION_REPLY_SENT;
    return 1;
}

u32 gti2HandleClientResponse(Gt2Connection *connection, const u8 *message, int length) {
    if (connection->mState != GT2_CONNECTION_CHALLENGE_SENT) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (length < 0x20) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2CheckResponse(message, connection->mResponse) == FALSE) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (connection->mSocket->mIncomingConnectionCallback == NULL) {
        if (gti2SendClosed(connection) == 0) {
            return 0;
        }
        gti2ConnectionClosed(connection);
        return 1;
    }
    connection->mState = GT2_CONNECTION_AWAIT_DECISION;
    if (CallIncomingConnectionCallback(connection->mSocket, connection, connection->mAddress, connection->mPort,
                                       GetElapsedMilliseconds() - connection->mChallengeTime, message + 0x20,
                                       length - 0x20) != FALSE) {
        return 1;
    }
    return 0;
}

u32 gti2HandleAccept(Gt2Connection *connection) {
    if (connection->mState != GT2_CONNECTION_REPLY_SENT) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    connection->mState = GT2_CONNECTION_CONNECTED;
    if (Gt2SetResultAndCallResultCallback(connection, 0, NULL, 0) != 0) {
        return 1;
    }
    return 0;
}

u32 gti2HandleReject(Gt2Connection *connection, void *message, u32 length) {
    if (connection->mState != GT2_CONNECTION_REPLY_SENT) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    gti2ConnectionClosed(connection);
    if (gti2SendClosed(connection) == 0) {
        return 0;
    }
    if (Gt2SetResultAndCallResultCallback(connection, 2, message, length) != FALSE) {
        return 1;
    }
    return 0;
}

u32 gti2HandleClose(Gt2Connection *connection) {
    if (gti2SendClosed(connection) == 0) {
        return 0;
    }
    if (gti2ConnectionError(connection, 2, connection->mState == GT2_CONNECTION_CLOSING ? K0 : K1) == 0) {
        return 0;
    }
    return 1;
}

u32 gti2DeliverReliableMessage(Gt2Connection *connection, int type, const u8 *message, u32 len) {
    int result;
    connection->mExpectedSerialNumber = connection->mExpectedSerialNumber + 1;
    if (type == 0) {
        result = gti2HandleAppReliable(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 1) {
        result = gti2HandleClientChallenge(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 2) {
        result = gti2HandleServerChallenge(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 3) {
        result = gti2HandleClientResponse(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 4) {
        result = gti2HandleAccept(connection);
        if (result == 0) {
            return 0;
        }
    } else if (type == 5) {
        result = gti2HandleReject(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if ((type == 6) && (result = gti2HandleClose(connection), result == 0)) {
        return 0;
    }
    return 1;
}

s32 gti2IncomingBufferMessageCompare(const void *elem1, const void *elem2) {
    const u8 *leftMessage = elem1;
    const u8 *rightMessage = elem2;
    s32 serialDiff;
    s32 rightSerialNumber;
    u32 diffFunction;
    serialDiff = *(const u16 *) (leftMessage + 12);
    rightSerialNumber = *(const u16 *) (rightMessage + 12);
    diffFunction = (u32) &gti2SNDiff;
    serialDiff = gti2SNDiff(serialDiff, rightSerialNumber);
    return serialDiff;
}

u32 gti2BufferIncomingMessage(Gt2Connection *connection, s32 type, u32 serialNumber, const u8 *message, s32 len,
                              s32 *overflow) {
    GTI2IncomingBufferMessage newEntry;
    s32 num;
    s32 index;
    GTI2IncomingBufferMessage *heldMessage;
    num = DarrayGetCount(connection->mIncomingBufferMessages);
    for (index = 0; index < num; index++) {
        heldMessage = DarrayGetElement(connection->mIncomingBufferMessages, index);
        if (heldMessage->mSerialNumber == serialNumber) {
            *overflow = 0;
            return 1;
        }
        if (gti2SNDiff(heldMessage->mSerialNumber, serialNumber) > 0) {
            break;
        }
    }
    if (GetBufferUnusedSize(&connection->mIncomingBuffer) < len) {
        *overflow = 1;
        return 1;
    }
    newEntry.mStart = connection->mIncomingBuffer.mLength;
    newEntry.mLen = len;
    newEntry.mType = type;
    newEntry.mSerialNumber = serialNumber;
    DarrayInsertSorted(connection->mIncomingBufferMessages, &newEntry, gti2IncomingBufferMessageCompare);
    if (num + 1 != DarrayGetCount(connection->mIncomingBufferMessages)) {
        *overflow = 1;
        return 1;
    }
    AppendBufferBytes(&connection->mIncomingBuffer, message, len);
    if (num == 0) {
        if (gti2SendNack(connection, connection->mExpectedSerialNumber, serialNumber - 1) == FALSE) {
            return 0;
        }
    } else {
        heldMessage = DarrayGetElement(connection->mIncomingBufferMessages, num);
        if (heldMessage->mSerialNumber == serialNumber) {
            heldMessage = DarrayGetElement(connection->mIncomingBufferMessages, num - 1);
            if ((u16) gti2SNDiff(serialNumber, heldMessage->mSerialNumber) > 1) {
                if (gti2SendNack(connection, heldMessage->mSerialNumber + 1, serialNumber - 1) == FALSE) {
                    return 0;
                }
            }
        }
    }
    *overflow = 0;
    return 1;
}

void gti2RemoveHoldMessage(Gt2Connection *connection, GTI2IncomingBufferMessage *message, s32 index) {
    s32 heldEnd = 0;
    s32 removedStart = message->mStart;
    s32 removedLen = message->mLen;
    s32 num;
    s32 heldIndex;
    GTI2IncomingBufferMessage *heldMessage;
    DarrayRemove(connection->mIncomingBufferMessages, index);
    num = DarrayGetCount(connection->mIncomingBufferMessages);
    for (heldIndex = 0; heldIndex < num; heldIndex++) {
        heldMessage = DarrayGetElement(connection->mIncomingBufferMessages, heldIndex);
        if (heldMessage->mStart > removedStart) {
            heldMessage->mStart -= removedLen;
            if (heldEnd <= heldMessage->mStart + heldMessage->mLen) {
                heldEnd = heldMessage->mStart + heldMessage->mLen;
            }
        }
    }
    RemoveBufferBytes(&connection->mIncomingBuffer, removedStart, removedLen);
}

u32 gti2DeliverHoldMessages(Gt2Connection *connection) {
    s32 index;
    GTI2IncomingBufferMessage *message;
top:
    for (index = DarrayGetCount(connection->mIncomingBufferMessages) - 1; index >= 0; index--) {
        message = DarrayGetElement(connection->mIncomingBufferMessages, index);
        if (message->mSerialNumber == connection->mExpectedSerialNumber) {
            if (gti2DeliverReliableMessage(connection, message->mType,
                                           connection->mIncomingBuffer.mData + message->mStart, message->mLen) == 0) {
                return 0;
            }
            gti2RemoveHoldMessage(connection, message, index);
            goto top;
        }
    }
    return 1;
}

void gti2SetPendingAck(Gt2Connection *connection) {
    u32 now;
    if (connection->mPendingAck == 0) {
        connection->mPendingAck = 1;
        now = GetElapsedMilliseconds();
        connection->mPendingAckTime = now;
    }
}

u32 gti2HandleReliableMessage(Gt2Connection *connection, u32 type, const u8 *message, s32 len) {
    u32 serialNumber;
    s32 bufferFull;
    u32 expectedSerialNumber;
    if (len < 7) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    serialNumber = gti2UShortFromBuffer(message, 3);
    expectedSerialNumber = gti2UShortFromBuffer(message, 5);
    if (gti2HandleESN(connection, expectedSerialNumber) == 0) {
        return 0;
    }
    if (serialNumber == connection->mExpectedSerialNumber) {
        gti2SetPendingAck(connection);
        if (gti2DeliverReliableMessage(connection, type, message + 7, len - 7) == 0) {
            return 0;
        }
        if (gti2DeliverHoldMessages(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2SNDiff(serialNumber, connection->mExpectedSerialNumber) < 0) {
        gti2SetPendingAck(connection);
        return 1;
    }
    if (gti2BufferIncomingMessage(connection, type, serialNumber, message + 7, len - 7, &bufferFull) == 0) {
        return 0;
    }
    if (bufferFull != 0 && gti2ConnectionMemoryError(connection) == 0) {
        return 0;
    }
    return 1;
}

u32 gti2HandleAck(Gt2Connection *connection, const u8 *message, s32 len) {
    if (len != 2) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2HandleESN(connection, gti2UShortFromBuffer(message, 0)) != 0) {
        return 1;
    }
    return 0;
}

u32 gti2HandleNack(Gt2Connection *connection, const u8 *message, s32 len) {
    u32 firstNumber;
    u32 lastNumber;
    s32 num;
    s32 index;
    GTI2OutgoingBufferMessage *sentEntry;
    firstNumber = gti2UShortFromBuffer(message, 0);
    if (len == 2) {
        lastNumber = firstNumber;
    } else if (len == 4) {
        lastNumber = gti2UShortFromBuffer(message, 2);
    } else {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    num = DarrayGetCount(connection->mOutgoingBufferMessages);
    for (index = 0; index < num; index++) {
        sentEntry = DarrayGetElement(connection->mOutgoingBufferMessages, index);
        if (gti2SNDiff(sentEntry->mSerialNumber, firstNumber) >= 0 &&
            gti2SNDiff(sentEntry->mSerialNumber, lastNumber) <= 0) {
            if (gti2ResendMessage(connection, sentEntry) == FALSE) {
                return 0;
            }
        }
    }
    return 1;
}

u32 gti2HandlePing(Gt2Connection *connection, u32 message, u32 len) {
    u32 sendResult = (u32) connection;
    u32 pingMessage = message;
    u32 pingLength = len;
    u32 sendPongFunction;
    sendPongFunction = (u32) &gti2SendPong;
    sendResult = gti2SendPong(sendResult, pingMessage, pingLength);
    return sendResult;
}

u32 gti2HandlePong(Gt2Connection *connection, u8 *message, s32 len) {
    s32 pingSentTime;
    u8 *startTimeBytes;
    u8 *timeData;
    if (connection->mCallbacks.mElapsedTimeCallback == NULL) {
        return 1;
    }
    if (len != 8) {
        return 1;
    }
    if (memcmp(message, gPingTimeId, 4) != 0) {
        return 1;
    }
    startTimeBytes = (u8 *) &pingSentTime;
    timeData = message + 4;
    startTimeBytes[0] = timeData[0];
    startTimeBytes[1] = timeData[1];
    startTimeBytes[2] = timeData[2];
    startTimeBytes[3] = timeData[3];
    if (Gt2CallElapsedTimeCallback(connection, GetElapsedMilliseconds() - pingSentTime) != FALSE) {
        return 1;
    }
    return 0;
}

u32 gti2HandleClosed(Gt2Connection *connection) {
    if (connection->mState == GT2_CONNECTION_CLOSED) {
        return 1;
    }
    if (gti2ConnectionError(connection, 2, connection->mState == GT2_CONNECTION_CLOSING ? K0 : K1) == 0) {
        return 0;
    }
    return 1;
}

u32 gti2HandleUnreliableMessage(Gt2Connection *connection, u32 type, u8 *message, s32 len) {
    u8 *payloadStart = message + 3;
    s32 payloadLen = len - 3;
    if (type == 0x64) {
        if (gti2HandleAck(connection, payloadStart, payloadLen) == 0) {
            return 0;
        }
    } else if (type == 0x65) {
        if (gti2HandleNack(connection, payloadStart, payloadLen) == 0) {
            return 0;
        }
    } else if (type == 0x66) {
        if (gti2HandlePing(connection, (u32) message, len) == 0) {
            return 0;
        }
    } else if (type == 0x67) {
        if (gti2HandlePong(connection, payloadStart, payloadLen) == 0) {
            return 0;
        }
    } else if (type == 0x68) {
        if (gti2HandleClosed(connection) == 0) {
            return 0;
        }
    }
    return 1;
}

u32 gti2HandleMessage(Gt2Socket *socket, u8 *message, s32 len, u32 address, u32 port) {
    Gt2Connection *connection;
    Gt2Connection *activeConnection;
    s32 wasHandled;
    BOOL hasMagic;
    s32 value;
    connection = gti2SocketFindConnection(socket, address, port);
    if (socket->mReceiveDumpCallback != NULL) {
        if (gti2DumpCallback(socket, connection, address, port, 0, (s32) message, len, 0) == 0) {
            return 0;
        }
    }
    if (len > 2 && memcmp(message, gGti2MagicString, 2) == 0) {
        hasMagic = TRUE;
    } else {
        hasMagic = FALSE;
    }
    if (connection == NULL) {
        if (CallUnmatchedDataCallback(socket, address, port, message, len, &wasHandled) == FALSE) {
            return 0;
        }
        if (wasHandled != 0) {
            return 1;
        }
        if (hasMagic == FALSE || message[2] != 1) {
            if (hasMagic == FALSE || message[2] != 0x68) {
                if (gti2SendClosedOnSocket(socket, address, port) == FALSE) {
                    return 0;
                }
            }
            return 1;
        } else {
            if (socket->mIncomingConnectionCallback == NULL) {
                return 1;
            }
            value = gti2NewIncomingConnection(socket, &connection, address, port);
            if (value != 0) {
                if (value != 5 && gti2SendClosedOnSocket(socket, address, port) == FALSE) {
                    return 0;
                }
                return 1;
            }
        }
    }
    activeConnection = connection;
    if (activeConnection->mState == GT2_CONNECTION_CLOSED) {
        if (hasMagic == FALSE || message[2] != 0x68) {
            if (gti2SendClosed(activeConnection) == 0) {
                return 0;
            }
        }
        return 1;
    }
    if (hasMagic != FALSE && len >= 4 && memcmp(message + 2, gGti2MagicString, 2) == 0) {
        message += 2;
        len -= 2;
        hasMagic = FALSE;
    }
    if (hasMagic == FALSE) {
        if (gti2HandleAppUnreliable(activeConnection, message, len) != 0) {
            return 1;
        }
        return 0;
    }
    value = message[2];
    if (value < 0) {
        if (gti2ConnectionCommunicationError(activeConnection) != 0) {
            return 1;
        }
        return 0;
    }
    if (value < 8) {
        if (gti2HandleReliableMessage(activeConnection, value, message, len) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2HandleUnreliableMessage(activeConnection, value, message, len) != 0) {
        return 1;
    }
    return 0;
}

u32 gti2HandleConnectionReset(Gt2Socket *socket, u32 address, u32 port) {
    Gt2Connection *connection;
    int checkResult;
    int elapsed;
    connection = gti2SocketFindConnection(socket, address, port);
    if (socket->mReceiveDumpCallback != NULL) {
        checkResult = gti2DumpCallback(socket, connection, address, port, 1, 0, 0, 0);
        if (checkResult == 0) {
            return 0;
        }
    }
    if (connection == NULL) {
        return 1;
    }
    if (connection->mState == GT2_CONNECTION_OFFER_SENT) {
        if ((connection->mTimeSinceCreateLimit == 0) ||
            (elapsed = GetElapsedMilliseconds(),
             (elapsed - connection->mCreateTime) < connection->mTimeSinceCreateLimit)) {
            return 1;
        }
        checkResult = gti2ConnectionError(connection, 6, 1);
        if (checkResult == 0) {
            return 0;
        }
    } else {
        checkResult = gti2ConnectionError(connection, 2, 1);
        if (checkResult == 0) {
            return 0;
        }
    }
    return 1;
}

u32 gti2ReceiveMessages(Gt2Socket *socket) {
    SOCSockAddrIn address;
    u8 buffer[0x5dc];
    s32 senderAddrLen;
    s32 receivedLen;
    u32 error;
    while (CanReceiveOnSocket(socket->mDescriptor) != 0) {
        senderAddrLen = 8;
        receivedLen = recvfrom(socket->mDescriptor, buffer, 0x5dc, 0, &address, &senderAddrLen);
        if (receivedLen == -1) {
            error = GOAGetLastError(socket->mDescriptor);
            if (error == -15) {
                if (gti2HandleConnectionReset(
                        socket, address.mAddr,
                        (u16) (((address.mPort >> 8) & 0xff) | ((address.mPort << 8) & 0xff00))) == 0) {
                    return 0;
                }
            } else if (error != -35) {
                gti2SocketError(socket);
                return 0;
            }
        } else {
            if (gti2HandleMessage(socket, buffer, receivedLen, address.mAddr,
                                  (u16) (((address.mPort >> 8) & 0xff) | ((address.mPort << 8) & 0xff00))) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

u32 gti2StoreOutgoingReliableMessageInfo(Gt2Connection *connection, u16 serialNumber, s32 len) {
    GTI2OutgoingBufferMessage newEntry = {0, 0, 0, {0, 0}, 0};
    s32 num;
    newEntry.mStart = connection->mSendBuffer.mLength;
    newEntry.mLen = len;
    newEntry.mSerialNumber = serialNumber;
    newEntry.mLastSend = GetElapsedMilliseconds();
    num = DarrayGetCount(connection->mOutgoingBufferMessages);
    DarrayAppend(connection->mOutgoingBufferMessages, &newEntry);
    if (num + 1 == DarrayGetCount(connection->mOutgoingBufferMessages)) {
        return 1;
    }
    return 0;
}

BOOL gti2BeginReliableMessage(Gt2Connection *connection, u32 type, int len, int *overflow) {
    if (GetBufferUnusedSize(&connection->mSendBuffer) < len) {
        if (gti2ConnectionMemoryError(connection) == 0) {
            return FALSE;
        }
        *overflow = 1;
        return TRUE;
    }
    if (gti2StoreOutgoingReliableMessageInfo(connection, connection->mSerialNumber, len) == 0) {
        if (gti2ConnectionMemoryError(connection) == 0) {
            return FALSE;
        }
        *overflow = 1;
        return TRUE;
    }
    AppendBufferBytes(&connection->mSendBuffer, gGti2MagicString, 2);
    AppendBufferByte(&connection->mSendBuffer, type);
    AppendBufferU16(&connection->mSendBuffer, connection->mSerialNumber++);
    AppendBufferU16(&connection->mSendBuffer, connection->mExpectedSerialNumber);
    *overflow = 0;
    return TRUE;
}

#pragma opt_common_subs off

u32 gti2EndReliableMessage(Gt2Connection *connection) {
    int checkResult;
    int messageCount;
    int *messageInfo;
    messageCount = DarrayGetCount(connection->mOutgoingBufferMessages);
    if (messageCount <= 0) {
        AssertionFailed("len > 0", "gt2Message.c", NULL, 0x475);
    }
    messageInfo = DarrayGetElement(connection->mOutgoingBufferMessages, messageCount + -1);
    checkResult = SendConnectionBytes(connection, connection->mSendBuffer.mData + *messageInfo, messageInfo[1]);
    if (checkResult == 0) {
        return 0;
    }
    connection->mPendingAck = 0;
    return 1;
}

u32 gti2SendAppReliable(Gt2Connection *connection, const u8 *message, int len) {
    int result;
    int bufferFull[2];
    result = gti2BeginReliableMessage(connection, 0, len + 7, bufferFull);
    if (result == 0) {
        return 0;
    }
    if (bufferFull[0] != 0) {
        return 1;
    }
    AppendBufferBytes(&connection->mSendBuffer, message, len);
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendClientChallenge(Gt2Connection *connection, const void *challenge) {
    int result;
    int bufferFull;
    result = gti2BeginReliableMessage(connection, 1, 0x27, &bufferFull);
    if (result == 0) {
        return 0;
    }
    if (bufferFull != 0) {
        return 1;
    }
    AppendBufferBytes(&connection->mSendBuffer, challenge, 0x20);
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendServerChallenge(Gt2Connection *connection, const u8 *response, const u8 *challenge) {
    int result;
    int bufferFull[2];
    result = gti2BeginReliableMessage(connection, 2, 0x47, bufferFull);
    if (result == 0) {
        return 0;
    }
    if (bufferFull[0] != 0) {
        return 1;
    }
    AppendBufferBytes(&connection->mSendBuffer, response, 0x20);
    AppendBufferBytes(&connection->mSendBuffer, challenge, 0x20);
    result = gti2EndReliableMessage(connection);
    if (result == 0) {
        return 0;
    }
    connection->mChallengeTime = connection->mLastSendTime;
    return 1;
}

u32 gti2SendClientResponse(Gt2Connection *connection, const u8 *response, const u8 *message, int len) {
    int result;
    int bufferFull;
    result = gti2BeginReliableMessage(connection, 3, len + 0x27, &bufferFull);
    if (result == 0) {
        return 0;
    }
    if (bufferFull != 0) {
        return 1;
    }
    AppendBufferBytes(&connection->mSendBuffer, response, 0x20);
    AppendBufferBytes(&connection->mSendBuffer, message, len);
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendAccept(Gt2Connection *connection) {
    int result;
    int bufferFull[2];
    result = gti2BeginReliableMessage(connection, 4, 7, bufferFull);
    if (result == 0) {
        return 0;
    }
    if (bufferFull[0] != 0) {
        return 1;
    }
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendReject(Gt2Connection *connection, const void *message, int len) {
    int result;
    int bufferFull[2];
    result = gti2BeginReliableMessage(connection, 5, len + 7, bufferFull);
    if (result == 0) {
        return 0;
    }
    if (bufferFull[0] != 0) {
        return 1;
    }
    AppendBufferBytes(&connection->mSendBuffer, message, len);
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendClose(Gt2Connection *connection) {
    int result;
    int bufferFull[2];
    result = gti2BeginReliableMessage(connection, 6, 7, bufferFull);
    if (result == 0) {
        return 0;
    }
    if (bufferFull[0] != 0) {
        return 1;
    }
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendKeepAlive(Gt2Connection *connection) {
    int result;
    int bufferFull[2];
    result = gti2BeginReliableMessage(connection, 7, 7, bufferFull);
    if (result == 0) {
        return 0;
    }
    if (bufferFull[0] != 0) {
        return 1;
    }
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

#pragma opt_common_subs reset

static inline void CopyUnalignedHalfword(void *destination, const void *source) {
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
    CopyUnalignedHalfword(buffer, gGti2MagicString);
    buffer[2] = 0x64;
    gti2UShortToBuffer(buffer, 3, connection->mExpectedSerialNumber);
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
    CopyUnalignedHalfword(buffer, gGti2MagicString);
    buffer[2] = 0x65;
    gti2UShortToBuffer(buffer, 3, firstNumber);
    pos += 5;
    if (firstNumber != lastNumber) {
        gti2UShortToBuffer(buffer, pos, lastNumber);
        pos += 2;
    }
    if (SendConnectionBytes(connection, buffer, pos) == 0) {
        return FALSE;
    }
    return TRUE;
}

u32 gti2SendPong(u32 connection, u32 message, u32 len) {
    u32 sendResult = connection;
    u32 messageAddress = message;
    u32 length = len;
    u32 pongType;
    pongType = 103u;
    *(u8 *) ((messageAddress) + 2u) = pongType;
    pongType = (u32) &SendConnectionBytes;
    sendResult = SendConnectionBytes((Gt2Connection *) sendResult, (u8 *) messageAddress, length);
    return sendResult;
}

int gti2SendClosed(Gt2Connection *connection) {
    return gti2SendClosedOnSocket(connection->mSocket, connection->mAddress, connection->mPort);
}

BOOL gti2SendClosedOnSocket(Gt2Socket *socket, u32 address, int port) {
    u8 buffer[3];

    __memcpy(buffer, gGti2MagicString, 2);
    buffer[2] = 0x68;
    if (gti2SocketSend((u32 *) socket, address, port, (u32) buffer, 3) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL gti2ResendMessage(Gt2Connection *connection, GTI2OutgoingBufferMessage *message) {
    gti2UShortToBuffer(connection->mSendBuffer.mData, message->mStart + 5, connection->mExpectedSerialNumber);
    if (SendConnectionBytes(connection, connection->mSendBuffer.mData + message->mStart, message->mLen) == 0) {
        return FALSE;
    }
    message->mLastSend = connection->mLastSendTime;
    if (connection->mSendBuffer.mData[message->mStart + 2] == 2) {
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
    return gti2CreateSocket(socket, localAddress, outgoingBufferSize, incomingBufferSize, callback);
}

void gt2CloseSocket(Gt2Socket *socket) {
    gt2CloseAllConnectionsHard(socket);
    DeleteSocket(socket);
}

void gt2Think(Gt2Socket *socket) {
    if (gti2ReceiveMessages(socket) != 0) {
        if (gti2SocketConnectionsThink(socket) != 0) {
            gti2FreeClosedConnections(socket);
        }
    }
}
