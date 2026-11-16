#include "01/Race/mission_run_state.h"

#include "01/MapObjects/mission_run_map_object.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "03/Net/essid_packet_steps.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Race/standings_balloons.h"
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
#include "sprite_animation_control.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Sound/sound_handle_pool.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Sound/sound_seq.h"

MissionRunData *gMissionRunData;

void AddMissionRunMapObject(MissionRunMapObject *mapObject) {
    u8 kartCount;
    u16 entryIndex;

    kartCount = gRaceSetup->mKartCount;
    entryIndex = gMissionRunData->mMapObjectCount + kartCount;
    gMissionRunData->mMapObjects[entryIndex - kartCount] = mapObject;
    ClearStandingEliminationStatus(entryIndex);
    gMissionRunData->mMapObjectCount++;
}

MissionRunMapObject *GetMissionRunMapObject(int entryIndex) {
    return gMissionRunData->mMapObjects[entryIndex - gRaceSetup->mKartCount];
}

u8 MissionRunGetCurrentKartCount(void) {
    return gRaceSetup->mKartCount;
}

u16 GetMissionRunMapObjectLastIndex(void) {
    return gMissionRunData->mMapObjectCount + gRaceSetup->mKartCount - 1;
}

void AddMissionRunCount(void) {
    MissionRunData *missionRunData;
    u32 countLimit;

    if ((gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) != FALSE) {
        return;
    }
    missionRunData = gMissionRunData;
    countLimit = GetMissionRunCountLimit();
    if (missionRunData->mCount >= countLimit) {
        return;
    }
    missionRunData->mCount = missionRunData->mCount + 1;
    StartMissionRunCountSeq(gMissionRunData->mCount, GetMissionRunCountLimit());
    switch (gRaceSetup->mMissionKind) {
        case MISSION_KIND_COUNT_SHAPE_ENTRIES:
        case MISSION_KIND_COUNT_PENDING_WITH_SEQ:
        case MISSION_KIND_COUNT_MAP_OBJECTS:
        case MISSION_KIND_COUNT_PENDING:
        case MISSION_KIND_COUNT_HITS:
            countLimit = GetMissionRunCountLimit();
            if (gMissionRunData->mCount >= countLimit) {
                FinishMissionRunKartAtGoal(gRaceSetup->mEntryIndex);
            }
            break;
    }
}

Vec3 *GetMissionRunKartPos(void) {
    return &gMissionRunData->mKartPos;
}

Vec3 *GetMissionRunPrevKartPos(void) {
    return &gMissionRunData->mPrevKartPos;
}

u16 GetMissionRunKartHeadingAngle(void) {
    return (gMissionRunData->mKartHeadingAngle);
}

u16 GetMissionRunPrevKartHeadingAngle(void) {
    return (gMissionRunData->mPrevKartHeadingAngle);
}

void CreateMissionRunData(void) {
    Kart *kart;
    MissionRunData *missionRunData;

    gMissionRunData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MissionRunData));
    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    missionRunData = gMissionRunData;
    missionRunData->mPrevKartPos = kart->mPos;
    missionRunData->mKartPos = missionRunData->mPrevKartPos;
    missionRunData->mPrevKartHeadingAngle = kart->mHeadingAngle;
    missionRunData = gMissionRunData;
    missionRunData->mKartHeadingAngle = missionRunData->mPrevKartHeadingAngle;
}

void UpdateMissionRunData(void) {
    Kart *kart;
    MissionRunData *missionRunData;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) == 0) {
        missionRunData = gMissionRunData;
        missionRunData->mPrevKartPos = missionRunData->mKartPos;
        missionRunData->mPrevKartHeadingAngle = missionRunData->mKartHeadingAngle;
        missionRunData = gMissionRunData;
        missionRunData->mKartPos = kart->mPos;
        missionRunData->mKartHeadingAngle = kart->mHeadingAngle;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
            if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex)) {
                gMissionRunData->mSinceHitCallbackFrames += 1;
                if (gMissionRunData->mSinceHitCallbackFrames > MISSION_RUN_SELF_HIT_CALLBACK_FRAMES) {
                    gMissionRunData->mSinceHitCallbackFrames = 0;
                    CallKartHitCallbackForSelf(gRaceSetup->mEntryIndex);
                    return;
                }
            }
        }
        return;
    }
    {
        u32 missionKind = gRaceSetup->mMissionKind;
        if (missionKind == MISSION_KIND_COUNT_PENDING_WITH_SEQ || missionKind == MISSION_KIND_COUNT_PENDING) {
            if (GetRaceUpdateFramesMod8() == 0) {
                missionRunData = gMissionRunData;
                if (missionRunData->mPendingBossTransfer != 0) {
                    missionRunData->mPendingBossTransfer -= 1;
                    missionRunData = gMissionRunData;
                    if (missionRunData->mCount != 0) {
                        missionRunData->mCount -= 1;
                        gMissionRunData->mBossCount += 1;
                    }
                    if (gMissionRunData->mBossTransferCallback != NULL) {
                        gMissionRunData->mBossTransferCallback();
                    }
                    gMissionRunData->mTimer = 0;
                } else if (missionRunData->mPendingDrop != 0) {
                    missionRunData->mPendingDrop -= 1;
                    missionRunData = gMissionRunData;
                    if (missionRunData->mCount != 0) {
                        missionRunData->mCount -= 1;
                    }
                    if (gMissionRunData->mDropCallback != NULL) {
                        gMissionRunData->mDropCallback();
                    }
                    gMissionRunData->mTimer = 0;
                } else if (missionRunData->mPendingCountUp != 0) {
                    missionRunData->mPendingCountUp -= 1;
                    AddMissionRunCount();
                    if (gMissionRunData->mCountUpCallback != NULL) {
                        gMissionRunData->mCountUpCallback();
                    }
                }
            }
            missionRunData = gMissionRunData;
            if (missionRunData->mTimer != 0) {
                missionRunData->mTimer -= 1;
                missionRunData = gMissionRunData;
                if (missionRunData->mTimer == 0) {
                    if (missionRunData->mTimerEndCallback != NULL) {
                        missionRunData->mTimerEndCallback();
                    }
                }
            }
        }
    }
}

void SetMissionRunTimerValues(u16 startTimer, u16 maxTimer, u16 countUpTimerAdd, u16 bossTransferTimerAdd) {
    gMissionRunData->mTimerStart = startTimer;
    gMissionRunData->mTimerMax = maxTimer;
    gMissionRunData->mCountUpTimerAdd = countUpTimerAdd;
    gMissionRunData->mBossTransferTimerAdd = bossTransferTimerAdd;
}

s32 GetMissionRunTimer(void) {
    return (gMissionRunData->mTimer);
}

void SetMissionRunTimer(u16 timer) {
    gMissionRunData->mTimer = timer;
}

u32 GetMissionRunCount(void) {
    return (gMissionRunData->mCount);
}

u32 GetMissionRunCountLimit(void) {
    u32 countLimit = gRaceSetup->mMissionRunCountLimit;
    if (countLimit == 0) {
        countLimit = 1;
    }
    return countLimit;
}

s32 GetMissionRunBossCount(void) {
    return (gMissionRunData->mBossCount);
}

void AddMissionRunCountForHit(void) {
    if (gRaceSetup->mMissionKind == MISSION_KIND_COUNT_HITS) {
        AddMissionRunCount();
    }
}

void AddMissionRunCountForMapObjectKind(s32 mapObjectKind) {
    RaceSetup *raceSetup = gRaceSetup;
    u32 missionKind = raceSetup->mMissionKind;
    if (missionKind == MISSION_KIND_COUNT_MAP_OBJECTS || missionKind == MISSION_KIND_COUNT_HITS ||
        missionKind == MISSION_KIND_COUNT_SHAPE_ENTRIES) {
        u32 firstCountedKind = raceSetup->mMissionCountMapObjectKinds[0];
        if (firstCountedKind == 0 && raceSetup->mMissionCountMapObjectKinds[1] == 0 &&
            raceSetup->mMissionCountMapObjectKinds[2] == 0 && raceSetup->mMissionCountMapObjectKinds[3] == 0 &&
            mapObjectKind > 400 && mapObjectKind < 500) {
            AddMissionRunCount();
            return;
        }
        if (mapObjectKind == firstCountedKind || mapObjectKind == raceSetup->mMissionCountMapObjectKinds[1] ||
            mapObjectKind == raceSetup->mMissionCountMapObjectKinds[2] ||
            mapObjectKind == raceSetup->mMissionCountMapObjectKinds[3]) {
            AddMissionRunCount();
        }
    }
}

void AddMissionRunPendingDropOnKartHit(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDrop(5);
    }
}

void AddMissionRunCountForMiniTurbo(void) {
    if (gRaceSetup->mMissionKind == MISSION_KIND_LAPS_MINI_TURBO_COUNT) {
        AddMissionRunCount();
    }
}

void AddMissionRunCountForShapeEntry(void) {
    if (gRaceSetup->mMissionKind == MISSION_KIND_COUNT_SHAPE_ENTRIES) {
        AddMissionRunCount();
    }
}

BOOL IsAnyBalloonUnparked(void) {
    MapObjectList *list;
    Balloon *balloon;
    s32 balloonIndex;

    list = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BALLOON);
    if (list != NULL) {
        for (balloonIndex = 0;
             balloonIndex < list->mMapObjectCount && (balloon = list->mMapObjects[balloonIndex]) != NULL;
             balloonIndex++) {
            if ((balloon->mMapObject.mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void SetMissionRunCountUpCallback(MissionRunEventCallback callback) {
    gMissionRunData->mCountUpCallback = callback;
}

void SetMissionRunDropCallback(MissionRunEventCallback callback) {
    gMissionRunData->mDropCallback = callback;
}

void SetMissionRunBossTransferCallback(MissionRunEventCallback callback) {
    gMissionRunData->mBossTransferCallback = callback;
}

void AddMissionRunPendingDrop(u32 amount) {
    MissionRunData *missionRunData = gMissionRunData;
    u16 count = missionRunData->mCount;
    if (amount >= count) {
        amount = count;
    }
    missionRunData->mPendingDrop += amount;
}

void AddMissionRunPendingBossTransfer(u16 amount) {
    MissionRunData *missionRunData = gMissionRunData;
    u16 count = missionRunData->mCount;
    if (amount >= count) {
        amount = count;
    }
    missionRunData->mPendingBossTransfer += amount;
}

void AddMissionRunBossCount(short amount) {
    gMissionRunData->mBossCount += amount;
    if (gMissionRunData->mBossCount > GetMissionRunCountLimit()) {
        gMissionRunData->mBossCount = GetMissionRunCountLimit();
    }
}

void AddMissionRunPendingCountUp(s32 stepCount) {
    s32 stepIndex;

    for (stepIndex = 0; stepIndex < stepCount; stepIndex++) {
        if (++gMissionRunData->mPendingCountUp > GetMissionRunCountLimit()) {
            gMissionRunData->mPendingCountUp = GetMissionRunCountLimit();
            return;
        }
        if (gMissionRunData->mTimer == 0) {
            gMissionRunData->mTimer = gMissionRunData->mTimerStart;
        } else {
            gMissionRunData->mTimer += gMissionRunData->mCountUpTimerAdd;
            if (gMissionRunData->mTimer > gMissionRunData->mTimerMax) {
                gMissionRunData->mTimer = gMissionRunData->mTimerMax;
            }
        }
    }
}

void AddMissionRunPendingCountUpFromBoss(s32 stepCount) {
    s32 stepIndex;

    if ((u32) stepCount >= gMissionRunData->mBossCount) {
        stepCount = gMissionRunData->mBossCount;
    }
    for (stepIndex = 0; stepIndex < stepCount; stepIndex++) {
        gMissionRunData->mBossCount--;
        if (++gMissionRunData->mPendingCountUp > GetMissionRunCountLimit()) {
            gMissionRunData->mPendingCountUp = GetMissionRunCountLimit();
            return;
        }
        if (gMissionRunData->mTimer == 0) {
            gMissionRunData->mTimer = gMissionRunData->mTimerStart;
        } else {
            gMissionRunData->mTimer += gMissionRunData->mBossTransferTimerAdd;
            if (gMissionRunData->mTimer > gMissionRunData->mTimerMax) {
                gMissionRunData->mTimer = gMissionRunData->mTimerMax;
            }
        }
    }
}
