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
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_021919ac.h"
#include "00/code_0219a000.h"
#include "00/code_0219a5e8.h"
#include "00/code_0219a604.h"
#include "00/code_021a3668.h"
#include "00/code_0219a654.h"

typedef struct Unk0219a430Addr {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0219a430Addr;

void gti2ConnectionFree(Gt2Connection **element) {
    gti2ConnectionCleanup(*element);
}

Gt2Connection *FindConnection(Gt2Socket *socket, u32 address, u32 port) {
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

u32 CreateSocket(Gt2Socket **socketOut, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                 u32 errorCallback) {
    Gt2Socket *newSocket;
    u16 netPort;
    Unk0219a430Addr socketAddress;
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
    if (Gt2ParseAddress(localAddress, &address, &netPort) == FALSE) {
        return 4;
    }
    newSocket = func_ov000_021a3690(0x44);
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
        func_ov000_021a3668(newSocket);
        return 1;
    }
    newSocket->mConnectionsToFree = DarrayCreate(4, 4, (void (*)(void *)) & gti2ConnectionFree);
    if (newSocket->mConnectionsToFree == NULL) {
        HashtableDelete(newSocket->mConnections);
        func_ov000_021a3668(newSocket);
        return 1;
    }
    newSocket->mDescriptor = OpenNetSocket(2, 2, 0);
    if (newSocket->mDescriptor == -1) {
        HashtableDelete(newSocket->mConnections);
        DarrayDelete(newSocket->mConnectionsToFree);
        func_ov000_021a3668(newSocket);
        return 3;
    }
    bindWords = (u32 *) &socketAddress;
    bindWords[0] = 0;
    bindWords[1] = 0;
    socketAddress.mUnk_01 = 2;
    socketAddress.mUnk_04 = address;
    socketAddress.mUnk_02 = ((netPort >> 8) & 0xff) | ((netPort << 8) & 0xff00);
    if (bind(newSocket->mDescriptor, &socketAddress, 8) == -1) {
        closesocket(newSocket->mDescriptor);
        HashtableDelete(newSocket->mConnections);
        DarrayDelete(newSocket->mConnectionsToFree);
        func_ov000_021a3668(newSocket);
        return 3;
    }
    addressLength = 8;
    getsockname(newSocket->mDescriptor, &socketAddress, (u32 *) &addressLength);
    newSocket->mAddress = socketAddress.mUnk_04;
    newSocket->mPort = ((socketAddress.mUnk_02 >> 8) & 0xff) | ((socketAddress.mUnk_02 << 8) & 0xff00);
    *socketOut = newSocket;
    return 0;
}
