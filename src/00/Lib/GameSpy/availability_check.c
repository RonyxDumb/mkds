#include "00/Lib/GameSpy/availability_check.h"
#include "00/Lib/GameSpy/server_list.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/login_connect.h"
#include "00/Lib/GameSpy/query_reporting.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "narrow_string_functions.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"

#pragma opt_propagation off

u8 gAvailablePacketHeader[4] = {0xfe, 0xfd, AVAILABILITY_PACKET_TYPE, 0};
SBServerList *gSortServerList;
s32 gGsiAcResult;
char gGsiAcHostname[0x40];
GsiAvailableCheck gGsiAvailableCheck;
char gGsiAcGamename[0x40];

BOOL get_sockaddrin(const char *hostname, u32 port, SOCSockAddrIn *address) {
    SOCHostEnt *resolvedHost;
    address->mFamily = SOCKET_FAMILY_IPV4;
    address->mPort = (((u16) port >> 8) & 0xff) | (((u16) port << 8) & 0xff00);
    address->mAddr = inet_addr(hostname);
    if (address->mAddr == -1) {
        resolvedHost = SOC_GetHostByName(hostname);
        if (resolvedHost == NULL) {
            return FALSE;
        }
        address->mAddr = **resolvedHost->mAddrList;
    }
    return TRUE;
}

void AvailableSendPacket(void) {
    sendto(gGsiAvailableCheck.mSocket, &gGsiAvailableCheck.mPacketType, gGsiAvailableCheck.mPacketLength, 0,
           &gGsiAvailableCheck.mAddress, 8);
    gGsiAvailableCheck.mSendTime = current_time();
}

void GSIStartAvailableCheckA(const char *gamename) {
    char hostBuffer[0x40];
    s8 customHostFirstChar;
    strcpy(gGsiAcGamename, gamename);
    gGsiAvailableCheck.mSocket = -1;
    SocketStartUp();
    customHostFirstChar = gGsiAcHostname[0];
    if (customHostFirstChar == 0) {
        sprintf(hostBuffer, "%s.available.gs.nintendowifi.net", gamename);
    }
    if (get_sockaddrin(customHostFirstChar != 0 ? gGsiAcHostname : hostBuffer, REPORTING_AND_AVAILABILITY_PORT,
                       &gGsiAvailableCheck.mAddress) != FALSE) {
        gGsiAvailableCheck.mSocket = OpenNetSocket(2, 2, 0);
        if (gGsiAvailableCheck.mSocket != -1) {
            u32 len;
            gGsiAvailableCheck.mPacketType = AVAILABILITY_PACKET_TYPE;
            len = strlen(gamename);
            memcpy(gGsiAvailableCheck.mPacketGamename, gamename, len + 1);
            gGsiAvailableCheck.mPacketLength = len + 6;
            AvailableSendPacket();
            gGsiAvailableCheck.mRetryCount = 0;
        }
    }
}

BOOL HandlePacket(const s8 *packet, s32 len, SOCSockAddrIn *address, u32 *disabledservices) {
    u32 serviceMask;
    if (len < 7) {
        return TRUE;
    }
    if (memcmp(&address->mAddr, &gGsiAvailableCheck.mAddress.mAddr, 4) != 0) {
        return TRUE;
    }
    if (address->mPort != gGsiAvailableCheck.mAddress.mPort) {
        return TRUE;
    }
    if (memcmp((const u8 *) packet, gAvailablePacketHeader, 3) != 0) {
        return TRUE;
    }
    serviceMask = (packet[3] << 24) & 0xff000000;
    serviceMask |= (packet[4] << 16) & 0xff0000;
    serviceMask |= (packet[5] << 8) & 0xff00;
    serviceMask |= packet[6] & 0xff;
    *disabledservices = serviceMask;
    return FALSE;
}

s32 GSIAvailableCheckThink(void) {
    SOCSockAddrIn address;
    s32 len;
    u32 disabledMask;
    s8 replyBuffer[0x40];
    len = 8;
    if (gGsiAvailableCheck.mSocket == -1) {
        gGsiAcResult = 1;
        return 1;
    }
    if (CanReceiveOnSocket(gGsiAvailableCheck.mSocket) != 0 &&
        HandlePacket(replyBuffer, recvfrom(gGsiAvailableCheck.mSocket, replyBuffer, 0x40, 0, &address, &len),
                     &address, &disabledMask) == FALSE) {
        closesocket(gGsiAvailableCheck.mSocket);
        if ((disabledMask & 1) != 0) {
            gGsiAcResult = 2;
        } else if ((disabledMask & 2) != 0) {
            gGsiAcResult = 3;
        } else {
            gGsiAcResult = 1;
        }
        return gGsiAcResult;
    }
    if (current_time() > gGsiAvailableCheck.mSendTime + 0x7d0) {
        if (gGsiAvailableCheck.mRetryCount == 1) {
            closesocket(gGsiAvailableCheck.mSocket);
            gGsiAcResult = 1;
            return 1;
        }
        AvailableSendPacket();
        gGsiAvailableCheck.mRetryCount = gGsiAvailableCheck.mRetryCount + 1;
    }
    return 0;
}

s32 IntKeyCompare(SBServer **entry1, SBServer **entry2) {
    SBServer *firstServer;
    SBServer *secondServer;
    s32 firstValue;
    s32 diff;
    firstServer = *entry1;
    secondServer = *entry2;
    firstValue = SBServerGetIntValueA(firstServer, gSortServerList->mSortKey, 0);
    diff = firstValue - SBServerGetIntValueA(secondServer, gSortServerList->mSortKey, 0);
    if (gSortServerList->mSortAscending == 0) {
        diff = -diff;
    }
    return diff;
}

s32 FloatKeyCompare(SBServer **entry1, SBServer **entry2) {
    SBServer *firstServer;
    SBServer *secondServer;
    double firstValue;
    double secondValue;
    double difference;
    firstServer = *entry1;
    secondServer = *entry2;
    firstValue = SBServerGetFloatValueA(firstServer, gSortServerList->mSortKey, 0);
    secondValue = SBServerGetFloatValueA(secondServer, gSortServerList->mSortKey, 0);
    difference = firstValue - secondValue;
    if (gSortServerList->mSortAscending == 0) {
        difference = 0 - difference;
    }
    if ((float) difference > 0) {
        return 1;
    }
    return -((float) difference < 0);
}
