#include "00/code_021988e8.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a61c.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dd8c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "03/code_021b94b8.h"
#include "00/code_0218e2dc.h"
#include "00/code_02198748.h"
#include "00/code_02198a8c.h"
#include "00/code_0219a654.h"

int gt2Accept(Gt2Connection *connection, Gt2ConnectionCallbacks *callbacks) {
    return gti2AcceptConnection(connection, callbacks);
}

void gt2Reject(Gt2Connection *connection, void *message, u32 len) {
    gti2RejectConnection(connection, message, len);
}

int gt2Connect(void *socket, Gt2Connection **connection, u32 remoteAddress, void *message, int len, u32 timeout,
               Gt2ConnectionCallbacks *callbacks, int blocking) {
    Gt2Connection *pendingConn;
    u32 ipAddress;
    u16 netPort;
    u32 portValue;
    int l;
    int startResult;
    if (gt2StringToAddress((const char *) remoteAddress, &ipAddress, &netPort) == FALSE || ipAddress == 0 ||
        (portValue = netPort) == 0) {
        return 4;
    }
    if (((((ipAddress << 24) & 0xff000000) |
          (((ipAddress << 8) & 0xff0000) | (((ipAddress >> 24) & 0xff) | ((ipAddress >> 8) & 0xff00)))) &
         0xe0000000) == 0xe0000000) {
        return 4;
    }
    l = gti2NewOutgoingConnection(socket, &pendingConn, ipAddress, portValue);
    if (l != 0) {
        return l;
    }
    pendingConn->mTimeSinceCreateLimit = timeout;
    startResult = gti2StartConnectionAttempt(pendingConn, message, len, callbacks);
    if (startResult != 0) {
        gti2FreeSocketConnection(pendingConn);
        return startResult;
    }
    if (blocking == 0) {
        if (connection != NULL) {
            *connection = pendingConn;
        }
        return 0;
    }
    pendingConn->mCallbackLevel++;
    do {
        gt2Think(socket);
        l = pendingConn->mState >= 5 ? 1 : 0;
        if (l == 0) {
            msleep(1);
        }
    } while (l == 0);
    pendingConn->mCallbackLevel--;
    if (pendingConn->mState == 5) {
        *connection = pendingConn;
    }
    return pendingConn->mResult;
}

void gt2Send(Gt2Connection *connection, u8 *message, int len, int reliable) {
    if (connection->mState == 5) {
        gti2MessageCheck((const char **) &message, &len);
        if (DarrayGetCount((u32 *) connection->mSendFilters) != 0) {
            gti2SendFilterCallback(connection, 0, (s32) message, (void *) len, reliable);
            return;
        }
        gti2Send(connection, message, len, reliable);
    }
}

void gt2CloseConnectionHard(Gt2Connection *connection) {
    gti2CloseConnection(connection, 1);
}

void gti2CloseAllConnectionsHardMap(Gt2Connection **elem) {
    gt2CloseConnectionHard(*elem);
}

void gt2CloseAllConnectionsHard(Gt2Socket *socket) {
    HashtableForEach(socket->mConnections, (void (*)(void *, void *)) gti2CloseAllConnectionsHardMap, NULL);
}
