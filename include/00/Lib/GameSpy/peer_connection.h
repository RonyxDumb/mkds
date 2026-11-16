#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/profile_search.h"

// Buffers made by gpiFailedOpCallback, one for each request type; the first word is taken from the request.
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

typedef struct RegisterUniqueNickReply {
    /* 0 */ s32 mResult;
} RegisterUniqueNickReply;

// Three words printed by gpiPeerStartTransferMessage.
typedef struct GPITransferID {
    /* 0 */ u32 mProfileId;
    /* 4 */ u32 mCount;
    /* 8 */ u32 mTime;
} GPITransferID;

// Output buffer description built by gpiPeerAddMessage.
typedef struct GPIMessage {
    /* 00 */ GPIBuffer mBuffer;
    /* 10 */ s32 mType;
    /* 14 */ u32 mStart;
} GPIMessage;

u32 gpiAddOperation(GPConnection *connection, int type, void *data, GPIOperation **operationOut, int blocking,
                       GPCallback callback, int param);

#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/GameSpy/socket_calls.h"


s32 gpiPeerFinishTransferMessage(GPConnection *connection, GPIPeer *peer, const char *message, s32 len);
u32 gpiPeerStartTransferMessage(GPConnection *connection, GPIPeer *peer, u32 type, GPITransferID *transferID);
s32 gpiPeerAddMessage(GPConnection *connection, GPIPeer *peer, u32 type, const char *message);
s32 gpiPeerStartConnect(GPConnection *connection, GPIPeer *peer);
int gpiPeerGetSig(GPConnection *connection, GPIPeer *peer);
GPIPeer *gpiAddPeer(GPConnection *connection, u32 profileid, u32 initiate);
void gpiFreeMessage(void **bufferPointer);
GPIPeer *gpiGetConnectedPeer(GPConnection *object, u32 key);
s32 gpiProcessPeers(GPConnection *connection);
void gpiSetPeerSocketSizes(s32 sock);
void gpiRemovePeer(GPConnection *connection, GPIPeer *peer);
void gpiDestroyPeer(GPConnection *connection, GPIPeer *peer);
s32 gpiProcessPeer(GPConnection *connection, GPIPeer *peer);
s32 gpiProcessPeerConnected(GPConnection *connection, GPIPeer *peer);
s32 gpiPeerSendMessages(GPConnection *connection, GPIPeer *peer);
s32 gpiProcessPeerAcceptingConnection(GPConnection *connection, GPIPeer *peer);
s32 gpiProcessPeerInitiatingConnection(GPConnection *connection, GPIPeer *peer);
