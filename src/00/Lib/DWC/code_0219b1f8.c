#include "00/Lib/DWC/code_0219b1f8.h"
#include "00/code_0219b000.h"
#include "00/code_0219c954.h"
#include "00/unk_021b5000.h"
#include "00/code_021a10b0.h"
#include "00/code_021a17bc.h"
#include "00/code_0219c000.h"
#include "00/code_021a01dc.h"
#include "00/Lib/GameSpy/code_0219a654.h"
#include "00/Lib/GameSpy/gt2Utility.h"
#include "00/Lib/DWC/code_02188720.h"
#include "00/Lib/GameSpy/code_02198a8c.h"
#include "00/Lib/GameSpy/code_0219887c.h"
#include "00/code_0219a000.h"
#include "00/Lib/DWC/code_021a3264.h"
#include "00/Lib/GameSpy/gt2Main.h"
#include "00/code_021a1ae0.h"
#include "code_0214d018.h"
#include "00/Lib/GameSpy/code_0218d488.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/code_0219c93c.h"
#include "00/Lib/DWC/dwc_connectinet.h"
#include "00/Lib/DWC/code_0219cc00.h"
#include "code_02139f70.h"
#include "00/Lib/DWC/code_0219d128.h"
#include "00/code_0218d000.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "00/code_0219d000.h"
#include "00/unk_021b4000.h"
#include "code_0200fc8c.h"
#include "00/unk_021b1000.h"
#include "dwc_backup.h"
#include "code_021519d4.h"
#include "00/Lib/DWC/code_02186a9c.h"
#include "00/Lib/CPS/network.h"
#include "00/Lib/NitroWiFi/util.h"
#include "00/Lib/DWC/code_0218a67c.h"
#include "00/Lib/NitroWiFi/cpsif.h"
#include "00/Lib/DWC/code_02185954.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/DWC/code_021a2ccc.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/sb_serverlist.h"
#include "00/Lib/DWC/code_0219caac.h"
#include "00/Lib/GameSpy/code_02196960.h"
#include "00/Lib/DWC/dwc_match.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "os_printf.h"
#include "code_0213a460.h"

WiFiConnection *gWiFiConnection = NULL;
s32 stLastSocketError = 0;
DWCConnectionInfo stConnectionInfoList[32];
void *stGt2ConnectionList[32];

// Sets up the object at each login (the caller zeroes the 0xdb4 bytes first, code_0211f6cc.c): stores
// gWiFiConnection, builds the login, buddy, matching and net-layer objects and copies the game name and key. Undone
// by DWC_ShutdownFriendsMatch.
void DWC_InitFriendsMatch(void *connectionObject, void *userData, s32 titleNumber, const char *gameName,
                          const char *secretKey, s32 sendBufferSize, s32 receiveBufferSize, void *friendList,
                          s32 friendListLength) {
    u32 gameNameLength;
    u32 secretKeyLength;
    gWiFiConnection = connectionObject;
    DWC_ClearError();
    gWiFiConnection->mSocket = NULL;
    gWiFiConnection->mResultCallback = DWCi_GT2ConnectedCallback;
    gWiFiConnection->mDataCallback = DWCi_GT2ReceivedCallback;
    gWiFiConnection->mClosedCallback = (s32(*)()) DWCi_GT2ClosedCallback;
    gWiFiConnection->mElapsedTimeCallback = DWCi_GT2PingCallback;
    gWiFiConnection->mSendBufferSize = sendBufferSize == 0 ? 0x2000 : sendBufferSize;
    gWiFiConnection->mReceiveBufferSize = receiveBufferSize == 0 ? 0x2000 : receiveBufferSize;
    gWiFiConnection->mGpConnection.mGpiConnection = NULL;
    gWiFiConnection->mUnk_20 = userData;
    gWiFiConnection->mState = 0;
    gWiFiConnection->mPrevState = 0;
    gWiFiConnection->mOwnIndex = 0;
    gWiFiConnection->mOwnCloseFlag = 0;
    gWiFiConnection->mUnk_2e = 0;
    gWiFiConnection->mProfileId = 0;
    gWiFiConnection->mGameName = gcd_gamename;
    gWiFiConnection->mUnk_58 = gcd_secret_key;
    gWiFiConnection->mLoginCallback = NULL;
    gWiFiConnection->mLoginCallbackArg = 0;
    gWiFiConnection->mBuddySyncCallback = NULL;
    gWiFiConnection->mBuddySyncCallbackArg = NULL;
    gWiFiConnection->mMatchingCallback = NULL;
    gWiFiConnection->mMatchingCallbackArg = NULL;
    gWiFiConnection->mMatchedSCCallback = NULL;
    gWiFiConnection->mMatchedSCCallbackArg = NULL;
    gWiFiConnection->mConnectionClosedCallback = NULL;
    gWiFiConnection->mConnectionClosedCallbackArg = NULL;
    DWCi_ClearGT2ConnectionList();
    InitWiFiLogin(&gWiFiConnection->mLogin, userData, &gWiFiConnection->mGpConnection, titleNumber,
                  ((DWCAccUserData *) userData)->mGamecode, DWCi_LoginCallback, NULL);
    DWCi_FriendInit(&gWiFiConnection->mBuddySync, &gWiFiConnection->mGpConnection, gWiFiConnection->mPlayerName,
                    friendList, friendListLength);
    DWCi_MatchInit(&gWiFiConnection->mMatching, &gWiFiConnection->mGpConnection, &gWiFiConnection->mSocket,
                   &gWiFiConnection->mResultCallback, gcd_gamename, gcd_secret_key, friendList, friendListLength);
    DWCi_InitTransport(&gWiFiConnection->mMessageLayer);
    if (strlen(gameName) < 0x100) {
        gameNameLength = strlen(gameName);
    } else {
        gameNameLength = 0xff;
    }
    MI_CpuCopy8(gameName, gcd_gamename, gameNameLength);
    gcd_gamename[gameNameLength] = 0;
    if (strlen(secretKey) < 0x100) {
        secretKeyLength = strlen(secretKey);
    } else {
        secretKeyLength = 0xff;
    }
    MI_CpuCopy8(secretKey, gcd_secret_key, secretKeyLength);
    gcd_secret_key[secretKeyLength] = 0;
}

// Undo of DWC_InitFriendsMatch: frees the matching list, closes stats and GP, closes the socket and clears
// gWiFiConnection. Called on failure, leave and logout paths.
void DWC_ShutdownFriendsMatch(void) {
    if (gWiFiConnection != NULL) {
        if (gWiFiConnection->mMatching.mQr2 != NULL) {
            qr2_shutdown(gWiFiConnection->mMatching.mQr2);
            gWiFiConnection->mMatching.mQr2 = NULL;
        }
        gWiFiConnection->mMatching.mQr2ShutdownPending = 0;
        if (gWiFiConnection->mMatching.mServerList != NULL) {
            ServerBrowserFree(gWiFiConnection->mMatching.mServerList);
            gWiFiConnection->mMatching.mServerList = NULL;
        }
        NNFreeNegotiateList();
        GstatsClose();
        if (gWiFiConnection->mGpConnection.mGpiConnection != NULL) {
            GpSetCallback(&gWiFiConnection->mGpConnection, 0, NULL, 0);
            GpSetCallback(&gWiFiConnection->mGpConnection, 3, NULL, 0);
            GpSetCallback(&gWiFiConnection->mGpConnection, 1, NULL, 0);
            GpSetCallback(&gWiFiConnection->mGpConnection, 2, NULL, 0);
            GpUpdate(&gWiFiConnection->mGpConnection);
            GpDestroy(&gWiFiConnection->mGpConnection);
            gWiFiConnection->mGpConnection.mGpiConnection = NULL;
        }
        DWCi_ShutdownLogin();
        DWCi_ShutdownFriend();
        DWCi_ShutdownMatch();
        DWCi_ShutdownTransport();
        if (gWiFiConnection->mSocket != NULL) {
            gt2CloseSocket(gWiFiConnection->mSocket);
            gWiFiConnection->mSocket = NULL;
        }
        gWiFiConnection = NULL;
    }
}

u32 UpdateInetConnection(void) {
    int checkResult;
    DWC_ProcessInet();
    checkResult = DWCi_CheckDisconnected();
    if (checkResult != 0) {
        DWCi_SetError(9, 0);
        DWC_CleanupInet();
        return 1;
    }
    return 0;
}

void DWCs_ForceShutdown(void) {}

void DWC_ProcessFriendsMatch(void) {
    if (UpdateInetConnection() != 0) {
        DWCs_ForceShutdown();
    }
    if (gWiFiConnection == NULL) {
        return;
    }
    if (gWiFiConnection->mState == 0) {
        return;
    }
    if (DWCi_IsError() != 0) {
        return;
    }
    switch (gWiFiConnection->mState) {
        case 1:
            switch (GSIAvailableCheckThink()) {
                case 1:
                    if (ReportWiFiGpResult(GpInitialize(&gWiFiConnection->mGpConnection,
                                                        gWiFiConnection->mLogin.mProductId, 0)) != 0) {
                        return;
                    }
                    if (ReportWiFiGpResult(GpSetCallback(&gWiFiConnection->mGpConnection, 0,
                                                         (void (*)(void *, void *, u32)) DWCi_GPErrorCallback, 0)) !=
                        0) {
                        return;
                    }
                    if (ReportWiFiGpResult(
                            GpSetCallback(&gWiFiConnection->mGpConnection, 3,
                                          (void (*)(void *, void *, u32)) DWCi_GPRecvBuddyMessageCallback, 0)) != 0) {
                        return;
                    }
                    if (ReportWiFiGpResult(
                            GpSetCallback(&gWiFiConnection->mGpConnection, 1,
                                          (void (*)(void *, void *, u32)) DWCi_GPRecvBuddyRequestCallback, 0)) != 0) {
                        return;
                    }
                    if (ReportWiFiGpResult(GpSetCallback(&gWiFiConnection->mGpConnection, 2,
                                                         (void (*)(void *, void *, u32)) DWCi_GPRecvBuddyStatusCallback,
                                                         0)) != 0) {
                        return;
                    }
                    DWCi_SetState(2);
                    DWCi_LoginAsync();
                    break;
                case 2:
                    DWCi_StopLogin(3, -20110);
                    return;
                case 3:
                    DWCi_StopLogin(4, -20101);
                    return;
            }
            break;
        case 2:
            DWCi_LoginProcess();
            break;
        case 3:
        case 4:
            DWCi_FriendProcess();
            DWCi_MatchProcess(0);
            break;
        case 5:
            DWCi_MatchProcess(1);
            DWCi_FriendProcess();
            break;
        case 6:
            DWCi_TransportProcess();
            DWCi_FriendProcess();
            if (gWiFiConnection->mMatching.mMode == 2 || gWiFiConnection->mMatching.mMode == 3) {
                DWCi_MatchProcess(1);
            } else if (gWiFiConnection->mSocket != NULL) {
                DWCi_MatchProcess(0);
            }
            break;
    }
    if (gWiFiConnection->mMatching.mQr2ShutdownPending == 1) {
        if (gWiFiConnection->mMatching.mQr2 != NULL) {
            qr2_shutdown(gWiFiConnection->mMatching.mQr2);
            gWiFiConnection->mMatching.mQr2 = NULL;
        }
        gWiFiConnection->mMatching.mQr2ShutdownPending = 0;
    }
}

// Also stores a and b into the login object (mLogin.mUnk_10 / mUnk_14).
void DWC_LoginAsync(u32 playerName, u32 reserved, void (*callback)(s32 playerName), u32 callbackArg) {
    if (DWCi_IsError() == 0) {
        if (gWiFiConnection->mState == 0) {
            gWiFiConnection->mLoginCallback = callback;
            gWiFiConnection->mLoginCallbackArg = callbackArg;
            gWiFiConnection->mLogin.mUnk_10 = playerName;
            gWiFiConnection->mLogin.mUnk_14 = reserved;
            if (DWC_GetInetStatus() != 4) {
                DWCi_StopLogin(2, -60010);
                return;
            }
            DWCi_SetState(1);
            GSIStartAvailableCheckA(gWiFiConnection->mGameName);
        }
    }
}

// The connection-level start (state check, state 4, callbacks); calls StartBuddySync (the two names differ only by
// WiFi). Refused (FALSE) in states 0 to 2 and 4.
BOOL DWC_UpdateServersAsync(const s8 *playerName, void (*updateCallback)(s32, s32), void *updateParam,
                            void (*statusCallback)(u32, u8), void *statusParam, void (*deleteCallback)(u32, u32),
                            void *deleteParam) {
    WiFiConnection *wiFiConnection;
    u32 playerNameLength;
    if (gWiFiConnection == NULL || DWCi_IsError() != 0 || (wiFiConnection = gWiFiConnection)->mState < 3 ||
        wiFiConnection->mState == 4) {
        return FALSE;
    }
    if (playerName == NULL || *playerName == 0) {
        playerNameLength = 0;
    } else {
        if (strlen((const char *) playerName) < 0x20) {
            playerNameLength = strlen((const char *) playerName);
        } else {
            playerNameLength = 0x1f;
        }
        MI_CpuCopy8(playerName, wiFiConnection->mPlayerName, playerNameLength);
    }
    gWiFiConnection->mPlayerName[playerNameLength] = 0;
    gWiFiConnection->mBuddySyncCallback = updateCallback;
    gWiFiConnection->mBuddySyncCallbackArg = updateParam;
    DWCi_SetState(4);
    StartBuddySync((s32) gWiFiConnection->mLogin.mAuthToken, gWiFiConnection->mLogin.mPartnerChallenge,
                   (void (*)(s32, u8, void *)) DWCi_UpdateServersCallback, NULL,
                   (void (*)(s32, u8, void *, void *)) statusCallback, statusParam,
                   (void (*)(s32, s32, void *)) deleteCallback, deleteParam);
    return TRUE;
}

// Connection-level start: only in state 3 and with no error pending; clears the peer tables, stores the callback pair,
// sets state 5 and calls DWCi_ConnectToAnybodyAsync.
void DWC_ConnectToAnybodyAsync(u32 numEntry, void *addFilter, void *matchedCallback, void *matchedParam,
                               void *evalCallback, u32 evalParam) {
    if (DWCi_IsError() == 0 && gWiFiConnection->mState == 3) {
        DWCi_ClearGT2ConnectionList();
        gWiFiConnection->mMatchingCallback = (void (*)(u32, u32, void *)) matchedCallback;
        gWiFiConnection->mMatchingCallbackArg = matchedParam;
        DWCi_SetState(5);
        DWCi_ConnectToAnybodyAsync((u8) (numEntry - 1), addFilter, (u32) DWCi_MatchedCallback, 0, (u32) evalCallback,
                                   evalParam);
    }
}

// Connection-level start: only in state 3; stores the callback pair, sets state 5 and calls DWCi_ConnectToFriendsAsync
// with the given list, or with a list of all buddy entries in random order when it is NULL (the one caller passes
// NULL).
void DWC_ConnectToFriendsAsync(void *friendIdxList, u32 friendIdxListLength, u32 numEntry, u32 distantFriend,
                               void *matchedCallback, void *matchedParam, u32 evalCallback, u32 evalParam) {
    u8 orderedIdxList[0x40];
    u8 randomKeys[0x40];
    u8 index;
    u8 otherIndex;
    u8 rank;
    if (DWCi_IsError() == 0 && gWiFiConnection->mState == 3) {
        DWCi_ClearGT2ConnectionList();
        gWiFiConnection->mMatchingCallback = (void (*)(u32, u32, void *)) matchedCallback;
        gWiFiConnection->mMatchingCallbackArg = matchedParam;
        DWCi_SetState(5);
        if (friendIdxList != NULL) {
            DWCi_ConnectToFriendsAsync(friendIdxList, friendIdxListLength, (u8) (numEntry - 1), distantFriend,
                                       DWCi_MatchedCallback, 0, evalCallback, evalParam);
            return;
        }
        index = 0;
        friendIdxListLength = 0;
        for (; index < DWCi_GetFriendListLen(); index++) {
            randomKeys[index] = DWCi_GetMathRand32(0x80) + 1;
            friendIdxListLength++;
        }
        index = 0;
        for (; index < DWCi_GetFriendListLen(); index++) {
            if (randomKeys[index] != 0) {
                otherIndex = 0;
                rank = 0;
                for (; otherIndex < DWCi_GetFriendListLen(); otherIndex++) {
                    if (index != otherIndex && randomKeys[index] < randomKeys[otherIndex]) {
                        rank++;
                    }
                }
                orderedIdxList[rank] = index;
            }
        }
        DWCi_ConnectToFriendsAsync(orderedIdxList, friendIdxListLength, (u8) (numEntry - 1), distantFriend,
                                   DWCi_MatchedCallback, 0, evalCallback, evalParam);
    }
}

s32 DWC_CloseAllConnectionsHard(void) {
    WiFiConnection *wiFiConnection;
    if (gWiFiConnection == NULL || DWCi_IsError() != 0 ||
        ((wiFiConnection = gWiFiConnection)->mState != 5 && wiFiConnection->mState != 6)) {
        return -1;
    }
    if (wiFiConnection->mMatching.mLastParticipantPos == 0) {
        DWCi_SetGPStatus(1, "", NULL);
        NNFreeNegotiateList();
        DWCi_SetState(3);
        return 1;
    }
    wiFiConnection->mOwnCloseFlag = 1;
    gt2CloseAllConnectionsHard(gWiFiConnection->mSocket);
    gWiFiConnection->mOwnCloseFlag = 0;
    return 0;
}

s32 DWC_CloseConnectionHard(s32 aid) {
    void *connection;
    if (gWiFiConnection == NULL || DWCi_IsError() != 0 ||
        (gWiFiConnection->mState != 5 && gWiFiConnection->mState != 6)) {
        return -1;
    }
    connection = DWCi_GetGT2Connection(aid);
    if (connection == NULL) {
        return -2;
    }
    gt2CloseConnectionHard(connection);
    return 0;
}

s32 DWC_GetNumConnectionHost(void) {
    if (gWiFiConnection == NULL) {
        return 0;
    }
    if (gWiFiConnection->mMatching.mMode == 2 || gWiFiConnection->mMatching.mMode == 3) {
        return DWCi_GetNumValidConnection() + 1;
    }
    return DWCi_GetNumAllConnection() + 1;
}

u8 DWC_GetMyAID(void) {
    if (gWiFiConnection != NULL) {
        return gWiFiConnection->mOwnIndex;
    }
    return 0;
}

s32 DWC_GetAIDList(u8 **aidList) {
    if (gWiFiConnection == NULL) {
        return 0;
    }
    *aidList = gWiFiConnection->mMatching.mParticipantIndices;
    if (gWiFiConnection->mMatching.mMode == 2 || gWiFiConnection->mMatching.mMode == 3) {
        return DWCi_GetValidAIDList((void **) aidList);
    }
    return DWCi_GetAllAIDList((void **) aidList);
}

BOOL DWC_IsValidAID(u32 aid) {
    if (gWiFiConnection == NULL) {
        return FALSE;
    }
    if ((gWiFiConnection->mMatching.mParticipantMask & (1 << aid)) != 0) {
        return DWCi_IsValidAID(aid);
    }
    return FALSE;
}

// 0 when the object is NULL.
u32 DWC_GetState(void) {
    if (gWiFiConnection != NULL) {
        return gWiFiConnection->mState;
    }
    return 0;
}

s32 DWCi_GT2Startup(void) {
    WiFiConnection *wiFiConnection;
    u32 randomPort;
    s32 result;
    if (gWiFiConnection->mSocket != NULL) {
        return 0;
    }
    randomPort = (u16) (DWCi_GetMathRand32(0x4000) + 0xc000);
    wiFiConnection = gWiFiConnection;
    result = gt2CreateSocket((Gt2Socket **) gWiFiConnection, (const char *) gt2AddressToString(0, randomPort, 0),
                             wiFiConnection->mSendBufferSize, wiFiConnection->mReceiveBufferSize,
                             (u32) DWCi_GT2SocketErrorCallback);
    if (ReportWiFiSocketResult(result) != 0) {
        return result;
    }
    gt2Listen(gWiFiConnection->mSocket, DWCi_GT2ConnectAttemptCallback);
    SetUnmatchedDataCallback(gWiFiConnection->mSocket, (UnkWordFunc *) DWCi_GT2UnrecognizedMessageCallback);
    return result;
}

void *DWCi_GetGT2Connection(u32 aid) {
    s32 index;
    void **slot;
    if (gWiFiConnection == NULL) {
        return NULL;
    }
    index = 0;
    slot = stGt2ConnectionList;
    for (; index < 32; slot++, index++) {
        if (*slot != NULL && aid == gt2GetConnectionData(*slot)[1]) {
            return stGt2ConnectionList[index];
        }
    }
    return NULL;
}

u8 DWCi_GetConnectionAID(Unk0219887c *connection) {
    return gt2GetConnectionData(connection)[1];
}

u32 DWCi_GetConnectionIndex(Unk0219887c *connection) {
    return gt2GetConnectionData(connection)[0];
}

s32 DWCi_GT2GetConnectionListIdx(void) {
    s32 index = 0;
    void **slot = stGt2ConnectionList;
    for (; index < 32; slot++, index++) {
        if (*slot == NULL) {
            return index;
        }
    }
    return -1;
}

void DWCi_ClearGT2ConnectionList(void) {
    func_0214d018_inline(stGt2ConnectionList, 0x80);
    func_0214d018_inline(stConnectionInfoList, 0x100);
}

void **DWCi_GetGT2ConnectionByIdx(s32 index) {
    return &stGt2ConnectionList[index];
}

void **DWCi_GetGT2ConnectionByProfileID(u32 profileId, s32 numHost) {
    u8 index;

    for (index = 0; index < numHost; index++) {
        if (profileId == gWiFiConnection->mMatching.mParticipantProfileIds[index]) {
            break;
        }
    }
    if (index >= numHost) {
        return NULL;
    }
    return DWCi_GetGT2ConnectionByIdx(
        DWCi_GetConnectionIndex(DWCi_GetGT2Connection(gWiFiConnection->mMatching.mParticipantIndices[index])));
}

DWCConnectionInfo *DWCi_GetConnectionInfoByIdx(s32 index) {
    return &stConnectionInfoList[index];
}

BOOL DWCi_IsValidAID(u32 aid) {
    s32 index;

    for (index = 0; index < 0x20; index++) {
        if (stGt2ConnectionList[index] != NULL && aid == gt2GetConnectionData(stGt2ConnectionList[index])[1]) {
            return TRUE;
        }
    }
    return FALSE;
}

// Plain setter; also copies the old state into mPrevState (so a Set to the same value overwrites it).
void DWCi_SetState(s32 value) {
    gWiFiConnection->mPrevState = gWiFiConnection->mState;
    gWiFiConnection->mState = value;
}

u32 DWCi_DeleteAID(u32 aid) {
    void *aidList;
    s32 hostTotal;
    s32 index;

    hostTotal = DWCi_GetAllAIDList(&aidList);
    for (index = 0; index < hostTotal; index++) {
        if (aid == ((u8 *) aidList)[index]) {
            break;
        }
    }
    if (index == hostTotal) {
        return 0;
    }
    return DWCi_DeleteHostByIndex(index, hostTotal);
}

u32 DWCi_GetAIDBitmapFromList(const u8 *values, s32 count) {
    u32 mask = 0;
    s32 i;
    for (i = 0; i < count; i++) {
        mask |= 1 << values[i];
    }
    return mask;
}

// Maps a GP result 1 to 4 to (kind, code) and reports it by connection state; 0 passes through.
int ReportWiFiGpResult(int result) {
    s32 errorKind;
    s32 errorCode;

    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            errorKind = 0xb;
            errorCode = -1;
            break;
        case 2:
            errorKind = 0xb;
            errorCode = -2;
            break;
        case 3:
            errorKind = 6;
            errorCode = -10;
            break;
        case 4:
            errorKind = 6;
            errorCode = -20;
            break;
    }
    switch (gWiFiConnection->mState) {
        case 1:
            errorCode -= 0xee48;
            DWCi_StopLogin(errorKind, errorCode);
            break;
        case 2:
            errorCode -= 0xee48;
            DWCi_StopLogin(errorKind, errorCode);
            break;
        case 5:
            errorCode -= 0x13c68;
            DWCi_StopMatching(errorKind, errorCode);
            break;
        case 4:
            errorCode -= 0x11558;
            break;
        default:
            errorCode -= 0x16378;
            break;
    }
    DWCi_StopFriendProcess(errorKind, errorCode);
    return result;
}

// Maps a gti2CreateSocket result (1 to 7; 2 and 5 mean no error and return 0) to (kind, code) and reports it through
// DWCi_StopLogin; returns the result.
u32 ReportWiFiSocketResult(u32 result) {
    s32 errorKind;
    s32 errorCode;

    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            errorKind = 0xb;
            errorCode = -1;
            break;
        case 2:
        case 5:
            errorKind = 0;
            errorCode = 0;
            result = 0;
            break;
        case 3:
            errorKind = 6;
            errorCode = -10;
            break;
        case 4:
            errorKind = 6;
            errorCode = -30;
            break;
        case 6:
            errorKind = 6;
            errorCode = -70;
            break;
        case 7:
            errorKind = 6;
            errorCode = -80;
            break;
    }
    if (errorKind != 0) {
        DWCi_StopLogin(errorKind, errorCode - 0x105b8);
    }
    return result;
}

// Called by the login object with (0, profile id) on success and (code, 0) on failure; passes the result on to
// mLoginCallback.
void DWCi_LoginCallback(int error, u32 profileId) {
    UnkFunc *callback;
    if (error == 0) {
        gWiFiConnection->mProfileId = profileId;
        DWCi_SetState(3);
        DWCi_InitGPProcessCount();
    } else {
        DWCi_SetState(0);
    }
    callback = gWiFiConnection->mLoginCallback;
    if (callback != NULL) {
        (*callback)(error, profileId, gWiFiConnection->mLoginCallbackArg);
    }
}

void DWCi_UpdateServersCallback(u32 error, u32 isChanged) {
    DWCi_SetState((u32) (gWiFiConnection->mPrevState));
    gWiFiConnection->mBuddySyncCallback(error, isChanged, gWiFiConnection->mBuddySyncCallbackArg);
}

// Result callback of both starts (the matching object's mResultCallback): result 0 with flag 0 sets state 6 and finds
// the own position / mOwnIndex among the participants; result 0 with a flag sets state 3 when no search is running;
// every result rebuilds mParticipantMask and then calls mMatchingCallback (modes 0 and 1) or the unset mode 2/3
// callback.
void DWCi_MatchedCallback(u32 error, u32 cancel, u32 self, u32 isServer, u32 index) {
    s32 participantIndex;
    WiFiConnection *wiFiConnection;

    if (error == 0 && cancel != 0) {
        if (gWiFiConnection->mMatching.mState == 0) {
            DWCi_ClearQR2Key();
            DWCi_SetState(3);
        }
    } else if (error == 0) {
        DWCi_SetState(6);
        for (participantIndex = 0; participantIndex <= gWiFiConnection->mMatching.mLastParticipantPos;
             participantIndex++) {
            if (gWiFiConnection->mProfileId == gWiFiConnection->mMatching.mParticipantProfileIds[participantIndex]) {
                gWiFiConnection->mOwnIndex = gWiFiConnection->mMatching.mParticipantIndices[participantIndex];
                break;
            }
        }
    }
    gWiFiConnection->mMatching.mParticipantMask = DWCi_GetAIDBitmapFromList(
        gWiFiConnection->mMatching.mParticipantIndices, gWiFiConnection->mMatching.mLastParticipantPos + 1);
    DWCi_SetNumValidConnection();
    wiFiConnection = gWiFiConnection;
    if (wiFiConnection->mMatching.mMode == 2 || wiFiConnection->mMatching.mMode == 3) {
        wiFiConnection = gWiFiConnection;
        wiFiConnection->mMatchedSCCallback(error, cancel, self, isServer, index, wiFiConnection->mMatchedSCCallbackArg);
    } else {
        wiFiConnection->mMatchingCallback(error, cancel, wiFiConnection->mMatchingCallbackArg);
    }
}

// GP callback slot 0 (error). Reports error kind 3 through ReportWiFiGpResult only when the GP error number is not
// 0x603 or 0x901.
void DWCi_GPErrorCallback(u32 connection, int arg) {
    if ((*(s32 *) (arg + 4) != 0x603) && (*(s32 *) (arg + 4) != 0x901)) {
        ReportWiFiGpResult(3);
    }
}

s32 stLastSocketError;

// GP callback slot 3 (message). The first branch hands the text to DWCi_GPRecvBuddyAuthCallback (the "I have authorized
// ..." sentence); the second takes GPCM-prefixed text with a MAT tag and forwards it to the matching code only in state
// 5 or matching mode 2 and 3.
void DWCi_GPRecvBuddyMessageCallback(GpConnection *connection, BuddyMessageData *arg, u32 param) {
    char *message;
    char versionText[12] = {0};
    u32 versionLength;
    WiFiConnection *wiFiConnection;

    message = arg->mUnk_08;
    if (DWCi_GPRecvBuddyAuthCallback(connection, (u32 *) arg, param) == 0) {
        if (memcmp(message, "GPCM", strlen("GPCM")) == 0) {
            message += strlen("GPCM");
            versionLength = strchr(message, 0x76) - message;
            strncpy(versionText, message, versionLength);
            if (versionLength <= 10) {
                if (strtoul(versionText, NULL, 10) == 3) {
                    message += versionLength + 1;
                    if (memcmp(message, "MAT", strlen("MAT")) == 0) {
                        wiFiConnection = gWiFiConnection;
                        if (wiFiConnection->mState == 5 || wiFiConnection->mMatching.mMode == 2 ||
                            wiFiConnection->mMatching.mMode == 3) {
                            message += strlen("MAT");
                            DWCi_MatchGPRecvBuddyMsgCallback(connection, arg->mProfile, message);
                        }
                    }
                }
            }
        }
    }
}

// Slot 1 of the Gt2ConnectionCallbacks record (the library's Gt2CallDataCallback): the body
// only forwards (connection, data, size, flag) to DWCi_RecvCallback, the receive side of the message layer.
void DWCi_GT2ReceivedCallback(Unk0219887c *connection, void *message, s32 length, u32 reliable) {
    DWCi_RecvCallback(connection, message, length, reliable);
}

void DWCi_GT2ClosedCallback(Unk0219887c *connection, u32 reason) {
    u32 profileId;
    s32 detail;
    BOOL hostSide;
    u8 *connectionInfo;
    u32 aid;
    s32 kind;
    u32 inMask;
    WiFiConnection *wiFiConnection;
    u32 friendListIndex;
    void **closedCallbackArg;

    profileId = 0;
    hostSide = FALSE;
    if (DWCi_IsShutdownMatch() != 0) {
        return;
    }
    switch (reason) {
        case 0:
        case 1:
            kind = 0;
            break;
        case 2:
        case 3:
            kind = 6;
            detail = -0x1db0;
            break;
        case 4:
            kind = 0xb;
            detail = -0x1db1;
            break;
    }
    if (kind == 0) {
        connectionInfo = gt2GetConnectionData(connection);
        if (connectionInfo == NULL) {
            return;
        }
        aid = connectionInfo[1];
        inMask = (gWiFiConnection->mMatching.mParticipantMask & (1 << aid)) != 0;
        DWCi_ClearTransConnection(aid);
        wiFiConnection = gWiFiConnection;
        if ((wiFiConnection->mMatching.mMode == 2 && reason == 0) ||
            (wiFiConnection->mMatching.mMode == 3 && aid == 0)) {
            hostSide = TRUE;
        }
        profileId = DWCi_DeleteAID(aid);
        stGt2ConnectionList[connectionInfo[0]] = NULL;
        gWiFiConnection->mMatching.mLastParticipantPos--;
        gWiFiConnection->mMatching.mNNCompletedCount--;
    }
    if (gWiFiConnection->mOwnCloseFlag == 0 && gWiFiConnection->mState == 6 && inMask == 0) {
        if (gWiFiConnection->mMatching.mMode == 2 && kind == 0) {
            DWCi_GPSetServerStatus();
            DWCi_ProcessMatchSCClosing(profileId);
        }
        return;
    }
    if (DWCi_ProcessMatchClosing(kind, detail, profileId) != 0) {
        return;
    }
    if (kind != 0) {
        DWCi_SetError(kind, detail);
        return;
    }
    if (gWiFiConnection->mMatching.mMode == 2) {
        if (gWiFiConnection->mOwnCloseFlag == 0) {
            DWCi_GPSetServerStatus();
        } else if (gWiFiConnection->mMatching.mLastParticipantPos == 0) {
            DWCi_SetGPStatus(1, "", NULL);
        }
    } else if (gWiFiConnection->mMatching.mLastParticipantPos == 0) {
        DWCi_SetGPStatus(1, "", NULL);
    }
    if (gWiFiConnection->mMatching.mMode == 0 || gWiFiConnection->mMatching.mMode == 1) {
        gWiFiConnection->mMatching.mNumEntry = gWiFiConnection->mMatching.mNNCompletedCount;
        qr2_send_statechanged(gWiFiConnection->mMatching.mQr2);
    }
    wiFiConnection = gWiFiConnection;
    if (wiFiConnection->mConnectionClosedCallback != NULL && inMask != 0) {
        if (reason == 0) {
            reason = 1;
        } else {
            reason = 0;
        }
        friendListIndex = DWCi_GetFriendListIndex(profileId);
        closedCallbackArg = &wiFiConnection->mConnectionClosedCallbackArg;
        gWiFiConnection->mConnectionClosedCallback(kind, reason, hostSide, aid, friendListIndex,
                                                   *closedCallbackArg);
    }
    if (gWiFiConnection->mOwnCloseFlag != 0 || gWiFiConnection->mMatching.mMode != 2) {
        if (gWiFiConnection->mMatching.mLastParticipantPos == 0) {
            NNFreeNegotiateList();
            DWCi_ClearQR2Key();
            DWCi_SetState(3);
        }
    }
}

// Slot 3 of the record (Gt2CallElapsedTimeCallback): the body only forwards (connection,
// elapsed time) to DWCi_PingCallback, which calls the layer's mUnk_60c with the time and the peer index.
void DWCi_GT2PingCallback(Unk0219887c *connection, u32 latency) {
    DWCi_PingCallback(connection, latency);
}

void DWCi_GT2SocketErrorCallback(u32 *socket) {
    stLastSocketError = GOAGetLastError(GetSocketDescriptor(socket));
    DWCi_SetError(0xb, -0x17aeb);
    gWiFiConnection->mSocket = NULL;
}

NatTraversalEntry *FindNegotiatorForCookie(u32 cookie) {
    s32 index;
    NatTraversalEntry *negotiator;

    if (negotiateList == NULL) {
        return NULL;
    }
    for (index = 0; index < DarrayGetCount((u32 *) negotiateList); index++) {
        negotiator = DarrayGetElement(negotiateList, index);
        if (negotiator->mCookie == cookie) {
            return negotiator;
        }
    }
    return NULL;
}
