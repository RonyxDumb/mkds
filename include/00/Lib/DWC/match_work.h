#pragma once

#include "types.h"
#include "00/Lib/DWC/match_send.h"

// Values of WiFiMatching.mState: IDLE means no search; the search states look through the server list (LIST_SEARCH) or
// send a reservation and wait for the reply (RESERVING); the negotiate and connect states take a reserved peer through
// address negotiation and the connection (the client is the side that searched); the sync states line the
// participants up before the result is reported, the cancel states do the same to back out, and MIN_COMPLETE_POLL asks
// every participant whether the minimum entry timeout has passed.
enum {
    WIFI_MATCH_STATE_IDLE = 0,
    WIFI_MATCH_STATE_CONNECTED = 1,
    WIFI_MATCH_STATE_LIST_FIRST_UPDATE = 2,
    WIFI_MATCH_STATE_LIST_SEARCH = 3,
    WIFI_MATCH_STATE_RESERVING = 4,
    WIFI_MATCH_STATE_HOST_LOOKUP = 5,
    WIFI_MATCH_STATE_NEGOTIATE_CLIENT = 6,
    WIFI_MATCH_STATE_CONNECT_CLIENT = 7,
    WIFI_MATCH_STATE_CANCEL_CLIENT = 8,
    WIFI_MATCH_STATE_SYN_CLIENT = 9,
    WIFI_MATCH_STATE_ACCEPTING = 10,
    WIFI_MATCH_STATE_NEGOTIATE_SERVER = 11,
    WIFI_MATCH_STATE_CONNECT_SERVER = 12,
    WIFI_MATCH_STATE_INFORM_PEERS = 13,
    WIFI_MATCH_STATE_CANCEL_SERVER = 14,
    WIFI_MATCH_STATE_CANCEL_SERVER_DELAY = 15,
    WIFI_MATCH_STATE_SYN_SERVER = 16,
    WIFI_MATCH_STATE_SYN_SERVER_DELAY = 17,
    WIFI_MATCH_STATE_RESUME_WAIT = 18,
    WIFI_MATCH_STATE_MIN_COMPLETE_POLL = 19,
};

// The matching state embedded in WiFiConnection at 0x33c (0x464 bytes), reached through gWiFiMatching; not
// WiFiVSMatching, the VS screen.
typedef struct GTI2Socket GTI2Socket;
typedef s32 MatchEvalFunc();
typedef void (*DWCMatchedSCCallback)(u32 error, u32 cancel, u32 self, u32 isServer, u32 index, u32 arg);

typedef struct WiFiMatching {
    /* 000 */ struct GPConnection *mGpConnection;
    // Address of WiFiConnection.mSocket, so a socket made or cleared later is seen; every use except the NULL tests
    // dereferences it.
    /* 004 */ GTI2Socket **mConnectionSocket;
    // Address of the GT2ConnectionCallbacks record in WiFiConnection, given to the connect calls.
    /* 008 */ struct GT2ConnectionCallbacks *mConnectionCallbacks;
    /* 00c */ u8 mConnectRetryCount;
    // Position of the last participant: the lists hold mLastParticipantPos + 1 entries and 0 means nobody else.
    /* 00d */ u8 mLastParticipantPos;
    // One less than the number of bits set in mParticipantMask, 0 when none; used in place of mLastParticipantPos in
    // modes 2 and 3.
    /* 00e */ u8 mLastMaskedParticipantPos;
    /* 00f */ u8 mUnk_0f;
    /* 010 */ struct QueryRecord *mQr2;
    /* 014 */ u8 mNNCompletedCount;
    // 0 filter search, 1 buddy list (set by DWCi_SetMatchCommonParam); the code also tests 2 and 3, which nothing sets.
    /* 015 */ volatile u8 mMode;
    /* 016 */ u8 mNumEntry;
    /* 017 */ u8 mMresvPresent;
    /* 018 */ u8 mQr2ShutdownPending;
    /* 019 */ u8 mUnk_19;
    /* 01a */ u16 mOwnPort;
    /* 01c */ u32 mOwnAddress;
    /* 020 */ u32 mMresvProfileId;
    // Address each participant's commands are sent to; mParticipantCommandPorts holds the matching ports.
    /* 024 */ u32 mParticipantCommandAddresses[32];
    /* 0a4 */ u16 mParticipantCommandPorts[32];
    /* 0e4 */ struct MatchingServerList *mServerList;
    /* 0e8 */ u32 mServerUpdateWaitKind;
    /* 0ec */ u64 mServerUpdateWaitStartTick;
    // GP profile id of each participant by position; the connection finds its own position by comparing
    // WiFiConnection.mProfileId.
    /* 0f4 */ u32 mParticipantProfileIds[32];
    /* 174 */ u8 mNatnegCounts[2];
    /* 176 */ u16 mCookieRandom;
    /* 178 */ u32 mLastNatnegCookie;
    /* 17c */ u64 mNNFailedTime;
    /* 184 */ u64 mIncomingWaitStartTime;
    /* 18c */ DWCNNInfo mNNInfo;
    // WIFI_MATCH_STATE_*; switched on by DWCi_MatchProcess when its parameter is 1; IDLE means no search is running.
    /* 198 */ s32 mState;
    /* 19c */ u8 mPostProcessPos;
    /* 19d */ u8 mBuddyEntryIndexPos;
    /* 19e */ u8 mDistantFriend;
    /* 19f */ u8 mPriorResvDelayCount;
    /* 1a0 */ u8 mCloseKind;
    /* 1a1 */ u8 mStopPending;
    /* 1a2 */ u8 mResvRetryCount;
    /* 1a3 */ u8 mSynResendCounts[2];
    /* 1a5 */ u8 mUnk_1a5;
    /* 1a6 */ u16 mSynLatency;
    /* 1a8 */ u16 mCancelSynLatency;
    /* 1aa */ u16 mServerPort;
    /* 1ac */ u32 mServerAddress;
    /* 1b0 */ u32 mResvDelayPending;
    /* 1b4 */ u64 mResvDelayStartTick;
    /* 1bc */ u32 mResvTimeoutMs;
    /* 1c0 */ u64 mResvTimeoutStartTick;
    /* 1c8 */ u32 mSynReplyMask;
    /* 1cc */ u32 mCancelSynReplyMask;
    /* 1d0 */ u64 mLastPeerMessageSendTime;
    /* 1d8 */ u64 mLastCancelSynSendTime;
    /* 1e0 */ u64 mResumeWaitStartTime;
    /* 1e8 */ u32 mOwnProfileId;
    /* 1ec */ u32 mReplyProfileId;
    /* 1f0 */ u32 mPriorProfileId;
    /* 1f4 */ u32 mEventProfileId;
    // Address each participant is connected to; mParticipantConnectPorts holds the matching ports.
    /* 1f8 */ u32 mParticipantConnectAddresses[32];
    /* 278 */ u16 mParticipantConnectPorts[32];
    // u8[32] parallel to mParticipantProfileIds: the session index of each participant; the connection takes mOwnIndex
    // from it at its own position.
    /* 2b8 */ u8 mParticipantIndices[32];
    // One bit per participant index, rebuilt from mParticipantIndices; a bit is cleared when its participant leaves.
    /* 2d8 */ u32 mParticipantMask;
    // The game name buffer WiFiConnection.mGameName points to, given to the server list.
    /* 2dc */ const char *mGameName;
    // The key string gcd_secret_key, given after the game name when the server list is created.
    /* 2e0 */ const char *mSecretKey;
    /* 2e4 */ u8 *mBuddies;
    /* 2e8 */ u32 mBuddyEntryCount;
    /* 2ec */ u8 mBuddyEntryIndices[0x40];
    /* 32c */ s32 mBuddyEntryIndexCount;
    /* 330 */ u32 mReceivedList[0x21];
    /* 3b4 */ u8 mLastCommand;
    /* 3b5 */ u8 mResendCount;
    /* 3b6 */ u16 mLastCommandPort;
    /* 3b8 */ u32 mLastCommandAddress;
    /* 3bc */ u8 mLastCommandValues[0x80];
    /* 43c */ u32 mLastCommandProfileId;
    /* 440 */ u32 mLastCommandValueCount;
    /* 444 */ u64 mLastCommandTime;
    // Set by DWCi_SetMatchCommonParam; called with (error kind or 0, 0 or 1, ..., mResultCallbackArg), among others by
    // DWCi_StopMatching.
    /* 44c */ DWCMatchedSCCallback mResultCallback;
    /* 450 */ u32 mResultCallbackArg;
    /* 454 */ void (*mNewParticipantCallback)(u32 friendIndex, u32 callbackArg);
    /* 458 */ u32 mNewParticipantCallbackArg;
    /* 45c */ MatchEvalFunc *mEvalCallback;
    /* 460 */ u32 mEvalCallbackArg;
} WiFiMatching;

// Values of WiFiMatching.mMode: a search by filter, a search among the buddy list, a server that takes in clients and
// the client of a server.
enum {
    WIFI_MATCH_MODE_FILTER_SEARCH = 0,
    WIFI_MATCH_MODE_BUDDY_LIST = 1,
    WIFI_MATCH_MODE_SERVER = 2,
    WIFI_MATCH_MODE_SERVER_CLIENT = 3,
};

// Timeouts (milliseconds) and retry limits of the matching. A CONNECT_INFO command with
// no answer is sent again after WIFI_MATCH_COMMAND_WAIT_MSEC; the resend, reserve retry and connect retry counters
// give up once they pass WIFI_MATCH_RETRY_MAX; a RESERVE_OK that is not followed up is dropped after
// WIFI_MATCH_COMMAND_WAIT_MSEC in a filter search and after WIFI_MATCH_RESERVE_OK_KEEP_MSEC in every mode.
#define DWC_MAX_CONNECTIONS 32
#define WIFI_MATCH_RETRY_MAX 5
#define WIFI_MATCH_COMMAND_WAIT_MSEC 6000
#define WIFI_MATCH_RESV_TIMEOUT_MSEC 6000
#define DWC_MATCH_SB_UPDATE_TIMEOUT 13000
#define WIFI_MATCH_RESERVE_OK_KEEP_MSEC (WIFI_MATCH_COMMAND_WAIT_MSEC + DWC_MATCH_SB_UPDATE_TIMEOUT)
#define WIFI_MATCH_INCOMING_WAIT_MSEC 25000
#define WIFI_MATCH_PARTICIPANT_INFO_WAIT_MSEC 30000
#define WIFI_MATCH_NN_FAILED_WAIT_MSEC 10000
#define WIFI_MATCH_NATNEG_FAILURE_LIMIT 5
#define WIFI_MATCH_PRIOR_RESV_DELAY_MAX 16
#define WIFI_MATCH_RESUME_WAIT_MSEC 3000
#define MATCH_RESEND_INTERVAL_MS 3000

// Values of WiFiMatching.mLastCommand and the command number of the matching messages DWCi_SendMatchCommand sends and
// DWCi_ProcessRecvMatchCommand handles. RESERVE asks a host for a place (RESERVE_PRIORITY when a prior host is set);
// the host answers with RESERVE_OK, RESERVE_DENIED or RESERVE_WAIT. CONNECT_INFO carries the address for the
// connection, PARTICIPANT_INFO and PARTICIPANT_ACK pass on the participant list entries. NONE is no command.
enum {
    WIFI_MATCH_COMMAND_RESERVE = 1,
    WIFI_MATCH_COMMAND_RESERVE_OK = 2,
    WIFI_MATCH_COMMAND_RESERVE_DENIED = 3,
    WIFI_MATCH_COMMAND_RESERVE_WAIT = 4,
    WIFI_MATCH_COMMAND_CANCEL_RESERVE = 5,
    WIFI_MATCH_COMMAND_CONNECT_INFO = 6,
    WIFI_MATCH_COMMAND_NEW_PARTICIPANT = 7,
    WIFI_MATCH_COMMAND_PARTICIPANT_INFO = 8,
    WIFI_MATCH_COMMAND_PARTICIPANT_ACK = 9,
    WIFI_MATCH_COMMAND_RESUME_MATCHING = 10,
    WIFI_MATCH_COMMAND_RESERVE_PRIORITY = 11,
    WIFI_MATCH_COMMAND_CANCEL_HOST = 12,
    WIFI_MATCH_COMMAND_CANCEL_SYN_FIRST = 13,
    WIFI_MATCH_COMMAND_CANCEL_SYN_SECOND = 14,
    WIFI_MATCH_COMMAND_CANCEL_SYN_THIRD = 15,
    WIFI_MATCH_COMMAND_CLOSE_CONNECTIONS = 16,
    WIFI_MATCH_COMMAND_MIN_COMPLETE_QUERY = 17,
    WIFI_MATCH_COMMAND_MIN_COMPLETE_REPLY = 18,
    WIFI_MATCH_COMMAND_STOP_MATCHING = 19,
    WIFI_MATCH_COMMAND_NONE = 0xff,
};

// Values of WiFiMatching.mCloseKind, set while the matching closes connections itself: the close callback is ignored
// (1), or ignored and DWCi_ProcessMatchSCClosing also skips its cancel (2); 3 marks the close after a failure.
enum {
    WIFI_MATCH_CLOSE_NONE = 0,
    WIFI_MATCH_CLOSE_IGNORE_CALLBACK = 1,
    WIFI_MATCH_CLOSE_IGNORE_CALLBACK_AND_SC_CANCEL = 2,
    WIFI_MATCH_CLOSE_ALL_AFTER_CLOSE = 3,
};

// Values of WiFiMatching.mServerUpdateWaitKind: no update waits, or one waits 1000 ms or 3000 ms before the server
// list update is requested.
enum {
    WIFI_MATCH_UPDATE_WAIT_NONE = 0,
    WIFI_MATCH_UPDATE_WAIT_1000_MS = 1,
    WIFI_MATCH_UPDATE_WAIT_3000_MS = 2,
};

void DWCi_QR2PublicAddrCallback(u32 address, u16 port, void *userData);
