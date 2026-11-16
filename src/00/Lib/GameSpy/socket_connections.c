#include "00/Lib/GameSpy/socket_connections.h"
#include "00/Lib/GameSpy/connection_events.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/hash_table.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/connection_lifecycle.h"
#include "00/Lib/GameSpy/connection_control.h"
#include "00/Lib/GameSpy/protocol_messages.h"
#include "00/Lib/GameSpy/login_connect.h"
#include "00/Lib/GameSpy/nat_negotiation.h"
#include "00/Lib/GameSpy/address_text_convert.h"
#include "00/Lib/GameSpy/message_check.h"
#include "00/Lib/GameSpy/byte_buffer.h"
#include "quick_sort.h"

u32 gti2ConnectionHash(const Gt2ConnectionEntry *entry, u32 modulus) {
    return (entry->mValue->mAddress * entry->mValue->mPort) % modulus;
}

s32 gti2ConnectionCompare(const GTI2Connection *const *left, const GTI2Connection *const *right) {
    const GTI2Connection *leftConnection = *left;
    const GTI2Connection *rightConnection = *right;
    if (leftConnection->mAddress != rightConnection->mAddress) {
        return leftConnection->mAddress - rightConnection->mAddress;
    }
    return (s16) (leftConnection->mPort - rightConnection->mPort);
}

void gti2ConnectionFree(GTI2Connection **element) {
    gti2ConnectionCleanup(*element);
}

GTI2Connection *gti2SocketFindConnection(GTI2Socket *socket, u32 address, u32 port) {
    GTI2Connection key;
    GTI2Connection *keyPointer;
    void *found;
    key.mAddress = address;
    key.mPort = port;
    keyPointer = &key;
    found = TableLookup(socket->mConnections, &keyPointer);
    if (found != NULL) {
        return *(GTI2Connection **) found;
    }
    return NULL;
}

u32 gti2CreateSocket(GTI2Socket **socketOut, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                     void (*errorCallback)(GTI2Socket *)) {
    GTI2Socket *newSocket;
    u16 netPort;
    SOCSockAddrIn socketAddress;
    u32 address;
    u32 addressLength;
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
    memset(newSocket, 0, sizeof(*newSocket));
    newSocket->mDescriptor = -1;
    newSocket->mIncomingBufferSize = incomingBufferSize;
    newSocket->mSendBufferSize = outgoingBufferSize;
    newSocket->mSocketErrorCallback = errorCallback;
    newSocket->mConnections = HashtableCreate(4, 0x20, 2, (s32(*)(void *, s32)) & gti2ConnectionHash,
                                              (ArrayCompareFn *) &gti2ConnectionCompare, NULL);
    if (newSocket->mConnections == NULL) {
        DWCi_GsFree(newSocket);
        return 1;
    }
    newSocket->mConnectionsToFree = ArrayNew(4, 4, (void (*)(void *)) & gti2ConnectionFree);
    if (newSocket->mConnectionsToFree == NULL) {
        TableFree(newSocket->mConnections);
        DWCi_GsFree(newSocket);
        return 1;
    }
    newSocket->mDescriptor = OpenNetSocket(2, 2, 0);
    if (newSocket->mDescriptor == -1) {
        TableFree(newSocket->mConnections);
        ArrayFree(newSocket->mConnectionsToFree);
        DWCi_GsFree(newSocket);
        return 3;
    }
    bindWords = (u32 *) &socketAddress;
    bindWords[0] = 0;
    bindWords[1] = 0;
    socketAddress.mFamily = SOCKET_FAMILY_IPV4;
    socketAddress.mAddr = address;
    socketAddress.mPort = ((netPort >> 8) & 0xff) | ((netPort << 8) & 0xff00);
    if (bind(newSocket->mDescriptor, &socketAddress, 8) == -1) {
        closesocket(newSocket->mDescriptor);
        TableFree(newSocket->mConnections);
        ArrayFree(newSocket->mConnectionsToFree);
        DWCi_GsFree(newSocket);
        return 3;
    }
    addressLength = 8;
    getsockname(newSocket->mDescriptor, &socketAddress, &addressLength);
    newSocket->mAddress = socketAddress.mAddr;
    newSocket->mPort = ((socketAddress.mPort >> 8) & 0xff) | ((socketAddress.mPort << 8) & 0xff00);
    *socketOut = newSocket;
    return 0;
}

void DeleteSocket(GTI2Socket *gt2Socket) {
    if (gt2Socket->mRunningCallbackCount != 0) {
        gt2Socket->mDeletePending = TRUE;
        return;
    }
    closesocket(gt2Socket->mDescriptor);
    TableFree(gt2Socket->mConnections);
    ArrayFree(gt2Socket->mConnectionsToFree);
    DWCi_GsFree(gt2Socket);
    SocketShutDown();
}

void SetIncomingConnectionCallback(GTI2Socket *gt2Socket, void *callback) {
    gt2Socket->mIncomingConnectionCallback = callback;
}

GTI2Connection *gti2CreateConnectionObject(void) {
    u32 connectionObject;
    u32 allocFunction;
    connectionObject = 160u;
    allocFunction = (u32) &DWCi_GsMalloc;
    connectionObject = (u32) DWCi_GsMalloc(connectionObject);
    return (GTI2Connection *) connectionObject;
}

u32 gti2NewSocketConnection(GTI2Socket *socket, GTI2Connection **connectionOut, u32 address, u32 port) {
    GTI2Connection *newConnection = NULL;
    if (gti2SocketFindConnection(socket, address, port) != NULL) {
        return 5;
    }
    newConnection = gti2CreateConnectionObject();
    if (newConnection != NULL) {
        memset(newConnection, 0, sizeof(*newConnection));
        newConnection->mAddress = address;
        newConnection->mPort = port;
        newConnection->mSocket = socket;
        newConnection->mCreateTime = current_time();
        newConnection->mLastSendTime = newConnection->mCreateTime;
        newConnection->mSerialNumber = 0;
        newConnection->mExpectedSerialNumber = 0;
        if (gti2AllocateBuffer(&newConnection->mIncomingBuffer, socket->mIncomingBufferSize) != 0 &&
            gti2AllocateBuffer(&newConnection->mSendBuffer, socket->mSendBufferSize) != 0) {
            newConnection->mIncomingBufferMessages = ArrayNew(0x10, 0x40, NULL);
            if (newConnection->mIncomingBufferMessages != NULL) {
                newConnection->mOutgoingBufferMessages = ArrayNew(0x10, 0x40, NULL);
                if (newConnection->mOutgoingBufferMessages != NULL) {
                    newConnection->mSendFilters = ArrayNew(4, 2, NULL);
                    if (newConnection->mSendFilters != NULL) {
                        newConnection->mReceiveFilters = ArrayNew(4, 2, NULL);
                        if (newConnection->mReceiveFilters != NULL) {
                            TableEnter(socket->mConnections, &newConnection);
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
            ArrayFree(newConnection->mIncomingBufferMessages);
        }
        if (newConnection->mOutgoingBufferMessages != NULL) {
            ArrayFree(newConnection->mOutgoingBufferMessages);
        }
        if (newConnection->mSendFilters != NULL) {
            ArrayFree(newConnection->mSendFilters);
        }
        if (newConnection->mReceiveFilters != NULL) {
            ArrayFree(newConnection->mReceiveFilters);
        }
        DWCi_GsFree(newConnection);
    }
    return 1;
}

void gti2FreeSocketConnection(GTI2Connection *connection) {
    s32 closedCount;
    s32 index;
    if (connection->mFreeAtAcceptReject == FALSE && connection->mCallbackLevel == 0) {
        if (connection->mState == GT2_CONNECTION_CLOSED) {
            closedCount = ArrayLength(connection->mSocket->mConnectionsToFree);
            for (index = 0; index < closedCount; index++) {
                if (connection ==
                    *(GTI2Connection **) ArrayNth(connection->mSocket->mConnectionsToFree, index)) {
                    ArrayDeleteAt(connection->mSocket->mConnectionsToFree, index);
                    return;
                }
            }
        } else {
            TableRemove(connection->mSocket->mConnections, &connection);
        }
    }
}

u32 gti2SocketSend(GTI2Socket *socket, u32 address, int port, u32 message, u32 length) {
    s32 lastError;
    gti2MessageCheck((const char **) &message, (s32 *) &length);
    if (CanSendOnSocket(socket->mDescriptor) == 0) {
        return 1;
    }
    {
        SOCSockAddrIn sockaddr = {0, 0, 0, 0};
        SOCSockAddrIn *sockaddrPointer = &sockaddr;
        sockaddrPointer->mFamily = SOCKET_FAMILY_IPV4;
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
        } else if (socket->mSendDumpCallback != NULL) {
            if (gti2DumpCallback(socket, gti2SocketFindConnection(socket, address, port), address, port, 0, message,
                                 length, 1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

u32 gti2SocketConnectionsThinkMap(GTI2Connection **element, u32 *clientData) {
    GTI2Connection *connection = *element;
    u32 now = *clientData;
    if (connection->mState != GT2_CONNECTION_CLOSED && gti2ConnectionThink(connection, now) == 0) {
        return 0;
    }
    if (connection->mState == GT2_CONNECTION_CLOSED && connection->mFreeAtAcceptReject == FALSE &&
        connection->mCallbackLevel == 0) {
        gti2FreeSocketConnection(connection);
    }
    return 1;
}

u32 gti2SocketConnectionsThink(GTI2Socket *socket) {
    void *stoppedElement;
    u32 currentTime[2];
    currentTime[0] = current_time();
    stoppedElement = TableMapSafe2(socket->mConnections, (s32) &gti2SocketConnectionsThinkMap, currentTime);
    if (stoppedElement == NULL) {
        return 1;
    }
    return 0;
}

void gti2FreeClosedConnections(GTI2Socket *socket) {
    s32 index;
    for (index = ArrayLength(socket->mConnectionsToFree) - 1; index >= 0; index--) {
        gti2FreeSocketConnection(*(GTI2Connection **) ArrayNth(socket->mConnectionsToFree, index));
    }
}

void gti2SocketError(GTI2Socket *socket) {
    if (socket->mError == FALSE) {
        socket->mError = TRUE;
        gt2CloseAllConnectionsHard(socket);
        if (gti2SocketErrorCallback(socket) != FALSE) {
            DeleteSocket(socket);
        }
    }
}
