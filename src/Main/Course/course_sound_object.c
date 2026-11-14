#include "Main/Course/course_sound_object.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Course/code_02042044.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/iron_ball.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/snd_handle_start.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
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
                    courseSoundObject->mState = 4;
                    courseMapRow = courseSoundObject->mMapObject.mCourseMapRow;
                    crossFirstZ = courseMapRow->mPosition.z + (-0x4a6000);
                    crossFirstY = courseMapRow->mPosition.y;
                    crossFirstX = courseMapRow->mPosition.x + (-0x2c6000);
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = 0x103;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = 5;
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
                    courseSoundObject->mSecondPart.mStartParams.mSoundId = 0x103;
                    courseSoundObject->mSecondPart.mStartParams.mFalloffIndex = 5;
                    courseSoundObject->mSecondPart.mStartParams.mPositionSource =
                        &courseSoundObject->mSecondPart.mSourcePos;
                    courseSoundObject->mSecondPart.mSndHandleSlot = GetSndHandleSlot(9);
                    courseSoundObject->mSecondPart.mSourcePos.x = crossSecondX;
                    courseSoundObject->mSecondPart.mSourcePos.y = crossSecondY;
                    courseSoundObject->mSecondPart.mSourcePos.z = crossSecondZ;
                    break;
                case COURSE_ID_BANK:
                    courseSoundObject->mState = 5;
                    courseMapRow = courseSoundObject->mMapObject.mCourseMapRow;
                    bankChainZ = courseMapRow->mPosition.z;
                    bankChainY = courseMapRow->mPosition.y;
                    bankChainX = courseMapRow->mPosition.x;
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = 0x109;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = 4;
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
                    if ((courseSoundObject->mMapObject.mFlags & 0x100) == 0) {
                        ParkMapObject(&courseSoundObject->mMapObject);
                    }
                    break;
            }
        } else {
            switch (gRaceSetup->mCourseId) {
                case COURSE_ID_CROSS:
                    courseSoundObject->mState = 1;
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = 0x108;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = 8;
                    courseSoundObject->mFirstPart.mStartParams.mPositionSource =
                        &courseSoundObject->mFirstPart.mSourcePos;
                    courseSoundObject->mFirstPart.mSndHandleSlot = GetSndHandleSlot(8);
                    courseSoundObject->mFirstPart.mSourcePos.x = 0;
                    courseSoundObject->mFirstPart.mSourcePos.y = 0;
                    courseSoundObject->mFirstPart.mSourcePos.z = 0;
                    courseSoundObject->mSecondPart.mStartParams.mSoundId = 0x107;
                    courseSoundObject->mSecondPart.mStartParams.mFalloffIndex = 8;
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
                    courseSoundObject->mState = 1;
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = 0x1a0;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = 8;
                    courseSoundObject->mFirstPart.mStartParams.mPositionSource =
                        &courseSoundObject->mFirstPart.mSourcePos;
                    courseSoundObject->mFirstPart.mSndHandleSlot = GetSndHandleSlot(8);
                    courseSoundObject->mFirstPart.mSourcePos.x = 0;
                    courseSoundObject->mFirstPart.mSourcePos.y = 0;
                    courseSoundObject->mFirstPart.mSourcePos.z = 0;
                    courseSoundObject->mSecondPart.mStartParams.mSoundId = 0x19f;
                    courseSoundObject->mSecondPart.mStartParams.mFalloffIndex = 8;
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
                    courseSoundObject->mState = 6;
                    courseMapRow = courseSoundObject->mMapObject.mCourseMapRow;
                    bankFirstZ = courseMapRow->mPosition.z;
                    bankFirstY = courseMapRow->mPosition.y;
                    bankFirstX = courseMapRow->mPosition.x;
                    courseSoundObject->mFirstPart.mStartParams.mSoundId = 0x109;
                    courseSoundObject->mFirstPart.mStartParams.mFalloffIndex = 6;
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
                    courseSoundObject->mSecondPart.mStartParams.mSoundId = 0x109;
                    courseSoundObject->mSecondPart.mStartParams.mFalloffIndex = 6;
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
                    if ((courseSoundObject->mMapObject.mFlags & 0x100) == 0) {
                        ParkMapObject(&courseSoundObject->mMapObject);
                    }
                    break;
            }
        }
    }
}

static inline void StartCourseSoundPartIfInRange(CourseSoundObjectPart *soundPart) {
    s32 falloffDistanceSquared;

    if (soundPart->mStartParams.mFalloffIndex == 2) {
        falloffDistanceSquared = gSoundFalloffs[2].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == 3) {
        falloffDistanceSquared = gSoundFalloffs[3].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == 4) {
        falloffDistanceSquared = gSoundFalloffs[4].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == 5) {
        falloffDistanceSquared = gSoundFalloffs[5].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == 6) {
        falloffDistanceSquared = gSoundFalloffs[6].mFarDistanceSquared;
    } else if (soundPart->mStartParams.mFalloffIndex == 8) {
        falloffDistanceSquared = gSoundFalloffs[8].mFarDistanceSquared;
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
        case 1:
            if (IsRaceStarted() == 1) {
                soundId = courseSoundObject->mSecondPart.mStartParams.mSoundId;
                NNS_SndPlayerStopSeq(courseSoundObject->mFirstPart.mSndHandleSlot, 0);
                courseSoundObject->mFirstPart.mStartParams.mSoundId = soundId;
                courseSoundObject->mState = 2;
            }
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            break;
        case 2:
            PlaceCourseSoundObjectPartSource(&courseSoundObject->mFirstPart, &courseSoundObject->mMapObject.mPos);
            if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL && IsKartOnLastLap(gRaceSetup->mEntryIndex) != FALSE &&
                courseSoundObject->mFirstPart.mInRangeUpdateCount == 0 &&
                courseSoundObject->mFirstPart.mCameraOnOtherSide != FALSE) {
                soundId = GetLastLapCourseSoundId();
                NNS_SndPlayerStopSeq(courseSoundObject->mFirstPart.mSndHandleSlot, 0);
                courseSoundObject->mFirstPart.mStartParams.mSoundId = soundId;
                courseSoundObject->mState = 3;
            }
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            break;
        case 3:
            PlaceCourseSoundObjectPartSource(&courseSoundObject->mFirstPart, &courseSoundObject->mMapObject.mPos);
            if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0) {
                ParkMapObject(&courseSoundObject->mMapObject);
            } else if (courseSoundObject->mFirstPart.mCameraOnOtherSide == FALSE) {
                soundId = courseSoundObject->mSecondPart.mStartParams.mSoundId;
                NNS_SndPlayerStopSeq(courseSoundObject->mFirstPart.mSndHandleSlot, 0);
                courseSoundObject->mFirstPart.mStartParams.mSoundId = soundId;
                courseSoundObject->mState = 2;
            }
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            break;
        case 4:
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            StartCourseSoundPartIfInRange(&courseSoundObject->mSecondPart);
            break;
        case 5:
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            break;
        case 6:
            StartCourseSoundPartIfInRange(&courseSoundObject->mFirstPart);
            StartCourseSoundPartIfInRange(&courseSoundObject->mSecondPart);
            break;
    }
}
