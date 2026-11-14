#include "Main/MapObjects/bound.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/sun.h"
#include "Main/MapObjects/sun_fireball.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/System/heap_call.h"
#include "Main/Kart/code_0207a000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Item/item_link_following.h"
#include "Main/Item/bouncing_item_box.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_0217b000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Kart/karts.h"

MapObjectModel *gSun;
MapObjectModel *gSunLOD;

MapObjectKindDescriptor gSunKindDescriptor = {0,
                                             {0, 0},
                                             0xe0,
                                             InitSun,
                                             CreateEmptyMapObjectKindData,
                                             CreateSunDrawList,
                                             0,
                                             0,
                                             CreateSunUpdateList};

void InitSun(Sun *sun) {
    InitGroupFollower(&sun->mFollower, sun->mMapObject.mCourseMapRow, 0);
    CreateParkedMapObjects(MAP_OBJECT_KIND_SUN_FIREBALL, 0x1e, sun);
    sun->mMapObject.mPosStep.x = 0;
    sun->mMapObject.mPosStep.y = 0;
    sun->mMapObject.mPosStep.z = 0;
}

void CreateSunAndSunLOD(void *mapObjectList) {
    gSun = CreateMapObjectModelAnimated(mapObjectList, "sun.nsbmd");
    CreateMapObjectModelNsbcaAnimation(gSun, "sun.nsbca");
    gSunLOD = CreateMapObjectModelAnimated(mapObjectList, "sun_LOD.nsbmd");
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
        radius = MUL_FIXED12_NO_ROUND(FX_CosIdx((u16) sun->mDrawOffsetRadiusAngle), -0x14000) + 0x14000;
        angleIndex = (sun->mDrawOffsetAngle >> 4) * 2;
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
            sun->mFollower.mSpeed = 0x3c000;
            sun->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                sun->mFollower.mPath->mSegments[sun->mFollower.mSegmentIndex].mInverseProgressLength, 0x3c000);
            if (AdvanceGroupFollower(&sun->mFollower) != FALSE && (value = sun->mFollower.mFromEntry->mUnk_0e) != 0) {
                if (sun->mMapObject.mFlags & 0x800) {
                    mode = gRaceSetup->mMode;
                    if (mode == MODE_TIME_ATTACK) {
                        sun->mTimer = value;
                    } else if (mode == 5) {
                        sun->mTimer = sun->mFollower.mFromEntry->mUnk_10;
                    }
                }
                sun->mState = 2;
            }
            GetGroupFollowerLinearPosition(&sun->mFollower, &sun->mMapObject.mPos);
            break;
        case 2:
            if (sun->mMapObject.mFlags & 0x800) {
                if (sun->mTimer-- <= 0) {
                    sun->mDrawOffsetAngle = 0;
                    sun->mDrawOffsetRadiusAngle = sun->mDrawOffsetAngle;
                    sun->mTimer = 5;
                    sun->mState = 3;
                }
            } else if (UpdateSun_inline_b(sun)) {
                sun->mDrawOffsetAngle = 0;
                sun->mDrawOffsetRadiusAngle = sun->mDrawOffsetAngle;
                sun->mTimer = 5;
                sun->mState = 3;
            }
            break;
        case 3:
            sun->mDrawOffsetAngle += 0xe39;
            if (sun->mDrawOffsetRadiusAngle < 0x8000) {
                sun->mDrawOffsetRadiusAngle += 0x222;
            }
            if (sun->mTimer-- > 0) {
                break;
            }
            if (sun->mFireballIndex == 0) {
                sun->mFireballAngle = ((u64) CollideKartWithBound_inline(GetMapObjectRandom()) * 0x10000) >> 32;
            } else {
                sun->mFireballAngle += 0x8000;
            }
            position.x = sun->mMapObject.mPos.x;
            position.y = sun->mMapObject.mPos.y - 0x1e000;
            position.z = sun->mMapObject.mPos.z;
            direction.x = FX_SinIdx(sun->mFireballAngle);
            direction.y = 0;
            direction.z = FX_CosIdx(sun->mFireballAngle);
            StartSunFireball(&position, &direction);
            sun->mFireballIndex += 1;
            if (sun->mFireballIndex >= 2) {
                sun->mFireballIndex = 0;
                sun->mState = 4;
            } else {
                sun->mTimer = 0x1e;
            }
            break;
        case 4:
            sun->mDrawOffsetAngle += 0xe39;
            sun->mDrawOffsetRadiusAngle += 0x222;
            if (sun->mDrawOffsetRadiusAngle > 0x10000) {
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

MapObjectList *CreateSunDrawList(void) {
    return CreateMapObjectDrawList1(CreateSunAndSunLOD, DrawSun, SunSetupDrawReturnArgument);
}

MapObjectList *CreateSunUpdateList(void) {
    return CreateMapObjectUpdateList(InitSunObjects, UpdateSun, NULL);
}
