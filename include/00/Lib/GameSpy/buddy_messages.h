#pragma once

#include "types.h"
#include "00/Lib/GameSpy/profile_operation_types.h"
#include "00/Lib/GameSpy/profile_callback_types.h"

struct GPConnection;

struct GPConnection;

// The hash table of known profiles and how many were added to it.
typedef struct GPIProfileList {
    /* 00 */ struct HashImplementation *mTable;
    /* 04 */ s32 mNum;
} GPIProfileList;

// Values of GPIConnection.mErrorNumber that the connect code acts on: REMOVES_PROFILE drops the profile the
// connection was using; RETURNS_PROFILE_ID comes with the id of a profile that is read from the reply.
#define PROFILE_ERROR_REMOVES_PROFILE 0x106
#define PROFILE_ERROR_RETURNS_PROFILE_ID 0x201

// Values of GPIConnection.mConnectState: the socket is being connected, then the login handshake runs, then the
// connection is up; IDLE is the state before the connect; CLOSED follows a close and is left only through a reset.
enum {
    PROFILE_CONNECTION_IDLE = 0,
    PROFILE_CONNECTION_SOCKET_OPENING = 1,
    PROFILE_CONNECTION_HANDSHAKE = 2,
    PROFILE_CONNECTION_LOGGED_IN = 3,
    PROFILE_CONNECTION_CLOSED = 4,
};

// The first id given to an operation; mNextOperationId wraps back to it.
#define PROFILE_FIRST_OPERATION_ID 2

// Types of buddy messages: the "bm" value of a server message and the type of a message between peers.
enum {
    BUDDY_MESSAGE_TYPE_MESSAGE = 1,
    BUDDY_MESSAGE_TYPE_REQUEST = 2,
    BUDDY_MESSAGE_TYPE_STATUS = 100,
    BUDDY_MESSAGE_TYPE_INVITE = 101,
    BUDDY_MESSAGE_TYPE_PING = 102,
    BUDDY_MESSAGE_TYPE_PONG = 103,
    BUDDY_MESSAGE_TYPE_TRANSFER_REPLY = 201,
};

// The presence connection: login names, callbacks, sockets, buffers, status strings, operation, profile and peer lists.
typedef struct GPIConnection {
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
    /* 1a4 */ GPICallback mCallbacks[6];
    /* 1d4 */ s32 mConnectSocket;
    /* 1d8 */ s32 mConnectState;
    /* 1dc */ char *mInputBuffer;
    /* 1e0 */ s32 mInputBufferCapacity;
    /* 1e4 */ s32 mInputBufferLength;
    /* 1e8 */ s32 mInputBufferPos;
    /* 1ec */ void *mCommandBuffer;
    /* 1f0 */ s32 mCommandBufferCapacity;
    /* 1f4 */ GPIBuffer mOutputBuffer;
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
    /* 424 */ GPIOperation *mOperationList;
    /* 428 */ GPIProfileList mProfileList;
    /* 430 */ s32 mBuddyCount;
    /* 434 */ GPIPeer *mPeerList;
    /* 438 */ QueuedCallback *mCallbackQueueHead;
    /* 43c */ QueuedCallback *mCallbackQueueTail;
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
} GPIConnection;

// Object passed to gpiDeleteBuddy as its first argument.
typedef struct GPConnection {
    /* 00 */ GPIConnection *mGpiConnection;
} GPConnection;

typedef struct GPIProfile GPIProfile;

typedef struct GPConnection GPConnection;

// A received buddy message: the profile, the date and a string.
typedef struct BuddyMessageData {
    /* 00 */ s32 mProfile;
    /* 04 */ s32 mDate;
    /* 08 */ char *mUnk_08;
} BuddyMessageData;

// A received buddy request: the profile, the date and the reason text.
typedef struct BuddyRequestData {
    /* 000 */ s32 mProfile;
    /* 004 */ s32 mDate;
    /* 008 */ char mReason[0x404];
} BuddyRequestData;

// A received game invite: the profile, the product id and the location text.
typedef struct GameInviteData {
    /* 000 */ s32 mProfile;
    /* 004 */ s32 mProductId;
    /* 008 */ char mLocation[0x100];
} GameInviteData;

u32 gpiDeleteBuddy(GPConnection *connection, u32 profile);
s32 gpiFixBuddyIndices(GPConnection *unused, GPIProfile *profile, void *data);
u32 gpiAuthBuddyRequest(GPConnection *connection, u32 profile);
u32 gpiSendBuddyMessage(GPConnection *connection, s32 profileid, s32 type, const char *message);
u32 gpiSendServerBuddyMessage(GPConnection *connection, s32 profileid, s32 type, const char *message);
s32 gpiProcessRecvBuddyMessage(GPConnection *connection, char *input);

typedef struct GPConnection GPConnection;
typedef struct GPIProfile GPIProfile;
typedef struct GPIBuffer GPIBuffer;

u32 gpiSendAuthBuddyRequest(GPConnection *connection, GPIProfile *profile);
u32 gpiClipBufferToPosition(GPConnection *connection, GPIBuffer *buffer);
u32 gpiReadMessageFromBuffer(GPConnection *connection, GPIBuffer *inputBuffer, s32 *message, s32 *type, s32 *plen);
