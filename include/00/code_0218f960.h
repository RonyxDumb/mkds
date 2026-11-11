#pragma once

#include "types.h"
#include "00/types_021937c0.h"
#include "00/types_021906e4.h"

struct GpConnection;

struct GpConnection;

// List at 0x428 of GpiConnection: the object and the number of entries added to it.
typedef struct GPIProfileList {
    /* 00 */ struct Hashtable *mTable;
    /* 04 */ s32 mUnk_04;
} GPIProfileList;

// Object behind GpConnection.mGpiConnection: GpiWriteDelbuddyAndRemoveBuddy passes the address of 0x1f4 to
// GpiAppendBufferString and GpiAppendBufferNumber, reads 0x198 and decrements 0x430.
typedef struct GpiConnection {
    /* 000 */ char mErrorMessage[0x100];
    /* 100 */ s32 mUnk_100;
    /* 104 */ BOOL mUnk_104;
    /* 108 */ u32 mUnk_108;
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
    /* 1e8 */ s32 mUnk_1e8;
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
    /* 420 */ s32 mUnk_420;
    /* 424 */ GpiOperation *mOperationList;
    /* 428 */ GPIProfileList mProfileList;
    /* 430 */ s32 mBuddyCount;
    /* 434 */ GpiPeer *mPeerList;
    /* 438 */ GpiQueuedCallback *mCallbackQueueHead;
    /* 43c */ GpiQueuedCallback *mCallbackQueueTail;
    /* 440 */ void *mUpdateproBuffer;
    /* 444 */ s32 mUpdateproBufferCapacity;
    /* 448 */ s32 mUpdateproBufferLength;
    /* 44c */ s32 mUnk_44c;
    /* 450 */ void *mUpdateuiBuffer;
    /* 454 */ s32 mUpdateuiBufferCapacity;
    /* 458 */ s32 mUpdateuiBufferLength;
    /* 45c */ s32 mUnk_45c;
    /* 460 */ void *mUnk_460;
    /* 464 */ u8 mUnk_464[8];
    /* 46c */ s32 mProductId;
    /* 470 */ s32 mNamespaceId;
    /* 474 */ s8 mUnk_474[0x19];
} GpiConnection;

// Object passed to GpiWriteDelbuddyAndRemoveBuddy as its first argument.
typedef struct GpConnection {
    /* 00 */ GpiConnection *mGpiConnection;
} GpConnection;

typedef struct Unk0218fa98 {
    /* 00 */ u8 pad_00[8];
    /* 08 */ s32 *mUnk_08;
} Unk0218fa98;

typedef struct GpConnection GpConnection;

// Object gpiProcessRecvBuddyMessage allocates with 0xc bytes and passes to GpiQueueCallback.
typedef struct BuddyMessageData {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ char *mUnk_08;
} BuddyMessageData;

// Object gpiProcessRecvBuddyMessage allocates with 0x40c bytes and passes to GpiQueueCallback.
typedef struct BuddyRequestData {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ char mUnk_008[0x404];
} BuddyRequestData;

// Object gpiProcessRecvBuddyMessage allocates with 0x108 bytes and passes to GpiQueueCallback.
typedef struct GameInviteData {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ char mUnk_008[0x100];
} GameInviteData;

extern char gUnexpectedDataErrorString[];
extern char gFKey[];
extern char gDateKey[];
extern u8 data_ov000_021b2814[];
extern char gSignedKey[];
extern char gPipeSKey[];
extern char gPipeSsKey[];
extern char gPipeLsKey[];
extern char gPipeIpKey[];
extern char gPipePKey[];
extern char gPipeLKey[];
extern char data_ov000_021b2854[];

u32 GpiWriteDelbuddyAndRemoveBuddy(GpConnection *connection, u32 profile);
s32 GpiDecrementBuddyIndexAbove(void *unused, Unk0218fa98 *object, s32 minimum);
u32 gpiAuthBuddyRequest(GpConnection *connection, u32 profile);
u32 gpiSendBuddyMessage(GpConnection *connection, s32 profileid, s32 type, const char *message);
u32 gpiSendServerBuddyMessage(GpConnection *connection, s32 profileid, s32 type, const char *message);
s32 gpiProcessRecvBuddyMessage(GpConnection *connection, char *input);
