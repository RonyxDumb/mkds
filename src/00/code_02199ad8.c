#include "00/code_02199ad8.h"
#include "00/code_0218d818.h"
#include "00/code_0219903c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_02197b08.h"
#include "00/code_02197b34.h"
#include "00/code_02197ddc.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02198d04.h"
#include "00/code_02199fa4.h"
#include "00/code_02199fb0.h"
#include "00/code_0219a014.h"
#include "00/code_021a3668.h"
#include "code_021382a8.h"
#include "00/code_0218e2dc.h"

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
    if (connection->mState != 5 && connection->mState != 6) {
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
    if (connection->mState != 5 && connection->mState != 6) {
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
    s8 response[0x20];
    s8 ownChallenge[0x20];
    if (connection->mState != 2) {
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
    gti2GetResponse(response, (const s8 *) message);
    gti2GetChallenge(ownChallenge);
    gti2GetResponse((s8 *) connection->mResponse, ownChallenge);
    if (gti2SendServerChallenge(connection, (const u8 *) response, (const u8 *) ownChallenge) == 0) {
        return 0;
    }
    connection->mState = 3;
    return 1;
}

u32 gti2HandleServerChallenge(Gt2Connection *connection, const u8 *message, int length) {
    s8 response[0x20];
    if (connection->mState != 0) {
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
    gti2GetResponse(response, (const s8 *) (message + 0x20));
    if (gti2SendClientResponse(connection, (const u8 *) response, connection->mUnk_38.mData,
                               connection->mUnk_38.mSize) == 0) {
        return 0;
    }
    if (connection->mUnk_38.mData != NULL) {
        DWCi_GsFree(connection->mUnk_38.mData);
        connection->mUnk_38.mData = NULL;
    }
    connection->mState = 1;
    return 1;
}

u32 gti2HandleClientResponse(Gt2Connection *connection, const u8 *message, int length) {
    if (connection->mState != 3) {
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
    connection->mState = 4;
    if (CallIncomingConnectionCallback(connection->mSocket, connection, connection->mAddress, connection->mPort,
                                       GetElapsedMilliseconds() - connection->mChallengeTime, message + 0x20,
                                       length - 0x20) != FALSE) {
        return 1;
    }
    return 0;
}

u32 gti2HandleAccept(Gt2Connection *connection) {
    if (connection->mState != 1) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    connection->mState = 5;
    if (Gt2SetResultAndCallResultCallback(connection, 0, NULL, 0) != 0) {
        return 1;
    }
    return 0;
}

u32 gti2HandleReject(Gt2Connection *connection, void *message, u32 length) {
    if (connection->mState != 1) {
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
    if (gti2ConnectionError(connection, 2, connection->mState == 6 ? K0 : K1) == 0) {
        return 0;
    }
    return 1;
}
