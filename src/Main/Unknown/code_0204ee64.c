#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void StartBlockCountRequest(void) {
    s32 savedValue = gStruct217AA00->fieldC;
    u8 mask;
    s32 s = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
    if (s == 1) {
        mask = gStruct217AA00->field44.mChildMask;
    } else {
        mask = 1;
    }
    gStruct217AA00->fieldC = 0x2a;
    gStruct217AA00->mRequestPending = 1;
    if (RequestBlockCount(mask, BlockCountRequestCallback) == 0) {
        gStruct217AA00->mRequestPending = 0;
        gStruct217AA00->fieldC = savedValue;
    }
}

void BlockCountRequestCallback(BlockTransferRecord *record) {
    if (record->mKind == 2) {
        if (record->mCallbackCode == 3) {
            gStruct217AA00->mBlockCount = *(s16 *) &record->field14;
            gStruct217AA00->mRequestPending = 0;
        } else {
            sub_2050E60(8);
        }
    } else {
        sub_2050E60(8);
    }
}

void StartBlockNodeRequest(void) {
    s32 savedValue = gStruct217AA00->fieldC;
    gStruct217AA00->fieldC = 0x2b;
    gStruct217AA00->mRequestPending = 1;
    if (RequestBlockNode(1, gStruct217AA00->mBlockIndex, gStruct217AA00->mBlockInfos, BlockNodeRequestCallback) == 0) {
        gStruct217AA00->fieldC = savedValue;
        gStruct217AA00->mRequestPending = 0;
    }
}

void BlockNodeRequestCallback(BlockTransferRecord *record) {
    if (record->mKind == 6) {
        if (record->mCallbackCode == 7) {
            gStruct217AA00->mRequestPending = 0;
        } else {
            StartBlockNodeRequest();
        }
    } else {
        sub_2050E60(8);
    }
}

void StartBlockDataRequest(void) {
    s32 savedValue = gStruct217AA00->fieldC;
    gStruct217AA00->fieldC = 0x2c;
    gStruct217AA00->mRequestPending = 1;
    gStruct217AA00->field1D60 = gStruct217AA00->mBlockEntries[gStruct217AA00->mBlockIndex].mBuffer;
    if (RequestBlockData(1, gStruct217AA00->mBlockInfos[0]->mBlockId, &gStruct217AA00->field1D60,
                         gStruct217AA00->mBlockInfos[0]->mSize, gStruct217AA00->mChunkBitmaps,
                         BlockDataRequestCallback) == 0) {
        gStruct217AA00->fieldC = savedValue;
        gStruct217AA00->mRequestPending = 0;
    }
}

void BlockDataRequestCallback(BlockTransferRecord *record) {
    if (record->mKind == 4) {
        if (record->mCallbackCode == 5) {
            gStruct217AA00->mRequestPending = 0;
        } else {
            sub_2050E60(8);
        }
    } else {
        sub_2050E60(8);
    }
}

void SetOwnIndexFromConnection(void) {
    s32 v = gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0;
    if (v == 2) {
        if (gStruct217AA00->mOwnIndex == 0xffff) {
            sub_2050E60(8);
            return;
        }
        SetOwnIndex(gStruct217AA00->mOwnIndex);
    }
}

void func_0204ef1c(void) {
    gStruct217AA00->fieldC = 0xb;
    gStruct217AA00->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, gStruct217AA00->mMPReceiveBuffer, gStruct217AA00->mMPReceiveBufferSize,
                     gStruct217AA00->mMPSendBuffer, gStruct217AA00->mMPSendBufferSize, 1, 0, 0, 0, 0, 0) != 2) {
        sub_2050E60(2);
    }
}

void AddGhostDataBlock(u8 *data, u32 size) {
    u16 index = gStruct217AA00->mGhostBlockCount;
    WBT_RegisterBlock(&gStruct217AA00->mBlockEntries[index].mNode, (u16) (index + 0x3e8), aNitrokartGhostDataTest01, data, size, 0);
    gStruct217AA00->mBlockEntries[index].mBuffer = (u32 *) data;
    gStruct217AA00->mGhostBlockCount++;
}

void func_0204eeac(u8 *data, u32 size) {
    AddGhostDataBlock(data, size);
}

void RemoveGhostDataBlocks(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        WBT_UnregisterBlock((u16) (i + 0x3e8));
        gStruct217AA00->mBlockEntries[i].mBuffer = 0;
    }
    gStruct217AA00->mGhostBlockCount = 0;
}

#pragma thumb off
