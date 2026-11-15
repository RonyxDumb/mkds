#pragma once

#include "types.h"

typedef struct SelectBattleStageNscrRect {
    /* 00 */ u8 mFirstColumn;
    /* 01 */ u8 mLastColumn;
    /* 02 */ u8 mFirstRow;
    /* 03 */ u8 mLastRow;
} SelectBattleStageNscrRect;

extern const u8 gSelectBattleStageSTableIndices[6][3];

#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/select_return.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

extern const u8 gSelectBattleStageNegatedYCells[1];
extern const u8 gSelectBattleStageSecondXCells[2];
extern const u8 gSelectBattleStageMNscrCopyDestination[2];
extern const u8 gSelectBattleStageOffsetYCells[3];
extern const u8 gSelectBattleStageXCells[3];
extern const s8 gSelectBattleStageOffsets[6];
extern const u8 gSelectBattleStageMNscrIndices[6];
extern const u8 gSelectBattleStageBnblRectIndices[6];
extern const SelectBattleStageNscrRect gSelectBattleStageNscrRects[6];

void WriteSelectBattleStageRegisters(void);
s32 AdvanceSelectBattleStage(void);
void AdvanceSelectBattleStageOffsetTimer(void);
void UpdateSelectBattleStageHighlight(void);
void AdvanceSelectBattleStageSlideOut(void);
void AdvanceSelectBattleStageChoises(void);
void AdvanceSelectBattleStageWaitSelectReturnThenChoises(void);
void AdvanceSelectBattleStagePressStage(void);
void AdvanceSelectBattleStageInput(void);
void AdvanceSelectBattleStageWaitSelectReturn(void);
void AdvanceSelectBattleStageSlideIn(void);
void UpdateSelectBattleStageCellOffsets(void);
void CopyAndQueueSelectBattleStageNscrRect(void);
void LocateAndQueueSelectBattleStage(void);
void ReleaseSelectBattleStage(void);
void InitSelectBattleStage(void *parentHeap, s32 variant, void *mainOam, void *subOam);

#include "00/Menu/wi_fi_vs_matching.h"
