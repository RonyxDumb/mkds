#include "Main/MapObjects/bound.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bc5c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209d5e8.h"
#include "Main/Unknown/code_0209d5ec.h"
#include "Main/MapObjects/sun_fireball.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Item/item_link_following.h"
#include "Main/Item/bouncing_item_box.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_0209d650.h"
#include "Main/Kart/karts.h"

void InitSun(Sun *sun) {
    InitGroupFollower(&sun->mUnk_0b8, sun->mMapObject.mCourseMapRow, 0);
    CreateParkedMapObjects(MAP_OBJECT_KIND_SUN_FIREBALL, 0x1e, sun);
    sun->mMapObject.mPosStep.x = 0;
    sun->mMapObject.mPosStep.y = 0;
    sun->mMapObject.mPosStep.z = 0;
}

void CreateSunAndSunLOD(void *mapObjectList) {
    gSun = CreateMapObjectModelAnimated(mapObjectList, gSunNsbmdName);
    CreateMapObjectModelNsbcaAnimation(gSun, gSunNsbcaName);
    gSunLOD = CreateMapObjectModelAnimated(mapObjectList, gSunLODNsbmdName);
    SetMapObjectModelPolygonId(gSun, AllocPolygonId());
}

u32 SunSetupDrawReturnArgument(u32 value) {
    return value;
}

void DrawSun(void *mapObjectList, Sun *sun) {
    s32 gxParam;
    s32 radius;
    s32 angleIndex;
    Vec3 translation;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&sun->mMapObject.mPos), 0xc);
    if (sun->mState == 3 || sun->mState == 4) {
        radius = MUL_FIXED12_NO_ROUND(FX_CosIdx((u16) sun->mUnk_0ac), -0x14000) + 0x14000;
        angleIndex = (sun->mUnk_0b0 >> 4) * 2;
        translation.x = MUL_FIXED12_NO_ROUND(radius, FX_SinCosTable_[angleIndex + 1]) >> 4;
        translation.y = MUL_FIXED12_NO_ROUND(radius, FX_SinCosTable_[angleIndex]) >> 4;
        translation.z = 0;
        NNS_G3dGeBufferOP_N(0x1c, &translation, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &sun->mMapObject.mScale, 3);
    if (GetCurrentCameraKind() == 2) {
        QueueMapObjectModelMaterial(mapObjectList, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, sun->mNsbcaFrameIndex);
        DrawMapObjectModel(mapObjectList, gSun, sun);
    } else if ((s32) (sun->mMapObject.mDistanceSquaredAndFlags & 0x3fffffe0) < 0x3d0900) {
        QueueMapObjectModelMaterial(mapObjectList, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, sun->mNsbcaFrameIndex);
        DrawMapObjectModel(mapObjectList, gSun, sun);
    } else {
        QueueMapObjectModelMaterial(mapObjectList, gSunLOD);
        DrawMapObjectModel1Mat1Shp(mapObjectList, gSunLOD, sun);
    }
}

static inline u32 CollideKartWithBound_inline(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return randomState64->mValue >> 32;
}

void InitSunObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    Sun *sun;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0;
         mapObjectIndex < mapObjectList->mMapObjectCount && (sun = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
            sun->mTimer = (u16) sun->mMapObject.mCourseMapRow->mSettings[0];
        } else if (gRaceSetup->mMode == MODE_WIFI) {
            sun->mTimer = (u16) sun->mMapObject.mCourseMapRow->mSettings[1];
        }
    }
}

static inline BOOL UpdateSun_inline(void) {
    s32 kartIndex;

    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        if ((s32) GetKartHighestLap((u16) kartIndex) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL UpdateSun_inline_b(Sun *sun) {
    s32 kartIndex;
    Kart *kart;
    Vec3 *kartPos;
    s32 deltaX;
    s32 deltaZ;

    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        kart = GetKart((u16) kartIndex);
        kartPos = &kart->mPos;
        deltaX = kartPos->x - sun->mMapObject.mPos.x;
        deltaZ = kartPos->z - sun->mMapObject.mPos.z;
        if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ < 0x15f900000000LL) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateSun(MapObjectList *mapObjectList, Sun *sun) {
    Vec3 position;
    Vec3 direction;
    s32 value;
    s32 mode;

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
            if (AdvanceGroupFollower(&sun->mUnk_0b8) != FALSE && (value = sun->mUnk_0b8.mFromEntry->mUnk_0e) != 0) {
                if (sun->mMapObject.mFlags & 0x800) {
                    mode = gRaceSetup->mMode;
                    if (mode == MODE_TIME_ATTACK) {
                        sun->mTimer = value;
                    } else if (mode == 5) {
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
        value = sun->mNsbcaFrameIndexPerFrame + 0x19a;
        if (value >= 0x8000) {
            value = 0x8000;
        }
        sun->mNsbcaFrameIndexPerFrame = value;
    } else {
        value = sun->mNsbcaFrameIndexPerFrame - 0x19a;
        if (value <= 0x1000) {
            value = 0x1000;
        }
        sun->mNsbcaFrameIndexPerFrame = value;
    }
    sun->mNsbcaFrameIndex += FROM_FIXED12(sun->mNsbcaFrameIndexPerFrame);
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
