#include "00/Lib/GameSpy/protocol_messages.h"
#include "00/Lib/GameSpy/connection_lifecycle.h"
#include "00/Lib/GameSpy/connection_control.h"
#include "00/Lib/GameSpy/connection_events.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/challenge_response_check.h"
#include "00/Lib/GameSpy/challenge_response.h"
#include "00/Lib/GameSpy/byte_buffer.h"
#include "quick_sort.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/socket_connections.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/GameSpy/query_reporting.h"

u8 gGti2MagicString[2] = {0xfe, 0xfe};
char gPingTimeId[] = "time";

u32 gti2UShortFromBuffer(const u8 *buffer, s32 offset) {
    u16 highByte = (buffer[offset] << 8) & 0xff00;
    return highByte | buffer[offset + 1];
}

void gti2UShortToBuffer(u8 *buffer, s32 offset, u16 value) {
    buffer[offset] = value >> 8;
    buffer[offset + 1] = value;
}

int gti2SNDiff(int serialNumber1, int serialNumber2) {
    return (serialNumber1 - serialNumber2) * 0x10000 >> 0x10;
}

u32 gti2ConnectionError(GTI2Connection *connection, u32 result, u32 reason) {
    s32 state = connection->mState;
    if (state < SOCKET_CONNECTION_CONNECTED) {
        if (connection->mInitiated != FALSE) {
            gti2ConnectionClosed(connection);
            if (gti2ConnectedCallback(connection, result, NULL, 0) == FALSE) {
                return 0;
            }
        } else {
            if (state == SOCKET_CONNECTION_AWAIT_ACCEPT_REJECT) {
                connection->mFreeAtAcceptReject = TRUE;
            }
            gti2ConnectionClosed(connection);
        }
    } else if (state != SOCKET_CONNECTION_CLOSED) {
        gti2ConnectionClosed(connection);
        if (gti2ClosedCallback(connection, (void *) reason) == FALSE) {
            return 0;
        }
    }
    return 1;
}

u32 gti2ConnectionCommunicationError(GTI2Connection *connection) {
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

u32 gti2ConnectionMemoryError(GTI2Connection *connection) {
    int sentClosed;
    u32 result;
    sentClosed = gti2SendClosed(connection);
    if (sentClosed != 0) {
        result = gti2ConnectionError(connection, 1, 4);
        return result;
    }
    return 0;
}

enum { CLOSE_REASON_LOCAL, CLOSE_REASON_REMOTE };

u32 gti2HandleESN(GTI2Connection *connection, u32 esn) {
    s32 messageCount;
    s32 index;
    s32 trimBytes;
    GTI2OutgoingBufferMessage *message;
    messageCount = ArrayLength(connection->mOutgoingBufferMessages);
    if (messageCount == 0) {
        return 1;
    }
    for (index = 0; index < messageCount; index++) {
        message = ArrayNth(connection->mOutgoingBufferMessages, index);
        if (gti2SNDiff(message->mSerialNumber, esn) >= 0) {
            break;
        }
    }
    if (index == 0) {
        return 1;
    }
    while (index-- != 0) {
        ArrayDeleteAt(connection->mOutgoingBufferMessages, index);
    }
    messageCount = ArrayLength(connection->mOutgoingBufferMessages);
    if (messageCount == 0) {
        connection->mSendBuffer.mLength = 0;
        return 1;
    }
    message = ArrayNth(connection->mOutgoingBufferMessages, 0);
    trimBytes = message->mStart;
    for (index = 0; index < messageCount; index++) {
        message = ArrayNth(connection->mOutgoingBufferMessages, index);
        message->mStart -= trimBytes;
    }
    gti2BufferShorten(&connection->mSendBuffer, 0, trimBytes);
    return 1;
}

u32 gti2HandleAppUnreliable(GTI2Connection *connection, const u8 *message, s32 length) {
    if (connection->mState != SOCKET_CONNECTION_CONNECTED && connection->mState != SOCKET_CONNECTION_CLOSING) {
        return 1;
    }
    if (ArrayLength(connection->mReceiveFilters) != 0) {
        if (gti2ReceiveFilterCallback(connection, 0, message, length, 0) != FALSE) {
            return 1;
        }
        return 0;
    }
    if (gti2ReceivedCallback(connection, message, length, 0) != FALSE) {
        return 1;
    }
    return 0;
}

u32 gti2HandleAppReliable(GTI2Connection *connection, const u8 *message, u32 length) {
    if (connection->mState != SOCKET_CONNECTION_CONNECTED && connection->mState != SOCKET_CONNECTION_CLOSING) {
        if (gti2ConnectionCommunicationError(connection) == 0) {
            return 0;
        }
    } else {
        if (ArrayLength(connection->mReceiveFilters) != 0) {
            if (gti2ReceiveFilterCallback(connection, 0, message, length, 1) != FALSE) {
                return 1;
            }
            return 0;
        }
        if (gti2ReceivedCallback(connection, message, length, 1) == FALSE) {
            return 0;
        }
    }
    return 1;
}

u32 gti2HandleClientChallenge(GTI2Connection *connection, const u8 *message, int length) {
    u8 peerAnswer[0x20];
    u8 ownChallenge[0x20];
    if (connection->mState != SOCKET_CONNECTION_AWAIT_CLIENT_CHALLENGE) {
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
    gti2GetResponse(peerAnswer, message);
    gti2GetChallenge(ownChallenge);
    gti2GetResponse(connection->mResponse, ownChallenge);
    if (gti2SendServerChallenge(connection, peerAnswer, ownChallenge) == 0) {
        return 0;
    }
    connection->mState = SOCKET_CONNECTION_SERVER_CHALLENGE_SENT;
    return 1;
}

u32 gti2HandleServerChallenge(GTI2Connection *connection, const u8 *message, int length) {
    u8 clientAnswer[0x20];
    if (connection->mState != SOCKET_CONNECTION_AWAIT_SERVER_CHALLENGE) {
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
    gti2GetResponse(clientAnswer, message + 0x20);
    if (gti2SendClientResponse(connection, clientAnswer, connection->mInitialMessageData,
                               connection->mInitialMessageSize) == 0) {
        return 0;
    }
    if (connection->mInitialMessageData != NULL) {
        DWCi_GsFree(connection->mInitialMessageData);
        connection->mInitialMessageData = NULL;
    }
    connection->mState = SOCKET_CONNECTION_CLIENT_RESPONSE_SENT;
    return 1;
}

u32 gti2HandleClientResponse(GTI2Connection *connection, const u8 *message, int length) {
    if (connection->mState != SOCKET_CONNECTION_SERVER_CHALLENGE_SENT) {
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
    connection->mState = SOCKET_CONNECTION_AWAIT_ACCEPT_REJECT;
    if (CallIncomingConnectionCallback(connection->mSocket, connection, connection->mAddress, connection->mPort,
                                       current_time() - connection->mChallengeTime, message + 0x20,
                                       length - 0x20) != FALSE) {
        return 1;
    }
    return 0;
}

u32 gti2HandleAccept(GTI2Connection *connection) {
    if (connection->mState != SOCKET_CONNECTION_CLIENT_RESPONSE_SENT) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    connection->mState = SOCKET_CONNECTION_CONNECTED;
    if (gti2ConnectedCallback(connection, 0, NULL, 0) != 0) {
        return 1;
    }
    return 0;
}

u32 gti2HandleReject(GTI2Connection *connection, void *message, u32 length) {
    if (connection->mState != SOCKET_CONNECTION_CLIENT_RESPONSE_SENT) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    gti2ConnectionClosed(connection);
    if (gti2SendClosed(connection) == 0) {
        return 0;
    }
    if (gti2ConnectedCallback(connection, 2, message, length) != FALSE) {
        return 1;
    }
    return 0;
}

u32 gti2HandleClose(GTI2Connection *connection) {
    if (gti2SendClosed(connection) == 0) {
        return 0;
    }
    if (gti2ConnectionError(connection, 2,
                            connection->mState == SOCKET_CONNECTION_CLOSING ? CLOSE_REASON_LOCAL : CLOSE_REASON_REMOTE) == 0) {
        return 0;
    }
    return 1;
}

u32 gti2DeliverReliableMessage(GTI2Connection *connection, int type, const u8 *message, u32 len) {
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

u32 gti2BufferIncomingMessage(GTI2Connection *connection, s32 type, u32 serialNumber, const u8 *message, s32 len,
                              s32 *overflow) {
    GTI2IncomingBufferMessage newEntry;
    s32 num;
    s32 index;
    GTI2IncomingBufferMessage *heldMessage;
    num = ArrayLength(connection->mIncomingBufferMessages);
    for (index = 0; index < num; index++) {
        heldMessage = ArrayNth(connection->mIncomingBufferMessages, index);
        if (heldMessage->mSerialNumber == serialNumber) {
            *overflow = 0;
            return 1;
        }
        if (gti2SNDiff(heldMessage->mSerialNumber, serialNumber) > 0) {
            break;
        }
    }
    if (gti2GetBufferFreeSpace(&connection->mIncomingBuffer) < len) {
        *overflow = 1;
        return 1;
    }
    newEntry.mStart = connection->mIncomingBuffer.mLength;
    newEntry.mLen = len;
    newEntry.mType = type;
    newEntry.mSerialNumber = serialNumber;
    ArrayInsertSorted(connection->mIncomingBufferMessages, &newEntry, gti2IncomingBufferMessageCompare);
    if (num + 1 != ArrayLength(connection->mIncomingBufferMessages)) {
        *overflow = 1;
        return 1;
    }
    gti2BufferWriteData(&connection->mIncomingBuffer, message, len);
    if (num == 0) {
        if (gti2SendNack(connection, connection->mExpectedSerialNumber, serialNumber - 1) == FALSE) {
            return 0;
        }
    } else {
        heldMessage = ArrayNth(connection->mIncomingBufferMessages, num);
        if (heldMessage->mSerialNumber == serialNumber) {
            heldMessage = ArrayNth(connection->mIncomingBufferMessages, num - 1);
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

void gti2RemoveHoldMessage(GTI2Connection *connection, GTI2IncomingBufferMessage *message, s32 index) {
    s32 heldEnd = 0;
    s32 removedStart = message->mStart;
    s32 removedLen = message->mLen;
    s32 num;
    s32 heldIndex;
    GTI2IncomingBufferMessage *heldMessage;
    ArrayDeleteAt(connection->mIncomingBufferMessages, index);
    num = ArrayLength(connection->mIncomingBufferMessages);
    for (heldIndex = 0; heldIndex < num; heldIndex++) {
        heldMessage = ArrayNth(connection->mIncomingBufferMessages, heldIndex);
        if (heldMessage->mStart > removedStart) {
            heldMessage->mStart -= removedLen;
            if (heldEnd <= heldMessage->mStart + heldMessage->mLen) {
                heldEnd = heldMessage->mStart + heldMessage->mLen;
            }
        }
    }
    gti2BufferShorten(&connection->mIncomingBuffer, removedStart, removedLen);
}

u32 gti2DeliverHoldMessages(GTI2Connection *connection) {
    s32 index;
    GTI2IncomingBufferMessage *message;
top:
    for (index = ArrayLength(connection->mIncomingBufferMessages) - 1; index >= 0; index--) {
        message = ArrayNth(connection->mIncomingBufferMessages, index);
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

void gti2SetPendingAck(GTI2Connection *connection) {
    u32 now;
    if (connection->mPendingAck == 0) {
        connection->mPendingAck = 1;
        now = current_time();
        connection->mPendingAckTime = now;
    }
}

u32 gti2HandleReliableMessage(GTI2Connection *connection, u32 type, const u8 *message, s32 len) {
    u32 serialNumber;
    s32 bufferOverflow;
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
    if (gti2BufferIncomingMessage(connection, type, serialNumber, message + 7, len - 7, &bufferOverflow) == 0) {
        return 0;
    }
    if (bufferOverflow != 0 && gti2ConnectionMemoryError(connection) == 0) {
        return 0;
    }
    return 1;
}

u32 gti2HandleAck(GTI2Connection *connection, const u8 *message, s32 len) {
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

u32 gti2HandleNack(GTI2Connection *connection, const u8 *message, s32 len) {
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
    num = ArrayLength(connection->mOutgoingBufferMessages);
    for (index = 0; index < num; index++) {
        sentEntry = ArrayNth(connection->mOutgoingBufferMessages, index);
        if (gti2SNDiff(sentEntry->mSerialNumber, firstNumber) >= 0 &&
            gti2SNDiff(sentEntry->mSerialNumber, lastNumber) <= 0) {
            if (gti2ResendMessage(connection, sentEntry) == FALSE) {
                return 0;
            }
        }
    }
    return 1;
}

u32 gti2HandlePing(GTI2Connection *connection, u8 *message, u32 len) {
    GTI2Connection *pingConnection = connection;
    u8 *pingMessage = message;
    u32 pingLength = len;
    u32 sendResult;
    u32 sendPongFunction;
    sendPongFunction = (u32) &gti2SendPong;
    sendResult = gti2SendPong(pingConnection, pingMessage, pingLength);
    return sendResult;
}

u32 gti2HandlePong(GTI2Connection *connection, u8 *message, s32 len) {
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
    if (gti2PingCallback(connection, current_time() - pingSentTime) != FALSE) {
        return 1;
    }
    return 0;
}

u32 gti2HandleClosed(GTI2Connection *connection) {
    if (connection->mState == SOCKET_CONNECTION_CLOSED) {
        return 1;
    }
    if (gti2ConnectionError(connection, 2,
                            connection->mState == SOCKET_CONNECTION_CLOSING ? CLOSE_REASON_LOCAL : CLOSE_REASON_REMOTE) == 0) {
        return 0;
    }
    return 1;
}

u32 gti2HandleUnreliableMessage(GTI2Connection *connection, u32 type, u8 *message, s32 len) {
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
        if (gti2HandlePing(connection, message, len) == 0) {
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

u32 gti2HandleMessage(GTI2Socket *socket, u8 *message, s32 len, u32 address, u32 port) {
    GTI2Connection *connection;
    GTI2Connection *senderConnection;
    s32 wasHandled;
    BOOL isProtocolMessage;
    s32 value;
    connection = gti2SocketFindConnection(socket, address, port);
    if (socket->mReceiveDumpCallback != NULL) {
        if (gti2DumpCallback(socket, connection, address, port, 0, (s32) message, len, 0) == 0) {
            return 0;
        }
    }
    if (len > 2 && memcmp(message, gGti2MagicString, 2) == 0) {
        isProtocolMessage = TRUE;
    } else {
        isProtocolMessage = FALSE;
    }
    if (connection == NULL) {
        if (gti2UnrecognizedMessageCallback(socket, address, port, message, len, &wasHandled) == FALSE) {
            return 0;
        }
        if (wasHandled != 0) {
            return 1;
        }
        if (isProtocolMessage == FALSE || message[2] != 1) {
            if (isProtocolMessage == FALSE || message[2] != 0x68) {
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
    senderConnection = connection;
    if (senderConnection->mState == SOCKET_CONNECTION_CLOSED) {
        if (isProtocolMessage == FALSE || message[2] != 0x68) {
            if (gti2SendClosed(senderConnection) == 0) {
                return 0;
            }
        }
        return 1;
    }
    if (isProtocolMessage != FALSE && len >= 4 && memcmp(message + 2, gGti2MagicString, 2) == 0) {
        message += 2;
        len -= 2;
        isProtocolMessage = FALSE;
    }
    if (isProtocolMessage == FALSE) {
        if (gti2HandleAppUnreliable(senderConnection, message, len) != 0) {
            return 1;
        }
        return 0;
    }
    value = message[2];
    if (value < 0) {
        if (gti2ConnectionCommunicationError(senderConnection) != 0) {
            return 1;
        }
        return 0;
    }
    if (value < 8) {
        if (gti2HandleReliableMessage(senderConnection, value, message, len) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2HandleUnreliableMessage(senderConnection, value, message, len) != 0) {
        return 1;
    }
    return 0;
}

u32 gti2HandleConnectionReset(GTI2Socket *socket, u32 address, u32 port) {
    GTI2Connection *connection;
    int checkResult;
    int now;
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
    if (connection->mState == SOCKET_CONNECTION_AWAIT_SERVER_CHALLENGE) {
        if ((connection->mTimeSinceCreateLimit == 0) ||
            (now = current_time(),
             (now - connection->mCreateTime) < connection->mTimeSinceCreateLimit)) {
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

u32 gti2ReceiveMessages(GTI2Socket *socket) {
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

u32 gti2StoreOutgoingReliableMessageInfo(GTI2Connection *connection, u16 serialNumber, s32 len) {
    GTI2OutgoingBufferMessage newEntry = {0, 0, 0, {0, 0}, 0};
    s32 num;
    newEntry.mStart = connection->mSendBuffer.mLength;
    newEntry.mLen = len;
    newEntry.mSerialNumber = serialNumber;
    newEntry.mLastSend = current_time();
    num = ArrayLength(connection->mOutgoingBufferMessages);
    ArrayAppend(connection->mOutgoingBufferMessages, &newEntry);
    if (num + 1 == ArrayLength(connection->mOutgoingBufferMessages)) {
        return 1;
    }
    return 0;
}

BOOL gti2BeginReliableMessage(GTI2Connection *connection, u32 type, int len, int *overflow) {
    if (gti2GetBufferFreeSpace(&connection->mSendBuffer) < len) {
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
    gti2BufferWriteData(&connection->mSendBuffer, gGti2MagicString, 2);
    gti2BufferWriteByte(&connection->mSendBuffer, type);
    gti2BufferWriteUShort(&connection->mSendBuffer, connection->mSerialNumber++);
    gti2BufferWriteUShort(&connection->mSendBuffer, connection->mExpectedSerialNumber);
    *overflow = 0;
    return TRUE;
}

#pragma opt_common_subs off

u32 gti2EndReliableMessage(GTI2Connection *connection) {
    int checkResult;
    int messageCount;
    int *messageInfo;
    messageCount = ArrayLength(connection->mOutgoingBufferMessages);
    if (messageCount <= 0) {
        AssertionFailed("len > 0", "gt2Message.c", NULL, 0x475);
    }
    messageInfo = ArrayNth(connection->mOutgoingBufferMessages, messageCount + -1);
    checkResult = gti2ConnectionSendData(connection, connection->mSendBuffer.mData + *messageInfo, messageInfo[1]);
    if (checkResult == 0) {
        return 0;
    }
    connection->mPendingAck = 0;
    return 1;
}

u32 gti2SendAppReliable(GTI2Connection *connection, const u8 *message, int len) {
    int result;
    int bufferOverflow[2];
    result = gti2BeginReliableMessage(connection, 0, len + 7, bufferOverflow);
    if (result == 0) {
        return 0;
    }
    if (bufferOverflow[0] != 0) {
        return 1;
    }
    gti2BufferWriteData(&connection->mSendBuffer, message, len);
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendClientChallenge(GTI2Connection *connection, const void *challenge) {
    int result;
    int bufferOverflow;
    result = gti2BeginReliableMessage(connection, 1, 0x27, &bufferOverflow);
    if (result == 0) {
        return 0;
    }
    if (bufferOverflow != 0) {
        return 1;
    }
    gti2BufferWriteData(&connection->mSendBuffer, challenge, 0x20);
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendServerChallenge(GTI2Connection *connection, const u8 *response, const u8 *challenge) {
    int result;
    int bufferOverflow[2];
    result = gti2BeginReliableMessage(connection, 2, 0x47, bufferOverflow);
    if (result == 0) {
        return 0;
    }
    if (bufferOverflow[0] != 0) {
        return 1;
    }
    gti2BufferWriteData(&connection->mSendBuffer, response, 0x20);
    gti2BufferWriteData(&connection->mSendBuffer, challenge, 0x20);
    result = gti2EndReliableMessage(connection);
    if (result == 0) {
        return 0;
    }
    connection->mChallengeTime = connection->mLastSendTime;
    return 1;
}

u32 gti2SendClientResponse(GTI2Connection *connection, const u8 *response, const u8 *message, int len) {
    int result;
    int bufferOverflow;
    result = gti2BeginReliableMessage(connection, 3, len + 0x27, &bufferOverflow);
    if (result == 0) {
        return 0;
    }
    if (bufferOverflow != 0) {
        return 1;
    }
    gti2BufferWriteData(&connection->mSendBuffer, response, 0x20);
    gti2BufferWriteData(&connection->mSendBuffer, message, len);
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendAccept(GTI2Connection *connection) {
    int result;
    int bufferOverflow[2];
    result = gti2BeginReliableMessage(connection, 4, 7, bufferOverflow);
    if (result == 0) {
        return 0;
    }
    if (bufferOverflow[0] != 0) {
        return 1;
    }
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendReject(GTI2Connection *connection, const void *message, int len) {
    int result;
    int bufferOverflow[2];
    result = gti2BeginReliableMessage(connection, 5, len + 7, bufferOverflow);
    if (result == 0) {
        return 0;
    }
    if (bufferOverflow[0] != 0) {
        return 1;
    }
    gti2BufferWriteData(&connection->mSendBuffer, message, len);
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendClose(GTI2Connection *connection) {
    int result;
    int bufferOverflow[2];
    result = gti2BeginReliableMessage(connection, 6, 7, bufferOverflow);
    if (result == 0) {
        return 0;
    }
    if (bufferOverflow[0] != 0) {
        return 1;
    }
    result = gti2EndReliableMessage(connection);
    if (result != 0) {
        return 1;
    }
    return 0;
}

u32 gti2SendKeepAlive(GTI2Connection *connection) {
    int result;
    int bufferOverflow[2];
    result = gti2BeginReliableMessage(connection, 7, 7, bufferOverflow);
    if (result == 0) {
        return 0;
    }
    if (bufferOverflow[0] != 0) {
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

BOOL gti2SendAppUnreliable(GTI2Connection *connection, u8 *message, int len) {
    int totalLength;
    u8 *start;
    if (len < 2 || memcmp(message, gGti2MagicString, 2) != 0) {
        if (gti2ConnectionSendData(connection, message, len) == 0) {
            return FALSE;
        }
        return TRUE;
    }
    totalLength = len + 2;
    if (gti2GetBufferFreeSpace(&connection->mSendBuffer) < totalLength) {
        return TRUE;
    }
    start = connection->mSendBuffer.mData + connection->mSendBuffer.mLength;
    gti2BufferWriteData(&connection->mSendBuffer, gGti2MagicString, 2);
    gti2BufferWriteData(&connection->mSendBuffer, message, len);
    if (gti2ConnectionSendData(connection, start, totalLength) == 0) {
        return FALSE;
    }
    gti2BufferShorten(&connection->mSendBuffer, -1, totalLength);
    return TRUE;
}

BOOL gti2SendAck(GTI2Connection *connection) {
    u8 buffer[3];
    CopyUnalignedHalfword(buffer, gGti2MagicString);
    buffer[2] = 0x64;
    gti2UShortToBuffer(buffer, 3, connection->mExpectedSerialNumber);
    if (gti2ConnectionSendData(connection, buffer, 5) == 0) {
        return FALSE;
    }
    connection->mPendingAck = 0;
    return TRUE;
}

BOOL gti2SendNack(GTI2Connection *connection, u16 firstNumber, u16 lastNumber) {
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
    if (gti2ConnectionSendData(connection, buffer, pos) == 0) {
        return FALSE;
    }
    return TRUE;
}

u32 gti2SendPong(GTI2Connection *connection, u8 *message, u32 len) {
    GTI2Connection *sendConnection = connection;
    u8 *messageAddress = message;
    u32 length = len;
    u32 sendResult;
    u32 pongType;
    pongType = 103u;
    messageAddress[2] = pongType;
    pongType = (u32) &gti2ConnectionSendData;
    sendResult = gti2ConnectionSendData(sendConnection, messageAddress, length);
    return sendResult;
}

int gti2SendClosed(GTI2Connection *connection) {
    return gti2SendClosedOnSocket(connection->mSocket, connection->mAddress, connection->mPort);
}

BOOL gti2SendClosedOnSocket(GTI2Socket *socket, u32 address, int port) {
    u8 buffer[3];

    __memcpy(buffer, gGti2MagicString, 2);
    buffer[2] = 0x68;
    if (gti2SocketSend(socket, address, port, (u32) buffer, 3) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL gti2ResendMessage(GTI2Connection *connection, GTI2OutgoingBufferMessage *message) {
    gti2UShortToBuffer(connection->mSendBuffer.mData, message->mStart + 5, connection->mExpectedSerialNumber);
    if (gti2ConnectionSendData(connection, connection->mSendBuffer.mData + message->mStart, message->mLen) == 0) {
        return FALSE;
    }
    message->mLastSend = connection->mLastSendTime;
    if (connection->mSendBuffer.mData[message->mStart + 2] == 2) {
        connection->mChallengeTime = connection->mLastSendTime;
    }
    return TRUE;
}

int gti2Send(GTI2Connection *connection, u8 *message, int len, int reliable) {
    if (reliable != 0) {
        return gti2SendAppReliable(connection, message, len);
    }
    return gti2SendAppUnreliable(connection, message, len);
}

u32 gt2CreateSocket(GTI2Socket **socket, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                    void (*callback)(GTI2Socket *)) {
    return gti2CreateSocket(socket, localAddress, outgoingBufferSize, incomingBufferSize, callback);
}

void gt2CloseSocket(GTI2Socket *socket) {
    gt2CloseAllConnectionsHard(socket);
    DeleteSocket(socket);
}

void gt2Think(GTI2Socket *socket) {
    if (gti2ReceiveMessages(socket) != 0) {
        if (gti2SocketConnectionsThink(socket) != 0) {
            gti2FreeClosedConnections(socket);
        }
    }
}
