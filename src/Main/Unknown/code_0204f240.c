#include "Main/Unknown/code_0204f240.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0204f198.h"
#include "Main/Unknown/code_0204f19c.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void AddPendingFile(const void *path, void *heap, void **dataOutput, u32 value, s32 uncompress) {
    u16 i;
    for (i = 0; i < 12; i++) {
        if (gStruct217AA00->mBlockEntries[i].mPath == 0) {
            MI_CpuCopy8(path, &gStruct217AA00->mBlockEntries[i].mPath, 0x40);
            if (uncompress != 0) {
                gStruct217AA00->mBlockEntries[i].mBuffer = gStruct217AA00->mCompressedBuffer;
                gStruct217AA00->mBlockEntries[i].mUncompressedBuffer = 0;
                gStruct217AA00->mBlockEntries[i].mUncompressPending = 1;
                gStruct217AA00->mBlockEntries[i].mUnk_84_0 = value;
            } else {
                gStruct217AA00->mBlockEntries[i].mBuffer = 0;
                gStruct217AA00->mBlockEntries[i].mUncompressedBuffer = 0;
                gStruct217AA00->mBlockEntries[i].mUncompressPending = 0;
                gStruct217AA00->mBlockEntries[i].mUnk_84_0 = value;
            }
            gStruct217AA00->mBlockEntries[i].mHeap = heap;
            gStruct217AA00->mBlockEntries[i].mUnk_84_30 = 1;
            gStruct217AA00->mBlockEntries[i].mDataOutput = dataOutput;
            return;
        }
    }
}

void StartParentSideBlockTransfer(void) {
    gStruct217AA00->mUnk_000c = 0x28;
    gStruct217AA00->mRequestPending = 1;
    StartParentBlockTransfer(0x192, 0xe, ParentBlockTransferCallback);
    gStruct217AA00->mSendTimer = 0;
    gStruct217AA00->mUnk_1e44 &= ~1;
    gStruct217AA00->mUnk_0454 |= 0x200;
    gStruct217AA00->mRequestPending = 0;
}

void StartChildSideBlockTransfer(void) {
    gStruct217AA00->mUnk_000c = 0x29;
    gStruct217AA00->mRequestPending = 1;
    WBT_InitChild(ChildBlockTransferCallback);
    gStruct217AA00->mSendTimer = 0;
    gStruct217AA00->mUnk_1e44 &= ~1;
    gStruct217AA00->mUnk_0454 |= 0x200;
    gStruct217AA00->mRequestPending = 0;
}

void func_0204f33c(void *heap) {
    s32 i;
    gStruct217AA00->mMPSendBufferSize = 0x1c0;
    gStruct217AA00->mMPSendBuffer = heap_allocEx(heap, gStruct217AA00->mMPSendBufferSize, 0x20);
    gStruct217AA00->mMPReceiveBufferSize = 0x400;
    gStruct217AA00->mMPReceiveBuffer = heap_allocEx(heap, gStruct217AA00->mMPReceiveBufferSize, 0x20);
    for (i = 0; i < 8; i++) {
        gStruct217AA00->mBlockInfos[i] = heap_allocEx(heap, 0x28, 0x20);
        gStruct217AA00->mChunkBitmaps[i] = heap_allocEx(heap, 4, 0x20);
    }
    gStruct217AA00->mPacketBuffer = heap_allocEx(heap, 0x192, 0x20);
    gStruct217AA00->mScanGhostInfos = heap_allocEx(heap, 0x20, 0x20);
}

void InitBlockEntries(void *heap, s32 mode) {
    Unk0217aa00_16a0_view *view = &gStruct217AA00->mUnk_16a0_view;
    s32 i;
    for (i = 0; i < 12; i++) {
        view->mBlockEntries[i].mPath = 0;
        view->mBlockEntries[i].mBuffer = NULL;
        view->mBlockEntries[i].mUncompressedBuffer = NULL;
        view->mBlockEntries[i].mUncompressPending = 0;
        view->mBlockEntries[i].mUnk_84_0 = 0;
    }
    view->mUnk_660 = mode;
    view->mUnk_798 = FALSE;
    view->mUnk_79c = FALSE;
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
        func_0204f33c(heap);
        RemoveGhostDataBlocks();
    } else if (mode == 1) {
        gStruct217AA00->mCompressedBuffer = heap_allocEx(heap, 0x4b000, 0x20);
    }
}

#pragma thumb off
