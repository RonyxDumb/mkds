#include "Main/Net/block.h"
#include "Main/Net/wireless_block_requests.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/scan.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/System/backup_net_camera_work.h"

const u8 g_str_NitroKartGhostDataTest[32] = {0x4e, 0x69, 0x74, 0x72, 0x6f, 0x4b, 0x61, 0x72, 0x74, 0x20, 0x47,
                                0x68, 0x6f, 0x73, 0x74, 0x20, 0x44, 0x61, 0x74, 0x61, 0x20, 0x54,
                                0x65, 0x73, 0x74, 0x20, 0x30, 0x31, 0x20, 0x20, 0x20, 0x20};

#pragma thumb on

void StartBlockCountRequest(void) {
    s32 savedValue = g_GlobalZE->mStep;
    u8 mask;
    s32 connectionMode = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
    if (connectionMode == CONNECTION_MODE_PARENT) {
        mask = g_GlobalZE->mChildren.mChildMask;
    } else {
        mask = 1;
    }
    g_GlobalZE->mStep = CONNECTION_STEP_BLOCK_COUNT_REQUEST;
    g_GlobalZE->mRequestPending = 1;
    if (WBT_RequestSync(mask, BlockCountRequestCallback) == 0) {
        g_GlobalZE->mRequestPending = 0;
        g_GlobalZE->mStep = savedValue;
    }
}

void BlockCountRequestCallback(WBTCommand *record) {
    if (record->mCommand == XFER_COMMAND_HANDSHAKE) {
        if (record->mEvent == XFER_EVENT_HANDSHAKE_ENDED) {
            g_GlobalZE->mBlockCount = record->mData.mSync.mNumOfList;
            g_GlobalZE->mRequestPending = 0;
        } else {
            SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
        }
    } else {
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    }
}

void StartBlockNodeRequest(void) {
    s32 savedValue = g_GlobalZE->mStep;
    g_GlobalZE->mStep = CONNECTION_STEP_BLOCK_NODE_REQUEST;
    g_GlobalZE->mRequestPending = 1;
    if (WBT_GetBlockInfo(1, g_GlobalZE->mBlockIndex, g_GlobalZE->mBlockInfos, BlockNodeRequestCallback) ==
        0) {
        g_GlobalZE->mStep = savedValue;
        g_GlobalZE->mRequestPending = 0;
    }
}

void BlockNodeRequestCallback(WBTCommand *record) {
    if (record->mCommand == XFER_COMMAND_FETCH_DETAILS) {
        if (record->mEvent == XFER_EVENT_LAYOUT_ENDED) {
            g_GlobalZE->mRequestPending = 0;
        } else {
            StartBlockNodeRequest();
        }
    } else {
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    }
}

void StartBlockDataRequest(void) {
    s32 savedValue = g_GlobalZE->mStep;
    g_GlobalZE->mStep = CONNECTION_STEP_BLOCK_DATA_REQUEST;
    g_GlobalZE->mRequestPending = 1;
    g_GlobalZE->mCurrentBlockBuffer = g_GlobalZE->mBlockEntries[g_GlobalZE->mBlockIndex].mBuffer;
    if (WBT_GetBlock(1, g_GlobalZE->mBlockInfos[0]->mId, &g_GlobalZE->mCurrentBlockBuffer,
                     g_GlobalZE->mBlockInfos[0]->mBlockSize, g_GlobalZE->mChunkBitmaps,
                     BlockDataRequestCallback) == 0) {
        g_GlobalZE->mStep = savedValue;
        g_GlobalZE->mRequestPending = 0;
    }
}

void BlockDataRequestCallback(WBTCommand *record) {
    if (record->mCommand == XFER_COMMAND_FETCH_DATA) {
        if (record->mEvent == XFER_EVENT_DATA_ENDED) {
            g_GlobalZE->mRequestPending = 0;
        } else {
            SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
        }
    } else {
        SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
    }
}

void SetWbtOwnAidFromConnection(void) {
    s32 connectionMode = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
    if (connectionMode == CONNECTION_MODE_CHILD) {
        if (g_GlobalZE->mOwnIndex == CONNECTION_OWN_INDEX_NONE) {
            SetRequestErrorCode(CONNECTION_ERROR_OPERATION_FAILED);
            return;
        }
        WBT_SetOwnAid(g_GlobalZE->mOwnIndex);
    }
}

void StartMPWithBuffers(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_STARTING_EXCHANGE;
    g_GlobalZE->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, g_GlobalZE->mMPReceiveBuffer, g_GlobalZE->mMPReceiveBufferSize,
                     g_GlobalZE->mMPSendBuffer, g_GlobalZE->mMPSendBufferSize, 1, 0, 0, 0, 0, 0) != 2) {
        SetRequestErrorCode(CONNECTION_ERROR_MP_FAILED);
    }
}

void NitroKartStringFunction_from_thumb(void *data, u32 size) {
    u16 index = g_GlobalZE->mGhostBlockCount;
    StructGO_SomeFn_from_thumb(&g_GlobalZE->mBlockEntries[index].mNode, (u16) (index + 0x3e8), g_str_NitroKartGhostDataTest, data, size,
                      0);
    g_GlobalZE->mBlockEntries[index].mBuffer = data;
    g_GlobalZE->mGhostBlockCount++;
}

void j_NitroKartStringFunction_from_thumb(void *data, u32 size) {
    NitroKartStringFunction_from_thumb(data, size);
}

void RemoveGhostDataBlocks(void) {
    s32 blockIndex;
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        WBT_UnregisterBlock((u16) (blockIndex + 0x3e8));
        g_GlobalZE->mBlockEntries[blockIndex].mBuffer = 0;
    }
    g_GlobalZE->mGhostBlockCount = 0;
}

#pragma thumb off
