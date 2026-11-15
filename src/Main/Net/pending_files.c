#include "Main/Net/pending_files.h"
#include "Main/System/heap.h"
#include "file_open_read.h"
#include "fs_file.h"
#include "Main/System/thread_function_queue.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Net/child_block_transfer.h"
#include "Main/Net/parent_block_transfer.h"
#include "Main/Net/wbt_requests.h"
#include "Main/Net/block.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void UncompressPendingFile(void) {
    s16 index = gConnectionWork->mNextLoadIndex - 1;
    u32 uncompressedSize = *gConnectionWork->mBlockEntries[index].mBuffer >> 8;
    void *destination = gConnectionWork->mBlockEntries[index].mUncompressedBuffer;
    if (destination == NULL) {
        destination =
            HeapAllocAligned(gConnectionWork->mBlockEntries[index].mHeap, uncompressedSize, HEAP_ALIGN_CACHE_LINE);
        *gConnectionWork->mBlockEntries[index].mDataOutput = destination;
    }
    MI_UncompressLZ8(gConnectionWork->mBlockEntries[index].mBuffer, destination);
    gConnectionWork->mBlockEntries[index].mUncompressPending = 0;
}

// Staged: one step per call; returns TRUE when no queued file is left.
BOOL LoadPendingFiles(void) {
    u16 nextIndex = gConnectionWork->mNextLoadIndex;
    s16 previousIndex = nextIndex - 1;
    FSFile *file = &gConnectionWork->mFile;
    void *workOrPath;
    s32 size;
    u32 *buffer;
    if (((file->mStat & FILE_RECORD_BUSY) ? 1 : 0) != 0) {
        return FALSE;
    }
    if (previousIndex >= 0 && gConnectionWork->mBlockEntries[previousIndex].mUncompressPending != 0) {
        if (gThreadFunctionQueue->mRunRequested != 0) {
            return FALSE;
        }
        QueueThreadFunction(UncompressPendingFile);
        gThreadFunctionQueue->mRunRequested = 1;
        return FALSE;
    }
    if (nextIndex >= CONNECTION_BLOCK_ENTRY_COUNT || gConnectionWork->mBlockEntries[nextIndex].mPath[0] == 0) {
        return TRUE;
    }
    workOrPath = gConnectionWork->mBlockEntries[nextIndex].mPath;
    if (((file->mStat & FILE_RECORD_OPEN) ? 1 : 0) != 0) {
        FS_CloseFile(file);
    }
    FS_InitFile(file);
    if (FS_OpenFile(file, workOrPath) != 0) {
        workOrPath = gConnectionWork;
        size = file->mProp.p.mUnk_08 - file->mProp.p.mUnk_04;
        buffer = ((ConnectionWork *) workOrPath)->mBlockEntries[nextIndex].mBuffer;
        if (buffer == NULL) {
            buffer = HeapAllocAligned(gConnectionWork->mBlockEntries[nextIndex].mHeap, size, HEAP_ALIGN_CACHE_LINE);
            *gConnectionWork->mBlockEntries[nextIndex].mDataOutput = buffer;
        }
        FS_ReadFileAsync(file, buffer, size);
        gConnectionWork->mNextLoadIndex++;
    }
    return FALSE;
}

#pragma thumb off

#pragma thumb on

void ResetPendingFiles(void) {
    int entryIndex;
    BlockTransferView *view;
    BlockEntry *entry;
    u32 flagBitsMask;
    u32 clearPendingMask;
    flagBitsMask = (0xe0000000u);
    clearPendingMask = (0xdfffffffu);
    view = &gConnectionWork->mBlockTransfer;
    entryIndex = 0;
    entry = view->mBlockEntries;
    do {
        entry->mPath[0] = 0;
        entry->mBuffer = NULL;
        entry->mUncompressedBuffer = NULL;
        entry->mUnk_84 = entry->mUnk_84 & clearPendingMask;
        entry->mUnk_84 = entry->mUnk_84 & flagBitsMask;
        entry = entry + 1;
        entryIndex = entryIndex + 1;
    } while (entryIndex < CONNECTION_BLOCK_ENTRY_COUNT);
    view->mNextLoadIndex = CONNECTION_BLOCK_ENTRY_COUNT;
}

#pragma thumb off

#pragma thumb on

void AddPendingFile(const void *path, void *heap, void **dataOutput, u32 value, s32 uncompress) {
    u16 entryIndex;
    for (entryIndex = 0; entryIndex < CONNECTION_BLOCK_ENTRY_COUNT; entryIndex++) {
        if (gConnectionWork->mBlockEntries[entryIndex].mPath[0] == 0) {
            MI_CpuCopy8(path, gConnectionWork->mBlockEntries[entryIndex].mPath,
                        sizeof(gConnectionWork->mBlockEntries[entryIndex].mPath));
            if (uncompress != 0) {
                gConnectionWork->mBlockEntries[entryIndex].mBuffer = gConnectionWork->mCompressedBuffer;
                gConnectionWork->mBlockEntries[entryIndex].mUncompressedBuffer = 0;
                gConnectionWork->mBlockEntries[entryIndex].mUncompressPending = 1;
                gConnectionWork->mBlockEntries[entryIndex].mByteSize = value;
            } else {
                gConnectionWork->mBlockEntries[entryIndex].mBuffer = 0;
                gConnectionWork->mBlockEntries[entryIndex].mUncompressedBuffer = 0;
                gConnectionWork->mBlockEntries[entryIndex].mUncompressPending = 0;
                gConnectionWork->mBlockEntries[entryIndex].mByteSize = value;
            }
            gConnectionWork->mBlockEntries[entryIndex].mHeap = heap;
            gConnectionWork->mBlockEntries[entryIndex].mUnk_84_30 = 1;
            gConnectionWork->mBlockEntries[entryIndex].mDataOutput = dataOutput;
            return;
        }
    }
}

void StartParentSideBlockTransfer(void) {
    gConnectionWork->mStep = CONNECTION_STEP_PARENT_BLOCK_TRANSFER;
    gConnectionWork->mRequestPending = 1;
    WBT_InitParent(0x192, 0xe, ParentBlockTransferCallback);
    gConnectionWork->mSendTimer = 0;
    gConnectionWork->mTransferFlags &= ~1;
    gConnectionWork->mFlags |= CONNECTION_FLAG_BLOCK_TRANSFER;
    gConnectionWork->mRequestPending = 0;
}

void StartChildSideBlockTransfer(void) {
    gConnectionWork->mStep = CONNECTION_STEP_CHILD_BLOCK_TRANSFER;
    gConnectionWork->mRequestPending = 1;
    WBT_InitChild(ChildBlockTransferCallback);
    gConnectionWork->mSendTimer = 0;
    gConnectionWork->mTransferFlags &= ~1;
    gConnectionWork->mFlags |= CONNECTION_FLAG_BLOCK_TRANSFER;
    gConnectionWork->mRequestPending = 0;
}

void AllocTransferBuffers(void *heap) {
    s32 blockInfoIndex;
    gConnectionWork->mMPSendBufferSize = CONNECTION_MP_SEND_BUFFER_SIZE;
    gConnectionWork->mMPSendBuffer = HeapAllocAligned(heap, gConnectionWork->mMPSendBufferSize, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mMPReceiveBufferSize = CONNECTION_MP_RECEIVE_BUFFER_SIZE;
    gConnectionWork->mMPReceiveBuffer =
        HeapAllocAligned(heap, gConnectionWork->mMPReceiveBufferSize, HEAP_ALIGN_CACHE_LINE);
    for (blockInfoIndex = 0; blockInfoIndex < 8; blockInfoIndex++) {
        gConnectionWork->mBlockInfos[blockInfoIndex] = HeapAllocAligned(heap, 0x28, HEAP_ALIGN_CACHE_LINE);
        gConnectionWork->mChunkBitmaps[blockInfoIndex] = HeapAllocAligned(heap, 4, HEAP_ALIGN_CACHE_LINE);
    }
    gConnectionWork->mPacketBuffer = HeapAllocAligned(heap, 0x192, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mScanGhostInfos = HeapAllocAligned(heap, 0x20, HEAP_ALIGN_CACHE_LINE);
}

void InitBlockEntries(void *heap, s32 mode) {
    BlockTransferView *view = &gConnectionWork->mBlockTransfer;
    s32 entryIndex;
    for (entryIndex = 0; entryIndex < CONNECTION_BLOCK_ENTRY_COUNT; entryIndex++) {
        view->mBlockEntries[entryIndex].mPath[0] = 0;
        view->mBlockEntries[entryIndex].mBuffer = NULL;
        view->mBlockEntries[entryIndex].mUncompressedBuffer = NULL;
        view->mBlockEntries[entryIndex].mUncompressPending = 0;
        view->mBlockEntries[entryIndex].mByteSize = 0;
    }
    view->mMode = mode;
    view->mZeroWordReceived = FALSE;
    view->mMPSetupActive = FALSE;
    view->mGhostBlockCount = 0;
    view->mUnk_7a2 = 0;
    view->mUnk_7a4 = 0;
    view->mUnk_7a5 = -1;
    view->mUnk_7a6 = 0;
    view->mUnk_6b4 = 0;
    view->mNextLoadIndex = 0;
    view->mUnk_66a = -1;
    view->mCompressedBuffer = NULL;
    if (mode == 2) {
        AllocTransferBuffers(heap);
        RemoveGhostDataBlocks();
    } else if (mode == 1) {
        gConnectionWork->mCompressedBuffer = HeapAllocAligned(heap, 0x4b000, HEAP_ALIGN_CACHE_LINE);
    }
}

#pragma thumb off
