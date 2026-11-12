#include "00/Lib/GameSpy/code_0219742c.h"

#include "00/unk_021b3000.h"
#include "00/unk_021b4000.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_02196960.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "00/Lib/GameSpy/code_0218d488.h"

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
