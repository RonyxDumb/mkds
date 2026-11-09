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

void DrawIronBallShadow(void *a, IronBall *ironBall, u32 c, u32 d) {
    u32 shadowAlphaCap;

    if (ironBall->mShadowStage == 0) {
        return;
    }
    if (((s32) ironBall->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0) >= 1000000) {
        return;
    }
    shadowAlphaCap = ironBall->mShadowMatrix.mAlphaCap;
    if (shadowAlphaCap == 0) {
        return;
    }
    if (shadowAlphaCap > 0x1c) {
        return;
    }
    func_020e53ac(&ironBall->mShadowMatrix, NULL, c, d);
}

void InitIronBallObjects(MapObjectList *mapObjectList) {
    s32 i;
    IronBall *ironBall;
    u32 z0;
    u32 z1;
    u32 z2;
    u32 shadowAlphaCap;
    u16 b;
    u16 c;
    u16 a;

    if (mapObjectList == NULL) {
        return;
    }
    z0 = 0;
    z1 = 0;
    z2 = 0;
    shadowAlphaCap = 0x1c;
    b = data_021567ec;
    c = data_021567f0;
    a = data_021567f4;
    for (i = 0; i < mapObjectList->mMapObjectCount && (ironBall = mapObjectList->mMapObjects[i]) != NULL; i++) {
        ironBall->mUnk_000.mFlags |= b;
        ironBall->mUnk_000.mFlags |= c;
        ironBall->mUnk_000.mFlags |= a;
        ironBall->mNormalPathSpeed = (ironBall->mUnk_000.mCourseMapRow->mUnk_28 * 0xa000L) / 100;
        ironBall->mSlowPathSpeed = (ironBall->mUnk_000.mCourseMapRow->mUnk_28 * 0x5000L) / 100;
        ironBall->mPathSpeed = ironBall->mNormalPathSpeed;
        ironBall->mPathPos = ironBall->mUnk_000.mCourseMapRow->mUnk_00;
        ironBall->mUnk_000.mPos = ironBall->mPathPos;
        ironBall->mPathPos.y += 0x1000;
        RefreshShadowMatrix(&ironBall->mShadowMatrix, &ironBall->mPathPos, ironBall->mUnk_000.mExtent.x << 1,
                            shadowAlphaCap);
        RefreshMapObjectMatrixFromHitNormal(&ironBall->mUnk_000);
        InitGroupFollower(&ironBall->mFollower, ironBall->mUnk_000.mCourseMapRow, z0);
        GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mUnk_000.mUnk_10);
        ironBall->mPathPos.y += 0x1000;
        VEC_MultAdd(ironBall->mUnk_000.mExtent.x, &ironBall->mUnk_000.mMatrix.mUnk_00[1], &ironBall->mPathPos,
                    &ironBall->mUnk_000.mPos);
        if (ironBall->mUnk_000.mFlags & 0x800) {
            ironBall->mTimer = (u16) ironBall->mUnk_000.mCourseMapRow->mUnk_2a;
            ironBall->mState = z2;
        } else {
            ironBall->mNextStartLap = (ironBall->mUnk_000.mCourseMapRow->mUnk_2a + 0x176f) / 6000 + 1;
            ironBall->mState = z1;
        }
    }
}

void UpdateIronBall(void *a, IronBall *ironBall) {
    CourseMapGroupEntry *fromEntry;
    RandomState64 *mapObjectRandom;
    BOOL lapReached;
    s32 v;
    s32 w;
    s32 i;
    s32 n;
    s32 t;
    u16 randomNumber;

    if (ironBall->mTimer > 0) {
        ironBall->mTimer -= 1;
    }
    switch (ironBall->mState) {
        case 0:
            if (ironBall->mUnk_000.mFlags & 0x800) {
                if (ironBall->mTimer-- > 0) {
                    return;
                }
                ironBall->mTimer = (u16) ironBall->mUnk_000.mCourseMapRow->mUnk_2c;
                ironBall->mState1Timer = (u16) ironBall->mUnk_000.mCourseMapRow->mUnk_2e;
                SetupGroupFollowerAtEntry(&ironBall->mFollower, 0, 1);
                ironBall->mState = 1;
                return;
            }
            w = ironBall->mNextStartLap;
            for (i = 0; i < gRaceSetup->mKartCount; i++) {
                if (GetKartHighestLap((u16) i) >= w) {
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
            ironBall->mState1Timer = (u16) ironBall->mUnk_000.mCourseMapRow->mUnk_2e;
            SetupGroupFollowerAtEntry(&ironBall->mFollower, 0, 1);
            ironBall->mState = 1;
            return;
        case 1:
            ironBall->mState1Timer -= 1;
            if (ironBall->mState1Timer > 0) {
                return;
            }
            ironBall->mUnk_000.mFlags &= ~1;
            ironBall->mUnk_000.mFlags &= ~2;
            ironBall->mUnk_000.mFlags &= ~8;
            ironBall->mUnk_000.mAlpha = 0x1f;
            ironBall->mState = 2;
            return;
        case 2:
            break;
        default:
            return;
    }
    if (!(GetKartKind3ShapeMask() & ironBall->mUnk_128) && !(ironBall->mUnk_000.mDistanceSquaredAndFlags & 4)) {
        func_0210b874(ironBall->mUnk_000.mSound, ironBall->mPathSpeed);
    }
    v = ironBall->mPathSpeed;
    ironBall->mFollower.mSpeed = v;
    ironBall->mFollower.mProgressStep =
        ((s64) v * ironBall->mFollower.mPath->mSegments[ironBall->mFollower.mSegmentIndex].mInverseProgressLength) >>
        12;
    if (AdvanceGroupFollower(&ironBall->mFollower) != FALSE) {
        fromEntry = ironBall->mFollower.mFromEntry;
        if (ironBall->mFollower.mForward == 0) {
            if (fromEntry->mUnk_10 >= 0) {
                SetupGroupFollowerAtEntry(&ironBall->mFollower, fromEntry->mUnk_10, 1);
                fromEntry = ironBall->mFollower.mFromEntry;
            } else if (ironBall->mUnk_000.mCourseMapRow->mUnk_2c != 0) {
                SetupGroupFollowerAtEntry(&ironBall->mFollower, 0, 1);
                ironBall->mUnk_000.mFlags |= data_021567ec;
                ironBall->mUnk_000.mFlags |= data_021567f0;
                ironBall->mUnk_000.mFlags |= data_021567f4;
                ironBall->mState = 0;
                return;
            } else {
                ParkMapObject(&ironBall->mUnk_000);
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
        v = fromEntry->mUnk_0e;
        if ((u16) v <= 1) {
            ironBall->mPathSpeed = ironBall->mNormalPathSpeed;
            ironBall->mShadowStage = 0;
        } else if ((u16) (s16) (v - 2) <= 1) {
            ironBall->mPathSpeed = ironBall->mSlowPathSpeed;
            ironBall->mShadowStage = 2;
        } else if (v == 10) {
            ironBall->mPathSpeed = 0x8000;
            ironBall->mShadowStage = 2;
            ironBall->mHeightOffset = ironBall->mPathPos.y;
            SetupGroupFollowerAtEntry(&ironBall->mFollower, fromEntry->mUnk_0c + 1, 1);
            GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mUnk_000.mUnk_10);
            ironBall->mPathPos.y += 0x1000;
            ironBall->mHeightOffset = ironBall->mHeightOffset - ironBall->mPathPos.y;
            ironBall->mHeightSpeed = 0xa000;
        } else if (v == 11) {
            ironBall->mPathSpeed = 0x5000;
            ironBall->mShadowStage = 2;
            ironBall->mHeightOffset = ironBall->mPathPos.y;
            SetupGroupFollowerAtEntry(&ironBall->mFollower, fromEntry->mUnk_0c + 1, 1);
            GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mUnk_000.mUnk_10);
            ironBall->mPathPos.y += 0x1000;
            ironBall->mHeightOffset = ironBall->mHeightOffset - ironBall->mPathPos.y;
            ironBall->mHeightSpeed = -0x3000;
        } else if (v >= 100) {
            ironBall->mPathPos = fromEntry->mPos;
            ironBall->mUnk_000.mUnk_10.x = 0;
            ironBall->mUnk_000.mUnk_10.y = 0;
            ironBall->mUnk_000.mUnk_10.z = 0;
            n = fromEntry->mUnk_0e;
            if (n < 200) {
                StartBoundWobble(n - 100);
                ironBall->mPathSpeed = 0xf000;
                ironBall->mShadowStage = 1;
            } else if (n < 300) {
                t = n - 200;
                if (n != ironBall->mFollower.mToEntry->mUnk_0e) {
                    ironBall->mPathSpeed = 0x1e000;
                } else {
                    func_0209753c(t);
                }
                ironBall->mShadowStage = 1;
            }
        }
    }
    if (ironBall->mFollower.mFromEntry->mUnk_0d != 0 && ironBall->mFollower.mToEntry->mUnk_0d != 0) {
        ironBall->mUnk_000.mFlags |= data_021567f8;
    } else {
        ironBall->mUnk_000.mFlags &= ~0x20;
    }
    if (ironBall->mHeightOffset > 0 || ironBall->mHeightSpeed != 0) {
        ironBall->mHeightSpeed -= 0x1000;
        ironBall->mHeightOffset = ironBall->mHeightOffset + ironBall->mHeightSpeed;
        if (ironBall->mHeightOffset <= 0) {
            ironBall->mHeightSpeed = ((s64) ironBall->mHeightSpeed * -0x800) >> 12;
            if (ironBall->mHeightSpeed < 0x1000) {
                ironBall->mHeightSpeed = 0;
            } else if (!(GetKartKind3ShapeMask() & ironBall->mUnk_128) &&
                       !(ironBall->mUnk_000.mDistanceSquaredAndFlags & 4)) {
                func_0210b8bc(ironBall->mUnk_000.mSound, ironBall->mHeightSpeed);
            }
            ironBall->mHeightOffset = ironBall->mHeightSpeed;
        }
    }
    v = ironBall->mFollower.mFromEntry->mUnk_0e;
    if (v >= 100) {
        GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mUnk_000.mUnk_10);
        ironBall->mPathPos.y += 0x1000;
        w = ironBall->mPathSpeed - 410;
        if (w <= 0xa000) {
            w = 0xa000;
        }
        ironBall->mPathSpeed = w;
    } else if ((u16) (s16) (v - 10) <= 1) {
        GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mUnk_000.mUnk_10);
        ironBall->mPathPos.y += 0x1000;
    } else if (v == 0 || v == 2) {
        GetGroupFollowerCurvePosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mUnk_000.mUnk_10);
        ironBall->mPathPos.y += 0x1000;
    } else {
        GetGroupFollowerLinearPosStep(&ironBall->mFollower, &ironBall->mPathPos, &ironBall->mUnk_000.mUnk_10);
        ironBall->mPathPos.y += 0x1000;
    }
    VEC_MultAdd(ironBall->mUnk_000.mExtent.x, &ironBall->mUnk_000.mMatrix.mUnk_00[1], &ironBall->mPathPos,
                &ironBall->mUnk_000.mPos);
    ironBall->mUnk_000.mPos.y = ironBall->mUnk_000.mPos.y + ironBall->mHeightOffset;
    if (ironBall->mRotateZAngle < 0) {
        if (ironBall->mRotateZAngle == -1) {
            v = 0x38e;
        } else {
            v = -1;
        }
    } else {
        if (ironBall->mRotateZAngle != 1) {
            v = 1;
        } else {
            v = -0x38e;
        }
    }
    ironBall->mRotateZAngle = v;
    if (ironBall->mShadowStage == 2) {
        RefreshShadowMatrix(&ironBall->mShadowMatrix, &ironBall->mPathPos, ironBall->mUnk_000.mExtent.x << 1, 0x1c);
        ironBall->mPathPos.y += 0x1000;
        ironBall->mShadowStage = 1;
    }
    if (ironBall->mShadowStage != 0) {
        if (((s32) ironBall->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0) < 1000000) {
            w = (ironBall->mHeightOffset >> 14) - 7;
            if (w < 0) {
                v = 0x1c;
            } else if (w < 0x1c) {
                v = 0x1c - w;
            } else {
                v = 0;
            }
            ironBall->mShadowMatrix.mAlphaCap = v;
            SetShadowPositionRaised(&ironBall->mShadowMatrix, &ironBall->mPathPos);
        }
        ironBall->mUnk_000.mFlags &= ~1;
    } else {
        ironBall->mUnk_000.mFlags |= data_021567ec;
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
    s32 v;
    s32 n;
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
            v = FX_Atan2Idx(currentCamera->mPos.x - position->x, currentCamera->mPos.z - position->z);
            if (v >= 0 && v <= 0xaaab) {
                n = ((u16) v >> 4) << 1;
                soundPart->mSourcePos.x = position->x + (s32) (((s64) gPairsByAngle[n] * 0x5dc000) >> 12);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + (s32) (((s64) gPairsByAngle[n + 1] * 0x5dc000) >> 12);
                soundPart->mUnk_20 = FALSE;
            } else if (currentCamera->mPos.z > position->z && currentCamera->mPos.y < position->y - 0x32000) {
                soundPart->mSourcePos.x = position->x + (s32) (((s64) gPairsByAngle[0] * 0x5dc000) >> 12);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + (s32) (((s64) gPairsByAngle[1] * 0x5dc000) >> 12);
                v = soundPart->mSourcePos.x - crossXMargin;
                n = currentCamera->mPos.x;
                if (n <= v) {
                    n = v;
                }
                soundPart->mSourcePos.x = n;
                soundPart->mUnk_20 = TRUE;
            } else {
                soundPart->mSourcePos.x = position->x + (s32) (((s64) data_0215feb4[0x54] * 0x5dc000) >> 12);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + (s32) (((s64) data_0215feb4[0x55] * 0x5dc000) >> 12);
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
