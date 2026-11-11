#include "00/code_0219a0d0.h"
#include "00/code_0218d818.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218d000.h"
#include "00/code_0219a61c.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dd8c.h"
#include "00/code_0218e2dc.h"
#include "00/unk_021b4000.h"
#include "00/code_02197000.h"
#include "00/code_02199000.h"
#include "00/code_0219a000.h"
#include "00/code_0219903c.h"
#include "00/code_02197ddc.h"
#include "00/code_02198584.h"
#include "00/code_0219a044.h"
#include "00/code_0219a3e8.h"
#include "00/code_0219a430.h"
#include "00/code_021a3668.h"
#include "code_021382a8.h"

u32 gti2NewSocketConnection(Gt2Socket *socket, Gt2Connection **connectionOut, u32 address, u32 port) {
    Gt2Connection *newConnection = NULL;
    if (gti2SocketFindConnection(socket, address, port) != NULL) {
        return 5;
    }
    newConnection = gti2CreateConnectionObject();
    if (newConnection != NULL) {
        memset(newConnection, 0, 0xa0);
        newConnection->mAddress = address;
        newConnection->mPort = port;
        newConnection->mSocket = socket;
        newConnection->mCreateTime = GetElapsedMilliseconds();
        newConnection->mLastSendTime = newConnection->mCreateTime;
        newConnection->mSerialNumber = 0;
        newConnection->mExpectedSerialNumber = 0;
        if (InitBuffer(&newConnection->mIncomingBuffer, socket->mIncomingBufferSize) != 0 &&
            InitBuffer(&newConnection->mSendBuffer, socket->mSendBufferSize) != 0) {
            newConnection->mIncomingBufferMessages = DarrayCreate(0x10, 0x40, NULL);
            if (newConnection->mIncomingBufferMessages != NULL) {
                newConnection->mOutgoingBufferMessages = DarrayCreate(0x10, 0x40, NULL);
                if (newConnection->mOutgoingBufferMessages != NULL) {
                    newConnection->mSendFilters = DarrayCreate(4, 2, NULL);
                    if (newConnection->mSendFilters != NULL) {
                        newConnection->mReceiveFilters = DarrayCreate(4, 2, NULL);
                        if (newConnection->mReceiveFilters != NULL) {
                            HashtableSet(socket->mConnections, &newConnection);
                            *connectionOut = gti2SocketFindConnection(socket, address, port);
                            if (*connectionOut != NULL) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    if (newConnection != NULL) {
        DWCi_GsFree(newConnection->mIncomingBuffer.mData);
        DWCi_GsFree(newConnection->mSendBuffer.mData);
        if (newConnection->mIncomingBufferMessages != NULL) {
            DarrayDelete(newConnection->mIncomingBufferMessages);
        }
        if (newConnection->mOutgoingBufferMessages != NULL) {
            DarrayDelete(newConnection->mOutgoingBufferMessages);
        }
        if (newConnection->mSendFilters != NULL) {
            DarrayDelete(newConnection->mSendFilters);
        }
        if (newConnection->mReceiveFilters != NULL) {
            DarrayDelete(newConnection->mReceiveFilters);
        }
        DWCi_GsFree(newConnection);
    }
    return 1;
}

void gti2FreeSocketConnection(Gt2Connection *connection) {
    s32 closedCount;
    s32 index;
    if (connection->mFreeAtAcceptReject == FALSE && connection->mCallbackLevel == 0) {
        if (connection->mState == 7) {
            closedCount = DarrayGetCount(connection->mSocket->mConnectionsToFree);
            for (index = 0; index < closedCount; index++) {
                if (connection ==
                    *(Gt2Connection **) DarrayGetElement(connection->mSocket->mConnectionsToFree, index)) {
                    DarrayRemove(connection->mSocket->mConnectionsToFree, index);
                    return;
                }
            }
        } else {
            HashtableRemove(connection->mSocket->mConnections, &connection);
        }
    }
}

u32 gti2SocketSend(u32 *socketPointer, u32 address, int port, u32 message, u32 length) {
    Gt2Socket *socket = (Gt2Socket *) socketPointer;
    s32 lastError;
    gti2MessageCheck((const char **) &message, (s32 *) &length);
    if (CanSendOnSocket(socket->mDescriptor) == 0) {
        return 1;
    }
    {
        SOCSockAddrIn sockaddr = {0, 0, 0, 0};
        SOCSockAddrIn *sockaddrPointer = &sockaddr;
        sockaddrPointer->mFamily = 2;
        sockaddrPointer->mAddr = address;
        sockaddrPointer->mPort = ((port >> 8) & 0xff) | ((port << 8) & 0xff00);
        if (sendto(socket->mDescriptor, (void *) message, length, 0, &sockaddr, 8) == -1) {
            lastError = GOAGetLastError(socket->mDescriptor);
            if (lastError == -15) {
                if (gti2HandleConnectionReset(socket, address, port) == 0) {
                    return 0;
                }
            } else if (lastError == -42 || lastError == -6) {
                return 1;
            } else if (lastError != -35) {
                gti2SocketError(socket);
                return 0;
            }
        } else if (socket->mSentCallback != NULL) {
            if (gti2DumpCallback(socket, gti2SocketFindConnection(socket, address, port), address, port, 0, message,
                                 length, 1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

u32 gti2SocketConnectionsThinkMap(Gt2Connection **element, u32 *clientData) {
    Gt2Connection *connection = *element;
    u32 now = *clientData;
    if (connection->mState != 7 && gti2ConnectionThink(connection, now) == 0) {
        return 0;
    }
    if (connection->mState == 7 && connection->mFreeAtAcceptReject == FALSE && connection->mCallbackLevel == 0) {
        gti2FreeSocketConnection(connection);
    }
    return 1;
}
