#include "00/gt2Socket.h"
#include "00/code_02197e58.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/code_0218d818.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dd8c.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e2dc.h"
#include "00/gt2Connection.h"
#include "00/gt2Main.h"
#include "00/code_02198a8c.h"
#include "00/code_021919ac.h"
#include "00/code_0219a000.h"
#include "00/code_021a3668.h"
#include "00/code_0219a654.h"
#include "00/code_0219a61c.h"
#include "00/code_02197000.h"
#include "00/code_02199000.h"
#include "00/gt2Message.h"
#include "00/code_02197ddc.h"
#include "code_021382a8.h"

u32 gti2ConnectionHash(const Gt2ConnectionEntry *object, u32 modulus) {
    return (object->mValue->mAddress * object->mValue->mPort) % modulus;
}

s32 gti2ConnectionCompare(const Gt2Connection *const *left, const Gt2Connection *const *right) {
    const Gt2Connection *leftConnection = *left;
    const Gt2Connection *rightConnection = *right;
    if (leftConnection->mAddress != rightConnection->mAddress) {
        return leftConnection->mAddress - rightConnection->mAddress;
    }
    return (s16) (leftConnection->mPort - rightConnection->mPort);
}

void gti2ConnectionFree(Gt2Connection **element) {
    gti2ConnectionCleanup(*element);
}

Gt2Connection *gti2SocketFindConnection(Gt2Socket *socket, u32 address, u32 port) {
    Gt2Connection key;
    Gt2Connection *keyPointer;
    void *found;
    key.mAddress = address;
    key.mPort = port;
    keyPointer = &key;
    found = HashtableFind(socket->mConnections, &keyPointer);
    if (found != NULL) {
        return *(Gt2Connection **) found;
    }
    return NULL;
}

u32 gti2CreateSocket(Gt2Socket **socketOut, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                     u32 errorCallback) {
    Gt2Socket *newSocket;
    u16 netPort;
    SOCSockAddrIn socketAddress;
    u32 address;
    s32 addressLength;
    u32 *bindWords;
    SocketStartUp();
    if (incomingBufferSize == 0) {
        incomingBufferSize = 0x10000;
    }
    if (outgoingBufferSize == 0) {
        outgoingBufferSize = 0x10000;
    }
    if (gt2StringToAddress(localAddress, &address, &netPort) == FALSE) {
        return 4;
    }
    newSocket = DWCi_GsMalloc(0x44);
    if (newSocket == NULL) {
        return 1;
    }
    memset(newSocket, 0, 0x44);
    newSocket->mDescriptor = -1;
    newSocket->mIncomingBufferSize = incomingBufferSize;
    newSocket->mSendBufferSize = outgoingBufferSize;
    newSocket->mSocketErrorCallback = (void (*)(Gt2Socket *)) errorCallback;
    newSocket->mConnections = HashtableCreate(4, 0x20, 2, (s32(*)(void *, s32)) & gti2ConnectionHash,
                                              (s32(*)(void *, void *)) & gti2ConnectionCompare, NULL);
    if (newSocket->mConnections == NULL) {
        DWCi_GsFree(newSocket);
        return 1;
    }
    newSocket->mConnectionsToFree = DarrayCreate(4, 4, (void (*)(void *)) & gti2ConnectionFree);
    if (newSocket->mConnectionsToFree == NULL) {
        HashtableDelete(newSocket->mConnections);
        DWCi_GsFree(newSocket);
        return 1;
    }
    newSocket->mDescriptor = OpenNetSocket(2, 2, 0);
    if (newSocket->mDescriptor == -1) {
        HashtableDelete(newSocket->mConnections);
        DarrayDelete(newSocket->mConnectionsToFree);
        DWCi_GsFree(newSocket);
        return 3;
    }
    bindWords = (u32 *) &socketAddress;
    bindWords[0] = 0;
    bindWords[1] = 0;
    socketAddress.mFamily = 2;
    socketAddress.mAddr = address;
    socketAddress.mPort = ((netPort >> 8) & 0xff) | ((netPort << 8) & 0xff00);
    if (bind(newSocket->mDescriptor, &socketAddress, 8) == -1) {
        closesocket(newSocket->mDescriptor);
        HashtableDelete(newSocket->mConnections);
        DarrayDelete(newSocket->mConnectionsToFree);
        DWCi_GsFree(newSocket);
        return 3;
    }
    addressLength = 8;
    getsockname(newSocket->mDescriptor, &socketAddress, (u32 *) &addressLength);
    newSocket->mAddress = socketAddress.mAddr;
    newSocket->mPort = ((socketAddress.mPort >> 8) & 0xff) | ((socketAddress.mPort << 8) & 0xff00);
    *socketOut = newSocket;
    return 0;
}

void DeleteSocket(Gt2Socket *a) {
    if (a->mRunningCallbackCount != 0) {
        a->mDeletePending = TRUE;
        return;
    }
    closesocket(a->mDescriptor);
    HashtableDelete(a->mConnections);
    DarrayDelete(a->mConnectionsToFree);
    DWCi_GsFree(a);
    SocketShutDown();
}

void SetIncomingConnectionCallback(Gt2Socket *a, void *b) {
    a->mIncomingConnectionCallback = b;
}

Gt2Connection *gti2CreateConnectionObject(void) {
    u32 value0;
    u32 allocFunction;
    value0 = 160u;
    allocFunction = (u32) &DWCi_GsMalloc;
    value0 = (u32) DWCi_GsMalloc(value0);
    return (Gt2Connection *) value0;
}

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

u32 gti2SocketConnectionsThink(Gt2Socket *socket) {
    void *stoppedElement;
    u32 currentTime[2];
    currentTime[0] = GetElapsedMilliseconds();
    stoppedElement = HashtableFindByFn(socket->mConnections, (s32) &gti2SocketConnectionsThinkMap, currentTime);
    if (stoppedElement == NULL) {
        return 1;
    }
    return 0;
}

void gti2FreeClosedConnections(Gt2Socket *socket) {
    s32 index;
    for (index = DarrayGetCount(socket->mConnectionsToFree) - 1; index >= 0; index--) {
        gti2FreeSocketConnection(*(Gt2Connection **) DarrayGetElement(socket->mConnectionsToFree, index));
    }
}

void gti2SocketError(Gt2Socket *socket) {
    if (socket->mError == FALSE) {
        socket->mError = TRUE;
        gt2CloseAllConnectionsHard(socket);
        if (gti2SocketErrorCallback(socket) != FALSE) {
            DeleteSocket(socket);
        }
    }
}
