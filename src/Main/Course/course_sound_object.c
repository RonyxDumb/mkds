#include "Main/Course/course_sound_object.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/iron_ball.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_handle_start_and_distance_change.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/race_end_seq_menu_seqs_and_emblem_sound.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Race/race_progress_rank.h"
#include "Main/Race/kart.h"

// Sets up the sound parts of each object per course and camera mode.
void InitCourseSoundObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    CourseSoundObject *courseSoundObject;
    CourseMapRow *courseMapRow;
    s32 crossFirstX;
    s32 crossFirstY;
    s32 crossFirstZ;
    s32 crossSecondX;
    s32 crossSecondY;
    s32 crossSecondZ;
    s32 bankChainX;
    s32 bankChainY;
    s32 bankChainZ;
    s32 bankFirstX;
    s32 bankFirstY;
    s32 bankFirstZ;
    s32 bankSecondX;
    s32 bankSecondY;
    s32 bankSecondZ;
    s32 handleSlotIndex;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (courseSoundObject = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if (GetRaceUseChainCameras() != 0) {
            switch (gRaceSetup->mCourseId) {
                case COURSE_ID_CROSS:
                    courseSoundObject->mState = COURSE_SOUND_STATE_CHAIN_TWO_PARTS;
                    courseMapRow = courseSoundObject->mMapObject.mCourseMapRow;
                    crossFirstZ = courseMapRow->mPosition.z + (-0x4a6000);
                    crossFirstY = courseMapRow->mPosition.y;
                    crossFirstX = courseMapRow->mPosition.x + (-0x2c6000);
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = COURSE_SOUND_ID_CROSS_CHAIN;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = SOUND_FALLOFF_VERY_LONG_RANGE;
                    courseSoundObject->mFirstPart.mStartParams.mPositionSource =
                        &courseSoundObject->mFirstPart.mSourcePos;
                    courseSoundObject->mFirstPart.mSndHandleSlot = GetSndHandleSlot(8);
                    courseSoundObject->mFirstPart.mSourcePos.x = crossFirstX;
                    courseSoundObject->mFirstPart.mSourcePos.y = crossFirstY;
                    courseSoundObject->mFirstPart.mSourcePos.z = crossFirstZ;
                    courseMapRow = courseSoundObject->mMapObject.mCourseMapRow;
                    crossSecondZ = courseMapRow->mPosition.z + 0x726000;
                    crossSecondY = courseMapRow->mPosition.y;
                    crossSecondX = courseMapRow->mPosition.x + (-0x7ee000);
                    courseSoundObject->mSecondPart.mStartParams.mSoundId = COURSE_SOUND_ID_CROSS_CHAIN;
                    courseSoundObject->mSecondPart.mStartParams.mFalloffIndex = SOUND_FALLOFF_VERY_LONG_RANGE;
                    courseSoundObject->mSecondPart.mStartParams.mPositionSource =
                        &courseSoundObject->mSecondPart.mSourcePos;
                    courseSoundObject->mSecondPart.mSndHandleSlot = GetSndHandleSlot(9);
                    courseSoundObject->mSecondPart.mSourcePos.x = crossSecondX;
                    courseSoundObject->mSecondPart.mSourcePos.y = crossSecondY;
                    courseSoundObject->mSecondPart.mSourcePos.z = crossSecondZ;
                    break;
                case COURSE_ID_BANK:
                    courseSoundObject->mState = COURSE_SOUND_STATE_CHAIN_ONE_PART;
                    courseMapRow = courseSoundObject->mMapObject.mCourseMapRow;
                    bankChainZ = courseMapRow->mPosition.z;
                    bankChainY = courseMapRow->mPosition.y;
                    bankChainX = courseMapRow->mPosition.x;
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = COURSE_SOUND_ID_BANK;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = SOUND_FALLOFF_LONG_RANGE;
                    courseSoundObject->mFirstPart.mStartParams.mPositionSource =
                        &courseSoundObject->mFirstPart.mSourcePos;
                    if (mapObjectIndex == 0) {
                        handleSlotIndex = 8;
                    } else if (mapObjectIndex == 1) {
                        handleSlotIndex = 9;
                    } else {
                        handleSlotIndex = 10;
                    }
                    courseSoundObject->mFirstPart.mSndHandleSlot = GetSndHandleSlot(handleSlotIndex);
                    courseSoundObject->mFirstPart.mSourcePos.x = bankChainX;
                    courseSoundObject->mFirstPart.mSourcePos.y = bankChainY;
                    courseSoundObject->mFirstPart.mSourcePos.z = bankChainZ;
                    VEC_MultAdd(MUL_FIXED12_NO_ROUND(courseSoundObject->mMapObject.mScale.z, 0x5000),
                                &courseSoundObject->mMapObject.mMatrix.mRows[2],
                                &courseSoundObject->mFirstPart.mSourcePos, &courseSoundObject->mFirstPart.mSourcePos);
                    break;
                default:
                    if ((courseSoundObject->mMapObject.mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
                        ParkMapObject(&courseSoundObject->mMapObject);
                    }
                    break;
            }
        } else {
            switch (gRaceSetup->mCourseId) {
                case COURSE_ID_CROSS:
                    courseSoundObject->mState = COURSE_SOUND_STATE_WAIT_RACE_START;
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = COURSE_SOUND_ID_CROSS_FIRST_PART;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = SOUND_FALLOFF_LONGER_RANGE;
                    courseSoundObject->mFirstPart.mStartParams.mPositionSource =
                        &courseSoundObject->mFirstPart.mSourcePos;
                    courseSoundObject->mFirstPart.mSndHandleSlot = GetSndHandleSlot(8);
                    courseSoundObject->mFirstPart.mSourcePos.x = 0;
                    courseSoundObject->mFirstPart.mSourcePos.y = 0;
                    courseSoundObject->mFirstPart.mSourcePos.z = 0;
                    courseSoundObject->mSecondPart.mStartParams.mSoundId = COURSE_SOUND_ID_CROSS_SECOND_PART;
                    courseSoundObject->mSecondPart.mStartParams.mFalloffIndex = SOUND_FALLOFF_LONGER_RANGE;
                    courseSoundObject->mSecondPart.mStartParams.mPositionSource =
                        &courseSoundObject->mSecondPart.mSourcePos;
                    courseSoundObject->mSecondPart.mSndHandleSlot = GetSndHandleSlot(9);
                    courseSoundObject->mSecondPart.mSourcePos.x = 0;
                    courseSoundObject->mSecondPart.mSourcePos.y = 0;
                    courseSoundObject->mSecondPart.mSourcePos.z = 0;
                    PlaceCourseSoundObjectPartSource(&courseSoundObject->mFirstPart,
                                                     &courseSoundObject->mMapObject.mPos);
                    break;
                case COURSE_ID_MARIO:
                    courseSoundObject->mState = COURSE_SOUND_STATE_WAIT_RACE_START;
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = COURSE_SOUND_ID_MARIO_FIRST_PART;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = SOUND_FALLOFF_LONGER_RANGE;
                    courseSoundObject->mFirstPart.mStartParams.mPositionSource =
                        &courseSoundObject->mFirstPart.mSourcePos;
                    courseSoundObject->mFirstPart.mSndHandleSlot = GetSndHandleSlot(8);
                    courseSoundObject->mFirstPart.mSourcePos.x = 0;
                    courseSoundObject->mFirstPart.mSourcePos.y = 0;
                    courseSoundObject->mFirstPart.mSourcePos.z = 0;
                    courseSoundObject->mSecondPart.mStartParams.mSoundId = COURSE_SOUND_ID_MARIO_SECOND_PART;
                    courseSoundObject->mSecondPart.mStartParams.mFalloffIndex = SOUND_FALLOFF_LONGER_RANGE;
                    courseSoundObject->mSecondPart.mStartParams.mPositionSource =
                        &courseSoundObject->mSecondPart.mSourcePos;
                    courseSoundObject->mSecondPart.mSndHandleSlot = GetSndHandleSlot(9);
                    courseSoundObject->mSecondPart.mSourcePos.x = 0;
                    courseSoundObject->mSecondPart.mSourcePos.y = 0;
                    courseSoundObject->mSecondPart.mSourcePos.z = 0;
                    PlaceCourseSoundObjectPartSource(&courseSoundObject->mFirstPart,
                                                     &courseSoundObject->mMapObject.mPos);
                    break;
                case COURSE_ID_BANK:
                    courseSoundObject->mState = COURSE_SOUND_STATE_TWO_PARTS;
                    courseMapRow = courseSoundObject->mMapObject.mCourseMapRow;
                    bankFirstZ = courseMapRow->mPosition.z;
                    bankFirstY = courseMapRow->mPosition.y;
                    bankFirstX = courseMapRow->mPosition.x;
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = COURSE_SOUND_ID_BANK;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = SOUND_FALLOFF_SHORT_MEDIUM_RANGE;
                    courseSoundObject->mFirstPart.mStartParams.mPositionSource =
                        &courseSoundObject->mFirstPart.mSourcePos;
                    courseSoundObject->mFirstPart.mSndHandleSlot = GetSndHandleSlot(8);
                    courseSoundObject->mFirstPart.mSourcePos.x = bankFirstX;
                    courseSoundObject->mFirstPart.mSourcePos.y = bankFirstY;
                    courseSoundObject->mFirstPart.mSourcePos.z = bankFirstZ;
                    VEC_MultAdd(MUL_FIXED12_NO_ROUND(courseSoundObject->mMapObject.mScale.z, 0x5000),
                                &courseSoundObject->mMapObject.mMatrix.mRows[2],
                                &courseSoundObject->mFirstPart.mSourcePos, &courseSoundObject->mFirstPart.mSourcePos);
                    courseMapRow = courseSoundObject->mMapObject.mCourseMapRow;
                    bankSecondZ = courseMapRow->mPosition.z;
                    bankSecondY = courseMapRow->mPosition.y;
                    bankSecondX = courseMapRow->mPosition.x;
                    courseSoundObject->mSecondPart.mStartParams.mSoundId = COURSE_SOUND_ID_BANK;
                    courseSoundObject->mSecondPart.mStartParams.mFalloffIndex = SOUND_FALLOFF_SHORT_MEDIUM_RANGE;
                    courseSoundObject->mSecondPart.mStartParams.mPositionSource =
                        &courseSoundObject->mSecondPart.mSourcePos;
                    courseSoundObject->mSecondPart.mSndHandleSlot = GetSndHandleSlot(9);
                    courseSoundObject->mSecondPart.mSourcePos.x = bankSecondX;
                    courseSoundObject->mSecondPart.mSourcePos.y = bankSecondY;
                    courseSoundObject->mSecondPart.mSourcePos.z = bankSecondZ;
                    VEC_MultAdd(MUL_FIXED12_NO_ROUND(courseSoundObject->mMapObject.mScale.z, -0x5000),
                                &courseSoundObject->mMapObject.mMatrix.mRows[2],
                                &courseSoundObject->mSecondPart.mSourcePos, &courseSoundObject->mSecondPart.mSourcePos);
                    break;
                default:
                    if ((courseSoundObject->mMapObject.mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
                        ParkMapObject(&courseSoundObject->mMapObject);
                    }
                    break;
            }
        }
    }
}

static inline void StartCourseSoundPartIfInRange(CourseSoundObjectPart *soundPart) {
    s32 falloffDistanceSquared;

    if (soundPart->mStartParams.mFalloffIndex == SOUND_FALLOFF_SHORT_RANGE) {
        falloffDistanceSquared = gSoundFalloffs[SOUND_FALLOFF_SHORT_RANGE].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == SOUND_FALLOFF_MEDIUM_RANGE) {
        falloffDistanceSquared = gSoundFalloffs[SOUND_FALLOFF_MEDIUM_RANGE].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == SOUND_FALLOFF_LONG_RANGE) {
        falloffDistanceSquared = gSoundFalloffs[SOUND_FALLOFF_LONG_RANGE].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == SOUND_FALLOFF_VERY_LONG_RANGE) {
        falloffDistanceSquared = gSoundFalloffs[SOUND_FALLOFF_VERY_LONG_RANGE].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == SOUND_FALLOFF_SHORT_MEDIUM_RANGE) {
        falloffDistanceSquared = gSoundFalloffs[SOUND_FALLOFF_SHORT_MEDIUM_RANGE].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == SOUND_FALLOFF_LONGER_RANGE) {
        falloffDistanceSquared = gSoundFalloffs[SOUND_FALLOFF_LONGER_RANGE].mFarDistanceSquared;
    } else {
        falloffDistanceSquared = 0;
    }
    soundPart->mStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&soundPart->mSourcePos);
    if (soundPart->mStartParams.mDistanceSquared < falloffDistanceSquared) {
        soundPart->mInRangeUpdateCount = soundPart->mInRangeUpdateCount == 0 ? 1 : 2;
        if (GetRaceUseChainCameras() != 0) {
            StartSndHandleSoundUnchecked(&soundPart->mStartParams, soundPart->mSndHandleSlot);
        } else {
            StartSndHandleSound(&soundPart->mStartParams, soundPart->mSndHandleSlot);
        }
    } else {
        soundPart->mInRangeUpdateCount = 0;
    }
}

void UpdateCourseSoundObject(void *mapObjectList, CourseSoundObject *courseSoundObject) {
    s32 soundId;

    switch (courseSoundObject->mState) {
        case COURSE_SOUND_STATE_WAIT_RACE_START:
            if (IsRaceStarted() == 1) {
                soundId = courseSoundObject->mSecondPart.mStartParams.mSoundId;
                NNS_SndPlayerStopSeq(courseSoundObject->mFirstPart.mSndHandleSlot, 0);
                courseSoundObject->mFirstPart.mStartParams.mSoundId = soundId;
                courseSoundObject->mState = COURSE_SOUND_STATE_RACE;
            }
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            break;
        case COURSE_SOUND_STATE_RACE:
            PlaceCourseSoundObjectPartSource(&courseSoundObject->mFirstPart, &courseSoundObject->mMapObject.mPos);
            if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL && IsKartOnLastLap(gRaceSetup->mEntryIndex) != FALSE &&
                courseSoundObject->mFirstPart.mInRangeUpdateCount == 0 &&
                courseSoundObject->mFirstPart.mCameraOnOtherSide != FALSE) {
                soundId = GetLastLapCourseSoundId();
                NNS_SndPlayerStopSeq(courseSoundObject->mFirstPart.mSndHandleSlot, 0);
                courseSoundObject->mFirstPart.mStartParams.mSoundId = soundId;
                courseSoundObject->mState = COURSE_SOUND_STATE_LAST_LAP;
            }
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            break;
        case COURSE_SOUND_STATE_LAST_LAP:
            PlaceCourseSoundObjectPartSource(&courseSoundObject->mFirstPart, &courseSoundObject->mMapObject.mPos);
            if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0) {
                ParkMapObject(&courseSoundObject->mMapObject);
            } else if (courseSoundObject->mFirstPart.mCameraOnOtherSide == FALSE) {
                soundId = courseSoundObject->mSecondPart.mStartParams.mSoundId;
                NNS_SndPlayerStopSeq(courseSoundObject->mFirstPart.mSndHandleSlot, 0);
                courseSoundObject->mFirstPart.mStartParams.mSoundId = soundId;
                courseSoundObject->mState = COURSE_SOUND_STATE_RACE;
            }
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            break;
        case COURSE_SOUND_STATE_CHAIN_TWO_PARTS:
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            StartCourseSoundPartIfInRange(&courseSoundObject->mSecondPart);
            break;
        case COURSE_SOUND_STATE_CHAIN_ONE_PART:
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            break;
        case COURSE_SOUND_STATE_TWO_PARTS:
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            StartCourseSoundPartIfInRange(&courseSoundObject->mSecondPart);
            break;
    }
}
