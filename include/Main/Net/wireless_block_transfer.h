#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h" // RomArchiveParentViewEntry, RomArchiveMessage
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"

// WBTCommand.mCommand.
typedef enum WBTCommandKind {
    XFER_COMMAND_UNUSED = 0, // no request in the slot: none running in mCurrentRequest, none waiting in mNextRequest
    XFER_COMMAND_HANDSHAKE = 2,
    XFER_COMMAND_FETCH_DATA = 4,
    XFER_COMMAND_FETCH_DETAILS = 6,
    XFER_COMMAND_SEND_CUSTOM = 10,
    XFER_COMMAND_HOOK_RECORD = 12, // only the callback record carries it
} WBTCommandKind;

// WBTCommand.mEvent. Values 2, 3, 8, 10 and 11 are the packet kinds that raise them; 5 and 7 are raised when the
// no-missing-chunk answer ends a data or info request; 13 comes before a chunk is sent and 15 is a failure; 1, 4, 6, 9,
// 12 and 14 are never raised.
typedef enum WBTEventKind {
    XFER_EVENT_NOTHING = 0,
    XFER_EVENT_QUIET = 1,
    XFER_EVENT_HANDSHAKE_ASKED = 2,
    XFER_EVENT_HANDSHAKE_ENDED = 3,
    XFER_EVENT_DATA_ASKED = 4,
    XFER_EVENT_DATA_ENDED = 5,
    XFER_EVENT_LAYOUT_ASKED = 6,
    XFER_EVENT_LAYOUT_ENDED = 7,
    XFER_EVENT_ALL_CHUNKS_HELD = 8,
    XFER_EVENT_ALL_CHUNKS_ANSWER = 9,
    XFER_EVENT_CUSTOM_ARRIVED = 10,
    XFER_EVENT_CUSTOM_ENDED = 11,
    XFER_EVENT_UNUSED_12 = 12, // never raised
    XFER_EVENT_BEFORE_SEND = 13,
    XFER_EVENT_UNUSED_14 = 14, // never raised
    XFER_EVENT_FAILED = 15, // the callback record's result says why
} WBTEventKind;

// BlockTransferEntry.mPacketKind: the first byte of a packet.
typedef enum WBTPacketKind {
    XFER_PACKET_FILLER = 1,
    XFER_PACKET_HANDSHAKE_ASK = 2,
    XFER_PACKET_HANDSHAKE_ANSWER = 3,
    XFER_PACKET_DATA_ASK = 4,
    XFER_PACKET_DATA_CHUNK = 5,
    XFER_PACKET_LAYOUT_ASK = 6,
    XFER_PACKET_LAYOUT_ANSWER = 7,
    XFER_PACKET_ALL_HELD = 8,
    XFER_PACKET_ALL_HELD_ANSWER = 9,
    XFER_PACKET_CUSTOM = 10,
    XFER_PACKET_CUSTOM_ANSWER = 11,
} WBTPacketKind;

// WBTCommand.mResult of the callback record: OK for a normal event, else why the failed event was raised.
typedef enum WBTResultKind {
    XFER_RESULT_OK = 0,
    XFER_RESULT_KIND_REJECTED = 3,
    XFER_RESULT_STEP_REJECTED = 4,
    XFER_RESULT_CUT_SHORT = 5,
    XFER_RESULT_CHUNK_BEYOND_END = 6,
} WBTResultKind;

// Steps of WBT_CallPacketRecvHook; each reads the field its name gives, in an order that depends on the packet kind.
typedef enum WBTParseStep {
    XFER_PARSE_KIND_FIELD = 1,
    XFER_PARSE_MASK_FIELD = 2,
    XFER_PARSE_ASK_NUMBER = 3,
    XFER_PARSE_TOTAL_FIELD = 4,
    XFER_PARSE_SIZE_LIST = 5,
    XFER_PARSE_TARGET_FIELD = 7,
    XFER_PARSE_SLICE_NUMBER = 8,
    XFER_PARSE_BODY = 9,
    XFER_PARSE_LENGTH_FIELD = 10,
} WBTParseStep;

// Values of BlockTransferEntry.mReplyPending.
typedef enum WBTEntryState {
    XFER_ENTRY_FREE = 1,
    XFER_ENTRY_AWAITING_ANSWER = 2,
} WBTEntryState;

// Which chunks of a block have arrived: mLength, mTotal and mCount, the last received (mCurrent) and picked chunk
// index, the bitmap and the buffer.
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

static inline u32 *GetPacketBitmapWord(WBTPacketBitmap *bitmap, s32 chunkIndex) {
    return &bitmap->mBitmap[chunkIndex >> 5];
}

// One block transfer slot: its state, packet kind, request id, chunk sizes, block id, payload and receive bitmap.
typedef struct BlockTransferEntry {
// 1 at rest; 2 while a parsed request waits for its reply.
    /* 00 */ u8 mState;
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

// Most bytes of user data one custom packet carries, and the size of the block information a details request
// (WBT_GetBlockInfo) receives.
#define BLOCK_TRANSFER_USER_DATA_MAX_BYTES 9
#define BLOCK_TRANSFER_BLOCK_INFO_BYTES 0x28

// The tail of a WBTCommand: the arguments of a request or, in mCallbackRecord, what an event brings.
typedef union WBTCommandData {
    struct {
        s16 mNumOfList;
        s16 mPeerPacketSize;
        s16 mMyPacketSize;
    } mSync;
    struct {
        u32 mBlockId;
    } mBlockDone;
    struct {
        u32 mBlockId;
        s32 mBlockSeqNo;
        u32 mDataPtr;
        s16 mOwnPacketSize;
    } mPrepareSendData;
    struct {
        u8 mData[BLOCK_TRANSFER_USER_DATA_MAX_BYTES];
        u8 mSize;
    } mUserData;
    u32 mUserDataWord;
    struct {
        u32 mBlockId;
        u32 mRecvDataSize;
        u32 mRecvBuf[16];
        void *mPktBmp[16];
    } mGet;
    RomArchiveParentViewEntry mArchiveParentViewEntry;
    RomArchiveMessage mArchiveMessage;
} WBTCommandData;

struct WBTCommand;

// A block transfer command: the command and event, target and peer bitmaps, counters, result, callback and data.
typedef struct WBTCommand {
    /* 00 */ s32 mCommand;
    /* 04 */ s32 mEvent;
    /* 08 */ u16 mTargetBmp;
    /* 0a */ u16 mPeerBmp;
    /* 0c */ u8 mMyCmdCounter;
    /* 0d */ u8 mPeerCmdCounter;
    /* 0e */ u16 mResult;
    /* 10 */ void (*mCallback)(struct WBTCommand *);
    // In mCallbackRecord, the data carries what WBTi_NotifySystemCallback fills in: the block count and both chunk
    // sizes (XFER_EVENT_HANDSHAKE_ASKED), a block id (XFER_EVENT_ALL_CHUNKS_HELD), or up to 9 bytes with their length
    // (XFER_EVENT_CUSTOM_ARRIVED, length 0 when more than 9 arrived).
    /* 14 */ WBTCommandData mData;
} WBTCommand;

// The block transfer state: the current, next and callback commands and the sixteen transfer slots.
typedef struct BlockTransfer {
    /* 000 */ WBTCommand mCurrentRequest;
    /* 09c */ WBTCommand mNextRequest;
    /* 138 */ WBTCommand mCallbackRecord;
    /* 1d4 */ BlockTransferEntry mEntries[16];
} BlockTransfer;

s32 WBTi_SwitchNextCommand(BlockTransfer *transfer, u8 *buffer, s32 bufferSize);
s32 WBTi_CheckRequest(BlockTransfer *transfer, u8 *buffer, s32 bufferSize);
s32 ReplyToBlockNodeRequestAlways(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize);
s32 ReplyToBlockNodeRequest(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize);
s32 ReplyToBlockDataRequest(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize);
s32 ReplyToBytesPacket(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize);
s32 ReplyToNoMissingChunk(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize);
s32 ReplyToBlockCountRequest(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize);
u32 WBT_CallPacketRecvHook(BlockTransfer *transfer, s32 entryIndex, const u8 *cursor, s32 packetSize);
void WBTi_NotifyCompletionCallback(BlockTransfer *transfer, s32 event, s32 entryIndex);
void WBTi_NotifySystemCallback(BlockTransfer *transfer, s32 event, s32 entryIndex, u32 result);
BOOL StoreReceivedChunk(WBTPacketBitmap *bitmap, s32 chunkIndex, const u8 *chunkData);
s32 WBTi_FindBitmapIndex(WBTPacketBitmap *bitmap);
