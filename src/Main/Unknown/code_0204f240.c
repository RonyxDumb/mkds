#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204f198.h"
#include "Main/Unknown/code_0204f19c.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void AddPendingFile(const void *path, void *heap, void **dataOutput, u32 value, s32 uncompress) {
    u16 entryIndex;
    for (entryIndex = 0; entryIndex < 12; entryIndex++) {
        if (gConnectionWork->mBlockEntries[entryIndex].mPath == 0) {
            MI_CpuCopy8(path, &gConnectionWork->mBlockEntries[entryIndex].mPath, 0x40);
            if (uncompress != 0) {
                gConnectionWork->mBlockEntries[entryIndex].mBuffer = gConnectionWork->mCompressedBuffer;
                gConnectionWork->mBlockEntries[entryIndex].mUncompressedBuffer = 0;
                gConnectionWork->mBlockEntries[entryIndex].mUncompressPending = 1;
                gConnectionWork->mBlockEntries[entryIndex].mUnk_84_0 = value;
            } else {
                gConnectionWork->mBlockEntries[entryIndex].mBuffer = 0;
                gConnectionWork->mBlockEntries[entryIndex].mUncompressedBuffer = 0;
                gConnectionWork->mBlockEntries[entryIndex].mUncompressPending = 0;
                gConnectionWork->mBlockEntries[entryIndex].mUnk_84_0 = value;
            }
            gConnectionWork->mBlockEntries[entryIndex].mHeap = heap;
            gConnectionWork->mBlockEntries[entryIndex].mUnk_84_30 = 1;
            gConnectionWork->mBlockEntries[entryIndex].mDataOutput = dataOutput;
            return;
        }
    }
}

void StartParentSideBlockTransfer(void) {
    gConnectionWork->mStep = 0x28;
    gConnectionWork->mRequestPending = 1;
    WBT_InitParent(0x192, 0xe, ParentBlockTransferCallback);
    gConnectionWork->mSendTimer = 0;
    gConnectionWork->mTransferFlags &= ~1;
    gConnectionWork->mFlags |= CONNECTION_FLAG_BLOCK_TRANSFER;
    gConnectionWork->mRequestPending = 0;
}

void StartChildSideBlockTransfer(void) {
    gConnectionWork->mStep = 0x29;
    gConnectionWork->mRequestPending = 1;
    WBT_InitChild(ChildBlockTransferCallback);
    gConnectionWork->mSendTimer = 0;
    gConnectionWork->mTransferFlags &= ~1;
    gConnectionWork->mFlags |= CONNECTION_FLAG_BLOCK_TRANSFER;
    gConnectionWork->mRequestPending = 0;
}

void AllocTransferBuffers(void *heap) {
    s32 blockInfoIndex;
    gConnectionWork->mMPSendBufferSize = 0x1c0;
    gConnectionWork->mMPSendBuffer = HeapAllocAligned(heap, gConnectionWork->mMPSendBufferSize, 0x20);
    gConnectionWork->mMPReceiveBufferSize = 0x400;
    gConnectionWork->mMPReceiveBuffer = HeapAllocAligned(heap, gConnectionWork->mMPReceiveBufferSize, 0x20);
    for (blockInfoIndex = 0; blockInfoIndex < 8; blockInfoIndex++) {
        gConnectionWork->mBlockInfos[blockInfoIndex] = HeapAllocAligned(heap, 0x28, 0x20);
        gConnectionWork->mChunkBitmaps[blockInfoIndex] = HeapAllocAligned(heap, 4, 0x20);
    }
    gConnectionWork->mPacketBuffer = HeapAllocAligned(heap, 0x192, 0x20);
    gConnectionWork->mScanGhostInfos = HeapAllocAligned(heap, 0x20, 0x20);
}

void InitBlockEntries(void *heap, s32 mode) {
    BlockTransferView *view = &gConnectionWork->mUnk_16a0_view;
    s32 entryIndex;
    for (entryIndex = 0; entryIndex < 12; entryIndex++) {
        view->mBlockEntries[entryIndex].mPath = 0;
        view->mBlockEntries[entryIndex].mBuffer = NULL;
        view->mBlockEntries[entryIndex].mUncompressedBuffer = NULL;
        view->mBlockEntries[entryIndex].mUncompressPending = 0;
        view->mBlockEntries[entryIndex].mUnk_84_0 = 0;
    }
    view->mUnk_660 = mode;
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
        gConnectionWork->mCompressedBuffer = HeapAllocAligned(heap, 0x4b000, 0x20);
    }
}

#pragma thumb off
