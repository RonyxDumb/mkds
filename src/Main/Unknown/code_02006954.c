#include "Main/Unknown/code_02006954.h"

#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_020070f0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02133000.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

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
    return &gNextRequest;
}

#pragma thumb off

#pragma thumb on

u32 TrySetNextRequest(const WBTCommand *request) {
    u32 savedInterrupts;
    WBTCommand *nextRequest;
    savedInterrupts = OS_DisableInterrupts();
    if (wbt_initialize_flag != 1) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    nextRequest = GetNextRequestAddress();
    if (nextRequest == NULL || nextRequest->mCommand != 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    MIi_CpuCopy32(request, &gNextRequest, 0x9c);
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

#pragma thumb off

#pragma thumb on

WBTBlockInfoList *GetBlockListHead(void) {
    return gBlockListHead;
}

void SetBlockListHead(WBTBlockInfoList *head) {
    gBlockListHead = head;
}

#pragma thumb off

#pragma thumb on

WBTBlockInfoList *FindBlockById(u32 blockId) {
    WBTBlockInfoList *node;
    for (node = GetBlockListHead(); node != NULL; node = node->mNext) {
        if (node->mId == blockId) {
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
    s32 i;
    for (i = 0; i < 16; i++) {
        if (((mask >> i) & 1) != 0) {
            return i;
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
    if (transfer->mCurrentRequest.mCommand == 4 && transfer->mCurrentRequest.mUnk_14.w.mUnk_14 == blockId) {
        *chunkCountOut = receive->mTotal;
        *receivedChunkCountOut = receive->mCount;
        return TRUE;
    }
    return FALSE;
}

u32 WBT_SetPacketSize(s32 sendSize, s32 receiveSize) {
    switch (GetBlockTransfer()->mCurrentRequest.mCommand) {
        case 4:
        case 6:
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
    for (node = GetBlockListHead(); node != NULL; node = node->mNext) {
        count = count + 1;
    }
    return count;
}

#pragma thumb off

#pragma thumb on

s32 WBT_RegisterBlock(WBTBlockInfoList *node, u32 blockId, const void *info, u8 *data, u32 size, u16 f) {
    WBTBlockInfoList *lastNode;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (GetBlockListHead() == NULL) {
        SetBlockListHead(node);
    } else {
        for (lastNode = GetBlockListHead(); lastNode->mNext != NULL; lastNode = lastNode->mNext) {
        }
        lastNode->mNext = node;
    }
    if (data == NULL) {
        node->mBlockType = 1;
    } else {
        node->mDataPtr = data;
        node->mBlockType = 0;
    }
    node->mNext = NULL;
    node->mId = blockId;
    node->mBlockSize = size;
    node->mPermissionBmp = f;
    if (info != NULL) {
        MI_CpuCopy8(info, node->mUserId, 0x20);
    } else {
        MI_CpuFill8(node->mUserId, 0, 0x20);
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

WBTBlockInfoList *WBT_UnregisterBlock(u32 blockId) {
    WBTBlockInfoList *v1;
    WBTBlockInfoList *v2;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    v1 = GetBlockListHead();
    if (v1 == NULL) {
        OS_RestoreInterrupts(savedInterrupts);
        return NULL;
    }
    if (v1->mId == blockId) {
        SetBlockListHead(v1->mNext);
        OS_RestoreInterrupts(savedInterrupts);
        return v1;
    }
    for (v2 = v1->mNext; v2 != NULL; v1 = v2, v2 = v2->mNext) {
        if (v2->mId == blockId) {
            v1->mNext = v2->mNext;
            OS_RestoreInterrupts(savedInterrupts);
            return v2;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return NULL;
}

u32 WBT_RequestSync(u16 indexMask, void (*callback)(WBTCommand *)) {
    WBTCommand request;
    request.mCommand = 2;
    request.mTargetBmp = indexMask;
    request.mCallback = callback;
    return TrySetNextRequest(&request);
}

u32 WBT_GetBlockInfo(u16 indexMask, u32 blockIdOrPosition, const void *buffers, void (*callback)(WBTCommand *)) {
    WBTCommand request;
    request.mCommand = 6;
    request.mTargetBmp = indexMask;
    request.mCallback = callback;
    request.mUnk_14.w.mUnk_14 = blockIdOrPosition;
    request.mUnk_14.w.mUnk_18 = 0x28;
    MIi_CpuCopy32(buffers, &request.mUnk_14.w.mUnk_1c, 0x40);
    return TrySetNextRequest(&request);
}

u32 WBT_GetBlock(u16 indexMask, u32 blockId, const void *buffers, u32 blockSize, const void *chunkBitmaps,
                 void (*callback)(WBTCommand *)) {
    WBTCommand request;
    request.mCommand = 4;
    request.mTargetBmp = indexMask;
    request.mCallback = callback;
    request.mUnk_14.w.mUnk_14 = blockId;
    request.mUnk_14.w.mUnk_18 = blockSize;
    MIi_CpuCopy32(buffers, &request.mUnk_14.w.mUnk_1c, 0x40);
    MIi_CpuCopy32(chunkBitmaps, &request.mChunkBitmaps, 0x40);
    return TrySetNextRequest(&request);
}

u32 WBT_PutUserData(u16 indexMask, const void *bytes, s32 byteCount, void (*callback)(WBTCommand *)) {
    WBTCommand request;
    WBTCommand *requestPointer;
    if (byteCount < 0 || byteCount > 9) {
        return 0;
    }
    request.mCommand = 10;
    requestPointer = &request;
    requestPointer->mTargetBmp = indexMask;
    requestPointer->mCallback = callback;
    MI_CpuCopy8(bytes, &requestPointer->mUnk_14.w.mUnk_14, byteCount);
    requestPointer->mUnk_14.b.mUnk_1d = byteCount;
    return TrySetNextRequest(&request);
}

s32 BuildParentPacketUnchecked(u8 *buffer, s32 bufferSize) {
    BlockTransfer *transfer;
    s32 i;
    s32 packetSize;
    transfer = GetBlockTransfer();
    i = gLastReplyIndex;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        packetSize = ReplyToBytesPacket(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
        packetSize = ReplyToBlockCountRequest(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
        packetSize = ReplyToBlockNodeRequest(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
        packetSize = ReplyToNoMissingChunk(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
    } while (i != gLastReplyIndex);
    packetSize = WBTi_CheckRequest(transfer, buffer, bufferSize);
    if (packetSize != 0) {
        return packetSize;
    }
    packetSize = WBTi_SwitchNextCommand(transfer, buffer, bufferSize);
    if (packetSize != 0) {
        return packetSize;
    }
    i = gLastReplyIndex;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        packetSize = ReplyToBlockDataRequest(transfer, i, buffer, bufferSize);
        if (packetSize != 0) {
            gLastReplyIndex = i;
            return packetSize;
        }
    } while (i != gLastReplyIndex);
    for (i = 1; i < 16; i++) {
        packetSize = ReplyToBlockNodeRequestAlways(transfer, i, buffer, bufferSize);
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
    s32 i;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (wbt_initialize_flag == 1) {
        OS_RestoreInterrupts(savedInterrupts);
        return;
    }
    wbt_initialize_flag = 1;
    WBT_SetOwnAid(0);
    SetBlockListHead(NULL);
    transfer = GetBlockTransfer();
    transfer->mCurrentRequest.mCommand = 0;
    transfer->mCurrentRequest.mTargetBmp = 0;
    transfer->mCurrentRequest.mPeerBmp = 0;
    transfer->mCurrentRequest.mCallback = NULL;
    transfer->mCallbackRecord.mCommand = 0;
    transfer->mCallbackRecord.mTargetBmp = 0;
    transfer->mCallbackRecord.mPeerBmp = 0;
    transfer->mCallbackRecord.mCallback = callback;
    for (i = 0; i < 16; i++) {
        transfer->mEntries[i].mLastCallbackId = 0;
    }
    request.mCommand = 0;
    TrySetNextRequest(&request);
    ResetRequestId();
    SetSendChunkSize(sendSize - 0xe);
    SetReceiveChunkSize(receiveSize - 0xe);
    OS_RestoreInterrupts(savedInterrupts);
}

void WBT_InitChild(void (*callback)(WBTCommand *)) {
    WBTCommand request;
    BlockTransfer *transfer;
    s32 i;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (wbt_initialize_flag == 1) {
        OS_RestoreInterrupts(savedInterrupts);
        return;
    }
    wbt_initialize_flag = 1;
    WBT_SetOwnAid(-1);
    SetBlockListHead(NULL);
    transfer = GetBlockTransfer();
    transfer->mCurrentRequest.mCommand = 0;
    transfer->mCurrentRequest.mTargetBmp = 0;
    transfer->mCurrentRequest.mPeerBmp = 0;
    transfer->mCurrentRequest.mCallback = NULL;
    transfer->mCallbackRecord.mCommand = 0;
    transfer->mCallbackRecord.mTargetBmp = 0;
    transfer->mCallbackRecord.mPeerBmp = 0;
    transfer->mCallbackRecord.mCallback = callback;
    for (i = 0; i < 16; i++) {
        transfer->mEntries[i].mLastCallbackId = 0;
    }
    request.mCommand = 0;
    TrySetNextRequest(&request);
    ResetRequestId();
    SetSendChunkSize(0);
    SetReceiveChunkSize(0);
    OS_RestoreInterrupts(savedInterrupts);
}

void WBT_End(void) {
    WBTCommand request;
    BlockTransfer *transfer;
    s32 i;
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (wbt_initialize_flag == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return;
    }
    wbt_initialize_flag = 0;
    WBT_SetOwnAid(-1);
    SetBlockListHead(NULL);
    transfer = GetBlockTransfer();
    transfer->mCurrentRequest.mCommand = 0;
    transfer->mCurrentRequest.mTargetBmp = 0;
    transfer->mCurrentRequest.mPeerBmp = 0;
    transfer->mCurrentRequest.mCallback = NULL;
    transfer->mCallbackRecord.mCommand = 0;
    transfer->mCallbackRecord.mTargetBmp = 0;
    transfer->mCallbackRecord.mPeerBmp = 0;
    transfer->mCallbackRecord.mCallback = NULL;
    for (i = 0; i < 16; i++) {
        transfer->mEntries[i].mLastCallbackId = 0;
    }
    request.mCommand = 0;
    TrySetNextRequest(&request);
    ResetRequestId();
    SetSendChunkSize(-1);
    SetReceiveChunkSize(-1);
    OS_RestoreInterrupts(savedInterrupts);
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
