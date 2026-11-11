#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "code_02022030.h" // NNSG2dCellDataWithBR

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

#include "00/code_021832d8.h"
