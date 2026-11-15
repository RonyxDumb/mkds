#include "00/Lib/GameSpy/code_0219a654.h"
#include "00/Lib/DWC/dwc_result.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/code_0219b1d4.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/Lib/CPS/code_021a88a8.h"
#include "00/Lib/NitroWiFi/code_021a8aa8.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/Lib/NitroWiFi/socl_startup.h"
#include "00/Lib/GameSpy/code_0218d488.h"

u8 NNMagicData[6] = {0xfd, 0xfc, 0x1e, 0x66, 0x6a, 0xb2};
void *negotiateList = NULL;
char *Matchup1Hostname;
char *Matchup2Hostname;
u32 matchup1ip = 0;
u32 matchup2ip = 0;

NatTraversalEntry *AddNegotiator(void) {
    NatTraversalEntry negotiator = {0};

    if (negotiateList == NULL) {
        negotiateList = DarrayCreate(0x40, 4, (void (*)(void *)) NegotiatorFree);
    }
    DarrayAppend(negotiateList, &negotiator);
    return DarrayGetElement(negotiateList, DarrayGetCount(negotiateList) - 1);
}

void RemoveNegotiator(NatTraversalEntry *negotiator) {
    s32 index;

    for (index = 0; index < DarrayGetCount(negotiateList); index++) {
        if (negotiator == DarrayGetElement(negotiateList, index)) {
            DarrayRemoveWithoutCallback(negotiateList, index);
            return;
        }
    }
}

void NNFreeNegotiateList(void) {
    if (negotiateList != NULL) {
        DarrayDelete(negotiateList);
        negotiateList = NULL;
    }
}

BOOL CheckMagic(const u8 *data) {
    if (memcmp(data, NNMagicData, 6) == 0) {
        return TRUE;
    }
    return FALSE;
}

void SendNegotiatorPacket(u32 sock, u32 toaddr, u16 toport, void *data, s32 length) {
    SOCSockAddrIn sockaddr;

    sockaddr.mFamily = SOCKET_FAMILY_IPV4;
    sockaddr.mPort = toport >> 8 & 0xff | toport << 8 & 0xff00;
    sockaddr.mAddr = toaddr;
    sendto(sock, data, length, 0, &sockaddr, 8);
}

u32 GetLocalIP(void) {
    s32 ownAddr;
    u32 *addressPointer;
    SOCHostEnt *host;
    s32 index;

    ownAddr = 0;
    host = getlocalhost();
    if (host == NULL) {
        return ownAddr;
    }
    index = 0;
    while (1) {
        addressPointer = host->mAddrList[index];
        if (addressPointer == NULL) {
            break;
        }
        if (*addressPointer != 0x0100007f) {
            ownAddr = *addressPointer;
            if (IsPrivateIP(addressPointer) != FALSE) {
                return ownAddr;
            }
        }
        index++;
    }
    return ownAddr;
}

static inline void CopyNNMagic(void *destination, const void *source) {
    u8 *destinationBytes = destination;
    const u8 *sourceBytes = source;
    destinationBytes[0] = sourceBytes[0];
    destinationBytes[1] = sourceBytes[1];
    destinationBytes[2] = sourceBytes[2];
    destinationBytes[3] = sourceBytes[3];
    destinationBytes[4] = sourceBytes[4];
    destinationBytes[5] = sourceBytes[5];
}

u16 GetLocalPort(u32 sock) {
    SOCSockAddrIn sockaddr;
    u32 sockaddrLength;
    s32 result;
    u16 port;

    sockaddrLength = 8;
    result = getsockname(sock, &sockaddr, &sockaddrLength);
    port = 0;
    if (result != -1) {
        port = sockaddr.mPort;
    }
    return port;
}

void SendInitPackets(NatTraversalEntry *negotiator) {
    InitPacketWithGamename packet;
    u32 value;
    u32 packetLength;
    u32 portSocket;
    u16 ownPort;
    InitPacketWithGamename *packetView;

    packetView = (InitPacketWithGamename *) &packet;
    packetView->mMagic = *(NNMagic *) NNMagicData;
    packetView->mVersion = NAT_PACKET_VERSION;
    packetView->mPacketType = NAT_PACKET_INIT;
    packetView->mClientIndex = negotiator->mClientIndex;
    value = negotiator->mCookie;
    *(u32 *) packetView->mCookie =
        (value << 24 & 0xff000000) | ((value << 8 & 0xff0000) | ((value >> 24 & 0xff) | (value >> 8 & 0xff00)));
    value = 0;
    if (negotiator->mGameSock != -1) {
        value = 1;
    }
    packetView->mUseGamePort = value;
    value = (GetLocalIP() << 24 & 0xff000000) |
            ((GetLocalIP() << 8 & 0xff0000) | ((GetLocalIP() >> 24 & 0xff) | (GetLocalIP() >> 8 & 0xff00)));
    packet.mLocalIpFirstByte = value >> 24;
    packet.mLocalIpSecondByte = value >> 16;
    packet.mLocalIpThirdByte = value >> 8;
    packet.mLocalIpFourthByte = value;
    packet.mLocalPortHighByte = 0;
    packet.mLocalPortLowByte = 0;
    strcpy(packet.mGameName, gGsiAcGamename);
    packetLength = strlen(gGsiAcGamename) + 0x16;
    if (packetView->mUseGamePort != 0 && negotiator->mInitAckRecv[NN_PT_GP] == 0) {
        packetView->mPortType = NN_PT_GP;
        SendNegotiatorPacket(negotiator->mGameSock, matchup1ip, MATCHUP_PORT, packetView, packetLength);
    }
    if (negotiator->mInitAckRecv[NN_PT_NN1] == 0) {
        packetView->mPortType = NN_PT_NN1;
        SendNegotiatorPacket(negotiator->mDescriptor, matchup1ip, MATCHUP_PORT, packetView, packetLength);
    }
    if (packetView->mUseGamePort != 0) {
        portSocket = negotiator->mGameSock;
    } else {
        portSocket = negotiator->mDescriptor;
    }
    ownPort =
        (GetLocalPort(packetView->mUseGamePort != 0 ? negotiator->mGameSock : negotiator->mDescriptor) >> 8 & 0xff) |
        (GetLocalPort(portSocket) << 8 & 0xff00);
    packet.mLocalPortHighByte = ownPort >> 8;
    packet.mLocalPortLowByte = ownPort;
    if (negotiator->mInitAckRecv[NN_PT_NN2] == 0) {
        packetView->mPortType = NN_PT_NN2;
        SendNegotiatorPacket(negotiator->mDescriptor, matchup2ip, MATCHUP_PORT, packetView, packetLength);
    }
    negotiator->mRetryTime = GetElapsedMilliseconds() + INIT_RETRY_TIME;
    negotiator->mMaxRetryCount = INIT_RETRY_COUNT;
}

void SendPingPacket(NatTraversalEntry *negotiator) {
    ConnectPacket packet;
    u32 cookie;
    s32 sock;

    CopyNNMagic(&packet.mMagic, NNMagicData);
    packet.mVersion = NAT_PACKET_VERSION;
    packet.mPacketType = NAT_PACKET_PING;
    cookie = negotiator->mCookie;
    *(u32 *) packet.mCookie =
        (cookie << 24 & 0xff000000) | ((cookie << 8 & 0xff0000) | ((cookie >> 24 & 0xff) | (cookie >> 8 & 0xff00)));
    *(u32 *) packet.mRemoteIp = negotiator->mGuessedIP;
    *(u16 *) packet.mRemotePort = negotiator->mGuessedPort >> 8 & 0xff | negotiator->mGuessedPort << 8 & 0xff00;
    packet.mGotYourData = negotiator->mGotRemoteData;
    packet.mFinished = negotiator->mState != NAT_NEGOTIATION_PING;
    sock = negotiator->mGameSock;
    if (sock == -1) {
        sock = negotiator->mDescriptor;
    }
    SendNegotiatorPacket(sock, negotiator->mGuessedIP, negotiator->mGuessedPort, &packet, 0x14);
    negotiator->mRetryTime = GetElapsedMilliseconds() + PING_RETRY_TIME;
    negotiator->mMaxRetryCount = PING_RETRY_COUNT;
    if (negotiator->mGotRemoteData != 0) {
        negotiator->mSendGotRemoteData = 1;
    }
}

u32 NameToIp(const char *name) {
    u32 address;
    SOCHostEnt *host;

    address = inet_addr(name);
    if (address == -1) {
        host = SOC_GetHostByName(name);
        if (host == NULL) {
            return 0;
        }
        address = **host->mAddrList;
    }
    return address;
}

u32 ResolveServer(char *overrideHostname, const char *defaultHostname) {
    char fullHostname[0x80];

    if (overrideHostname == NULL) {
        snprintf(fullHostname, 0x80, "%s.%s", gGsiAcGamename, defaultHostname);
        overrideHostname = fullHostname;
    }
    return NameToIp(overrideHostname);
}

BOOL ResolveServers(void) {
    if (matchup1ip == 0) {
        matchup1ip = ResolveServer(Matchup1Hostname, "natneg1.gs.nintendowifi.net");
    }
    if (matchup2ip == 0) {
        matchup2ip = ResolveServer(Matchup2Hostname, "natneg2.gs.nintendowifi.net");
    }
    if (matchup1ip == 0 || matchup2ip == 0) {
        return FALSE;
    }
    return TRUE;
}

s32 NNBeginNegotiationWithSocket(
    u32 gamesocket, u32 cookie, u32 clientNumber, void (*progressCallback)(s32 gamesocket, void *cookie),
    void (*completedCallback)(s32 gamesocket, s32 cookie, void *clientNumber, void *progressCallback), void *userdata) {
    NatTraversalEntry *negotiator;

    if (gGsiAcResult != 1) {
        return 2;
    }
    if (ResolveServers() == FALSE) {
        return 3;
    }
    negotiator = AddNegotiator();
    if (negotiator == NULL) {
        return 1;
    }
    negotiator->mGameSock = gamesocket;
    negotiator->mClientIndex = clientNumber;
    negotiator->mCookie = cookie;
    negotiator->mProgressCallback = progressCallback;
    negotiator->mCompletedCallback = completedCallback;
    negotiator->mUserdata = userdata;
    negotiator->mDescriptor = OpenNetSocket(2, 2, 0);
    negotiator->mRetryCount = 0;
    negotiator->mGotRemoteData = 0;
    negotiator->mSendGotRemoteData = 0;
    negotiator->mGuessedIP = 0;
    negotiator->mGuessedPort = 0;
    negotiator->mMaxRetryCount = 0;
    if (negotiator->mDescriptor == -1) {
        RemoveNegotiator(negotiator);
        return 2;
    }
    SendInitPackets(negotiator);
    return 0;
}

void NNCancel(u32 cookie) {
    NatTraversalEntry *negotiator;

    negotiator = FindNegotiatorForCookie(cookie);
    if (negotiator != NULL) {
        if (negotiator->mDescriptor != -1) {
            closesocket(negotiator->mDescriptor);
        }
        negotiator->mDescriptor = -1;
        negotiator->mState = NAT_NEGOTIATION_CANCELED;
    }
}

void NegotiateThink(NatTraversalEntry *negotiator) {
    SOCSockAddrIn senderAddress;
    s32 senderAddressLength;
    s32 receivedLength;
    SOCSockAddrIn resultAddress;
    static u8 receiveBuffer[512];

    senderAddressLength = 8;
    if (negotiator->mState == NAT_NEGOTIATION_CANCELED) {
        RemoveNegotiator(negotiator);
        return;
    }
    if (negotiator->mDescriptor != -1) {
        do {
            if (CanReceiveOnSocket(negotiator->mDescriptor) == 0) {
                break;
            }
            receivedLength =
                recvfrom(negotiator->mDescriptor, receiveBuffer, 0x200, 0, &senderAddress, &senderAddressLength);
            if (receivedLength == -1) {
                break;
            }
            NNProcessData(receiveBuffer, receivedLength, &senderAddress);
            if (negotiator->mState == NAT_NEGOTIATION_CANCELED) {
                break;
            }
        } while (negotiator->mDescriptor != -1);
    }
    if (negotiator->mState == NAT_NEGOTIATION_SEND_INIT || negotiator->mState == NAT_NEGOTIATION_PING) {
        if (GetElapsedMilliseconds() > negotiator->mRetryTime) {
            if (negotiator->mRetryCount > negotiator->mMaxRetryCount) {
                negotiator->mCompletedCallback(2, -1, NULL, negotiator->mUserdata);
                NNCancel(negotiator->mCookie);
            } else {
                negotiator->mRetryCount = negotiator->mRetryCount + 1;
                if (negotiator->mState == NAT_NEGOTIATION_SEND_INIT) {
                    SendInitPackets(negotiator);
                } else {
                    SendPingPacket(negotiator);
                }
            }
        }
    }
    if (negotiator->mState == NAT_NEGOTIATION_PINGED) {
        if (GetElapsedMilliseconds() > negotiator->mRetryTime) {
            if (negotiator->mGameSock == -1) {
                resultAddress.mFamily = SOCKET_FAMILY_IPV4;
                resultAddress.mPort = negotiator->mGuessedPort >> 8 & 0xff | negotiator->mGuessedPort << 8 & 0xff00;
                resultAddress.mAddr = negotiator->mGuessedIP;
                negotiator->mCompletedCallback(0, negotiator->mDescriptor, &resultAddress, negotiator->mUserdata);
                negotiator->mDescriptor = -1;
            }
            NNCancel(negotiator->mCookie);
        }
    }
    if (negotiator->mState == NAT_NEGOTIATION_WAIT_CONNECT) {
        if (GetElapsedMilliseconds() > negotiator->mRetryTime) {
            negotiator->mCompletedCallback(1, -1, NULL, negotiator->mUserdata);
            NNCancel(negotiator->mCookie);
        }
    }
}

void NNThink(void) {
    s32 index;

    if (negotiateList != NULL) {
        for (index = DarrayGetCount(negotiateList) - 1; index >= 0; index--) {
            NegotiateThink(DarrayGetElement(negotiateList, index));
        }
    }
}

void SendConnectAck(NatTraversalEntry *negotiator, SOCSockAddrIn *toaddr) {
    InitPacket packet;
    u32 cookie;

    CopyNNMagic(&packet.mMagic, NNMagicData);
    packet.mVersion = NAT_PACKET_VERSION;
    packet.mPacketType = NAT_PACKET_CONNECT_ACK;
    packet.mClientIndex = negotiator->mClientIndex;
    cookie = negotiator->mCookie;
    *(u32 *) packet.mCookie =
        (cookie << 24 & 0xff000000) | ((cookie << 8 & 0xff0000) | ((cookie >> 24 & 0xff) | (cookie >> 8 & 0xff00)));
    SendNegotiatorPacket(negotiator->mDescriptor, toaddr->mAddr,
                         toaddr->mPort >> 8 & 0xff | toaddr->mPort << 8 & 0xff00, &packet, 0x15);
}

void ProcessConnectPacket(NatTraversalEntry *negotiator, ConnectPacket *packet, SOCSockAddrIn *fromAddress) {
    s32 result;

    if (packet->mFinished == FINISHED_NOERROR) {
        SendConnectAck(negotiator, fromAddress);
    }
    if (negotiator->mState < NAT_NEGOTIATION_PING) {
        if (packet->mFinished != FINISHED_NOERROR) {
            result = nr_unknownerror;
            if (packet->mFinished == FINISHED_ERROR_DEADBEAT_PARTNER) {
                result = nr_deadbeatpartner;
            } else if (packet->mFinished == FINISHED_ERROR_INIT_PACKETS_TIMEDOUT) {
                result = nr_inittimeout;
            }
            negotiator->mCompletedCallback(result, -1, NULL, negotiator->mUserdata);
            NNCancel(negotiator->mCookie);
        } else {
            negotiator->mGuessedIP = *(u32 *) packet->mRemoteIp;
            negotiator->mGuessedPort =
                *(u16 *) packet->mRemotePort >> 8 & 0xff | *(u16 *) packet->mRemotePort << 8 & 0xff00;
            negotiator->mRetryCount = 0;
            negotiator->mState = NAT_NEGOTIATION_PING;
            negotiator->mProgressCallback(negotiator->mState, negotiator->mUserdata);
            SendPingPacket(negotiator);
        }
    }
}

void ProcessPingPacket(NatTraversalEntry *negotiator, ConnectPacket *packet, SOCSockAddrIn *fromAddress) {
    if (negotiator->mState >= NAT_NEGOTIATION_PING) {
        negotiator->mGuessedIP = fromAddress->mAddr;
        negotiator->mGuessedPort = fromAddress->mPort >> 8 & 0xff | fromAddress->mPort << 8 & 0xff00;
        negotiator->mGotRemoteData = 1;
        if (packet->mGotYourData == 0) {
            SendPingPacket(negotiator);
            return;
        }
        if (negotiator->mState == NAT_NEGOTIATION_PING) {
            if (negotiator->mSendGotRemoteData == 0) {
                SendPingPacket(negotiator);
            }
            negotiator->mState = NAT_NEGOTIATION_PINGED;
            negotiator->mRetryTime = GetElapsedMilliseconds() + FINISHED_IDLE_TIME;
            if (negotiator->mGameSock != -1) {
                negotiator->mCompletedCallback(0, negotiator->mGameSock, fromAddress, negotiator->mUserdata);
            }
        } else if (packet->mFinished == FINISHED_NOERROR) {
            SendPingPacket(negotiator);
        }
    }
}

void ProcessInitPacket(NatTraversalEntry *negotiator, InitPacket *packet, SOCSockAddrIn *fromAddress) {
    u32 portKind;

    switch (packet->mPacketType) {
        case NAT_PACKET_INIT_ACK:
            portKind = packet->mPortType;
            if (portKind <= 2) {
                negotiator->mInitAckRecv[portKind] = 1;
                if (negotiator->mState == NAT_NEGOTIATION_SEND_INIT && negotiator->mInitAckRecv[NN_PT_NN1] != 0 &&
                    negotiator->mInitAckRecv[NN_PT_NN2] != 0 &&
                    (negotiator->mGameSock == -1 || negotiator->mInitAckRecv[NN_PT_GP] != 0)) {
                    negotiator->mState = NAT_NEGOTIATION_WAIT_CONNECT;
                    negotiator->mRetryTime = GetElapsedMilliseconds() + 10000;
                    negotiator->mProgressCallback(negotiator->mState, negotiator->mUserdata);
                }
            }
            break;
        case NAT_PACKET_ECHO_REQUEST:
            packet->mPacketType = NAT_PACKET_ECHO_REPLY;
            SendNegotiatorPacket(negotiator->mDescriptor, fromAddress->mAddr,
                             fromAddress->mPort >> 8 & 0xff | fromAddress->mPort << 8 & 0xff00, packet, 0x15);
            break;
    }
}

void NNProcessData(u8 *data, s32 length, void *fromAddress) {
    ConnectPacket connectPacket;
    InitPacket initPacket;
    u32 typeCode;
    u32 cookie;
    NatTraversalEntry *negotiator;

    if (CheckMagic(data) != FALSE) {
        typeCode = data[7];
        if (typeCode == NAT_PACKET_CONNECT || typeCode == NAT_PACKET_PING) {
            if (length >= 0x14) {
                connectPacket = *(ConnectPacket *) data;
                cookie = *(u32 *) connectPacket.mCookie;
                negotiator = FindNegotiatorForCookie(
                    (cookie << 24 & 0xff000000) |
                    ((cookie << 8 & 0xff0000) | ((cookie >> 24 & 0xff) | (cookie >> 8 & 0xff00))));
                if (negotiator != NULL) {
                    if (typeCode == NAT_PACKET_CONNECT) {
                        ProcessConnectPacket(negotiator, &connectPacket, fromAddress);
                    } else {
                        ProcessPingPacket(negotiator, &connectPacket, fromAddress);
                    }
                }
            }
        } else if (length >= 0x15) {
            initPacket = *(InitPacket *) data;
            cookie = *(u32 *) initPacket.mCookie;
            negotiator =
                FindNegotiatorForCookie((cookie << 24 & 0xff000000) |
                                        ((cookie << 8 & 0xff0000) | ((cookie >> 24 & 0xff) | (cookie >> 8 & 0xff00))));
            if (negotiator != NULL) {
                ProcessInitPacket(negotiator, &initPacket, fromAddress);
            }
        }
    }
}
