#include "Main/Net/block.h"
#include "Main/Net/wireless_block_requests.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/scan.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/System/backup_net_camera_work.h"

const u8 gGhostBlockInfo[32] = {0x4e, 0x69, 0x74, 0x72, 0x6f, 0x4b, 0x61, 0x72, 0x74, 0x20, 0x47,
                                0x68, 0x6f, 0x73, 0x74, 0x20, 0x44, 0x61, 0x74, 0x61, 0x20, 0x54,
                                0x65, 0x73, 0x74, 0x20, 0x30, 0x31, 0x20, 0x20, 0x20, 0x20};

#pragma thumb on

void StartBlockCountRequest(void) {
    s32 savedValue = gConnectionWork->mStep;
    u8 mask;
    s32 connectionMode = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
    if (connectionMode == CONNECTION_MODE_PARENT) {
        mask = gConnectionWork->mChildren.mChildMask;
    } else {
        mask = 1;
    }
    gConnectionWork->mStep = CONNECTION_STEP_BLOCK_COUNT_REQUEST;
    gConnectionWork->mRequestPending = 1;
    if (WBT_RequestSync(mask, BlockCountRequestCallback) == 0) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mStep = savedValue;
    }
}

void BlockCountRequestCallback(WBTCommand *record) {
    if (record->mCommand == XFER_COMMAND_HANDSHAKE) {
        if (record->mEvent == XFER_EVENT_HANDSHAKE_ENDED) {
            gConnectionWork->mBlockCount = record->mData.mSync.mNumOfList;
            gConnectionWork->mRequestPending = 0;
        } else {
            SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
        }
    } else {
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    }
}

void StartBlockNodeRequest(void) {
    s32 savedValue = gConnectionWork->mStep;
    gConnectionWork->mStep = CONNECTION_STEP_BLOCK_NODE_REQUEST;
    gConnectionWork->mRequestPending = 1;
    if (WBT_GetBlockInfo(1, gConnectionWork->mBlockIndex, gConnectionWork->mBlockInfos, BlockNodeRequestCallback) ==
        0) {
        gConnectionWork->mStep = savedValue;
        gConnectionWork->mRequestPending = 0;
    }
}

void BlockNodeRequestCallback(WBTCommand *record) {
    if (record->mCommand == XFER_COMMAND_FETCH_NODE) {
        if (record->mEvent == XFER_EVENT_NODE_ENDED) {
            gConnectionWork->mRequestPending = 0;
        } else {
            StartBlockNodeRequest();
        }
    } else {
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    }
}

void StartBlockDataRequest(void) {
    s32 savedValue = gConnectionWork->mStep;
    gConnectionWork->mStep = CONNECTION_STEP_BLOCK_DATA_REQUEST;
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
    if (record->mCommand == XFER_COMMAND_FETCH_DATA) {
        if (record->mEvent == XFER_EVENT_DATA_ENDED) {
            gConnectionWork->mRequestPending = 0;
        } else {
            SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
        }
    } else {
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    }
}

void SetWbtOwnAidFromConnection(void) {
    s32 connectionMode = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
    if (connectionMode == CONNECTION_MODE_CHILD) {
        if (gConnectionWork->mOwnIndex == CONNECTION_OWN_INDEX_NONE) {
            SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
            return;
        }
        WBT_SetOwnAid(gConnectionWork->mOwnIndex);
    }
}

void StartMPWithBuffers(void) {
    gConnectionWork->mStep = CONNECTION_STEP_STARTING_EXCHANGE;
    gConnectionWork->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, gConnectionWork->mMPReceiveBuffer, gConnectionWork->mMPReceiveBufferSize,
                     gConnectionWork->mMPSendBuffer, gConnectionWork->mMPSendBufferSize, 1, 0, 0, 0, 0, 0) != 2) {
        SetRequestErrorCode(CONNECTION_ERROR_MP_FAILED);
    }
}

void AddGhostDataBlock(void *data, u32 size) {
    u16 index = gConnectionWork->mGhostBlockCount;
    WBT_RegisterBlock(&gConnectionWork->mBlockEntries[index].mNode, (u16) (index + 0x3e8), gGhostBlockInfo, data, size,
                      0);
    gConnectionWork->mBlockEntries[index].mBuffer = data;
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
