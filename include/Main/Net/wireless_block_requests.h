#pragma once

#include "types.h"
#include "Main/Net/wireless_block_transfer.h"

typedef struct WBTCommand WBTCommand;
typedef struct BlockTransfer BlockTransfer;

// A registered block: its id, its size and the user id.
typedef struct WBTBlockInfo {
    /* 00 */ u32 mId;
    /* 04 */ s32 mBlockSize;
    /* 08 */ u8 mUserId[0x20];
} WBTBlockInfo;

// WBTBlockInfoList.mBlockType.
typedef enum BlockTransferBlockType {
    XFER_BLOCK_TYPE_MEMORY = 0, // the chunks are read from mDataPtr
    XFER_BLOCK_TYPE_SUPPLIED = 1, // registered without a buffer; the callback supplies each chunk
} BlockTransferBlockType;

// A registered block: its WBTBlockInfo in mDataInfo, the mNext link, the mDataPtr buffer, the mPermissionBmp and the
// mBlockType.
typedef struct WBTBlockInfoList {
    /* 00 */ WBTBlockInfo mDataInfo;
    /* 28 */ struct WBTBlockInfoList *mNext;
    /* 2c */ u8 *mDataPtr;
    /* 30 */ u16 mPermissionBmp;
    /* 32 */ u16 mBlockType;
} WBTBlockInfoList;

u32 WBT_MpParentSendHook(u8 *buffer, s32 bufferSize);
void WBT_End(void);
void WBT_InitChild(void (*callback)(WBTCommand *));
void WBT_InitParent(s32 sendSize, s32 receiveSize, void (*callback)(WBTCommand *));
void BuildChildPacketUnchecked(u8 *buffer, s32 bufferSize);
void ReceiveParentPacket(const u8 *packet, u32 size);
void ReceivePacketFromIndex(u32 index, const u8 *packet, int size);
s32 BuildParentPacketUnchecked(u8 *buffer, s32 bufferSize);
u32 WBT_PutUserData(u16 indexMask, const void *bytes, s32 byteCount, void (*callback)(WBTCommand *));
u32 WBT_GetBlock(u16 indexMask, u32 blockId, const void *buffers, u32 blockSize, const void *chunkBitmaps,
                 void (*callback)(WBTCommand *));
u32 WBT_GetBlockInfo(u16 indexMask, u32 blockIdOrPosition, const void *buffers, void (*callback)(WBTCommand *));
u32 WBT_RequestSync(u16 indexMask, void (*callback)(WBTCommand *));
WBTBlockInfoList *WBT_UnregisterBlock(u32 blockId);
s32 WBT_RegisterBlock(WBTBlockInfoList *node, u32 blockId, const void *info, u8 *data, u32 size, u16 permissionBmp);
int WBT_NumOfRegisteredBlock(void);
u32 WBT_SetPacketSize(s32 sendSize, s32 receiveSize);
BOOL WBT_GetCurrentDownloadProgress(u32 blockId, s32 entryIndex, s32 *receivedChunkCountOut, s32 *chunkCountOut);
u32 WBT_CalcPacketbitmapSize(s32 size);
s32 WBT_AidbitmapToAid(s32 mask);
unsigned int WBT_GetOwnAid(void);
void WBT_SetOwnAid(unsigned int index);
WBTBlockInfoList *FindBlockById(u32 blockId);
void SetBlockListHead(WBTBlockInfoList *head);
WBTBlockInfoList *GetBlockListHead(void);
u32 TrySetNextRequest(const WBTCommand *request);
WBTCommand *GetNextRequestAddress(void);
BlockTransfer *GetBlockTransfer(void);
void SetSendChunkSize(unsigned int chunkSize);
void SetReceiveChunkSize(unsigned int chunkSize);
unsigned int WBT_GetOwnPacketLength(void);
unsigned int WBT_GetPeerPacketLength(void);

extern s32 gLastReplyIndex;
extern u32 gOwnIndex;
