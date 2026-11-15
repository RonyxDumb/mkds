#include "00/Lib/GameSpy/code_021a3a18.h"

#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/code_021a3000.h"
#include "00/Lib/DWC/dwc_connectinet.h"
#include "00/code_021a4000.h"
#include "00/code_021a88a8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0214d018.h"
#include "00/Lib/GameSpy/code_021a4b84.h"
#include "code_021384cc.h"
#include "code_02139f70.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/NitroWiFi/socl_startup.h"

NatnegMagic gNatnegMagicBytes = {{0xfd, 0xfc, 0x1e, 0x66, 0x6a, 0xb2}};
QueryRecord gStaticQr2Rec = {-1};
QueryRecord *gCurrentQr2Rec = &gStaticQr2Rec;
char gQr2Hostname[64];
s32 gNumLocalIps = 0;
u8 gLocalIpList[5 * 4];
s8 gQr2Indata[256];

s32 qr2_init_socketA(QueryRecord **qrec, s32 socket, s32 boundport, const char *gamename, const char *secretKey,
                     s32 isPublic, s32 natFlag, QueryServerKeyFunc serverKeyFn,
                     QueryPlayerTeamKeyFunc playerKeyFn, QueryPlayerTeamKeyFunc teamKeyFn,
                     QueryKeyListFunc keyListFn, QueryCountFunc countFn,
                     QueryErrorFunc errorFn, void *userData) {
    char hostText[0x40];
    s32 index;
    s8 hostOverride;
    s32 resolved;
    QueryRecord *record;

    if (qrec == NULL) {
        record = &gStaticQr2Rec;
    } else {
        *qrec = DWCi_GsMalloc(0x110);
        record = *qrec;
    }
    srand(GetElapsedMilliseconds());
    strcpy(record->mGameName, gamename);
    strcpy((char *) record->mSecretKey, secretKey);
    record->mQport = boundport;
    index = 0;
    record->mLastHeartbeat = 0;
    record->mLastKeepalive = 0;
    record->mHbSock = socket;
    record->mListedState = 1;
    record->mUserData = userData;
    record->mServerKeyCallback = serverKeyFn;
    record->mPlayerKeyCallback = playerKeyFn;
    record->mTeamKeyCallback = teamKeyFn;
    record->mKeyListCallback = keyListFn;
    record->mPlayerTeamCountCallback = countFn;
    record->mAddErrorCallback = errorFn;
    record->mNatnegCallback = 0;
    record->mClientMessageCallback = 0;
    record->mCdkeyProcess = 0;
    record->mIsPublic = isPublic;
    record->mReadSocket = FALSE;
    record->mNatNegotiate = natFlag;
    record->mPublicIp = 0;
    record->mPublicPort = 0;
    record->mPublicAddressCallback = NULL;
    record->mUserStateChangeRequested = FALSE;
    do {
        record->mInstanceKey[index] = (s32) rand() % 0xff;
        index++;
    } while (index < 4);
    index = 0;
    do {
        record->mClientMessageKeys[index] = -1;
        index++;
    } while (index < 10);
    record->mCurMessageKey = 0;
    if (gNumLocalIps == 0) {
        enum_local_ips();
    }
    if (isPublic != 0) {
        hostOverride = gQr2Hostname[0];
        if (hostOverride == 0) {
            sprintf(hostText, "%s.master.gs.nintendowifi.net", gamename);
        }
        resolved = ResolveQueryHostAddress(hostOverride != 0 ? gQr2Hostname : hostText, 0x6cfc, &record->mHbAddr, NULL);
    } else {
        resolved = 1;
    }
    if (resolved != 0) {
        return 0;
    }
    return 3;
}

void qr2_register_natneg_callback(QueryRecord *qrec, UnkFunc *nncallback) {
    if (qrec == NULL) {
        qrec = gCurrentQr2Rec;
    }
    qrec->mNatnegCallback = nncallback;
}

void qr2_register_clientmessage_callback(QueryRecord *qrec, UnkFunc *cmcallback) {
    if (qrec == NULL) {
        qrec = gCurrentQr2Rec;
    }
    qrec->mClientMessageCallback = cmcallback;
}

void qr2_register_publicaddress_callback(QueryRecord *qrec, QueryPublicAddressFunc pacallback) {
    if (qrec == NULL) {
        qrec = gCurrentQr2Rec;
    }
    qrec->mPublicAddressCallback = pacallback;
}

void qr2_think(QueryRecord *qrec) {
    if (qrec == NULL) {
        qrec = gCurrentQr2Rec;
    }
    if (qrec->mIsPublic != 0) {
        qr2_check_send_heartbeat(qrec);
    }
    qr2_check_queries(qrec);
}

void qr2_check_queries(QueryRecord *qrec) {
    u8 senderAddress[8];
    s32 senderAddressLength;
    s32 zero;
    s32 bytesReceived;

    senderAddressLength = 8;
    if (qrec->mReadSocket != FALSE && CanReceiveOnSocket(qrec->mHbSock) != 0) {
        zero = 0;
        do {
            bytesReceived = recvfrom(qrec->mHbSock, gQr2Indata, 0xff, zero, senderAddress, &senderAddressLength);
            if (bytesReceived != ~zero) {
                gQr2Indata[bytesReceived] = zero;
                qr2_parse_queryA(qrec, gQr2Indata, bytesReceived, senderAddress);
            }
        } while (CanReceiveOnSocket(qrec->mHbSock) != 0);
    }
}

void qr2_check_send_heartbeat(QueryRecord *qrec) {
    u32 currentTime;
    s32 listState;

    currentTime = GetElapsedMilliseconds();
    if (qrec->mHbSock != -1) {
        listState = qrec->mListedState;
        if (listState > 0 && currentTime - qrec->mLastHeartbeat > 10000) {
            if (listState >= 4) {
                qrec->mListedState = 0;
                qrec->mAddErrorCallback(5, (const u8 *) "No challenge value was received from the master server.",
                                        qrec->mUserData);
                return;
            }
            send_heartbeat(qrec, 3);
            qrec->mListedState = qrec->mListedState + 1;
        } else if (qrec->mUserStateChangeRequested != FALSE && currentTime - qrec->mLastHeartbeat > 10000) {
            send_heartbeat(qrec, 1);
        } else if (currentTime - qrec->mLastHeartbeat > 60000 || qrec->mLastHeartbeat == 0 ||
                   currentTime < qrec->mLastHeartbeat) {
            send_heartbeat(qrec, 0);
        }
        if (currentTime - qrec->mLastKeepalive > 20000) {
            send_keepalive(qrec);
        }
    }
}

void qr2_send_statechanged(QueryRecord *qrec) {
    int currentTime;
    if (qrec == NULL) {
        qrec = gCurrentQr2Rec;
    }
    if (qrec->mIsPublic != 0) {
        currentTime = GetElapsedMilliseconds();
        if ((currentTime - qrec->mLastHeartbeat) < (0x00002710u)) {
            qrec->mUserStateChangeRequested = TRUE;
            return;
        }
        send_heartbeat(qrec, 1);
        qrec->mUserStateChangeRequested = FALSE;
    }
}

void qr2_shutdown(QueryRecord *qrec) {
    if (qrec == NULL) {
        qrec = gCurrentQr2Rec;
    }
    if (qrec->mIsPublic != 0) {
        send_heartbeat(qrec, 2);
    }
    if (qrec->mHbSock != -1 && qrec->mReadSocket != FALSE) {
        closesocket(qrec->mHbSock);
    }
    qrec->mHbSock = -1;
    qrec->mLastHeartbeat = 0;
    if (qrec->mReadSocket != FALSE) {
        SocketShutDown();
    }
    if (qrec != &gStaticQr2Rec) {
        DWCi_GsFree(qrec);
    }
}

void qr2_keybuffer_add(MatchingKeyIds *keybuffer, int keyid) {
    int keyCount;
    keyCount = keybuffer->mKeyCount;
    if (((keyCount < 0xfe) && (1 <= keyid)) && (keyid <= 254)) {
        keybuffer->mKeyCount = keyCount + 1;
        keybuffer->mKeys[keyCount] = (s8) keyid;
    }
}

static inline u16 Qr2SwapBytes16(u16 port) {
    return ((port >> 8) & 0xff) | ((port << 8) & 0xff00);
}

void qr2_buffer_add_int(QueryBuffer *outbuf, s32 value) {
    char text[0x18];

    sprintf(text, "%d", value);
    qr2_buffer_addA(outbuf, text);
}

void qr2_buffer_addA(QueryBuffer *outbuf, const char *value) {
    s32 appendLen;
    s32 available;

    appendLen = strlen(value) + 1;
    available = 0x800 - outbuf->mLen;
    if (appendLen > available) {
        appendLen = available;
    }
    if (appendLen != 0) {
        memcpy(&outbuf->mBuffer[outbuf->mLen], value, appendLen);
        outbuf->mLen += appendLen;
        outbuf->mBuffer[outbuf->mLen - 1] = 0;
    }
}

void enum_local_ips(void) {
    SOCHostEnt *localHost;
    LocalIpAddressBytes *hostAddress;
    LocalIpAddressBytes *ownAddressList;

    localHost = getlocalhost();
    if (localHost != NULL) {
        gNumLocalIps = 0;
        ownAddressList = (LocalIpAddressBytes *) gLocalIpList;
        for (; gNumLocalIps < 5; gNumLocalIps++) {
            hostAddress = (LocalIpAddressBytes *) localHost->mAddrList[gNumLocalIps];
            if (hostAddress == NULL) {
                break;
            }
            ownAddressList[gNumLocalIps] = *hostAddress;
        }
    }
}

BOOL ResolveQueryHostAddress(const char *host, u32 port, SOCSockAddrIn *saddr, SOCHostEnt **savehent) {
    SOCHostEnt *hent;

    hent = NULL;
    saddr->mFamily = 2;
    saddr->mPort = Qr2SwapBytes16(port);
    if (host == NULL) {
        saddr->mAddr = 0;
    } else {
        saddr->mAddr = inet_addr(host);
    }
    if (saddr->mAddr == -1) {
        if (strcmp(host, "255.255.255.255") != 0) {
            hent = SOC_GetHostByName(host);
            if (hent == NULL) {
                return FALSE;
            }
            saddr->mAddr = **hent->mAddrList;
        }
    }
    if (savehent != NULL) {
        *savehent = hent;
    }
    return TRUE;
}

void swap_byte(u8 *first, u8 *second) {
    u8 tempByte;
    tempByte = *first;
    *first = *second;
    *second = tempByte;
}

u8 encode_ct(u32 value) {
    if (value < 0x1a) {
        return value + 0x41 & 0xff;
    }
    if (value < 0x34) {
        return value + 0x47 & 0xff;
    }
    if (value < 0x3e) {
        return value - 4 & 0xff;
    }
    if (value == 0x3e) {
        return 0x2b;
    }
    if (value == 0x3f) {
        return 0x2f;
    }
    return 0;
}

void gs_encode(const u8 *ins, s32 size, u8 *result) {
    u8 tripKwart[7];
    s32 inputIndex;
    s32 position;
    u8 *tripCursor;
    s32 quartetIndex;
    u8 currentByte;
    u8 previousByte;

    inputIndex = 0;
    if (size > 0) {
        do {
            for (position = 0, tripCursor = tripKwart; position <= 2; position++, inputIndex++) {
                if (inputIndex < size) {
                    *tripCursor = *ins++;
                } else {
                    *tripCursor = 0;
                }
                tripCursor++;
            }
            currentByte = tripKwart[0];
            tripKwart[3] = currentByte >> 2;
            previousByte = tripKwart[1];
            tripKwart[4] = ((currentByte & 3) << 4) + (previousByte >> 4);
            currentByte = tripKwart[2];
            tripKwart[5] = ((previousByte & 0xf) << 2) + (currentByte >> 6);
            tripKwart[6] = currentByte & 0x3f;
            for (quartetIndex = 0, tripCursor = &tripKwart[3]; quartetIndex <= 3; quartetIndex++) {
                *result++ = encode_ct(*tripCursor);
                tripCursor++;
            }
        } while (inputIndex < size);
    }
    *result = 0;
}

void gs_encrypt(u8 *key, s32 keyLength, u8 *dataBytes, s32 bufferLength) {
    u8 state[0x100];
    s16 byteIndex;
    u8 *statePtrAtX;
    u8 keyPos;
    u8 swapIndex;
    u8 streamX;
    u8 streamIndex;
    s16 fillIndex;
    s16 scheduleIndex;
    u8 *stateCursor;

    for (fillIndex = 0; fillIndex < 0x100; fillIndex++) {
        state[fillIndex] = fillIndex;
    }
    keyPos = 0;
    swapIndex = 0;
    scheduleIndex = 0;
    stateCursor = state;
    do {
        swapIndex = (stateCursor[0] + key[keyPos] + swapIndex) % 0x100;
        keyPos = (keyPos + 1) % keyLength;
        swap_byte(stateCursor, state + swapIndex);
        stateCursor++;
        scheduleIndex++;
    } while (scheduleIndex < 0x100);
    streamX = 0;
    swapIndex = 0;
    byteIndex = 0;
    if (bufferLength > 0) {
        do {
            streamX = (streamX + dataBytes[byteIndex] + 1) % 0x100;
            statePtrAtX = state + streamX;
            swapIndex = (*statePtrAtX + swapIndex) % 0x100;
            swap_byte(statePtrAtX, state + swapIndex);
            streamIndex = (*statePtrAtX + state[swapIndex]) % 0x100;
            dataBytes[byteIndex] ^= state[streamIndex];
            byteIndex++;
        } while (byteIndex < bufferLength);
    }
}

void qr_add_packet_header(u32 buf, u32 ptype, u32 reqkey) {
    u32 body;
    u32 firstByte;
    u32 secondByte;
    u32 thirdByte;
    u32 fourthByte;
    u32 headerLength;
    u32 lengthOffset;
    *(u8 *) ((buf) + (0)) = ptype;
    body = ((buf) + (0x1u));
    firstByte = (*(u8 *) ((reqkey) + (0)));
    *(u8 *) ((buf) + (1)) = firstByte;
    secondByte = (*(u8 *) ((reqkey) + (1)));
    *(u8 *) ((body) + (1)) = secondByte;
    thirdByte = (*(u8 *) ((reqkey) + (2)));
    *(u8 *) ((body) + (2)) = thirdByte;
    fourthByte = (*(u8 *) ((reqkey) + (3)));
    *(u8 *) ((body) + (3)) = fourthByte;
    headerLength = 0x5u;
    lengthOffset = 0x800u;
    *(u32 *) ((buf) + (0 + (lengthOffset))) = headerLength;
}

void compute_challenge_response(QueryRecord *qrec, QueryBuffer *buf, const char *challenge, s32 challengelen) {
    u8 cipherBytes[0x44];

    if (challengelen >= 1 && challengelen <= 0x41 && ((s8 *) challenge)[challengelen - 1] == 0) {
        strcpy((char *) cipherBytes, challenge);
        gs_encrypt(qrec->mSecretKey, strlen((const char *) qrec->mSecretKey), cipherBytes, challengelen - 1);
        gs_encode(cipherBytes, challengelen - 1, &buf->mBuffer[buf->mLen]);
        buf->mLen += strlen((const char *) &buf->mBuffer[buf->mLen]) + 1;
    }
}

void handle_public_address(QueryRecord *qrec, const char *buffer) {
    u32 outerAddress;
    u32 scannedPort;
    u16 natPort;

    sscanf(buffer, "%08X%04X", &outerAddress, &scannedPort);
    natPort = scannedPort;
    outerAddress = (outerAddress << 24 & 0xff000000) |
               ((outerAddress << 8 & 0xff0000) | ((outerAddress >> 24 & 0xff) | (outerAddress >> 8 & 0xff00)));
    if (outerAddress != 0 && natPort != 0) {
        if (qrec->mPublicIp != outerAddress || qrec->mPublicPort != natPort) {
            qrec->mPublicIp = outerAddress;
            qrec->mPublicPort = natPort;
            qrec->mPublicAddressCallback(outerAddress, natPort, qrec->mUserData);
        }
    }
}

void qr_build_partial_query_reply(QueryRecord *qrec, QueryBuffer *buf, s32 keytype, s32 keycount, const u8 *keys) {
    MatchingKeyIds keybuffer;
    u16 countShort;
    u16 swappedCount;
    s32 countValue;
    s32 playerIdx;
    s32 bufferLength;
    s32 keyIndex;
    s32 firstKeyIndex;
    s32 keyPosition;
    const u8 *keyCursor;
    const char *keyName;
    u8 *countBytes;
    u8 *writePtr;

    keybuffer.mKeyCount = 0;
    if (keycount == 0) {
        return;
    }
    if ((u32) (keytype - 1) <= 1) {
        if ((u32) (0x800 - buf->mLen) < 2) {
            return;
        }
        countValue = qrec->mPlayerTeamCountCallback(keytype, qrec->mUserData);
        countShort = countValue;
        swappedCount = (countShort >> 8 & 0xff) | (countShort << 8 & 0xff00);
        writePtr = &buf->mBuffer[buf->mLen];
        countBytes = (u8 *) &swappedCount;
        writePtr[0] = countBytes[0];
        writePtr[1] = countBytes[1];
        buf->mLen += 2;
    } else {
        countValue = 1;
    }
    if (keycount == 0xff) {
        qrec->mKeyListCallback(keytype, &keybuffer, qrec->mUserData);
        keyIndex = 0;
        if (keybuffer.mKeyCount > 0) {
            keyCursor = keybuffer.mKeys;
            do {
                keyName = gQr2RegisteredKeyList[*keyCursor];
                if (keyName == NULL) {
                    keyName = "unknown";
                }
                qr2_buffer_addA(buf, keyName);
                if (keytype == 0) {
                    bufferLength = buf->mLen;
                    qrec->mServerKeyCallback(*keyCursor, buf, qrec->mUserData);
                    if (bufferLength == buf->mLen) {
                        qr2_buffer_addA(buf, "");
                    }
                }
                keyCursor++;
                keyIndex++;
            } while (keyIndex < keybuffer.mKeyCount);
        }
        if (0x800 - buf->mLen < 1) {
            return;
        }
        buf->mBuffer[buf->mLen++] = 0;
        keycount = keybuffer.mKeyCount;
        keys = keybuffer.mKeys;
        if (keytype == 0) {
            return;
        }
    }
    playerIdx = 0;
    if (countValue > 0) {
        firstKeyIndex = playerIdx;
        do {
            keyPosition = firstKeyIndex;
            if (keycount > 0) {
                do {
                    bufferLength = buf->mLen;
                    if (keytype == 0) {
                        qrec->mServerKeyCallback(keys[keyPosition], buf, qrec->mUserData);
                    } else if (keytype == 1) {
                        qrec->mPlayerKeyCallback(keys[keyPosition], playerIdx, buf, qrec->mUserData);
                    } else if (keytype == 2) {
                        qrec->mTeamKeyCallback(keys[keyPosition], playerIdx, buf, qrec->mUserData);
                    }
                    if (bufferLength == buf->mLen) {
                        qr2_buffer_addA(buf, "");
                    }
                    keyPosition++;
                } while (keyPosition < keycount);
            }
            playerIdx++;
        } while (playerIdx < countValue);
    }
}

void qr_build_query_reply(QueryRecord *qrec, QueryBuffer *buf, s32 serverkeycount, const u8 *serverkeys,
                          s32 playerkeycount, const u8 *playerkeys, s32 teamkeycount, const u8 *teamkeys) {
    qr_build_partial_query_reply(qrec, buf, 0, serverkeycount, serverkeys);
    qr_build_partial_query_reply(qrec, buf, 1, playerkeycount, playerkeys);
    qr_build_partial_query_reply(qrec, buf, 2, teamkeycount, teamkeys);
}

void qr_process_query(QueryRecord *qrec, QueryBuffer *buf, const u8 *qdata, s32 len) {
    u8 serverKeyTotal;
    u8 playerKeyTotal;
    u8 teamKeyTotal;
    const u8 *serverKeyList;
    const u8 *playerKeyList;
    const u8 *teamKeyList;

    serverKeyList = NULL;
    playerKeyList = NULL;
    teamKeyList = NULL;
    if (len >= 3) {
        serverKeyTotal = *qdata++;
        len--;
        if (serverKeyTotal != 0 && serverKeyTotal != 0xff) {
            serverKeyList = qdata;
            qdata += serverKeyTotal;
            len -= serverKeyTotal;
        }
        if (len >= 2) {
            playerKeyTotal = *qdata++;
            len--;
            if (playerKeyTotal != 0 && playerKeyTotal != 0xff) {
                playerKeyList = qdata;
                qdata += playerKeyTotal;
                len -= playerKeyTotal;
            }
            if (len >= 1) {
                teamKeyTotal = *qdata;
                len--;
                if (teamKeyTotal != 0 && teamKeyTotal != 0xff) {
                    teamKeyList = qdata + 1;
                    len -= teamKeyTotal;
                }
                if (len >= 0) {
                    qr_build_query_reply(qrec, buf, serverKeyTotal, serverKeyList, playerKeyTotal, playerKeyList,
                                         teamKeyTotal, teamKeyList);
                }
            }
        }
    }
}

void qr_build_partial_old_query_reply(QueryRecord *qrec, QueryBuffer *buf, s32 keytype) {
    char keyNameBuf[0x80];
    MatchingKeyIds keybuffer;
    s32 teamTotal;
    s32 bufferLength;
    s32 keyIndex;
    s32 firstPindex;
    s32 playerIdx;
    const char *keyName;
    u8 *keyCursor;

    keybuffer.mKeyCount = 0;
    if ((u32) (keytype - 1) <= 1) {
        teamTotal = qrec->mPlayerTeamCountCallback(keytype, qrec->mUserData);
    } else {
        teamTotal = 1;
    }
    qrec->mKeyListCallback(keytype, &keybuffer, qrec->mUserData);
    keyIndex = 0;
    if (keybuffer.mKeyCount > 0) {
        keyCursor = keybuffer.mKeys;
        firstPindex = keyIndex;
        do {
            keyName = gQr2RegisteredKeyList[*keyCursor];
            if (keyName == NULL) {
                keyName = "unknown";
            }
            if (keytype == 0) {
                qr2_buffer_addA(buf, keyName);
                buf->mBuffer[buf->mLen - 1] = 0x5c;
                bufferLength = buf->mLen;
                qrec->mServerKeyCallback(*keyCursor, buf, qrec->mUserData);
                if (bufferLength == buf->mLen) {
                    qr2_buffer_addA(buf, "");
                }
                buf->mBuffer[buf->mLen - 1] = 0x5c;
            } else {
                playerIdx = firstPindex;
                if (teamTotal > 0) {
                    do {
                        sprintf(keyNameBuf, "%s%d", keyName, playerIdx);
                        qr2_buffer_addA(buf, keyNameBuf);
                        buf->mBuffer[buf->mLen - 1] = 0x5c;
                        bufferLength = buf->mLen;
                        if (keytype == 1) {
                            qrec->mPlayerKeyCallback(*keyCursor, playerIdx, buf, qrec->mUserData);
                        } else if (keytype == 2) {
                            qrec->mTeamKeyCallback(*keyCursor, playerIdx, buf, qrec->mUserData);
                        }
                        if (bufferLength == buf->mLen) {
                            qr2_buffer_addA(buf, "");
                        }
                        buf->mBuffer[buf->mLen - 1] = 0x5c;
                        playerIdx++;
                    } while (playerIdx < teamTotal);
                }
            }
            keyCursor++;
            keyIndex++;
        } while (keyIndex < keybuffer.mKeyCount);
    }
}

void qr_process_old_query(QueryRecord *qrec, QueryBuffer *buf) {
    buf->mLen = 1;
    buf->mBuffer[0] = 0x5c;
    qr_build_partial_old_query_reply(qrec, buf, 0);
    qr_build_partial_old_query_reply(qrec, buf, 1);
    qr_build_partial_old_query_reply(qrec, buf, 2);
    qr2_buffer_addA(buf, "final\\\\queryid\\1.1");
    buf->mLen = buf->mLen + -1;
}

void qr_process_client_message(QueryRecord *qrec, u8 *buf, s32 len) {
    NatnegMagic magicRef = gNatnegMagicBytes;
    s32 index;
    BOOL natNegPacket = TRUE;
    u32 echoCookie;
    u8 *cookieSource;
    u8 *cookieBytes;
    if (len >= 10) {
        for (index = 0; index < 6; index++) {
            if (magicRef.mBytes[index] != buf[index]) {
                natNegPacket = FALSE;
                break;
            }
        }
    } else {
        natNegPacket = FALSE;
    }
    if (natNegPacket != FALSE) {
        cookieBytes = (u8 *) &echoCookie;
        cookieSource = buf + 6;
        cookieBytes[0] = cookieSource[0];
        cookieBytes[1] = cookieSource[1];
        cookieBytes[2] = cookieSource[2];
        cookieBytes[3] = cookieSource[3];
        if (qrec->mNatnegCallback != NULL) {
            qrec->mNatnegCallback(
                ((echoCookie << 24) & 0xff000000) |
                    (((echoCookie << 8) & 0xff0000) | (((echoCookie >> 24) & 0xff) | ((echoCookie >> 8) & 0xff00))),
                qrec->mUserData);
        }
    } else if (qrec->mClientMessageCallback != NULL) {
        qrec->mClientMessageCallback((s8 *) buf, len, qrec->mUserData);
    }
}

BOOL qr_got_recent_message(QueryRecord *qrec, int msgkey) {
    int index;
    int nextIndex;
    int *keyField;
    index = 0;
    do {
        if (msgkey == qrec->mClientMessageKeys[index]) {
            return 1;
        }
        index = index + 1;
    } while (index < 10);
    nextIndex = (qrec->mCurMessageKey + 1) % (10);
    keyField = &qrec->mCurMessageKey;
    *keyField = nextIndex;
    qrec->mClientMessageKeys[*keyField] = msgkey;
    return 0;
}

void qr2_parse_queryA(QueryRecord *qrec, s8 *query, s32 len, void *sender) {
    QueryBuffer buf;
    s32 queryKind;
    s32 index;
    s8 *requestKey;
    s8 *pos;
    buf.mLen = 0;
    if (qrec == NULL) {
        qrec = gCurrentQr2Rec;
    }
    if (query[0] == 0x3b) {
        if (qrec->mCdkeyProcess != NULL) {
            qrec->mCdkeyProcess(query, len, sender);
            return;
        }
    } else if (query[0] == 0x5c) {
        qr_process_old_query(qrec, &buf);
        sendto(qrec->mHbSock, &buf, buf.mLen, 0, sender, 8);
        return;
    } else if (len >= 7) {
        if ((u8) query[0] == 0xfe) {
            if ((u8) query[1] == 0xfd) {
                if (qrec->mListedState > 0) {
                    qrec->mListedState = 0;
                }
                queryKind = query[2];
                requestKey = query + 3;
                pos = query + 7;
                len = len - 7;
                qr_add_packet_header((u32) &buf, queryKind, (u32) requestKey);
                switch (queryKind) {
                    case 0:
                        qr_process_query(qrec, &buf, (u8 *) pos, len);
                        break;
                    case 1:
                        if (len >= 13 && qrec->mPublicAddressCallback != 0) {
                            handle_public_address(qrec, (const char *) (pos + len - 13));
                        }
                        compute_challenge_response(qrec, &buf, (const char *) pos, len);
                        break;
                    case 2:
                        if (len > 0x20) {
                            len = 0x20;
                        }
                        buf.mBuffer[0] = 5;
                        memcpy(&buf.mBuffer[buf.mLen], pos, len);
                        buf.mLen += len;
                        break;
                    case 4:
                        if (qrec->mListedState == -1) {
                            return;
                        }
                        for (index = 0; index < 4; index++) {
                            if (requestKey[index] != qrec->mInstanceKey[index]) {
                                return;
                            }
                        }
                        if (len < 2) {
                            return;
                        }
                        qrec->mListedState = -1;
                        qrec->mAddErrorCallback(pos[0], (u8 *) (pos + 1), qrec->mUserData);
                        return;
                    case 6:
                        for (index = 0; index < 4; index++) {
                            if (requestKey[index] != qrec->mInstanceKey[index]) {
                                return;
                            }
                        }
                        if (len < 4) {
                            return;
                        }
                        buf.mBuffer[0] = 7;
                        __memcpy(&buf.mBuffer[buf.mLen], pos, 4);
                        buf.mLen += 4;
                        __memcpy(&index, pos, 4);
                        if (qr_got_recent_message(qrec, index) == 0) {
                            qr_process_client_message(qrec, (u8 *) (pos + 4), len - 4);
                        }
                        break;
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    default:
                        return;
                }
                sendto(qrec->mHbSock, &buf, buf.mLen, 0, sender, 8);
            }
        }
    }
}

void send_keepalive(QueryRecord *qrec) {
    QueryBuffer buf;
    buf.mLen = 0;
    qr_add_packet_header((u32) &buf, 8, (u32) qrec->mInstanceKey);
    sendto(qrec->mHbSock, &buf, buf.mLen, 0, &qrec->mHbAddr, 8);
    qrec->mLastKeepalive = GetElapsedMilliseconds();
}

void send_heartbeat(QueryRecord *qrec, s32 statechanged) {
    QueryBuffer buf;
    char keyText[0x14];
    s32 index;
    buf.mLen = 0;
    qr_add_packet_header((u32) &buf, 3, (u32) qrec->mInstanceKey);
    for (index = 0; index < gNumLocalIps; index++) {
        sprintf(keyText, "localip%d", index);
        qr2_buffer_addA(&buf, keyText);
        qr2_buffer_addA(&buf, SOC_InetNtoA(((SOCInAddr *) gLocalIpList)[index]));
    }
    qr2_buffer_addA(&buf, "localport");
    qr2_buffer_add_int(&buf, qrec->mQport);
    qr2_buffer_addA(&buf, "natneg");
    qr2_buffer_addA(&buf, qrec->mNatNegotiate != 0 ? "1" : "0");
    if (statechanged != 0) {
        qr2_buffer_addA(&buf, "statechanged");
        qr2_buffer_add_int(&buf, statechanged);
    }
    qr2_buffer_addA(&buf, "gamename");
    qr2_buffer_addA(&buf, qrec->mGameName);
    if (qrec->mPublicAddressCallback != 0) {
        qr2_buffer_addA(&buf, "publicip");
        qr2_buffer_add_int(&buf, qrec->mPublicIp);
        qr2_buffer_addA(&buf, "publicport");
        qr2_buffer_add_int(&buf, qrec->mPublicPort);
    }
    if (statechanged != 2) {
        qr_build_query_reply(qrec, &buf, 0xff, NULL, 0xff, NULL, 0xff, NULL);
    } else if (0x800 - buf.mLen >= 1) {
        buf.mBuffer[buf.mLen++] = 0;
    }
    sendto(qrec->mHbSock, &buf, buf.mLen, 0, &qrec->mHbAddr, 8);
    qrec->mLastHeartbeat = GetElapsedMilliseconds();
    qrec->mLastKeepalive = qrec->mLastHeartbeat;
    if (statechanged != 0) {
        qrec->mUserStateChangeRequested = 0;
    }
}
