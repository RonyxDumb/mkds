#pragma once

#include "types.h"

typedef struct SelectBattleStageNscrRect {
    /* 00 */ u8 mFirstColumn;
    /* 01 */ u8 mLastColumn;
    /* 02 */ u8 mFirstRow;
    /* 03 */ u8 mLastRow;
} SelectBattleStageNscrRect;

extern const u8 gSelectBattleStageSTableIndices[6][3];

#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/System/result_archive_path.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Menu/select_return.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"

extern const u8 gSelectBattleStageNegatedYCells[];
extern const u8 gSelectBattleStageSecondXCells[];
extern const u8 gSelectBattleStageMNscrCopyDestination[];
extern const u8 gSelectBattleStageOffsetYCells[];
extern const u8 gSelectBattleStageXCells[];
extern const s8 gSelectBattleStageOffsets[];
extern const u8 gSelectBattleStageMNscrIndices[];
extern const u8 gSelectBattleStageBnblRectIndices[6];
extern const SelectBattleStageNscrRect gSelectBattleStageNscrRects[];

void WriteSelectBattleStageRegisters(void);
s32 AdvanceSelectBattleStage(void);
void AdvanceSelectBattleStageOffsetTimer(void);
void UpdateSelectBattleStageHighlight(void);
void AdvanceSelectBattleStageState6(void);
void AdvanceSelectBattleStageState5(void);
void AdvanceSelectBattleStageState4(void);
void AdvanceSelectBattleStageState3(void);
void AdvanceSelectBattleStageState2(void);
void AdvanceSelectBattleStageState1(void);
void AdvanceSelectBattleStageState0(void);
void UpdateSelectBattleStageCellOffsets(void);
void CopyAndQueueSelectBattleStageNscrRect(void);
void LocateAndQueueSelectBattleStage(void);
void ReleaseSelectBattleStage(void);
void InitSelectBattleStage(void *parentHeap, s32 d, void *mainOam, void *subOam);

#include "00/code_021832d8.h"
