#include "Main/Race/race_goal_times.h"

#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells.h"
#include "Main/Race/race_goal_m.h"
#include "Main/Race/race_new_record_ta.h"
#include "cell_animation.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Race/kart.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

struct RaceHudSubScreenCells *gRaceHudSubScreenCreamCells;
RaceHudSubScreenCells *gRaceHudSubScreenFireball2Cells;
struct RaceHudSubScreenCells *gRaceHudSubScreenBerryCells;
struct RaceGoalTimes *gRaceGoalTimes;

void ClearRaceHudSubScreenFireball2Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenFireball2Cells);
}

void UpdateRaceHudSubScreenFireball2Cells(void) {
    s32 objectIndex;
    s32 cellCount;
    BOOL inFirstHalf;
    u32 raceHudSubScreenScale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    raceHudSubScreenScale = GetRaceHudSubScreenScale();
    gRaceHudSubScreenFireball2Cells->mObjectPairs->mSecond++;
    if (gRaceHudSubScreenFireball2Cells->mObjectPairs->mSecond < 0 ||
        gRaceHudSubScreenFireball2Cells->mObjectPairs->mSecond >= RACE_GOAL_TIMES_FIREBALL_CYCLE_FRAMES) {
        gRaceHudSubScreenFireball2Cells->mObjectPairs->mSecond = 0;
    }
    inFirstHalf = gRaceHudSubScreenFireball2Cells->mObjectPairs->mSecond < RACE_GOAL_TIMES_FIREBALL_HALF_FRAMES;
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenFireball2Cells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenFireball2Cells->mObjects[objectIndex];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenFireball2Cells->mCells[cellCount].mDrawPos,
                                            raceHudSubScreenScale, 1, 1) == FALSE) {
            continue;
        }
        gRaceHudSubScreenFireball2Cells->mCells[cellCount].mCell =
            GetB3C4_Cell_RaceS(inFirstHalf != FALSE ? 0xa5 : 0xa6);
        gRaceHudSubScreenFireball2Cells->mCells[cellCount].mPriority = 1;
        gRaceHudSubScreenFireball2Cells->mCells[cellCount].mXlu = 0;
        gRaceHudSubScreenFireball2Cells->mCells[cellCount].mAngle = object->mAngle;
        cellCount++;
    }
    gRaceHudSubScreenFireball2Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenFireball2Cells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenFireball2Cells, 1);
}

void InitRaceGoalTimes(void) {
    u16 lapIndex;

    gRaceGoalTimes = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*gRaceGoalTimes));
    gRaceGoalTimes->mFinishTime.mDigits[0] = 0;
    gRaceGoalTimes->mFinishTime.mDigits[1] = 0;
    gRaceGoalTimes->mFinishTime.mDigits[2] = 0;
    gRaceGoalTimes->mFinishTime.mDigits[3] = 0;
    gRaceGoalTimes->mFinishTime.mDigits[4] = 0;
    gRaceGoalTimes->mFinishTime.mDigits[5] = 0;
    gRaceGoalTimes->mFinishTime.mDigits[6] = 0;
    for (lapIndex = 0; lapIndex < 5; lapIndex++) {
        gRaceGoalTimes->mLapTimes[lapIndex].mDigits[0] = 0;
        gRaceGoalTimes->mLapTimes[lapIndex].mDigits[1] = 0;
        gRaceGoalTimes->mLapTimes[lapIndex].mDigits[2] = 0;
        gRaceGoalTimes->mLapTimes[lapIndex].mDigits[3] = 0;
        gRaceGoalTimes->mLapTimes[lapIndex].mDigits[4] = 0;
        gRaceGoalTimes->mLapTimes[lapIndex].mDigits[5] = 0;
        gRaceGoalTimes->mLapTimes[lapIndex].mDigits[6] = 0;
    }
    gRaceGoalTimes->mRecordCycleFrame = 0;
    gRaceGoalTimes->mCellIndexAdd = RACE_GOAL_TIMES_CELL_SET_FIRST;
}

void ClearRaceGoalTimesPointer(void) {
    gRaceGoalTimes = NULL;
}

void UpdateRaceGoalTimes(void) {
    u8 minute;
    u8 second;
    u16 millisecond;
    u16 lapIndex;
    s32 cycleStep;

    if (g_GlobalCO->mMode != MODE_GRAND_PRIX && g_GlobalCO->mMode != MODE_TIME_ATTACK) {
        return;
    }
    GetPlayerTotalTime(GetCurrentPlayerRacerId(), &minute, &second, &millisecond);
    SplitTimeDigits(minute, second, millisecond, &gRaceGoalTimes->mFinishTime);
    for (lapIndex = 0; lapIndex < GetCurrentLapCount(); lapIndex++) {
        MaybeGetPlayerLapTime(GetCurrentPlayerRacerId(), lapIndex + 1, &minute, &second, &millisecond);
        SplitTimeDigits(minute, second, millisecond, &gRaceGoalTimes->mLapTimes[lapIndex]);
    }
    if (g_GlobalCO->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (IsRaceNewRecordTaFinishRecord() == 0 && GetLastTimeTrialWasRecord() == 0) {
        return;
    }
    gRaceGoalTimes->mRecordCycleFrame++;
    if (gRaceGoalTimes->mRecordCycleFrame >= RACE_GOAL_TIMES_CYCLE_FRAMES) {
        gRaceGoalTimes->mRecordCycleFrame = 0;
    }
    cycleStep = gRaceGoalTimes->mRecordCycleFrame % RACE_GOAL_TIMES_CYCLE_FRAMES;
    if (cycleStep < RACE_GOAL_TIMES_CYCLE_QUARTER_FRAMES) {
        gRaceGoalTimes->mCellIndexAdd = RACE_GOAL_TIMES_CELL_SET_FIRST;
        return;
    }
    if (cycleStep < RACE_GOAL_TIMES_CYCLE_QUARTER_FRAMES * 2) {
        gRaceGoalTimes->mCellIndexAdd = RACE_GOAL_TIMES_CELL_SET_SECOND;
        return;
    }
    if (cycleStep < RACE_GOAL_TIMES_CYCLE_QUARTER_FRAMES * 3) {
        gRaceGoalTimes->mCellIndexAdd = RACE_GOAL_TIMES_CELL_SET_THIRD;
    } else {
        gRaceGoalTimes->mCellIndexAdd = RACE_GOAL_TIMES_CELL_SET_SECOND;
    }
}

// Draws the finish time and lap times of the goal screen.
void DrawRaceGoalTimes(RaceHudOamBuffer *oamBuffer) {
    NNSG2dCellDataWithBR *cell;
    s32 positions[4][2];
    s32 slideOffsets[6];
    u16 rowIndex;
    s32 updateFrames;
    s32 cellOffset;
    s32 rowY;

    updateFrames = GetB3F0_Beb1();
    if (g_GlobalCO->mMode != MODE_GRAND_PRIX && g_GlobalCO->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (g_GlobalCO->mRaceKind == RACE_KIND_START_BATTLE || g_GlobalCO->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (IsSavingTimeTrialRecord() != 0) {
        cell = GetB3C4_Cell_RaceGoalM(0x43);
        positions[0][0] = 0x80000;
        positions[0][1] = 0x60000;
        oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, positions[0], 0, 1);
    }
    if (updateFrames <= 0) {
        return;
    }
    for (rowIndex = 0; rowIndex < 6; rowIndex++) {
        slideOffsets[rowIndex] = ComputeValueInterpolation_from_thumb(1, 0x80, 0, updateFrames - rowIndex * 4, 0x14);
    }
    cell = GetB3C4_Cell_RaceGoalM((IsRaceNewRecordTaFinishRecord() != 0 ? gRaceGoalTimes->mCellIndexAdd : 0) + 0x15);
    positions[1][0] = TO_FIXED12(slideOffsets[0] + 0xa2);
    positions[1][1] = 0x10000;
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, positions[1], 0, 1);
    DrawRaceGoalTimeDigits(oamBuffer, slideOffsets[0], 0x10, &gRaceGoalTimes->mFinishTime,
                           IsRaceNewRecordTaFinishRecord() != 0 ? gRaceGoalTimes->mCellIndexAdd : 0);
    cell = GetB3C4_Cell_RaceGoalM((GetLastTimeTrialWasRecord() != 0 ? gRaceGoalTimes->mCellIndexAdd : 0) + 0x16);
    positions[2][0] = TO_FIXED12(slideOffsets[1] + 0x99);
    positions[2][1] = 0x28000;
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, positions[2], 0, 1);
    for (rowIndex = 0; rowIndex < GetCurrentLapCount(); rowIndex++) {
        cellOffset = 0;
        if (GetLastTimeTrialWasRecord() != 0 && rowIndex + 1 == GetLeastTimeLapId()) {
            cellOffset = gRaceGoalTimes->mCellIndexAdd;
        }
        cell = GetB3C4_Cell_RaceGoalM(rowIndex + 0x18 + cellOffset);
        rowY = rowIndex * 16 + 0x28;
        positions[3][0] = TO_FIXED12(slideOffsets[rowIndex + 1] + 0x9e);
        positions[3][1] = TO_FIXED12(rowY);
        oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, positions[3], 0, 1);
        DrawRaceGoalTimeDigits(oamBuffer, slideOffsets[rowIndex + 1], rowY, &gRaceGoalTimes->mLapTimes[rowIndex],
                               cellOffset);
    }
}

// Draws the seven digits of e and the two separators; the first digit is skipped when it is 0.
void DrawRaceGoalTimeDigits(RaceHudOamBuffer *oamBuffer, s32 originX, s32 originY, TimeDigits *digits, s32 cellOffset) {
    NNSG2dCellDataWithBR *cell;
    s32 digit0Position[2];
    s32 digit1Position[2];
    s32 separator0Position[2];
    s32 digit2Position[2];
    s32 digit3Position[2];
    s32 separator1Position[2];
    s32 digit4Position[2];
    s32 digit5Position[2];
    s32 digit6Position[2];
    s32 columnOffsets[9] = {170, 179, 188, 198, 207, 216, 226, 235, 244};

    if (digits->mDigits[0] != 0) {
        cell = GetB3C4_Cell_RaceGoalM(digits->mDigits[0] + 0x17 + cellOffset);
        digit0Position[0] = TO_FIXED12(originX + columnOffsets[0]);
        digit0Position[1] = TO_FIXED12(originY);
        oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, digit0Position, 0, 1);
    }
    cell = GetB3C4_Cell_RaceGoalM(digits->mDigits[1] + 0x17 + cellOffset);
    digit1Position[0] = TO_FIXED12(originX + columnOffsets[1]);
    digit1Position[1] = TO_FIXED12(originY);
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit1Position, 0, 1);
    cell = GetB3C4_Cell_RaceGoalM(cellOffset + 0x21);
    separator0Position[0] = TO_FIXED12(originX + columnOffsets[2]);
    separator0Position[1] = TO_FIXED12(originY);
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, separator0Position, 0, 1);
    cell = GetB3C4_Cell_RaceGoalM(digits->mDigits[2] + 0x17 + cellOffset);
    digit2Position[0] = TO_FIXED12(originX + columnOffsets[3]);
    digit2Position[1] = TO_FIXED12(originY);
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit2Position, 0, 1);
    cell = GetB3C4_Cell_RaceGoalM(digits->mDigits[3] + 0x17 + cellOffset);
    digit3Position[0] = TO_FIXED12(originX + columnOffsets[4]);
    digit3Position[1] = TO_FIXED12(originY);
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit3Position, 0, 1);
    cell = GetB3C4_Cell_RaceGoalM(cellOffset + 0x21);
    separator1Position[0] = TO_FIXED12(originX + columnOffsets[5]);
    separator1Position[1] = TO_FIXED12(originY);
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, separator1Position, 0, 1);
    cell = GetB3C4_Cell_RaceGoalM(digits->mDigits[4] + 0x17 + cellOffset);
    digit4Position[0] = TO_FIXED12(originX + columnOffsets[6]);
    digit4Position[1] = TO_FIXED12(originY);
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit4Position, 0, 1);
    cell = GetB3C4_Cell_RaceGoalM(digits->mDigits[5] + 0x17 + cellOffset);
    digit5Position[0] = TO_FIXED12(originX + columnOffsets[7]);
    digit5Position[1] = TO_FIXED12(originY);
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit5Position, 0, 1);
    cell = GetB3C4_Cell_RaceGoalM(digits->mDigits[6] + 0x17 + cellOffset);
    digit6Position[0] = TO_FIXED12(originX + columnOffsets[8]);
    digit6Position[1] = TO_FIXED12(originY);
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit6Position, 0, 1);
}

s32 CreateRaceHudSubScreenBerryCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBerryCells, MAP_OBJECT_KIND_BERRY);
}

void ClearRaceHudSubScreenBerryCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBerryCells);
}

void UpdateRaceHudSubScreenBerryCells(void) {
    s32 objectIndex;
    s32 cellCount;
    u32 raceHudSubScreenScale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    raceHudSubScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenBerryCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenBerryCells->mObjects[objectIndex];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenBerryCells->mCells[cellCount].mDrawPos,
                                            raceHudSubScreenScale, 1, 1) == FALSE) {
            continue;
        }
        gRaceHudSubScreenBerryCells->mCells[cellCount].mCell = GetB3C4_Cell_RaceS(0xb8);
        gRaceHudSubScreenBerryCells->mCells[cellCount].mPriority =
            CheckVectorBounds_Clock_Airship(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
        gRaceHudSubScreenBerryCells->mCells[cellCount].mAngle = object->mAngle;
        gRaceHudSubScreenBerryCells->mObjectPairs[cellCount].mFirst = object->mScale.x / 6;
        cellCount++;
    }
    gRaceHudSubScreenBerryCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBerryCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenBerryCells, 1);
}

s32 CreateRaceHudSubScreenCreamCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCreamCells, MAP_OBJECT_KIND_CREAM);
}

void ClearRaceHudSubScreenCreamCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenCreamCells);
}

void UpdateRaceHudSubScreenCreamCells(void) {
    s32 objectIndex;
    s32 cellCount;
    s32 raceHudSubScreenScale;
    MapObject *object;
    Vec3 *position;

    cellCount = 0;
    raceHudSubScreenScale = GetRaceHudSubScreenScale();
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenCreamCells->mObjectCount; objectIndex++) {
        object = gRaceHudSubScreenCreamCells->mObjects[objectIndex];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenCreamCells->mCells[cellCount].mDrawPos,
                                            raceHudSubScreenScale, 1, 1) != FALSE) {
            gRaceHudSubScreenCreamCells->mCells[cellCount].mCell = GetB3C4_Cell_RaceS(0xb7);
            gRaceHudSubScreenCreamCells->mCells[cellCount].mPriority =
                CheckVectorBounds_Clock_Airship(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
            gRaceHudSubScreenCreamCells->mCells[cellCount].mAngle = object->mAngle;
            gRaceHudSubScreenCreamCells->mObjectPairs[cellCount].mFirst = object->mScale.x / 6;
            cellCount++;
        }
    }
    gRaceHudSubScreenCreamCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenCreamCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenCreamCells, 1);
}
