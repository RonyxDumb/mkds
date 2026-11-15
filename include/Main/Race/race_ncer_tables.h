#pragma once

#include "types.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "sprite_animation_control.h" // NNSG2dCellDataWithBR

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

// Number of cells in each NCER the tables hold (race_m, race_goal_m, race_ta_m, race_battle_m, race_mr_m,
// race_goal_mr_m, race_s, race_goal_s, race_goal_team_s, race_new_record_ta_s, race_start_battle_m).
#define RACE_M_NCER_COUNT 0x38
#define RACE_GOAL_M_NCER_COUNT 0x44
#define RACE_TA_M_NCER_COUNT 0xf
#define RACE_BATTLE_M_NCER_COUNT 0xd
#define RACE_MR_M_NCER_COUNT 0x16
#define RACE_GOAL_MR_M_NCER_COUNT 8
#define RACE_S_NCER_COUNT 0xc9
#define RACE_GOAL_S_NCER_COUNT 0x2c
#define RACE_GOAL_TEAM_S_NCER_COUNT 0x28
#define RACE_NEW_RECORD_TA_S_NCER_COUNT 0x21
#define RACE_START_BATTLE_M_NCER_COUNT 3

// Slots of mNclrNcgrPairs: the palette and characters loaded from the file of that name (race_m_o, race_goal_m_o,
// race_ta_m_o, ...). The _M files are for the main screen, the _S files for the sub screen.
typedef enum {
    RACE_NCER_PAIR_RACE_M,
    RACE_NCER_PAIR_GOAL_M,
    RACE_NCER_PAIR_TA_M,
    RACE_NCER_PAIR_BATTLE_M,
    RACE_NCER_PAIR_MR_M,
    RACE_NCER_PAIR_GOAL_MR_M,
    RACE_NCER_PAIR_RACE_S,
    RACE_NCER_PAIR_GOAL_S,
    RACE_NCER_PAIR_GOAL_TEAM_S,
    RACE_NCER_PAIR_NEW_RECORD_TA_S,
    RACE_NCER_PAIR_START_BATTLE_M,
    RACE_NCER_PAIR_COUNT
} RaceNcerPair;

// 0x88c bytes, allocated by InitRaceNcerNclrNcgrTables; the pointer to it is held in gRaceNcerNclrNcgrTables.
typedef struct RaceNcerNclrNcgrTables {
    /* 000 */ NNSG2dCellDataWithBR *mRaceMNcerEntries[RACE_M_NCER_COUNT];
    /* 0e0 */ NNSG2dCellDataWithBR *mRaceGoalMNcerEntries[RACE_GOAL_M_NCER_COUNT];
    /* 1f0 */ NNSG2dCellDataWithBR *mRaceTaMNcerEntries[RACE_TA_M_NCER_COUNT];
    /* 22c */ NNSG2dCellDataWithBR *mRaceBattleMNcerEntries[RACE_BATTLE_M_NCER_COUNT];
    /* 260 */ NNSG2dCellDataWithBR *mRaceMrMNcerEntries[RACE_MR_M_NCER_COUNT];
    /* 2b8 */ NNSG2dCellDataWithBR *mRaceGoalMrMNcerEntries[RACE_GOAL_MR_M_NCER_COUNT];
    /* 2d8 */ NNSG2dCellDataWithBR *mRaceSNcerEntries[RACE_S_NCER_COUNT];
    /* 5fc */ NNSG2dCellDataWithBR *mRaceGoalSNcerEntries[RACE_GOAL_S_NCER_COUNT];
    /* 6ac */ NNSG2dCellDataWithBR *mRaceGoalTeamSNcerEntries[RACE_GOAL_TEAM_S_NCER_COUNT];
    /* 74c */ NNSG2dCellDataWithBR *mRaceNewRecordTaSNcerEntries[RACE_NEW_RECORD_TA_S_NCER_COUNT];
    /* 7d0 */ NNSG2dCellDataWithBR *mRaceStartBattleMNcerEntries[RACE_START_BATTLE_M_NCER_COUNT];
    /* 7dc */ RaceNclrNcgr mNclrNcgrPairs[RACE_NCER_PAIR_COUNT];
} RaceNcerNclrNcgrTables;

void InitRaceNcerNclrNcgrTables(void);

#include "00/Menu/wi_fi_vs_matching.h"

extern struct RaceNcerNclrNcgrTables *gRaceNcerNclrNcgrTables;
