#include "00/code_021985ec.h"
#include "00/code_0218d818.h"
#include "00/code_02197e58.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_02198a8c.h"
#include "00/code_02198d04.h"

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
    Unk02198af4 *message;
    len = DarrayGetCount((u32 *) connection->mOutgoingBufferMessages);
    for (index = 0; index < len; index++) {
        message = DarrayGetElement(connection->mOutgoingBufferMessages, index);
        if (now - message->mUnk_0c > 1000) {
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
