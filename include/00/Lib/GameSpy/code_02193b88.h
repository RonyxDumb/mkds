#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/Lib/GameSpy/code_02194bb8.h"

// Buffers made by GpiQueueOperationCallback, one for each request type; the first word is taken from the request.
typedef struct ConnectReply {
    /* 00 */ s32 mResult;
    /* 04 */ u32 mProfile;
    /* 08 */ char mUniquenick[0x18];
} ConnectReply;

typedef struct NewProfileReply {
    /* 0 */ s32 mResult;
    /* 4 */ u8 mUnk_04[4];
} NewProfileReply;

// Values of ProfileSearchReply.mMore: the reply starts as DONE and becomes CONTINUE when the server says more
// matches follow; the search is asked again only while it is still CONTINUE after the callback ran.
enum {
    PROFILE_SEARCH_MORE_CONTINUE = 0x600,
    PROFILE_SEARCH_MORE_DONE = 0x601,
};

typedef struct ProfileSearchReply {
    /* 0 */ s32 mResult;
    /* 4 */ s32 mNumMatches;
    /* 8 */ s32 mMore;
    /* c */ ProfileMatch *mMatches;
} ProfileSearchReply;

typedef struct RegisterNickReply {
    /* 0 */ s32 mResult;
} RegisterNickReply;

// Three words printed by GpiPeerSendXfer.
typedef struct GpiTransferId {
    /* 0 */ u32 mProfileId;
    /* 4 */ u32 mCount;
    /* 8 */ u32 mTime;
} GpiTransferId;

// Output buffer description built by GpiPeerQueueMessage.
typedef struct GPIMessage {
    /* 00 */ GpiBuffer mBuffer;
    /* 10 */ s32 mType;
    /* 14 */ u32 mStart;
} GPIMessage;

u32 GpiCreateOperation(GpConnection *connection, int type, void *data, GpiOperation **operationOut, int blocking,
                       GpiCallbackFn callback, int param);

#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"


s32 GpiPeerSendLenMsg(GpConnection *connection, GpiPeer *peer, const char *message, s32 len);
u32 GpiPeerSendXfer(GpConnection *connection, GpiPeer *peer, u32 type, GpiTransferId *transferID);
s32 GpiPeerQueueMessage(GpConnection *connection, GpiPeer *peer, u32 type, const char *message);
s32 GpiPeerConnect(GpConnection *connection, GpiPeer *peer);
int gpiPeerGetSig(GpConnection *connection, GpiPeer *peer);
GpiPeer *GpiPeerCreate(GpConnection *connection, u32 profileid, u32 initiate);
void gpiFreeMessage(void **bufferPointer);
GpiPeer *gpiGetConnectedPeer(GpConnection *object, u32 key);
s32 GpiUpdatePeers(GpConnection *connection);
void gpiSetPeerSocketSizes(s32 sock);
void GpiPeerRemoveAndWriteQueuedMessages(GpConnection *connection, GpiPeer *peer);
void GpiPeerDelete(GpConnection *connection, GpiPeer *peer);
s32 GpiPeerUpdate(GpConnection *connection, GpiPeer *peer);
s32 gpiProcessPeerConnected(GpConnection *connection, GpiPeer *peer);
s32 gpiPeerSendMessages(GpConnection *connection, GpiPeer *peer);
s32 GpiPeerUpdateWaiting(GpConnection *connection, GpiPeer *peer);
s32 gpiProcessPeerInitiatingConnection(GpConnection *connection, GpiPeer *peer);
