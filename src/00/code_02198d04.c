#include "00/code_02198d04.h"
#include "00/code_0218d818.h"
#include "00/code_02197b34.h"
#include "00/gt2Connection.h"
#include "00/code_0219903c.h"
#include "00/unk_021b3000.h"
#include "code_02134398.h"
#include "00/code_02197e58.h"

#pragma opt_common_subs off

u32 gti2EndReliableMessage(Gt2Connection *connection) {
    int v1;
    int *messageInfo;
    v1 = DarrayGetCount(connection->mOutgoingBufferMessages);
    if (v1 <= 0) {
        AssertionFailed(gGt2MessageEndAssert, gGt2MessageFileName, NULL, 0x475);
    }
    messageInfo = DarrayGetElement(connection->mOutgoingBufferMessages, v1 + -1);
    v1 = SendConnectionBytes(connection, connection->mSendBuffer.mData + *messageInfo, messageInfo[1]);
    if (v1 == 0) {
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
