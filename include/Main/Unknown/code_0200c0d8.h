#pragma once

#include "types.h"

// Six bytes that MBi_SetRecvBufferFromParent fills and WriteParentMessage writes out.
typedef struct ParentMessage {
    /* 0 */ u8 mKind;
    /* 1 */ u8 field1;
    /* 2 */ u16 field2;
    /* 4 */ u16 field4;
} ParentMessage;

// 0x14 bytes that WriteChildMessage writes out and ReadChildMessage fills; the bytes from 3 or 4 on are moved from or
// to the entry in the word at gPieceSizes.
typedef struct ChildMessage {
    /* 00 */ u8 mKind;
    /* 01 */ u8 field1;
    /* 02 */ u16 field2;
    /* 04 */ u8 field4[0x10];
} ChildMessage;

// 0x20-byte entry that CopyNextPiece copies.
typedef struct Unk0200c12c {
    /* 00 */ u32 field0;
    /* 04 */ u8 field4[0x16];
    /* 1a */ u16 field1A;
    /* 1c */ u8 field1C;
    /* 1d */ u8 field1D[3];
} Unk0200c12c;

u8 *MBi_SetRecvBufferFromParent(ParentMessage *message, u8 *buffer);
u8 CopyNextPiece(void *output, void *pieces);
u8 *WriteChildMessage(ChildMessage *message, u8 *buffer);
u32 AreAllPiecesReceived(u32 child);
u8 *StorePiece(ChildMessage *message, u32 child);
u8 *ReadChildMessage(u8 *bytes, ChildMessage *message, u32 child);
u8 *WriteParentMessage(u8 *input, u8 *output);
void ClearChildPieces(s32 child);
void SetupPieceBuffer(u32 buffer);
void SetupPieceSizes(s32 packetSize);
