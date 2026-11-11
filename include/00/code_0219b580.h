#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "00/code_021a2ccc.h"

// Online link of one WiFi session, embedded in WiFiSession at 0x0b2c (0xdb4 bytes = 0x7a0 + 0x614, the u8 array in
// WiFiSession) and reached through gWiFiConnection: InitWiFiConnection sets it up at each login,
// ReleaseWiFiConnection ends it. mState is its state machine, switched once per frame in UpdateWiFiConnection: 0
// idle, 1 GP set-up, 2 login, 3 logged in, 4 buddy sync, 5 partner search, 6 matched. Owns the Gt2 socket (mSocket)
// and the GP connection (mGpConnection) and holds the login object (mLogin), the buddy object (mBuddySync), the
// matching object (mUnk_33c) and the net layer (mUnk_7a0). The table of peer connections is not a member
// (stGt2ConnectionList). Not a Gt2Connection (one peer link).
typedef struct WiFiConnection {
    // Gt2Socket * (declared void *): created by DWCi_GT2Startup when the login succeeds (called from
    // code_0219c3e4.c), closed by ReleaseWiFiConnection or by the socket's own callback DWCi_GT2SocketErrorCallback,
    // which sets it NULL.
    /* 00 */ void *mSocket;
    // Slot 0 of a Gt2ConnectionCallbacks record made of mResultCallback, mDataCallback, mUnk_0c, mElapsedTimeCallback
    // (its address is handed to the matching object and from there to the Gt2 connect call): result of a Gt2 connect,
    // WiFiGt2ResultCallback (retries up to 5 times).
    /* 04 */ void (*mResultCallback)();
    // Slot 1 of the record at mResultCallback: data received from a peer, forwarded to the net layer
    // (func_ov000_021a317c).
    /* 08 */ void (*mDataCallback)();
    /* 0c */ s32 (*mUnk_0c)();
    // Slot 3 of the record at mResultCallback: forwards (connection, elapsed time) to the net layer's mUnk_60c
    // callback (func_ov000_021a314c). Slot 2 (mUnk_0c, the library's unnamed mUnk_08) is the connection-closed
    // handler DWCi_GT2ClosedCallback.
    /* 10 */ void (*mElapsedTimeCallback)();
    // Passed to CreateSocket as the send buffer size (0 selects 0x2000).
    /* 14 */ u32 mSendBufferSize;
    // Pair of mSendBufferSize: both come from InitWiFiConnection's parameters (0 selects 0x2000) and go to
    // CreateSocket, which stores this one at Gt2Socket.mUnk_3c; the library gives it to the second InitBuffer of each
    // connection (code_0219a0d0.c:48), the buffer that holds reliable messages arriving ahead of the next expected
    // sequence number (code_02199614.c:51, code_0219981c.c:38).
    /* 18 */ u32 mReceiveBufferSize;
    // The GP connection object: GpInitialize in state 1, closed by ReleaseWiFiConnection; the buddy object keeps a
    // pointer to it.
    /* 1c */ GpConnection mGpConnection;
    /* 20 */ void *mUnk_20;
    // 0 idle, 1 GP set-up, 2 login, 3 logged in, 4 buddy sync, 5 partner search, 6 matched. Written by
    // InitWiFiConnection (0) and SetWiFiConnectionState only.
    /* 24 */ s32 mState;
    // State before the last SetWiFiConnectionState; WiFiBuddySyncCallback returns to it when the sync ends.
    /* 28 */ s32 mPrevState;
    // This player's index among the participants: 0 after Init, then taken from the participant table when a
    // participant id equals mProfileId; read through GetOwnParticipantIndex.
    /* 2c */ u8 mOwnIndex;
    // 1 only while DWC_CloseAllConnectionsHard closes every peer connection of the socket (state 5 or 6, other
    // participants present); read by DWCi_GT2ClosedCallback to tell this close from a
    // peer leaving. The matching object's own close-all does not set it.
    /* 2d */ u8 mUnk_2d;
    /* 2e */ u16 mUnk_2e;
    // The GP profile id of the logged-in player; set by WiFiLoginCallback and compared with the participant ids of the
    // matching object.
    /* 30 */ u32 mProfileId;
    // 0x20-byte text given to StartWiFiBuddySync (the only caller passes NULL, so it is always empty); handed to
    // InitBuddySync, used as the add-buddy reason text and, when not empty, in the stats request '\dwc_name\%s'.
    /* 34 */ char mUnk_34[0x20];
    // Points at the 0x100-byte game name buffer gcd_gamename (InitWiFiConnection's fourth argument,
    // "mariokartds"). Its one read is StartWiFiLogin passing it to GSIStartAvailableCheckA, which copies it to
    // gGsiAcGamename, the buffer GpiWriteLogin appends after '\gamename\'; the matching
    // object's mGameName is the same buffer and the stats host name starts with it (code_0219742c.c:49).
    /* 54 */ char *mGameName;
    // Points at the 0x100-byte buffer gcd_secret_key (InitWiFiConnection's fifth argument): mixed into the stats
    // login hash ('%d%s', code_02196960.c:36), given to the matching object as mUnk_2e0. Never read through this
    // member.
    /* 58 */ char *mUnk_58;
    // Set by StartWiFiLogin; WiFiLoginCallback calls it with (result, profile id, mLoginCallbackArg) on success and
    // on failure.
    /* 5c */ void (*mLoginCallback)(s32 param_1);
    /* 60 */ u32 mLoginCallbackArg;
    // Set by StartWiFiBuddySync; WiFiBuddySyncCallback calls it with (result, changed flag, mBuddySyncCallbackArg)
    // when the sync ends or fails.
    /* 64 */ void (*mBuddySyncCallback)();
    /* 68 */ void *mBuddySyncCallbackArg;
    // Set by StartWiFiMatchingWithFilter / WithBuddies; WiFiMatchingCallback calls it with (result, flag,
    // mMatchingCallbackArg) for matching modes 0 and 1 (the pair at 0x74 / 0x78 is called for modes 2 and 3 and is
    // never set).
    /* 6c */ void (*mMatchingCallback)(u32 a, u32 b, void *c);
    /* 70 */ void *mMatchingCallbackArg;
    /* 74 */ void (*mUnk_74)(u32 a, u32 b, u32 c, u32 d, u32 e, void *f);
    /* 78 */ void *mUnk_78;
    /* 7c */ void (*mUnk_7c)(s32 a, s32 b, s32 c, u32 d, u32 e, void *f);
    /* 80 */ void *mUnk_80;
    // Login object (WiFiLogin): holds the GP connection pointer, the login state
    // (mUnk_04), the two credential strings given to the connect call (mUnk_4c, mUnk_14c) and the saved profile
    // record; stepped in state 2; its result callback is WiFiLoginCallback.
    /* 84 */ WiFiLogin mLogin;
    /* 2e8 */ WiFiBuddySync mBuddySync;
    /* 33c */ WiFiMatching mMatching;
    /* 7a0 */ WiFiMessageLayer mMessageLayer;
} WiFiConnection;

typedef struct Unk0219887c Unk0219887c;

typedef struct DWCConnectionInfo {
    /* 00 */ u8 mIndex;
    /* 01 */ u8 mAid;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mParam;
} DWCConnectionInfo;

BOOL StartWiFiBuddySync(const s8 *playerName, void (*updateCallback)(s32, s32), void *updateParam,
                        void (*statusCallback)(u32, u8), void *statusParam, void (*deleteCallback)(u32, u32),
                        void *deleteParam);

// Pointer to the connection embedded in gWiFiSession: set by InitWiFiConnection at each login, NULL after
// ReleaseWiFiConnection.
extern WiFiConnection *gWiFiConnection;
extern void *stGt2ConnectionList[32];
extern DWCConnectionInfo stConnectionInfoList[32];

void WiFiGpErrorCallback(u32 connection, int arg);
void WiFiMatchingCallback(u32 error, u32 cancel, u32 self, u32 isServer, u32 index);
void WiFiBuddySyncCallback(u32 error, u32 isChanged);
void WiFiLoginCallback(int error, u32 profileId);
u32 ReportWiFiSocketResult(u32 result);
int ReportWiFiGpResult(int result);
u32 DWCi_GetAIDBitmapFromList(const u8 *values, s32 count);
u32 DWCi_DeleteAID(u32 aid);
void SetWiFiConnectionState(s32 value);
BOOL DWCi_IsValidAID(u32 aid);
DWCConnectionInfo *DWCi_GetConnectionInfoByIdx(s32 index);
void **DWCi_GetGT2ConnectionByProfileID(u32 profileId, s32 numHost);
void **DWCi_GetGT2ConnectionByIdx(s32 index);
void DWCi_ClearGT2ConnectionList(void);
s32 DWCi_GT2GetConnectionListIdx(void);
u32 DWCi_GetConnectionIndex(Unk0219887c *connection);
u8 DWCi_GetConnectionAID(Unk0219887c *connection);
void *DWCi_GetGT2Connection(u32 aid);
s32 DWCi_GT2Startup(void);
u32 GetWiFiConnectionState(void);
BOOL DWC_IsValidAID(u32 aid);
s32 DWC_GetAIDList(u8 **aidList);
u8 GetOwnParticipantIndex(void);
s32 DWC_GetNumConnectionHost(void);
s32 DWC_CloseConnectionHard(s32 aid);
s32 DWC_CloseAllConnectionsHard(void);
void StartWiFiMatchingWithBuddies(void *friendIdxList, u32 friendIdxListLength, u32 numEntry, u32 distantFriend,
                                  void *matchedCallback, void *matchedParam, u32 evalCallback, u32 evalParam);
void StartWiFiMatchingWithFilter(u32 numEntry, void *addFilter, void *matchedCallback, void *matchedParam,
                                 void *evalCallback, u32 evalParam);
void StartWiFiLogin(u32 playerName, u32 reserved, void (*callback)(s32 playerName), u32 callbackArg);
void UpdateWiFiConnection(void);
void DWCs_ForceShutdown(void);
u32 UpdateInetConnection(void);
void ReleaseWiFiConnection(void);
void InitWiFiConnection(void *connectionObject, void *userData, s32 productId, const char *gameName,
                        const char *secretKey, s32 sendBufferSize, s32 receiveBufferSize, void *friendList,
                        s32 friendListLength);
// Declared here until the code that defines it is decompiled.
