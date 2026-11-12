#include "Main/MapObjects/fireball2.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/picture_puddle.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Sound/snd_handle_slots.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/data_02167000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "code_02147cd8.h"
#include "code_0212df7c.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

const u16 gSunFireballInitMapObjectFlag = 0x200;
const u32 gFireball2SkipSoundFlag = 0x40000000;
MapObjectModel *gFireball2;

MapObjectKindDescriptor gFireball2KindDescriptor = {0,
                                             {0, 0},
                                             0x19e8,
                                             (void (*)(void *, CourseMapRow *, void *)) InitFireball2,
                                             CreateFireball2KindData,
                                             CreateFireball2DrawList,
                                             0,
                                             0,
                                             CreateFireball2UpdateList};

MapObjectList *CreatePuddleDrawList(void) {
    return CreateMapObjectDrawList2(CreatePuddle, DrawPuddle, SetupDrawPuddle);
}

void InitFireball2(Fireball2 *fireball2) {
    fireball2->mMapObject.mFlags |= gFireball2InitMapObjectFlag;
    fireball2->mRowCount = fireball2->mMapObject.mCourseMapRow->mSettings[0];
    fireball2->mRowElementCount = fireball2->mMapObject.mCourseMapRow->mSettings[3] + 1;
    CreateMapObjectSoundSourceFalloff2(&fireball2->mMapObject);
    fireball2->mMapObject.mFlags &= ~1;
    fireball2->mMapObject.mFlags &= ~2;
    fireball2->mMapObject.mFlags &= ~8;
    fireball2->mMapObject.mAlpha = 0x1f;
}

u8 CollideKartWithFireball2(Fireball2 *fireball2, Kart *kart, u8 *firstResponse, u8 *response) {
    u8 responseValue;

    responseValue = *response;
    if (fireball2->mKartHitTimers[kart->mIndex] == 0) {
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
            fireball2->mMapObject.mDistanceSquaredAndFlags |= gFireball2SkipSoundFlag;
        }
        StartSoundIfKartStarOrKiller(&fireball2->mMapObject, kart);
    }
    fireball2->mKartHitTimers[kart->mIndex] = 0xb;
    return responseValue;
}

static inline BOOL IsKartWithinFireball2Range(Kart *kart, Fireball2 *fireball, s32 radius) {
    s32 deltaY;
    s32 deltaX;
    s32 deltaZ;
    s32 negativeRadius;

    negativeRadius = -radius;
    deltaZ = kart->mPos.z - fireball->mMapObject.mPos.z;
    if (deltaZ > radius || deltaZ < negativeRadius) {
        return FALSE;
    }
    deltaX = kart->mPos.x - fireball->mMapObject.mPos.x;
    if (deltaX > radius || deltaX < negativeRadius) {
        return FALSE;
    }
    deltaY = kart->mPos.y - fireball->mMapObject.mPos.y;
    if (deltaY > radius || deltaY < negativeRadius) {
        return FALSE;
    }
    return (s64) deltaX * deltaX + (s64) deltaY * deltaY + (s64) deltaZ * deltaZ < (s64) radius * radius;
}

BOOL IsPosNearFireball2(Fireball2 *fireball2, Vec3 *pos, s32 radius) {
    s32 rowIndex;
    s32 deltaX;
    s32 deltaY;
    s32 deltaZ;

    for (rowIndex = 0; rowIndex < fireball2->mRowCount; rowIndex++) {
        deltaX = pos->x - fireball2->mElements[rowIndex][0].mPos.x;
        deltaY = pos->y - fireball2->mElements[rowIndex][0].mPos.y;
        deltaZ = pos->z - fireball2->mElements[rowIndex][0].mPos.z;
        if ((s64) deltaX * deltaX + (s64) deltaY * deltaY + (s64) deltaZ * deltaZ <
            (s64) (radius + 0xf000) * (radius + 0xf000)) {
            return TRUE;
        }
    }
    return FALSE;
}

void CreateFireball2(MapObjectList *mapObjectList) {
    gFireball2 = CreateMapObjectModelNsbmd(mapObjectList, "fireball2.nsbmd");
    SetMapObjectModelPolygonId(gFireball2, 0x3f);
    mapObjectList->mSortByDistance = 1;
}

void SetupDrawFireball2(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gFireball2);
}

void DrawFireball2(void *mapObjectList, Fireball2 *fireball2) {
    s32 gxParam;
    s32 centerGxParam;
    s32 reverseGxParam;
    MtxFx33 elementRotation;
    MtxFx33 centerRotation;
    MtxFx33 reverseRotation;
    s32 rowIndex;
    s32 cameraDot;
    s32 elementIndex;
    s32 facingForward;
    s32 rowInFront;
    Camera *currentCamera;

    currentCamera = GetCurrentCamera();
    cameraDot = Vec3DotUnrounded(&fireball2->mMapObject.mMatrix.mRows[0], &currentCamera->mForward);
    for (rowIndex = 0; rowIndex < fireball2->mRowCount; rowIndex++) {
        if (cameraDot >= 0) {
            facingForward = 1;
        } else {
            facingForward = 0;
        }
        if (fireball2->mElements[rowIndex][0].mAngle >= 0x4000 && fireball2->mElements[rowIndex][0].mAngle < 0xc000) {
            rowInFront = 1;
        } else {
            rowInFront = 0;
        }
        if (facingForward ^ rowInFront) {
            for (elementIndex = 0; elementIndex < fireball2->mRowElementCount; elementIndex++) {
                gxParam = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
                NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&fireball2->mElements[rowIndex][elementIndex].mPos),
                                    0xc);
                if (fireball2->mElements[rowIndex][elementIndex].mRotationAngle != 0) {
                    MTX_RotZ33_(&elementRotation,
                                FX_SinIdx(fireball2->mElements[rowIndex][elementIndex].mRotationAngle),
                                FX_CosIdx(fireball2->mElements[rowIndex][elementIndex].mRotationAngle));
                    NNS_G3dGeBufferOP_N(0x1a, &elementRotation, 9);
                }
                NNS_G3dGeBufferOP_N(0x1b, &fireball2->mMapObject.mScale, 3);
                SetMapObjectModelPolygonId(gFireball2, AllocPolygonIdWrapping());
                DrawMapObjectModel(mapObjectList, gFireball2, fireball2);
            }
        }
    }
    if (fireball2->mRowElementCount > 1) {
        centerGxParam = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &centerGxParam, 1);
        NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&fireball2->mCenterPos), 0xc);
        if (fireball2->mCenterRotationAngle != 0) {
            MTX_RotZ33_(&centerRotation, FX_SinIdx(fireball2->mCenterRotationAngle),
                        FX_CosIdx(fireball2->mCenterRotationAngle));
            NNS_G3dGeBufferOP_N(0x1a, &centerRotation, 9);
        }
        NNS_G3dGeBufferOP_N(0x1b, &fireball2->mMapObject.mScale, 3);
        SetMapObjectModelPolygonId(gFireball2, AllocPolygonIdWrapping());
        DrawMapObjectModel(mapObjectList, gFireball2, fireball2);
    }
    for (rowIndex = 0; rowIndex < fireball2->mRowCount; rowIndex++) {
        if (cameraDot >= 0) {
            facingForward = 1;
        } else {
            facingForward = 0;
        }
        if (fireball2->mElements[rowIndex][0].mAngle >= 0x4000 && fireball2->mElements[rowIndex][0].mAngle < 0xc000) {
            rowInFront = 1;
        } else {
            rowInFront = 0;
        }
        if ((facingForward ^ rowInFront) == 0) {
            for (elementIndex = fireball2->mRowElementCount - 1; elementIndex >= 0; elementIndex--) {
                reverseGxParam = 0x1e;
                NNS_G3dGeBufferOP_N(0x14, &reverseGxParam, 1);
                NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&fireball2->mElements[rowIndex][elementIndex].mPos),
                                    0xc);
                if (fireball2->mElements[rowIndex][elementIndex].mRotationAngle != 0) {
                    MTX_RotZ33_(&reverseRotation,
                                FX_SinIdx(fireball2->mElements[rowIndex][elementIndex].mRotationAngle),
                                FX_CosIdx(fireball2->mElements[rowIndex][elementIndex].mRotationAngle));
                    NNS_G3dGeBufferOP_N(0x1a, &reverseRotation, 9);
                }
                NNS_G3dGeBufferOP_N(0x1b, &fireball2->mMapObject.mScale, 3);
                SetMapObjectModelPolygonId(gFireball2, AllocPolygonIdWrapping());
                DrawMapObjectModel(mapObjectList, gFireball2, fireball2);
            }
        }
    }
}

void InitFireball2Objects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    s32 elementIndex;
    s32 rowIndex;
    s16 radiusSetting;
    float radius;
    u64 randomBits;
    Fireball2 *fireball2;
    RandomState64 *mapObjectRandom;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (fireball2 = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        radiusSetting = fireball2->mMapObject.mCourseMapRow->mSettings[1];
        if (radiusSetting > 0) {
            radius = 0.5f + TO_FIXED12(radiusSetting);
        } else {
            radius = TO_FIXED12(radiusSetting) - 0.5f;
        }
        fireball2->mRadius = radius;
        fireball2->mRowAnglePerFrame = (fireball2->mMapObject.mCourseMapRow->mSettings[2] * 0x16c) / 100;
        fireball2->mRowAngleSpacing = 0x10000 / fireball2->mRowCount;
        fireball2->mElementRadiusSpacing = fireball2->mRadius / fireball2->mRowElementCount;
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        randomBits = mapObjectRandom->mValue >> 32;
        fireball2->mCenterRotationAngle = (randomBits * 0x10000) >> 32;
        for (elementIndex = 0; elementIndex < fireball2->mRowElementCount; elementIndex++) {
            for (rowIndex = 0; rowIndex < fireball2->mRowCount; rowIndex++) {
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                randomBits = mapObjectRandom->mValue >> 32;
                fireball2->mElements[rowIndex][elementIndex].mRotationAngle = (randomBits * 0x10000) >> 32;
            }
        }
    }
}

void UpdateFireball2(void *mapObjectList, Fireball2 *fireball2) {
    s32 index;
    s32 rowIndex;
    s32 ringRadius;
    s32 axisDistance;
    u16 angle;
    Kart *kart;
    NNSSndSeqPlayer **sndHandleSlot;
    Vec3 kartOffset;

    ringRadius = fireball2->mRadius;
    fireball2->mCenterPos = fireball2->mMapObject.mPos;
    if (fireball2->mRowElementCount == 1) {
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        if (IsKartWithinFireball2Range(kart, fireball2, ringRadius - 0xf000) != FALSE) {
            VEC_Subtract(&kart->mPos, &fireball2->mMapObject.mPos, &kartOffset);
            axisDistance = Vec3DotUnrounded(&kartOffset, &fireball2->mMapObject.mMatrix.mRows[2]);
            if ((fireball2->mEntryKartAxisDistance < 0 && axisDistance > 0) ||
                (fireball2->mEntryKartAxisDistance > 0 && axisDistance < 0)) {
                StopSndHandleSlots7To11();
                sndHandleSlot = GetSndHandleSlot(7);
                if ((gRaceSoundKind & 1) && gSoundModeHolder.mSeqStartEnabled != 0) {
                    if (sndHandleSlot[0] != NULL) {
                        NNS_SndPlayerStopSeq(sndHandleSlot, 0);
                    }
                    if (sndHandleSlot[0] != NULL) {
                        NNS_SndPlayerStopSeq(sndHandleSlot, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x1c2);
                }
                fireball2->mEntryKartAxisDistance = 0;
            } else {
                fireball2->mEntryKartAxisDistance = axisDistance;
            }
        } else {
            fireball2->mEntryKartAxisDistance = 0;
        }
    }
    if (fireball2->mRowElementCount > 1) {
        fireball2->mCenterRotationAngle = fireball2->mCenterRotationAngle + 0x51e;
    }
    for (index = 0; index < fireball2->mRowElementCount; index++) {
        angle = fireball2->mRowAngle;
        for (rowIndex = 0; rowIndex < fireball2->mRowCount; rowIndex++) {
            angle = angle + fireball2->mRowAngleSpacing;
            fireball2->mElements[rowIndex][index].mAngle = angle;
            VEC_MultAdd(MUL_FIXED12_NO_ROUND(ringRadius, FX_CosIdx(angle)), &fireball2->mMapObject.mMatrix.mRows[0],
                        &fireball2->mMapObject.mPos, &fireball2->mElements[rowIndex][index].mPos);
            VEC_MultAdd(MUL_FIXED12_NO_ROUND(ringRadius, FX_SinIdx(angle)), &fireball2->mMapObject.mMatrix.mRows[1],
                        &fireball2->mElements[rowIndex][index].mPos, &fireball2->mElements[rowIndex][index].mPos);
            fireball2->mElements[rowIndex][index].mRotationAngle =
                fireball2->mElements[rowIndex][index].mRotationAngle + 0x51e;
        }
        ringRadius = ringRadius - fireball2->mElementRadiusSpacing;
    }
    fireball2->mRowAngle = fireball2->mRowAngle - fireball2->mRowAnglePerFrame;
    for (index = 0; index < gRaceSetup->mKartCount; index++) {
        if (fireball2->mKartHitTimers[index] > 0) {
            fireball2->mKartHitTimers[index] = fireball2->mKartHitTimers[index] - 1;
        }
    }
    StartMapObjectSoundWhileRequested(&fireball2->mMapObject, 0x160);
}

MapObjectKindData *CreateFireball2KindData(void) {
    return CreateMapObjectKindDataWithSound(CollideKartWithFireball2, NULL, IsPosNearFireball2, 0, 0, 0x18d);
}

MapObjectList *CreateFireball2DrawList(void) {
    return CreateMapObjectDrawList2(CreateFireball2, DrawFireball2, SetupDrawFireball2);
}

MapObjectList *CreateFireball2UpdateList(void) {
    return CreateMapObjectUpdateList(InitFireball2Objects, UpdateFireball2, NULL);
}
