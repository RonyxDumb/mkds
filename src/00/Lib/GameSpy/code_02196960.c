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

s8 *GenerateAuthA(const char *challenge, const char *password, s8 *response) {
    u32 passwordLen;
    char hashInput[0x80];
    passwordLen = strlen(password);
    if (strlen(challenge) + passwordLen + 0x14 >= 0x80) {
        *(CdKeyTooLongText *) response = gCdKeyTooLongText;
        return response;
    }
    sprintf(hashInput, gGenerateAuthFormat, password, challenge);
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
    if (*(u32 *) &gInternalInit == 0) {
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
        strcat((char *) statsHost, gHostnameDot);
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
                AssertionFailed(gInitStatsThinkAssert, gGstatsFileName, NULL, 0x145);
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
    if (game == NULL) {
        game = gStatsGame;
    }
    if (game == NULL) {
        create_challenge(gConnId ^ 0x38f371e6, gChallenge);
        return gChallenge;
    }
    return game + 0x10;
}

void PreAuthenticatePlayerPartner(s32 localId, s32 profileId, s32 challengeResponse, UnkFunc *callback, s32 instance) {
    PreAuthPMRespformatText replyFormat = gPreAuthPMRespformat;
    s8 data[0x100];
    s32 len;
    gEnc = gEnc3;
    xcode_buf(replyFormat.mText, 0x23);
    len = sprintf((char *) data, (const char *) replyFormat.mText, profileId, challengeResponse, localId);
    SendPlayerAuthRequest(data, len, localId, callback, instance);
}

void SetPersistDataValuesA(u32 ownId, u32 profileId, u32 type, u32 index, u32 valueString, u32 callback, u32 instance) {
    SetPersistDataHelper(ownId, profileId, type, index, (const u8 *) valueString, strlen((const char *) valueString) + 1,
                         (UnkFunc *) callback, instance, 1);
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
    *(u32 *) &gInternalInit = 1;
    gEnc1[0] = 0x47;
    gEnc2[0] = 0x49;
    gEnc3[0] = 0x50;
    gStatsFile[0] = 0x67;
    gFinalStr[0] = 0x5c;
}

s32 SendChallengeResponse(const s8 *indata, u32 gameport) {
    char md5Text[0x21];
    ChallengeRespformatText replyFormat = gChallengeRespformat;
    const s8 *challengeText;
    s32 len;
    s8 replyBuf[0x80];
    gChallengeStr[0] = 0x63;
    challengeText = value_for_key(indata, gChallengeStr);
    if (challengeText == NULL) {
        closesocket(gSock);
        return 5;
    }
    len = g_crc32(challengeText, strlen((const char *) challengeText));
    len = sprintf((char *) replyBuf, gChallengeHashFormat, len, gcd_secret_key);
    MD5Digest((const char *) replyBuf, len, md5Text);
    gEnc = gEnc3;
    xcode_buf(replyFormat.mText, 0x2b);
    len = sprintf((char *) replyBuf, (const char *) replyFormat.mText, gcd_gamename, md5Text, gameport);
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
    gSessKeyStr[0] = 0x73;
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
    sprintf((char *) chstr, gCreateChallengeFormat, challenge);
    while (*pos != 0) {
        *pos = *pos + 0x11 + (pos - chstr);
        pos++;
    }
}

const s8 *value_for_key(const s8 *text, const char *key) {
    KeyspecText searchPattern = gValueForKeyKeyspec;
    const s8 *pos;
    s8 *valuePos;
    s8 *valueSlot;
    gValueIndex ^= 1;
    strcat((char *) searchPattern.mText, key);
    strcat((char *) searchPattern.mText, gKeyspecDelimiter);
    pos = (const s8 *) strstr((const char *) text, (const char *) searchPattern.mText);
    if (pos == NULL) {
        return NULL;
    }
    pos += strlen((const char *) searchPattern.mText);
    valueSlot = gValueForKeyValues + (gValueIndex << 8);
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
        result = gEmptyValue;
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
    ConnErrorText errorBytes = gConnErrorSendAuth;
    if (gSock != -1) {
        sentBytes = DoSend(data, len);
    }
    if (sentBytes <= 0) {
        GstatsClose();
        gEnc = gEnc3;
        xcode_buf(errorBytes.mText, 0xf);
        if (callback != NULL) {
            callback(ownId, 0, 0, errorBytes.mText, instance);
        }
    } else {
        AddRequestCallback(0, ownId, 0, 0, 0, callback, instance);
    }
}

void SetPersistDataHelper(s32 ownId, s32 profileId, s32 type, s32 index, const u8 *data, s32 len, UnkFunc *callback,
                          s32 instance, s32 kvset) {
    SetPersistRespformatText replyFormat = gSetPersistRespformat;
    s8 packetBuf[0x200];
    s32 headLen;
    s8 *packetData;
    s32 totalLength;
    gEnc = gEnc3;
    xcode_buf(replyFormat.mText, 0x3e);
    if (type == 0 || type == 2) {
        if (callback != NULL) {
            callback(ownId, profileId, type, index, 0, 0, instance);
        }
        return;
    }
    headLen = sprintf((char *) packetBuf, (const char *) replyFormat.mText, profileId, type, index, kvset, ownId, len);
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
    s32 pid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gPauthrKey));
    s32 lid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gLidKey));
    const s8 *failText = value_for_key_safe((const s8 *) buf, gErrmsgKey);
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

    pid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gGetpidrKey));
    lid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gLidKey));
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

    okFlag = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gGetpdrKey));
    lid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gLidKey));
    pid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gStatsPidKey));
    revisionStamp = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gModKey));
    requestPos = FindRequest(1, lid, pid);
    if (requestPos != -1) {
        length = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gLengthKey));
        marker = (u8 *) strstr((const char *) buf, gDataMarker);
        if (marker == NULL) {
            length = 0;
            data = (const u8 *) gEmptyValue;
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

    okFlag = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gSetpdrKey));
    pid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gStatsPidKey));
    lid = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gLidKey));
    revisionStamp = StrtolBase10((const char *) value_for_key_safe((const s8 *) buf, gModKey));
    requestPos = FindRequest(2, lid, pid);
    if (requestPos != -1) {
        CallReqCallback(requestPos, okFlag, revisionStamp, NULL, 0);
    }
}

void ProcessStatement(u8 *buff, s32 len) {
    buff[len] = 0;
    if (strncmp((const char *) buff, gPauthrStatement, 8) == 0) {
        ProcessPlayerAuth(buff, len);
        return;
    }
    if (strncmp((const char *) buff, gGetpidrStatement, 9) == 0) {
        ProcessGetPid(buff, len);
        return;
    }
    if (strncmp((const char *) buff, gGetpidrStatement, 9) == 0) {
        ProcessGetPid(buff, len);
        return;
    }
    if (strncmp((const char *) buff, gGetpdrStatement, 8) == 0) {
        ProcessGetData(buff, len);
        return;
    }
    if (strncmp((const char *) buff, gSetpdrStatement, 8) == 0) {
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
                case 0:
                    req->mCallback.mAuthCallback(req->mLocalId, req->mProfileId, success, data, req->mInstance);
                    break;
                case 1:
                    req->mCallback.mDataCallback(req->mLocalId, req->mProfileId, req->mPdType, req->mPdIndex, success,
                                                 modified, data, length, req->mInstance);
                    break;
                case 2:
                    req->mCallback.mSaveCallback(req->mLocalId, req->mProfileId, req->mPdType, req->mPdIndex, success,
                                                 modified, req->mInstance);
                    break;
                case 3:
                    req->mCallback.mProfileCallback(req->mLocalId, req->mProfileId, success, req->mInstance);
                    break;
            }
        }
        DarrayRemove(gServerReqs, requestPos);
    }
}

void ClosePendingCallbacks(void) {
    s32 index;
    ConnErrorBytes errorBytes;

    if (gServerReqs != NULL) {
        for (index = DarrayGetCount(gServerReqs) - 1; index >= 0; index--) {
            errorBytes = gConnErrorClosePending;
            gEnc = gEnc3;
            xcode_buf((s8 *) errorBytes.mText, 0xf);
            CallReqCallback(index, 0, 0, errorBytes.mText, 0);
        }
        DarrayDelete(gServerReqs);
        gServerReqs = NULL;
    }
}
