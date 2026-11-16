#pragma once

#include "types.h"
#include "00/Lib/GameSpy/profile_operation_types.h"
#include "00/Lib/GameSpy/profile_callback_types.h"

struct GpConnection;

struct GpConnection;

// The hash table of buddy profiles and how many were added to it.
typedef struct GPIProfileList {
    /* 00 */ struct Hashtable *mTable;
    /* 04 */ s32 mNum;
} GPIProfileList;

// Values of GpiConnection.mErrorNumber that the connect code acts on: REMOVES_PROFILE drops the profile the
// connection was using; RETURNS_PROFILE_ID comes with the id of a profile that is read from the reply.
#define PROFILE_ERROR_REMOVES_PROFILE 0x106
#define PROFILE_ERROR_RETURNS_PROFILE_ID 0x201

// Values of GpiConnection.mConnectState: the socket is being connected, then the login handshake runs, then the
// connection is up; IDLE is the state before the connect; CLOSED follows a close and is left only through a reset.
enum {
    PROFILE_CONNECTION_IDLE = 0,
    PROFILE_CONNECTION_SOCKET_OPENING = 1,
    PROFILE_CONNECTION_HANDSHAKE = 2,
    PROFILE_CONNECTION_LOGGED_IN = 3,
    PROFILE_CONNECTION_CLOSED = 4,
};

// The first id given to an operation; mNextOperationId wraps back to it.
#define GPI_FIRST_OPERATION_ID 2

// Types of buddy messages: the "bm" value of a server message and the type of a message between peers.
enum {
    GPI_BM_MESSAGE = 1,
    GPI_BM_REQUEST = 2,
    GPI_BM_STATUS = 100,
    GPI_BM_INVITE = 101,
    GPI_BM_PING = 102,
    GPI_BM_PONG = 103,
    GPI_BM_FILE_SEND_REQUEST = 200,
    GPI_BM_FILE_SEND_REPLY,
    GPI_BM_FILE_BEGIN,
    GPI_BM_FILE_END,
    GPI_BM_FILE_DATA,
    GPI_BM_FILE_SKIP,
    GPI_BM_FILE_TRANSFER_THROTTLE,
    GPI_BM_FILE_TRANSFER_CANCEL,
    GPI_BM_FILE_TRANSFER_KEEPALIVE,
};

// Object behind GpConnection.mGpiConnection: GpiWriteDelbuddyAndRemoveBuddy passes the address of 0x1f4 to
// GpiAppendBufferString and GpiAppendBufferNumber, reads 0x198 and decrements 0x430.
typedef struct GpiConnection {
    /* 000 */ char mErrorMessage[0x100];
    /* 100 */ s32 mInfoCaching;
    /* 104 */ BOOL mInfoCachingBuddyOnly;
    /* 108 */ u32 mSimulation;
    /* 10c */ BOOL mFirewall;
    /* 110 */ char mNick[0x1f];
    /* 12f */ s8 mUniquenick[0x15];
    /* 144 */ char mEmail[0x33];
    /* 177 */ s8 mPassword[0x21];
    /* 198 */ u32 mSesskey;
    /* 19c */ u32 mUserId;
    /* 1a0 */ u32 mProfileId;
    /* 1a4 */ GpiCallback mCallbacks[6];
    /* 1d4 */ s32 mConnectSocket;
    /* 1d8 */ s32 mConnectState;
    /* 1dc */ char *mInputBuffer;
    /* 1e0 */ s32 mInputBufferCapacity;
    /* 1e4 */ s32 mInputBufferLength;
    /* 1e8 */ s32 mInputBufferPos;
    /* 1ec */ void *mCommandBuffer;
    /* 1f0 */ s32 mCommandBufferCapacity;
    /* 1f4 */ GpiBuffer mOutputBuffer;
    /* 204 */ s32 mListenSocket;
    /* 208 */ u32 mPort;
    /* 20c */ s32 mNextOperationId;
    /* 210 */ s32 mSearchCount;
    /* 214 */ s32 mStatus;
    /* 218 */ char mStatusString[0x100];
    /* 318 */ char mLocationString[0x100];
    /* 418 */ u32 mErrorNumber;
    /* 41c */ BOOL mFatal;
    /* 420 */ s32 mDiskCache;
    /* 424 */ GpiOperation *mOperationList;
    /* 428 */ GPIProfileList mProfileList;
    /* 430 */ s32 mBuddyCount;
    /* 434 */ GpiPeer *mPeerList;
    /* 438 */ GpiQueuedCallback *mCallbackQueueHead;
    /* 43c */ GpiQueuedCallback *mCallbackQueueTail;
    /* 440 */ void *mUpdateproBuffer;
    /* 444 */ s32 mUpdateproBufferCapacity;
    /* 448 */ s32 mUpdateproBufferLength;
    /* 44c */ s32 mUpdateproBufferPos;
    /* 450 */ void *mUpdateuiBuffer;
    /* 454 */ s32 mUpdateuiBufferCapacity;
    /* 458 */ s32 mUpdateuiBufferLength;
    /* 45c */ s32 mUpdateuiBufferPos;
    /* 460 */ void *mDebugBuffer;
    /* 464 */ u8 mUnk_464[8];
    /* 46c */ s32 mProductId;
    /* 470 */ s32 mNamespaceId;
    /* 474 */ char mLoginTicket[0x19];
} GpiConnection;

// Object passed to GpiWriteDelbuddyAndRemoveBuddy as its first argument.
typedef struct GpConnection {
    /* 00 */ GpiConnection *mGpiConnection;
} GpConnection;

typedef struct GpiProfile GpiProfile;

typedef struct GpConnection GpConnection;

// Object gpiProcessRecvBuddyMessage allocates with 0xc bytes and passes to GpiQueueCallback.
typedef struct BuddyMessageData {
    /* 00 */ s32 mProfile;
    /* 04 */ s32 mDate;
    /* 08 */ char *mUnk_08;
} BuddyMessageData;

// Object gpiProcessRecvBuddyMessage allocates with 0x40c bytes and passes to GpiQueueCallback.
typedef struct BuddyRequestData {
    /* 000 */ s32 mProfile;
    /* 004 */ s32 mDate;
    /* 008 */ char mReason[0x404];
} BuddyRequestData;

// Object gpiProcessRecvBuddyMessage allocates with 0x108 bytes and passes to GpiQueueCallback.
typedef struct GameInviteData {
    /* 000 */ s32 mProfile;
    /* 004 */ s32 mProductId;
    /* 008 */ char mLocation[0x100];
} GameInviteData;

u32 GpiWriteDelbuddyAndRemoveBuddy(GpConnection *connection, u32 profile);
s32 GpiDecrementBuddyIndexAbove(GpConnection *unused, GpiProfile *profile, void *data);
u32 gpiAuthBuddyRequest(GpConnection *connection, u32 profile);
u32 gpiSendBuddyMessage(GpConnection *connection, s32 profileid, s32 type, const char *message);
u32 gpiSendServerBuddyMessage(GpConnection *connection, s32 profileid, s32 type, const char *message);
s32 gpiProcessRecvBuddyMessage(GpConnection *connection, char *input);

typedef struct GpConnection GpConnection;
typedef struct GpiProfile GpiProfile;
typedef struct GpiBuffer GpiBuffer;

u32 gpiSendAuthBuddyRequest(GpConnection *connection, GpiProfile *profile);
u32 gpiClipBufferToPosition(GpConnection *connection, GpiBuffer *buffer);
u32 gpiReadMessageFromBuffer(GpConnection *connection, GpiBuffer *inputBuffer, s32 *message, s32 *type, s32 *plen);
