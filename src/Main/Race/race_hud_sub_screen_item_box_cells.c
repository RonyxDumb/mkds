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
                    gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mCell = GetRaceSNcerEntry(0x4e);
                    gRaceHudSubScreenItemBoxCells->mCells[cellIndex].mPriority =
                        IsPositionOutsideBox(position) != 0 ? RACE_HUD_PRIORITY_MIDDLE : RACE_HUD_PRIORITY_3;
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
    s32 recordIndexThenIsRecord;
    s32 finishMs;
    TimeRecord *record;
    TimeRecord *records;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceNewRecordTa == NULL) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        gRaceNewRecordTa->mFinishTimeIsRecord = TryStoreRaceNewRecordTaFinishTime(0);
        gRaceNewRecordTa->mBestLapIsRecord = TryStoreRaceNewRecordTaBestLap(0);
        return;
    }
    GetKartFinishTime(GetFollowedKartOrEntryIndex(), &minute, &second, &millisecond);
    records = gRaceNewRecordTa->mRecords;
    finishMs = TIME_TO_MS(minute, second, millisecond);
    for (recordIndexThenIsRecord = 4; recordIndexThenIsRecord >= 0; recordIndexThenIsRecord--) {
        record = &records[recordIndexThenIsRecord];
        if (record->mFilled != 0 &&
            finishMs == record->mMillisecond + (record->mSecond * 1000 + record->mMinute * 60000)) {
            recordIndexThenIsRecord = 1;
            goto found;
        }
    }
    recordIndexThenIsRecord = 0;
found:
    gRaceNewRecordTa->mFinishTimeIsRecord = recordIndexThenIsRecord;
    record = &gRaceNewRecordTa->mRecords[TIME_RECORD_BEST_LAP];
    gRaceNewRecordTa->mBestLapNumber =
        GetKartBestLapTime(GetFollowedKartOrEntryIndex(), &bestMinute, &bestSecond, &bestMillisecond);
    gRaceNewRecordTa->mBestLapIsRecord =
        (bestMinute == record->mMinute && bestSecond == record->mSecond && bestMillisecond == record->mMillisecond) ? 1
                                                                                                                    : 0;
}

s32 IsRaceNewRecordTaFinishRecord(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mFinishTimeIsRecord : 0;
}

BOOL IsRaceNewRecordTaFinishRecordFirst(void) {
    if (gRaceNewRecordTa != NULL) {
        if (gRaceNewRecordTa->mFinishTimeIsRecord != 0) {
            if (gRaceNewRecordTa->mFinishRecordIndex == 0) {
                return TRUE;
            }
        }
        return FALSE;
    }
    return FALSE;
}

s32 IsRaceNewRecordTaBestLapRecord(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mBestLapIsRecord : 0;
}
