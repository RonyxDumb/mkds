#include "00/code_021a6d5c.h"
#include "00/code_0218a064.h"

#include "00/code_021a6d6c.h"
#include "03/code_021b94b8.h"
#include "00/code_021a6fb4.h"
#include "00/code_021a6d1c.h"
#include "00/code_021a669c.h"
#include "00/code_021a6934.h"
#include "00/code_021a73d8.h"
#include "00/code_021a8424.h"
#include "00/code_021a8878.h"
#include "00/code_021ad734.h"
#include "os_thread.h"
#include "code_0214d018.h"
#include "00/unk_021b6000.h"
#include "00/code_021a91b4.h"
#include "Main/Unknown/unk_0216f000.h"
#include "00/unk_021b4000.h"
#include "code_02000b44.h"
#include "code_02133048.h"
#include "code_0200fc8c.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a6fc0.h"
#include "00/code_021a88a8.h"
#include "code_0200e77c.h"
#include "00/unk_021b5000.h"
#include "code_0200edc0.h"
#include "00/code_021a72c4.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a78a4.h"
#include "00/code_021a740c.h"
#include "00/code_021a7000.h"
#include "00/code_021ae1e4.h"
#include "00/code_021a7bfc.h"
#include "00/code_021acef8.h"
#include "00/code_02186d04.h"
#include "00/code_021a7bc8.h"
#include "00/code_021ae000.h"
#include "00/code_021a86bc.h"
#include "00/code_021b026c.h"
#include "00/code_021a8a80.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"
#include "os_printf.h"
#include "00/code_021a87bc.h"
#include "00/code_021a75f8.h"
#include "std_string.h"
#include "00/code_021a8604.h"
#include "00/code_021a836c.h"

s32 SOC_Socket(s32 protocolFamily, s32 socketType, s32 protocol) {
    if (socketType == 1) {
        return SOCL_CreateSocket(&SOCLSocketParamTCP);
    }
    return SOCL_CreateSocket(&SOCLSocketParamUDP);
}

s32 SOC_Bind(s32 socket, const void *sockAddr) {
    const SOCSockAddrIn *addr = sockAddr;
    u16 localPort = ((addr->mPort >> 8) & 0xff) | ((addr->mPort << 8) & 0xff00);
    return SOCL_Bind((SOCLSocket *) socket, localPort);
}

s32 SOC_Connect(SOCLSocket *socket, SOCSockAddrIn *sockAddr) {
    u32 networkAddress = sockAddr->mAddr;
    u16 port = ((sockAddr->mPort >> 8) & 0xff) | ((sockAddr->mPort << 8) & 0xff00);
    u32 hostAddress =
        ((networkAddress << 24) & 0xff000000) |
        (((networkAddress << 8) & 0xff0000) | (((networkAddress >> 24) & 0xff) | ((networkAddress >> 8) & 0xff00)));
    return SOCL_Connect(socket, port, (u16 *) hostAddress);
}

s32 SOC_Recv(s32 sockObj, void *buffer, s32 length, s32 flags) {
    u32 noPort = ((0x0u) + (0x0u));
    u32 result = SOCL_ReadFrom(sockObj, buffer, length, noPort, 0x0u, flags);
    return result;
}

s32 SOC_RecvFrom(s32 sockObj, void *buffer, s32 length, s32 flags, void *sockFrom) {
    SOCSockAddrIn *addr;
    u16 netPort;
    u32 remoteIp;
    s32 result = SOCL_ReadFrom(sockObj, buffer, length, (u32) &netPort, &remoteIp, flags);
    if (result >= 0 && sockFrom != NULL) {
        addr = sockFrom;
        addr->mPort = ((netPort >> 8) & 0xff) | ((netPort << 8) & 0xff00);
        addr->mAddr = ((remoteIp << 24) & 0xff000000) |
                      (((remoteIp << 8) & 0xff0000) | (((remoteIp >> 24) & 0xff) | ((remoteIp >> 8) & 0xff00)));
    }
    return result;
}

s32 SOC_Send(s32 sockObj, void *buffer, s32 length, s32 flags) {
    u32 zeroPort = ((0x0u) + (0x0u));
    u32 result = SOCL_WriteTo(sockObj, buffer, length, zeroPort, 0x0u, flags);
    return result;
}

s32 SOC_SendTo(s32 sockObj, void *buffer, s32 length, s32 flags, void *sockTo) {
    SOCSockAddrIn *addr = sockTo;
    u16 netPort;
    u32 remoteIp;
    if (addr != NULL) {
        netPort = ((addr->mPort >> 8) & 0xff) | ((addr->mPort << 8) & 0xff00);
        remoteIp = ((addr->mAddr << 24) & 0xff000000) |
                   (((addr->mAddr << 8) & 0xff0000) | (((addr->mAddr >> 24) & 0xff) | ((addr->mAddr >> 8) & 0xff00)));
    } else {
        netPort = 0;
        remoteIp = 0;
    }
    return SOCL_WriteTo(sockObj, buffer, length, netPort, remoteIp, flags);
}

s32 SOC_Shutdown(s32 descriptor) {
    return SOCL_Shutdown(descriptor);
}

s32 SOC_Close(s32 descriptor) {
    return SOCL_Close(descriptor);
}

SOCHostEnt *SOC_GetHostByName(const char *hostname) {
    u32 hostAddress = SOCL_Resolve(hostname);
    if (hostAddress == 0) {
        return NULL;
    }
    STD_CopyLStringZeroFill((char *) entName, hostname, 0x101);
    hostent.mName = (u8 *) entName;
    hostent.mAliases = NULL;
    hostent.mAddrType = 2;
    hostent.mLength = 4;
    hostent.mAddrList = hostAddrList;
    hostAddrList[0] = &hostip;
    hostAddrList[1] = NULL;
    hostip = ((hostAddress << 24) & 0xff000000) |
             (((hostAddress << 8) & 0xff0000) | (((hostAddress >> 24) & 0xff) | ((hostAddress >> 8) & 0xff00)));
    return &hostent;
}

s32 SOC_GetSockName(u32 socketHandle, void *sockAddr) {
    SOCLSocket *socket = (SOCLSocket *) socketHandle;
    SOCSockAddrIn *addr = sockAddr;
    u32 ownAddr;
    u32 ownPort;
    u16 portValue;
    if (socket == NULL) {
        return -0x27;
    }
    ownAddr = SOCL_GetHostID();
    if (socket != NULL) {
        ownPort = socket->mLocalPort;
    } else {
        ownPort = 0;
    }
    if (ownAddr == 0) {
        ownPort = 0;
    }
    addr->mLen = 8;
    addr->mFamily = 2;
    portValue = ownPort;
    addr->mPort = ((portValue >> 8) & 0xff) | ((portValue << 8) & 0xff00);
    addr->mAddr = ((ownAddr << 24) & 0xff000000) |
                  (((ownAddr << 8) & 0xff0000) | (((ownAddr >> 24) & 0xff) | ((ownAddr >> 8) & 0xff00)));
    return 0;
}

u32 SOC_GetHostID(void) {
    u32 hostValue = (SOCL_GetHostID());
    u32 shiftedLeft24 = ((hostValue) << 24);
    u32 topByteMask = 0xff000000u;
    u32 byte0ToTop = ((shiftedLeft24) & (topByteMask));
    u32 shiftedLeft8 = ((hostValue) << 8);
    u32 thirdByteMask = 0xff0000u;
    u32 byte1ToThird = ((shiftedLeft8) & (thirdByteMask));
    u32 shiftedRight24 = ((hostValue) >> 24);
    u32 byte3ToLow = ((shiftedRight24) & (0xffu));
    u32 shiftedRight8 = ((hostValue) >> 8);
    u32 secondByteMask = 0xff00u;
    u32 byte2ToSecond = ((shiftedRight8) & (secondByteMask));
    u32 lowTwoBytes = ((byte3ToLow) | (byte2ToSecond));
    u32 lowThreeBytes = ((byte1ToThird) | (lowTwoBytes));
    u32 swappedWord = ((byte0ToTop) | (lowThreeBytes));
    u32 result = ((swappedWord) + (0x0u));
    return result;
}

void SOC_SetResolver(u32 *firstDns, u32 *secondDns) {
    u32 secondWord = (*(u32 *) ((secondDns) + (0)));
    u32 firstWord = (*(u32 *) ((firstDns) + (0)));
    u32 firstShiftedLeft24 = ((firstWord) << 24);
    u32 topByteMask = 0xff000000u;
    u32 firstByte0ToTop = ((firstShiftedLeft24) & (topByteMask));
    u32 firstShiftedLeft8 = ((firstWord) << 8);
    u32 thirdByteMask = 0xff0000u;
    u32 firstByte1ToThird = ((firstShiftedLeft8) & (thirdByteMask));
    u32 firstShiftedRight24 = ((firstWord) >> 24);
    u32 firstByte3ToLow = ((firstShiftedRight24) & (0xffu));
    u32 firstShiftedRight8 = ((firstWord) >> 8);
    u32 secondByteMask = 0xff00u;
    u32 firstByte2ToSecond = ((firstShiftedRight8) & (secondByteMask));
    u32 firstLowTwoBytes = ((firstByte3ToLow) | (firstByte2ToSecond));
    u32 firstLowThreeBytes = ((firstByte1ToThird) | (firstLowTwoBytes));
    u32 firstSwapped = ((firstByte0ToTop) | (firstLowThreeBytes));
    u32 firstResult = ((firstSwapped) + (0x0u));
    u32 secondShiftedLeft24 = ((secondWord) << 24);
    u32 topByteMaskCopy = 0xff000000u;
    u32 secondByte0ToTop = ((secondShiftedLeft24) & (topByteMaskCopy));
    u32 secondShiftedLeft8 = ((secondWord) << 8);
    u32 secondByte1ToThird = ((secondShiftedLeft8) & (thirdByteMask));
    u32 secondShiftedRight24 = ((secondWord) >> 24);
    u32 secondByte3ToLow = ((secondShiftedRight24) & (0xffu));
    u32 secondShiftedRight8 = ((secondWord) >> 8);
    u32 secondByte2ToSecond = ((secondShiftedRight8) & (secondByteMask));
    u32 secondLowTwoBytes = ((secondByte3ToLow) | (secondByte2ToSecond));
    u32 secondLowThreeBytes = ((secondByte1ToThird) | (secondLowTwoBytes));
    u32 secondSwapped = ((secondByte0ToTop) | (secondLowThreeBytes));
    u32 secondResult = ((secondSwapped) + (0x0u));
    u32 resolverResult = (SOCL_SetResolver(firstResult, secondResult));
}

s32 SOC_Listen(s32 descriptor) {
    return SOCL_Listen(descriptor);
}

s32 SOC_Accept(SOCLSocket *socket, SOCSockAddrIn *sockAddr, s32 f) {
    u16 remotePort;
    u32 peerAddr;
    s32 result = SOCL_Accept(socket, &remotePort, &peerAddr);
    if (result >= 0) {
        sockAddr->mPort = ((remotePort >> 8) & 0xff) | ((remotePort << 8) & 0xff00);
        sockAddr->mAddr = ((peerAddr << 24) & 0xff000000) |
                          (((peerAddr << 8) & 0xff0000) | (((peerAddr >> 24) & 0xff) | ((peerAddr >> 8) & 0xff00)));
    }
    return result;
}

s32 SOC_Fcntl(SOCLSocket *socket, s32 command, u32 mode) {
    if (socket == NULL) {
        return -1;
    }
    switch (command) {
        case 3:
            if (socket->mFlagBlock == 1) {
                return 0;
            }
            return 4;
        case 4:
            if (mode & 4) {
                socket->mFlagBlock = 0;
            } else {
                socket->mFlagBlock = 1;
            }
            break;
    }
    return 0;
}

void *AllocFunc_SOCL(u32 size) {
    u32 totalSize = size + 4;
    u32 *memory = AllocFunc_SOC(0, totalSize);
    if (memory != NULL) {
        *memory = totalSize;
        memory++;
    }
    return memory;
}

void FreeFunc_SOCL(int memory) {
    if (memory != 0) {
        (*(UnkFunc *) (*(u32 *) &FreeFunc_SOC))(0, (u32 *) (memory + -4), *(u32 *) (memory + -4));
    }
}

s32 SOC_Startup(void *configPointer) {
    SOCConfig *socConfig = configPointer;
    soclConfig.mUseDhcp = socConfig->mFlag == 1 ? 1 : 0;
    soclConfig.mMyIp = ((socConfig->mAddr << 24) & 0xff000000) |
                       (((socConfig->mAddr << 8) & 0xff0000) |
                        (((socConfig->mAddr >> 24) & 0xff) | ((socConfig->mAddr >> 8) & 0xff00)));
    soclConfig.mNetMask = ((socConfig->mNetmask << 24) & 0xff000000) |
                          (((socConfig->mNetmask << 8) & 0xff0000) |
                           (((socConfig->mNetmask >> 24) & 0xff) | ((socConfig->mNetmask >> 8) & 0xff00)));
    soclConfig.mGatewayIp = ((socConfig->mRouter << 24) & 0xff000000) |
                            (((socConfig->mRouter << 8) & 0xff0000) |
                             (((socConfig->mRouter >> 24) & 0xff) | ((socConfig->mRouter >> 8) & 0xff00)));
    soclConfig.mUnk_10 = ((socConfig->mDns1 << 24) & 0xff000000) |
                         (((socConfig->mDns1 << 8) & 0xff0000) |
                          (((socConfig->mDns1 >> 24) & 0xff) | ((socConfig->mDns1 >> 8) & 0xff00)));
    soclConfig.mUnk_14 = ((socConfig->mDns2 << 24) & 0xff000000) |
                         (((socConfig->mDns2 << 8) & 0xff0000) |
                          (((socConfig->mDns2 >> 24) & 0xff) | ((socConfig->mDns2 >> 8) & 0xff00)));
    soclConfig.mAlloc = AllocFunc_SOCL;
    soclConfig.mFree = (void (*)(void *)) FreeFunc_SOCL;
    AllocFunc_SOC = socConfig->mAlloc;
    *(void **) FreeFunc_SOC = socConfig->mFree;
    soclConfig.mCmdPacketMax = 0x40;
    soclConfig.mMtu = socConfig->mMtu;
    soclConfig.mRwin = socConfig->mRwin;
    return SOCL_Startup(&soclConfig);
}

s32 SOC_Cleanup(void) {
    return SOCL_Cleanup();
}

char *SOC_InetNtoA(SOCInAddr address) {
    SOC_InetNtoP(2, &address, sInetNtoABuffer, 0x10);
    return sInetNtoABuffer;
}

BOOL SOC_InetAtoN(u32 addressString, u32 *addressOut) {
    u32 hostAddress = SOCL_InetAtoH(addressString);
    if (hostAddress == 0) {
        return 0;
    }
    *addressOut = ((hostAddress << 24) & 0xff000000) |
                  (((hostAddress << 8) & 0xff0000) | (((hostAddress >> 24) & 0xff) | ((hostAddress >> 8) & 0xff00)));
    return 1;
}

char *SOC_InetNtoP(s32 family, const void *source, char *destination, u32 length) {
    u8 addressBytes[8];
    if (family != 2) {
        return NULL;
    }
    if (length < 0x10) {
        return NULL;
    }
    MI_CpuCopy8(source, addressBytes, 4);
    SOC_U32to4U8(*(u32 *) addressBytes, &addressBytes[4]);
    OS_SNPrintf(destination, 0x10, gInetNtoPFormat, addressBytes[7], addressBytes[6], addressBytes[5], addressBytes[4]);
    return destination;
}

void SOC_U32to4U8(u32 word, u8 *bytes) {
    *bytes = (s8) (word >> 0x18);
    bytes[1] = (s8) (word >> 0x10);
    bytes[2] = (s8) (word >> 8);
    bytes[3] = (s8) word;
}

s32 SOC_Poll(void *entries, s32 entryCount, s64 ticksLeft) {
    SocketPollEntry *entry;
    s32 readyCount;
    u32 index;
    u32 status;
    BOOL hasTimeout;
    hasTimeout = ticksLeft != -1;
    for (;;) {
        entry = entries;
        readyCount = 0;
        for (index = 0; index < entryCount; index++) {
            status = entry->mEvents | 0xe0;
            status &= SOCL_GetStatus(entry->mFd);
            if (status != 0) {
                readyCount++;
            }
            entry->mRevents = status;
            entry++;
        }
        if (readyCount > 0) {
            break;
        }
        if (hasTimeout != FALSE && ticksLeft <= 0) {
            break;
        }
        OS_Sleep(1);
        ticksLeft -= 0x20b;
    }
    return readyCount;
}

void SOCLi_SocketRegister(void *socket) {
    u32 value0 = (u32) socket;
    u32 socketAddress;
    u32 value3;
    socketAddress = (value0) + (0u);
    value0 = (u32) &SOCLiSocketList;
    SOCLi_SocketRegisterList(value0, socketAddress);
}

void SOCLi_SocketRegisterList(u32 listAddress, u32 socketAddress) {
    u32 list = listAddress;
    u32 socket = socketAddress;
    u32 oldHead;
    oldHead = *(const u32 *) ((list) + 0u);
    *(u32 *) ((socket) + 124u) = oldHead;
    *(u32 *) ((list) + 0u) = socket;
}

void SOCLi_SocketRegisterTrash(SOCLSocket *socket) {
    u32 listAddress;
    u32 socketAddress;
    u32 value3;
    socketAddress = ((u32) socket) + (0u);
    listAddress = (u32) &SOCLiSocketListTrash;
    SOCLi_SocketRegisterList(listAddress, socketAddress);
}

void SOCLi_SocketUnregister(SOCLSocket *socket) {
    u32 listAddress;
    u32 socketAddress;
    u32 value3;
    socketAddress = ((u32) socket) + (0u);
    listAddress = (u32) &SOCLiSocketList;
    SOCLi_SocketUnregisterList((SOCLSocket **) listAddress, (SOCLSocket *) socketAddress);
}

void SOCLi_SocketUnregisterList(SOCLSocket **head, SOCLSocket *node) {
    SOCLSocket **link = SOCLi_SocketGetNextPtr(head, node);
    if (link != NULL) {
        *link = node->mNext;
    }
}

SOCLSocket **SOCLi_SocketGetNextPtr(SOCLSocket **head, SOCLSocket *node) {
    SOCLSocket *entry = *head;
    while (entry != NULL) {
        if (entry == node) {
            return head;
        }
        head = &entry->mNext;
        entry = entry->mNext;
    }
    return NULL;
}

void SOCLi_SocketUnregisterTrash(SOCLSocket *socket) {
    u32 listAddress;
    u32 socketAddress;
    u32 value3;
    socketAddress = ((u32) socket) + (0u);
    listAddress = (u32) &SOCLiSocketListTrash;
    SOCLi_SocketUnregisterList((SOCLSocket **) listAddress, (SOCLSocket *) socketAddress);
}

BOOL SOCL_SocketIsInvalid(SOCLSocket *socket) {
    if ((s32) socket <= 0 || SOCLi_SocketGetNextPtr(&SOCLiSocketList, socket) == NULL) {
        return 1;
    }
    return 0;
}

BOOL SOCL_SocketIsInTrash(SOCLSocket *node) {
    if (SOCLi_SocketGetNextPtr(&SOCLiSocketListTrash, node) != NULL) {
        return TRUE;
    }
    return FALSE;
}

u32 SOCLi_RoundUp4(int size) {
    return size + 3U & 0xfffffffc;
}

// The halfword at 0x70 is read again for every test, through a volatile view of the object.
u32 SOCL_GetStatus(SOCLSocket *socket) {
    u32 status = 0;
    u32 interruptState;
    BOOL isTcp;
    volatile SOCLSocket *volatileSocket = socket;
    if (SOCL_SocketIsInvalid(socket) != 0) {
        status |= 0x80;
    } else {
        if ((volatileSocket->mStatusFlags & 0x40) != 0) {
            status |= 0x20;
        }
        if (socket->mFlagMode == 1 || (volatileSocket->mStatusFlags & 4) != 0) {
            interruptState = OS_DisableInterrupts();
            if (SOCLi_GetReadBufferOccpiedSize(socket) > 0) {
                status |= 1;
            }
            if (SOCLi_GetWriteBufferFreeSize(socket) > 0) {
                status |= 8;
            }
            OS_RestoreInterrupts(interruptState);
        }
        isTcp = TRUE;
        if (socket->mFlagMode != 0 && socket->mFlagMode != 4) {
            isTcp = FALSE;
        }
        if (isTcp != FALSE) {
            if ((volatileSocket->mStatusFlags & 4) != 0 && socket->mState != 4 && (status & 1) == 0) {
                volatileSocket->mStatusFlags &= ~6;
            }
            if ((volatileSocket->mStatusFlags & 2) == 0 && (volatileSocket->mStatusFlags & 4) == 0) {
                status |= 0x40;
            }
        }
    }
    return status;
}

s32 SOCLi_GetReadBufferOccpiedSize(SOCLSocket *socket) {
    u32 size;
    SOCLiSocketRecvCommandPipe *inPipe;
    s8 kind;
    inPipe = socket->mReceiveBlock;
    size = 0;
    if (inPipe != NULL) {
        kind = socket->mFlagMode;
        if (kind == 1) {
            if (inPipe->mUdpDataOut != NULL) {
                size = inPipe->mUdpDataOut->mSize;
            }
        } else if ((kind == 0) || (kind == 4)) {
            size = socket->mReceiveBufferLength - inPipe->mConsumed;
        }
    }
    return size;
}

s32 SOCL_Resolve(const char *hostname) {
    CPSSoc soc;
    u8 *memory;
    s32 resolvedAddr;
    if (hostname == NULL) {
        return 0;
    }
    memory = SOCLiConfigPtr->mAlloc(0x1154);
    if (memory == NULL) {
        return 0;
    }
    MI_CpuFill8(&soc, 0, 0x64);
    soc.mReceiveBuffer = memory;
    soc.mReceiveBufferSize = 0xb68;
    soc.mSendBuffer = memory + 0xb68;
    soc.mSendBufferSize = 0x5ea;
    CPS_SocRegister(&soc);
    resolvedAddr = CPS_Resolve(hostname);
    CPS_SocUnRegister();
    SOCLiConfigPtr->mFree(memory);
    return resolvedAddr;
}

s32 SOCL_InetAtoH(u32 hostname) {
    u32 interruptState = OS_DisableInterrupts();
    u32 savedFirstDns = CPSDnsIp[0];
    u32 savedSecondDns = CPSDnsIp[1];
    s32 resolvedAddr;
    CPSDnsIp[0] = 0;
    CPSDnsIp[1] = 0;
    resolvedAddr = CPS_Resolve((const char *) hostname);
    CPSDnsIp[0] = savedFirstDns;
    CPSDnsIp[1] = savedSecondDns;
    OS_RestoreInterrupts(interruptState);
    return resolvedAddr;
}

s32 SOCL_SetResolver(u32 firstDns, u32 secondDns) {
    if (SOCL_GetHostID() == 0) {
        return 0xffffffd9;
    }
    CPSDnsIp[0] = firstDns;
    CPSDnsIp[1] = secondDns;
    return 0;
}

s32 SOCL_GetHostID(void) {
    if (CPSMyIp == 0) {
        if ((SOCLiDhcpState & 3) == 1) {
            if (OS_GetProcMode() != 0x12) {
                OS_Sleep(10);
            }
        }
    } else if (SOCLiRequestedIP == 0) {
        SOCLiRequestedIP = CPSMyIp;
    }
    return CPSMyIp;
}

s32 SOCL_Cleanup(void) {
    s32 result;
    s32 inProgressCode;
    if (SOCLiRequestedIP == 0) {
        SOCLiRequestedIP = CPSMyIp;
    }
    result = SOCL_CalmDown();
    inProgressCode = -0x1a;
    if (result == inProgressCode) {
        do {
            OS_Sleep(100);
        } while (SOCL_CalmDown() == inProgressCode);
    }
    result = SOCLi_CleanupCommandPacketQueue();
    if (result >= 0) {
        CPS_Cleanup();
        CPS_SetScavengerCallback(NULL);
        if (SOCLiConfigPtr->mLanBuf == NULL) {
            SOCLiConfigPtr->mFree(SOCLiCPSConfig.mLanBuf);
        }
        SOCLiConfigPtr = NULL;
    }
    return result;
}

s32 SOCL_CloseAll(void) {
    SOCLSocket *sockObj;
    SOCLSocket *udpSendSocket;
    u32 interruptState;
    for (;;) {
        interruptState = OS_DisableInterrupts();
        sockObj = SOCLiSocketList;
        if (sockObj != NULL) {
            udpSendSocket = SOCLiUDPSendSocket;
            do {
                if (sockObj != udpSendSocket && (sockObj->mStatusFlags & 0x10) == 0) {
                    break;
                }
                sockObj = sockObj->mNext;
            } while (sockObj != NULL);
        }
        OS_RestoreInterrupts(interruptState);
        if (sockObj == NULL) {
            break;
        }
        SOCL_Close((s32) sockObj);
    }
    if (SOCLiSocketList == NULL || (SOCLiSocketList == SOCLiUDPSendSocket && SOCLiSocketList->mNext == NULL)) {
        if (SOCLiSocketListTrash == NULL) {
            return 0;
        }
    }
    return -0x1a;
}

s32 SOCL_CalmDown(void) {
    s32 result;
    SOCL_CloseAll();
    if (SOCLiUDPSendSocket != NULL) {
        result = SOCL_CloseAll();
        if (result == 0) {
            SOCL_Close((s32) SOCLiUDPSendSocket);
            if (SOCL_IsClosed(SOCLiUDPSendSocket) != 0) {
                SOCLiUDPSendSocket = NULL;
            }
            result = -0x1a;
        }
        SOCLi_TrashSocket();
    } else {
        if (CPS_CalmDown() != 0) {
            result = 0;
        } else {
            result = -0x1a;
        }
    }
    return result;
}

BOOL SOCL_IsClosed(SOCLSocket *socket) {
    int checkResult;
    if (((0 <= (s32) socket) && (checkResult = SOCL_SocketIsInvalid(socket), checkResult != 0)) &&
        (checkResult = SOCL_SocketIsInTrash(socket), checkResult == 0)) {
        return 1;
    }
    return 0;
}

static inline s32 SOCL_SocketIsTCP(SOCLSocket *socket) {
    BOOL isTcp = TRUE;
    if (socket->mFlagMode != 0 && socket->mFlagMode != 4) {
        isTcp = FALSE;
    }
    return isTcp;
}

static inline s32 SOCL_SocketIsCreated(SOCLSocket *socket) {
    BOOL isCreated = FALSE;
    if (socket != NULL) {
        isCreated = (socket->mStatusFlags & 1) != 0;
    }
    return isCreated;
}

s32 SOCL_Close(s32 socketHandle) {
    volatile SOCLSocket *volatileSocket;
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    SOCLiCommandPacket *cmdPacket;
    volatileSocket = sockObj;
    if (socketHandle <= 0) {
        return -0x1c;
    }
    if (SOCL_SocketIsInTrash(sockObj) != FALSE) {
        return -0x1a;
    }
    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return 0;
    }
    if (SOCL_SocketIsCreated(sockObj) == 0) {
        return -0x27;
    }
    if ((volatileSocket->mStatusFlags & 0x10) != 0) {
        return -0x1a;
    }
    volatileSocket->mStatusFlags |= 0x18;
    if (SOCL_SocketIsTCP(sockObj) != 0) {
        SOCLi_SendCommandPacket(&sockObj->mSendBlock->mCommandPipe, NULL);
    }
    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_CloseCallBack, sockObj, 1);
    cmdPacket->mFlagBlock = 0;
    return SOCLi_ExecCommandPacketInCtrlPipe(sockObj, cmdPacket);
}

s32 SOCLi_CloseCallBack(SOCLiCommandPacket *command) {
    SOCLSocket *sockObj = command->mSocket;
    void *block;
    u32 interruptState;
    if (SOCL_SocketIsTCP(sockObj) != 0) {
        OS_JoinThread(&sockObj->mSendBlock->mCommandPipe.mThread);
        CPS_TcpShutdown();
        CPS_TcpClose();
        CPS_SocRelease();
    }
    CPS_SocUnRegister();
    sockObj->mStatusFlags &= ~6;
    if (sockObj->mFlagMode == 2) {
        block = sockObj->mSendBlock;
    } else {
        block = sockObj->mReceiveBlock;
    }
    SOCLi_SendCommandPacket(block, NULL);
    interruptState = OS_DisableInterrupts();
    SOCLi_SocketUnregister(sockObj);
    SOCLi_SocketRegisterTrash(sockObj);
    OS_RestoreInterrupts(interruptState);
    sockObj->mStatusFlags |= 0x20;
    return 0;
}

void SOCLi_CleanupSocket(SOCLSocket *socket) {
    SOCLiSocketUdpData *datagram;
    SOCLiSocketUdpData *nextDatagram;
    u32 interruptState;
    if (socket != NULL) {
        socket->mStatusFlags = 0;
        if (SOCL_SocketIsTCP(socket) != 0) {
            SOCLi_FreeCommandPipe(&socket->mSendBlock->mCommandPipe);
            SOCLi_FreeCommandPipe(&socket->mReceiveBlock->mCommandPipe);
        } else if (socket->mFlagMode == 1) {
            datagram = socket->mReceiveBlock->mUdpDataOut;
            while (datagram != NULL) {
                nextDatagram = datagram->mNext;
                SOCLiConfigPtr->mFree(datagram);
                datagram = nextDatagram;
            }
            socket->mReceiveBlock->mUdpDataSize = 0;
            socket->mReceiveBlock->mUdpDataIn = NULL;
            socket->mReceiveBlock->mUdpDataOut = NULL;
            OS_WakeupThread(&socket->mReceiveBlock->mUdpDataWaiting);
            SOCLi_FreeCommandPipe(&socket->mReceiveBlock->mCommandPipe);
        } else if (socket->mFlagMode == 2) {
            SOCLi_FreeCommandPipe(&socket->mSendBlock->mCommandPipe);
        }
        interruptState = OS_DisableInterrupts();
        SOCLi_SocketUnregister(socket);
        SOCLi_SocketUnregisterTrash(socket);
        SOCLiConfigPtr->mFree(socket);
        OS_RestoreInterrupts(interruptState);
    }
}

void SOCLi_FreeCommandPipe(SOCLiSocketCommandPipe *pipe) {
    SOCLiCommandPacket *cmdPacket;
    u32 interruptState;
    if (pipe != NULL) {
        OS_JoinThread(&pipe->mThread);
        interruptState = OS_DisableInterrupts();
        OS_DisableScheduler();
        if (OS_ReceiveMessage(&pipe->mQueue, (void **) &cmdPacket, 0) != 0) {
            do {
                if (cmdPacket != NULL) {
                    if (cmdPacket->mResponse != NULL) {
                        OS_SendMessage(cmdPacket->mResponse, (void *) -11, 0);
                    }
                    SOCLi_FreeCommandPacket(cmdPacket);
                }
            } while (OS_ReceiveMessage(&pipe->mQueue, (void **) &cmdPacket, 0) != 0);
        }
        OS_EnableScheduler();
        OS_RestoreInterrupts(interruptState);
        OSi_RescheduleThread();
    }
}

void SOCLi_TrashSocket(void) {
    u32 interruptState = OS_DisableInterrupts();
    while (SOCLiSocketListTrash != NULL) {
        SOCLi_CleanupSocket(SOCLiSocketListTrash);
    }
    OS_RestoreInterrupts(interruptState);
}

s32 SOCL_Shutdown(s32 socketHandle) {
    volatile SOCLSocket *volatileSocket;
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    SOCLiSocketSendCommandPipe *outPipe;
    SOCLiCommandPacket *cmdPacket;
    volatileSocket = sockObj;
    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return -0x1c;
    }
    if (SOCL_SocketIsCreated(sockObj) == 0) {
        return -0x27;
    }
    if ((volatileSocket->mStatusFlags & 4) == 0 || (volatileSocket->mStatusFlags & 8) != 0) {
        return -0x38;
    }
    volatileSocket->mStatusFlags |= 8;
    outPipe = sockObj->mSendBlock;
    if (outPipe != NULL && outPipe->mExeSocket != NULL) {
        cmdPacket = SOCLi_CreateCommandPacket(SOCLi_ShutdownCallBack, outPipe->mExeSocket, sockObj->mFlagBlock);
        if (cmdPacket == NULL) {
            return -0x21;
        }
        return SOCLi_ExecCommandPacketInSendPipe(outPipe->mExeSocket, cmdPacket);
    }
    return 0;
}

s32 SOCLi_ShutdownCallBack(SOCLiCommandPacket *command) {
    if (SOCL_SocketIsTCP(command->mSocket) != 0) {
        CPS_TcpShutdown();
    }
    return 0;
}

s32 SOCL_WriteTo(u32 socketHandle, void *buffer, u32 length, u16 remotePort, u32 peerAddr, u32 flags) {
    volatile SOCLSocket *volatileSocket;
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    SOCLiSocketSendCommandPipe *outPipe;
    BOOL isBlocking;
    s32 result;
    volatileSocket = sockObj;
    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return -0x1c;
    }
    if (SOCL_SocketIsCreated(sockObj) == 0) {
        return -0x27;
    }
    if (SOCL_SocketIsTCP(sockObj) != 0) {
        if ((volatileSocket->mStatusFlags & 4) == 0 || (volatileSocket->mStatusFlags & 8) != 0) {
            return -0x38;
        }
    }
    outPipe = sockObj->mSendBlock;
    if ((flags & 4) != 0 || sockObj->mFlagBlock == 0) {
        if (OS_TryLockMutex(&outPipe->mCommandPipe.mInUse) == 0) {
            return -6;
        }
        isBlocking = FALSE;
    } else {
        OS_LockMutex(&outPipe->mCommandPipe.mInUse);
        isBlocking = TRUE;
    }
    result = SOCLi_WriteBuffer(sockObj, buffer, length, remotePort, (u16 *) peerAddr, isBlocking);
    OS_UnlockMutex(&outPipe->mCommandPipe.mInUse);
    return result;
}

s32 SOCLi_WriteBuffer(SOCLSocket *socket, u8 *buffer, s32 length, u16 remotePort, u16 *peerAddr, s32 isBlocking) {
    s32 chunkLimit;
    s32 copiedLength;
    s32 writeLength;
    u32 ringIn;
    copiedLength = 0;
    chunkLimit = socket->mSendBlock->mExeSocket->mSendBuffer.mSize;
    if (socket->mFlagMode == 1) {
        chunkLimit -= 0x2a;
        if (length > chunkLimit) {
            return -0x23;
        }
        chunkLimit = length;
    } else {
        chunkLimit -= 0x36;
        if (length <= chunkLimit) {
            chunkLimit = length;
        }
    }
    while (length > 0) {
        writeLength = SOCLi_AllocWriteBuffer(socket, length, chunkLimit, &ringIn, isBlocking);
        if (writeLength > 0) {
            if (SOCLi_ExecWriteCommand(socket, buffer, writeLength, ringIn, remotePort, peerAddr, isBlocking) <= 0) {
                return -6;
            }
            buffer += writeLength;
            length -= writeLength;
            copiedLength += writeLength;
        }
        if (isBlocking == 0) {
            if (writeLength > 0) {
                break;
            }
            return -6;
        }
    }
    return copiedLength;
}

s32 SOCLi_AllocWriteBuffer(SOCLSocket *socket, s32 maxSize, s32 lowestSize, u32 *ringInPtr, s32 isBlocking) {
    SOCLiSocketSendCommandPipe *outPipe = socket->mSendBlock;
    s32 freeSize;
    u32 interruptState;
    if (lowestSize > maxSize) {
        lowestSize = maxSize;
    }
    interruptState = OS_DisableInterrupts();
    for (;;) {
        freeSize = SOCLi_GetWriteBufferFreeSize(socket);
        if (freeSize >= lowestSize) {
            if (freeSize >= maxSize) {
                freeSize = maxSize;
            }
            *ringInPtr = outPipe->mBufferIn;
            break;
        }
        if (isBlocking == 0) {
            freeSize = 0;
            break;
        }
        OS_SleepThread((OSThreadQueue *) &outPipe->mBufferWaitingHead);
    }
    OS_RestoreInterrupts(interruptState);
    return freeSize;
}

s32 SOCLi_GetWriteBufferFreeSize(SOCLSocket *socket) {
    SOCLiSocketSendCommandPipe *outPipe = socket->mSendBlock;
    s32 ringSize = outPipe->mBufferArea.mSize;
    s32 freeSize = outPipe->mBufferIn;
    freeSize = outPipe->mBufferOut - freeSize - 1;
    if (freeSize < 0) {
        freeSize += ringSize;
    }
    return freeSize;
}

s32 SOCLi_ExecWriteCommand(SOCLSocket *socket, u8 *buffer, s32 length, s32 ringIn, u16 remotePort, u16 *peerAddr,
                           s32 isBlocking) {
    SOCLiSocketSendCommandPipe *outPipe = socket->mSendBlock;
    SOCLiCommandWrite *writePacket;
    s32 zero;
    u8 *ringStart;
    s32 ringSize;
    s32 ringEnd;
    writePacket = (SOCLiCommandWrite *) SOCLi_CreateCommandPacket(SOCLi_WriteCallBack, outPipe->mExeSocket, isBlocking);
    if (writePacket == NULL) {
        return -0x21;
    }
    writePacket->mUnk_0d = 0;
    zero = 0;
    ringStart = outPipe->mBufferArea.mStart;
    ringSize = outPipe->mBufferArea.mSize;
    ringEnd = ringIn + length;
    if (ringEnd < ringSize) {
        writePacket->mBuffer1 = ringStart + ringIn;
        writePacket->mBuffer1Len = length;
        writePacket->mBuffer2 = (u8 *) zero;
        writePacket->mBuffer2Len = zero;
        ringIn = ringEnd;
    } else {
        writePacket->mBuffer1 = ringStart + ringIn;
        writePacket->mBuffer1Len = ringSize - ringIn;
        writePacket->mBuffer2 = ringStart;
        writePacket->mBuffer2Len = length - writePacket->mBuffer1Len;
        ringIn = writePacket->mBuffer2Len;
        MI_CpuCopy8(buffer + writePacket->mBuffer1Len, writePacket->mBuffer2, ringIn);
    }
    MI_CpuCopy8(buffer, writePacket->mBuffer1, writePacket->mBuffer1Len);
    writePacket->mWriteBufferAfter = ringIn;
    outPipe->mBufferIn = writePacket->mWriteBufferAfter;
    if (socket->mFlagMode == 1) {
        if (socket->mLocalPort == 0) {
            socket->mLocalPort = CPS_SocGetEport();
            socket->mCpsLocalPort = socket->mLocalPort;
        }
        writePacket->mLocalPort = socket->mLocalPort;
        if (socket->mRemoteIp == NULL || peerAddr != NULL) {
            writePacket->mRemoteIp = peerAddr;
            writePacket->mRemotePort = remotePort;
        } else {
            writePacket->mRemoteIp = socket->mRemoteIp;
            writePacket->mRemotePort = socket->mRemotePort;
        }
    } else {
        writePacket->mRemoteIp = NULL;
    }
    if (SOCLi_ExecCommandPacketInSendPipe(outPipe->mExeSocket, writePacket) != 0) {
        length = 0;
    }
    return length;
}

s32 SOCLi_WriteCallBack(SOCLiCommandPacket *packet) {
    SOCLiCommandWrite *command = (SOCLiCommandWrite *) packet;
    SOCLSocket *sockObj = command->mSocket;
    SOCLiSocketSendCommandPipe *outPipe = sockObj->mSendBlock;
    s32 headerSize;
    u8 *sendBuffer;
    s32 written = 0;
    s32 sendCapacity;
    s32 chunkLength;
    if (SOCL_SocketIsTCP(sockObj) == 0 || (sockObj->mStatusFlags & 4) != 0) {
        if (command->mRemoteIp != NULL) {
            CPS_SocBind(command->mLocalPort, command->mRemotePort, (s32) command->mRemoteIp);
        }
        if (SOCL_SocketIsTCP(sockObj) != 0) {
            headerSize = 0x36;
        } else {
            headerSize = 0x2a;
        }
        sendBuffer = sockObj->mSendBuffer.mStart + headerSize;
        sendCapacity = sockObj->mSendBuffer.mSize - headerSize;
        for (;;) {
            chunkLength = SOCLi_MemCpy(sendBuffer, sendCapacity, command);
            if (chunkLength <= 0) {
                break;
            }
            chunkLength = CPS_SocWrite(sendBuffer, chunkLength);
            if (chunkLength <= 0) {
                if (SOCL_SocketIsTCP(sockObj) != 0) {
                    sockObj->mStatusFlags &= ~0xe;
                }
                written = -0x4c;
                break;
            }
            written += chunkLength;
        }
    } else {
        written = -0x4c;
    }
    outPipe->mBufferOut = command->mWriteBufferAfter;
    OS_WakeupThread((OSThreadQueue *) &outPipe->mBufferWaitingHead);
    return written;
}

s32 SOCLi_MemCpy(const void *destination, s32 capacity, SOCLiCommandWrite *command) {
    s32 firstLength = command->mBuffer1Len;
    s32 secondLength = command->mBuffer2Len;
    if (firstLength > capacity) {
        firstLength = capacity;
        secondLength = 0;
    } else if (secondLength > capacity - firstLength) {
        secondLength = capacity - firstLength;
    }
    if (firstLength > 0) {
        MI_CpuCopy8(command->mBuffer1, destination, firstLength);
        command->mBuffer1 += firstLength;
        command->mBuffer1Len -= firstLength;
    }
    if (secondLength > 0) {
        MI_CpuCopy8(command->mBuffer2, (u8 *) destination + firstLength, secondLength);
        command->mBuffer2 += secondLength;
        command->mBuffer2Len -= secondLength;
    }
    return firstLength + secondLength;
}

s32 SOCL_ReadFrom(u32 socketHandle, void *buffer, u32 length, u32 remotePort, u32 *peerAddr, u32 flags) {
    volatile SOCLSocket *volatileSocket;
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    SOCLiSocketRecvCommandPipe *inPipe;
    s32 i;
    volatileSocket = sockObj;
    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return -0x1c;
    }
    if ((flags & 4) != 0 || sockObj->mFlagBlock == 0) {
        if (sockObj->mFlagMode == 4) {
            return -0x1c;
        }
        i = 0;
    } else {
        if (OS_GetProcMode() == 0x12) {
            return -0x1c;
        }
        i = 1;
    }
    if (SOCL_SocketIsCreated(sockObj) == 0) {
        return -0x27;
    }
    if (SOCL_SocketIsTCP(sockObj) != 0) {
        if ((volatileSocket->mStatusFlags & 4) == 0 || (volatileSocket->mStatusFlags & 8) != 0) {
            return -0x38;
        }
    }
    inPipe = sockObj->mReceiveBlock;
    if (i == 0) {
        if (OS_TryLockMutex(&inPipe->mCommandPipe.mInUse) == 0) {
            return -6;
        }
    } else {
        OS_LockMutex(&inPipe->mCommandPipe.mInUse);
    }
    i = SOCLi_ReadAndConsumeBuffer(sockObj, buffer, length, (u16 *) remotePort, peerAddr, i, flags);
    OS_UnlockMutex(&inPipe->mCommandPipe.mInUse);
    return i;
}

s32 SOCLi_ReadAndConsumeBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr,
                               s32 isBlocking, s32 flags) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    s32 savedNoConsume;
    s32 result;
    BOOL isPeek;
    if ((flags & 2) != 0 && inPipe != NULL) {
        isPeek = TRUE;
    } else {
        isPeek = FALSE;
    }
    if (isPeek != FALSE) {
        savedNoConsume = inPipe->mNoConsume;
        inPipe->mNoConsume = 1;
    }
    if (socket->mFlagMode == 1) {
        result = SOCLi_ReadUdpBuffer(socket, buffer, length, remotePort, peerAddr, isBlocking);
    } else {
        result = SOCLi_ReadBuffer(socket, buffer, length, remotePort, peerAddr, isBlocking);
        if (result >= 0) {
            SOCLi_ConsumeBuffer(socket);
        }
    }
    if (isPeek != FALSE) {
        inPipe->mNoConsume = savedNoConsume;
    }
    return result;
}

s32 SOCLi_ReadBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr, s32 isBlocking) {
    s32 result;
    if (socket->mFlagMode == 4) {
        return SOCLi_ExecReadCommand(socket, (u32) buffer, length, (u32) remotePort, (u32) peerAddr);
    }
    result = SOCLi_CopyCPSBuffer(socket, buffer, length, remotePort, peerAddr);
    if (result == -6 && isBlocking == 1) {
        result = SOCLi_ExecReadCommand(socket, (u32) buffer, length, (u32) remotePort, (u32) peerAddr);
    }
    return result;
}

s32 SOCLi_CopyCPSBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr) {
    u32 interruptState = OS_DisableInterrupts();
    u16 ports[2];
    s32 available;
    u32 remoteAddress;
    u8 *source;
    s32 result;
    source = SOCLi_ReadCPSBuffer(socket, &available, &ports[0], &ports[1], &remoteAddress);
    if (source != NULL) {
        result = available;
        if (result == 0) {
            result = -6;
        } else {
            if (length > result) {
                length = result;
            }
            if (SOCL_SocketIsTCP(socket) != 0) {
                result = length;
            }
            MI_CpuCopy8(source, buffer, length);
            if (socket->mReceiveBlock->mNoConsume == 0) {
                socket->mReceiveBlock->mConsumed = socket->mReceiveBlock->mConsumed + result;
            }
        }
    } else {
        if (available == 0) {
            result = 0;
        } else {
            result = -0x1c;
        }
        socket->mStatusFlags &= ~6;
    }
    if (result >= 0) {
        if (remotePort != NULL && peerAddr != NULL) {
            *remotePort = ports[1];
            *peerAddr = remoteAddress;
        }
        if (socket->mLocalPort == 0) {
            socket->mLocalPort = ports[0];
        }
    }
    OS_RestoreInterrupts(interruptState);
    return result;
}

u8 *SOCLi_ReadCPSBuffer(SOCLSocket *socket, s32 *lengthOut, u16 *localPortOut, u16 *remotePortOut, u32 *remoteIpOut) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    SOCLSocket *cpsSocket = inPipe->mCommandPipe.mThread.mSpecific[0];
    s32 used = inPipe->mConsumed;
    s32 available = cpsSocket->mReceiveBufferLength - used;
    if (available >= 0) {
        *localPortOut = cpsSocket->mCpsLocalPort;
        *remotePortOut = cpsSocket->mCpsRemotePort;
        *remoteIpOut = cpsSocket->mCpsRemoteIp;
        *lengthOut = available;
        if (available == 0 && cpsSocket->mState != 4) {
            return NULL;
        }
    } else {
        *lengthOut = -1;
        return NULL;
    }
    return cpsSocket->mReceiveBuffer.mStart + used;
}

s32 SOCLi_ExecReadCommand(SOCLSocket *socket, u32 buffer, u32 length, u32 remotePort, u32 peerAddr) {
    u32 bufferValue = ((buffer) + (0x0u));
    u32 lengthValue = ((length) + (0x0u));
    u32 remotePortValue = ((remotePort) + (0x0u));
    Unk021a7064Func callback = (Unk021a7064Func) SOCLi_ReadCallBack;
    u32 commandAddress = ((u32) SOCLi_CreateCommandPacket(callback, socket, 0x1u));
    u32 packetAddr = ((commandAddress) + (0x0u));
    u32 remoteIpValue;
    u32 result;
    *(u32 *) ((packetAddr) + (16)) = bufferValue;
    *(u32 *) ((packetAddr) + (20)) = lengthValue;
    *(u32 *) ((packetAddr) + (24)) = remotePortValue;
    remoteIpValue = peerAddr;
    *(u32 *) ((packetAddr) + (28)) = remoteIpValue;
    result = SOCLi_ExecCommandPacketInRecvPipe(socket, (SOCLiCommandPacket *) packetAddr);
    return result;
}

s32 SOCLi_ReadCallBack(SOCLiCommandPacket *packet) {
    SOCLiCommandRead *command = (SOCLiCommandRead *) packet;
    SOCLSocket *sockObj = command->mSocket;
    SOCLiSocketRecvCommandPipe *inPipe = sockObj->mReceiveBlock;
    u8 *buffer = command->mBuffer;
    u32 length = command->mBufferLen;
    u16 *remotePort = command->mRemotePort;
    u32 *peerAddr = command->mRemoteIp;
    s32 h = inPipe->mConsumed;
    const u8 *gotData;
    s32 cpsLength;
    BOOL isTcp;
    for (;;) {
        gotData = CPS_SocRead((u32 *) &cpsLength);
        if (gotData == NULL) {
            break;
        }
        if (cpsLength - h > 0) {
            break;
        }
        isTcp = TRUE;
        if (sockObj->mFlagMode != 0 && sockObj->mFlagMode != 4) {
            isTcp = FALSE;
        }
        if (isTcp != FALSE && sockObj->mState != 4) {
            gotData = NULL;
            break;
        }
        OS_Sleep(10);
    }
    if (sockObj->mFlagMode == 4) {
        if (gotData == NULL) {
            return 0;
        }
        if (length > cpsLength) {
            length = cpsLength;
        }
        MI_CpuCopy8(gotData, buffer, length);
        CPS_SocConsume(length);
        return length;
    }
    if (gotData != NULL) {
        h = SOCLi_CopyCPSBuffer(sockObj, buffer, length, remotePort, peerAddr);
    } else {
        h = 0;
    }
    if (h <= 0) {
        return h;
    }
    if (inPipe->mConsumed >= inPipe->mConsumedMin) {
        SOCLi_ConsumeCPSBuffer(sockObj);
    }
    return h;
}

static inline s32 ReadUdpSOCL_SocketIsCreated(SOCLSocket *socket) {
    BOOL isCreated = FALSE;
    if (socket != NULL) {
        isCreated = (socket->mStatusFlags & 1) != 0;
    }
    return isCreated;
}

s32 SOCLi_ConsumeBuffer(SOCLSocket *socket) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    SOCLiCommandPacket *cmdPacket;
    if (inPipe->mConsumed < inPipe->mConsumedMin) {
        return 0;
    }
    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_ConsumeCallBack, socket, 0);
    if (cmdPacket == NULL) {
        return -0x21;
    }
    return SOCLi_ExecCommandPacketInRecvPipe(socket, cmdPacket);
}

s32 SOCLi_ConsumeCallBack(SOCLiCommandPacket *command) {
    return SOCLi_ConsumeCPSBuffer(command->mSocket);
}

s32 SOCLi_ConsumeCPSBuffer(SOCLSocket *socket) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    u32 interruptState = OS_DisableInterrupts();
    s32 used = inPipe->mConsumed;
    if (used != 0) {
        inPipe->mConsumed = 0;
        CPS_SocConsume(used);
    }
    OS_RestoreInterrupts(interruptState);
    return used;
}

s32 SOCLi_ReadUdpBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr, s32 isBlocking) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    u32 interruptState;
    s32 result;
    SOCLiSocketUdpData *datagram;
    *(SOCLiSocketUdpData *volatile *) &inPipe->mUdpDataOut;
    interruptState = OS_DisableInterrupts();
    datagram = inPipe->mUdpDataOut;
    while (datagram == NULL) {
        if (isBlocking == 0) {
            result = -6;
            break;
        }
        OS_SleepThread(&inPipe->mUdpDataWaiting);
        if (SOCL_SocketIsInvalid(socket) != 0 || ReadUdpSOCL_SocketIsCreated(socket) == 0) {
            result = -0x38;
            break;
        }
        datagram = inPipe->mUdpDataOut;
    }
    if (datagram != NULL) {
        if (length > datagram->mSize) {
            length = datagram->mSize;
        }
        MI_CpuCopy8(datagram->mData, buffer, length);
        if (remotePort != NULL) {
            *remotePort = datagram->mRemotePort;
        }
        if (peerAddr != NULL) {
            *peerAddr = datagram->mRemoteIp;
        }
        result = datagram->mSize;
        if (inPipe->mNoConsume == 0) {
            inPipe->mUdpDataOut = datagram->mNext;
            if (datagram->mNext == NULL) {
                inPipe->mUdpDataIn = NULL;
            }
            SOCLiConfigPtr->mFree(datagram);
            inPipe->mUdpDataSize -= result;
        }
    }
    OS_RestoreInterrupts(interruptState);
    return result;
}

s32 SOCLi_UdpRecvCallback(void *data, u32 length, SOCLSocket *socket) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    u32 interruptState = OS_DisableInterrupts();
    if (inPipe->mUdpDataSizeMax >= inPipe->mUdpDataSize + length) {
        SOCLiSocketUdpData *datagram = SOCLiConfigPtr->mAlloc(length + 0xc);
        if (datagram != NULL) {
            inPipe->mUdpDataSize += length;
            datagram->mNext = NULL;
            datagram->mSize = length;
            datagram->mRemotePort = socket->mCpsRemotePort;
            datagram->mRemoteIp = socket->mCpsRemoteIp;
            MI_CpuCopy8(data, datagram->mData, length);
            if (socket->mLocalPort == 0) {
                socket->mLocalPort = socket->mCpsLocalPort;
            }
            socket->mCpsRemotePort = socket->mCpsRemotePortBound;
            socket->mCpsRemoteIp = socket->mCpsRemoteIpBound;
            if (((const SOCLiSocketRecvCommandPipe *) inPipe)->mUdpDataIn != NULL) {
                inPipe->mUdpDataIn->mNext = datagram;
            }
            inPipe->mUdpDataIn = datagram;
            if (inPipe->mUdpDataOut == NULL) {
                inPipe->mUdpDataOut = datagram;
            }
        } else {
            SOCLi_CheckCount[0]++;
        }
    } else {
        SOCLi_CheckCount[1]++;
    }
    OS_WakeupThread(&inPipe->mUdpDataWaiting);
    OS_RestoreInterrupts(interruptState);
    return 1;
}

s32 SOCL_Bind(SOCLSocket *socket, u16 ownPort) {
    BOOL isCreated;
    if (SOCL_SocketIsInvalid(socket) != 0) {
        return -28;
    }
    isCreated = FALSE;
    if (socket != NULL) {
        isCreated = (socket->mStatusFlags & 1) != 0;
    }
    if (isCreated == FALSE) {
        return -39;
    }
    if (socket->mStatusFlags & 2) {
        return -7;
    }
    socket->mLocalPort = ownPort;
    if (socket->mFlagMode == 1) {
        return SOCLi_ExecBindCommand(socket);
    }
    return 0;
}

s32 SOCL_Connect(SOCLSocket *socket, u16 remotePort, u16 *peerAddr) {
    s32 result;
    BOOL condition;
    volatile SOCLSocket *volatileSocket = socket;

    if (SOCL_SocketIsInvalid(socket) != 0 || (volatileSocket->mStatusFlags & 8)) {
        return -28;
    }
    condition = FALSE;
    if (socket != NULL) {
        condition = (socket->mStatusFlags & 1) != 0;
    }
    if (condition == FALSE) {
        return -39;
    }
    condition = TRUE;
    if (socket->mFlagMode != 0 && socket->mFlagMode != 4) {
        condition = FALSE;
    }
    if (condition != FALSE) {
        if (volatileSocket->mStatusFlags & 4) {
            if (socket->mFlagBlock == 1) {
                return -30;
            }
            return 0;
        }
        if (volatileSocket->mStatusFlags & 2) {
            if (volatileSocket->mStatusFlags & 0x40) {
                return socket->mEntryResult;
            }
            return SOCLiResultCodeInConnecting;
        }
        socket->mRemotePort = remotePort;
        socket->mRemoteIp = peerAddr;
        result = SOCLi_ExecBindCommand(socket);
        if (socket->mFlagBlock == 1) {
            return result;
        }
        return -26;
    }
    socket->mRemotePort = remotePort;
    socket->mRemoteIp = peerAddr;
    return 0;
}

s32 SOCLi_ExecBindCommand(SOCLSocket *socket) {
    SOCLiCommandPacket *cmdPacket;

    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_BindCallBack, socket, socket->mFlagBlock);
    if (cmdPacket == NULL) {
        return -33;
    }
    cmdPacket->mUnk_10 = socket->mLocalPort;
    cmdPacket->mUnk_12 = socket->mRemotePort;
    cmdPacket->mUnk_14 = socket->mRemoteIp;
    socket->mStatusFlags |= 2;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, cmdPacket);
}

s32 SOCLi_BindCallBack(SOCLiCommandPacket *packet) {
    SOCLSocket *sockObj;
    SOCLiSocketRecvCommandPipe *inPipe;
    s32 connectResult;

    sockObj = packet->mSocket;
    connectResult = 0;
    inPipe = sockObj->mReceiveBlock;
    OS_LockMutex(&inPipe->mCommandPipe.mInUse);
    CPS_SocBind(packet->mUnk_10, packet->mUnk_12, (s32) packet->mUnk_14);
    inPipe->mConsumed = 0;
    if (packet->mFlagMode == 0 || packet->mFlagMode == 4) {
        connectResult = CPS_TcpConnect();
    }
    OS_UnlockMutex(&inPipe->mCommandPipe.mInUse);
    if (connectResult != 0) {
        sockObj->mStatusFlags |= 0x40;
        return -76;
    }
    sockObj->mStatusFlags |= 4;
    return 0;
}

s32 SOCL_Listen(s32 socketHandle) {
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    BOOL condition;

    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return -28;
    }
    condition = FALSE;
    if (sockObj != NULL) {
        condition = (sockObj->mStatusFlags & 1) != 0;
    }
    if (condition == FALSE) {
        return -39;
    }
    if (sockObj->mStatusFlags & 2) {
        return -28;
    }
    condition = TRUE;
    if (sockObj->mFlagMode != 0 && sockObj->mFlagMode != 4) {
        condition = FALSE;
    }
    if (condition == FALSE) {
        return -28;
    }
    if (sockObj->mFlagBlock == 1) {
        return 0;
    }
    return -6;
}

s32 SOCL_Accept(SOCLSocket *socket, u16 *remotePortOut, u32 *remoteIpOut) {
    s32 acceptSocket;
    BOOL condition;
    s32 result;

    if (SOCL_SocketIsInvalid(socket) != 0) {
        return -28;
    }
    condition = FALSE;
    if (socket != NULL) {
        condition = (socket->mStatusFlags & 1) != 0;
    }
    if (condition == FALSE) {
        return -39;
    }
    if (socket->mStatusFlags & 2) {
        return -28;
    }
    condition = TRUE;
    if (socket->mFlagMode != 0 && socket->mFlagMode != 4) {
        condition = FALSE;
    }
    if (condition == FALSE) {
        return -28;
    }
    if (socket->mFlagBlock != 1) {
        return -6;
    }
    acceptSocket = SOCL_CreateSocket(&SOCLSocketParamTCP);
    if (acceptSocket < 0) {
        return acceptSocket;
    }
    result = SOCL_Bind((SOCLSocket *) acceptSocket, socket->mLocalPort);
    if (result < 0) {
        return result;
    }
    result = SOCL_ListenAccept((SOCLSocket *) acceptSocket, remotePortOut, remoteIpOut);
    if (result < 0) {
        return result;
    }
    return acceptSocket;
}

s32 SOCL_ListenAccept(SOCLSocket *socket, u16 *remotePortOut, u32 *remoteIpOut) {
    SOCLiCommandPacket *cmdPacket;
    BOOL condition;
    s32 c;

    if (SOCL_SocketIsInvalid(socket) != 0) {
        return -28;
    }
    condition = FALSE;
    if (socket != NULL) {
        condition = (socket->mStatusFlags & 1) != 0;
    }
    if (condition == FALSE) {
        return -39;
    }
    if (socket->mStatusFlags & 2) {
        return -28;
    }
    condition = TRUE;
    if (socket->mFlagMode != 0 && socket->mFlagMode != 4) {
        condition = FALSE;
    }
    if (condition == FALSE) {
        return -28;
    }
    if (socket->mFlagBlock != 1) {
        return -6;
    }
    if (socket->mLocalPort == 0) {
        return -28;
    }
    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_ListenAcceptCallBack, socket, socket->mFlagBlock);
    cmdPacket->mUnk_10 = socket->mLocalPort;
    cmdPacket->mUnk_14 = remotePortOut;
    cmdPacket->mUnk_18 = remoteIpOut;
    socket->mStatusFlags |= 2;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, cmdPacket);
}

s32 SOCLi_ListenAcceptCallBack(SOCLiCommandPacket *packet) {
    SOCLSocket *sockObj;
    SOCLiSocketRecvCommandPipe *inPipe;
    u16 remotePort;
    u32 ownAddr;
    u32 peerAddr;

    sockObj = packet->mSocket;
    inPipe = sockObj->mReceiveBlock;
    OS_LockMutex(&inPipe->mCommandPipe.mInUse);
    CPS_SocBind(packet->mUnk_10, 0, 0);
    CPS_TcpListen();
    inPipe->mConsumed = 0;
    peerAddr = CPS_SocWho(&remotePort, &ownAddr);
    *packet->mUnk_14 = remotePort;
    *packet->mUnk_18 = peerAddr;
    sockObj->mStatusFlags |= 4;
    OS_UnlockMutex(&inPipe->mCommandPipe.mInUse);
    return 0;
}

s32 SOCL_CreateSocket(SOCLSocketParam *param) {
    SOCLSocket *sockObj;
    SOCLiCommandPacket *cmdPacket;
    sockObj = SOCLi_StartupSocket(param);
    if (sockObj == NULL) {
        return -0x31;
    }
    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_CreateSocketCallBack, sockObj, 1);
    SOCLi_ExecCommandPacketInCtrlPipe(sockObj, cmdPacket);
    return (s32) sockObj;
}

s32 SOCLi_CreateSocketCallBack(SOCLiCommandPacket *command) {
    SOCLSocket *sockObj;
    SOCLiSocketCommandPipe *outPipe;

    sockObj = command->mSocket;
    CPS_SocRegister(sockObj);
    outPipe = &sockObj->mSendBlock->mCommandPipe;
    switch (sockObj->mFlagMode) {
        case 0:
        case 4:
            CPS_SocDup(&outPipe->mThread);
            CPS_SocUse();
            break;
        case 1:
            CPS_SocUse();
            CPS_SocDatagramMode();
            CPS_SetUdpCallback(SOCLi_UdpRecvCallback);
            break;
        case 2:
            CPS_SocDatagramMode();
            break;
        case 3:
            break;
    }
    sockObj->mStatusFlags = 1;
    return 0;
}

SOCLSocket *SOCLi_StartupSocket(SOCLSocketParam *param) {
    s32 size;
    u32 interruptState;
    SOCLSocket *sockObj;

    size = SOCLi_GetSizeSocket(param);
    interruptState = OS_DisableInterrupts();
    sockObj = SOCLiConfigPtr->mAlloc(size);
    if (sockObj != NULL) {
        MI_CpuFill8(sockObj, 0, size);
        SOCLi_InitSocket(sockObj, param);
        SOCLi_SocketRegister(sockObj);
    }
    OS_RestoreInterrupts(interruptState);
    return sockObj;
}

s32 SOCLi_GetSizeSocket(SOCLSocketParam *param) {
    s32 size = 0x80;

    if (param->mRcvbufSize != 0) {
        size += 0x114;
        size += SOCLi_RoundUp4(param->mRcvbufSize);
        size += SOCLi_RoundUp4(param->mLinbufSize);
        size += SOCLi_GetSizeCommandPipe(&param->mRecvPipe);
    }
    if (param->mSndbufSize != 0) {
        size += 0x110;
        size += SOCLi_RoundUp4(param->mSndbufSize);
        size += SOCLi_RoundUp4(param->mOutbufSize);
        size += SOCLi_RoundUp4(param->mWrtbufSize);
        size += SOCLi_GetSizeCommandPipe(&param->mSendPipe);
    }
    return size;
}

int SOCLi_GetSizeCommandPipe(SOCLSocketCommandPipeParam *param) {
    int queueSize;
    int stackSize;
    queueSize = SOCLi_RoundUp4(param->mQueueMax << 2);
    stackSize = SOCLi_RoundUp4(param->mStackSize);
    return queueSize + stackSize;
}

u8 *SOCLi_InitSocket(SOCLSocket *socket, SOCLSocketParam *param) {
    u8 *cursor;
    SOCLiSocketRecvCommandPipe *inPipe;
    SOCLiSocketSendCommandPipe *outPipe;

    socket->mFlagMode = param->mFlagMode;
    socket->mFlagBlock = param->mFlagBlock;
    cursor = (u8 *) &socket->mUnk_80;
    if (param->mRcvbufSize != 0) {
        inPipe = &socket->mUnk_80;
        socket->mReceiveBlock = inPipe;
        inPipe->mConsumedMin = param->mRcvbufConsumeMin;
        cursor = SOCLi_InitCommandPipe(inPipe->mCommandMessages, &inPipe->mCommandPipe, &param->mRecvPipe);
        cursor = SOCLi_InitSocketBuffer(cursor, &socket->mReceiveBuffer, param->mRcvbufSize);
        cursor = SOCLi_InitSocketBuffer(cursor, &socket->mUnk_50, param->mLinbufSize);
        inPipe->mUdpDataSizeMax = param->mUdpbufSize;
        inPipe->mUdpDataWaiting.mTail = NULL;
        inPipe->mUdpDataWaiting.mHead = inPipe->mUdpDataWaiting.mTail;
    }
    if (param->mSndbufSize != 0) {
        outPipe = (SOCLiSocketSendCommandPipe *) cursor;
        socket->mSendBlock = outPipe;
        outPipe->mExeSocket = socket;
        cursor = SOCLi_InitCommandPipe(outPipe->mCommandMessages, &outPipe->mCommandPipe, &param->mSendPipe);
        cursor = SOCLi_InitSocketBuffer(cursor, &socket->mSendBuffer, param->mSndbufSize);
        cursor = SOCLi_InitSocketBuffer(cursor, &socket->mUnk_58, param->mOutbufSize);
        cursor = SOCLi_InitSocketBuffer(cursor, &outPipe->mBufferArea, param->mWrtbufSize);
        outPipe->mBufferWaitingTail = 0;
        outPipe->mBufferWaitingHead = outPipe->mBufferWaitingTail;
    } else {
        socket->mSendBlock = SOCLiUDPSendSocket->mSendBlock;
    }
    return cursor;
}

u8 *SOCLi_InitSocketBuffer(u8 *cursor, SizedBuffer *buffer, s32 size) {
    u8 *start;
    start = cursor;
    if (size == 0) {
        start = NULL;
    }
    buffer->mStart = start;
    buffer->mSize = size;
    return cursor + SOCLi_RoundUp4(size);
}

u8 *SOCLi_InitCommandPipe(u8 *messages, SOCLiSocketCommandPipe *pipe, SOCLSocketCommandPipeParam *param) {
    u8 *stackBottom;

    stackBottom = messages + SOCLi_GetSizeCommandPipe(param);
    OS_InitMessageQueue(&pipe->mQueue, (void **) messages, param->mQueueMax);
    OS_InitMutex(&pipe->mInUse);
    OS_CreateThread(&pipe->mThread, SOCLi_CommandPacketHandler, pipe, stackBottom, param->mStackSize, param->mPriority);
    OS_WakeupThreadDirect(&pipe->mThread);
    return stackBottom;
}

s32 SOCLi_StartupCommandPacketQueue(s32 count) {
    s32 queueBytes;
    void **messages;
    SOCLiCommandPacket *packet;
    s32 packetBytes;

    queueBytes = (count * 4 + 3) & ~3;
    packetBytes = (count * 0x2c + 3) & ~3;
    messages = SOCLiConfigPtr->mAlloc(packetBytes + queueBytes);
    if (messages == NULL) {
        return -1;
    }
    OS_InitMessageQueue(&SOCLiCommandPacketQueue, messages, count);
    packet = OFFSET_PTR(SOCLiCommandPacket, messages, queueBytes);
    if (count > 0) {
        do {
            SOCLi_FreeCommandPacket(packet);
            packet++;
            count--;
        } while (count > 0);
    }
    SOCLiCommandPackets = messages;
    return 0;
}

s32 SOCLi_CleanupCommandPacketQueue(void) {
    if (SOCLiCommandPacketQueue.mCount < SOCLiCommandPacketQueue.mCapacity) {
        return -1;
    }
    SOCLiConfigPtr->mFree(SOCLiCommandPackets);
    SOCLiCommandPackets = NULL;
    return 0;
}

SOCLiCommandPacket *SOCLi_AllocCommandPacket(s32 flag) {
    int received;
    SOCLiCommandPacket *packet[1];
    received = OS_ReceiveMessage(&SOCLiCommandPacketQueue, (void **) packet, flag);
    if (received != 0) {
        return packet[0];
    }
    return NULL;
}

SOCLiCommandPacket *SOCLi_CreateCommandPacket(Unk021a7064Func handler, SOCLSocket *socket, s32 flag) {
    SOCLiCommandPacket *packet;

    packet = SOCLi_AllocCommandPacket(flag);
    if (packet != NULL) {
        packet->mHandler = handler;
        packet->mSocket = socket;
        packet->mFlagBlock = flag;
        packet->mFlagMode = socket->mFlagMode;
    }
    return packet;
}

void SOCLi_FreeCommandPacket(SOCLiCommandPacket *packet) {
    if (packet != NULL) {
        OS_SendMessage(&SOCLiCommandPacketQueue, (packet), 0);
    }
}

s32 SOCLi_SendCommandPacket(SOCLiSocketCommandPipe *pipe, SOCLiCommandPacket *packet) {
    s32 result;

    result = OS_SendMessage(&pipe->mQueue, packet, packet != NULL ? packet->mFlagBlock : 1);
    if (result == 0) {
        SOCLi_FreeCommandPacket(packet);
    }
    if (result != 0) {
        return 0;
    }
    return -42;
}

s32 SOCLi_ExecCommandPacket(SOCLiSocketCommandPipe *pipe, SOCLiCommandPacket *packet) {
    s32 result;
    void *response;
    OSMessageQueue replyQueue;

    if (packet->mFlagBlock == 0) {
        packet->mResponse = NULL;
        result = SOCLi_SendCommandPacket(pipe, packet);
    } else {
        OS_InitMessageQueue(&replyQueue, &response, 1);
        packet->mResponse = &replyQueue;
        SOCLi_SendCommandPacket(pipe, packet);
        OS_ReceiveMessage(&replyQueue, (void **) &result, 1);
    }
    return result;
}

s32 SOCLi_ExecCommandPacketInRecvPipe(SOCLSocket *socket, SOCLiCommandPacket *packet) {
    return SOCLi_ExecCommandPacket(&socket->mReceiveBlock->mCommandPipe, packet);
}

s32 SOCLi_ExecCommandPacketInSendPipe(SOCLSocket *socket, void *packet) {
    return SOCLi_ExecCommandPacket(&socket->mSendBlock->mCommandPipe, packet);
}

s32 SOCLi_ExecCommandPacketInCtrlPipe(SOCLSocket *socket, SOCLiCommandPacket *packet) {
    if (socket->mReceiveBlock != NULL) {
        return SOCLi_ExecCommandPacket(&socket->mReceiveBlock->mCommandPipe, packet);
    }
    return SOCLi_ExecCommandPacket(&socket->mSendBlock->mCommandPipe, packet);
}

void SOCLi_CommandPacketHandler(void *queueArgument) {
    OSMessageQueue *queue = queueArgument;
    SOCLiCommandPacket *packet;
    s32 result;
    u32 interruptState;

    while (1) {
        OS_ReadMessage(queue, (void **) &packet, 1);
        if (packet == NULL) {
            return;
        }
        result = packet->mHandler(packet);
        interruptState = OS_DisableInterrupts();
        OS_DisableScheduler();
        OS_ReceiveMessage(queue, NULL, 0);
        if (packet->mSocket != NULL) {
            packet->mSocket->mEntryResult = result;
        }
        if (packet->mResponse != NULL) {
            OS_SendMessage(packet->mResponse, (void *) result, 0);
        }
        SOCLi_FreeCommandPacket(packet);
        OS_EnableScheduler();
        OS_RestoreInterrupts(interruptState);
        OSi_RescheduleThread();
    }
}

s32 SOCL_Startup(SOCLConfig *config) {
    OSi_ReferSymbol(0x2000bbc);
    if (SOCLiConfigPtr != NULL) {
        return 0;
    }
    SOCLiConfigPtr = config;
    SOCLi_StartupCPS();
    return SOCLi_StartupSOCL();
}

s32 SOCLi_StartupSOCL(void) {
    s32 result;

    result = SOCLi_StartupCommandPacketQueue(SOCLiConfigPtr->mCmdPacketMax);
    if (result >= 0) {
        SOCLiUDPSendSocket = (SOCLSocket *) SOCL_CreateSocket(&SOCLSocketParamUDPSend);
    }
    return result;
}

void SOCLi_StartupCPS(void) {
    CPSConfig *cfgBlock = &SOCLiCPSConfig;
    SOCLConfig *config = SOCLiConfigPtr;
    s32 c;
    s32 rwin;

    MI_CpuFill8(cfgBlock, 0, 0x30);
    cfgBlock->mAlloc = config->mAlloc;
    cfgBlock->mFree = config->mFree;
    cfgBlock->mLinkIsOn = SOCL_LinkIsOn;
    cfgBlock->mRandomSeedLow = 0;
    cfgBlock->mRandomSeedHigh = 0;
    cfgBlock->mYieldWait = *(u32 *) SOCLiYieldWait;
    if (config->mLanBufLen != 0) {
        cfgBlock->mLanBufLen = config->mLanBufLen;
    } else {
        cfgBlock->mLanBufLen = 0x4000;
    }
    if (config->mLanBuf != NULL) {
        cfgBlock->mLanBuf = config->mLanBuf;
    } else {
        cfgBlock->mLanBuf = SOCLiConfigPtr->mAlloc(cfgBlock->mLanBufLen);
    }
    c = config->mMtu;
    if (c == 0) {
        c = 0x240;
    }
    rwin = config->mRwin;
    if (rwin == 0) {
        rwin = 0x10c0;
    }
    cfgBlock->mMyMss = c - 0x28;
    SOCLSocketParamTCP.mRcvbufSize = rwin;
    SOCLSocketParamTCP.mRcvbufConsumeMin = rwin / 2;
    CPSMyIp = 0;
    if (config->mUseDhcp != 0) {
        SOCLiDhcpState = 1;
        cfgBlock->mMode = 0;
        cfgBlock->mDhcpCallback = SOCLi_DhcpTimeout;
        cfgBlock->mRequestedIp = SOCLiRequestedIP;
    } else {
        SOCLiDhcpState = 0;
        cfgBlock->mMode = 1;
        cfgBlock->mDhcpCallback = SOCLi_SetMyIP;
    }
    c = config->mCpsThreadPriority;
    if (c == 0) {
        c = 0xb;
    }
    CPS_SetThreadPriority(c);
    WCM_SetRecvDCFCallback(CPSi_RecvCallbackFunc);
    CPS_SetScavengerCallback(SOCLi_TrashSocket);
    CPS_Startup(cfgBlock);
}

void SOCLi_SetMyIP(void) {
    SOCLConfig *config = SOCLiConfigPtr;

    CPSMyIp = config->mMyIp;
    CPSNetMask = config->mNetMask;
    CPSGatewayIp = config->mGatewayIp;
    CPSDnsIp[0] = config->mUnk_10;
    CPSDnsIp[1] = config->mUnk_14;
    SOCLiDhcpState |= 2;
}

void SOCLi_DhcpTimeout(void) {
    SOCLiDhcpState |= 2;
}
