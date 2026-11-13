#include "Main/MapObjects/view_frustum.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/mkd_ef_burner.h"
#include "Main/Race/race_start_sequence.h"

#include "Main/MapObjects/woodbox.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/data_020d2000.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/water.h"
#include "Main/MapObjects/rock.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "ITCM/collision_slots.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Kart/karts.h"
#include "Main/Race/race.h"
#include "Main/Graphics/light_color.h"
#include "Main/MapObjects/rotary.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/MapObjects/koopa_block.h"
#include "Main/System/heap_call.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_sources.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/earthen_pipe.h"
#include "Main/MapObjects/dossun_kind_descriptor.h"
#include "Main/MapObjects/wanwan_reset.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/MapObjects/wanwan_chain_object.h"
#include "Main/MapObjects/item_box_kind_descriptor.h"
#include "Main/MapObjects/mkd_ef_bubble_kind_descriptor.h"
#include "Main/MapObjects/group_item_box_kind_descriptor.h"
#include "Main/MapObjects/vehicle_kind_descriptor.h"
#include "Main/MapObjects/kart_balloons_kind_descriptor.h"
#include "Main/Sound/distance_sound_volume.h"
#include "Main/MapObjects/ob_pakkun_sf_kind_descriptor.h"
#include "Main/MapObjects/pendulum_kind_descriptor.h"
#include "Main/MapObjects/shine_battle.h"
#include "Main/Item/dram_box.h"

MapObjectKindRow gMapObjectKindRows[133] = {
    {101, (MapObjectKindDescriptor *) &gItemBoxKindDescriptor, NULL},
    {201, (MapObjectKindDescriptor *) &gGroupItemBoxKindDescriptor, NULL},
    {111, (MapObjectKindDescriptor *) &gPooledItemBoxKindDescriptor, NULL},
    {405, (MapObjectKindDescriptor *) &gBusAKindDescriptor, &gBusAKindInfo},
    {410, (MapObjectKindDescriptor *) &gCarAKindDescriptor, &gCarAKindInfo},
    {412, (MapObjectKindDescriptor *) &gTruckAKindDescriptor, &gTruckAKindInfo},
    {403, (MapObjectKindDescriptor *) &gDossunKindDescriptor, NULL},
    {404, NULL, NULL},
    {401, (MapObjectKindDescriptor *) &gKuriboKindDescriptor, NULL},
    {406, (MapObjectKindDescriptor *) &gWanwanOnChainKindDescriptor, NULL},
    {421, (MapObjectKindDescriptor *) &gWanwanOnPathKindDescriptor, NULL},
    {407, (MapObjectKindDescriptor *) &gWanwanChainKindDescriptor, NULL},
    {408, (MapObjectKindDescriptor *) &gMkdEfBubbleKindDescriptor, NULL},
    {409, (MapObjectKindDescriptor *) &data_usa_02158b80, NULL},
    {411, (MapObjectKindDescriptor *) &data_usa_02158fb0, NULL},
    {422, (MapObjectKindDescriptor *) &gObPakkunSfKindDescriptor, NULL},
    {303, (MapObjectKindDescriptor *) &gEarthenPipeKindDescriptor, NULL},
    {402, (MapObjectKindDescriptor *) &gRockKindDescriptor, NULL},
    {433, (MapObjectKindDescriptor *) &gRock2KindDescriptor, NULL},
    {205, (MapObjectKindDescriptor *) &gSecondHandKindDescriptor, NULL},
    {207, (MapObjectKindDescriptor *) &gPendulumKindDescriptor, NULL},
    {103, (MapObjectKindDescriptor *) &gWoodbox1KindDescriptor, NULL},
    {2, (MapObjectKindDescriptor *) &gAttractorKindDescriptor, NULL},
    {12, (MapObjectKindDescriptor *) &gWaterKindDescriptor, (void *) CreateMiniStage3Water},
    {1, (MapObjectKindDescriptor *) &gWaterKindDescriptor, (void *) CreateBeachWater},
    {3, (MapObjectKindDescriptor *) &gWaterKindDescriptor, (void *) CreateTownWater},
    {6, (MapObjectKindDescriptor *) &gWaterKindDescriptor, (void *) CreateYoshiWater},
    {9, (MapObjectKindDescriptor *) &gWaterKindDescriptor, (void *) CreateHyudoroWater},
    {5, (MapObjectKindDescriptor *) &gWaterEfctKindDescriptor, NULL},
    {14, (MapObjectKindDescriptor *) &gWaterEfctKindDescriptor, NULL},
    {15, (MapObjectKindDescriptor *) &gWaterEfctKindDescriptor, NULL},
    {202, (MapObjectKindDescriptor *) &gKoopaBlockKindDescriptor, NULL},
    {203, (MapObjectKindDescriptor *) &gRotaryGearBlackKindDescriptor, &gRotaryGearBlackKindInfo},
    {206, (MapObjectKindDescriptor *) &gRotaryTestCylinderKindDescriptor, &gRotaryTestCylinderKindInfo},
    {208, (MapObjectKindDescriptor *) &gRotaryRoomKindDescriptor, &gRotaryRoomKindInfo},
    {209, (MapObjectKindDescriptor *) &gRotaryBridgeKindDescriptor, &gRotaryBridgeKindInfo},
    {210, (MapObjectKindDescriptor *) &gDramKindDescriptor, NULL},
    {204, (MapObjectKindDescriptor *) &data_usa_02158c8c, NULL},
    {11, (MapObjectKindDescriptor *) &data_usa_0215a034, NULL},
    {413, &gSmanKindDescriptor, NULL},
    {308, &gCowKindDescriptor, NULL},
    {414, &gKanoke64KindDescriptor, NULL},
    {415, &gBasabasaKindDescriptor, NULL},
    {416, &gBasabasaBurstKindDescriptor, NULL},
    {420, &gMkdEfBurnerKindDescriptor, NULL},
    {418, (MapObjectKindDescriptor *) &gNsKiller2KindDescriptor, NULL},
    {417, &gNsKiller1KindDescriptor, NULL},
    {419, &gMoveTreeKindDescriptor, NULL},
    {315, &gTeresaKindDescriptor, NULL},
    {317, &gTeresaSpawnerKindDescriptor, NULL},
    {316, &gBakubakuKindDescriptor, NULL},
    {423, &gCoverPooHoleKindDescriptor, NULL},
    {425, &gFlipperKindDescriptor, NULL},
    {426, &gPakkunKindDescriptor, NULL},
    {427, &gPakkunSpitKindDescriptor, NULL},
    {428, &gCrabKindDescriptor, NULL},
    {424, &gBoundKindDescriptor, NULL},
    {429, &gSunKindDescriptor, NULL},
    {430, &gSunFireballKindDescriptor, NULL},
    {431, &gFireball2KindDescriptor, NULL},
    {13, &gPuddleKindDescriptor, NULL},
    {337, &gPicture1KindDescriptor, NULL},
    {338, &gPicture2KindDescriptor, NULL},
    {340, &gRainStarKindDescriptor, NULL},
    {320, &gChandelierKindDescriptor, NULL},
    {343, &gTownMonteKindDescriptor, NULL},
    {8, &data_usa_02167940, NULL},
    {102, &gCourseMapRowKindDescriptor, NULL},
    {106, &gShine16KindDescriptor, NULL},
    {107, (MapObjectKindDescriptor *) &gShineBattleKindDescriptor, NULL},
    {344, &gAirshipKindDescriptor, NULL},
    {10, &gDistanceSoundKindDescriptor, NULL},
    {105, (MapObjectKindDescriptor *) &gKartBalloonsKindDescriptor, NULL},
    {108, &gBalloonKindDescriptor, NULL},
    {434, &gSanboKindDescriptor, NULL},
    {432, &gIronBallKindDescriptor, NULL},
    {435, &gIronBallDrawOnlyKindDescriptor, NULL},
    {436, &gCreamKindDescriptor, NULL},
    {437, &gBerryKindDescriptor, NULL},
    {112, &gShineBalloonKindDescriptor, NULL},
    {301, &gBeachTree1KindDescriptor, NULL},
    {302, &gBeachTree1SecondKindDescriptor, NULL},
    {304, &gOpaTree1KindDescriptor, NULL},
    {306, &gOlgMush1KindDescriptor, NULL},
    {305, &gOlgPipe1KindDescriptor, NULL},
    {307, &gOf6yoshi1KindDescriptor, NULL},
    {309, &gNsCannon1KindDescriptor, NULL},
    {314, &gCrossTree1KindDescriptor, NULL},
    {318, &gBankTree1KindDescriptor, NULL},
    {319, &gGardenTree1KindDescriptor, NULL},
    {312, &gGardenTree1SecondKindDescriptor, NULL},
    {321, &gTownTree1KindDescriptor, NULL},
    {325, &gTownTree1SecondKindDescriptor, NULL},
    {322, &gMarioTree3KindDescriptor, NULL},
    {323, &gSnowTree1KindDescriptor, NULL},
    {326, &gSnowTree1SecondKindDescriptor, NULL},
    {327, &gDeTree1KindDescriptor, NULL},
    {328, &gDeTree1SecondKindDescriptor, NULL},
    {335, &gOlaTree1cKindDescriptor, NULL},
    {336, &gOsaTree1cKindDescriptor, NULL},
    {331, &gKinoHouse1KindDescriptor, NULL},
    {332, &gKinoHouse2KindDescriptor, NULL},
    {333, &gKinoMount1KindDescriptor, NULL},
    {334, &gKinoMount2KindDescriptor, NULL},
    {339, &gOm6Tree1KindDescriptor, NULL},
    {341, &gOf6Tree1KindDescriptor, NULL},
    {342, &gOf6Tree1SecondKindDescriptor, NULL},
    {329, &gBankEgg1KindDescriptor, NULL},
    {310, &gMiniDokanKindDescriptor, NULL},
    {104, &gCoinKindDescriptor, NULL},
    {110, &gMissionGateKindDescriptor, NULL},
    {345, &gStopSignKindDescriptor, NULL},
    {501, &gBossDonketuKindDescriptor, NULL},
    {502, &gKingIceDonketuKindDescriptor, NULL},
    {504, &gBombKingKindDescriptor, NULL},
    {503, &gKurikingKindDescriptor, NULL},
    {508, &gHanachanKindDescriptor, NULL},
    {510, &gHanachanFollowerKindDescriptor, NULL},
    {509, &gKingTeresaKindDescriptor, NULL},
    {507, &gIwanteKindDescriptor, NULL},
    {511, &gEmptyMapObjectKindDescriptor, NULL},
    {16, &gCameraEffectKindDescriptor, NULL},
    {438, &gPeriodicEffectKindDescriptor, NULL},
    {512, &gIwanteHandsKindDescriptor, NULL},
    {0, NULL, NULL},
    {0, NULL, NULL},
    {0, NULL, NULL},
    {0, NULL, NULL},
    {0, NULL, NULL},
    {0, NULL, NULL},
    {0, NULL, NULL},
    {0, NULL, NULL},
    {0, NULL, NULL}};

ViewFrustum gViewFrustumBeforeRotation;
ViewFrustum gViewFrustum;
s32 gItemSoundCameraHeightLimit;

ViewFrustum *GetViewFrustum(void) {
    return &gViewFrustum;
}

void RequestViewTestRefresh(void) {
    gViewFrustum.mViewTestRefreshRequested = TRUE;
    gViewFrustum.mViewTestRefreshPending = FALSE;
}

u32 GetViewTestRefreshPending(void) {
    u32 pending;
    pending = gViewFrustum.mViewTestRefreshPending;
    return pending;
}

void UpdateViewFrustum(MtxFx43 *viewMatrix) {
    MtxFx33 buf;

    MTX_Transpose33_(viewMatrix, &buf);
    MTX_MultVec33(&viewMatrix->mRows[3], &buf, &gViewFrustum.mCameraPos);
    gViewFrustum.mCameraPos.x = -gViewFrustum.mCameraPos.x;
    gViewFrustum.mCameraPos.y = -gViewFrustum.mCameraPos.y;
    gViewFrustum.mCameraPos.z = -gViewFrustum.mCameraPos.z;
    gViewFrustum.mCameraPos.x = gViewFrustum.mCameraPos.x << 4;
    gViewFrustum.mCameraPos.y = gViewFrustum.mCameraPos.y << 4;
    gViewFrustum.mCameraPos.z = gViewFrustum.mCameraPos.z << 4;
    gViewFrustum.mViewDirection.x = -buf.mRows[2].x;
    gViewFrustum.mViewDirection.y = -buf.mRows[2].y;
    gViewFrustum.mViewDirection.z = -buf.mRows[2].z;
    MTX_MultVec33(&gViewFrustumBeforeRotation.mLeftPlaneNormal, &buf, &gViewFrustum.mLeftPlaneNormal);
    MTX_MultVec33(&gViewFrustumBeforeRotation.mRightPlaneNormal, &buf, &gViewFrustum.mRightPlaneNormal);
    MTX_MultVec33(&gViewFrustumBeforeRotation.mTopPlaneNormal, &buf, &gViewFrustum.mTopPlaneNormal);
    MTX_MultVec33(&gViewFrustumBeforeRotation.mBottomPlaneNormal, &buf, &gViewFrustum.mBottomPlaneNormal);
    if (gViewFrustum.mViewTestRefreshRequested != FALSE) {
        gViewFrustum.mViewTestRefreshRequested = FALSE;
        gViewFrustum.mViewTestRefreshPending = TRUE;
    } else {
        gViewFrustum.mViewTestRefreshPending = FALSE;
    }
}

u32 ComputeDistanceViewTest(Vec3 *position, s32 unusedArg1, s32 unusedArg2, s32 distanceLimitSquared) {
    s32 deltaX;
    s32 deltaZ;
    s32 distanceSquared;
    u32 result;

    deltaX = FROM_FIXED12(position->x - gViewFrustum.mCameraPos.x);
    deltaZ = FROM_FIXED12(position->z - gViewFrustum.mCameraPos.z);
    distanceSquared = deltaX * deltaX + deltaZ * deltaZ;
    result = distanceSquared & ~0xc000001f;
    if (distanceSquared > distanceLimitSquared) {
        result |= gViewTestDistanceLimitFlag;
    }
    return result | 3;
}

s32 GetHorizontalCameraDistanceSquared(Vec3 *position) {
    s32 deltaX;
    s32 deltaZ;

    if (position == NULL) {
        return 0;
    }
    deltaX = FROM_FIXED12(position->x - gViewFrustum.mCameraPos.x);
    deltaZ = FROM_FIXED12(position->z - gViewFrustum.mCameraPos.z);
    return deltaX * deltaX + deltaZ * deltaZ;
}

void SetItemObjectSoundByViewRange(ItemObject *itemObject, Vec3 *position, u32 distanceAndFlags) {
    s32 cameraHeightAboveItem;

    if (distanceAndFlags & 4) {
        if (itemObject->mSoundSource.mSourceFlags & 1) {
            SetSoundSourceFlagBit(&itemObject->mSoundSource, 2, 1);
        }
        return;
    }
    cameraHeightAboveItem = gViewFrustum.mCameraPos.y - position->y;
    if (cameraHeightAboveItem > -0x12c000 && cameraHeightAboveItem < gItemSoundCameraHeightLimit) {
        if (!(itemObject->mSoundSource.mSourceFlags & 1)) {
            SetSoundSourceFlagBit(&itemObject->mSoundSource, 2, 1);
        }
    } else {
        if (itemObject->mSoundSource.mSourceFlags & 1) {
            SetSoundSourceFlagBit(&itemObject->mSoundSource, 2, 1);
        }
    }
}

BOOL IsMapObjectOutOfRange(MapObject *mapObject) {
    s32 cameraHeightAboveObject;

    if (mapObject->mDistanceSquaredAndFlags & 4) {
        return TRUE;
    }
    cameraHeightAboveObject = gViewFrustum.mCameraPos.y - mapObject->mPos.y;
    if (mapObject->mKindData->mHeightRangeMin < cameraHeightAboveObject &&
        cameraHeightAboveObject < mapObject->mKindData->mHeightRangeMax) {
        return FALSE;
    }
    return TRUE;
}

BOOL IsMapObjectOutOfRangeOrMaskedAtDistance(MapObject *mapObject, s32 distanceSquared) {
    s32 heightAboveCamera;
    Vec3 *position;
    MapObjectKindData *kindData;

    position = &mapObject->mPos;
    if (distanceSquared > mapObject->mFarDistanceSquared) {
        return TRUE;
    }
    kindData = mapObject->mKindData;
    heightAboveCamera = FROM_FIXED12(position->y - gViewFrustum.mCameraPos.y);
    if (heightAboveCamera < kindData->mHeightRangeMin || kindData->mHeightRangeMax < heightAboveCamera) {
        return TRUE;
    }
    return (GetKartKind3ShapeListMask() & mapObject->mDigitMask) != 0;
}

void SetupMapObjectView(MtxFx43 *viewMatrix) {
    SetViewMatrices(viewMatrix);
    SetViewYawQuaternion(viewMatrix);
}

void DrawMapObjectList(MapObjectList *list, MtxFx43 *viewMatrix) {
    s32 objectIndex;
    MapObject *mapObject;
    UnkFunc *forEachObject;
    s32 objectCount;
    void **objects;
    MapObject *lastObject;
    s32 lastIndex;

    forEachObject = list->mForEachObject;
    objectCount = list->mMapObjectCount;
    objects = list->mDrawOrder;
    if (forEachObject == NULL) {
        return;
    }
    if (list->mSortByDistance != 0) {
        lastObject = NULL;
        for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
            mapObject = objects[objectIndex];
            if (!(mapObject->mFlags & 0x12) && mapObject->mAlpha != 0) {
                forEachObject(list, mapObject, viewMatrix, mapObject->mAlpha);
                if (lastObject != NULL && (s32) (mapObject->mDistanceSquaredAndFlags & ~0xc000001f) >
                                              (s32) (lastObject->mDistanceSquaredAndFlags & ~0xc000001f)) {
                    objects[lastIndex] = mapObject;
                    objects[objectIndex] = lastObject;
                } else {
                    lastObject = mapObject;
                }
                lastIndex = objectIndex;
            }
        }
    } else {
        for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
            mapObject = objects[objectIndex];
            if (!(mapObject->mFlags & 0x12) && mapObject->mAlpha != 0) {
                forEachObject(list, mapObject, viewMatrix, mapObject->mAlpha);
            }
        }
    }
}

#pragma thumb on

void InitMapObjectViewState(void) {
    gViewFrustum.mViewTestRefreshRequested = TRUE;
    gViewFrustum.mViewTestRefreshPending = FALSE;
    if (gRaceSetup->mRaceKind == RACE_KIND_REPLAY) {
        gItemSoundCameraHeightLimit = 0x258000;
        return;
    }
    gItemSoundCameraHeightLimit = 0x12c000;
}

#pragma thumb off

#pragma thumb on
void RefreshViewFrustumFromProjection(s32 top, s32 bottom, s32 left, s32 right, s32 nearDistance, s32 farDistance) {
    gViewFrustumBeforeRotation.mNear = nearDistance << 4;
    gViewFrustum.mNear = nearDistance << 4;
    gViewFrustumBeforeRotation.mFar = farDistance << 4;
    gViewFrustum.mFar = farDistance << 4;

    gViewFrustumBeforeRotation.mLeftPlaneNormal.x = nearDistance;
    gViewFrustumBeforeRotation.mLeftPlaneNormal.y = 0;
    gViewFrustumBeforeRotation.mLeftPlaneNormal.z = -left;
    if ((s64) gViewFrustumBeforeRotation.mLeftPlaneNormal.z * gViewFrustumBeforeRotation.mLeftPlaneNormal.z +
            ((s64) gViewFrustumBeforeRotation.mLeftPlaneNormal.x * gViewFrustumBeforeRotation.mLeftPlaneNormal.x +
             (s64) gViewFrustumBeforeRotation.mLeftPlaneNormal.y * gViewFrustumBeforeRotation.mLeftPlaneNormal.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewFrustumBeforeRotation.mLeftPlaneNormal,
                                           &gViewFrustumBeforeRotation.mLeftPlaneNormal);
    }
    if (gRaceSetup->mMirrorMode != 0) {
        gViewFrustumBeforeRotation.mLeftPlaneNormal.x = -gViewFrustumBeforeRotation.mLeftPlaneNormal.x;
        gViewFrustumBeforeRotation.mLeftPlaneNormal.y = -gViewFrustumBeforeRotation.mLeftPlaneNormal.y;
        gViewFrustumBeforeRotation.mLeftPlaneNormal.z = -gViewFrustumBeforeRotation.mLeftPlaneNormal.z;
    }

    gViewFrustumBeforeRotation.mRightPlaneNormal.x = -nearDistance;
    gViewFrustumBeforeRotation.mRightPlaneNormal.y = 0;
    gViewFrustumBeforeRotation.mRightPlaneNormal.z = right;
    if ((s64) gViewFrustumBeforeRotation.mRightPlaneNormal.z * gViewFrustumBeforeRotation.mRightPlaneNormal.z +
            ((s64) gViewFrustumBeforeRotation.mRightPlaneNormal.x * gViewFrustumBeforeRotation.mRightPlaneNormal.x +
             (s64) gViewFrustumBeforeRotation.mRightPlaneNormal.y * gViewFrustumBeforeRotation.mRightPlaneNormal.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewFrustumBeforeRotation.mRightPlaneNormal,
                                           &gViewFrustumBeforeRotation.mRightPlaneNormal);
    }
    if (gRaceSetup->mMirrorMode != 0) {
        gViewFrustumBeforeRotation.mRightPlaneNormal.x = -gViewFrustumBeforeRotation.mRightPlaneNormal.x;
        gViewFrustumBeforeRotation.mRightPlaneNormal.y = -gViewFrustumBeforeRotation.mRightPlaneNormal.y;
        gViewFrustumBeforeRotation.mRightPlaneNormal.z = -gViewFrustumBeforeRotation.mRightPlaneNormal.z;
    }

    gViewFrustumBeforeRotation.mTopPlaneNormal.x = 0;
    gViewFrustumBeforeRotation.mTopPlaneNormal.y = -nearDistance;
    gViewFrustumBeforeRotation.mTopPlaneNormal.z = top;
    if ((s64) gViewFrustumBeforeRotation.mTopPlaneNormal.z * gViewFrustumBeforeRotation.mTopPlaneNormal.z +
            ((s64) gViewFrustumBeforeRotation.mTopPlaneNormal.x * gViewFrustumBeforeRotation.mTopPlaneNormal.x +
             (s64) gViewFrustumBeforeRotation.mTopPlaneNormal.y * gViewFrustumBeforeRotation.mTopPlaneNormal.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewFrustumBeforeRotation.mTopPlaneNormal,
                                           &gViewFrustumBeforeRotation.mTopPlaneNormal);
    }

    gViewFrustumBeforeRotation.mBottomPlaneNormal.x = 0;
    gViewFrustumBeforeRotation.mBottomPlaneNormal.y = nearDistance;
    gViewFrustumBeforeRotation.mBottomPlaneNormal.z = -bottom;
    if ((s64) gViewFrustumBeforeRotation.mBottomPlaneNormal.z * gViewFrustumBeforeRotation.mBottomPlaneNormal.z +
            ((s64) gViewFrustumBeforeRotation.mBottomPlaneNormal.x * gViewFrustumBeforeRotation.mBottomPlaneNormal.x +
             (s64) gViewFrustumBeforeRotation.mBottomPlaneNormal.y * gViewFrustumBeforeRotation.mBottomPlaneNormal.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewFrustumBeforeRotation.mBottomPlaneNormal,
                                           &gViewFrustumBeforeRotation.mBottomPlaneNormal);
    }
}
#pragma thumb off

#pragma thumb on
void ClearMapObjectList(MapObjectList *list) {
    list->mMapObjects = NULL;
    list->mMapObjectCount = 0;
}
#pragma thumb off

#pragma thumb on
void DrawListAddToMapObjectListCount(MapObjectList *list, s32 count) {
    list->mMapObjectCount += count;
}
#pragma thumb off

#pragma thumb on
u32 InitMapObjectDrawList(MapObjectList *list) {
    list->mMapObjects = HeapAlloc(GetHeap(GetCurrentHeapCall()), list->mMapObjectCount << 2);
    list->mMapObjectCount = 0;
    return 0;
}
#pragma thumb off

#pragma thumb on
u32 AddMapObjectToDrawList(MapObjectList *list, MapObject *mapObject) {
    u32 index = list->mMapObjectCount;
    list->mMapObjectCount = index + 1;
    list->mMapObjects[index] = mapObject;
    return index << 2;
}
#pragma thumb off

#pragma thumb on

void SetDrawListSlot(void *listSlot) {
    *(u32 *) ((u8 *) (u32) (((u32) * (const u32 *) ((u8 *) (u32) listSlot + 0))) + 40) = (u32) listSlot;
}

#pragma thumb off

#pragma thumb on
void InitMapObjectDrawOrder(MapObjectList *list) {
    s32 objectIndex;

    if (list->mSortByDistance != 0) {
        list->mDrawOrder = HeapAlloc(GetHeap(GetCurrentHeapCall()), list->mMapObjectCount * 4);
        for (objectIndex = 0; objectIndex < list->mMapObjectCount; objectIndex++) {
            list->mDrawOrder[objectIndex] = list->mMapObjects[objectIndex];
        }
    } else {
        list->mDrawOrder = list->mMapObjects;
    }
}
#pragma thumb off

void SetCourseWater(Water *water) {
    gCourseWater = water;
}

void SetCourseWaterEfct(void *waterEfct) {
    gCourseWaterEfct = waterEfct;
}

void UpdateMapObjectViewTests(void) {
    u32 shapeMask;
    s32 objectIndex;
    s32 mapObjectCount;
    MapObject *mapObject;
    MapObject **mapObjects;
    u32 frameSlot;
    u16 extraFlags;
    u32 extraViewFlags;

    mapObjectCount = gMapObjects->mMapObjectCount;
    mapObjects = gMapObjects->mMapObjects;
    shapeMask = GetKartKind3ShapeListMask();
    frameSlot = GetRaceUpdateFrames() & 3;
    objectIndex = 0;
    if (mapObjectCount <= 0) {
        return;
    }
    extraFlags = gViewTestPassedFlag;
    extraViewFlags = gViewTestResultFlag;
    do {
        mapObject = mapObjects[objectIndex];
        mapObject->mDistanceSquaredAndFlags &= ~8;
        if (!(mapObject->mFlags & 2)) {
            if (mapObject->mDistanceSquaredAndFlags & 1) {
                if (mapObject->mAlpha != 0) {
                    mapObject->mAlpha -= 1;
                }
            } else {
                if (mapObject->mAlpha < 0x1f) {
                    mapObject->mAlpha += 1;
                }
            }
            if ((objectIndex & 3) == frameSlot) {
                if (mapObject->mDigitMask & shapeMask) {
                    mapObject->mDistanceSquaredAndFlags = (mapObject->mDistanceSquaredAndFlags & 0x10) | 0x5f592e7;
                    mapObject->mFlags |= extraFlags;
                } else {
                    if (mapObject->mUseTwoPlaneViewTest != 0) {
                        mapObject->mDistanceSquaredAndFlags =
                            (mapObject->mDistanceSquaredAndFlags & 0x10) |
                            ComputeTwoPlaneViewTest(&mapObject->mPos, mapObject->mViewRadius, mapObject->mDrawDistance,
                                                    mapObject->mFarDistanceSquared, mapObject->mAlpha);
                    } else {
                        mapObject->mDistanceSquaredAndFlags =
                            (mapObject->mDistanceSquaredAndFlags & 0x10) |
                            ComputeViewTest(&mapObject->mPos, mapObject->mViewRadius, mapObject->mDrawDistance,
                                            mapObject->mFarDistanceSquared, mapObject->mAlpha);
                    }
                    mapObject->mDistanceSquaredAndFlags |= extraViewFlags;
                    if (mapObject->mDistanceSquaredAndFlags & 2) {
                        mapObject->mFlags |= extraFlags;
                    } else {
                        mapObject->mFlags &= ~0x10;
                    }
                }
            }
        }
    } while (++objectIndex < mapObjectCount);
}

void RefreshMapObjectViewTests(void) {
    u32 shapeMask;
    s32 objectIndex;
    s32 mapObjectCount;
    MapObject *mapObject;
    MapObject **mapObjects;
    u16 extraFlags;
    u32 extraViewFlags;

    shapeMask = GetKartKind3ShapeListMask();
    objectIndex = 0;
    mapObjectCount = gMapObjects->mMapObjectCount;
    mapObjects = gMapObjects->mMapObjects;
    if (mapObjectCount <= 0) {
        return;
    }
    extraFlags = gViewTestPassedFlag;
    extraViewFlags = gViewTestResultFlag;
    do {
        mapObject = mapObjects[objectIndex];
        mapObject->mDistanceSquaredAndFlags &= ~8;
        if (!(mapObject->mFlags & 2)) {
            if (mapObject->mDigitMask & shapeMask) {
                mapObject->mFlags |= extraFlags;
            } else {
                if (mapObject->mUseTwoPlaneViewTest != 0) {
                    mapObject->mDistanceSquaredAndFlags =
                        (mapObject->mDistanceSquaredAndFlags & 0x10) |
                        ComputeTwoPlaneViewTest(&mapObject->mPos, mapObject->mViewRadius, mapObject->mDrawDistance,
                                                mapObject->mFarDistanceSquared, mapObject->mAlpha);
                } else {
                    mapObject->mDistanceSquaredAndFlags =
                        (mapObject->mDistanceSquaredAndFlags & 0x10) |
                        ComputeViewTest(&mapObject->mPos, mapObject->mViewRadius, mapObject->mDrawDistance,
                                        mapObject->mFarDistanceSquared, mapObject->mAlpha);
                }
                mapObject->mDistanceSquaredAndFlags |= extraViewFlags;
                if (mapObject->mDistanceSquaredAndFlags & 1) {
                    mapObject->mAlpha = 0;
                } else {
                    mapObject->mAlpha = 0x1f;
                }
                if (mapObject->mDistanceSquaredAndFlags & 2) {
                    mapObject->mFlags |= extraFlags;
                } else {
                    mapObject->mFlags &= ~0x10;
                }
            }
        }
    } while (++objectIndex < mapObjectCount);
}

void UpdateMapObjects(void) {
    MapObjectList *list;
    s32 listIndex;
    s32 updateListCount;
    MapObjectList **lists;
    s32 startFrames;

    lists = gMapObjects->mUpdateLists;
    updateListCount = gMapObjects->mUpdateListCount;
    startFrames = GetRaceStartSequenceFrames();
    if (startFrames <= 0x168) {
        if (gRaceSetup->mRaceKind != RACE_KIND_START_GP) {
            if (startFrames == -0x73) {
                ParkFlaggedMapObjects();
            } else if (startFrames == 0x168) {
                UnparkFlaggedMapObjects();
            }
        }
    }
    if (gMapObjects->mRunUpdateLists != 0) {
        for (listIndex = 0; listIndex < updateListCount; listIndex++) {
            list = lists[listIndex];
            if (list->mBeforeObjects != NULL) {
                list->mBeforeObjects(list);
            }
            UpdateMapObjectList(list);
            if (list->mAfterObjects != NULL) {
                list->mAfterObjects(list);
            }
        }
    }
    if (GetViewTestRefreshPending() != 0) {
        RefreshMapObjectViewTests();
    } else {
        UpdateMapObjectViewTests();
    }
    if (gCourseWater != NULL) {
        UpdateWater(gCourseWater);
    }
}

void DrawMapObjects(Camera *view) {
    s32 listIndex;
    s32 firstPassCount;
    MapObjectList **lists;
    MapObjectList *list;
    MtxFx43 *viewMatrix;
    s32 secondPassCount;
    s32 secondPassListIndex;

    viewMatrix = &view->mViewMatrix;
    SetupMapObjectView(viewMatrix);
    if (gCourseWater != NULL) {
        DrawWater(gCourseWater, viewMatrix);
    }
    listIndex = 0;
    firstPassCount = gMapObjects->mFirstPassDrawListCount;
    lists = gMapObjects->mFirstPassDrawLists;
    for (; listIndex < firstPassCount; listIndex++) {
        list = lists[listIndex];
        SendWhiteLight01Color();
        if (list->mBeforeObjects != NULL) {
            list->mBeforeObjects(list);
        }
        DrawMapObjectList(list, viewMatrix);
        if (list->mAfterObjects != NULL) {
            list->mAfterObjects(list);
        }
    }
    QueueViewMatrix();
    secondPassListIndex = 0;
    secondPassCount = gMapObjects->mSecondPassDrawListCount;
    lists = gMapObjects->mSecondPassDrawLists;
    for (; secondPassListIndex < secondPassCount; secondPassListIndex++) {
        list = lists[secondPassListIndex];
        if (list->mBeforeObjects != NULL) {
            list->mBeforeObjects(list);
        }
        DrawMapObjectList(list, viewMatrix);
        if (list->mAfterObjects != NULL) {
            list->mAfterObjects(list);
        }
    }
}

void DrawKoopaBlocksKind203AndBridges(Camera *view) {
    MtxFx43 *viewMatrix;

    viewMatrix = &view->mViewMatrix;
    if (gMapObjects->mHasKoopaBlock != 0) {
        DrawAllKoopaBlocks(viewMatrix);
    }
    if (gMapObjects->mUnk_180 != 0) {
        DrawAllKind203MapObjects(viewMatrix);
    }
    if (gMapObjects->mUnk_184 != 0) {
        DrawAllBridges(viewMatrix);
    }
}

s32 FindMapObjectsTouchingKart(Kart *kart, Vec3 *position, Vec3 *hitOffset) {
    Vec3 centre;
    Vec3 lo;
    Vec3 hi;
    s32 radius;
    BOOL kartFlagSet;
    s32 itemEffect;
    s32 slotIndex;
    MapObject *mapObject;
    s32 foundCount;
    Vec3 *foundVector;

    centre = *position;
    kartFlagSet = (kart->mDriveFlags & KART_DRIVE_FAR_FROM_ENTRY) != 0;
    radius = kart->mRadius;
    itemEffect = kart->mItemEffect;
    foundVector = gFoundMapObjectVectors;
    {
        Vec3 zeroLow = {0, 0, 0};
        lo = zeroLow;
    }
    {
        Vec3 zeroHigh = {0, 0, 0};
        hi = zeroHigh;
    }
    foundCount = 0;
    hitOffset->x = hitOffset->y = hitOffset->z = 0;
    for (slotIndex = 0; slotIndex < gFoundCollisionSlotCount; slotIndex++) {
        if (gFoundCollisionSlotFlags[slotIndex] & 0x2000) {
            mapObject = gFoundCollisionSlotObjects[slotIndex];
            if (kartFlagSet != FALSE && !(mapObject->mDistanceSquaredAndFlags & 0x10)) {
                continue;
            }
            if (IsSphereHittingMapObject(&centre, radius, mapObject, foundVector) != FALSE) {
                if (!(mapObject->mFlags & 0x40) && DoesKartRespondToMapObject(itemEffect, mapObject) != 0) {
                    lo.x = (foundVector->x < lo.x) ? foundVector->x : lo.x;
                    lo.y = (foundVector->y < lo.y) ? foundVector->y : lo.y;
                    lo.z = (foundVector->z < lo.z) ? foundVector->z : lo.z;
                    hi.x = (foundVector->x > hi.x) ? foundVector->x : hi.x;
                    hi.y = (foundVector->y > hi.y) ? foundVector->y : hi.y;
                    hi.z = (foundVector->z > hi.z) ? foundVector->z : hi.z;
                }
                gFoundMapObjects[foundCount] = mapObject;
                foundCount++;
                foundVector = &gFoundMapObjectVectors[foundCount];
                if (foundCount >= 0x20) {
                    foundCount = 0x1f;
                }
            }
        }
    }
    if (foundCount != 0 && hitOffset != NULL) {
        hitOffset->x = hi.x + lo.x;
        hitOffset->y = hi.y + lo.y;
        if (hitOffset->y < 0) {
            hitOffset->y = 0;
        }
        hitOffset->z = hi.z + lo.z;
    }
    return foundCount;
}

s32 FindMapObjectsOfKindInRadius(Vec3 *position, s32 radius, s32 kind) {
    s32 foundCount;
    MapObject *mapObject;
    s32 deltaZ;
    s32 deltaX;
    s32 slotIndex;

    foundCount = 0;
    FindCollisionSlotsAroundPos(position, radius, 0x2000);
    for (slotIndex = 0; slotIndex < gFoundCollisionSlotCount; slotIndex++) {
        mapObject = gFoundCollisionSlotObjects[slotIndex];
        if (mapObject->mKind == kind) {
            deltaX = position->x - mapObject->mPos.x;
            deltaZ = position->z - mapObject->mPos.z;
            if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ < (s64) radius * radius) {
                gFoundMapObjects[foundCount] = mapObject;
                foundCount++;
            }
        }
    }
    return foundCount;
}

// Returns the i-th map object stored by the last FindMapObjectsTouchingKart or FindMapObjectsOfKindInRadius call; i
// must be below the count that call returned.
MapObject *GetFoundMapObject(u32 index) {
    return gFoundMapObjects[index];
}

Vec3 *GetFoundMapObjectVector(int index) {
    return gFoundMapObjectVectors + index;
}

BOOL IsSphereHittingMapObject(Vec3 *position, s32 radius, MapObject *mapObject, Vec3 *overlapOffset) {
    s32 combinedRadius;
    s32 combinedHeight;
    s32 dx;
    s32 dy;
    s32 dz;
    BOOL isHit;
    s32 negatedRadius;
    if (mapObject->mFlags & 1) {
        return FALSE;
    }
    switch (mapObject->mKindData->mShapeKind) {
        case 1:
            combinedRadius = radius + mapObject->mExtent.x;
            negatedRadius = -combinedRadius;
            dz = position->z - mapObject->mPos.z;
            if (dz > combinedRadius || dz < negatedRadius) {
                isHit = FALSE;
            } else {
                dx = position->x - mapObject->mPos.x;
                if (dx > combinedRadius || dx < negatedRadius) {
                    isHit = FALSE;
                } else {
                    dy = position->y - mapObject->mPos.y;
                    if (dy > combinedRadius || dy < negatedRadius) {
                        isHit = FALSE;
                    } else {
                        isHit = (s64) dx * dx + (s64) dy * dy + (s64) dz * dz < (s64) combinedRadius * combinedRadius;
                    }
                }
            }
            if (isHit == FALSE) {
                return FALSE;
            }
            ComputeSphereOverlapOffset(position, &mapObject->mPos, combinedRadius, overlapOffset);
            return TRUE;
        case 2:
            combinedRadius = radius + mapObject->mExtent.x;
            combinedHeight = radius + mapObject->mExtent.y;
            negatedRadius = -combinedRadius;
            dz = position->z - mapObject->mPos.z;
            if (dz > combinedRadius || dz < negatedRadius) {
                isHit = FALSE;
            } else {
                dx = position->x - mapObject->mPos.x;
                if (dx > combinedRadius || dx < negatedRadius) {
                    isHit = FALSE;
                } else {
                    dy = position->y - mapObject->mPos.y;
                    if (dy > combinedHeight || dy < -combinedHeight) {
                        isHit = FALSE;
                    } else {
                        isHit = (s64) dx * dx + (s64) dz * dz < (s64) combinedRadius * combinedRadius;
                    }
                }
            }
            if (isHit == FALSE) {
                return FALSE;
            }
            ComputeCylinderOverlapOffset(position, &mapObject->mPos, combinedRadius, combinedHeight, overlapOffset);
            return TRUE;
        case 3:
            return ComputeSphereHitOnRotatedCylinder(position, &mapObject->mPos, &mapObject->mMatrix.mRows[0],
                                                     mapObject->mExtent.x, mapObject->mExtent.y, mapObject->mExtent.y,
                                                     radius, overlapOffset) != 0;
        case 4:
            return ComputeSphereHitOnRotatedBox(position, &mapObject->mPos, &mapObject->mMatrix.mRows[0],
                                                &mapObject->mExtent, &mapObject->mExtent, radius, overlapOffset) != 0;
        case 0:
            return FALSE;
        case 5:
            if (mapObject->mKindData->mSphereHitTest != NULL) {
                return mapObject->mKindData->mSphereHitTest(mapObject, position, radius, overlapOffset) != 0;
            }
            return FALSE;
        default:
            return FALSE;
    }
}

// TRUE when the course has a water object (gCourseWater is not NULL); asked by the camera and the HUD gauge.
BOOL IsWaterPresent(void) {
    return gCourseWater != NULL;
}

// y minus mHeight of gCourseWater (negative below the water), 9999.0 (fx32) when the course has no water; asked by the
// camera; it does not look at mUnk_170 or WaterEfct.
s32 GetHeightAboveWater(s32 height) {
    return gCourseWater != NULL ? height - gCourseWater->mHeight : 0x270f000;
}

// mHeightFactor of gCourseWater, 0 when the course has no water; asked by the HUD gauge.
s32 GetWaterHeightFactor(void) {
    return gCourseWater != NULL ? gCourseWater->mHeightFactor : 0;
}

// mHeightAngle of gCourseWater, 0 when the course has no water; the HUD gauge tests 0x4000 <= angle < 0xc000 (the
// falling half).
u32 GetWaterHeightAngle(void) {
    return gCourseWater != NULL ? gCourseWater->mHeightAngle : 0;
}

u32 IsWaterHeightUsed(void) {
    u32 result = 0;
    if (gCourseWater == NULL) {
        return result;
    }
    if (gCourseWater->mUnk_170 != 0) {
        result = 1;
    }
    return result;
}

// Y minus mHeight when the Water exists and mUnk_170 is non-zero (mini stage 3, beach), else y minus WaterEfct.mHeight,
// else 9999.0 (fx32); Or = the second source when the first is not used; asked by the kart steps, the kart sound and
// the overlay-1 objects.
s32 GetHeightAboveWaterOrEfct(s32 height) {
    if (gCourseWater != NULL && gCourseWater->mUnk_170 != 0) {
        return height - gCourseWater->mHeight;
    }
    return gCourseWaterEfct != NULL ? height - gCourseWaterEfct->mHeight : 0x270f000;
}

s32 IsFarBelowWaterEfct(s32 height) {
    BOOL isFarBelow;
    isFarBelow = FALSE;
    if (gCourseWaterEfct != NULL) {
        if (height - gCourseWaterEfct->mHeight < -0x32000) {
            isFarBelow = TRUE;
        }
    }
    return isFarBelow;
}

void RunMapObjectListCallbacks(void) {
    s32 listIndex;
    s32 listCount;
    MapObjects *mapObjects;
    MapObjectList **lists;
    listIndex = 0;
    mapObjects = gMapObjects;
    listCount = mapObjects->mUpdateListCount;
    lists = mapObjects->mUpdateLists;
    for (; listIndex < listCount; listIndex++) {
        CallMapObjectListCallback(lists[listIndex]);
    }
}

s32 GetMapObjectHitResponse(MapObject *mapObject, s32 itemKind, Vec3 *hitOffset) {
    return CollideSphereWithMapObjects(&mapObject->mPos, &mapObject->mPosStep, mapObject->mExtent.x,
                                       mapObject->mCollisionSlotIndex, itemKind, hitOffset);
}

void SetMapObjectsRunUpdateLists(void) {
    gMapObjects->mRunUpdateLists = 1;
}

u16 AllocPolygonIdWrapping(void) {
    gWrappingPolygonId++;
    if (gWrappingPolygonId > 0x3e) {
        gWrappingPolygonId = gWrappingPolygonIdBase;
    }
    return gWrappingPolygonId;
}

u16 AllocPolygonId(void) {
    return gNextPolygonId++;
}

#pragma thumb on

u16 CountMapObjectsOfKind(u32 kind) {
    s32 objectIndex;
    u16 count;
    count = 0;
    objectIndex = 0;
    for (; objectIndex < gMapObjects->mMapObjectCount; objectIndex++) {
        if (kind == gMapObjects->mMapObjects[objectIndex]->mKind) {
            count++;
        }
    }
    return count;
}

void ParkFlaggedMapObjects(void) {
    s32 objectIndex;
    s32 mapObjectCount;
    MapObject **mapObjectSlot;
    MapObject *mapObject;
    mapObjectCount = gMapObjects->mMapObjectCount;
    mapObjectSlot = gMapObjects->mMapObjects;
    for (objectIndex = 0; objectIndex < mapObjectCount; objectIndex++) {
        mapObject = *mapObjectSlot;
        if (mapObject->mFlags & 0x80) {
            if (mapObject->mFlags & 0x100) {
                mapObject->mFlags &= ~0x80;
            } else {
                mapObject->mFlags &= ~0xf000;
                mapObject->mFlags |= (mapObject->mFlags & 0xf) << 12;
                mapObject->mFlags |= gMapObjectNoUpdateListFlag;
                if (mapObject->mCollisionSlotIndex != -1) {
                    DisableCollisionSlot(mapObject->mCollisionSlotIndex);
                }
            }
        }
        mapObjectSlot++;
    }
}

void UnparkFlaggedMapObjects(void) {
    s32 objectIndex;
    s32 mapObjectCount;
    MapObject **mapObjectSlot;
    MapObject *mapObject;
    mapObjectCount = gMapObjects->mMapObjectCount;
    mapObjectSlot = gMapObjects->mMapObjects;
    for (objectIndex = 0; objectIndex < mapObjectCount; objectIndex++) {
        mapObject = *mapObjectSlot;
        if (mapObject->mFlags & 0x80) {
            mapObject->mFlags &= ~0x80;
            mapObject->mFlags &= ~0xf;
            mapObject->mFlags |= (mapObject->mFlags & 0xf000) >> 12;
            if (mapObject->mCollisionSlotIndex != -1) {
                EnableCollisionSlot(mapObject->mCollisionSlotIndex);
            }
        }
        mapObjectSlot++;
    }
}

#pragma thumb off

#pragma thumb on

// Stores the mask of the nonzero decimal digits of a (bit d for digit d) in mUnk_74; a of 10000 or more first sets flag
// 0x80 in mFlags and loses the 10000.
void SetMapObjectMaskAndFlagFromNumber(s32 number, MapObject *mapObject) {
    int limit;
    u32 digitMask;
    limit = 0x2710;
    if (0x2710 <= number) {
        mapObject->mFlags = mapObject->mFlags | gMapObjectNumberOverflowFlag;
        number = (number - limit) * 0x10000 >> 0x10;
    }
    digitMask = DecimalNonZeroDigitsToBitMask(number);
    mapObject->mDigitMask = digitMask;
}

#pragma thumb off

const u16 gViewTestPassedFlag = 0x10;
const u16 gMapObjectNumberOverflowFlag = 0x80;
const u32 gViewTestDistanceLimitFlag = 4;
const u32 gViewTestResultFlag = 8;
const u32 gViewTestMaxDistanceFlag = 1;
