#include "00/code_021a3a18.h"

#include "00/code_0218e2dc.h"
#include "00/code_021a3000.h"
#include "00/code_021a3760.h"
#include "00/code_021a4000.h"
#include "00/code_021a88a8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0214d018.h"
#include "00/code_021a4b84.h"
#include "code_021384cc.h"
#include "code_02139f70.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/code_021a6d5c.h"

s32 qr2_init_socketA(QueryRecord **qrec, s32 socket, s32 boundport, const char *gamename, const char *secretKey,
                     s32 isPublic, s32 natFlag, Unk021a4a08Func88 serverKeyFn,
                     Unk021a4a08Func8c playerKeyFn, Unk021a4a08Func8c teamKeyFn,
                     Unk021a4a08Func94 keyListFn, Unk021a4a08Func98 countFn,
                     Unk021a4a08Func9c errorFn, void *userData) {
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
    strcpy((char *) record->mGameName, gamename);
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
            sprintf(hostText, gQr2MasterHostnameFormat, gamename);
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

void qr2_register_publicaddress_callback(void *qrec, void (*pacallback)(void *, u16)) {
    if (qrec == NULL) {
        qrec = gCurrentQr2Rec;
    }
    *(void (**)(void *, u16))((u8 *) qrec + 0xa8) = pacallback;
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
                qr2_parse_queryA((Unk021a3a18 *) qrec, gQr2Indata, bytesReceived, senderAddress);
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
                qrec->mAddErrorCallback(5, gNoChallengeErrorMessage, qrec->mUserData);
                return;
            }
            send_heartbeat((Unk021a3a18 *) qrec, 3);
            qrec->mListedState = qrec->mListedState + 1;
        } else if (qrec->mUserStateChangeRequested != FALSE && currentTime - qrec->mLastHeartbeat > 10000) {
            send_heartbeat((Unk021a3a18 *) qrec, 1);
        } else if (currentTime - qrec->mLastHeartbeat > 60000 || qrec->mLastHeartbeat == 0 ||
                   currentTime < qrec->mLastHeartbeat) {
            send_heartbeat((Unk021a3a18 *) qrec, 0);
        }
        if (currentTime - qrec->mLastKeepalive > 20000) {
            send_keepalive((Unk021a3a18 *) qrec);
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
        send_heartbeat((Unk021a3a18 *) qrec, 1);
        qrec->mUserStateChangeRequested = FALSE;
    }
}

void qr2_shutdown(QueryRecord *qrec) {
    if (qrec == NULL) {
        qrec = gCurrentQr2Rec;
    }
    if (qrec->mIsPublic != 0) {
        send_heartbeat((Unk021a3a18 *) qrec, 2);
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
    keyCount = keybuffer->mUnk_100;
    if (((keyCount < 0xfe) && (1 <= keyid)) && (keyid <= 254)) {
        keybuffer->mUnk_100 = keyCount + 1;
        keybuffer->mUnk_000[keyCount] = (s8) keyid;
    }
}

static inline u16 Qr2SwapBytes16(u16 port) {
    return ((port >> 8) & 0xff) | ((port << 8) & 0xff00);
}

void qr2_buffer_add_int(QueryBuffer *outbuf, s32 value) {
    char text[0x18];

    sprintf(text, gIntFormat, value);
    qr2_buffer_addA(outbuf, text);
}

void qr2_buffer_addA(QueryBuffer *outbuf, const char *value) {
    s32 appendLen;
    s32 available;

    appendLen = strlen(value) + 1;
    available = 0x800 - outbuf->mUnk_800;
    if (appendLen > available) {
        appendLen = available;
    }
    if (appendLen != 0) {
        memcpy(&outbuf->mUnk_000[outbuf->mUnk_800], value, appendLen);
        outbuf->mUnk_800 += appendLen;
        outbuf->mUnk_000[outbuf->mUnk_800 - 1] = 0;
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
            hostAddress = (LocalIpAddressBytes *) localHost->mUnk_0c[gNumLocalIps];
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
        saddr->mAddr = inet_addr((u32) host);
    }
    if (saddr->mAddr == -1) {
        if (strcmp(host, gBroadcastAddress) != 0) {
            hent = SOC_GetHostByName(host);
            if (hent == NULL) {
                return FALSE;
            }
            saddr->mAddr = **hent->mUnk_0c;
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
    u8 i;
    u8 j;

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
            i = tripKwart[0];
            tripKwart[3] = i >> 2;
            j = tripKwart[1];
            tripKwart[4] = ((i & 3) << 4) + (j >> 4);
            i = tripKwart[2];
            tripKwart[5] = ((j & 0xf) << 2) + (i >> 6);
            tripKwart[6] = i & 0x3f;
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
        gs_encode(cipherBytes, challengelen - 1, &buf->mUnk_000[buf->mUnk_800]);
        buf->mUnk_800 += strlen((const char *) &buf->mUnk_000[buf->mUnk_800]) + 1;
    }
}

void handle_public_address(QueryRecord *qrec, const char *buffer) {
    u32 outerAddress;
    u32 scannedPort;
    u16 natPort;

    sscanf(buffer, gPublicAddressFormat, &outerAddress, &scannedPort);
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

    keybuffer.mUnk_100 = 0;
    if (keycount == 0) {
        return;
    }
    if ((u32) (keytype - 1) <= 1) {
        if ((u32) (0x800 - buf->mUnk_800) < 2) {
            return;
        }
        countValue = qrec->mPlayerTeamCountCallback(keytype, qrec->mUserData);
        countShort = countValue;
        swappedCount = (countShort >> 8 & 0xff) | (countShort << 8 & 0xff00);
        writePtr = &buf->mUnk_000[buf->mUnk_800];
        countBytes = (u8 *) &swappedCount;
        writePtr[0] = countBytes[0];
        writePtr[1] = countBytes[1];
        buf->mUnk_800 += 2;
    } else {
        countValue = 1;
    }
    if (keycount == 0xff) {
        qrec->mKeyListCallback(keytype, &keybuffer, qrec->mUserData);
        keyIndex = 0;
        if (keybuffer.mUnk_100 > 0) {
            keyCursor = keybuffer.mUnk_000;
            do {
                keyName = gQr2RegisteredKeyList[*keyCursor];
                if (keyName == NULL) {
                    keyName = gUnregisteredKeyName;
                }
                qr2_buffer_addA(buf, keyName);
                if (keytype == 0) {
                    bufferLength = buf->mUnk_800;
                    qrec->mServerKeyCallback(*keyCursor, buf, qrec->mUserData);
                    if (bufferLength == buf->mUnk_800) {
                        qr2_buffer_addA(buf, data_ov000_021b4400);
                    }
                }
                keyCursor++;
                keyIndex++;
            } while (keyIndex < keybuffer.mUnk_100);
        }
        if (0x800 - buf->mUnk_800 < 1) {
            return;
        }
        buf->mUnk_000[buf->mUnk_800++] = 0;
        keycount = keybuffer.mUnk_100;
        keys = keybuffer.mUnk_000;
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
                    bufferLength = buf->mUnk_800;
                    if (keytype == 0) {
                        qrec->mServerKeyCallback(keys[keyPosition], buf, qrec->mUserData);
                    } else if (keytype == 1) {
                        qrec->mPlayerKeyCallback(keys[keyPosition], playerIdx, buf, qrec->mUserData);
                    } else if (keytype == 2) {
                        qrec->mTeamKeyCallback(keys[keyPosition], playerIdx, buf, qrec->mUserData);
                    }
                    if (bufferLength == buf->mUnk_800) {
                        qr2_buffer_addA(buf, data_ov000_021b4400);
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

    keybuffer.mUnk_100 = 0;
    if ((u32) (keytype - 1) <= 1) {
        teamTotal = qrec->mPlayerTeamCountCallback(keytype, qrec->mUserData);
    } else {
        teamTotal = 1;
    }
    qrec->mKeyListCallback(keytype, &keybuffer, qrec->mUserData);
    keyIndex = 0;
    if (keybuffer.mUnk_100 > 0) {
        keyCursor = keybuffer.mUnk_000;
        firstPindex = keyIndex;
        do {
            keyName = gQr2RegisteredKeyList[*keyCursor];
            if (keyName == NULL) {
                keyName = gUnregisteredKeyName;
            }
            if (keytype == 0) {
                qr2_buffer_addA(buf, keyName);
                buf->mUnk_000[buf->mUnk_800 - 1] = 0x5c;
                bufferLength = buf->mUnk_800;
                qrec->mServerKeyCallback(*keyCursor, buf, qrec->mUserData);
                if (bufferLength == buf->mUnk_800) {
                    qr2_buffer_addA(buf, data_ov000_021b4400);
                }
                buf->mUnk_000[buf->mUnk_800 - 1] = 0x5c;
            } else {
                playerIdx = firstPindex;
                if (teamTotal > 0) {
                    do {
                        sprintf(keyNameBuf, data_ov000_021b4404, keyName, playerIdx);
                        qr2_buffer_addA(buf, keyNameBuf);
                        buf->mUnk_000[buf->mUnk_800 - 1] = 0x5c;
                        bufferLength = buf->mUnk_800;
                        if (keytype == 1) {
                            qrec->mPlayerKeyCallback(*keyCursor, playerIdx, buf, qrec->mUserData);
                        } else if (keytype == 2) {
                            qrec->mTeamKeyCallback(*keyCursor, playerIdx, buf, qrec->mUserData);
                        }
                        if (bufferLength == buf->mUnk_800) {
                            qr2_buffer_addA(buf, data_ov000_021b4400);
                        }
                        buf->mUnk_000[buf->mUnk_800 - 1] = 0x5c;
                        playerIdx++;
                    } while (playerIdx < teamTotal);
                }
            }
            keyCursor++;
            keyIndex++;
        } while (keyIndex < keybuffer.mUnk_100);
    }
}

void qr_process_old_query(QueryRecord *qrec, QueryBuffer *buf) {
    buf->mUnk_800 = 1;
    buf->mUnk_000[0] = 0x5c;
    qr_build_partial_old_query_reply(qrec, buf, 0);
    qr_build_partial_old_query_reply(qrec, buf, 1);
    qr_build_partial_old_query_reply(qrec, buf, 2);
    qr2_buffer_addA(buf, gFinalQueryidText);
    buf->mUnk_800 = buf->mUnk_800 + -1;
}

void qr_process_client_message(Unk021a3a18 *qrec, u8 *buf, s32 len) {
    NatnegMagic magicRef = gNatnegMagicBytes;
    s32 index;
    BOOL natNegPacket = TRUE;
    u32 echoCookie;
    u8 *cookieSource;
    u8 *cookieBytes;
    if (len >= 10) {
        for (index = 0; index < 6; index++) {
            if (magicRef.mUnk_00[index] != buf[index]) {
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
        if (qrec->mUnk_a0 != NULL) {
            qrec->mUnk_a0(((echoCookie << 24) & 0xff000000) |
                              (((echoCookie << 8) & 0xff0000) | (((echoCookie >> 24) & 0xff) | ((echoCookie >> 8) & 0xff00))),
                          qrec->mUnk_10c);
        }
    } else if (qrec->mUnk_a4 != NULL) {
        qrec->mUnk_a4((s8 *) buf, len, qrec->mUnk_10c);
    }
}

BOOL qr_got_recent_message(Unk021a3a18 *qrec, int msgkey) {
    int index;
    int nextIndex;
    int *keyField;
    index = 0;
    do {
        if (msgkey == qrec->mUnk_d8[index]) {
            return 1;
        }
        index = index + 1;
    } while (index < 10);
    nextIndex = (qrec->mUnk_100 + 1) % (10);
    keyField = &qrec->mUnk_100;
    *keyField = nextIndex;
    qrec->mUnk_d8[*keyField] = msgkey;
    return 0;
}

void qr2_parse_queryA(Unk021a3a18 *qrec, s8 *query, s32 len, void *sender) {
    QueryBuffer buf;
    s32 queryKind;
    s32 index;
    s8 *requestKey;
    s8 *pos;
    buf.mUnk_800 = 0;
    if (qrec == NULL) {
        qrec = (Unk021a3a18 *) gCurrentQr2Rec;
    }
    if (query[0] == 0x3b) {
        if (qrec->mUnk_d4 != NULL) {
            qrec->mUnk_d4(query, len, sender);
            return;
        }
    } else if (query[0] == 0x5c) {
        qr_process_old_query((QueryRecord *) qrec, &buf);
        sendto(qrec->mUnk_00, &buf, buf.mUnk_800, 0, sender, 8);
        return;
    } else if (len >= 7) {
        if ((u8) query[0] == 0xfe) {
            if ((u8) query[1] == 0xfd) {
                if (qrec->mUnk_b8 > 0) {
                    qrec->mUnk_b8 = 0;
                }
                queryKind = query[2];
                requestKey = query + 3;
                pos = query + 7;
                len = len - 7;
                qr_add_packet_header((u32) &buf, queryKind, (u32) requestKey);
                switch (queryKind) {
                    case 0:
                        qr_process_query((QueryRecord *) qrec, &buf, (u8 *) pos, len);
                        break;
                    case 1:
                        if (len >= 13 && qrec->mUnk_a8 != 0) {
                            handle_public_address((QueryRecord *) qrec, (const char *) (pos + len - 13));
                        }
                        compute_challenge_response((QueryRecord *) qrec, &buf, (const char *) pos, len);
                        break;
                    case 2:
                        if (len > 0x20) {
                            len = 0x20;
                        }
                        buf.mUnk_000[0] = 5;
                        memcpy(&buf.mUnk_000[buf.mUnk_800], pos, len);
                        buf.mUnk_800 += len;
                        break;
                    case 4:
                        if (qrec->mUnk_b8 == -1) {
                            return;
                        }
                        for (index = 0; index < 4; index++) {
                            if (requestKey[index] != qrec->mUnk_84[index]) {
                                return;
                            }
                        }
                        if (len < 2) {
                            return;
                        }
                        qrec->mUnk_b8 = -1;
                        qrec->mUnk_9c(pos[0], (u8 *) (pos + 1), qrec->mUnk_10c);
                        return;
                    case 6:
                        for (index = 0; index < 4; index++) {
                            if (requestKey[index] != qrec->mUnk_84[index]) {
                                return;
                            }
                        }
                        if (len < 4) {
                            return;
                        }
                        buf.mUnk_000[0] = 7;
                        __memcpy(&buf.mUnk_000[buf.mUnk_800], pos, 4);
                        buf.mUnk_800 += 4;
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
                sendto(qrec->mUnk_00, &buf, buf.mUnk_800, 0, sender, 8);
            }
        }
    }
}

void send_keepalive(Unk021a3a18 *qrec) {
    QueryBuffer buf;
    buf.mUnk_800 = 0;
    qr_add_packet_header((u32) &buf, 8, (u32) qrec->mUnk_84);
    sendto(qrec->mUnk_00, &buf, buf.mUnk_800, 0, qrec->mUnk_cc, 8);
    qrec->mUnk_b0 = GetElapsedMilliseconds();
}

void send_heartbeat(Unk021a3a18 *qrec, s32 statechanged) {
    QueryBuffer buf;
    char keyText[0x14];
    s32 index;
    buf.mUnk_800 = 0;
    qr_add_packet_header((u32) &buf, 3, (u32) qrec->mUnk_84);
    for (index = 0; index < gNumLocalIps; index++) {
        sprintf(keyText, gLocalIpKeyFormat, index);
        qr2_buffer_addA(&buf, keyText);
        qr2_buffer_addA(&buf, SOC_InetNtoA(((SOCInAddr *) gLocalIpList)[index]));
    }
    qr2_buffer_addA(&buf, gLocalportKey);
    qr2_buffer_add_int(&buf, qrec->mUnk_c0);
    qr2_buffer_addA(&buf, gNatnegKey);
    qr2_buffer_addA(&buf, qrec->mUnk_c8 != 0 ? gNatnegOnValue : gNatnegOffValue);
    if (statechanged != 0) {
        qr2_buffer_addA(&buf, gStatechangedKey);
        qr2_buffer_add_int(&buf, statechanged);
    }
    qr2_buffer_addA(&buf, gGamenamePlainKey);
    qr2_buffer_addA(&buf, qrec->mUnk_04);
    if (qrec->mUnk_a8 != 0) {
        qr2_buffer_addA(&buf, gPublicipKey);
        qr2_buffer_add_int(&buf, qrec->mUnk_104);
        qr2_buffer_addA(&buf, gPublicportKey);
        qr2_buffer_add_int(&buf, qrec->mUnk_108);
    }
    if (statechanged != 2) {
        qr_build_query_reply((QueryRecord *) qrec, &buf, 0xff, NULL, 0xff, NULL, 0xff, NULL);
    } else if (0x800 - buf.mUnk_800 >= 1) {
        buf.mUnk_000[buf.mUnk_800++] = 0;
    }
    sendto(qrec->mUnk_00, &buf, buf.mUnk_800, 0, qrec->mUnk_cc, 8);
    qrec->mUnk_ac = GetElapsedMilliseconds();
    qrec->mUnk_b0 = qrec->mUnk_ac;
    if (statechanged != 0) {
        qrec->mUnk_b4 = 0;
    }
}
