#pragma once

#include "types.h"
#include "Main/Unknown/code_020b3f7c.h" // Bmg
#include "code_0201ea58.h" // Unk0201ea30
#include "Main/Unknown/code_02124094.h" // LayoutTableEntry

// Seven words at 0x24 of MultiSelectMemberGroup, passed by address to mutil2_loadLayout, mutil2_initLayout and
// mutil2_initLabel.
typedef struct Unk02174e50_24 {
    /* 00 */ void *field0;
    /* 04 */ s32 field4;
    /* 08 */ struct Unk02021dc8 *field8;
    /* 0c */ struct Unk0201ea30 *fieldC;
    /* 10 */ Unk0201ea30 *field10;
    /* 14 */ struct Unk0201ea30 *field14;
    /* 18 */ LayoutTableEntry *field18;
} Unk02174e50_24;

// 12-byte entries at 0x58 of MultiSelectMemberGroup.
typedef struct Unk02174e50_58 {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
} Unk02174e50_58;

// 0xa8 bytes.
typedef struct MultiSelectMemberGroup {
    /* 00 */ u8 field0[0x24];
    /* 24 */ Unk02174e50_24 mGroupSParts;
    /* 40 */ void *field40;
    /* 44 */ void *mOamList;
    /* 48 */ s32 mSelectedIndex;
    /* 4c */ s32 mState;
    /* 50 */ s32 field50;
    /* 54 */ s32 mNextCallbacksIndex;
    /* 58 */ Unk02174e50_58 field58[4];
    /* 88 */ BOOL field88;
    /* 8c */ s32 mBg3OffsetFrames;
    /* 90 */ s32 mBg3Offset;
    /* 94 */ s32 mEntriesClearFrames;
    /* 98 */ s32 mState2Frames;
    /* 9c */ BOOL mEntriesCleared;
    /* a0 */ Bmg *mBannerMessages;
    /* a4 */ void *mHeap;
} MultiSelectMemberGroup;

typedef struct SceneNumbersView SceneNumbersView;

#include "Main/Unknown/code_020b4000.h" // Ncgr, Nclr

// 0x40 bytes.
typedef struct MultiSelectNS {
    /* 00 */ Ncgr *mNcgr;
    /* 04 */ Nclr *mNclr;
    /* 08 */ struct Unk02021dc8 *mNcer;
    /* 0c */ Unk0201ea30 *mBncl;
    /* 10 */ void *mBnbl;
    /* 14 */ Unk0201ea30 *mBnll;
    /* 18 */ LayoutTableEntry *mCellTable;
    /* 1c */ void *field1C;
    /* 20 */ void *mOamList;
    /* 24 */ void *mBannerMessages;
    /* 28 */ s32 mIndex;
    /* 2c */ s32 mNextCallbacksIndex;
    /* 30 */ s32 mState;
    /* 34 */ s32 mStateFrames;
    /* 38 */ s32 mOffset;
    /* 3c */ void *mHeap;
} MultiSelectNS;

void WriteMultiSelectMemberGroupRegisters(void);
void ReleaseMultiSelectMemberGroup(void);
s32 AdvanceMultiSelectMemberGroup(SceneNumbersView *sceneNumbers);
void InitMultiSelectMemberGroup(void *parentHeap, void *scene, void *oamList);
void func_0202fd2c(void);
void RefreshMultiSelectMemberGroup(s32 showSelected);
void SetMemberGroupCellTableOffsetY(void);
s32 func_0203023c(void);
s32 IsRectInMemberRow(s32 rectIndex, s32 memberRow);
