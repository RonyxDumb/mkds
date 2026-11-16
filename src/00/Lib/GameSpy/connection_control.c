#include "00/Lib/GameSpy/connection_control.h"
#include "00/Lib/GameSpy/socket_connections.h"
#include "00/Lib/GameSpy/message_check.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/hash_table.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/connection_lifecycle.h"
#include "00/Lib/GameSpy/protocol_messages.h"
#include "00/Lib/GameSpy/nat_negotiation.h"
#include "00/Lib/GameSpy/address_text_convert.h"

void gt2Listen(void *socket, void *callback) {
    u32 unusedValue;
    SetIncomingConnectionCallback(socket, callback);
}

int gt2Accept(Gt2Connection *connection, Gt2ConnectionCallbacks *callbacks) {
    return gti2AcceptConnection(connection, callbacks);
}

void gt2Reject(Gt2Connection *connection, void *message, u32 len) {
    gti2RejectConnection(connection, message, len);
}

int gt2Connect(void *socket, Gt2Connection **connection, const char *remoteAddress, void *message, int len, u32 timeout,
               Gt2ConnectionCallbacks *callbacks, int blocking) {
    Gt2Connection *pendingConn;
    u32 ipAddress;
    u16 netPort;
    u32 portValue;
    int result;
    int startResult;
    if (gt2StringToAddress(remoteAddress, &ipAddress, &netPort) == FALSE || ipAddress == 0 ||
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
        if (ArrayLength(connection->mSendFilters) != 0) {
            gti2SendFilterCallback(connection, 0, message, len, reliable);
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
    TableMapSafe(socket->mConnections, (void (*)(void *, void *)) gti2CloseAllConnectionsHardMap, NULL);
}
