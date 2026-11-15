#pragma once
#include "types.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"

// 12-byte entries of the table at gMemberGroupLabelMessageRows.
typedef struct LabelMessageRow {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ s16 mWidth;
    /* 04 */ s16 mHeight;
    /* 06 */ s16 mCellIndex;
    /* 08 */ s32 mMessageIndex;
} LabelMessageRow;

// 0x32-byte entries of the table at gMemberRowCellIndices.
typedef struct MemberRowCellIndices {
    /* 00 */ u16 mCellIndices[0x18];
    /* 30 */ u16 mLabelIndex;
} MemberRowCellIndices;

// 8-byte entries of the table at gSelectCharacterRowCellIndices.
typedef struct SelectCharacterRowCellIndices {
    /* 00 */ s16 mBracketCellIndex;
    /* 02 */ s16 mCharacterCellIndex;
    /* 04 */ s16 mOffsetCellIndex;
    /* 06 */ s16 mRectEntryId;
} SelectCharacterRowCellIndices;

// 8-byte entries at 0x90 of SelectCharacter, filled from gSelectCharacterRows.
typedef struct SelectCharacterRow {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s16 mNameLayoutEntryIndex;
    /* 06 */ u8 mUnk_06[2];
} SelectCharacterRow;

// 4-byte entries of the table at gSoundRowTable.
typedef struct SoundRow {
    /* 00 */ u8 mSeqStartProgress;
    /* 01 */ u8 mSeqId;
    /* 02 */ u8 mFirstBankId;
    /* 03 */ u8 mSecondBankId;
} SoundRow;

// 4-byte entries of the tables at gSelectCharacterPositions8Rows, gSelectCharacterPositions9Rows,
// gSelectCharacterPositions10Rows and gSelectCharacterPositions11Rows.
typedef struct SelectCharacterRowPosition {
    /* 00 */ s16 mEntryX;
    /* 02 */ s16 mEntryY;
} SelectCharacterRowPosition;

// One row of the label table of the multi select screen: label, size, entry and message index.
typedef struct MultiSelectNSLabelMessageRow {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ u16 mWidth;
    /* 04 */ u16 mHeight;
    /* 06 */ s16 mEntryIndex;
    /* 08 */ s32 mMessageIndex;
} MultiSelectNSLabelMessageRow;

// One step of the cell cycle of the multi-select member screen: the visible cell and the frames it stays.
typedef struct MultiSelectMemberCycleStep {
    /* 00 */ u16 mCellIndex;
    /* 02 */ u16 mFrameLimit;
} MultiSelectMemberCycleStep;

#define MULTI_SELECT_MEMBER_CYCLE_STEP_COUNT 4
extern const MultiSelectMemberCycleStep gMultiSelectMemberCycleSteps[MULTI_SELECT_MEMBER_CYCLE_STEP_COUNT];

// The label rows of the sub screen. The code indexes mRows up to 8; the rows after the fifth are in
// gMultiSelectKeyStartLabelData, which follows in the next file.
typedef struct MultiSelectMemberSubLabelRows {
    /* 00 */ LabelMessageRow mRows[5];
    /* 3c */ s16 mNextLabelIndex;
    /* 3e */ s16 mNextWidth;
} MultiSelectMemberSubLabelRows;

extern const LabelMessageRow gMultiSelectMemberMainLabelRows[2];

extern const MultiSelectMemberSubLabelRows gMultiSelectMemberSubLabelRows;

extern const u16 gMultiSelectMemberCountCellIndices[8];
