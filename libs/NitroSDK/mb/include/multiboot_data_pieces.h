#pragma once

#include "types.h"
#include "multiboot_piece_buffers.h"

typedef struct MbRequestPieceBuf MbRequestPieceBuf;

// Bytes of one child MP exchange that hold pieces; MBi_SetChildMPMaxSize divides it by the piece size.
#define MULTIBOOT_CHILD_MP_BUFFER_SIZE 0x1e

// ParentMessage.mKind.
typedef enum ParentMessageKind {
    PARENT_MESSAGE_LISTENING = 1,
    PARENT_MESSAGE_TURNED_DOWN = 2,
    PARENT_MESSAGE_WELCOMED = 3,
    PARENT_MESSAGE_BEGIN_SEND = 4,
    PARENT_MESSAGE_SEND_FINISHED = 5,
    PARENT_MESSAGE_GAVE_UP = 6,
} ParentMessageKind;

// ChildMessage.mKind.
typedef enum ChildMessageKind {
    CHILD_MESSAGE_NONE = 0,
    CHILD_MESSAGE_REQUEST = 7,
    CHILD_MESSAGE_ACCEPT_ACK = 8,
    CHILD_MESSAGE_ACK_WITH_DATA = 9,
    CHILD_MESSAGE_START_ACK = 10,
    CHILD_MESSAGE_DONE_ACK = 11,
} ChildMessageKind;

// Six bytes that MBi_SetRecvBufferFromParent fills and MBi_MakeParentSendBuffer writes out.
typedef struct ParentMessage {
    /* 0 */ u8 mKind;
    /* 1 */ u8 mPad1;
    /* 2 */ u16 mFid;
    /* 4 */ u16 mSeqno;
} ParentMessage;

// 0x14 bytes that MBi_MakeChildSendBuffer writes out and MBi_SetRecvBufferFromChild fills; the bytes from 3 or 4 on are
// moved from or to the entry in the word at gPieceSizes.
typedef struct ChildMessage {
    /* 00 */ u8 mKind;
    /* 01 */ u8 mPad1;
    union {
        struct {
            /* 02 */ u16 mPieceRequest;
            /* 04 */ u8 mData[0x10];
        };
        struct {
            /* 02 */ u8 mPieceRequestByte;
            /* 03 */ u8 mPieceData[0x11];
        };
    };
} ChildMessage;

// 0x20-byte entry that MBi_SendRequestDataPiece copies.
typedef struct MBCommRequestData {
    /* 00 */ u32 mGgid;
    /* 04 */ u8 mUserInfo[0x16];
    /* 1a */ u16 mVersion;
    /* 1c */ u8 mFileId;
    /* 1d */ u8 mUnk_1d[3];
} MBCommRequestData;

u8 *MBi_SetRecvBufferFromParent(ParentMessage *message, u8 *buffer);
u8 MBi_SendRequestDataPiece(void *output, void *pieces);
u8 *MBi_MakeChildSendBuffer(ChildMessage *message, u8 *buffer);
u32 IsGetAllRequestData(u32 child);
u8 *MBi_ReceiveRequestDataPiece(ChildMessage *message, u32 child);
u8 *MBi_SetRecvBufferFromChild(u8 *bytes, ChildMessage *message, u32 child);
u8 *MBi_MakeParentSendBuffer(ParentMessage *message, u8 *output);
void MBi_ClearParentPieceBuffer(s32 child);
void MBi_SetParentPieceBuffer(MbRequestPieceBuf *buffer);
void MBi_SetChildMPMaxSize(s32 packetSize);

extern u8 gLastPieceIndex;
extern struct MbRequestPieceBuf *gPieceBuffer;
extern PieceSizes gPieceSizes;
