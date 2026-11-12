#pragma once

#include "types.h"
#include "Main/System/interpolation_value.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"

// 0xc-byte elements from 0xe0 of MultiSelectMember.
typedef struct MultiSelectMemberRow {
    /* 00 */ s32 mState;
    /* 04 */ s32 mStateFrames;
    /* 08 */ u16 mFirstCellIndex;
    /* 0a */ u16 mSecondCellIndex;
} MultiSelectMemberRow;

// 0x154 bytes.
typedef struct MultiSelectMember {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ CellFileSet mCellFileSets[2];
    /* 5c */ void *mMainOam;
    /* 60 */ void *mSubOam;
    /* 64 */ Bmg *mBannerMessages;
    /* 68 */ Bmg *mCommonMessages;
    /* 6c */ s32 mResult;
    /* 70 */ s32 mSetupState;
    /* 74 */ s32 mChildCount;
    /* 78 */ BOOL mStartPending;
    /* 7c */ BOOL mReturnPending;
    /* 80 */ BOOL mNameLabelDone;
    /* 84 */ s32 mUnk_84;
    /* 88 */ BOOL mUnk_88;
    /* 8c */ BOOL mConnectionNamesDone;
    /* 90 */ s32 mStarted;
    /* 94 */ s32 mState;
    /* 98 */ s32 mState2Frames;
    /* 9c */ s32 mTimer;
    /* a0 */ Interpolation mInterpolations[4];
    /* e0 */ MultiSelectMemberRow mRows[8];
    /* 140 */ s32 mCycleIndex;
    /* 144 */ s32 mCycleFrames;
    /* 148 */ BOOL mSeqZeroLoopStartPending;
    /* 14c */ s32 mSeqZeroLoopStartFrames;
    /* 150 */ void *mHeap;
} MultiSelectMember;

typedef struct SceneNumbers SceneNumbers;

#include "Main/Unknown/unk_02174000.h"

void WriteMultiSelectMemberRegisters(void);
void ReleaseMultiSelectMember(void);
s32 AdvanceMultiSelectMemberNoKeyStart(SceneNumbers *sceneNumbers);
s32 AdvanceMultiSelectMemberKeyStart(SceneNumbers *sceneNumbers);
void DrawMultiSelectMember(void);
BOOL MultiSelectMemberIsSubSlideOutDone(void);
BOOL MultiSelectMemberIsSubSlideInDone(void);
void InitMultiSelectMemberNoKeyStart(void *parentHeap, void *mainOam, void *subOam);
void InitMultiSelectMemberKeyStart(void *parentHeap, void *mainOam, void *subOam);
void InitMultiSelectMember(void *parentHeap, void *mainOam, void *subOam);
void UpdateMultiSelectMemberNoKeySetup(void);
void UpdateMultiSelectMemberKeySetup(void);
void SetMultiSelectMemberSubCellVisible(s32 visible);
void SetMultiSelectChildCountCellsVisible(void);
void UpdateMultiSelectMemberCells(void);
void PrintMultiSelectConnectionNames(void);
void PrintMultiSelectMemberNames(void);
s32 CountMultiSelectChildren(void);
void SetupMultiSelectMemberSubTextButton(void);
