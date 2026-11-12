#include "00/code_0219903c.h"

#include "00/code_02197b34.h"
#include "00/code_02197e58.h"
#include "00/code_02197000.h"
#include "00/code_02197ddc.h"
#include "00/code_02199f80.h"
#include "00/code_0218d000.h"
#include "00/code_02199fb0.h"
#include "00/code_0219a430.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218d818.h"
#include "00/code_0218e2dc.h"
#include "00/unk_021b4000.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196594.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"
#include "00/code_021a3a18.h"
#include "00/code_02199000.h"
#include "00/code_0219a000.h"
#include "00/code_0219a044.h"
#include "00/gt2Connection.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_0219960c.h"
#include "00/code_02199614.h"
#include "00/code_02199ad8.h"
#include "00/code_02199fa4.h"

enum { K0, K1 };

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
    if (connection->mState == 7) {
        return 1;
    }
    if (gti2ConnectionError(connection, 2, connection->mState == 6 ? K0 : K1) == 0) {
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
    Gt2Connection *k;
    s32 wasHandled;
    BOOL hasMagic;
    s32 i;
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
            i = gti2NewIncomingConnection(socket, &connection, address, port);
            if (i != 0) {
                if (i != 5 && gti2SendClosedOnSocket(socket, address, port) == FALSE) {
                    return 0;
                }
                return 1;
            }
        }
    }
    k = connection;
    if (k->mState == 7) {
        if (hasMagic == FALSE || message[2] != 0x68) {
            if (gti2SendClosed(k) == 0) {
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
        if (gti2HandleAppUnreliable(k, message, len) != 0) {
            return 1;
        }
        return 0;
    }
    i = message[2];
    if (i < 0) {
        if (gti2ConnectionCommunicationError(k) != 0) {
            return 1;
        }
        return 0;
    }
    if (i < 8) {
        if (gti2HandleReliableMessage(k, i, message, len) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2HandleUnreliableMessage(k, i, message, len) != 0) {
        return 1;
    }
    return 0;
}

u32 gti2HandleConnectionReset(Gt2Socket *socket, u32 address, u32 port) {
    Gt2Connection *connection;
    int v2;
    connection = gti2SocketFindConnection(socket, address, port);
    if (socket->mReceiveDumpCallback != NULL) {
        v2 = gti2DumpCallback(socket, connection, address, port, 1, 0, 0, 0);
        if (v2 == 0) {
            return 0;
        }
    }
    if (connection == NULL) {
        return 1;
    }
    if (connection->mState == 0) {
        if ((connection->mTimeSinceCreateLimit == 0) ||
            (v2 = GetElapsedMilliseconds(), (v2 - connection->mCreateTime) < connection->mTimeSinceCreateLimit)) {
            return 1;
        }
        v2 = gti2ConnectionError(connection, 6, 1);
        if (v2 == 0) {
            return 0;
        }
    } else {
        v2 = gti2ConnectionError(connection, 2, 1);
        if (v2 == 0) {
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
