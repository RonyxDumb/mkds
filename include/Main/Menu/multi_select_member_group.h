#pragma once

#include "types.h"
#include "Main/Graphics/locate_bmg_sections.h" // Bmg
#include "Main/Graphics/layout_rect_table.h" // LayoutEntryTable
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry

// The files of one cell set: chars, palette, cells, rects and the cell layouts and label layout built from them.
typedef struct CellFileSet {
    /* 00 */ Ncgr *mChars;
    /* 04 */ Nclr *mPalette;
    /* 08 */ struct NNSG2dCellDataBank *mCells;
    /* 0c */ LayoutEntryTable *mCellLayout;
    /* 10 */ struct LayoutEntryTable *mRects;
    /* 14 */ LayoutEntryTable *mLabelLayout;
    /* 18 */ LayoutTableEntry *mCellTable;
} CellFileSet;

// One member slot row of a multi select group: whether it has text, is multiboot and how many children it has.
typedef struct ScanSlotMemberRow {
    /* 00 */ s32 mHasText;
    /* 04 */ s32 mIsMultiBoot;
    /* 08 */ s32 mChildCount;
} ScanSlotMemberRow;

// Member rows of the group list; the row after them is the return row (MultiSelectMemberGroup.mSelectedIndex).
#define MULTI_SELECT_MEMBER_GROUP_ROW_COUNT 4
#define MULTI_SELECT_MEMBER_GROUP_RETURN_ROW 4
// Steps of the slide in and out, steps the pressed row is shown, frames after which the member entries are cleared.
#define MULTI_SELECT_MEMBER_GROUP_SLIDE_STEPS 10
#define MULTI_SELECT_MEMBER_GROUP_PRESS_STEPS 5
#define MULTI_SELECT_MEMBER_GROUP_CLEAR_FRAMES 0x78

// Values of MultiSelectMemberGroup.mState: the panel slides in, waits for a choice, the choice is shown for 5 frames,
// the panel slides out, then the next callbacks index is returned. NONE is only compared with.
enum {
    MULTI_SELECT_MEMBER_GROUP_STATE_NONE = -1,
    MULTI_SELECT_MEMBER_GROUP_STATE_SLIDE_IN,
    MULTI_SELECT_MEMBER_GROUP_STATE_CHOOSE,
    MULTI_SELECT_MEMBER_GROUP_STATE_PRESS_WAIT,
    MULTI_SELECT_MEMBER_GROUP_STATE_SLIDE_OUT,
    MULTI_SELECT_MEMBER_GROUP_STATE_DONE,
};

// Values of MultiSelectMemberGroup.mUpdateState: wait for the multiboot setup, poll the scan slots, wait for the
// connection to end, then done. The other numbers are never used.
enum {
    MULTI_SELECT_MEMBER_GROUP_UPDATE_WAIT_SETUP = 0,
    MULTI_SELECT_MEMBER_GROUP_UPDATE_POLL_SLOTS = 1,
    MULTI_SELECT_MEMBER_GROUP_UPDATE_WAIT_CONNECTION_END_ON_LEAVE = 5,
    MULTI_SELECT_MEMBER_GROUP_UPDATE_WAIT_CONNECTION_END_ALT = 8,
    MULTI_SELECT_MEMBER_GROUP_UPDATE_DONE = 11,
};

// 0xa8 bytes.
typedef struct MultiSelectMemberGroup {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ CellFileSet mGroupSParts;
    /* 40 */ void *mScene;
    /* 44 */ void *mOamList;
    /* 48 */ s32 mSelectedIndex;
    /* 4c */ s32 mState;
    /* 50 */ s32 mUpdateState;
    /* 54 */ s32 mNextCallbacksIndex;
    /* 58 */ ScanSlotMemberRow mMemberRows[4];
    /* 88 */ BOOL mRowPressed;
    /* 8c */ s32 mBg3OffsetFrames;
    /* 90 */ s32 mBg3Offset;
    /* 94 */ s32 mEntriesClearFrames;
    /* 98 */ s32 mPressWaitFrames;
    /* 9c */ BOOL mEntriesCleared;
    /* a0 */ Bmg *mBannerMessages;
    /* a4 */ void *mHeap;
} MultiSelectMemberGroup;

typedef struct SceneNumbers SceneNumbers;

#include "Main/Graphics/font_and_player_character.h" // Ncgr, Nclr
#include "Main/Menu/menu_label_cell_rows.h"
#include "Main/Menu/label_palette_indices.h"
#include "Main/Menu/wl_menu_scene.h"

// Values of MultiSelectNS.mState: the panel slides in, waits for a choice, the choice is shown for 5 frames, the panel
// slides out, then the next callbacks index is returned.
enum {
    MULTI_SELECT_NS_STATE_SLIDE_IN,
    MULTI_SELECT_NS_STATE_CHOOSE,
    MULTI_SELECT_NS_STATE_PRESS_WAIT,
    MULTI_SELECT_NS_STATE_SLIDE_OUT,
    MULTI_SELECT_NS_STATE_DONE,
};

// 0x40 bytes.
typedef struct MultiSelectNS {
    /* 00 */ Ncgr *mNcgr;
    /* 04 */ Nclr *mNclr;
    /* 08 */ struct NNSG2dCellDataBank *mNcer;
    /* 0c */ LayoutEntryTable *mBncl;
    /* 10 */ void *mBnbl;
    /* 14 */ LayoutEntryTable *mBnll;
    /* 18 */ LayoutTableEntry *mCellTable;
    /* 1c */ void *mScene;
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
s32 AdvanceMultiSelectMemberGroup(SceneNumbers *sceneNumbers);
void InitMultiSelectMemberGroup(void *parentHeap, void *scene, void *oamList);
void UpdateMemberRowsFromScanSlots(void);
void RefreshMultiSelectMemberGroup(s32 showSelected);
void SetMemberGroupCellTableOffsetY(void);
s32 IsSelectedMemberRowSelectable(void);
s32 IsRectInMemberRow(s32 rectIndex, s32 memberRow);

extern const u16 gMemberRowRectIndices[4][3];
extern const LabelMessageRow gMemberGroupLabelMessageRows[5];
extern const MemberRowCellIndices gMemberRowCellIndices[4];
extern LabelPaletteIndices gMemberLabelPaletteIndices;
extern struct WLMenuCallbacks gMultiSelectMemberGroupCallbacks;
extern struct MultiSelectMemberGroup *gMultiSelectMemberGroup;
