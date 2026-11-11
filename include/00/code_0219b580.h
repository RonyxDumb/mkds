#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "00/code_021a2ccc.h"

// Online link of one WiFi session, embedded in WiFiSession at 0x0b2c (0xdb4 bytes = 0x7a0 + 0x614, the u8 array in
// WiFiSession) and reached through gWiFiConnection: DWC_InitFriendsMatch sets it up at each login,
// DWC_ShutdownFriendsMatch ends it. mState is its state machine, switched once per frame in DWC_ProcessFriendsMatch: 0
// idle, 1 GP set-up, 2 login, 3 logged in, 4 buddy sync, 5 partner search, 6 matched. Owns the Gt2 socket (mSocket)
// and the GP connection (mGpConnection) and holds the login object (mLogin), the buddy object (mBuddySync), the
// matching object (mUnk_33c) and the net layer (mUnk_7a0). The table of peer connections is not a member
// (stGt2ConnectionList). Not a Gt2Connection (one peer link).
typedef struct WiFiConnection {
    // Gt2Socket * (declared void *): created by DWCi_GT2Startup when the login succeeds (called from
    // code_0219c3e4.c), closed by DWC_ShutdownFriendsMatch or by the socket's own callback DWCi_GT2SocketErrorCallback,
    // which sets it NULL.
    /* 00 */ void *mSocket;
    // Slot 0 of a Gt2ConnectionCallbacks record made of mResultCallback, mDataCallback, mUnk_0c, mElapsedTimeCallback
    // (its address is handed to the matching object and from there to the Gt2 connect call): result of a Gt2 connect,
    // DWCi_GT2ConnectedCallback (retries up to 5 times).
    /* 04 */ void (*mResultCallback)();
    // Slot 1 of the record at mResultCallback: data received from a peer, forwarded to the net layer
    // (DWCi_RecvCallback).
    /* 08 */ void (*mDataCallback)();
    /* 0c */ s32 (*mClosedCallback)();
    // Slot 3 of the record at mResultCallback: forwards (connection, elapsed time) to the net layer's mUnk_60c
    // callback (DWCi_PingCallback). Slot 2 (mUnk_0c) is the connection-closed
    // handler DWCi_GT2ClosedCallback.
    /* 10 */ void (*mElapsedTimeCallback)();
    // Passed to gti2CreateSocket as the send buffer size (0 selects 0x2000).
    /* 14 */ u32 mSendBufferSize;
    // Pair of mSendBufferSize: both come from DWC_InitFriendsMatch's parameters (0 selects 0x2000) and go to
    // gti2CreateSocket, which stores this one at Gt2Socket.mUnk_3c; the library gives it to the second InitBuffer of
    // each connection, the buffer that holds reliable messages arriving ahead of the next expected
    // sequence number.
    /* 18 */ u32 mReceiveBufferSize;
    // The GP connection object: GpInitialize in state 1, closed by DWC_ShutdownFriendsMatch; the buddy object keeps a
    // pointer to it.
    /* 1c */ GpConnection mGpConnection;
    /* 20 */ void *mUnk_20;
    // 0 idle, 1 GP set-up, 2 login, 3 logged in, 4 buddy sync, 5 partner search, 6 matched. Written by
    // DWC_InitFriendsMatch (0) and DWCi_SetState only.
    /* 24 */ s32 mState;
    // State before the last DWCi_SetState; DWCi_UpdateServersCallback returns to it when the sync ends.
    /* 28 */ s32 mPrevState;
    // This player's index among the participants: 0 after Init, then taken from the participant table when a
    // participant id equals mProfileId; read through DWC_GetMyAID.
    /* 2c */ u8 mOwnIndex;
    // 1 only while DWC_CloseAllConnectionsHard closes every peer connection of the socket (state 5 or 6, other
    // participants present); read by DWCi_GT2ClosedCallback to tell this close from a
    // peer leaving. The matching object's own close-all does not set it.
    /* 2d */ u8 mOwnCloseFlag;
    /* 2e */ u16 mUnk_2e;
    // The GP profile id of the logged-in player; set by DWCi_LoginCallback and compared with the participant ids of the
    // matching object.
    /* 30 */ u32 mProfileId;
    // 0x20-byte text given to DWC_UpdateServersAsync (the only caller passes NULL, so it is always empty); handed to
    // DWCi_FriendInit, used as the add-buddy reason text and, when not empty, in the stats request '\dwc_name\%s'.
    /* 34 */ char mPlayerName[0x20];
    // Points at the 0x100-byte game name buffer gcd_gamename (DWC_InitFriendsMatch's fourth argument,
    // "mariokartds"). Its one read is DWC_LoginAsync passing it to GSIStartAvailableCheckA, which copies it to
    // gGsiAcGamename, the buffer GpiWriteLogin appends after '\gamename\'; the matching
    // object's mGameName is the same buffer and the stats host name starts with it.
    /* 54 */ char *mGameName;
    // Points at the 0x100-byte buffer gcd_secret_key (DWC_InitFriendsMatch's fifth argument): mixed into the stats
    // login hash ('%d%s'), given to the matching object as mUnk_2e0. Never read through this
    // member.
    /* 58 */ char *mUnk_58;
    // Set by DWC_LoginAsync; DWCi_LoginCallback calls it with (result, profile id, mLoginCallbackArg) on success and
    // on failure.
    /* 5c */ void (*mLoginCallback)(s32 param_1);
    /* 60 */ u32 mLoginCallbackArg;
    // Set by DWC_UpdateServersAsync; DWCi_UpdateServersCallback calls it with (result, changed flag,
    // mBuddySyncCallbackArg) when the sync ends or fails.
    /* 64 */ void (*mBuddySyncCallback)();
    /* 68 */ void *mBuddySyncCallbackArg;
    // Set by DWC_ConnectToAnybodyAsync / WithBuddies; DWCi_MatchedCallback calls it with (result, flag,
    // mMatchingCallbackArg) for matching modes 0 and 1 (the pair at 0x74 / 0x78 is called for modes 2 and 3 and is
    // never set).
    /* 6c */ void (*mMatchingCallback)(u32 a, u32 b, void *c);
    /* 70 */ void *mMatchingCallbackArg;
    /* 74 */ void (*mMatchedSCCallback)(u32 a, u32 b, u32 c, u32 d, u32 e, void *f);
    /* 78 */ void *mMatchedSCCallbackArg;
    /* 7c */ void (*mConnectionClosedCallback)(s32 a, s32 b, s32 c, u32 d, u32 e, void *f);
    /* 80 */ void *mConnectionClosedCallbackArg;
    // Login object (WiFiLogin): holds the GP connection pointer, the login state
    // (mUnk_04), the two credential strings given to the connect call (mUnk_4c, mUnk_14c) and the saved profile
    // record; stepped in state 2; its result callback is DWCi_LoginCallback.
    /* 84 */ WiFiLogin mLogin;
    /* 2e8 */ WiFiBuddySync mBuddySync;
    /* 33c */ WiFiMatching mMatching;
    /* 7a0 */ WiFiMessageLayer mMessageLayer;
} WiFiConnection;

typedef struct Unk0219887c Unk0219887c;

typedef struct DWCConnectionInfo {
    /* 00 */ u8 mIndex;
    /* 01 */ u8 mAid;
    /* 02 */ u16 mReserve;
    /* 04 */ u32 mParam;
} DWCConnectionInfo;

BOOL DWC_UpdateServersAsync(const s8 *playerName, void (*updateCallback)(s32, s32), void *updateParam,
                            void (*statusCallback)(u32, u8), void *statusParam, void (*deleteCallback)(u32, u32),
                            void *deleteParam);

// Pointer to the connection embedded in gWiFiSession: set by DWC_InitFriendsMatch at each login, NULL after
// DWC_ShutdownFriendsMatch.
extern WiFiConnection *gWiFiConnection;
extern void *stGt2ConnectionList[32];
extern DWCConnectionInfo stConnectionInfoList[32];

void DWCi_GPErrorCallback(u32 connection, int arg);
void DWCi_MatchedCallback(u32 error, u32 cancel, u32 self, u32 isServer, u32 index);
void DWCi_UpdateServersCallback(u32 error, u32 isChanged);
void DWCi_LoginCallback(int error, u32 profileId);
u32 ReportWiFiSocketResult(u32 result);
int ReportWiFiGpResult(int result);
u32 DWCi_GetAIDBitmapFromList(const u8 *values, s32 count);
u32 DWCi_DeleteAID(u32 aid);
void DWCi_SetState(s32 value);
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
u32 DWC_GetState(void);
BOOL DWC_IsValidAID(u32 aid);
s32 DWC_GetAIDList(u8 **aidList);
u8 DWC_GetMyAID(void);
s32 DWC_GetNumConnectionHost(void);
s32 DWC_CloseConnectionHard(s32 aid);
s32 DWC_CloseAllConnectionsHard(void);
void DWC_ConnectToFriendsAsync(void *friendIdxList, u32 friendIdxListLength, u32 numEntry, u32 distantFriend,
                               void *matchedCallback, void *matchedParam, u32 evalCallback, u32 evalParam);
void DWC_ConnectToAnybodyAsync(u32 numEntry, void *addFilter, void *matchedCallback, void *matchedParam,
                               void *evalCallback, u32 evalParam);
void DWC_LoginAsync(u32 playerName, u32 reserved, void (*callback)(s32 playerName), u32 callbackArg);
void DWC_ProcessFriendsMatch(void);
void DWCs_ForceShutdown(void);
u32 UpdateInetConnection(void);
void DWC_ShutdownFriendsMatch(void);
void DWC_InitFriendsMatch(void *connectionObject, void *userData, s32 titleNumber, const char *gameName,
                          const char *secretKey, s32 sendBufferSize, s32 receiveBufferSize, void *friendList,
                          s32 friendListLength);
