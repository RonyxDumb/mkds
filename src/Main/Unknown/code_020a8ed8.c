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

u32 ibal_globalInitShadow(u32 p0) {
    return p0;
}

void ibal_renderShadow(void *a, IronBall *ironBall, u32 c, u32 d) {
    u32 shadowAlphaCap;

    if (ironBall->field12C == 0) {
        return;
    }
    if (((s32) ironBall->field0.mDistanceSquaredAndFlags & 0x3fffffe0) >= 1000000) {
        return;
    }
    shadowAlphaCap = ironBall->mShadowMatrix.field30;
    if (shadowAlphaCap == 0) {
        return;
    }
    if (shadowAlphaCap > 0x1c) {
        return;
    }
    oshd_renderMat(&ironBall->mShadowMatrix, NULL, c, d);
}

void ibal_globalLogicInit(MapObjectList *mapObjectList) {
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
        ironBall->field0.mFlags |= b;
        ironBall->field0.mFlags |= c;
        ironBall->field0.mFlags |= a;
        ironBall->fieldB4 = (ironBall->field0.mCourseMapRow->field28 * 0xa000L) / 100;
        ironBall->fieldB8 = (ironBall->field0.mCourseMapRow->field28 * 0x5000L) / 100;
        ironBall->mPathSpeed = ironBall->fieldB4;
        ironBall->field11C = ironBall->field0.mCourseMapRow->field0;
        ironBall->field0.mPos = ironBall->field11C;
        ironBall->field11C.y += 0x1000;
        oshd_setParams(&ironBall->mShadowMatrix, &ironBall->field11C, ironBall->field0.mExtent.x << 1,
                            shadowAlphaCap);
        mobj_setDirectionFromFloor(&ironBall->field0);
        pw_initFromObject(&ironBall->mFollower, ironBall->field0.mCourseMapRow, z0);
        pw_calcCurrentPointLinearXYZSpecial(&ironBall->mFollower, &ironBall->field11C, &ironBall->field0.field10);
        ironBall->field11C.y += 0x1000;
        VEC_MultAdd(ironBall->field0.mExtent.x, &ironBall->field0.mMatrix.field0[1], &ironBall->field11C,
                    &ironBall->field0.mPos);
        if (ironBall->field0.mFlags & 0x800) {
            ironBall->mTimer = (u16) ironBall->field0.mCourseMapRow->field2A;
            ironBall->mState = z2;
        } else {
            ironBall->mNextStartLap = (ironBall->field0.mCourseMapRow->field2A + 0x176f) / 6000 + 1;
            ironBall->mState = z1;
        }
    }
}

void ibal_update(void *a, IronBall *ironBall) {
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
            if (ironBall->field0.mFlags & 0x800) {
                if (ironBall->mTimer-- > 0) {
                    return;
                }
                ironBall->mTimer = (u16) ironBall->field0.mCourseMapRow->field2C;
                ironBall->mState1Timer = (u16) ironBall->field0.mCourseMapRow->field2E;
                pw_init(&ironBall->mFollower, 0, 1);
                ironBall->mState = 1;
                return;
            }
            w = ironBall->mNextStartLap;
            for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
                if (rstat_getDriverHighestReachedLap((u16) i) >= w) {
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
            ironBall->mState1Timer = (u16) ironBall->field0.mCourseMapRow->field2E;
            pw_init(&ironBall->mFollower, 0, 1);
            ironBall->mState = 1;
            return;
        case 1:
            ironBall->mState1Timer -= 1;
            if (ironBall->mState1Timer > 0) {
                return;
            }
            ironBall->field0.mFlags &= ~1;
            ironBall->field0.mFlags &= ~2;
            ironBall->field0.mFlags &= ~8;
            ironBall->field0.mAlpha = 0x1f;
            ironBall->mState = 2;
            return;
        case 2:
            break;
        default:
            return;
    }
    if (!(driver_getClipAreaMask() & ironBall->field128) && !(ironBall->field0.mDistanceSquaredAndFlags & 4)) {
        func_0210b874(ironBall->field0.mSound, ironBall->mPathSpeed);
    }
    v = ironBall->mPathSpeed;
    ironBall->mFollower.mSpeed = v;
    ironBall->mFollower.mProgressStep =
        ((s64) v * ironBall->mFollower.mPath->mSegments[ironBall->mFollower.mSegmentIndex].mInverseProgressLength) >>
        12;
    if (pw_update(&ironBall->mFollower) != FALSE) {
        fromEntry = ironBall->mFollower.mFromEntry;
        if (ironBall->mFollower.mForward == 0) {
            if (fromEntry->field10 >= 0) {
                pw_init(&ironBall->mFollower, fromEntry->field10, 1);
                fromEntry = ironBall->mFollower.mFromEntry;
            } else if (ironBall->field0.mCourseMapRow->field2C != 0) {
                pw_init(&ironBall->mFollower, 0, 1);
                ironBall->field0.mFlags |= data_021567ec;
                ironBall->field0.mFlags |= data_021567f0;
                ironBall->field0.mFlags |= data_021567f4;
                ironBall->mState = 0;
                return;
            } else {
                mobj_setInvisible(&ironBall->field0);
                return;
            }
        } else if (fromEntry->field10 >= 0) {
            mapObjectRandom = mobj_getRng1();
            mapObjectRandom->mValue =
                mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            randomNumber = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 5) >> 32;
            if (randomNumber != 0) {
                pw_init(&ironBall->mFollower, fromEntry->field10, 1);
                fromEntry = ironBall->mFollower.mFromEntry;
            }
        }
        v = fromEntry->fieldE;
        if ((u16) v <= 1) {
            ironBall->mPathSpeed = ironBall->fieldB4;
            ironBall->field12C = 0;
        } else if ((u16) (s16) (v - 2) <= 1) {
            ironBall->mPathSpeed = ironBall->fieldB8;
            ironBall->field12C = 2;
        } else if (v == 10) {
            ironBall->mPathSpeed = 0x8000;
            ironBall->field12C = 2;
            ironBall->mHeightOffset = ironBall->field11C.y;
            pw_init(&ironBall->mFollower, fromEntry->fieldC + 1, 1);
            pw_calcCurrentPointLinearXYZSpecial(&ironBall->mFollower, &ironBall->field11C, &ironBall->field0.field10);
            ironBall->field11C.y += 0x1000;
            ironBall->mHeightOffset = ironBall->mHeightOffset - ironBall->field11C.y;
            ironBall->mHeightSpeed = 0xa000;
        } else if (v == 11) {
            ironBall->mPathSpeed = 0x5000;
            ironBall->field12C = 2;
            ironBall->mHeightOffset = ironBall->field11C.y;
            pw_init(&ironBall->mFollower, fromEntry->fieldC + 1, 1);
            pw_calcCurrentPointLinearXYZSpecial(&ironBall->mFollower, &ironBall->field11C, &ironBall->field0.field10);
            ironBall->field11C.y += 0x1000;
            ironBall->mHeightOffset = ironBall->mHeightOffset - ironBall->field11C.y;
            ironBall->mHeightSpeed = -0x3000;
        } else if (v >= 100) {
            ironBall->field11C = fromEntry->mPos;
            ironBall->field0.field10.x = 0;
            ironBall->field0.field10.y = 0;
            ironBall->field0.field10.z = 0;
            n = ((const CourseMapGroupEntry *) fromEntry)->fieldE;
            if (n < 200) {
                bnd_handleBallHit(n - 100);
                ironBall->mPathSpeed = 0xf000;
                ironBall->field12C = 1;
            } else if (n < 300) {
                t = n - 200;
                if (n != ironBall->mFollower.mToEntry->fieldE) {
                    ironBall->mPathSpeed = 0x1e000;
                } else {
                    flip_handleBallHit(t);
                }
                ironBall->field12C = 1;
            }
        }
    }
    if (ironBall->mFollower.mFromEntry->fieldD != 0 && ironBall->mFollower.mToEntry->fieldD != 0) {
        ironBall->field0.mFlags |= data_021567f8;
    } else {
        ironBall->field0.mFlags &= ~0x20;
    }
    if (ironBall->mHeightOffset > 0 || ironBall->mHeightSpeed != 0) {
        ironBall->mHeightSpeed -= 0x1000;
        ironBall->mHeightOffset = ironBall->mHeightOffset + ironBall->mHeightSpeed;
        if (ironBall->mHeightOffset <= 0) {
            ironBall->mHeightSpeed = ((s64) ironBall->mHeightSpeed * -0x800) >> 12;
            if (ironBall->mHeightSpeed < 0x1000) {
                ironBall->mHeightSpeed = 0;
            } else if (!(driver_getClipAreaMask() & ironBall->field128) &&
                       !(ironBall->field0.mDistanceSquaredAndFlags & 4)) {
                func_0210b8bc(ironBall->field0.mSound, ironBall->mHeightSpeed);
            }
            ironBall->mHeightOffset = ironBall->mHeightSpeed;
        }
    }
    v = ironBall->mFollower.mFromEntry->fieldE;
    if (v >= 100) {
        pw_calcCurrentPointLinearXYZSpecial(&ironBall->mFollower, &ironBall->field11C, &ironBall->field0.field10);
        ironBall->field11C.y += 0x1000;
        w = ironBall->mPathSpeed - 410;
        if (w <= 0xa000) {
            w = 0xa000;
        }
        ironBall->mPathSpeed = w;
    } else if ((u16) (s16) (v - 10) <= 1) {
        pw_calcCurrentPointLinearXYZSpecial(&ironBall->mFollower, &ironBall->field11C, &ironBall->field0.field10);
        ironBall->field11C.y += 0x1000;
    } else if (v == 0 || v == 2) {
        pw_20D8BF8_XYZ(&ironBall->mFollower, &ironBall->field11C, &ironBall->field0.field10);
        ironBall->field11C.y += 0x1000;
    } else {
        pw_calcCurrentPointLinearXYZSpecial(&ironBall->mFollower, &ironBall->field11C, &ironBall->field0.field10);
        ironBall->field11C.y += 0x1000;
    }
    VEC_MultAdd(ironBall->field0.mExtent.x, &ironBall->field0.mMatrix.field0[1], &ironBall->field11C,
                &ironBall->field0.mPos);
    ironBall->field0.mPos.y = ironBall->field0.mPos.y + ironBall->mHeightOffset;
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
    if (ironBall->field12C == 2) {
        oshd_setParams(&ironBall->mShadowMatrix, &ironBall->field11C, ironBall->field0.mExtent.x << 1, 0x1c);
        ironBall->field11C.y += 0x1000;
        ironBall->field12C = 1;
    }
    if (ironBall->field12C != 0) {
        if (((s32) ironBall->field0.mDistanceSquaredAndFlags & 0x3fffffe0) < 1000000) {
            w = (ironBall->mHeightOffset >> 14) - 7;
            if (w < 0) {
                v = 0x1c;
            } else if (w < 0x1c) {
                v = 0x1c - w;
            } else {
                v = 0;
            }
            ironBall->mShadowMatrix.field30 = v;
            oshd_setPosition(&ironBall->mShadowMatrix, &ironBall->field11C);
        }
        ironBall->field0.mFlags &= ~1;
    } else {
        ironBall->field0.mFlags |= data_021567ec;
    }
}

void ibal_setupConfig(void) {
    MapObjectKindData *mapObjectKindData;

    mapObjectKindData = mobj_createConfig(ibal_onDriverCollide, NULL, NULL, 1, 1);
    mapObjectKindData->field38 = 0x190000;
    mapObjectKindData->field3C = -0x1f4000;
}

void *ibal_setupShadowRenderPart(void) {
    return mobj_createRenderPart3d(ibal_globalInitShadow, ibal_renderShadow, NULL);
}

void *ibal_setupBallRenderPart(void) {
    return mobj_createRenderPart2d(iball_loadBallModel, iball_renderBall, iball_applyBallMaterial);
}

void *ibal_setupLogicPart(void) {
    return mobj_createLogicPart(ibal_globalLogicInit, ibal_update, NULL);
}

void mobj0008_20A8ED8(Unk020a826c_a0 *soundPart, Vec3 *position) {
    s32 k;
    Camera *currentCamera;
    s32 v;
    s32 n;
    s32 x;
    s32 m;

    currentCamera = race_getCamera();
    switch (gRaceMultiConfig->mCourseId) {
        case COURSE_ID_CROSS:
            if (rstat_isDriverInFinalLap(gRaceMultiConfig->mEntryIndex) != FALSE || race_isCamAnimMode() != 0) {
                k = 0x898000;
            } else {
                k = 0x834000;
            }
            v = FX_Atan2Idx(currentCamera->mPos.x - position->x, currentCamera->mPos.z - position->z);
            if (v >= 0 && v <= 0xaaab) {
                n = ((u16) v >> 4) << 1;
                soundPart->mSourcePos.x = position->x + (s32) (((s64) FX_SinCosTable_[n] * 0x5dc000) >> 12);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + (s32) (((s64) FX_SinCosTable_[n + 1] * 0x5dc000) >> 12);
                soundPart->field20 = FALSE;
            } else if (currentCamera->mPos.z > position->z && currentCamera->mPos.y < position->y - 0x32000) {
                soundPart->mSourcePos.x = position->x + (s32) (((s64) FX_SinCosTable_[0] * 0x5dc000) >> 12);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + (s32) (((s64) FX_SinCosTable_[1] * 0x5dc000) >> 12);
                v = soundPart->mSourcePos.x - k;
                n = currentCamera->mPos.x;
                if (n <= v) {
                    n = v;
                }
                soundPart->mSourcePos.x = n;
                soundPart->field20 = TRUE;
            } else {
                soundPart->mSourcePos.x = position->x + (s32) (((s64) data_0215feb4[0x54] * 0x5dc000) >> 12);
                soundPart->mSourcePos.y = position->y;
                soundPart->mSourcePos.z = position->z + (s32) (((s64) data_0215feb4[0x55] * 0x5dc000) >> 12);
                soundPart->field20 = FALSE;
            }
            break;
        case COURSE_ID_MARIO:
            if (rstat_isDriverInFinalLap(gRaceMultiConfig->mEntryIndex) != FALSE || race_isCamAnimMode() != 0) {
                m = 0x384000;
            } else {
                m = 0x320000;
            }
            x = position->x - m;
            if (x <= currentCamera->mPos.x) {
                x = position->x + m;
                if (x >= currentCamera->mPos.x) {
                    x = currentCamera->mPos.x;
                }
            }
            soundPart->mSourcePos.x = x;
            soundPart->mSourcePos.y = position->y;
            soundPart->mSourcePos.z = position->z;
            if (currentCamera->mPos.x < position->x) {
                soundPart->field20 = TRUE;
            } else {
                soundPart->field20 = FALSE;
            }
            break;
    }
}
