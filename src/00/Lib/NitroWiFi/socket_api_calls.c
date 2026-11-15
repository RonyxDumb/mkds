#include "00/Lib/NitroWiFi/socket_api_calls.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"
#include "00/Lib/DWC/socket_config.h"

#include "00/Lib/NitroWiFi/socl_startup_commands.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/NitroWiFi/socket_command_packet.h"
#include "00/Lib/NitroWiFi/link_on_and_bssid_compare.h"
#include "00/Lib/NitroWiFi/access_point_list.h"
#include "00/Lib/NitroWiFi/wifi_stack_bridge.h"
#include "00/Lib/NitroWiFi/socket_create_call.h"
#include "00/Lib/NitroWiFi/dns_resolver_setting.h"
#include "00/Lib/CPS/tcp_ip_stack.h"
#include "thread_scheduler.h"
#include "cpu_copy_fill.h"
#include "00/Lib/CPS/stack_globals.h"
#include "00/Lib/CPS/https_session_upkeep.h"
#include "mb_data.h"
#include "00/Lib/wifi_library_globals.h"
#include "startup_entry.h"
#include "signed_int_divide.h"
#include "reset_interrupts_halt.h"
#include "00/Lib/NitroWiFi/socket_objects.h"
#include "00/Lib/CPS/socket_status_resolve.h"
#include "thread_mutex_types.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "mutex_init_decl.h"
#include "00/Lib/NitroWiFi/socket_allocation.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "00/Lib/NitroWiFi/udp_read_command.h"
#include "00/Lib/NitroWiFi/socket_listen_accept.h"
#include "00/Lib/NitroWiFi/socket_write_buffer.h"
#include "00/Lib/DWC/http_transfer.h"
#include "00/Lib/NitroWiFi/socket_read_command.h"
#include "00/Lib/NitroWiFi/socket_shutdown_all.h"
#include "00/Lib/NitroWiFi/socket_validity.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/query_reporting.h"
#include "formatted_text_to_buffer.h"
#include "string_copy_zero_fill.h"
#include "Main/Net/socl_socket_param_udp.h"

u32 SOCLiResultCodeInConnecting = 0xffffffe6;
SOCLSocketParam SOCLSocketParamTCP = {0, 1, 0, 0, 0x5ea, 0, 0, 0xbd5, 0, {0x800, 0xc, 8}, {0x800, 0xd, 8}};
SOCLSocketParam SOCLSocketParamUDPSend = {2, 0, 0, 0, 0x5ea, 0, 0, 0x6eb, 0, {0, 0, 0}, {0x800, 0xd, 8}};
SOCLSocket *SOCLiSocketListTrash;
SocketAllocFn AllocFunc_SOC;
u32 hostip;
SocketFreeFn FreeFunc_SOC;
SOCLSocket *SOCLiSocketList;
u32 *hostAddrList[2];
SOCHostEnt hostent;
char sInetNtoABuffer[16];
SOCLConfig soclConfig;
s8 entName[0x104];

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
    return SOCL_Connect(socket, port, hostAddress);
}

s32 SOC_Recv(s32 sockObj, void *buffer, s32 length, s32 flags) {
    u16 *noPort = NULL;
    u32 result = SOCL_ReadFrom(sockObj, buffer, length, noPort, 0x0u, flags);
    return result;
}

s32 SOC_RecvFrom(s32 sockObj, void *buffer, s32 length, s32 flags, void *sockFrom) {
    SOCSockAddrIn *addr;
    u16 netPort;
    u32 remoteIp;
    s32 result = SOCL_ReadFrom(sockObj, buffer, length, &netPort, &remoteIp, flags);
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
    hostent.mName = (char *) entName;
    hostent.mAliases = NULL;
    hostent.mAddrType = SOCKET_FAMILY_IPV4;
    hostent.mLength = SOCKET_ADDRESS_LENGTH_IPV4;
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
    addr->mFamily = SOCKET_FAMILY_IPV4;
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

s32 SOC_Accept(SOCLSocket *socket, SOCSockAddrIn *sockAddr, s32 unusedFlags) {
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
        case SOC_F_GETFL:
            if (socket->mFlagBlock == 1) {
                return 0;
            }
            return 4;
        case SOC_F_SETFL:
            if (mode & SOC_O_NONBLOCK) {
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

void FreeFunc_SOCL(u32 *memory) {
    if (memory != NULL) {
        FreeFunc_SOC(0, memory - 1, *(memory - 1));
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
    soclConfig.mDnsFirstIp = ((socConfig->mDns1 << 24) & 0xff000000) |
                             (((socConfig->mDns1 << 8) & 0xff0000) |
                              (((socConfig->mDns1 >> 24) & 0xff) | ((socConfig->mDns1 >> 8) & 0xff00)));
    soclConfig.mDnsSecondIp = ((socConfig->mDns2 << 24) & 0xff000000) |
                              (((socConfig->mDns2 << 8) & 0xff0000) |
                               (((socConfig->mDns2 >> 24) & 0xff) | ((socConfig->mDns2 >> 8) & 0xff00)));
    soclConfig.mAlloc = AllocFunc_SOCL;
    soclConfig.mFree = (void (*)(void *)) FreeFunc_SOCL;
    AllocFunc_SOC = socConfig->mAlloc;
    FreeFunc_SOC = socConfig->mFree;
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

BOOL SOC_InetAtoN(const char *addressString, u32 *addressOut) {
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
    OS_SNPrintf(destination, 0x10, "%d.%d.%d.%d", addressBytes[7], addressBytes[6], addressBytes[5], addressBytes[4]);
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
    u32 listAddress = (u32) socket;
    u32 socketAddress;
    u32 unusedScratch;
    socketAddress = (listAddress) + (0u);
    listAddress = (u32) &SOCLiSocketList;
    SOCLi_SocketRegisterList(listAddress, socketAddress);
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
    u32 unusedScratch;
    socketAddress = ((u32) socket) + (0u);
    listAddress = (u32) &SOCLiSocketListTrash;
    SOCLi_SocketRegisterList(listAddress, socketAddress);
}

void SOCLi_SocketUnregister(SOCLSocket *socket) {
    u32 listAddress;
    u32 socketAddress;
    u32 unusedScratch;
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
    u32 unusedScratch;
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
