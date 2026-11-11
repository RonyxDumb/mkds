#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_0218e8d4.h"

// Payload at 0x04 of a GpiOperation whose 0x00 is 3.
typedef struct Unk02193858 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ void *mUnk_18;
} Unk02193858;

// Buffers made by GpiQueueOperationCallback, one for each request type; the first word is taken from the request.
typedef struct ConnectReply {
    /* 00 */ s32 mResult;
    /* 04 */ u32 mProfile;
    /* 08 */ u8 mUnk_08[0x18];
} ConnectReply;

typedef struct NewProfileReply {
    /* 0 */ s32 mUnk_00;
    /* 4 */ u8 mUnk_04[4];
} NewProfileReply;

typedef struct ProfileSearchReply {
    /* 0 */ s32 mUnk_00;
    /* 4 */ s32 mUnk_04;
    /* 8 */ s32 mUnk_08;
    /* c */ Unk0219c400Entry *mUnk_0c;
} ProfileSearchReply;

typedef struct RegisterNickReply {
    /* 0 */ s32 mUnk_00;
} RegisterNickReply;

// Three words printed by GpiPeerSendXfer.
typedef struct GpiTransferId {
    /* 0 */ u32 mUnk_00;
    /* 4 */ u32 mUnk_04;
    /* 8 */ u32 mUnk_08;
} GpiTransferId;

// Output buffer description built by GpiPeerQueueMessage.
typedef struct GPIMessage {
    /* 00 */ GpiBuffer mBuffer;
    /* 10 */ u32 mType;
    /* 14 */ u32 mStart;
} GPIMessage;

// Address passed to connect by GpiPeerConnect.
typedef struct Unk02193d64 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk02193d64;

u32 GpiCreateOperation(GpConnection *connection, int type, int data, int *operationOut, int blocking, int callback,
                       int param);

#include "00/code_021965a0.h"
#include "00/code_02196594.h"
#include "00/code_0218e2dc.h"

// Entry of the list behind GpiPeer.mQueuedMessages.
typedef struct Unk0219405c {
    /* 00 */ const char *mBuffer;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ s32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk0219405c;

// Message handed to GpiQueueCallback by gpiProcessPeerConnected.
typedef struct Unk021941c4Msg {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ void *mUnk_08;
} Unk021941c4Msg;

// Entry of the list at 0x38 of GpiPeer.
typedef struct Unk02194370Entry {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mLength;
    /* 0c */ u32 mPos;
} Unk02194370Entry;

extern s8 gPeerBufferName[];
extern u8 data_ov000_021b3494[];
extern char gPongMessageText[];
extern char gPeerWaitingAssertion[];
extern char data_ov000_021b34c8[];
extern char gAuthStatement[];
extern char data_ov000_021b34d8[];
extern char data_ov000_021b34e0[];
extern char data_ov000_021b34e8[];
extern char gSigHashFormat[];
extern char gAnackStatement[];
extern char gAackStatement[];
extern u8 gPeerAuthorizationErrorString[];
extern u8 gPeerMessageParseErrorString[];

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
s32 gpiProcessPeerConnected(GpConnection *param_1, GpiPeer *param_2);
s32 gpiPeerSendMessages(GpConnection *connection, GpiPeer *peer);
s32 GpiPeerUpdateWaiting(GpConnection *param_1, GpiPeer *param_2);
s32 gpiProcessPeerInitiatingConnection(GpConnection *param_1, GpiPeer *param_2);
