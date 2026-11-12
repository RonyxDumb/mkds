#include "Main/Net/block.h"
#include "Main/Net/wbt_requests.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/scan.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void StartBlockCountRequest(void) {
    s32 savedValue = gConnectionWork->mStep;
    u8 mask;
    s32 connectionMode = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
    if (connectionMode == 1) {
        mask = gConnectionWork->mChildren.mChildMask;
    } else {
        mask = 1;
    }
    gConnectionWork->mStep = 0x2a;
    gConnectionWork->mRequestPending = 1;
    if (WBT_RequestSync(mask, BlockCountRequestCallback) == 0) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mStep = savedValue;
    }
}

void BlockCountRequestCallback(WBTCommand *record) {
    if (record->mCommand == 2) {
        if (record->mEvent == 3) {
            gConnectionWork->mBlockCount = record->mData.mSync.mNumOfList;
            gConnectionWork->mRequestPending = 0;
        } else {
            SetRequestErrorCode(8);
        }
    } else {
        SetRequestErrorCode(8);
    }
}

void StartBlockNodeRequest(void) {
    s32 savedValue = gConnectionWork->mStep;
    gConnectionWork->mStep = 0x2b;
    gConnectionWork->mRequestPending = 1;
    if (WBT_GetBlockInfo(1, gConnectionWork->mBlockIndex, gConnectionWork->mBlockInfos, BlockNodeRequestCallback) ==
        0) {
        gConnectionWork->mStep = savedValue;
        gConnectionWork->mRequestPending = 0;
    }
}

void BlockNodeRequestCallback(WBTCommand *record) {
    if (record->mCommand == 6) {
        if (record->mEvent == 7) {
            gConnectionWork->mRequestPending = 0;
        } else {
            StartBlockNodeRequest();
        }
    } else {
        SetRequestErrorCode(8);
    }
}

void StartBlockDataRequest(void) {
    s32 savedValue = gConnectionWork->mStep;
    gConnectionWork->mStep = 0x2c;
    gConnectionWork->mRequestPending = 1;
    gConnectionWork->mCurrentBlockBuffer = gConnectionWork->mBlockEntries[gConnectionWork->mBlockIndex].mBuffer;
    if (WBT_GetBlock(1, gConnectionWork->mBlockInfos[0]->mId, &gConnectionWork->mCurrentBlockBuffer,
                     gConnectionWork->mBlockInfos[0]->mBlockSize, gConnectionWork->mChunkBitmaps,
                     BlockDataRequestCallback) == 0) {
        gConnectionWork->mStep = savedValue;
        gConnectionWork->mRequestPending = 0;
    }
}

void BlockDataRequestCallback(WBTCommand *record) {
    if (record->mCommand == 4) {
        if (record->mEvent == 5) {
            gConnectionWork->mRequestPending = 0;
        } else {
            SetRequestErrorCode(8);
        }
    } else {
        SetRequestErrorCode(8);
    }
}

void SetWbtOwnAidFromConnection(void) {
    s32 connectionMode = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
    if (connectionMode == 2) {
        if (gConnectionWork->mOwnIndex == 0xffff) {
            SetRequestErrorCode(8);
            return;
        }
        WBT_SetOwnAid(gConnectionWork->mOwnIndex);
    }
}

void StartMPWithBuffers(void) {
    gConnectionWork->mStep = 0xb;
    gConnectionWork->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, gConnectionWork->mMPReceiveBuffer, gConnectionWork->mMPReceiveBufferSize,
                     gConnectionWork->mMPSendBuffer, gConnectionWork->mMPSendBufferSize, 1, 0, 0, 0, 0, 0) != 2) {
        SetRequestErrorCode(2);
    }
}

void AddGhostDataBlock(void *data, u32 size) {
    u16 index = gConnectionWork->mGhostBlockCount;
    WBT_RegisterBlock(&gConnectionWork->mBlockEntries[index].mNode, (u16) (index + 0x3e8), gGhostBlockInfo, data, size,
                      0);
    gConnectionWork->mBlockEntries[index].mBuffer = (u32 *) data;
    gConnectionWork->mGhostBlockCount++;
}

void AddGhostDataBlockWrapper(void *data, u32 size) {
    AddGhostDataBlock(data, size);
}

void RemoveGhostDataBlocks(void) {
    s32 blockIndex;
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        WBT_UnregisterBlock((u16) (blockIndex + 0x3e8));
        gConnectionWork->mBlockEntries[blockIndex].mBuffer = 0;
    }
    gConnectionWork->mGhostBlockCount = 0;
}

#pragma thumb off
