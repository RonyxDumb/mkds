#pragma once

#include "types.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/unk_02175000.h"

typedef struct FSFile FSFile;

// Entry of 0x28 bytes; the table of pointers at the start of the object at 0x440 of gRomArchiveTransfer points to them.
typedef struct RomArchiveNodeBuffer {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mBlockSize;
    /* 08 */ u8 mUnk_08[0x20];
} RomArchiveNodeBuffer;

// The object at 0x440 of gRomArchiveTransfer as StartRomArchiveChild and RomArchiveChildCallback use it: three tables
// of 16 words, then the entries.
typedef struct RomArchiveChildView {
    /* 000 */ RomArchiveNodeBuffer *mNodeBuffers[16];
    /* 040 */ u32 mBlockBuffers[16];
    /* 080 */ void *mChunkBitmaps[16];
    /* 0c0 */ RomArchiveNodeBuffer mUnk_0c0[16];
    /* 340 */ u8 mUnk_340[0x7bc];
    /* afc */ void *mChunkBitmapBuffer;
    /* b00 */ u32 mPositionOffset;
    /* b04 */ u32 mMaxReadSize;
    /* b08 */ s32 mFileBlockId;
} RomArchiveChildView;

// Node of 0x8c0 bytes; StartRomArchiveParent chains eight of them from 0xc0 of the object at 0x440 of
// gRomArchiveTransfer.
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
    /* 098 */ s32 mUnk_098;
    /* 09c */ s32 mUnk_09c;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ s32 mBufferOffsets[2];
    /* 0ac */ u8 mUnk_0ac[0x14];
    /* 0c0 */ u8 mBuffers[2][0x400];
} RomArchiveFileNode;

// Object that RomArchivePortCallback receives.
typedef struct RomArchivePortMessage {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ const u8 *mData;
    /* 10 */ u16 mDataLength;
    /* 12 */ u16 mFromIndex;
} RomArchivePortMessage;

typedef struct FSFile FSFile;

// Entries of 0x20 bytes after a count word; SendRomArchiveMessage reads and rewrites the word at 0x18.
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
void StartRomArchiveParent(u32 port, void (*stateCallback)(s32 port),
                           void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg,
                           u32 parentPacketSize, FSFile *file, s32 appendOverlays);
void InitRomArchive(u32 port, void (*stateCallback)(s32 port),
                    void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg);
void RomArchiveChildCallback(WBTCommand *record);
void RomArchiveParentCallback(WBTCommand *record);
void RomArchivePortCallback(RomArchivePortMessage *message);
void SendRomArchivePacket(void);
void RequestRomArchiveBytes(FSFile *file);
void FreeRomArchiveNode(RomArchiveParentView *view, RomArchiveFileNode *node);
void MoveRomArchiveNodeToList(RomArchiveFileNode **fromHead, RomArchiveFileNode **toHead, RomArchiveFileNode *node);
void ActivateRomArchiveNode(RomArchiveParentView *view, RomArchiveFileNode *node, s32 unused);
void SendRomArchiveMessage(void);
void RomArchiveSendCallback(WBTCommand *record);
u32 ReloadRomArchiveFromBlock(u32 *block);
void CreateRomArchiveBlock(FSFile *file, s32 appendOverlays);
s32 RomArchiveChildProc(FSFile *file, u32 command);
