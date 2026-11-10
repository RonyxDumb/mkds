#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h" // RomArchiveParentViewEntry, RomArchiveMessage

// Starts at offset 0x24 of an entry of BlockTransfer; 0x44 bytes (see WBTi_FindBitmapIndex).
typedef struct WBTPacketBitmap {
    /* 00 */ s32 mLength;
    /* 04 */ s32 mTotal;
    /* 08 */ s32 mPickedChunkIndex;
    /* 0c */ s32 mCurrent;
    /* 10 */ s32 mCount;
    /* 14 */ u32 *mBitmap;
    /* 18 */ u8 *mBuffer;
    /* 1c */ u8 mInlineChunkBitmap[0x28];
} WBTPacketBitmap;

// Entry of BlockTransfer; 0x68 bytes.
typedef struct BlockTransferEntry {
// 1 at rest; 2 while a parsed request waits for its reply.
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mPacketKind;
    /* 02 */ u8 mRequestId;
    /* 03 */ u8 mLastCallbackId;
    /* 04 */ s16 mPacketReceiveChunkSize;
    /* 06 */ s16 mPacketSendChunkSize;
    /* 08 */ u16 mIndexMask;
    /* 0a */ s16 mBlockCount;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mByteCount;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u32 mBlockId;
    /* 14 */ u32 mChunkIndex;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ u8 *mPayload;
    /* 24 */ WBTPacketBitmap mReceive;
} BlockTransferEntry;

// Tail of a WBTCommand from 0x14, which the kinds of request fill in different ways.
typedef union Unk0204c320_14 {
    u32 mUnk_w;
    struct {
        s16 mUnk_14;
        s16 mUnk_16;
        s16 mUnk_18;
    } h;
    RomArchiveParentViewEntry mUnk_0e;
    RomArchiveMessage mUnk_m;
    struct {
        u32 mUnk_14;
        u32 mUnk_18;
        u32 mUnk_1c[16];
    } w;
    struct {
        u8 mUnk_14[9];
        u8 mUnk_1d;
        u8 mUnk_1e[2];
        s16 mUnk_20;
    } b;
} Unk0204c320_14;

struct WBTCommand;

// Block of 0x9c bytes; BlockTransfer holds three of them.
typedef struct WBTCommand {
    /* 00 */ s32 mCommand;
    /* 04 */ s32 mEvent;
    /* 08 */ u16 mTargetBmp;
    /* 0a */ u16 mPeerBmp;
    /* 0c */ u8 mMyCmdCounter;
    /* 0d */ u8 mPeerCmdCounter;
    /* 0e */ u16 mResult;
    /* 10 */ void (*mCallback)(struct WBTCommand *);
// In mCallbackRecord, words 0x14 to 0x1c carry what the callback code brings: counts and chunk sizes, a block id
// and chunk, or up to 9 bytes with their length at 0x1d.
    /* 14 */ Unk0204c320_14 mUnk_14;
    /* 5c */ void *mChunkBitmaps[16];
} WBTCommand;

// Object at gBlockTransfer; 0x854 bytes.
typedef struct BlockTransfer {
    /* 000 */ WBTCommand mCurrentRequest;
    /* 09c */ WBTCommand mNextRequest;
    /* 138 */ WBTCommand mCallbackRecord;
    /* 1d4 */ BlockTransferEntry mEntries[16];
} BlockTransfer;

s32 WBTi_SwitchNextCommand(BlockTransfer *a, u8 *b, s32 c);
s32 WBTi_CheckRequest(BlockTransfer *a, u8 *b, s32 c);
s32 ReplyToBlockNodeRequestAlways(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToBlockNodeRequest(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToBlockDataRequest(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToBytesPacket(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToNoMissingChunk(BlockTransfer *a, s32 b, u8 *c, s32 d);
s32 ReplyToBlockCountRequest(BlockTransfer *a, s32 b, u8 *c, s32 d);
u32 WBT_CallPacketRecvHook(BlockTransfer *a, s32 b, const u8 *c, s32 d);
void WBTi_NotifyCompletionCallback(BlockTransfer *a, s32 b, s32 c);
void WBTi_NotifySystemCallback(BlockTransfer *a, s32 b, s32 c, u32 d);
BOOL StoreReceivedChunk(WBTPacketBitmap *a, s32 b, const u8 *c);
s32 WBTi_FindBitmapIndex(WBTPacketBitmap *a);
