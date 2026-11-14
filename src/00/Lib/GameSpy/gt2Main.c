#include "00/Lib/GameSpy/gt2Main.h"
#include "00/Lib/GameSpy/gt2Socket.h"
#include "00/Lib/GameSpy/code_0219a61c.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_0218dd8c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/gt2Connection.h"
#include "00/Lib/GameSpy/code_02198a8c.h"
#include "00/Lib/GameSpy/code_0219a654.h"
#include "00/Lib/GameSpy/gt2Utility.h"

void gt2Listen(void *socket, void *callback) {
    u32 value3;
    SetIncomingConnectionCallback(socket, callback);
}

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
    int result;
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
    result = gti2NewOutgoingConnection(socket, &pendingConn, ipAddress, portValue);
    if (result != 0) {
        return result;
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
        result = pendingConn->mState >= GT2_CONNECTION_CONNECTED ? 1 : 0;
        if (result == 0) {
            msleep(1);
        }
    } while (result == 0);
    pendingConn->mCallbackLevel--;
    if (pendingConn->mState == GT2_CONNECTION_CONNECTED) {
        *connection = pendingConn;
    }
    return pendingConn->mResult;
}

void gt2Send(Gt2Connection *connection, u8 *message, int len, int reliable) {
    if (connection->mState == GT2_CONNECTION_CONNECTED) {
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
