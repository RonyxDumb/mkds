#pragma once

#include "types.h"

// A rectangle of columns and rows within a select battle stage Nscr.
typedef struct SelectBattleStageNscrRect {
    /* 00 */ u8 mFirstColumn;
    /* 01 */ u8 mLastColumn;
    /* 02 */ u8 mFirstRow;
    /* 03 */ u8 mLastRow;
} SelectBattleStageNscrRect;

// The stages (SelectBattleStage.mIndex) listed top to bottom.
#define SELECT_BATTLE_STAGE_COUNT 6

// Frames of the slide in and the slide out; the layers slide in from SELECT_BATTLE_STAGE_SLIDE_DISTANCE_Y and _X, the
// stage cells from SELECT_BATTLE_STAGE_CELL_SLIDE_DISTANCE. The slide in is followed by SETTLE_FRAMES of the press
// offset animation (GetSelectedPressOffset), which the press of a stage plays as well; its highlight shows at the
// fifth.
#define SELECT_BATTLE_STAGE_SLIDE_FRAMES 10
#define SELECT_BATTLE_STAGE_SETTLE_FRAMES 10
#define SELECT_BATTLE_STAGE_HIGHLIGHT_FRAME 5
#define SELECT_BATTLE_STAGE_SLIDE_DISTANCE_Y 160
#define SELECT_BATTLE_STAGE_SLIDE_DISTANCE_X 256
#define SELECT_BATTLE_STAGE_CELL_SLIDE_DISTANCE 220

// Frames the cells of a stage shift after the index changed or a stage was pressed (mOffsetTimer counts them down).
#define SELECT_BATTLE_STAGE_OFFSET_TIMER_FRAMES 6

extern const u8 gSelectBattleStageSTableIndices[6][3];

#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/select_return.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
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
