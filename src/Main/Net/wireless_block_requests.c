#include "Main/Net/wireless_block_requests.h"

#include "Main/Net/append_bytes.h"
#include "Main/Net/request_id.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"

u32 gOwnIndex = 0xffffffff;
s32 gLastReplyIndex = 1;
u8 gRequestId[1];
s16 gReceiveChunkSize;
s16 gSendChunkSize;
struct WBTBlockInfoList *g_GlobalGO;
BlockTransfer gBlockTransfer;

#pragma thumb on

u32 WBT_GetPeerPacketLength(void) {
    return (gReceiveChunkSize);
}

u32 WBT_GetOwnPacketLength(void) {
    return (gSendChunkSize);
}

void SetReceiveChunkSize(u32 chunkSize) {
    gReceiveChunkSize = (u16) chunkSize;
}

void SetSendChunkSize(u32 chunkSize) {
    gSendChunkSize = (u16) chunkSize;
}

BlockTransfer *GetBlockTransfer(void) {
    return &gBlockTransfer;
}

WBTCommand *GetNextRequestAddress(void) {
    return &gBlockTransfer.mNextRequest;
}

#pragma thumb off

#pragma thumb on

u32 TrySetNextRequest(const WBTCommand *request) {
    u32 savedInterrupts;
    WBTCommand *nextRequest;
    savedInterrupts = Os_DisableIrq();
    if (wbt_initialize_flag != 1) {
        Os_RestoreIrq(savedInterrupts);
        return 0;
    }
    nextRequest = GetNextRequestAddress();
    if (nextRequest == NULL || nextRequest->mCommand != XFER_COMMAND_UNUSED) {
        Os_RestoreIrq(savedInterrupts);
        return 0;
    }
    Mem_CpuCopy32(request, &gBlockTransfer.mNextRequest, 0x9c);
    Os_RestoreIrq(savedInterrupts);
    return 1;
}

#pragma thumb off

#pragma thumb on

WBTBlockInfoList *GetGlobalGO_from_thumb(void) {
    return g_GlobalGO;
}

void SetGlobalGO_from_thumb(WBTBlockInfoList *head) {
    g_GlobalGO = head;
}

#pragma thumb off

#pragma thumb on

WBTBlockInfoList *FindGlobalGOBy_from_thumb(u32 blockId) {
    WBTBlockInfoList *node;
    for (node = GetGlobalGO_from_thumb(); node != NULL; node = node->mNext) {
        if (node->mDataInfo.mId == blockId) {
            return node;
        }
    }
    return NULL;
}

#pragma thumb off

#pragma thumb on

void WBT_SetOwnAid(u32 index) {
    gOwnIndex = index;
}

u32 WBT_GetOwnAid(void) {
    return gOwnIndex;
}

#pragma thumb off

#pragma thumb on

s32 WBT_AidbitmapToAid(s32 mask) {
    s32 aid;
    for (aid = 0; aid < 16; aid++) {
        if (((mask >> aid) & 1) != 0) {
            return aid;
        }
    }
    return -1;
}

u32 WBT_CalcPacketbitmapSize(s32 size) {
    s32 chunkSize;
    s32 chunkCount;
    chunkSize = WBT_GetPeerPacketLength();
    chunkCount = size / chunkSize + ((size % chunkSize) != 0 ? 1 : 0);
    return ((chunkCount >> 5) + ((chunkCount & 0x1f) != 0 ? 1 : 0)) << 2;
}

BOOL WBT_GetCurrentDownloadProgress(u32 blockId, s32 entryIndex, s32 *receivedChunkCountOut, s32 *chunkCountOut) {
    BlockTransfer *transfer;
    WBTPacketBitmap *receive;
    transfer = GetBlockTransfer();
    receive = &transfer->mEntries[entryIndex].mReceive;
    if (transfer->mCurrentRequest.mCommand == XFER_COMMAND_FETCH_DATA &&
        transfer->mCurrentRequest.mData.mGet.mBlockId == blockId) {
        *chunkCountOut = receive->mTotal;
        *receivedChunkCountOut = receive->mCount;
        return TRUE;
    }
    return FALSE;
}

u32 WBT_SetPacketSize(s32 sendSize, s32 receiveSize) {
    switch (GetBlockTransfer()->mCurrentRequest.mCommand) {
        case XFER_COMMAND_FETCH_DATA:
        case XFER_COMMAND_FETCH_DETAILS:
            return 0;
    }
    SetSendChunkSize(sendSize - 0xe);
    SetReceiveChunkSize(receiveSize - 0xe);
    return 1;
}

#pragma thumb off

#pragma thumb on

int WBT_NumOfRegisteredBlock(void) {
    int count;
    WBTBlockInfoList *node;
    count = 0;
    for (node = GetGlobalGO_from_thumb(); node != NULL; node = node->mNext) {
        count = count + 1;
    }
    return count;
}

#pragma thumb off

#pragma thumb on

s32 StructGO_SomeFn_from_thumb(WBTBlockInfoList *node, u32 blockId, const void *info, u8 *data, u32 size, u16 permissionBmp) {
    WBTBlockInfoList *lastNode;
    u32 savedInterrupts;
    savedInterrupts = Os_DisableIrq();
    if (GetGlobalGO_from_thumb() == NULL) {
        SetGlobalGO_from_thumb(node);
    } else {
        for (lastNode = GetGlobalGO_from_thumb(); lastNode->mNext != NULL; lastNode = lastNode->mNext) {
        }
        lastNode->mNext = node;
    }
    if (data == NULL) {
        node->mBlockType = XFER_BLOCK_TYPE_SUPPLIED;
    } else {
        node->mDataPtr = data;
        node->mBlockType = XFER_BLOCK_TYPE_MEMORY;
    }
    node->mNext = NULL;
    node->mDataInfo.mId = blockId;
    node->mDataInfo.mBlockSize = size;
    node->mPermissionBmp = permissionBmp;
    if (info != NULL) {
        Mem_CpuCopy8(info, node->mDataInfo.mUserId, sizeof(node->mDataInfo.mUserId));
    } else {
        Mem_CpuFill8(node->mDataInfo.mUserId, 0, sizeof(node->mDataInfo.mUserId));
    }
    Os_RestoreIrq(savedInterrupts);
    return 1;
}

WBTBlockInfoList *WBT_UnregisterBlock(u32 blockId) {
    WBTBlockInfoList *previousBlock;
    WBTBlockInfoList *currentBlock;
    u32 savedInterrupts;
    savedInterrupts = Os_DisableIrq();
    previousBlock = GetGlobalGO_from_thumb();
    if (previousBlock == NULL) {
        Os_RestoreIrq(savedInterrupts);
        return NULL;
    }
    if (previousBlock->mDataInfo.mId == blockId) {
        SetGlobalGO_from_thumb(previousBlock->mNext);
        Os_RestoreIrq(savedInterrupts);
        return previousBlock;
    }
    for (currentBlock = previousBlock->mNext; currentBlock != NULL;
         previousBlock = currentBlock, currentBlock = currentBlock->mNext) {
        if (currentBlock->mDataInfo.mId == blockId) {
            previousBlock->mNext = currentBlock->mNext;
            Os_RestoreIrq(savedInterrupts);
            return currentBlock;
        }
    }
    Os_RestoreIrq(savedInterrupts);
    return NULL;
}

u32 WBT_RequestSync(u16 indexMask, void (*callback)(WBTCommand *)) {
    WBTCommand request;
    request.mCommand = XFER_COMMAND_HANDSHAKE;
    request.mTargetBmp = indexMask;
    request.mCallback = callback;
    return TrySetNextRequest(&request);
}

u32 WBT_GetBlockInfo(u16 indexMask, u32 blockIdOrPosition, const void *buffers, void (*callback)(WBTCommand *)) {
    WBTCommand request;
    request.mCommand = XFER_COMMAND_FETCH_DETAILS;
    request.mTargetBmp = indexMask;
    request.mCallback = callback;
    request.mData.mGet.mBlockId = blockIdOrPosition;
    request.mData.mGet.mRecvDataSize = BLOCK_TRANSFER_BLOCK_INFO_BYTES;
    Mem_CpuCopy32(buffers, request.mData.mGet.mRecvBuf, 0x40);
    return TrySetNextRequest(&request);
}

u32 WBT_GetBlock(u16 indexMask, u32 blockId, const void *buffers, u32 blockSize, const void *chunkBitmaps,
                 void (*callback)(WBTCommand *)) {
    WBTCommand request;
    request.mCommand = XFER_COMMAND_FETCH_DATA;
    request.mTargetBmp = indexMask;
    request.mCallback = callback;
    request.mData.mGet.mBlockId = blockId;
    request.mData.mGet.mRecvDataSize = blockSize;
    Mem_CpuCopy32(buffers, request.mData.mGet.mRecvBuf, 0x40);
    Mem_CpuCopy32(chunkBitmaps, request.mData.mGet.mPktBmp, 0x40);
    return TrySetNextRequest(&request);
}

u32 WBT_PutUserData(u16 indexMask, const void *bytes, s32 byteCount, void (*callback)(WBTCommand *)) {
    WBTCommand request;
    WBTCommand *requestPointer;
    if (byteCount < 0 || byteCount > 9) {
        return 0;
    }
    request.mCommand = XFER_COMMAND_SEND_CUSTOM;
    requestPointer = &request;
    requestPointer->mTargetBmp = indexMask;
    requestPointer->mCallback = callback;
    Mem_CpuCopy8(bytes, requestPointer->mData.mUserData.mData, byteCount);
    requestPointer->mData.mUserData.mSize = byteCount;
    return TrySetNextRequest(&request);
}

s32 BuildParentPacketUnchecked(u8 *buffer, s32 bufferSize) {
    BlockTransfer *transfer;
    s32 entryIndex;
    s32 packetSize;
    transfer = GetBlockTransfer();
    entryIndex = gLastReplyIndex;
    do {
        entryIndex++;
        if (entryIndex > 15) {
            entryIndex = 1;
        }
        packetSize = ReplyToBytesPacket(transfer, entryIndex, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = entryIndex;
            return packetSize;
        }
        packetSize = ReplyToBlockCountRequest(transfer, entryIndex, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = entryIndex;
            return packetSize;
        }
        packetSize = ReplyToBlockNodeRequest(transfer, entryIndex, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = entryIndex;
            return packetSize;
        }
        packetSize = ReplyToNoMissingChunk(transfer, entryIndex, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = entryIndex;
            return packetSize;
        }
    } while (entryIndex != gLastReplyIndex);
    packetSize = WBTi_CheckRequest(transfer, buffer, bufferSize);
    if (packetSize != 0) {
        return packetSize;
    }
    packetSize = WBTi_SwitchNextCommand(transfer, buffer, bufferSize);
    if (packetSize != 0) {
        return packetSize;
    }
    entryIndex = gLastReplyIndex;
    do {
        entryIndex++;
        if (entryIndex > 15) {
            entryIndex = 1;
        }
        packetSize = ReplyToBlockDataRequest(transfer, entryIndex, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = entryIndex;
            return packetSize;
        }
    } while (entryIndex != gLastReplyIndex);
    for (entryIndex = 1; entryIndex < 16; entryIndex++) {
        packetSize = ReplyToBlockNodeRequestAlways(transfer, entryIndex, buffer, bufferSize);
        if (packetSize != 0) {
            return packetSize;
        }
    }
    return WriteEmptyPacket(buffer, 0xfffe, 0);
}

#pragma thumb off

#pragma thumb on

void ReceivePacketFromIndex(u32 index, const u8 *packet, int size) {
    if (0 < size) {
        WBT_CallPacketRecvHook(GetBlockTransfer(), index, packet, size);
    }
}

void ReceiveParentPacket(const u8 *packet, u32 size) {
    WBT_CallPacketRecvHook(GetBlockTransfer(), 0, packet, size);
}

#pragma thumb off

#pragma thumb on

void BuildChildPacketUnchecked(u8 *buffer, s32 bufferSize) {
    BlockTransfer *transfer;
    transfer = GetBlockTransfer();
    if (ReplyToBytesPacket(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToBlockCountRequest(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToBlockNodeRequest(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToNoMissingChunk(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToBlockDataRequest(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (ReplyToBlockNodeRequestAlways(transfer, 0, buffer, bufferSize) != 0) {
        return;
    }
    if (WBTi_CheckRequest(transfer, buffer, bufferSize) != 0) {
        return;
    }
    if (WBTi_SwitchNextCommand(transfer, buffer, bufferSize) != 0) {
        return;
    }
    WriteEmptyPacket(buffer, 0xffff, 0);
}

void WBT_InitParent(s32 sendSize, s32 receiveSize, void (*callback)(WBTCommand *)) {
    WBTCommand request;
    BlockTransfer *transfer;
    s32 entryIndex;
    u32 savedInterrupts;
    savedInterrupts = Os_DisableIrq();
    if (wbt_initialize_flag == 1) {
        Os_RestoreIrq(savedInterrupts);
        return;
    }
    wbt_initialize_flag = 1;
    WBT_SetOwnAid(0);
    SetGlobalGO_from_thumb(NULL);
    transfer = GetBlockTransfer();
    transfer->mCurrentRequest.mCommand = XFER_COMMAND_UNUSED;
    transfer->mCurrentRequest.mTargetBmp = 0;
    transfer->mCurrentRequest.mPeerBmp = 0;
    transfer->mCurrentRequest.mCallback = NULL;
    transfer->mCallbackRecord.mCommand = XFER_COMMAND_UNUSED;
    transfer->mCallbackRecord.mTargetBmp = 0;
    transfer->mCallbackRecord.mPeerBmp = 0;
    transfer->mCallbackRecord.mCallback = callback;
    for (entryIndex = 0; entryIndex < 16; entryIndex++) {
        transfer->mEntries[entryIndex].mLastCallbackId = 0;
    }
    request.mCommand = XFER_COMMAND_UNUSED;
    TrySetNextRequest(&request);
    ResetRequestId();
    SetSendChunkSize(sendSize - 0xe);
    SetReceiveChunkSize(receiveSize - 0xe);
    Os_RestoreIrq(savedInterrupts);
}

void WBT_InitChild(void (*callback)(WBTCommand *)) {
    WBTCommand request;
    BlockTransfer *transfer;
    s32 entryIndex;
    u32 savedInterrupts;
    savedInterrupts = Os_DisableIrq();
    if (wbt_initialize_flag == 1) {
        Os_RestoreIrq(savedInterrupts);
        return;
    }
    wbt_initialize_flag = 1;
    WBT_SetOwnAid(-1);
    SetGlobalGO_from_thumb(NULL);
    transfer = GetBlockTransfer();
    transfer->mCurrentRequest.mCommand = XFER_COMMAND_UNUSED;
    transfer->mCurrentRequest.mTargetBmp = 0;
    transfer->mCurrentRequest.mPeerBmp = 0;
    transfer->mCurrentRequest.mCallback = NULL;
    transfer->mCallbackRecord.mCommand = XFER_COMMAND_UNUSED;
    transfer->mCallbackRecord.mTargetBmp = 0;
    transfer->mCallbackRecord.mPeerBmp = 0;
    transfer->mCallbackRecord.mCallback = callback;
    for (entryIndex = 0; entryIndex < 16; entryIndex++) {
        transfer->mEntries[entryIndex].mLastCallbackId = 0;
    }
    request.mCommand = XFER_COMMAND_UNUSED;
    TrySetNextRequest(&request);
    ResetRequestId();
    SetSendChunkSize(0);
    SetReceiveChunkSize(0);
    Os_RestoreIrq(savedInterrupts);
}

void WBT_End(void) {
    WBTCommand request;
    BlockTransfer *transfer;
    s32 entryIndex;
    u32 savedInterrupts;
    savedInterrupts = Os_DisableIrq();
    if (wbt_initialize_flag == 0) {
        Os_RestoreIrq(savedInterrupts);
        return;
    }
    wbt_initialize_flag = 0;
    WBT_SetOwnAid(-1);
    SetGlobalGO_from_thumb(NULL);
    transfer = GetBlockTransfer();
    transfer->mCurrentRequest.mCommand = XFER_COMMAND_UNUSED;
    transfer->mCurrentRequest.mTargetBmp = 0;
    transfer->mCurrentRequest.mPeerBmp = 0;
    transfer->mCurrentRequest.mCallback = NULL;
    transfer->mCallbackRecord.mCommand = XFER_COMMAND_UNUSED;
    transfer->mCallbackRecord.mTargetBmp = 0;
    transfer->mCallbackRecord.mPeerBmp = 0;
    transfer->mCallbackRecord.mCallback = NULL;
    for (entryIndex = 0; entryIndex < 16; entryIndex++) {
        transfer->mEntries[entryIndex].mLastCallbackId = 0;
    }
    request.mCommand = XFER_COMMAND_UNUSED;
    TrySetNextRequest(&request);
    ResetRequestId();
    SetSendChunkSize(-1);
    SetReceiveChunkSize(-1);
    Os_RestoreIrq(savedInterrupts);
}

u32 WBT_MpParentSendHook(u8 *buffer, s32 bufferSize) {
    u16 packetSize;
    packetSize = 0;
    if (bufferSize > 0 && buffer != NULL) {
        packetSize = BuildParentPacketUnchecked(buffer, bufferSize);
    }
    return packetSize;
}

#pragma thumb off
