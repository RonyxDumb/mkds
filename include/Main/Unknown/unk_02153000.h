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

// 8-byte entries at 0x90 of SelectCharacter, filled from data_021535b4.
typedef struct SelectCharacterRow {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mNameLayoutEntryIndex;
} SelectCharacterRow;

// 4-byte entries of the table at gSoundRowTable.
typedef struct SoundRow {
    /* 00 */ u8 mUnk_00[4];
} SoundRow;

// 4-byte entries of the tables at data_021534bc, data_021534dc, data_02153500 and data_02153528.
typedef struct SelectCharacterRowPosition {
    /* 00 */ s16 mEntryX;
    /* 02 */ s16 mEntryY;
} SelectCharacterRowPosition;

extern LabelMessageRow gMemberGroupLabelMessageRows[];
extern SelectCharacterRowCellIndices gSelectCharacterRowCellIndices[];
extern SelectCharacterRowPosition data_021534bc[];
extern SelectCharacterRowPosition data_021534dc[];
extern SelectCharacterRowPosition data_02153500[];
extern SelectCharacterRowPosition data_02153528[];
extern SelectCharacterRow data_021535b4[];
extern MemberRowCellIndices gMemberRowCellIndices[];
extern u16 gMemberRowRectIndices[][3];

// Rows of nine words; each name starts at one word of the first row.
extern const char *gResultsBattleVictoryMBNcgrName[][9];
extern const char *gResultsBattleVictoryMBNclrName[][9];
extern const char *gResultsBattleVictoryMUpperNscrName[][9];
extern const char *gResultsBattleVictoryMLowerNscrName[][9];
extern const char *gResultsBattleVictoryMNcgrName[][9];
extern const char *gResultsBattleVictoryMNcerName[][9];
extern const char *gResultsBattleVictoryMONclrName[][9];
extern const char *gResultsBattleVictoryMBnclName[][9];
extern const char *gResultsBattleVictoryMBnllName[][9];
extern u16 data_02153f00[][4];
extern SoundRow gSoundRowTable[];

// Objects whose layout isn't known yet.
extern s32 gCourseMessageIndexTable[];
extern u8 gSurfaceSoundVolumeByRatio[];

extern u32 gCharacterSeqPairNoTable[];
extern u32 gKartMessageIndexTable[];
extern u32 gKartIndexTable[];
extern s32 gCharacterKartIndexTableBattle[];
extern s32 gCharacterKartIndexTable[];

extern u16 data_usa_021537dc[];
extern LabelCanvasEntry data_usa_021537f4[];
extern s16 data_usa_02153834[];
extern u16 data_021530b8[4][4];
extern u16 data_021530d0[4][4];
extern SplitCharFunc *data_021530e8[];
extern u32 data_02153118[][4];
extern u8 data_usa_021530f8[4][4][2];

extern u16 gMultiSelectNSRowCellIndices[][3];

typedef struct MultiSelectNSLabelMessageRow {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ u16 mWidth;
    /* 04 */ u16 mHeight;
    /* 06 */ s16 mEntryIndex;
    /* 08 */ s32 mMessageIndex;
} MultiSelectNSLabelMessageRow;

extern MultiSelectNSLabelMessageRow gMultiSelectNSLabelMessageRows[];
extern s16 gTimeAttackGhostGetScanMLabelTextRows[][4];
extern s16 gTimeAttackGhostGetSlotMLabelTextRows[][4];

// Tables of 12-byte entries (data_usa_02153d7c is the third entry of data_usa_02153d64) and of u16 pairs.
extern LabelMessageRow data_usa_02153d64[];
extern LabelMessageRow data_usa_02153d7c[];
extern LabelMessageRow data_usa_02153d88[];
extern u16 gMultiSelectMemberCycleCells[][2];
extern u16 gMultiSelectMemberCycleFrameLimits[][2];
extern u16 gMultiSelectMemberCountCellIndices[];
extern s16 data_usa_02153dbc[];

// Tables of four u16, written to mUnk_084 of SelectCharacter.
extern u16 data_usa_02153614[4];
extern u16 data_usa_0215361c[4];
extern u16 data_usa_02153624[4];
extern u16 data_usa_0215362c[4];
extern u16 data_usa_02153634[4];
extern u16 data_usa_0215363c[4];
extern u16 data_usa_02153644[4];
extern u16 data_usa_0215364c[4];
extern u16 data_usa_02153654[4];
extern u16 data_usa_0215365c[4];
extern u16 data_usa_02153664[4];
extern u16 data_usa_0215366c[4];
extern u16 data_usa_02153674[4];
extern u16 data_usa_0215367c[4];
extern u16 data_usa_02153684[4];
extern u16 data_usa_0215368c[4];
extern u16 data_usa_02153694[4];
extern u16 data_usa_0215369c[4];
extern u16 data_usa_021536a4[4];
extern u16 data_usa_021536ac[4];
extern u16 data_usa_021536b4[4];
extern u16 data_usa_021536bc[4];
extern u16 data_usa_021536c4[4];
extern u16 data_usa_021536cc[4];
extern u16 data_usa_021536d4[4];
extern u16 data_usa_021536dc[4];
extern u16 data_usa_021536e4[4];
extern u16 data_usa_021536ec[4];
extern u16 data_usa_021536f4[4];
extern u16 data_usa_021536fc[4];
extern u16 data_usa_02153704[4];
extern u16 data_usa_0215370c[4];
extern u16 data_usa_02153714[4];
extern u16 data_usa_0215371c[4];
extern u16 data_usa_02153724[4];
extern u16 data_usa_0215372c[4];
extern u16 data_usa_02153734[4];
extern u16 data_usa_0215373c[4];
extern u16 data_usa_02153744[4];
extern u16 data_usa_0215374c[4];
extern u16 data_usa_02153754[4];
extern u16 data_usa_0215375c[4];
extern u16 data_usa_02153764[4];
extern u16 data_usa_0215376c[4];
extern u16 data_usa_02153774[4];
extern u16 data_usa_0215377c[4];
extern u16 data_usa_02153784[4];
extern u16 data_usa_0215378c[4];
extern u16 data_usa_02153794[4];
extern u16 data_usa_0215379c[4];
extern u16 data_usa_021537a4[4];
extern u16 data_usa_021537ac[4];
extern u16 data_usa_021537b4[4];
extern u16 data_usa_021537bc[4];
extern u16 data_usa_021537c4[4];
extern u16 data_usa_021537cc[4];
extern u16 data_usa_021537d4[4];
