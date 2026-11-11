#include "Main/Unknown/code_020a8ed8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020f9c6c.h"

#include "code_02146d78.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a9cd4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0215d000.h"
#include "01/code_021a2034.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_02095f38.h"
#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/unk_0215f000.h"
#include "Main/Unknown/code_020a9000.h"
#include "Main/Unknown/code_0203c25c.h"

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
    firstFlag = data_021567ec;
    secondFlag = data_021567f0;
    thirdFlag = data_021567f4;
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
                ironBall->mMapObject.mFlags |= data_021567ec;
                ironBall->mMapObject.mFlags |= data_021567f0;
                ironBall->mMapObject.mFlags |= data_021567f4;
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
        ironBall->mMapObject.mFlags |= data_021567f8;
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
        ironBall->mMapObject.mFlags |= data_021567ec;
    }
}

void CreateIronBallKindData(void) {
    MapObjectKindData *mapObjectKindData;

    mapObjectKindData = CreateMapObjectKindData(CollideKartWithIronBall, NULL, NULL, 1, 1);
    mapObjectKindData->mUnk_38 = 0x190000;
    mapObjectKindData->mUnk_3c = -0x1f4000;
}

void *CreateIronBallShadowDrawList(void) {
    return CreateMapObjectDrawList1(IronBallReturnArgument, DrawIronBallShadow, NULL);
}

void *CreateIronBallDrawList(void) {
    return CreateMapObjectDrawList2(CreateIronBall, DrawIronBall, SetupDrawIronBall);
}

void *CreateIronBallUpdateList(void) {
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
                soundPart->mSourcePos.x = position->x + MUL_FIXED12_NO_ROUND(data_0215feb4[0x54], 0x5dc000);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + MUL_FIXED12_NO_ROUND(data_0215feb4[0x55], 0x5dc000);
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
