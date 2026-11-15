#pragma once
#include "types.h"
#include "g2d_Animation.h"

typedef struct NNSG2dCellDataWithBR NNSG2dCellDataWithBR;

NNSG2dCellDataWithBR *GetRaceStartBattleMNcerEntry(unsigned int cellIndex);

NNSG2dCellDataWithBR *GetRaceNewRecordTaSNcerEntry(unsigned int cellIndex);

NNSG2dCellDataWithBR *GetRaceGoalTeamSNcerEntry(unsigned int cellIndex);

NNSG2dCellDataWithBR *GetRaceGoalSNcerEntry(unsigned int cellIndex);

NNSG2dCellDataWithBR *GetRaceSNcerEntry(unsigned int cellIndex);

NNSG2dCellDataWithBR *GetRaceGoalMrMNcerEntry(unsigned int cellIndex);

NNSG2dCellDataWithBR *GetRaceMrMNcerEntry(unsigned int cellIndex);

NNSG2dCellDataWithBR *GetRaceBattleMNcerEntry(unsigned int cellIndex);

NNSG2dCellDataWithBR *GetRaceTaMNcerEntry(unsigned int cellIndex);

NNSG2dCellDataWithBR *GetRaceGoalMNcerEntry(unsigned int cellIndex);
