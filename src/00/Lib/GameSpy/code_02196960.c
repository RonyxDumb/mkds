#include "00/Lib/GameSpy/code_02196960.h"
#include "00/unk_021b3000.h"
#include "00/unk_021b4000.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "00/Lib/GameSpy/code_0218d488.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/code_02196000.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "code_021382a8.h"
#include "00/Lib/NitroWiFi/socl_startup.h"

extern u8 gEnc1[16];

typedef struct CdKeyTooLongText {
    /* 00 */ s8 mUnk_00[0x1d];
} CdKeyTooLongText;

char gcd_gamename[256] = "";
char gcd_secret_key[256] = "";
static u32 gInitStart = 0;
static void *gServerReqs = NULL;
static s32 gValueIndex = 0;
static s8 *gStatsGame = NULL;
static s32 gSock = -1;
static u8 gEnc2[16] = {'\0', 'n', 'd', 'u', 's', 't', 'r', 'i', 'e', 's', '\0'};
static u8 gEnc1[16] = {'\0', 'a', 'm', 'e', 'S', 'p', 'y', '3', 'D', '\0'};
static char gUnusedOrderPad16[16] = {1};
static u8 gStatsFile[16] = {'\0', 's', 't', 'a', 't', 's', '.', 'd', 'a', 't', '\0'};
static char gChallengeStr[] = {'\0', 'h', 'a', 'l', 'l', 'e', 'n', 'g', 'e', '\0'};
static char gFinalStr[10] = {'\0', 'f', 'i', 'n', 'a', 'l', '\\', '\0'};
static char gSessKeyStr[] = {'\0', 'e', 's', 's', 'k', 'e', 'y', '\0'};
static u8 *gEnc = gEnc1;
static s32 gRcvMax = 0;
static s8 *gRcvBuffer = NULL;
static u32 gSessKey = 0;
static u32 gConnId = 0;
static s32 gGamePort = 0;
static s32 gRcvLen = 0;
static s32 gStatsInitState = 0;
static u32 gInitTimeout = 20000;
char gStatsServerHostname[64] = "gamestats.gs.nintendowifi.net";
static u32 gInternalInit = 0;
static void *gUnusedOrderPointers9[3][3] = {
    {&gSock, &gSock, &gSock}, {&gSock, &gSock, &gSock}, {&gSock, &gSock, &gSock}};
static u8 gEnc3[16] = {'\0', 'r', 'o', 'j', 'e', 'c', 't', 'A', 'p', 'h', 'e', 'x', '\0'};
static void *gUnusedOrderPointers7[7] = {&gSock, &gSock, &gSock, &gSock, &gSock, &gSock, &gSock};

s8 *GenerateAuthA(const char *challenge, const char *password, s8 *response) {
    u32 passwordLen;
    char hashInput[0x80];
    passwordLen = strlen(password);
    if (strlen(challenge) + passwordLen + 0x14 >= 0x80) {
        *(CdKeyTooLongText *) response = *(const CdKeyTooLongText *) "CD Key or challenge too long";
        return response;
    }
    sprintf(hashInput, "%s%s", password, challenge);
    MD5Digest(hashInput, strlen(hashInput), (char *) response);
    return response;
}

s32 GstatsStartConnect(s32 theGamePort, s32 theInitTimeout) {
    u8 statsSockAddr[8];
    s8 statsHost[0x84];
    s32 ret;
    gGamePort = theGamePort;
    if (theInitTimeout != 0) {
        gInitTimeout = theInitTimeout;
    }
    if (gGsiAcResult != 1) {
        return 1;
    }
    if (gInternalInit == 0) {
        InternalInit();
    }
    SocketStartUp();
    gSessKey = GetElapsedMilliseconds();
    if (gSock != -1) {
        GstatsClose();
    }
    gRcvLen = 0;
    if (inet_addr((u32) gStatsServerHostname) == -1) {
        strcpy((char *) statsHost, gcd_gamename);
        strcat((char *) statsHost, ".");
        strcat((char *) statsHost, gStatsServerHostname);
    } else {
        strcpy((char *) statsHost, gStatsServerHostname);
    }
    if (ResolveStatsHostAddress(statsHost, 0x74e0, statsSockAddr, NULL) == FALSE) {
        return 2;
    }
    gSock = OpenNetSocket(2, 1, 0);
    if (gSock == -1) {
        return 1;
    }
    SetSockBlocking(gSock, 0);
    ret = connect(gSock, statsSockAddr, 8);
    if (ret == -1) {
        ret = GOAGetLastError(gSock);
        if (ret != -6 && ret != -0x4c && ret != -0x1a) {
            gStatsInitState = 1;
            closesocket(gSock);
            return 3;
        }
    }
    gRcvBuffer = DWCi_GsMalloc(0x40);
    if (gRcvBuffer == NULL) {
        return 3;
    }
    gRcvMax = 0x40;
    gRcvLen = 0;
    gInitStart = GetElapsedMilliseconds();
    gStatsInitState = 2;
    return 6;
}

s32 GstatsUpdateConnect(void) {
    u32 socketFlags[2];
    s32 aResult;
    s32 ret;
    switch (gStatsInitState) {
        case 1:
            return 3;
        case 2:
            socketFlags[0] = 0;
            socketFlags[1] = 0;
            aResult = GSISocketSelect(gSock, NULL, &socketFlags[0], &socketFlags[1]);
            if (aResult == -1 || (aResult == 1 && socketFlags[1] == 1)) {
                gStatsInitState = 1;
                GstatsClose();
                return 3;
            }
            if (aResult == 0) {
                if (GetElapsedMilliseconds() - gInitStart > gInitTimeout) {
                    gStatsInitState = 1;
                    GstatsClose();
                    return 7;
                }
                return 6;
            }
            if (aResult != 1 || socketFlags[0] != 1) {
                AssertionFailed("aResult == 1 && aWriteFlag == 1", "gstats.c", NULL, 0x145);
            }
            gStatsInitState = 3;
        case 3:
            if (CanReceiveOnSocket(gSock) == 0) {
                if (GetElapsedMilliseconds() - gInitStart > gInitTimeout) {
                    gStatsInitState = 1;
                    GstatsClose();
                    return 7;
                }
                return 6;
            }
            aResult = recv(gSock, gRcvBuffer + gRcvLen, gRcvMax - gRcvLen, 0);
            if (aResult == -1) {
                gStatsInitState = 1;
                GstatsClose();
                return 3;
            }
            gRcvLen += aResult;
            gRcvMax -= aResult;
            if (gRcvLen < 0x26) {
                return 6;
            }
            gRcvBuffer[gRcvLen] = 0;
            gStatsInitState = 4;
            gEnc = gEnc1;
            xcode_buf(gRcvBuffer, gRcvLen);
            ret = SendChallengeResponse(gRcvBuffer, gGamePort);
            if (ret != 0) {
                gStatsInitState = 1;
                GstatsClose();
                return ret;
            }
            gStatsInitState = 4;
            gRcvMax += gRcvLen;
            gRcvLen = 0;
            memset(gRcvBuffer, 0, gRcvMax);
        case 4:
            if (CanReceiveOnSocket(gSock) == 0) {
                if (GetElapsedMilliseconds() - gInitStart > gInitTimeout) {
                    gStatsInitState = 1;
                    GstatsClose();
                    return 7;
                }
                return 6;
            }
            ret = RecvSessionKey();
            if (ret != 0) {
                gStatsInitState = 1;
                GstatsClose();
                return ret;
            }
            gRcvMax += gRcvLen;
            gRcvLen = 0;
            memset(gRcvBuffer, 0, gRcvMax);
            gStatsInitState = 5;
        case 5:
            return 0;
        default:
            return 3;
    }
}

s32 GstatsConnect(s32 gameport) {
    s32 aResult = GstatsStartConnect(gameport, 0);
    if (aResult == 6) {
        do {
            aResult = GstatsUpdateConnect();
            msleep(5);
        } while (aResult == 6);
    }
    return aResult;
}

void GstatsClose(void) {
    if (gSock != -1) {
        shutdown(gSock, 2);
        closesocket(gSock);
    }
    gSock = -1;
    ClosePendingCallbacks();
    if (gRcvBuffer != NULL) {
        DWCi_GsFree(gRcvBuffer);
        gRcvBuffer = NULL;
        gRcvMax = 0;
        gRcvLen = 0;
    }
}

s8 *GetChallenge(s8 *game) {
    static s8 challengeBytes[9] = {0};
    if (game == NULL) {
        game = gStatsGame;
    }
    if (game == NULL) {
        create_challenge(gConnId ^ 0x38f371e6, challengeBytes);
        return challengeBytes;
    }
    return game + 0x10;
}

static char gUnusedOrderPad31[31] = {1};
static char gUnusedOrderPad34[34] = {1};
static char gUnusedOrderPad41[41] = {1};
static char gUnusedOrderPad56[56] = {1};

void PreAuthenticatePlayerPartner(s32 ownId, s32 tokenText, s32 responseText, UnkFunc *callback, s32 instance) {
    char replyFormat[] = "\xC\x13\x1A\x1E\xD\x13\x28\x1D\x11\x1D\x11\x10\x24\x1D\x04\x0F\x0B\x3F\x51\x32\x2C\x1A\x00"
                         "\x0B\x20\x2E\x4A\x19\x39\x0F\x1D\x25\x2C\x4D\x01";
    s8 data[0x100];
    s32 len;
    gEnc = gEnc3;
    xcode_buf((s8 *) replyFormat, sizeof(replyFormat) - 1);
    len = sprintf((char *) data, replyFormat, tokenText, responseText, ownId);
    SendPlayerAuthRequest(data, len, ownId, callback, instance);
}

static char gUnusedOrderPad30[30] = {1};
static char gUnusedOrderPad42[42] = {1};
static char gUnusedOrderPad35[35] = {1};
static char gUnusedOrderPad49[49] = {1};
static char gUnusedOrderPad8[8] = {1};

void SetPersistDataValuesA(u32 ownId, u32 profileId, u32 type, u32 index, u32 valueString, u32 callback, u32 instance) {
    SetPersistDataHelper(ownId, profileId, type, index, (const u8 *) valueString,
                         strlen((const char *) valueString) + 1, (UnkFunc *) callback, instance, 1);
}

BOOL PersistThink(void) {
    s32 len;
    s32 usedLen;
    if (gSock == -1) {
        return FALSE;
    }
    if (gStatsInitState != 5) {
        return FALSE;
    }
    if (SocketReadable(gSock) != 0) {
        do {
            if (gRcvMax - gRcvLen < 0x80) {
                if (gRcvMax < 0x100) {
                    gRcvMax = 0x100;
                } else {
                    gRcvMax = gRcvMax * 2;
                }
                gRcvBuffer = DWCi_GsRealloc(gRcvBuffer, gRcvMax + 1);
                if (gRcvBuffer == NULL) {
                    return FALSE;
                }
            }
            len = recv(gSock, gRcvBuffer + gRcvLen, gRcvMax - gRcvLen, 0);
            if (len <= 0) {
                GstatsClose();
                return FALSE;
            }
            gRcvLen += len;
            gRcvBuffer[gRcvLen] = 0;
            usedLen = ProcessInBuffer((u8 *) gRcvBuffer, gRcvLen);
            if (usedLen == gRcvLen) {
                gRcvLen = 0;
            } else {
                memmove(gRcvBuffer, gRcvBuffer + usedLen, gRcvLen - usedLen);
                gRcvLen -= usedLen;
            }
        } while (SocketReadable(gSock) != 0);
    }
    return gSock != -1;
}

void InternalInit(void) {
    gInternalInit = 1;
    gEnc1[0] = 'G';
    gEnc2[0] = 'I';
    gEnc3[0] = 'P';
    gStatsFile[0] = 'g';
    gFinalStr[0] = '\\';
}

s32 SendChallengeResponse(const s8 *indata, u32 gameport) {
    char md5Text[0x21];
    char replyFormat[] = "\xC\x13\x1A\x1E\xD\x3F\x28\x26\x11\x5\x0\x16\x31\x1F\xA\x36\x40\x10\x28\x33\x15\x1B\x15\x17"
                         "\x3E\x1\xA\x36\x40\x10\x28\x31\x1F\x1A\x11\x24\x75\x16\x33\x3\x1\x3F\x45";
    const s8 *challengeText;
    s32 len;
    s8 replyBuf[0x80];
    gChallengeStr[0] = 'c';
    challengeText = value_for_key(indata, gChallengeStr);
    if (challengeText == NULL) {
        closesocket(gSock);
        return 5;
    }
    len = g_crc32(challengeText, strlen((const char *) challengeText));
    len = sprintf((char *) replyBuf, "%d%s", len, gcd_secret_key);
    MD5Digest((const char *) replyBuf, len, md5Text);
    gEnc = gEnc3;
    xcode_buf((s8 *) replyFormat, sizeof(replyFormat) - 1);
    len = sprintf((char *) replyBuf, replyFormat, gcd_gamename, md5Text, gameport);
    if (DoSend(replyBuf, len) <= 0) {
        closesocket(gSock);
        return 3;
    }
    return 0;
}

s32 RecvSessionKey(void) {
    s8 replyBuf[0x80];
    s32 len = recv(gSock, replyBuf, 0x80, 0);
    const s8 *sessionText;
    s32 sockErrCode;
    if (len == -1) {
        sockErrCode = GOAGetLastError(gSock);
        if (sockErrCode != -6 && sockErrCode != -0x4c && sockErrCode != -0x1a) {
            closesocket(gSock);
            return 3;
        }
    }
    replyBuf[len] = 0;
    gEnc = gEnc1;
    xcode_buf(replyBuf, len);
    gSessKeyStr[0] = 's';
    sessionText = value_for_key(replyBuf, gSessKeyStr);
    if (sessionText == NULL) {
        closesocket(gSock);
        return 5;
    }
    gConnId = StrtolBase10((const char *) sessionText);
    return 0;
}

s32 DoSend(s8 *data, s32 len) {
    s32 sentTotal = 0;
    s32 ret;
    gEnc = gEnc1;
    xcode_buf(data, len);
    strcpy((char *) (data + len), gFinalStr);
    if (len + 7 > 0) {
        do {
            ret = send(gSock, data + sentTotal, len + 7 - sentTotal, 0);
            if (ret == -1) {
                ret = GOAGetLastError(gSock);
                if (ret != -6 && ret != -0x4c && ret != -0x1a) {
                    return ret;
                }
            } else if (ret == 0) {
                return -1;
            } else {
                sentTotal += ret;
            }
        } while (sentTotal < len + 7);
    }
    return sentTotal;
}

void xcode_buf(s8 *buf, s32 len) {
    s32 index;
    s8 *pos = (s8 *) gEnc;
    index = 0;
    if (len > 0) {
        do {
            buf[index] ^= *pos++;
            if (*pos == 0) {
                pos = (s8 *) gEnc;
            }
            index++;
        } while (index < len);
    }
}

int g_crc32(const s8 *text, int len) {
    int index;
    int hashValue;
    hashValue = 0;
    index = 0;
    if (0 < len) {
        do {
            hashValue = (0x9ccf9319u) * hashValue + text[index];
            index = index + 1;
        } while (index < len);
    }
    return hashValue;
}

void create_challenge(u32 challenge, s8 *chstr) {
    s8 *pos = chstr;
    sprintf((char *) chstr, "%08x", challenge);
    while (*pos != 0) {
        *pos = *pos + 0x11 + (pos - chstr);
        pos++;
    }
}

const s8 *value_for_key(const s8 *text, const char *key) {
    char searchPattern[256] = "\\";
    static s8 gValueForKeyValues[2][256] = {0};
    const s8 *pos;
    s8 *valuePos;
    s8 *valueSlot;
    gValueIndex ^= 1;
    strcat(searchPattern, key);
    strcat(searchPattern, "\\");
    pos = (const s8 *) strstr((const char *) text, searchPattern);
    if (pos == NULL) {
        return NULL;
    }
    pos += strlen(searchPattern);
    valueSlot = gValueForKeyValues[gValueIndex];
    valuePos = valueSlot;
    while (*pos != 0 && *pos != '\\') {
        *valuePos++ = *pos++;
    }
    *valuePos = 0;
    return valueSlot;
}

const s8 *value_for_key_safe(const s8 *text, const char *key) {
    const s8 *result = value_for_key(text, key);
    if (result == NULL) {
        result = (const s8 *) "";
    }
    return result;
}

BOOL ResolveStatsHostAddress(const s8 *host, u32 port, u8 *saddr, SOCHostEnt **savehent) {
    SOCHostEnt *hent = NULL;
    u16 shortPort = port;
    saddr[0] = 0;
    saddr[1] = 0;
    saddr[2] = 0;
    saddr[3] = 0;
    saddr[4] = 0;
    saddr[5] = 0;
    saddr[6] = 0;
    saddr[7] = 0;
    saddr[1] = 2;
    *OFFSET_PTR(u16, saddr, 2) = ((shortPort >> 8) & 0xff) | ((shortPort << 8) & 0xff00);
    if (host == NULL) {
        *OFFSET_PTR(u32, saddr, 4) = 0;
    } else {
        *OFFSET_PTR(u32, saddr, 4) = inet_addr((u32) host);
    }
    if (*OFFSET_PTR(u32, saddr, 4) == -1) {
        hent = SOC_GetHostByName((const char *) host);
        if (hent == NULL) {
            return FALSE;
        }
        *OFFSET_PTR(u32, saddr, 4) = **hent->mAddrList;
    }
    if (savehent != NULL) {
        *savehent = hent;
    }
    return TRUE;
}

void AddRequestCallback(s32 reqType, s32 ownId, s32 profileId, s32 dataKind, s32 dataIndex, UnkFunc *callback,
                        s32 instance) {
    ServerReq req;
    req.mCallback.mAuthCallback = callback;
    req.mInstance = instance;
    req.mLocalId = ownId;
    req.mReqType = reqType;
    req.mProfileId = profileId;
    req.mPdType = dataKind;
    req.mPdIndex = dataIndex;
    if (gServerReqs == NULL) {
        gServerReqs = DarrayCreate(0x1c, 2, NULL);
    }
    DarrayAppend(gServerReqs, &req);
}

void SendPlayerAuthRequest(s8 *data, s32 len, s32 ownId, UnkFunc *callback, s32 instance) {
    s32 sentBytes = 0;
    char errorBytes[] = "\x13\x1D\x1\x4\x0\x0\x0\x28\x1F\x6\x45\x34\x3F\x1\x1B";
    if (gSock != -1) {
        sentBytes = DoSend(data, len);
    }
    if (sentBytes <= 0) {
        GstatsClose();
        gEnc = gEnc3;
        xcode_buf((s8 *) errorBytes, sizeof(errorBytes) - 1);
        if (callback != NULL) {
            callback(ownId, 0, 0, errorBytes, instance);
        }
    } else {
        AddRequestCallback(0, ownId, 0, 0, 0, callback, instance);
    }
}

void SetPersistDataHelper(s32 ownId, s32 profileId, s32 type, s32 index, const u8 *data, s32 len, UnkFunc *callback,
                          s32 instance, s32 kvset) {
    char replyFormat[] = "\xC\x1\xA\x1E\x15\x7\x28\x1D\x0\x1\x1\x24\x75\x16\x33\x1A\x11\x1A\x4\x24\x2C\x4D\x1\x24\x34"
                         "\x1B\x1\xE\x0\x1B\x28\x64\x14\x34\xE\xE\xC\x57\xB\x36\x9\xA\x10\x1D\x55\xC\x39\x14\x35\x1C\x8"
                         "\x1E\xD\x3F\x51\x25\x2C\xC\x4\xC\x31\x2E";
    s8 packetBuf[0x200];
    s32 headLen;
    s8 *packetData;
    s32 totalLength;
    gEnc = gEnc3;
    xcode_buf((s8 *) replyFormat, sizeof(replyFormat) - 1);
    if (type == 0 || type == 2) {
        if (callback != NULL) {
            callback(ownId, profileId, type, index, 0, 0, instance);
        }
        return;
    }
    headLen = sprintf((char *) packetBuf, replyFormat, profileId, type, index, kvset, ownId, len);
    totalLength = headLen + len;
    if (totalLength < 0x1e0) {
        memcpy(packetBuf + headLen, data, len);
        packetData = packetBuf;
    } else {
        packetData = DWCi_GsMalloc(totalLength + 0x100);
        memcpy(packetData, packetBuf, headLen);
        memcpy(packetData + headLen, data, len);
    }
    if (gSock != -1) {
        headLen = DoSend(packetData, totalLength);
    }
    if (headLen <= 0) {
        GstatsClose();
        if (callback != NULL) {
            callback(ownId, profileId, type, index, 0, 0, instance);
        }
    } else {
        AddRequestCallback(2, ownId, profileId, type, index, callback, instance);
    }
    if (packetData != packetBuf) {
        DWCi_GsFree(packetData);
    }
}

u32 SocketReadable(u32 socket) {
    u32 value0 = socket;
    u32 value3;
    value3 = (u32) &CanReceiveOnSocket;
    value0 = CanReceiveOnSocket(value0);
    return value0;
}

const s8 *FindFinal(const s8 *buff, s32 len) {
    const s8 *pos = buff;
    s32 limit = len - 6;
    if (limit > 0) {
        do {
            if (pos[0] == '\\' && pos[1] == 'f' && pos[2] == 'i' && pos[3] == 'n' && pos[4] == 'a' && pos[5] == 'l' &&
                pos[6] == '\\') {
                return pos;
            }
            pos++;
        } while (pos - buff < limit);
    }
    return NULL;
}

s32 FindRequest(s32 reqType, s32 ownId, s32 profileId) {
    s32 index;
    ServerReq *req;
    if (gServerReqs == NULL) {
        return -1;
    }
    index = 0;
    if (DarrayGetCount((u32 *) gServerReqs) > 0) {
        do {
            req = DarrayGetElement(gServerReqs, index);
            if (req->mReqType == reqType && req->mLocalId == ownId && req->mProfileId == profileId) {
                return index;
            }
            index++;
        } while (index < DarrayGetCount((u32 *) gServerReqs));
    }
    return -1;
}

void ProcessPlayerAuth(u8 *buf, s32 len) {
    s32 pid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "pauthr"));
    s32 lid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "lid"));
    const s8 *failText = value_for_key_safe((const s8 *) buf, "errmsg");
    s32 requestPos = FindRequest(0, lid, 0);
    if (requestPos != -1) {
        ServerReq *req = DarrayGetElement(gServerReqs, requestPos);
        req->mProfileId = pid;
        CallReqCallback(requestPos, pid > 0 ? 1 : 0, 0, (const u8 *) failText, 0);
    }
}

void ProcessGetPid(u8 *buf, s32 len) {
    s32 pid;
    s32 lid;
    s32 requestPos;
    ServerReq *req;

    pid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "getpidr"));
    lid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "lid"));
    requestPos = FindRequest(3, lid, 0);
    if (requestPos != -1) {
        req = DarrayGetElement(gServerReqs, requestPos);
        req->mProfileId = pid;
        CallReqCallback(requestPos, (pid > 0) ? 1 : 0, 0, NULL, 0);
    }
}

void ProcessGetData(u8 *buf, s32 len) {
    s32 okFlag;
    s32 lid;
    s32 pid;
    s32 revisionStamp;
    s32 requestPos;
    s32 length;
    u8 *marker;
    const u8 *data;

    okFlag = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "getpdr"));
    lid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "lid"));
    pid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "pid"));
    revisionStamp = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "mod"));
    requestPos = FindRequest(1, lid, pid);
    if (requestPos != -1) {
        length = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "length"));
        marker = (u8 *) strstr((const char *) buf, "\\data\\");
        if (marker == NULL) {
            length = 0;
            data = (const u8 *) "";
        } else {
            data = marker + 6;
        }
        CallReqCallback(requestPos, okFlag, revisionStamp, data, length);
    }
}

void ProcessSetData(u8 *buf, s32 len) {
    s32 okFlag;
    s32 pid;
    s32 lid;
    s32 revisionStamp;
    s32 requestPos;

    okFlag = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "setpdr"));
    pid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "pid"));
    lid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "lid"));
    revisionStamp = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, "mod"));
    requestPos = FindRequest(2, lid, pid);
    if (requestPos != -1) {
        CallReqCallback(requestPos, okFlag, revisionStamp, NULL, 0);
    }
}

void ProcessStatement(u8 *buff, s32 len) {
    buff[len] = 0;
    if (strncmp((const char *) buff, "\\pauthr\\", 8) == 0) {
        ProcessPlayerAuth(buff, len);
        return;
    }
    if (strncmp((const char *) buff, "\\getpidr\\", 9) == 0) {
        ProcessGetPid(buff, len);
        return;
    }
    if (strncmp((const char *) buff, "\\getpidr\\", 9) == 0) {
        ProcessGetPid(buff, len);
        return;
    }
    if (strncmp((const char *) buff, "\\getpdr\\", 8) == 0) {
        ProcessGetData(buff, len);
        return;
    }
    if (strncmp((const char *) buff, "\\setpdr\\", 8) == 0) {
        ProcessSetData(buff, len);
    }
}

s32 ProcessInBuffer(u8 *buff, s32 len) {
    u8 *pos;
    s32 oldLen;
    s32 statementLen;

    oldLen = len;
    pos = (u8 *) FindFinal((const s8 *) buff, len);
    while (len > 0 && pos != NULL) {
        gEnc = gEnc1;
        statementLen = pos - buff;
        xcode_buf((s8 *) buff, statementLen);
        ProcessStatement(buff, statementLen);
        len = len - (statementLen + 7);
        buff = pos + 7;
        if (len > 0) {
            pos = (u8 *) FindFinal((const s8 *) buff, len);
        }
    }
    return oldLen - len;
}

void CallReqCallback(s32 requestPos, s32 success, s32 modified, const u8 *data, s32 length) {
    ServerReq *req;

    if (requestPos >= 0 && requestPos < DarrayGetCount(gServerReqs)) {
        req = DarrayGetElement(gServerReqs, requestPos);
        if (req->mCallback.mAuthCallback != NULL) {
            switch (req->mReqType) {
                case SERVER_REQ_TYPE_AUTH:
                    req->mCallback.mAuthCallback(req->mLocalId, req->mProfileId, success, data, req->mInstance);
                    break;
                case SERVER_REQ_TYPE_DATA:
                    req->mCallback.mDataCallback(req->mLocalId, req->mProfileId, req->mPdType, req->mPdIndex, success,
                                                 modified, data, length, req->mInstance);
                    break;
                case SERVER_REQ_TYPE_SAVE:
                    req->mCallback.mSaveCallback(req->mLocalId, req->mProfileId, req->mPdType, req->mPdIndex, success,
                                                 modified, req->mInstance);
                    break;
                case SERVER_REQ_TYPE_PROFILE:
                    req->mCallback.mProfileCallback(req->mLocalId, req->mProfileId, success, req->mInstance);
                    break;
            }
        }
        DarrayRemove(gServerReqs, requestPos);
    }
}

void ClosePendingCallbacks(void) {
    s32 index;

    if (gServerReqs != NULL) {
        for (index = DarrayGetCount(gServerReqs) - 1; index >= 0; index--) {
            char errorBytes[] = "\x13\x1D\x1\x4\x0\x0\x0\x28\x1F\x6\x45\x34\x3F\x1\x1B";
            gEnc = gEnc3;
            xcode_buf((s8 *) errorBytes, sizeof(errorBytes) - 1);
            CallReqCallback(index, 0, 0, (u8 *) errorBytes, 0);
        }
        DarrayDelete(gServerReqs);
        gServerReqs = NULL;
    }
}
