#pragma once

#include "types.h"
#include "Main/Net/wireless_block_requests.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"

typedef struct FSFile FSFile;

// One node buffer of a ROM archive transfer: its mBlockSize and the block bytes.
typedef struct RomArchiveNodeBuffer {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mBlockSize;
    /* 08 */ u8 mUnk_08[0x20];
} RomArchiveNodeBuffer;

// The child side of a ROM archive transfer: node, block and chunk bitmap tables, mOwnAid and the read position.
typedef struct RomArchiveChildView {
    /* 000 */ RomArchiveNodeBuffer *mNodeBuffers[16];
    /* 040 */ u32 mBlockBuffers[16];
    /* 080 */ void *mChunkBitmaps[16];
    /* 0c0 */ RomArchiveNodeBuffer mNodeBufferEntries[16];
    /* 340 */ u8 mWmStatus[0x184];
    /* 4c4 */ u16 mOwnAid;
    /* 4c6 */ u8 mUnk_4c6[0x636];
    /* afc */ void *mChunkBitmapBuffer;
    /* b00 */ u32 mPositionOffset;
    /* b04 */ u32 mMaxReadSize;
    /* b08 */ s32 mFileBlockId;
} RomArchiveChildView;

// RomArchiveTransfer.mState
enum {
    ROM_ARCHIVE_STOPPED,
    ROM_ARCHIVE_STARTING,
    ROM_ARCHIVE_READY,
};

enum {
    ROM_ARCHIVE_NODE_FREE,
    ROM_ARCHIVE_NODE_QUEUED,
    ROM_ARCHIVE_NODE_ACTIVE,
    ROM_ARCHIVE_NODE_FINISHED,
};

// RomArchiveFileNode.mLoadingBufferIndex while neither of the two buffers is being loaded.
#define ROM_ARCHIVE_NODE_NO_BUFFER 2

// One file a ROM archive parent sends: its FSFile, block range, load state and the two read buffers (mBuffers).
typedef struct RomArchiveFileNode {
    /* 000 */ struct RomArchiveFileNode *mNext;
    /* 004 */ WBTBlockInfoList mBlockNode;
    /* 038 */ FSFile mFile;
    /* 080 */ s32 mState;
    /* 084 */ s32 mChildCount;
    /* 088 */ u32 mPendingChildMask;
    /* 08c */ s32 mBlockId;
    /* 090 */ s32 mFileStart;
    /* 094 */ u32 mFileLength;
    /* 098 */ s32 mLastBlockId;
    /* 09c */ s32 mLoadingBufferIndex;
    /* 0a0 */ s32 mLastLoadedBufferIndex;
    /* 0a4 */ s32 mBufferOffsets[2];
    /* 0ac */ u8 mUnk_0ac[0x14];
    /* 0c0 */ u8 mBuffers[2][0x400];
} RomArchiveFileNode;

// Object that RomArchivePortCallback receives.
typedef struct RomArchivePortMessage {
    /* 00 */ u8 mPosition[4];
    /* 04 */ u16 mKind;
    /* 06 */ u8 mEnemyPointId[6];
    /* 0c */ const u8 *mData;
    /* 10 */ u16 mDataLength;
    /* 12 */ u16 mFromIndex;
} RomArchivePortMessage;

// One entry of the overlay table; SendRomArchiveMessage reads mFileId and rewrites it.
typedef struct OverlayTableEntry {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mFileId;
    /* 1c */ u8 mUnk_1c[4];
} OverlayTableEntry;

void WakeRomArchiveThread(void);
u32 SetRomArchiveGroupSendMask(u32 value);
u32 GetRomArchiveState(void);
void StopRomArchive(void);
void StartRomArchivePacketSend(void);
void StartRomArchive(int isParent, u32 port, u32 parentPacketSize, void (*stateCallback)(s32 isParent),
                     void *(*allocFunc)(s32 isParent, u32 port, void *parentPacketSize), u32 allocFuncArg);
void StartRomArchiveChild(u32 port, void (*stateCallback)(s32 port),
                          void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg);
void SomeInitialize(u32 port, void (*stateCallback)(s32 port),
                           void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg,
                           u32 parentPacketSize, FSFile *file, s32 appendOverlays);
void InitRomArchive(u32 port, void (*stateCallback)(s32 port),
                    void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg);
void RomArchiveChildCallback(WBTCommand *record);
void RomArchiveParentCallback(WBTCommand *record);
void RomArchivePortCallback(void *portMessage);
void SendRomArchivePacket(void);
void SomeFileAsyncReadFunc(FSFile *file);
void FreeRomArchiveNode(RomArchiveParentView *view, RomArchiveFileNode *node);
void MoveRomArchiveNodeToList(RomArchiveFileNode **fromHead, RomArchiveFileNode **toHead, RomArchiveFileNode *node);
void ActivateRomArchiveNode(RomArchiveParentView *view, RomArchiveFileNode *node, s32 unused);
void SendRomArchiveMessage(void);
void RomArchiveSendCallback(WBTCommand *record);
u32 SomeRomUnkFatFntReload(u32 *block);
void MaybeSetupRomRootOrOverlays(FSFile *file, s32 appendOverlays);
s32 UnkStruct_ExtraFileOperationHandler_Unk(FSFile *file, u32 command);

typedef struct FSArchive FSArchive;

s32 UnkStruct_WriteFn_RomUnk(FSArchive *archive, const void *src, u32 dst, u32 length);

extern const u8 g_SomeNullString[32];
extern s32 gRomArchiveStarted;
extern s32 gRomArchiveUnusedWord;
extern u8 gRomArchiveUnusedPad[0x18];
