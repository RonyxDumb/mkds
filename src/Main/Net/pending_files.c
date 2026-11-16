#include "Main/Net/pending_files.h"
#include "Main/System/heap.h"
#include "file_archive_access.h"
#include "file_handle_setup.h"
#include "Main/System/thread_function_queue.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Net/child_block_transfer.h"
#include "Main/Net/parent_block_transfer.h"
#include "Main/Net/wireless_block_requests.h"
#include "Main/Net/block.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void UncompressPendingFile(void) {
    s16 index = g_GlobalZE->mNextLoadIndex - 1;
    u32 uncompressedSize = *g_GlobalZE->mBlockEntries[index].mBuffer >> 8;
    void *destination = g_GlobalZE->mBlockEntries[index].mUncompressedBuffer;
    if (destination == NULL) {
        destination =
            Mem_AllocateHeapAligned(g_GlobalZE->mBlockEntries[index].mHeap, uncompressedSize, HEAP_ALIGN_CACHE_LINE);
        *g_GlobalZE->mBlockEntries[index].mDataOutput = destination;
    }
    DecompressLzss(g_GlobalZE->mBlockEntries[index].mBuffer, destination);
    g_GlobalZE->mBlockEntries[index].mUncompressPending = 0;
}

// Staged: one step per call; returns TRUE when no queued file is left.
BOOL LoadPendingFiles(void) {
    u16 nextIndex = g_GlobalZE->mNextLoadIndex;
    s16 previousIndex = nextIndex - 1;
    FSFile *file = &g_GlobalZE->mFile;
    void *workOrPath;
    s32 size;
    u32 *buffer;
    if (((file->mStat & FILE_RECORD_BUSY) ? 1 : 0) != 0) {
        return FALSE;
    }
    if (previousIndex >= 0 && g_GlobalZE->mBlockEntries[previousIndex].mUncompressPending != 0) {
        if (g_WorkerContext->mRunRequested != 0) {
            return FALSE;
        }
        WorkerInsertTask(UncompressPendingFile);
        g_WorkerContext->mRunRequested = 1;
        return FALSE;
    }
    if (nextIndex >= CONNECTION_BLOCK_ENTRY_COUNT || g_GlobalZE->mBlockEntries[nextIndex].mPath[0] == 0) {
        return TRUE;
    }
    workOrPath = g_GlobalZE->mBlockEntries[nextIndex].mPath;
    if (((file->mStat & FILE_RECORD_OPEN) ? 1 : 0) != 0) {
        Fs_File_Close(file);
    }
    Fs_File_Initialize(file);
    if (Fs_File_Open(file, workOrPath) != 0) {
        workOrPath = g_GlobalZE;
        size = file->mProp.p.mUnk_08 - file->mProp.p.mUnk_04;
        buffer = ((ConnectionWork *) workOrPath)->mBlockEntries[nextIndex].mBuffer;
        if (buffer == NULL) {
            buffer = Mem_AllocateHeapAligned(g_GlobalZE->mBlockEntries[nextIndex].mHeap, size, HEAP_ALIGN_CACHE_LINE);
            *g_GlobalZE->mBlockEntries[nextIndex].mDataOutput = buffer;
        }
        Fs_File_ReadAsync(file, buffer, size);
        g_GlobalZE->mNextLoadIndex++;
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
    view = &g_GlobalZE->mBlockTransfer;
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
        if (g_GlobalZE->mBlockEntries[entryIndex].mPath[0] == 0) {
            Mem_CpuCopy8(path, g_GlobalZE->mBlockEntries[entryIndex].mPath,
                        sizeof(g_GlobalZE->mBlockEntries[entryIndex].mPath));
            if (uncompress != 0) {
                g_GlobalZE->mBlockEntries[entryIndex].mBuffer = g_GlobalZE->mCompressedBuffer;
                g_GlobalZE->mBlockEntries[entryIndex].mUncompressedBuffer = 0;
                g_GlobalZE->mBlockEntries[entryIndex].mUncompressPending = 1;
                g_GlobalZE->mBlockEntries[entryIndex].mByteSize = value;
            } else {
                g_GlobalZE->mBlockEntries[entryIndex].mBuffer = 0;
                g_GlobalZE->mBlockEntries[entryIndex].mUncompressedBuffer = 0;
                g_GlobalZE->mBlockEntries[entryIndex].mUncompressPending = 0;
                g_GlobalZE->mBlockEntries[entryIndex].mByteSize = value;
            }
            g_GlobalZE->mBlockEntries[entryIndex].mHeap = heap;
            g_GlobalZE->mBlockEntries[entryIndex].mUnk_84_30 = 1;
            g_GlobalZE->mBlockEntries[entryIndex].mDataOutput = dataOutput;
            return;
        }
    }
}

void StartParentSideBlockTransfer(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_PARENT_BLOCK_TRANSFER;
    g_GlobalZE->mRequestPending = 1;
    WBT_InitParent(0x192, 0xe, ParentBlockTransferCallback);
    g_GlobalZE->mSendTimer = 0;
    g_GlobalZE->mTransferFlags &= ~1;
    g_GlobalZE->mFlags |= CONNECTION_FLAG_BLOCK_TRANSFER;
    g_GlobalZE->mRequestPending = 0;
}

void StartChildSideBlockTransfer(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_CHILD_BLOCK_TRANSFER;
    g_GlobalZE->mRequestPending = 1;
    WBT_InitChild(ChildBlockTransferCallback);
    g_GlobalZE->mSendTimer = 0;
    g_GlobalZE->mTransferFlags &= ~1;
    g_GlobalZE->mFlags |= CONNECTION_FLAG_BLOCK_TRANSFER;
    g_GlobalZE->mRequestPending = 0;
}

void AllocTransferBuffers(void *heap) {
    s32 blockInfoIndex;
    g_GlobalZE->mMPSendBufferSize = CONNECTION_MP_SEND_BUFFER_SIZE;
    g_GlobalZE->mMPSendBuffer = Mem_AllocateHeapAligned(heap, g_GlobalZE->mMPSendBufferSize, HEAP_ALIGN_CACHE_LINE);
    g_GlobalZE->mMPReceiveBufferSize = CONNECTION_MP_RECEIVE_BUFFER_SIZE;
    g_GlobalZE->mMPReceiveBuffer =
        Mem_AllocateHeapAligned(heap, g_GlobalZE->mMPReceiveBufferSize, HEAP_ALIGN_CACHE_LINE);
    for (blockInfoIndex = 0; blockInfoIndex < 8; blockInfoIndex++) {
        g_GlobalZE->mBlockInfos[blockInfoIndex] = Mem_AllocateHeapAligned(heap, 0x28, HEAP_ALIGN_CACHE_LINE);
        g_GlobalZE->mChunkBitmaps[blockInfoIndex] = Mem_AllocateHeapAligned(heap, 4, HEAP_ALIGN_CACHE_LINE);
    }
    g_GlobalZE->mPacketBuffer = Mem_AllocateHeapAligned(heap, 0x192, HEAP_ALIGN_CACHE_LINE);
    g_GlobalZE->mScanGhostInfos = Mem_AllocateHeapAligned(heap, 0x20, HEAP_ALIGN_CACHE_LINE);
}

void InitBlockEntries(void *heap, s32 mode) {
    BlockTransferView *view = &g_GlobalZE->mBlockTransfer;
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
        g_GlobalZE->mCompressedBuffer = Mem_AllocateHeapAligned(heap, 0x4b000, HEAP_ALIGN_CACHE_LINE);
    }
}

#pragma thumb off
