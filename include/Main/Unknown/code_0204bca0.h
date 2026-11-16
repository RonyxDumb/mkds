#pragma once

#include "types.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/unk_02175000.h"

typedef struct FSFile FSFile;

// Entry of 0x28 bytes; the table of pointers at the start of the object at 0x440 of gRomArchiveTransfer points to them.
typedef struct Unk0204bfac_28 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x20];
} Unk0204bfac_28;

// The object at 0x440 of gRomArchiveTransfer as WFS_InitChild and WFSi_OnChildSystemCallback use it: three tables
// of 16 words, then the entries.
typedef struct RomArchiveChildView {
    /* 000 */ Unk0204bfac_28 *mNodeBuffers[16];
    /* 040 */ u32 mBlockBuffers[16];
    /* 080 */ void *mChunkBitmaps[16];
    /* 0c0 */ Unk0204bfac_28 mUnk_0c0[16];
    /* 340 */ u8 mUnk_340[0x7bc];
    /* afc */ void *mChunkBitmapBuffer;
    /* b00 */ u32 mPositionOffset;
    /* b04 */ u32 mMaxReadSize;
    /* b08 */ s32 mFileBlockId;
} RomArchiveChildView;

// Node of 0x8c0 bytes; WFS_InitParent chains eight of them from 0xc0 of the object at 0x440 of
// gRomArchiveTransfer.
typedef struct RomArchiveFileNode {
    /* 000 */ struct RomArchiveFileNode *mNext;
    /* 004 */ BlockListNode mBlockNode;
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

// Words at 0x14 of the object that WFSi_OnChildSystemCallback and WFSi_OnParentSystemCallback receive.
typedef union Unk0204c320_14 {
    u32 mUnk_w;
    struct {
        u16 mUnk_14;
        s16 mUnk_16;
        s16 mUnk_18;
    } h;
    RomArchiveParentViewEntry mUnk_0e;
    RomArchiveMessage mUnk_m;
} Unk0204c320_14;

// Object that WFSi_OnChildSystemCallback and WFSi_OnParentSystemCallback receive.
typedef struct Unk0204c320 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[8];
    /* 14 */ Unk0204c320_14 mUnk_14;
    /* 20 */ s16 mUnk_20;
} Unk0204c320;

// Object that WFSi_PortCallback receives.
typedef struct RomArchivePortMessage {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ const u8 *mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} RomArchivePortMessage;

typedef struct FSFile FSFile;

// Entries of 0x20 bytes after a count word; WFSi_SendAck reads and rewrites the word at 0x18.
typedef struct OverlayTableEntry {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mFileId;
    /* 1c */ u8 mUnk_1c[4];
} OverlayTableEntry;

void WFSi_NotifyBusy(void);
u32 WFS_EnableSync(u32 value);
u32 WFS_GetStatus(void);
void WFS_End(void);
void WFS_Start(void);
void WFS_Init(int isParent, u32 port, u32 parentPacketSize, void (*stateCallback)(s32 isParent),
                     void *(*allocFunc)(s32 isParent, u32 port, void *parentPacketSize), u32 allocFuncArg);
void WFS_InitChild(u32 port, void (*stateCallback)(s32 port),
                          void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg);
void WFS_InitParent(u32 port, void (*stateCallback)(s32 port),
                           void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg,
                           u32 parentPacketSize, FSFile *file, s32 appendOverlays);
void WFSi_InitCommon(u32 port, void (*stateCallback)(s32 port),
                    void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg);
void WFSi_OnChildSystemCallback(Unk0204c320 *record);
void WFSi_OnParentSystemCallback(Unk0204c320 *record);
void WFSi_PortCallback(RomArchivePortMessage *message);
void WFSi_SetMPData(void);
void WFSi_ReadRequest(FSFile *file);
void WFSi_FromBusyToFree(RomArchiveParentView *view, RomArchiveFileNode *node);
void WFSi_MoveList(RomArchiveFileNode **fromHead, RomArchiveFileNode **toHead, RomArchiveFileNode *node);
void WFSi_SendOpenAck(RomArchiveParentView *view, RomArchiveFileNode *node, s32 c);
void WFSi_SendAck(void);
void WFSi_OnSendMessageDone(void);
u32 WFSi_ReplaceRomArchive(u32 *block);
void WFSi_LoadTables(FSFile *file, s32 appendOverlays);
s32 WFSi_RomArchiveProc(FSFile *file, u32 command);
