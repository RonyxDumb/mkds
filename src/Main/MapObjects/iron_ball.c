#include "Main/MapObjects/iron_ball.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Course/code_02042044.h"
#include "Main/Item/item_koura_w.h"

#include "fx_mtx33.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/iron_ball_kart.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "01/MapObjects/periodic_effect.h"
#include "code_02148538.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/Kart/karts.h"
#include "Main/Sound/map_object_sound_counter.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/cover_poo_hole_cover_height.h"
#include "Main/MapObjects/shadow_position_raised.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "code_02147cd8.h"
#include "Main/Race/race_progress_rank.h"

u32 IronBallReturnArgument(u32 value) {
    return value;
}

void DrawIronBallShadow(void *mapObjectList, IronBall *ironBall, u32 unused, u32 alpha) {
    u32 shadowAlphaCap;

    if (ironBall->mShadowStage == 0) {
        return;
    }
    if (((s32) ironBall->mMapObject.mDistanceSquaredAndFlags & 0x3fffffe0) >= 1000000) {
        return;
    }
    shadowAlphaCap = ironBall->mShadowMatrix.mAlphaCap;
    if (shadowAlphaCap == 0) {
        return;
    }
    if (shadowAlphaCap > 0x1c) {
        return;
    }
    DrawObjShadow(&ironBall->mShadowMatrix, NULL, unused, alpha);
}

void InitIronBallObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    IronBall *ironBall;
    u32 followerSpeed;
    u32 stateA;
    u32 stateB;
    u32 shadowAlphaCap;
    u16 firstFlag;
    u16 secondFlag;
    u16 thirdFlag;

    if (mapObjectList == NULL) {
        return;
    }
    followerSpeed = 0;
    stateA = 0;
    stateB = 0;
    shadowAlphaCap = 0x1c;
    firstFlag = gIronBallInitFirstFlag;
    secondFlag = gIronBallInitSecondFlag;
    thirdFlag = gIronBallInitThirdFlag;
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (ironBall = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        ironBall->mMapObject.mFlags |= firstFlag;
        ironBall->mMapObject.mFlags |= secondFlag;
        ironBall->mMapObject.mFlags |= thirdFlag;
        ironBall->mNormalPathSpeed = (ironBall->mMapObject.mCourseMapRow->mSettings[0] * 0xa000L) / 100;
        ironBall->mSlowPathSpeed = (ironBall->mMapObject.mCourseMapRow->mSettings[0] * 0x5000L) / 100;
        ironBall->mPathSpeed = ironBall->mNormalPathSpeed;
        ironBall->mPathPos = ironBall->mMapObject.mCourseMapRow->mPosition;
        ironBall->mMapObject.mPos = ironBall->mPathPos;
        ironBall->mPathPos.y += 0x1000;
        RefreshShadowMatrix(&ironBall->mShadowMatrix, &ironBall->mPathPos, ironBall->mMapObject.mExtent.x << 1,
                            shadowAlphaCap);
        RefreshMapObjectMatrixFromHitNormal(&ironBall->mMapObject);
        InitGroupFollower(&ironBall->mFollower, ironBall->mMapObject.mCourseMapRow, followerSpeed);
        GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mMapObject.mPosStep);
        ironBall->mPathPos.y += 0x1000;
        VEC_MultAdd(ironBall->mMapObject.mExtent.x, &ironBall->mMapObject.mMatrix.mRows[1], &ironBall->mPathPos,
                    &ironBall->mMapObject.mPos);
        if (ironBall->mMapObject.mFlags & 0x800) {
            ironBall->mTimer = (u16) ironBall->mMapObject.mCourseMapRow->mSettings[1];
            ironBall->mState = stateB;
        } else {
            ironBall->mNextStartLap = (ironBall->mMapObject.mCourseMapRow->mSettings[1] + 0x176f) / 6000 + 1;
            ironBall->mState = stateA;
        }
    }
}

void UpdateIronBall(void *mapObjectList, IronBall *ironBall) {
    CourseMapGroupEntry *fromEntry;
    RandomState64 *mapObjectRandom;
    BOOL lapReached;
    s32 value;
    s32 limit;
    s32 kartIndex;
    s32 settingValue;
    s32 flipperIndex;
    u16 randomNumber;

    if (ironBall->mTimer > 0) {
        ironBall->mTimer -= 1;
    }
    switch (ironBall->mState) {
        case 0:
            if (ironBall->mMapObject.mFlags & 0x800) {
                if (ironBall->mTimer-- > 0) {
                    return;
                }
                ironBall->mTimer = (u16) ironBall->mMapObject.mCourseMapRow->mSettings[2];
                ironBall->mState1Timer = (u16) ironBall->mMapObject.mCourseMapRow->mSettings[3];
                SetupGroupFollowerAtEntry(&ironBall->mFollower, 0, 1);
                ironBall->mState = 1;
                return;
            }
            limit = ironBall->mNextStartLap;
            for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
                if (GetKartHighestLap((u16) kartIndex) >= limit) {
                    lapReached = TRUE;
                    goto found;
                }
            }
            lapReached = FALSE;
        found:
            if (lapReached == FALSE) {
                return;
            }
            ironBall->mNextStartLap = ironBall->mNextStartLap + 1;
            ironBall->mState1Timer = (u16) ironBall->mMapObject.mCourseMapRow->mSettings[3];
            SetupGroupFollowerAtEntry(&ironBall->mFollower, 0, 1);
            ironBall->mState = 1;
            return;
        case 1:
            ironBall->mState1Timer -= 1;
            if (ironBall->mState1Timer > 0) {
                return;
            }
            ironBall->mMapObject.mFlags &= ~1;
            ironBall->mMapObject.mFlags &= ~2;
            ironBall->mMapObject.mFlags &= ~8;
            ironBall->mMapObject.mAlpha = 0x1f;
            ironBall->mState = 2;
            return;
        case 2:
            break;
        default:
            return;
    }
    if (!(GetKartKind3ShapeListMask() & ironBall->mSoundOffKind3ShapeListMask) &&
        !(ironBall->mMapObject.mDistanceSquaredAndFlags & 4)) {
        StartIronBallSpeedSound(ironBall->mMapObject.mSound, ironBall->mPathSpeed);
    }
    value = ironBall->mPathSpeed;
    ironBall->mFollower.mSpeed = value;
    ironBall->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
        value, ironBall->mFollower.mPath->mSegments[ironBall->mFollower.mSegmentIndex].mInverseProgressLength);
    if (AdvanceGroupFollower(&ironBall->mFollower) != FALSE) {
        fromEntry = ironBall->mFollower.mFromEntry;
        if (ironBall->mFollower.mForward == 0) {
            if (fromEntry->mUnk_10 >= 0) {
                SetupGroupFollowerAtEntry(&ironBall->mFollower, fromEntry->mUnk_10, 1);
                fromEntry = ironBall->mFollower.mFromEntry;
            } else if (ironBall->mMapObject.mCourseMapRow->mSettings[2] != 0) {
                SetupGroupFollowerAtEntry(&ironBall->mFollower, 0, 1);
                ironBall->mMapObject.mFlags |= gIronBallInitFirstFlag;
                ironBall->mMapObject.mFlags |= gIronBallInitSecondFlag;
                ironBall->mMapObject.mFlags |= gIronBallInitThirdFlag;
                ironBall->mState = 0;
                return;
            } else {
                ParkMapObject(&ironBall->mMapObject);
                return;
            }
        } else if (fromEntry->mUnk_10 >= 0) {
            mapObjectRandom = GetMapObjectRandom();
            mapObjectRandom->mValue =
                mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            randomNumber = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 5) >> 32;
            if (randomNumber != 0) {
                SetupGroupFollowerAtEntry(&ironBall->mFollower, fromEntry->mUnk_10, 1);
                fromEntry = ironBall->mFollower.mFromEntry;
            }
        }
        value = fromEntry->mUnk_0e;
        if ((u16) value <= 1) {
            ironBall->mPathSpeed = ironBall->mNormalPathSpeed;
            ironBall->mShadowStage = 0;
        } else if ((u16) (s16) (value - 2) <= 1) {
            ironBall->mPathSpeed = ironBall->mSlowPathSpeed;
            ironBall->mShadowStage = 2;
        } else if (value == 10) {
            ironBall->mPathSpeed = 0x8000;
            ironBall->mShadowStage = 2;
            ironBall->mHeightOffset = ironBall->mPathPos.y;
            SetupGroupFollowerAtEntry(&ironBall->mFollower, fromEntry->mUnk_0c + 1, 1);
            GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mMapObject.mPosStep);
            ironBall->mPathPos.y += 0x1000;
            ironBall->mHeightOffset = ironBall->mHeightOffset - ironBall->mPathPos.y;
            ironBall->mHeightSpeed = 0xa000;
        } else if (value == 11) {
            ironBall->mPathSpeed = 0x5000;
            ironBall->mShadowStage = 2;
            ironBall->mHeightOffset = ironBall->mPathPos.y;
            SetupGroupFollowerAtEntry(&ironBall->mFollower, fromEntry->mUnk_0c + 1, 1);
            GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mMapObject.mPosStep);
            ironBall->mPathPos.y += 0x1000;
            ironBall->mHeightOffset = ironBall->mHeightOffset - ironBall->mPathPos.y;
            ironBall->mHeightSpeed = -0x3000;
        } else if (value >= 100) {
            ironBall->mPathPos = fromEntry->mPos;
            ironBall->mMapObject.mPosStep.x = 0;
            ironBall->mMapObject.mPosStep.y = 0;
            ironBall->mMapObject.mPosStep.z = 0;
            settingValue = fromEntry->mUnk_0e;
            if (settingValue < 200) {
                StartBoundWobble(settingValue - 100);
                ironBall->mPathSpeed = 0xf000;
                ironBall->mShadowStage = 1;
            } else if (settingValue < 300) {
                flipperIndex = settingValue - 200;
                if (settingValue != ironBall->mFollower.mToEntry->mUnk_0e) {
                    ironBall->mPathSpeed = 0x1e000;
                } else {
                    SetFlipperState4TimerByIndex(flipperIndex);
                }
                ironBall->mShadowStage = 1;
            }
        }
    }
    if (ironBall->mFollower.mFromEntry->mUnk_0d != 0 && ironBall->mFollower.mToEntry->mUnk_0d != 0) {
        ironBall->mMapObject.mFlags |= gIronBallPathEntryFlag;
    } else {
        ironBall->mMapObject.mFlags &= ~0x20;
    }
    if (ironBall->mHeightOffset > 0 || ironBall->mHeightSpeed != 0) {
        ironBall->mHeightSpeed -= 0x1000;
        ironBall->mHeightOffset = ironBall->mHeightOffset + ironBall->mHeightSpeed;
        if (ironBall->mHeightOffset <= 0) {
            ironBall->mHeightSpeed = MUL_FIXED12_NO_ROUND(ironBall->mHeightSpeed, -0x800);
            if (ironBall->mHeightSpeed < 0x1000) {
                ironBall->mHeightSpeed = 0;
            } else if (!(GetKartKind3ShapeListMask() & ironBall->mSoundOffKind3ShapeListMask) &&
                       !(ironBall->mMapObject.mDistanceSquaredAndFlags & 4)) {
                StartIronBallBounceSound(ironBall->mMapObject.mSound, ironBall->mHeightSpeed);
            }
            ironBall->mHeightOffset = ironBall->mHeightSpeed;
        }
    }
    value = ironBall->mFollower.mFromEntry->mUnk_0e;
    if (value >= 100) {
        GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mMapObject.mPosStep);
        ironBall->mPathPos.y += 0x1000;
        limit = ironBall->mPathSpeed - 410;
        if (limit <= 0xa000) {
            limit = 0xa000;
        }
        ironBall->mPathSpeed = limit;
    } else if ((u16) (s16) (value - 10) <= 1) {
        GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mMapObject.mPosStep);
        ironBall->mPathPos.y += 0x1000;
    } else if (value == 0 || value == 2) {
        GetGroupFollowerCurvePosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mMapObject.mPosStep);
        ironBall->mPathPos.y += 0x1000;
    } else {
        GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mMapObject.mPosStep);
        ironBall->mPathPos.y += 0x1000;
    }
    VEC_MultAdd(ironBall->mMapObject.mExtent.x, &ironBall->mMapObject.mMatrix.mRows[1], &ironBall->mPathPos,
                &ironBall->mMapObject.mPos);
    ironBall->mMapObject.mPos.y = ironBall->mMapObject.mPos.y + ironBall->mHeightOffset;
    if (ironBall->mRotateZAngle < 0) {
        if (ironBall->mRotateZAngle == -1) {
            value = 0x38e;
        } else {
            value = -1;
        }
    } else {
        if (ironBall->mRotateZAngle != 1) {
            value = 1;
        } else {
            value = -0x38e;
        }
    }
    ironBall->mRotateZAngle = value;
    if (ironBall->mShadowStage == 2) {
        RefreshShadowMatrix(&ironBall->mShadowMatrix, &ironBall->mPathPos, ironBall->mMapObject.mExtent.x << 1, 0x1c);
        ironBall->mPathPos.y += 0x1000;
        ironBall->mShadowStage = 1;
    }
    if (ironBall->mShadowStage != 0) {
        if (((s32) ironBall->mMapObject.mDistanceSquaredAndFlags & 0x3fffffe0) < 1000000) {
            limit = (ironBall->mHeightOffset >> 14) - 7;
            if (limit < 0) {
                value = 0x1c;
            } else if (limit < 0x1c) {
                value = 0x1c - limit;
            } else {
                value = 0;
            }
            ironBall->mShadowMatrix.mAlphaCap = value;
            SetShadowPositionRaised(&ironBall->mShadowMatrix, &ironBall->mPathPos);
        }
        ironBall->mMapObject.mFlags &= ~1;
    } else {
        ironBall->mMapObject.mFlags |= gIronBallInitFirstFlag;
    }
}

MapObjectKindData *CreateIronBallKindData(void) {
    MapObjectKindData *mapObjectKindData;

    mapObjectKindData = CreateMapObjectKindData(CollideKartWithIronBall, NULL, NULL, 1, 1);
    mapObjectKindData->mHeightRangeMax = 0x190000;
    mapObjectKindData->mHeightRangeMin = -0x1f4000;
    return mapObjectKindData;
}

MapObjectList *CreateIronBallShadowDrawList(void) {
    return CreateMapObjectDrawList1(IronBallReturnArgument, DrawIronBallShadow, NULL);
}

MapObjectList *CreateIronBallDrawList(void) {
    return CreateMapObjectDrawList2(CreateIronBall, DrawIronBall, SetupDrawIronBall);
}

MapObjectList *CreateIronBallUpdateList(void) {
    return CreateMapObjectUpdateList(InitIronBallObjects, UpdateIronBall, NULL);
}

// Places the part's sound source around the object per course, following the camera x in some cases, and sets mUnk_20
// from the camera position.
void PlaceCourseSoundObjectPartSource(CourseSoundObjectPart *soundPart, Vec3 *position) {
    s32 crossXMargin;
    Camera *currentCamera;
    s32 value;
    s32 scratch;
    s32 sourceX;
    s32 marioXMargin;

    currentCamera = GetCurrentCamera();
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_CROSS:
            if (IsKartOnLastLap(gRaceSetup->mEntryIndex) != FALSE || GetRaceUseChainCameras() != 0) {
                crossXMargin = 0x898000;
            } else {
                crossXMargin = 0x834000;
            }
            value = FX_Atan2Idx(currentCamera->mPos.x - position->x, currentCamera->mPos.z - position->z);
            if (value >= 0 && value <= 0xaaab) {
                soundPart->mSourcePos.x = position->x + MUL_FIXED12_NO_ROUND(SIN_OF_ANGLE((u16) value), 0x5dc000);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + MUL_FIXED12_NO_ROUND(COS_OF_ANGLE((u16) value), 0x5dc000);
                soundPart->mUnk_20 = FALSE;
            } else if (currentCamera->mPos.z > position->z && currentCamera->mPos.y < position->y - 0x32000) {
                soundPart->mSourcePos.x = position->x + MUL_FIXED12_NO_ROUND(SIN_OF_ANGLE(0), 0x5dc000);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + MUL_FIXED12_NO_ROUND(COS_OF_ANGLE(0), 0x5dc000);
                value = soundPart->mSourcePos.x - crossXMargin;
                scratch = currentCamera->mPos.x;
                if (scratch <= value) {
                    scratch = value;
                }
                soundPart->mSourcePos.x = scratch;
                soundPart->mUnk_20 = TRUE;
            } else {
                soundPart->mSourcePos.x = position->x + MUL_FIXED12_NO_ROUND(SIN_OF_ANGLE(0xaaa0), 0x5dc000);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + MUL_FIXED12_NO_ROUND(COS_OF_ANGLE(0xaaa0), 0x5dc000);
                soundPart->mUnk_20 = FALSE;
            }
            break;
        case COURSE_ID_MARIO:
            if (IsKartOnLastLap(gRaceSetup->mEntryIndex) != FALSE || GetRaceUseChainCameras() != 0) {
                marioXMargin = 0x384000;
            } else {
                marioXMargin = 0x320000;
            }
            sourceX = position->x - marioXMargin;
            if (sourceX <= currentCamera->mPos.x) {
                sourceX = position->x + marioXMargin;
                if (sourceX >= currentCamera->mPos.x) {
                    sourceX = currentCamera->mPos.x;
                }
            }
            soundPart->mSourcePos.x = sourceX;
            soundPart->mSourcePos.y = position->y;
            soundPart->mSourcePos.z = position->z;
            if (currentCamera->mPos.x < position->x) {
                soundPart->mUnk_20 = TRUE;
            } else {
                soundPart->mUnk_20 = FALSE;
            }
            break;
    }
}

const u16 gIronBallInitThirdFlag = 8;
const u16 gIronBallInitSecondFlag = 2;
const u16 gIronBallInitFirstFlag = 1;
const u16 gIronBallPathEntryFlag = 0x20;
