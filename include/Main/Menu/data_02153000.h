#pragma once
#include "types.h"
#include "code_02022aa8.h"
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
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mCharacterCellIndex;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mRectEntryId;
} SelectCharacterRowCellIndices;

// 8-byte entries at 0x90 of SelectCharacter, filled from gSelectCharacterRows.
typedef struct SelectCharacterRow {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mNameLayoutEntryIndex;
} SelectCharacterRow;

// 4-byte entries of the table at gSoundRowTable.
typedef struct SoundRow {
    /* 00 */ u8 mUnk_00[4];
} SoundRow;

// 4-byte entries of the tables at gSelectCharacterPositions8Rows, gSelectCharacterPositions9Rows, gSelectCharacterPositions10Rows and gSelectCharacterPositions11Rows.
typedef struct SelectCharacterRowPosition {
    /* 00 */ s16 mEntryX;
    /* 02 */ s16 mEntryY;
} SelectCharacterRowPosition;

extern SelectCharacterRowCellIndices gSelectCharacterRowCellIndices[];

extern SelectCharacterRowPosition gSelectCharacterPositions8Rows[];

extern SelectCharacterRowPosition gSelectCharacterPositions9Rows[];

extern SelectCharacterRowPosition gSelectCharacterPositions10Rows[];

extern SelectCharacterRowPosition gSelectCharacterPositions11Rows[];

extern SelectCharacterRow gSelectCharacterRows[];

// Objects whose layout isn't known yet.
extern s32 gCourseMessageIndexTable[];

extern u32 gKartMessageIndexTable[];

extern u32 gKartIndexTable[];

extern s32 gCharacterKartIndexTableBattle[];

extern s32 gCharacterKartIndexTable[];

typedef struct MultiSelectNSLabelMessageRow {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ u16 mWidth;
    /* 04 */ u16 mHeight;
    /* 06 */ s16 mEntryIndex;
    /* 08 */ s32 mMessageIndex;
} MultiSelectNSLabelMessageRow;

extern s16 gTimeAttackGhostGetSlotMLabelTextRows[][4];

// Tables of 12-byte entries (data_usa_02153d7c is the third entry of data_usa_02153d64) and of u16 pairs.
extern LabelMessageRow data_usa_02153d64[];

extern LabelMessageRow data_usa_02153d7c[];

extern LabelMessageRow data_usa_02153d88[];

extern u16 gMultiSelectMemberCycleCells[][2];

extern u16 gMultiSelectMemberCycleFrameLimits[][2];

extern u16 gMultiSelectMemberCountCellIndices[];

extern s16 data_usa_02153dbc[];

