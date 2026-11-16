#include "Main/Net/append_bytes.h"
#include "Main/Net/wireless_block_requests.h"
#include "Main/Net/wireless_block_transfer.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "cpu_copy_fill.h"

u32 gLastSentBlockId = 0xffffffff;
s32 gLastSentChunkIndex = -1;
s32 gPrevSentChunkIndex = -1;

#pragma thumb on

static inline u8 *AppendBytes(const void *source, u8 *cursor, u32 byteCount) {
    Mem_CpuCopy8(source, cursor, byteCount);
    return cursor + byteCount;
}

u32 WBT_MpChildSendHook(u8 *buffer, s32 bufferSize) {
    if (bufferSize > 0 && buffer != NULL) {
        BuildChildPacketUnchecked(buffer, bufferSize);
    }
}

void WBT_MpChildRecvHook(const u8 *packet, u32 size) {
    if (packet != NULL && size != 0 && size != 0xffff) {
        ReceiveParentPacket(packet, size);
    }
}

// Packet kind 1: the header and one byte, sent when nothing else is waiting.
s32 WriteEmptyPacket(u8 *buffer, u16 indexMask, u8 requestId) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_FILLER;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    Mem_CpuCopy8(&requestId, cursor, 1);
    return cursor + 1 - buffer;
}

// Packet kind 2: asks for the block count and carries both chunk sizes.
s32 WriteBlockCountRequestPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 sendChunkSize, u32 receiveChunkSize) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_HANDSHAKE_ASK;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    cursor = AppendBytes(&requestId, cursor, 1);
    cursor = AppendBytes(&sendChunkSize, cursor, 2);
    Mem_CpuCopy8(&receiveChunkSize, cursor, 2);
    return cursor + 2 - buffer;
}

// Packet kind 3: answers kind 2 with the block count and both chunk sizes.
s32 WriteBlockCountReplyPacket(u8 *buffer, u16 indexMask, u8 requestId, s16 blockCount, u32 sendChunkSize,
                               u32 receiveChunkSize) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_HANDSHAKE_ANSWER;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    cursor = AppendBytes(&requestId, cursor, 1);
    cursor = AppendBytes(&blockCount, cursor, 2);
    cursor = AppendBytes(&sendChunkSize, cursor, 2);
    Mem_CpuCopy8(&receiveChunkSize, cursor, 2);
    return cursor + 2 - buffer;
}

// Packet kind 4: asks for one chunk of the block with this id.
s32 WriteBlockDataRequestPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId, u32 chunkIndex) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_DATA_ASK;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    cursor = AppendBytes(&requestId, cursor, 1);
    cursor = AppendBytes(&blockId, cursor, 4);
    Mem_CpuCopy8(&chunkIndex, cursor, 4);
    return cursor + 4 - buffer;
}

// Packet kind 5: one chunk of a block (zeros when no data pointer is given).
s32 WriteBlockDataPacket(u8 *buffer, u32 indexMask, u8 requestId, u32 blockId, u32 chunkIndex, u32 data, s32 dataSize) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_DATA_CHUNK;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    cursor = AppendBytes(&requestId, cursor, 1);
    cursor = AppendBytes(&blockId, cursor, 4);
    cursor = AppendBytes(&chunkIndex, cursor, 4);
    if (data == 0) {
        Mem_CpuFill8(cursor, 0, dataSize);
    } else {
        Mem_CpuCopy8((void *) data, cursor, dataSize);
    }
    return cursor + dataSize - buffer;
}

// Packet kind 6: asks for one chunk of a block node by id.
s32 WriteBlockNodeRequestPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId, u32 chunkIndex) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_LAYOUT_ASK;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    cursor = AppendBytes(&requestId, cursor, 1);
    cursor = AppendBytes(&blockId, cursor, 4);
    Mem_CpuCopy8(&chunkIndex, cursor, 4);
    return cursor + 4 - buffer;
}

// Packet kind 7: one chunk of a block node (zeros when no data pointer is given).
s32 WriteBlockNodePacket(u8 *buffer, u32 indexMask, u8 requestId, u32 blockId, u32 chunkIndex, u32 data, u32 dataSize) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_LAYOUT_ANSWER;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    cursor = AppendBytes(&requestId, cursor, 1);
    cursor = AppendBytes(&blockId, cursor, 4);
    cursor = AppendBytes(&chunkIndex, cursor, 4);
    if (data == 0) {
        Mem_CpuFill8(cursor, 0, dataSize);
    } else {
        Mem_CpuCopy8((void *) data, cursor, dataSize);
    }
    return cursor + dataSize - buffer;
}

// Packet kind 8: carries the block id; sent instead of a chunk request when no chunk of the block is missing.
s32 WriteNoMissingChunkPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_ALL_HELD;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    cursor = AppendBytes(&requestId, cursor, 1);
    Mem_CpuCopy8(&blockId, cursor, 4);
    return cursor + 4 - buffer;
}

// Packet kind 9: answers kind 8 with the block id.
s32 WriteNoMissingChunkReplyPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_ALL_HELD_ANSWER;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    cursor = AppendBytes(&requestId, cursor, 1);
    Mem_CpuCopy8(&blockId, cursor, 4);
    return cursor + 4 - buffer;
}

// Packet kind 10: up to 9 raw bytes and their length.
s32 WriteBytesPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 *bytes, u32 byteCount) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_CUSTOM;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    cursor = AppendBytes(&requestId, cursor, 1);
    cursor = AppendBytes(&byteCount, cursor, 1);
    Mem_CpuCopy8(bytes, cursor, 9);
    return cursor + 9 - buffer;
}

// Packet kind 11: answers kind 10.
s32 WriteBytesReplyPacket(u8 *buffer, u16 indexMask, u8 requestId) {
    struct {
        u8 mKind;
        u16 mIndexMask;
    } header;
    u8 *cursor;
    cursor = buffer;
    header.mIndexMask = indexMask;
    header.mKind = XFER_PACKET_CUSTOM_ANSWER;
    cursor = AppendBytes(&header, cursor, 1);
    cursor = AppendBytes(&header.mIndexMask, cursor, 2);
    Mem_CpuCopy8(&requestId, cursor, 1);
    return cursor + 1 - buffer;
}

// Picks the chunk to send next: skips the last two indexes sent for this block; -1 for an unknown id.
s32 PickSendChunkIndex(u32 blockId, s32 chunkIndex) {
    WBTBlockInfoList *node;
    s32 skipCount;
    node = GetGlobalGO_from_thumb();
    if (blockId < 1000) {
        return chunkIndex;
    }
    for (; node != NULL; node = node->mNext) {
        if (node->mDataInfo.mId == blockId) {
            if (blockId == gLastSentBlockId) {
                skipCount = 0;
                while (chunkIndex == gLastSentChunkIndex || chunkIndex == gPrevSentChunkIndex) {
                    chunkIndex++;
                    if (chunkIndex > (node->mDataInfo.mBlockSize + (s32) WBT_GetOwnPacketLength() - 1) /
                                             (s32) WBT_GetOwnPacketLength() -
                                         1) {
                        chunkIndex = 0;
                    }
                    skipCount++;
                    if (skipCount > 2) {
                        break;
                    }
                }
            }
            gLastSentBlockId = blockId;
            gPrevSentChunkIndex = gLastSentChunkIndex;
            gLastSentChunkIndex = chunkIndex;
            return chunkIndex;
        }
    }
    return -1;
}

// Address of one chunk; ids under 1000 count positions in the block list, higher ids are block ids.
u32 WBTi_GetPacketBuffer(u32 blockIdOrPosition, u32 chunkIndex) {
    WBTBlockInfoList *blockPointer;
    u32 blockPosition;
    blockPointer = GetGlobalGO_from_thumb();
    if (blockIdOrPosition < 1000) {
        for (blockPosition = 0;; blockPosition++, blockPointer = blockPointer->mNext) {
            if (blockPointer == NULL) {
                break;
            }
            if (blockPosition == blockIdOrPosition) {
                return (u32) blockPointer + chunkIndex * WBT_GetOwnPacketLength();
            }
        }
        return 0;
    }
    for (; blockPointer != NULL; blockPointer = blockPointer->mNext) {
        if (blockPointer->mDataInfo.mId == blockIdOrPosition) {
            blockPointer = (WBTBlockInfoList *) blockPointer->mDataPtr;
            return (u32) blockPointer + chunkIndex * WBT_GetOwnPacketLength();
        }
    }
    return 0;
}

void WBTi_InitBitmap(WBTPacketBitmap *state, s32 size, void *chunkBitmap, u32 buffer) {
    s32 chunkSize;
    chunkSize = WBT_GetPeerPacketLength();
    state->mLength = size;
    state->mPickedChunkIndex = 0;
    state->mCurrent = 0;
    state->mCount = 0;
    state->mTotal = size / chunkSize + ((size % chunkSize) != 0 ? 1 : 0);
    state->mBitmap = chunkBitmap;
    state->mBuffer = (u8 *) buffer;
    Mem_CpuFill8(chunkBitmap, 0, WBT_CalcPacketbitmapSize(size));
}

BOOL IsChunkReceived(WBTPacketBitmap *state, s32 chunkIndex) {
    u32 bitmapWord;
    bitmapWord = state->mBitmap[chunkIndex >> 5];
    if ((bitmapWord & (1 << (chunkIndex & 0x1f))) != 0) {
        return TRUE;
    }
    return FALSE;
}

#pragma thumb off
