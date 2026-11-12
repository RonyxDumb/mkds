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

#include "00/Menu/wi_fi_vs_matching.h"
