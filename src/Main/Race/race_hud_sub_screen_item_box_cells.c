#include "Main/Race/race_hud_sub_screen_item_box_cells.h"
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
#include "Main/Race/kart.h"
#include "Main/Race/race_new_record_ta.h"

RaceHudSubScreenCells *gRaceHudSubScreenItemBoxCells;
s32 gRaceHudSubScreenItemBoxNearOnly;

void UpdateRaceHudSubScreenItemBoxCells(void) {
    s32 objectIndex;
    s32 cellIndex;
    s32 cellCount;
    s32 subScreenScale;
    MapObject *mapObject;
    Vec3 *position;

    cellCount = 0;
    subScreenScale = GetRaceHudSubScreenScale();
    cellIndex = 0;
    for (objectIndex = 0; objectIndex < gRaceHudSubScreenItemBoxCells->mObjectCount; objectIndex++) {
        if (gRaceHudSubScreenItemBoxNearOnly == 0 ||
            IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenItemBoxCells->mObjectPairs[objectIndex]) != FALSE) {
            mapObject = gRaceHudSubScreenItemBoxCells->mObjects[objectIndex];
            if ((mapObject->mFlags & 1) == 0) {
                position = &mapObject->mPos;
                if (ComputeRaceHudSubScreenPosition(position,
                                                    &gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mDrawPos,
                                                    subScreenScale, 0, 0) != FALSE) {
                    gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mCell = GetB3C4_Cell_RaceS(0x4e);
                    gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mPriority =
                        CheckVectorBounds_Clock_Airship(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_BACK;
                    gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mXlu = mapObject->mFlags & MAP_OBJECT_FLAG_HUD_XLU;
                    cellCount++;
                    cellIndex++;
                }
            }
        }
    }
    gRaceHudSubScreenItemBoxCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenItemBoxCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenItemBoxCells, 0);
}

void RefreshRaceNewRecordTaRecordFlags(void) {
    u8 minute;
    u8 second;
    u16 millisecond;
    u8 bestMinute;
    u8 bestSecond;
    u16 bestMillisecond;
    s32 recordIndex;
    s32 finishMs;
    TimeRecord *record;
    TimeRecord *records;

    if (g_GlobalCO->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (g_GlobalE8 == NULL) {
        return;
    }
    if (g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
        g_GlobalE8->mFinishTimeIsRecord = CheckHandleSaveTimeTrialRecord2(0);
        g_GlobalE8->mBestLapIsRecord = CheckHandleSaveTimeTrialRecord_LeastLap(0);
        return;
    }
    GetPlayerTotalTime(GetCurrentPlayerRacerId(), &minute, &second, &millisecond);
    records = g_GlobalE8->mRecords;
    finishMs = TIME_TO_MS(minute, second, millisecond);
    for (recordIndex = 4; recordIndex >= 0; recordIndex--) {
        record = &records[recordIndex];
        if (record->mFilled != 0 &&
            finishMs == record->mMillisecond + (record->mSecond * 1000 + record->mMinute * 60000)) {
            recordIndex = 1;
            goto found;
        }
    }
    recordIndex = 0;
found:
    g_GlobalE8->mFinishTimeIsRecord = recordIndex;
    record = &g_GlobalE8->mRecords[TIME_RECORD_BEST_LAP];
    g_GlobalE8->mBestLapNumber =
        GetLeastTimeLap(GetCurrentPlayerRacerId(), &bestMinute, &bestSecond, &bestMillisecond);
    g_GlobalE8->mBestLapIsRecord =
        (bestMinute == record->mMinute && bestSecond == record->mSecond && bestMillisecond == record->mMillisecond) ? 1
                                                                                                                    : 0;
}

s32 IsRaceNewRecordTaFinishRecord(void) {
    return g_GlobalE8 != NULL ? g_GlobalE8->mFinishTimeIsRecord : 0;
}

BOOL IsRaceNewRecordTaFinishRecordFirst(void) {
    if (g_GlobalE8 != NULL) {
        if (g_GlobalE8->mFinishTimeIsRecord != 0) {
            if (g_GlobalE8->mFinishRecordIndex == 0) {
                return TRUE;
            }
        }
        return FALSE;
    }
    return FALSE;
}

s32 GetLastTimeTrialWasRecord(void) {
    return g_GlobalE8 != NULL ? g_GlobalE8->mBestLapIsRecord : 0;
}
