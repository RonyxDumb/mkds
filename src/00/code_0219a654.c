#include "00/code_0219a654.h"
#include "00/code_0218d818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218e2dc.h"
#include "00/unk_021b4000.h"
#include "00/code_0219b1d4.h"
#include "00/code_0219b1f8.h"
#include "00/code_021a3a18.h"
#include "00/code_021a88a8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b5000.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021a6d5c.h"

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

    sockaddr.mFamily = 2;
    sockaddr.mPort = toport >> 8 & 0xff | toport << 8 & 0xff00;
    sockaddr.mAddr = toaddr;
    sendto(sock, data, length, 0, &sockaddr, 8);
}

u32 GetLocalIP(void) {
    s32 ownAddr;
    u32 *addressPointer;
    SOCHostEnt *host;
    s32 offset;

    ownAddr = 0;
    host = getlocalhost();
    if (host == NULL) {
        return ownAddr;
    }
    offset = 0;
    while (1) {
        addressPointer = *OFFSET_PTR(u32 *, host->mAddrList, offset);
        if (addressPointer == NULL) {
            break;
        }
        if (*addressPointer != 0x0100007f) {
            ownAddr = *addressPointer;
            if (IsPrivateIP(addressPointer) != FALSE) {
                return ownAddr;
            }
        }
        offset += 4;
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
    u32 c;
    u32 packetLength;
    u32 portSocket;
    u16 ownPort;
    InitPacketWithGamename *packetView;

    packetView = (InitPacketWithGamename *) &packet;
    packetView->mMagic = *(NNMagic *) NNMagicData;
    packetView->mVersion = 2;
    packetView->mPacketType = 0;
    packetView->mClientIndex = negotiator->mClientIndex;
    c = negotiator->mCookie;
    *(u32 *) packetView->mCookie =
        (c << 24 & 0xff000000) | ((c << 8 & 0xff0000) | ((c >> 24 & 0xff) | (c >> 8 & 0xff00)));
    c = 0;
    if (negotiator->mGameSock != -1) {
        c = 1;
    }
    packetView->mUseGamePort = c;
    c = (GetLocalIP() << 24 & 0xff000000) |
        ((GetLocalIP() << 8 & 0xff0000) | ((GetLocalIP() >> 24 & 0xff) | (GetLocalIP() >> 8 & 0xff00)));
    packet.mLocalIpFirstByte = c >> 24;
    packet.mLocalIpSecondByte = c >> 16;
    packet.mLocalIpThirdByte = c >> 8;
    packet.mLocalIpFourthByte = c;
    packet.mLocalPortHighByte = 0;
    packet.mLocalPortLowByte = 0;
    strcpy(packet.mGameName, gGsiAcGamename);
    packetLength = strlen(gGsiAcGamename) + 0x16;
    if (packetView->mUseGamePort != 0 && negotiator->mInitAckRecv[0] == 0) {
        packetView->mPortType = 0;
        SendNegotiatorPacket(negotiator->mGameSock, matchup1ip, 0x6cfd, packetView, packetLength);
    }
    if (negotiator->mInitAckRecv[1] == 0) {
        packetView->mPortType = 1;
        SendNegotiatorPacket(negotiator->mDescriptor, matchup1ip, 0x6cfd, packetView, packetLength);
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
    if (negotiator->mInitAckRecv[2] == 0) {
        packetView->mPortType = 2;
        SendNegotiatorPacket(negotiator->mDescriptor, matchup2ip, 0x6cfd, packetView, packetLength);
    }
    negotiator->mRetryTime = GetElapsedMilliseconds() + 500;
    negotiator->mMaxRetryCount = 30;
}

void SendPingPacket(NatTraversalEntry *negotiator) {
    ConnectPacket packet;
    u32 cookie;
    s32 sock;

    CopyNNMagic(&packet.mMagic, NNMagicData);
    packet.mVersion = 2;
    packet.mPacketType = 7;
    cookie = negotiator->mCookie;
    *(u32 *) packet.mCookie =
        (cookie << 24 & 0xff000000) | ((cookie << 8 & 0xff0000) | ((cookie >> 24 & 0xff) | (cookie >> 8 & 0xff00)));
    *(u32 *) packet.mRemoteIp = negotiator->mGuessedIP;
    *(u16 *) packet.mRemotePort = negotiator->mGuessedPort >> 8 & 0xff | negotiator->mGuessedPort << 8 & 0xff00;
    packet.mGotYourData = negotiator->mGotRemoteData;
    packet.mFinished = negotiator->mState != 2;
    sock = negotiator->mGameSock;
    if (sock == -1) {
        sock = negotiator->mDescriptor;
    }
    SendNegotiatorPacket(sock, negotiator->mGuessedIP, negotiator->mGuessedPort, &packet, 0x14);
    negotiator->mRetryTime = GetElapsedMilliseconds() + 700;
    negotiator->mMaxRetryCount = 12;
    if (negotiator->mGotRemoteData != 0) {
        negotiator->mSendGotRemoteData = 1;
    }
}

u32 NameToIp(const char *name) {
    u32 address;
    SOCHostEnt *host;

    address = inet_addr((u32) name);
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
        snprintf(fullHostname, 0x80, gGamenameHostnameFormat, gGsiAcGamename, defaultHostname);
        overrideHostname = fullHostname;
    }
    return NameToIp(overrideHostname);
}

BOOL ResolveServers(void) {
    if (matchup1ip == 0) {
        matchup1ip = ResolveServer(Matchup1Hostname, gMatchup1HostnameDefault);
    }
    if (matchup2ip == 0) {
        matchup2ip = ResolveServer(Matchup2Hostname, gMatchup2HostnameDefault);
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
        negotiator->mState = 4;
    }
}

void NegotiateThink(NatTraversalEntry *negotiator) {
    SOCSockAddrIn senderAddress;
    s32 senderAddressLength;
    s32 receivedLength;
    SOCSockAddrIn resultAddress;

    senderAddressLength = 8;
    if (negotiator->mState == 4) {
        RemoveNegotiator(negotiator);
        return;
    }
    if (negotiator->mDescriptor != -1) {
        do {
            if (CanReceiveOnSocket(negotiator->mDescriptor) == 0) {
                break;
            }
            receivedLength = recvfrom(negotiator->mDescriptor, gNatNegReceiveBuffer, 0x200, 0, (u8 *) &senderAddress,
                                      &senderAddressLength);
            if (receivedLength == -1) {
                break;
            }
            NNProcessData(gNatNegReceiveBuffer, receivedLength, &senderAddress);
            if (negotiator->mState == 4) {
                break;
            }
        } while (negotiator->mDescriptor != -1);
    }
    if (negotiator->mState == 0 || negotiator->mState == 2) {
        if (GetElapsedMilliseconds() > negotiator->mRetryTime) {
            if (negotiator->mRetryCount > negotiator->mMaxRetryCount) {
                negotiator->mCompletedCallback(2, -1, NULL, negotiator->mUserdata);
                NNCancel(negotiator->mCookie);
            } else {
                negotiator->mRetryCount = negotiator->mRetryCount + 1;
                if (negotiator->mState == 0) {
                    SendInitPackets(negotiator);
                } else {
                    SendPingPacket(negotiator);
                }
            }
        }
    }
    if (negotiator->mState == 3) {
        if (GetElapsedMilliseconds() > negotiator->mRetryTime) {
            if (negotiator->mGameSock == -1) {
                resultAddress.mFamily = 2;
                resultAddress.mPort = negotiator->mGuessedPort >> 8 & 0xff | negotiator->mGuessedPort << 8 & 0xff00;
                resultAddress.mAddr = negotiator->mGuessedIP;
                negotiator->mCompletedCallback(0, negotiator->mDescriptor, &resultAddress, negotiator->mUserdata);
                negotiator->mDescriptor = -1;
            }
            NNCancel(negotiator->mCookie);
        }
    }
    if (negotiator->mState == 1) {
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
    packet.mVersion = 2;
    packet.mPacketType = 6;
    packet.mClientIndex = negotiator->mClientIndex;
    cookie = negotiator->mCookie;
    *(u32 *) packet.mCookie =
        (cookie << 24 & 0xff000000) | ((cookie << 8 & 0xff0000) | ((cookie >> 24 & 0xff) | (cookie >> 8 & 0xff00)));
    SendNegotiatorPacket(negotiator->mDescriptor, toaddr->mAddr, toaddr->mPort >> 8 & 0xff | toaddr->mPort << 8 & 0xff00,
                     &packet, 0x15);
}

void ProcessConnectPacket(NatTraversalEntry *negotiator, ConnectPacket *packet, SOCSockAddrIn *fromAddress) {
    s32 result;

    if (packet->mFinished == 0) {
        SendConnectAck(negotiator, fromAddress);
    }
    if (negotiator->mState < 2) {
        if (packet->mFinished != 0) {
            result = 3;
            if (packet->mFinished == 1) {
                result = 1;
            } else if (packet->mFinished == 2) {
                result = 2;
            }
            negotiator->mCompletedCallback(result, -1, NULL, negotiator->mUserdata);
            NNCancel(negotiator->mCookie);
        } else {
            negotiator->mGuessedIP = *(u32 *) packet->mRemoteIp;
            negotiator->mGuessedPort =
                *(u16 *) packet->mRemotePort >> 8 & 0xff | *(u16 *) packet->mRemotePort << 8 & 0xff00;
            negotiator->mRetryCount = 0;
            negotiator->mState = 2;
            negotiator->mProgressCallback(negotiator->mState, negotiator->mUserdata);
            SendPingPacket(negotiator);
        }
    }
}

void ProcessPingPacket(NatTraversalEntry *negotiator, ConnectPacket *packet, SOCSockAddrIn *fromAddress) {
    if (negotiator->mState >= 2) {
        negotiator->mGuessedIP = fromAddress->mAddr;
        negotiator->mGuessedPort = fromAddress->mPort >> 8 & 0xff | fromAddress->mPort << 8 & 0xff00;
        negotiator->mGotRemoteData = 1;
        if (packet->mGotYourData == 0) {
            SendPingPacket(negotiator);
            return;
        }
        if (negotiator->mState == 2) {
            if (negotiator->mSendGotRemoteData == 0) {
                SendPingPacket(negotiator);
            }
            negotiator->mState = 3;
            negotiator->mRetryTime = GetElapsedMilliseconds() + 5000;
            if (negotiator->mGameSock != -1) {
                negotiator->mCompletedCallback(0, negotiator->mGameSock, fromAddress, negotiator->mUserdata);
            }
        } else if (packet->mFinished == 0) {
            SendPingPacket(negotiator);
        }
    }
}

void ProcessInitPacket(NatTraversalEntry *negotiator, InitPacket *packet, SOCSockAddrIn *fromAddress) {
    u32 portKind;

    switch (packet->mPacketType) {
        case 1:
            portKind = packet->mPortType;
            if (portKind <= 2) {
                negotiator->mInitAckRecv[portKind] = 1;
                if (negotiator->mState == 0 && negotiator->mInitAckRecv[1] != 0 && negotiator->mInitAckRecv[2] != 0 &&
                    (negotiator->mGameSock == -1 || negotiator->mInitAckRecv[0] != 0)) {
                    negotiator->mState = 1;
                    negotiator->mRetryTime = GetElapsedMilliseconds() + 10000;
                    negotiator->mProgressCallback(negotiator->mState, negotiator->mUserdata);
                }
            }
            break;
        case 2:
            packet->mPacketType = 3;
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
        if (typeCode == 5 || typeCode == 7) {
            if (length >= 0x14) {
                connectPacket = *(ConnectPacket *) data;
                cookie = *(u32 *) connectPacket.mCookie;
                negotiator = FindNegotiatorForCookie(
                    (cookie << 24 & 0xff000000) |
                    ((cookie << 8 & 0xff0000) | ((cookie >> 24 & 0xff) | (cookie >> 8 & 0xff00))));
                if (negotiator != NULL) {
                    if (typeCode == 5) {
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

u32 gt2AddressToString(u32 ipAddress, u32 port, char *buffer) {
    SOCInAddr inAddress;
    char *addressString;

    addressString = buffer;
    if (addressString == NULL) {
        nIndex ^= 1;
        addressString = strAddressArray[nIndex];
    }
    if (ipAddress != 0) {
        inAddress.addr = ipAddress;
        if (port != 0) {
            sprintf(addressString, gAddressPortFormat, SOC_InetNtoA(inAddress), port);
        } else {
            sprintf(addressString, gAddressOnlyFormat, SOC_InetNtoA(inAddress));
        }
    } else if (port != 0) {
        sprintf(addressString, gPortOnlyFormat, port);
    } else {
        addressString[0] = 0;
    }
    return (u32) addressString;
}

BOOL gt2StringToAddress(const char *string, u32 *ipOut, u16 *portOut) {
    char hostCopy[0x100];
    const char *portSeparator;
    const char *portCursor;
    s32 g;
    s32 character;
    u32 sourceIp;
    u32 sourcePort;
    SOCHostEnt *hostEntry;

    if (string == NULL || *(s8 *) string == 0) {
        sourceIp = 0;
        sourcePort = 0;
    } else {
        portSeparator = strchr(string, 0x3a);
        if (portSeparator == NULL) {
            sourcePort = 0;
        } else {
            if (portSeparator == string) {
                string = NULL;
                sourceIp = 0;
            } else {
                g = portSeparator - string;
                if (g >= 0x100) {
                    AssertionFailed(gGt2HostLengthAssert, gGt2UtilityFileName, NULL, 0x81);
                }
                memcpy(hostCopy, string, g);
                hostCopy[g] = 0;
                string = hostCopy;
            }
            portCursor = portSeparator + 1;
            character = *(s8 *) (portSeparator + 1);
            if (character != 0) {
                do {
                    if (character < 0 || character >= 0x80) {
                        g = 0;
                    } else {
                        g = gCharClassFlags[character] & 8;
                    }
                    if (g == 0) {
                        return FALSE;
                    }
                    portCursor++;
                    character = *(s8 *) portCursor;
                } while (character != 0);
            }
            g = StrtolBase10(portSeparator + 1);
            if (g < 0 || g > 0xffff) {
                return FALSE;
            }
            sourcePort = (u16) g;
        }
        if (string != NULL) {
            sourceIp = inet_addr((u32) string);
            if (sourceIp == -1) {
                hostEntry = SOC_GetHostByName(string);
                if (hostEntry == NULL) {
                    return FALSE;
                }
                sourceIp = **hostEntry->mAddrList;
            }
        }
    }
    if (ipOut != NULL) {
        *ipOut = sourceIp;
    }
    if (portOut != NULL) {
        *portOut = sourcePort;
    }
    return TRUE;
}
