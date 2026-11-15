#pragma once

#include "types.h"
#include "00/types_021906e4.h"

// Values of GPISearchData.mKind: the request each kind sends is named by the first key of its message (search,
// valid, nicks, pmatch, check, newuser, others, uniquesearch).
enum {
    PROFILE_SEARCH_KIND_PROFILES = 1,
    PROFILE_SEARCH_KIND_VALID_EMAIL = 2,
    PROFILE_SEARCH_KIND_NICKS = 3,
    PROFILE_SEARCH_KIND_PLAYER_MATCH = 4,
    PROFILE_SEARCH_KIND_CHECK_NICK = 5,
    PROFILE_SEARCH_KIND_NEW_USER = 6,
    PROFILE_SEARCH_KIND_OTHERS = 7,
    PROFILE_SEARCH_KIND_UNIQUE_NICK = 8,
};

// Object behind GpiOperation.mUnk_04: GpiCreateSearch clears and fills it, GpiOpenSearchSocket sets the
// word at 0x04 and gives it the buffer at 0x08 of 0x0c bytes.
typedef struct GPISearchData {
    /* 000 */ s32 mKind;
    /* 004 */ s32 mSocket;
    /* 008 */ void *mInputBuffer;
    /* 00c */ s32 mInputBufferCapacity;
    /* 010 */ u32 mInputBufferLength;
    /* 014 */ u32 mInputBufferPos;
    /* 018 */ void *mOutputBuffer;
    /* 01c */ s32 mOutputBufferCapacity;
    /* 020 */ u32 mOutputBufferLength;
    /* 024 */ u32 mOutputBufferPos;
    /* 028 */ s8 mNick[0x1f];
    /* 047 */ s8 mUniquenick[0x15];
    /* 05c */ s8 mEmail[0x33];
    /* 08f */ s8 mFirstname[0x1f];
    /* 0ae */ s8 mLastname[0x1f];
    /* 0cd */ s8 mPassword[0x1f];
    /* 0ec */ s8 mCdkey[0x44];
    /* 130 */ s32 mIcquin;
    /* 134 */ s32 mSkip;
    /* 138 */ s32 mProductId;
    /* 13c */ s32 mProcessing;
    /* 140 */ s32 mRemove;
} GPISearchData;

// Values of GpiOperation.mType.
enum {
    PROFILE_OPERATION_CONNECT,
    PROFILE_OPERATION_NEW_PROFILE,
    PROFILE_OPERATION_INFO,
    PROFILE_OPERATION_SEARCH,
    PROFILE_OPERATION_REGISTER_UNIQUE_NICK,
};

// Values of GpiOperation.mState of the connect operation: the reply the server is expected to send next.
enum {
    PROFILE_CONNECT_STATE_WAIT_CHALLENGE = 1,
    PROFILE_CONNECT_STATE_WAIT_LOGIN_REPLY,
    PROFILE_CONNECT_STATE_WAIT_NEW_USER_REPLY,
};

// Values of GpiOperation.mState of the search operation: waiting for the socket to connect, waiting for the reply to
// end, and the reply read.
enum {
    PROFILE_SEARCH_STATE_WAIT_CONNECT = 1,
    PROFILE_SEARCH_STATE_WAIT_REPLY = 4,
    PROFILE_SEARCH_STATE_REPLY_READ = 5,
};

// A queued profile operation: its type, search data, blocking flag, completion callback, state and result.
typedef struct GpiOperation {
    /* 00 */ u32 mType;
    /* 04 */ GPISearchData *mData;
    /* 08 */ u32 mBlocking;
    /* 0c */ GpiCallback mCallback;
    /* 14 */ s32 mState;
    /* 18 */ u32 mId;
    /* 1c */ u32 mResult;
    /* 20 */ struct GpiOperation *mNext;
} GpiOperation;

// Values of GpiPeer.mState.
typedef enum GpiPeerState {
    PROFILE_PEER_STATE_NOT_CONNECTED = 0x64,
    PROFILE_PEER_STATE_WAIT_PROFILE_INFO = 0x65,
    PROFILE_PEER_STATE_START_CONNECT = 0x66,
    PROFILE_PEER_STATE_WAIT_CONNECT = 0x67,
    PROFILE_PEER_STATE_WAIT_AUTH = 0x68,
    PROFILE_PEER_STATE_CONNECTED = 0x69,
    PROFILE_PEER_STATE_CLOSED = 0x6a,
} GpiPeerState;

// A peer connection: its state, socket, profile id, timeout counters and the input and output byte buffers.
typedef struct GpiPeer {
    /* 00 */ s32 mState;
    /* 04 */ u32 mInitiated;
    /* 08 */ s32 mSocket;
    /* 0c */ u32 mProfileId;
    /* 10 */ s32 mTimeout;
    /* 14 */ s32 mNackCount;
    /* 18 */ void *mInputBuffer;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ s32 mInputBufferLength;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ GpiBuffer mOutputBuffer;
    /* 38 */ struct Darray *mQueuedMessages;
    /* 3c */ struct GpiPeer *mNext;
} GpiPeer;
