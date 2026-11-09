#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void StartBlockCountRequest(void) {
    s32 savedValue = gConnectionWork->mUnk_000c;
    u8 mask;
    s32 s = gConnectionWork == NULL ? 0 : gConnectionWork->mUnk_0000;
    if (s == 1) {
        mask = gConnectionWork->mUnk_0044.mChildMask;
    } else {
        mask = 1;
    }
    gConnectionWork->mUnk_000c = 0x2a;
    gConnectionWork->mRequestPending = 1;
    if (RequestBlockCount(mask, BlockCountRequestCallback) == 0) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mUnk_000c = savedValue;
    }
}

void BlockCountRequestCallback(BlockTransferRecord *record) {
    if (record->mKind == 2) {
        if (record->mCallbackCode == 3) {
            gConnectionWork->mBlockCount = record->mUnk_14.h.mUnk_14;
            gConnectionWork->mRequestPending = 0;
        } else {
            func_02050e60(8);
        }
    } else {
        func_02050e60(8);
    }
}

void StartBlockNodeRequest(void) {
    s32 savedValue = gConnectionWork->mUnk_000c;
    gConnectionWork->mUnk_000c = 0x2b;
    gConnectionWork->mRequestPending = 1;
    if (RequestBlockNode(1, gConnectionWork->mBlockIndex, gConnectionWork->mBlockInfos, BlockNodeRequestCallback) ==
        0) {
        gConnectionWork->mUnk_000c = savedValue;
        gConnectionWork->mRequestPending = 0;
    }
}

void BlockNodeRequestCallback(BlockTransferRecord *record) {
    if (record->mKind == 6) {
        if (record->mCallbackCode == 7) {
            gConnectionWork->mRequestPending = 0;
        } else {
            StartBlockNodeRequest();
        }
    } else {
        func_02050e60(8);
    }
}

void StartBlockDataRequest(void) {
    s32 savedValue = gConnectionWork->mUnk_000c;
    gConnectionWork->mUnk_000c = 0x2c;
    gConnectionWork->mRequestPending = 1;
    gConnectionWork->mUnk_1d60 = gConnectionWork->mBlockEntries[gConnectionWork->mBlockIndex].mBuffer;
    if (RequestBlockData(1, gConnectionWork->mBlockInfos[0]->mBlockId, &gConnectionWork->mUnk_1d60,
                         gConnectionWork->mBlockInfos[0]->mSize, gConnectionWork->mChunkBitmaps,
                         BlockDataRequestCallback) == 0) {
        gConnectionWork->mUnk_000c = savedValue;
        gConnectionWork->mRequestPending = 0;
    }
}

void BlockDataRequestCallback(BlockTransferRecord *record) {
    if (record->mKind == 4) {
        if (record->mCallbackCode == 5) {
            gConnectionWork->mRequestPending = 0;
        } else {
            func_02050e60(8);
        }
    } else {
        func_02050e60(8);
    }
}

void SetOwnIndexFromConnection(void) {
    s32 v = gConnectionWork == NULL ? 0 : gConnectionWork->mUnk_0000;
    if (v == 2) {
        if (gConnectionWork->mOwnIndex == 0xffff) {
            func_02050e60(8);
            return;
        }
        SetOwnIndex(gConnectionWork->mOwnIndex);
    }
}

void func_0204ef1c(void) {
    gConnectionWork->mUnk_000c = 0xb;
    gConnectionWork->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, gConnectionWork->mMPReceiveBuffer, gConnectionWork->mMPReceiveBufferSize,
                     gConnectionWork->mMPSendBuffer, gConnectionWork->mMPSendBufferSize, 1, 0, 0, 0, 0, 0) != 2) {
        func_02050e60(2);
    }
}

void AddGhostDataBlock(void *data, u32 size) {
    u16 index = gConnectionWork->mGhostBlockCount;
    AddBlock(&gConnectionWork->mBlockEntries[index].mNode, (u16) (index + 0x3e8), gGhostBlockInfo, data, size, 0);
    gConnectionWork->mBlockEntries[index].mBuffer = (u32 *) data;
    gConnectionWork->mGhostBlockCount++;
}

void func_0204eeac(void *data, u32 size) {
    AddGhostDataBlock(data, size);
}

void RemoveGhostDataBlocks(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        RemoveBlock((u16) (i + 0x3e8));
        gConnectionWork->mBlockEntries[i].mBuffer = 0;
    }
    gConnectionWork->mGhostBlockCount = 0;
}

#pragma thumb off
