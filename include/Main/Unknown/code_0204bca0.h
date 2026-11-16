#pragma once

#include "types.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/unk_02175000.h"

typedef struct FSFile FSFile;

// Entry of 0x28 bytes; the table of pointers at the start of the object at 0x440 of gRomArchiveTransfer points to them.
typedef struct Unk0204bfac_28 {
    /* 00 */ u8 field0[4];
    /* 04 */ s32 field4;
    /* 08 */ u8 field8[0x20];
} Unk0204bfac_28;

// The object at 0x440 of gRomArchiveTransfer as WFS_InitChild and WFSi_OnChildSystemCallback use it: three tables
// of 16 words, then the entries.
typedef struct RomArchiveChildView {
    /* 000 */ Unk0204bfac_28 *mNodeBuffers[16];
    /* 040 */ u32 mBlockBuffers[16];
    /* 080 */ void *mChunkBitmaps[16];
    /* 0c0 */ Unk0204bfac_28 fieldC0[16];
    /* 340 */ u8 field340[0x7bc];
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
    /* 098 */ s32 field98;
    /* 09c */ s32 field9C;
    /* 0a0 */ s32 fieldA0;
    /* 0a4 */ s32 mBufferOffsets[2];
    /* 0ac */ u8 fieldAC[0x14];
    /* 0c0 */ u8 mBuffers[2][0x400];
} RomArchiveFileNode;

// Words at 0x14 of the object that WFSi_OnChildSystemCallback and WFSi_OnParentSystemCallback receive.
typedef union Unk0204c320_14 {
    u32 mUnk_w;
    struct {
        u16 field14;
        s16 field16;
        s16 field18;
    } h;
    RomArchiveParentViewEntry fieldE;
    RomArchiveMessage mUnk_m;
} Unk0204c320_14;

// Object that WFSi_OnChildSystemCallback and WFSi_OnParentSystemCallback receive.
typedef struct Unk0204c320 {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ u16 field8;
    /* 0a */ u16 fieldA;
    /* 0c */ u8 fieldC[8];
    /* 14 */ Unk0204c320_14 field14;
    /* 20 */ s16 field20;
} Unk0204c320;

// Object that WFSi_PortCallback receives.
typedef struct RomArchivePortMessage {
    /* 00 */ u8 field0[4];
    /* 04 */ u16 field4;
    /* 06 */ u8 field6[6];
    /* 0c */ const u8 *fieldC;
    /* 10 */ u16 field10;
    /* 12 */ u16 field12;
} RomArchivePortMessage;

typedef struct FSFile FSFile;

// Entries of 0x20 bytes after a count word; WFSi_SendAck reads and rewrites the word at 0x18.
typedef struct OverlayTableEntry {
    /* 00 */ u8 field0[0x18];
    /* 18 */ u32 mFileId;
    /* 1c */ u8 field1C[4];
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
