#include "Main/Unknown/code_0209bf70.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bc5c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209d5e8.h"
#include "Main/Unknown/code_0209d5ec.h"
#include "Main/Unknown/code_0209d694.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_0209d650.h"
#include "Main/Unknown/code_02077bc0.h"

void InitSun(Sun *sun) {
    InitGroupFollower(&sun->mUnk_0b8, sun->mMapObject.mCourseMapRow, 0);
    CreateParkedMapObjects(MAP_OBJECT_KIND_SUN_FIREBALL, 0x1e, sun);
    sun->mMapObject.mPosStep.x = 0;
    sun->mMapObject.mPosStep.y = 0;
    sun->mMapObject.mPosStep.z = 0;
}

void CreateSunAndSunLOD(void *a) {
    gSun = CreateMapObjectModelAnimated(a, gSunNsbmdName);
    CreateMapObjectModelNsbcaAnimation(gSun, gSunNsbcaName);
    gSunLOD = CreateMapObjectModelAnimated(a, gSunLODNsbmdName);
    SetMapObjectModelPolygonId(gSun, AllocPolygonId());
}

u32 SunSetupDrawReturnArgument(u32 value) {
    return value;
}

void DrawSun(void *a, Unk0209d3fc *b) {
    s32 s;
    s32 t;
    s32 k;
    Vec3 v;

    s = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &s, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&b->mMapObject.mPos), 0xc);
    if (b->mState == 3 || b->mState == 4) {
        t = MUL_FIXED12_NO_ROUND(FX_CosIdx((u16) b->mUnk_ac), -0x14000) + 0x14000;
        k = (b->mUnk_b0 >> 4) * 2;
        v.x = MUL_FIXED12_NO_ROUND(t, FX_SinCosTable_[k + 1]) >> 4;
        v.y = MUL_FIXED12_NO_ROUND(t, FX_SinCosTable_[k]) >> 4;
        v.z = 0;
        NNS_G3dGeBufferOP_N(0x1c, &v, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &b->mMapObject.mScale, 3);
    if (GetCurrentCameraKind() == 2) {
        QueueMapObjectModelMaterial(a, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, b->mNsbcaFrameIndex);
        DrawMapObjectModel(a, gSun, b);
    } else if ((s32) (b->mMapObject.mDistanceSquaredAndFlags & 0x3fffffe0) < 0x3d0900) {
        QueueMapObjectModelMaterial(a, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, b->mNsbcaFrameIndex);
        DrawMapObjectModel(a, gSun, b);
    } else {
        QueueMapObjectModelMaterial(a, gSunLOD);
        DrawMapObjectModel1Mat1Shp(a, gSunLOD, b);
    }
}

static inline u32 CollideKartWithBound_inline(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return randomState64->mValue >> 32;
}

void InitSunObjects(MapObjectList *mapObjectList) {
    s32 i;
    Sun *sun;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (sun = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
            sun->mTimer = (u16) sun->mMapObject.mCourseMapRow->mUnk_28;
        } else if (gRaceSetup->mMode == 5) {
            sun->mTimer = (u16) sun->mMapObject.mCourseMapRow->mUnk_2a;
        }
    }
}

static inline BOOL UpdateSun_inline(void) {
    s32 i;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        if ((s32) GetKartHighestLap((u16) i) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL UpdateSun_inline_b(Sun *sun) {
    s32 i;
    Kart *kart;
    Vec3 *q;
    s32 x;
    s32 z;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        kart = GetKart((u16) i);
        q = &kart->mPos;
        x = q->x - sun->mMapObject.mPos.x;
        z = q->z - sun->mMapObject.mPos.z;
        if ((s64) x * x + (s64) z * z < 0x15f900000000LL) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateSun(MapObjectList *mapObjectList, Sun *sun) {
    Vec3 position;
    Vec3 direction;
    s32 t;
    s32 k;

    switch (sun->mState) {
        case 0:
            if (sun->mMapObject.mFlags & 0x800) {
                if (sun->mTimer-- <= 0) {
                    sun->mState = 1;
                }
            } else if (UpdateSun_inline()) {
                sun->mState = 1;
            }
            break;
        case 1:
            sun->mUnk_0b8.mSpeed = 0x3c000;
            sun->mUnk_0b8.mProgressStep = MUL_FIXED12_NO_ROUND(
                sun->mUnk_0b8.mPath->mSegments[sun->mUnk_0b8.mSegmentIndex].mInverseProgressLength, 0x3c000);
            if (AdvanceGroupFollower(&sun->mUnk_0b8) != FALSE && (t = sun->mUnk_0b8.mFromEntry->mUnk_0e) != 0) {
                if (sun->mMapObject.mFlags & 0x800) {
                    k = gRaceSetup->mMode;
                    if (k == MODE_TIME_ATTACK) {
                        sun->mTimer = t;
                    } else if (k == 5) {
                        sun->mTimer = sun->mUnk_0b8.mFromEntry->mUnk_10;
                    }
                }
                sun->mState = 2;
            }
            GetGroupFollowerLinearPosition(&sun->mUnk_0b8, &sun->mMapObject.mPos);
            break;
        case 2:
            if (sun->mMapObject.mFlags & 0x800) {
                if (sun->mTimer-- <= 0) {
                    sun->mUnk_0b0 = 0;
                    sun->mUnk_0ac = sun->mUnk_0b0;
                    sun->mTimer = 5;
                    sun->mState = 3;
                }
            } else if (UpdateSun_inline_b(sun)) {
                sun->mUnk_0b0 = 0;
                sun->mUnk_0ac = sun->mUnk_0b0;
                sun->mTimer = 5;
                sun->mState = 3;
            }
            break;
        case 3:
            sun->mUnk_0b0 += 0xe39;
            if (sun->mUnk_0ac < 0x8000) {
                sun->mUnk_0ac += 0x222;
            }
            if (sun->mTimer-- > 0) {
                break;
            }
            if (sun->mUnk_0a0 == 0) {
                sun->mUnk_0a4 = ((u64) CollideKartWithBound_inline(GetMapObjectRandom()) * 0x10000) >> 32;
            } else {
                sun->mUnk_0a4 += 0x8000;
            }
            position.x = sun->mMapObject.mPos.x;
            position.y = sun->mMapObject.mPos.y - 0x1e000;
            position.z = sun->mMapObject.mPos.z;
            direction.x = FX_SinIdx(sun->mUnk_0a4);
            direction.y = 0;
            direction.z = FX_CosIdx(sun->mUnk_0a4);
            StartSunFireball(&position, &direction);
            sun->mUnk_0a0 += 1;
            if (sun->mUnk_0a0 >= 2) {
                sun->mUnk_0a0 = 0;
                sun->mState = 4;
            } else {
                sun->mTimer = 0x1e;
            }
            break;
        case 4:
            sun->mUnk_0b0 += 0xe39;
            sun->mUnk_0ac += 0x222;
            if (sun->mUnk_0ac > 0x10000) {
                sun->mTimer = 0x1e;
                sun->mState = 0;
            }
            break;
    }
    if ((s32) (sun->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) >= 0x3d0900) {
        return;
    }
    if (sun->mState == 3) {
        t = sun->mNsbcaFrameIndexPerFrame + 0x19a;
        if (t >= 0x8000) {
            t = 0x8000;
        }
        sun->mNsbcaFrameIndexPerFrame = t;
    } else {
        t = sun->mNsbcaFrameIndexPerFrame - 0x19a;
        if (t <= 0x1000) {
            t = 0x1000;
        }
        sun->mNsbcaFrameIndexPerFrame = t;
    }
    sun->mNsbcaFrameIndex += sun->mNsbcaFrameIndexPerFrame >> 12;
    if (sun->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gSun)) {
        sun->mNsbcaFrameIndex = 0;
    }
}

void CreateSunDrawList(void) {
    CreateMapObjectDrawList1(CreateSunAndSunLOD, DrawSun, SunSetupDrawReturnArgument);
}

void CreateSunUpdateList(void) {
    CreateMapObjectUpdateList(InitSunObjects, UpdateSun, NULL);
}

void InitBound(Bound *bound) {
    bound->mMapObject.mFlags |= data_usa_021565d4;
    RefreshMapObjectMatrixFromHitNormal(&bound->mMapObject);
    bound->mInitialScaleX = bound->mMapObject.mScale.x;
}

// Shared by Bound, Cream and Berry: sets the object's motion from the Kart, starts the wobble and plays a sound.
s32 CollideKartWithBound(Bound *bound, Kart *kart, u8 *b, u8 *c) {
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 *q;
    u8 d;
    s32 t;
    u32 e;

    e = *b;
    d = *c;
    if (e == 3 || e == 4) {
        if (bound->mKartTimers[kart->mIndex] == 0) {
            VEC_Subtract(&kart->mPos, &bound->mMapObject.mPos, &v2);
            t = VEC_DotProduct(&kart->mVelocityDirection, &v2);
            v0.x = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.x, t);
            v0.y = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.y, t);
            v0.z = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.z, t);
            v1.x = v2.x - v0.x;
            v1.y = v2.y - v0.y;
            v1.z = v2.z - v0.z;
            t = VEC_DotProduct(&bound->mMapObject.mMatrix.mRows[1], &v1);
            v0.x = MUL_FIXED12_NO_ROUND(bound->mMapObject.mMatrix.mRows[1].x, t);
            v0.y = MUL_FIXED12_NO_ROUND(bound->mMapObject.mMatrix.mRows[1].y, t);
            v0.z = MUL_FIXED12_NO_ROUND(bound->mMapObject.mMatrix.mRows[1].z, t);
            v1.x -= v0.x;
            v1.y -= v0.y;
            v1.z -= v0.z;
            if (LENGTH_SQUARED(v1) < 0x10) {
                q = &kart->mUnk_120;
                bound->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(kart->mUnk_120.x, 0xc000);
                bound->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(q->y, 0xc000);
                bound->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(q->z, 0xc000);
            } else {
                Vec3NormalizeAndGetLengthUnchecked(&v1, &v1);
                bound->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(v1.x, 0xc000);
                bound->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(v1.y, 0xc000);
                bound->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(v1.z, 0xc000);
            }
            VEC_Subtract(&v0, &bound->mMapObject.mMatrix.mRows[1], &v0);
            VEC_MultAdd(0x19a, &v0, &bound->mMapObject.mPosStep, &bound->mMapObject.mPosStep);
            bound->mKartTimers[kart->mIndex] = 0x1f;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                CallStandingsKartOffsetCallback(kart->mIndex, &bound->mMapObject.mPosStep);
            }
        } else {
            bound->mMapObject.mPosStep.x = 0;
            bound->mMapObject.mPosStep.y = 0;
            bound->mMapObject.mPosStep.z = 0;
        }
        if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_GHOST && bound->mWobbling == FALSE) {
            bound->mWobbleXAngle = 0x8000;
            bound->mWobbleXMid = 0x1000;
            bound->mWobbleXAmplitude = 0x400;
            bound->mWobbleXAmplitudePerFrame = -0x29;
            bound->mWobbleXAnglePerFrame = 0x1000;
            bound->mUnk_0d4 = 0;
            bound->mWobbleYAngle = 0;
            bound->mWobbleYMid = 0x1000;
            bound->mWobbleYAmplitude = 0x400;
            bound->mWobbleYAmplitudePerFrame = -0x29;
            bound->mWobbleYAnglePerFrame = 0x1000;
            bound->mUnk_0f4 = 0;
            bound->mWobbling = TRUE;
            switch (bound->mMapObject.mKind) {
                case MAP_OBJECT_KIND_CREAM:
                    StartSoundFullVolumeWrapper(kart, 0x156);
                    break;
                case MAP_OBJECT_KIND_BERRY:
                    StartSoundFullVolumeWrapper(kart, 0x155);
                    break;
                case 0x1a8:
                    StartSoundFullVolumeWrapper(kart, 0x1cf);
                    break;
            }
            if ((u16) (bound->mMapObject.mKind + 0xfe4c) <= 1) {
                StartOrthoQuadsCreamEffect(
                    kart->mIndex,
                    (u16) (((u64) CollideKartWithBound_inline(&gRaceProgress->mLocalRandom) * 3) >> 32) + 1);
                VEC_Subtract(&bound->mMapObject.mPos, &kart->mCollisionCenter, &v3);
                if (!(LENGTH_SQUARED(v3) < 0x10)) {
                    Vec3NormalizeAndGetLengthUnchecked(&v3, &v3);
                }
                VEC_MultAdd(kart->mRadius, &v3, &kart->mCollisionCenter, &v3);
                if (kart->mIndex == gRaceSetup->mEntryIndex) {
                    StartEffect(0x74, &v3);
                } else {
                    StartEffect(0x75, &v3);
                }
            }
        }
        return d;
    }
    bound->mMapObject.mPosStep.x = 0;
    bound->mMapObject.mPosStep.y = 0;
    bound->mMapObject.mPosStep.z = 0;
    return 2;
}

// Shared by Bound, Cream and Berry: when *b is 2, starts a smaller wobble; returns *c.
u8 CollideItemObjectWithBound(Bound *bound, void *a, u8 *b, u8 *c) {
    u32 d;

    d = *c;
    if (*b == 2 && bound->mWobbling == FALSE) {
        bound->mWobbleXAngle = 0x8000;
        bound->mWobbleXMid = 0x1000;
        bound->mWobbleXAmplitude = 0x200;
        bound->mWobbleXAmplitudePerFrame = -0x14;
        bound->mWobbleXAnglePerFrame = 0x1000;
        bound->mUnk_0d4 = 0;
        bound->mWobbleYAngle = 0;
        bound->mWobbleYMid = 0x1000;
        bound->mWobbleYAmplitude = 0x200;
        bound->mWobbleYAmplitudePerFrame = -0x14;
        bound->mWobbleYAnglePerFrame = 0x1000;
        bound->mUnk_0f4 = 0;
        bound->mWobbling = TRUE;
        bound->mMapObject.mDistanceSquaredAndFlags |= data_usa_021565d0;
    }
    return d;
}

BOOL ComputeSphereHitOnBound(Bound *bound, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *pushOut) {
    if ((bound->mMapObject.mFlags & 0x800) == 0 && bound->mWobbling == TRUE) {
        bound->mSphereHit = ComputeSphereHitOnRotatedCylinder(
            sphereCenter, &bound->mMapObject.mPos, &bound->mMapObject.mMatrix.mRows[0],
            MUL_FIXED12_NO_ROUND(bound->mMapObject.mExtent.x, bound->mWobbleScaleX), bound->mMapObject.mExtent.y, 0,
            sphereRadius, pushOut);
    } else {
        bound->mSphereHit = ComputeSphereHitOnRotatedCylinder(
            sphereCenter, &bound->mMapObject.mPos, &bound->mMapObject.mMatrix.mRows[0], bound->mMapObject.mExtent.x,
            bound->mMapObject.mExtent.y, 0, sphereRadius, pushOut);
    }
    return bound->mSphereHit != 0;
}

void CreateBound(void *a) {
    gBound = CreateMapObjectModelAnimated(a, gBoundNsbmdName);
    CreateMapObjectModelNsbtpAnimation(gBound, gBoundNsbtpName);
}

void DrawBound(MapObjectList *mapObjectList, Bound *bound) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v[0], 1);
    bound->mMapObject.mMatrix.mRows[3].x = bound->mMapObject.mPos.x >> 4;
    bound->mMapObject.mMatrix.mRows[3].y = bound->mMapObject.mPos.y >> 4;
    bound->mMapObject.mMatrix.mRows[3].z = bound->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bound->mMapObject.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        x = bound->mWobbleScaleX;
        y = bound->mWobbleScaleY;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        NNS_G3dGeBufferOP_N(0x1b, &v[1], 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bound->mMapObject.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gBound, bound->mNsbtpFrameIndex);
    DrawMapObjectModel(mapObjectList, gBound, bound);
}

void CreateCream(void *a) {
    gCream = CreateMapObjectModelAnimated(a, gCreamNsbmdName);
    CreateOrthoQuadCreamEffect(data_usa_02167328);
}

void CreateBerry(void *a) {
    gBerry = CreateMapObjectModelAnimated(a, gBerryNsbmdName);
    CreateOrthoQuadCreamEffect(gCreamEffectNsbmdName);
}

void DrawCream(MapObjectList *mapObjectList, Bound *bound) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v[0], 1);
    bound->mMapObject.mMatrix.mRows[3].x = bound->mMapObject.mPos.x >> 4;
    bound->mMapObject.mMatrix.mRows[3].y = bound->mMapObject.mPos.y >> 4;
    bound->mMapObject.mMatrix.mRows[3].z = bound->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bound->mMapObject.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        x = bound->mWobbleScaleX;
        y = bound->mWobbleScaleY;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        NNS_G3dGeBufferOP_N(0x1b, &v[1], 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bound->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gCream, bound);
}

void DrawBerry(MapObjectList *mapObjectList, Bound *bound) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v[0], 1);
    bound->mMapObject.mMatrix.mRows[3].x = bound->mMapObject.mPos.x >> 4;
    bound->mMapObject.mMatrix.mRows[3].y = bound->mMapObject.mPos.y >> 4;
    bound->mMapObject.mMatrix.mRows[3].z = bound->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bound->mMapObject.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        x = bound->mWobbleScaleX;
        y = bound->mWobbleScaleY;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        NNS_G3dGeBufferOP_N(0x1b, &v[1], 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bound->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gBerry, bound);
}

void InitBoundAndCreamAndBerryObjects(MapObjectList *mapObjectList) {
    s32 i;
    Bound *bound;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (bound = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (bound->mMapObject.mCourseMapRow->mUnk_26 >= 0) {
            InitGroupFollower(&bound->mUnk_0f8, bound->mMapObject.mCourseMapRow, 0);
            bound->mUnk_0f8.mSpeed = 0x3000;
            bound->mUnk_0f8.mProgressStep = MUL_FIXED12_NO_ROUND(
                bound->mUnk_0f8.mPath->mSegments[bound->mUnk_0f8.mSegmentIndex].mInverseProgressLength, 0x3000);
        } else {
            bound->mUnk_0f8.mGroupIndex = 0xffff;
        }
    }
}

s16 BoundFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 BoundFX_MulInline(s32 a, s32 b) {
    return MUL_FIXED12_ROUNDED(a, b);
}

void UpdateBoundAndCreamAndBerry(MapObjectList *mapObjectList, Bound *bound) {
    u16 nsbtpFrameCount;
    s32 t;
    s32 i;
    s32 kartCount;

    if (bound->mUnk_0f8.mGroupIndex != 0xffff) {
        AdvanceGroupFollower(&bound->mUnk_0f8);
        GetGroupFollowerCurvePosStep(&bound->mUnk_0f8, &bound->mMapObject.mPos, &bound->mMapObject.mPosStep);
        nsbtpFrameCount = GetMapObjectModelNsbtpFrameCount(gBound);
        bound->mNsbtpFrameIndex += 1;
        if (bound->mNsbtpFrameIndex >= nsbtpFrameCount) {
            bound->mNsbtpFrameIndex = 1;
        }
    } else {
        bound->mMapObject.mPosStep.x = 0;
        bound->mMapObject.mPosStep.y = 0;
        bound->mMapObject.mPosStep.z = 0;
        bound->mNsbtpFrameIndex = 0;
    }
    if (bound->mWobbling == TRUE) {
        bound->mWobbleXAngle += bound->mWobbleXAnglePerFrame;
        t = BoundFX_MulInline(bound->mWobbleXAmplitude, BoundFX_SinIdx(bound->mWobbleXAngle));
        bound->mUnk_0c0 = bound->mWobbleXMid + t - bound->mWobbleScaleX;
        bound->mWobbleScaleX += bound->mUnk_0c0;
        if (bound->mWobbleXAmplitude > 0) {
            t = bound->mWobbleXAmplitude + bound->mWobbleXAmplitudePerFrame;
            if (t <= 0) {
                t = 0;
            }
            bound->mWobbleXAmplitude = t;
        } else if (bound->mWobbleXAmplitude < 0) {
            t = bound->mWobbleXAmplitude + bound->mWobbleXAmplitudePerFrame;
            if (t >= 0) {
                t = 0;
            }
            bound->mWobbleXAmplitude = t;
        }
        if (bound->mWobbleXAnglePerFrame > 0) {
            t = bound->mWobbleXAnglePerFrame + bound->mUnk_0d4;
            if (t <= 0) {
                t = 0;
            }
            bound->mWobbleXAnglePerFrame = t;
        } else if (bound->mWobbleXAnglePerFrame < 0) {
            t = bound->mWobbleXAnglePerFrame + bound->mUnk_0d4;
            if (t >= 0) {
                t = 0;
            }
            bound->mWobbleXAnglePerFrame = t;
        }
        bound->mWobbleYAngle += bound->mWobbleYAnglePerFrame;
        t = BoundFX_MulInline(bound->mWobbleYAmplitude, BoundFX_SinIdx(bound->mWobbleYAngle));
        bound->mUnk_0e0 = bound->mWobbleYMid + t - bound->mWobbleScaleY;
        bound->mWobbleScaleY += bound->mUnk_0e0;
        if (bound->mWobbleYAmplitude > 0) {
            t = bound->mWobbleYAmplitude + bound->mWobbleYAmplitudePerFrame;
            if (t <= 0) {
                t = 0;
            }
            bound->mWobbleYAmplitude = t;
        } else if (bound->mWobbleYAmplitude < 0) {
            t = bound->mWobbleYAmplitude + bound->mWobbleYAmplitudePerFrame;
            if (t >= 0) {
                t = 0;
            }
            bound->mWobbleYAmplitude = t;
        }
        if (bound->mWobbleYAnglePerFrame > 0) {
            t = bound->mWobbleYAnglePerFrame + bound->mUnk_0f4;
            if (t <= 0) {
                t = 0;
            }
            bound->mWobbleYAnglePerFrame = t;
        } else if (bound->mWobbleYAnglePerFrame < 0) {
            t = bound->mWobbleYAnglePerFrame + bound->mUnk_0f4;
            if (t >= 0) {
                t = 0;
            }
            bound->mWobbleYAnglePerFrame = t;
        }
        if (bound->mWobbleXAmplitude == 0 && bound->mWobbleYAmplitude == 0) {
            bound->mWobbling = FALSE;
            bound->mMapObject.mScale.x = bound->mInitialScaleX;
        } else {
            bound->mMapObject.mScale.x = MUL_FIXED12_NO_ROUND(bound->mInitialScaleX, bound->mWobbleScaleX);
        }
    } else {
        bound->mMapObject.mScale.x = bound->mInitialScaleX;
    }
    kartCount = gRaceSetup->mKartCount;
    for (i = 0; i < kartCount; i++) {
        if (bound->mKartTimers[i] > 0) {
            bound->mKartTimers[i] -= 1;
        }
    }
}

void CreateBoundKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mCollideItemObjectSoundId = 0x1cf;
}

void CreateCreamKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mCollideItemObjectSoundId = 0x156;
}

void CreateBerryKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mCollideItemObjectSoundId = 0x155;
}

void CreateBoundDrawList(void) {
    CreateMapObjectDrawList1(CreateBound, DrawBound, NULL);
}

void CreateCreamDrawList(void) {
    CreateMapObjectDrawList1(CreateCream, DrawCream, NULL);
}

void CreateBerryDrawList(void) {
    CreateMapObjectDrawList1(CreateBerry, DrawBerry, NULL);
}

void CreateBoundUpdateList(void) {
    CreateMapObjectUpdateList(InitBoundAndCreamAndBerryObjects, UpdateBoundAndCreamAndBerry, NULL);
}

// Starts the wobble of object a of the 0x1a8 list, with a sound unless the object is far; FALSE if already wobbling.
BOOL StartBoundWobble(s32 a) {
    Bound *bound;
    SoundStartParams s;
    s32 k;

    bound = GetMapObjectFromList(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BOUND), a);
    if (bound->mWobbling == FALSE) {
        bound->mWobbleXAngle = 0x8000;
        bound->mWobbleXMid = 0x1000;
        bound->mWobbleXAmplitude = 0x400;
        bound->mWobbleXAmplitudePerFrame = -0x29;
        bound->mWobbleXAnglePerFrame = 0x1000;
        bound->mUnk_0d4 = 0;
        bound->mWobbleYAngle = 0;
        bound->mWobbleYMid = 0x1000;
        bound->mWobbleYAmplitude = 0x400;
        bound->mWobbleYAmplitudePerFrame = -0x29;
        bound->mWobbleYAnglePerFrame = 0x1000;
        bound->mUnk_0f4 = 0;
        bound->mWobbling = TRUE;
        if ((bound->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
            if (bound->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                k = 2;
            } else if (bound->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s.mSoundId = 0x1cf;
            s.mPositionSource = &bound->mMapObject.mPos;
            s.mFalloffIndex = k;
            s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bound->mMapObject.mPos);
            StartSoundFromParams(&s);
        }
        return TRUE;
    }
    return FALSE;
}

#pragma thumb on

void *CreateMapObjectKindData(void *collideKartCallback, void *collideItemObjectCallback, void *sphereHitCallback,
                              u32 param_4, u16 param_5) {
    MapObjectKindData *kindData;

    GetHeap(GetCurrentHeapCall());
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    kindData->mCollideKartCallback = collideKartCallback;
    kindData->mCollideItemObjectCallback = collideItemObjectCallback;
    kindData->mUnk_20 = param_4;
    kindData->mUnk_1c = param_5;
    kindData->mSphereHitTest = sphereHitCallback;
    return kindData;
}

MapObjectKindData *CreateEmptyMapObjectKindData(void) {
    return CreateMapObjectKindData(NULL, NULL, NULL, 0, 1);
}

MapObjectKindData *CreateMapObjectKindDataWithSound(void *collideKartCallback, void *collideItemObjectCallback,
                                                    void *sphereHitCallback, u32 d, u16 e, u16 f) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(collideKartCallback, collideItemObjectCallback, sphereHitCallback, d, e);
    kindData->mSoundId = f;
    return kindData;
}
