#include "00/code_0218d488.h"
#include "00/code_0218aea4.h"
#include "00/code_0218b000.h"
#include "00/code_0218e2dc.h"
#include "00/unk_021b4000.h"
#include "00/code_021919ac.h"
#include "00/code_021a3a18.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "00/code_021a6d5c.h"

#pragma opt_propagation off

BOOL get_sockaddrin(const char *hostname, u32 port, SOCSockAddrIn *address) {
    SOCHostEnt *resolvedHost;
    address->mFamily = 2;
    address->mPort = (((u16) port >> 8) & 0xff) | (((u16) port << 8) & 0xff00);
    address->mAddr = inet_addr((u32) hostname);
    if (address->mAddr == -1) {
        resolvedHost = SOC_GetHostByName(hostname);
        if (resolvedHost == NULL) {
            return FALSE;
        }
        address->mAddr = **resolvedHost->mUnk_0c;
    }
    return TRUE;
}

void AvailableSendPacket(void) {
    sendto(gGsiAvailableCheck.mUnk_00, gGsiAvailableCheckPacket, gGsiAvailableCheck.mUnk_4c, 0,
           gGsiAvailableCheckAddress, 8);
    gGsiAvailableCheck.mUnk_50 = GetElapsedMilliseconds();
}

void GSIStartAvailableCheckA(const char *gamename) {
    char hostBuffer[0x40];
    s8 customHost;
    strcpy(gGsiAcGamename, gamename);
    gGsiAvailableCheck.mUnk_00 = -1;
    SocketStartUp();
    customHost = gGsiAcHostname[0];
    if (customHost == 0) {
        sprintf(hostBuffer, gAvailableHostFormat, gamename);
    }
    if (get_sockaddrin(customHost != 0 ? gGsiAcHostname : hostBuffer, 0x6cfc,
                       (SOCSockAddrIn *) gGsiAvailableCheckAddress) != FALSE) {
        gGsiAvailableCheck.mUnk_00 = OpenNetSocket(2, 2, 0);
        if (gGsiAvailableCheck.mUnk_00 != -1) {
            u32 len;
            gGsiAvailableCheck.mUnk_0c = 9;
            len = strlen(gamename);
            memcpy(gGsiAvailableCheckPacketGamename, gamename, len + 1);
            gGsiAvailableCheck.mUnk_4c = len + 6;
            AvailableSendPacket();
            gGsiAvailableCheck.mUnk_54 = 0;
        }
    }
}

BOOL HandlePacket(const s8 *packet, s32 len, u8 *address, u32 *disabledservices) {
    u32 serviceMask;
    if (len < 7) {
        return TRUE;
    }
    if (memcmp(address + 4, gGsiAvailableCheckAddressIp, 4) != 0) {
        return TRUE;
    }
    if (*OFFSET_PTR(u16, address, 2) != gGsiAvailableCheck.mUnk_06) {
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
    s8 packet[0x40];
    len = 8;
    if (gGsiAvailableCheck.mUnk_00 == -1) {
        gGsiAcResult = 1;
        return 1;
    }
    if (CanReceiveOnSocket(gGsiAvailableCheck.mUnk_00) != 0 &&
        HandlePacket(packet, recvfrom(gGsiAvailableCheck.mUnk_00, packet, 0x40, 0, (u8 *) &address, &len),
                     (u8 *) &address, &disabledMask) == FALSE) {
        closesocket(gGsiAvailableCheck.mUnk_00);
        if ((disabledMask & 1) != 0) {
            gGsiAcResult = 2;
        } else if ((disabledMask & 2) != 0) {
            gGsiAcResult = 3;
        } else {
            gGsiAcResult = 1;
        }
        return gGsiAcResult;
    }
    if (GetElapsedMilliseconds() > gGsiAvailableCheck.mUnk_50 + 0x7d0) {
        if (gGsiAvailableCheck.mUnk_54 == 1) {
            closesocket(gGsiAvailableCheck.mUnk_00);
            gGsiAcResult = 1;
            return 1;
        }
        AvailableSendPacket();
        gGsiAvailableCheck.mUnk_54 = gGsiAvailableCheck.mUnk_54 + 1;
    }
    return 0;
}

s32 IntKeyCompare(u32 *entry1, u32 *entry2) {
    u32 firstServer;
    u32 server2;
    s32 firstValue;
    s32 diff;
    firstServer = *entry1;
    server2 = *entry2;
    firstValue = SbServerGetInt((SbServer *) firstServer, gSortServerList->mSortKey, 0);
    diff = firstValue - SbServerGetInt((SbServer *) server2, gSortServerList->mSortKey, 0);
    if (gSortServerList->mSortAscending == 0) {
        diff = -diff;
    }
    return diff;
}

s32 FloatKeyCompare(u32 *entry1, u32 *entry2) {
    u32 firstServer;
    u32 server2;
    double firstValue;
    double secondValue;
    double difference;
    firstServer = *entry1;
    server2 = *entry2;
    firstValue = SbServerGetDouble((SbServer *) firstServer, gSortServerList->mSortKey, 0);
    secondValue = SbServerGetDouble((SbServer *) server2, gSortServerList->mSortKey, 0);
    difference = firstValue - secondValue;
    if (gSortServerList->mSortAscending == 0) {
        difference = 0 - difference;
    }
    if ((float) difference > 0) {
        return 1;
    }
    return -((float) difference < 0);
}
