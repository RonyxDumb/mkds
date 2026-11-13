#pragma once

#include "types.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "g2d_Animation.h" // NNSG2dCellDataWithBR

// Object behind member 0x04 of the elements of the tables of RaceNcerNclrNcgrTables: a halfword at 0x04.
typedef struct Unk020b6e00 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk020b6e00;

// Cells of race_m.NCER (mRaceMNcerEntries) that the item display picks: the box behind the item without teams and for
// each team, the empty item and the slot frame, then one cell per item as LookupRaceMNcerIndex maps them.
typedef enum {
    RACE_M_CELL_SLOT_BOX_NO_TEAMS = 8,
    RACE_M_CELL_SLOT_BOX_TEAM_0,
    RACE_M_CELL_SLOT_BOX_TEAM_1,
    RACE_M_CELL_ITEM_EMPTY,
    RACE_M_CELL_SLOT_FRAME,
    RACE_M_CELL_KINOKO_ONE,
    RACE_M_CELL_KINOKO_TWO,
    RACE_M_CELL_KINOKO_THREE,
    RACE_M_CELL_KOURA_R,
    RACE_M_CELL_KOURA_R_THREE,
    RACE_M_CELL_KOURA_G,
    RACE_M_CELL_KOURA_G_THREE,
    RACE_M_CELL_F_BOX,
    RACE_M_CELL_TERESA,
    RACE_M_CELL_BOMB,
    RACE_M_CELL_BANANA,
    RACE_M_CELL_BANANA_THREE,
    RACE_M_CELL_THUNDER,
    RACE_M_CELL_STAR,
    RACE_M_CELL_KOURA_W,
    RACE_M_CELL_KILLER,
    RACE_M_CELL_GESSO,
    RACE_M_CELL_KINOKO_P,
    RACE_M_CELL_BOUNCING_ITEM_BOX
} RaceMCell;

// Cells of race_s.NCER (mRaceSNcerEntries) that LookupRaceSNcerIndex picks per item; cells 0..7 are the kart cells.
typedef enum {
    RACE_S_CELL_KINOKO_ONE = 0x11,
    RACE_S_CELL_KINOKO_TWO,
    RACE_S_CELL_KINOKO_THREE,
    RACE_S_CELL_KOURA_R = 0x14,
    RACE_S_CELL_KOURA_R_THREE,
    RACE_S_CELL_BOUNCING_ITEM_BOX,
    RACE_S_CELL_F_BOX,
    RACE_S_CELL_KINOKO_P,
    RACE_S_CELL_STAR,
    RACE_S_CELL_GESSO,
    RACE_S_CELL_KOURA_G,
    RACE_S_CELL_KOURA_G_THREE,
    RACE_S_CELL_KILLER,
    RACE_S_CELL_TERESA,
    RACE_S_CELL_BOMB,
    RACE_S_CELL_KOURA_W,
    RACE_S_CELL_THUNDER,
    RACE_S_CELL_BANANA,
    RACE_S_CELL_BANANA_THREE
} RaceSCell;

s32 LookupRaceSNcerIndex(s32 kartIndex, s32 shownItem);
void RenderKartEntryNames(void);
void GetEntryCharacterAndPalette(s32 entryIndex, s32 *outCharacterIndex, s32 *outPaletteIndex);
void CopyRaceTransferSOAndMapSO(u16 *palette, void *chars);
void CopyRaceTransferMapMrSO(u16 *palette, void *chars);
void GetTimeRecordCharacterAndPalette(s32 recordIndex, s32 *outCharacterIndex, s32 *outPaletteIndex);

struct RaceNcerNclrNcgrTables **ClearRaceNcerNclrNcgrTablesPointer(void);

// 16-byte element of the table at 0x7dc of an RaceNcerNclrNcgrTables.
typedef struct RaceNclrNcgr {
    /* 00 */ Nclr *mNclr;
    /* 04 */ Ncgr *mNcgr;
    /* 08 */ u8 mUnk_08[8];
} RaceNclrNcgr;

// 0x88c bytes, allocated by InitRaceNcerNclrNcgrTables; the pointer to it is held in gRaceNcerNclrNcgrTables.
typedef struct RaceNcerNclrNcgrTables {
    /* 000 */ NNSG2dCellDataWithBR *mRaceMNcerEntries[0x38];
    /* 0e0 */ NNSG2dCellDataWithBR *mRaceGoalMNcerEntries[0x44];
    /* 1f0 */ NNSG2dCellDataWithBR *mRaceTaMNcerEntries[0xf];
    /* 22c */ NNSG2dCellDataWithBR *mRaceBattleMNcerEntries[0xd];
    /* 260 */ NNSG2dCellDataWithBR *mRaceMrMNcerEntries[0x16];
    /* 2b8 */ NNSG2dCellDataWithBR *mRaceGoalMrMNcerEntries[8];
    /* 2d8 */ NNSG2dCellDataWithBR *mRaceSNcerEntries[0xc9];
    /* 5fc */ NNSG2dCellDataWithBR *mRaceGoalSNcerEntries[0x2c];
    /* 6ac */ NNSG2dCellDataWithBR *mRaceGoalTeamSNcerEntries[0x28];
    /* 74c */ NNSG2dCellDataWithBR *mRaceNewRecordTaSNcerEntries[0x21];
    /* 7d0 */ NNSG2dCellDataWithBR *mRaceStartBattleMNcerEntries[3];
    /* 7dc */ RaceNclrNcgr mNclrNcgrPairs[11];
} RaceNcerNclrNcgrTables;

void InitRaceNcerNclrNcgrTables(void);

#include "00/Menu/wi_fi_vs_matching.h"

extern struct RaceNcerNclrNcgrTables *gRaceNcerNclrNcgrTables;
