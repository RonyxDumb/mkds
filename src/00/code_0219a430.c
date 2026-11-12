#include "00/code_0219a430.h"
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
#include "00/code_02197e58.h"
#include "00/gt2Connection.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_021919ac.h"
#include "00/code_0219a000.h"
#include "00/code_0219a5e8.h"
#include "00/code_0219a604.h"
#include "00/code_021a3668.h"
#include "00/code_0219a654.h"

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
