#include "Main/MapObjects/basabasa.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"

#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Course/course_map_group_entry.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "code_02147cd8.h"

MapObjectModel *gBasabasa;

MapObjectKindDescriptor gBasabasaKindDescriptor = {0,
                                                   {0, 0},
                                                   0xd8,
                                                   InitBasabasa,
                                                   CreateBasabasaKindData,
                                                   CreateBasabasaDrawList,
                                                   0,
                                                   0,
                                                   CreateBasabasaUpdateList};

void InitBasabasa(MapObject *mapObject) {
    MapObject *mapObjectArg = mapObject;
    MapObject *mapObjectCopy;
    mapObjectCopy = mapObjectArg;
    ParkMapObject(mapObjectArg);
    mapObjectArg = mapObjectCopy;
    CreateMapObjectSoundSourceFalloff2(mapObjectArg);
}

u8 CollideKartWithBasabasa(Basabasa *basabasa, Kart *kart, void *unusedFirstResponse, u8 *inOutResult) {
    Vec3 sideDirection;
    Vec3 offsetToKart;
    s32 forwardDot;
    s32 sideX;
    s32 sideZ;
    u8 result;
    u8 kartBit;
    s64 lengthSquared;

    kartBit = 1 << kart->mIndex;
    result = *inOutResult;
    if ((basabasa->mHitKartMask & kartBit) == 0) {
        VEC_Subtract(&kart->mPos, &basabasa->mMapObject.mPos, &offsetToKart);
        forwardDot = DOT2_FIXED12(basabasa->mMapObject.mMatrix.mRows[2].x, offsetToKart.x,
                                  basabasa->mMapObject.mMatrix.mRows[2].z, offsetToKart.z);
        sideX = offsetToKart.x - MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].x, forwardDot);
        sideZ = offsetToKart.z - MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].z, forwardDot);
        lengthSquared = SQUARE_SUM3(sideX, sideDirection.y, sideZ);
        sideDirection.x = sideX;
        sideDirection.z = sideZ;
        if (lengthSquared < 0x10) {
            basabasa->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].x, 0x1333);
            basabasa->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].y, 0x1333);
            basabasa->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].z, 0x1333);
        } else {
            Vec3NormalizeAndGetLengthUnchecked(&sideDirection, &sideDirection);
            basabasa->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(sideDirection.x, 0x1333);
            basabasa->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(sideDirection.y, 0x1333);
            basabasa->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(sideDirection.z, 0x1333);
        }
        basabasa->mHitKartMask |= kartBit;
    }
    return result;
}

void CreateBasabasa(void *mapObjectList) {
    gBasabasa = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "basabasa.nsbmd", "basabasa.nsbtp");
    SetMapObjectModelPolygonId(gBasabasa, 0x3f);
}

void SetupDrawBasabasa(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gBasabasa);
}

void DrawBasabasa(void *mapObjectList, Basabasa *basabasa) {
    s32 gxParam;
    MtxFx33 rotationMatrix;
    s32 drawAngle;

    drawAngle = BASABASA_DRAW_ANGLE_OFFSET_LIMIT - basabasa->mDrawAngleOffset;
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&basabasa->mMapObject.mPos), 0xc);
    if (basabasa->mRotateZNegated != 0) {
        MTX_RotZ33_(&rotationMatrix, FX_SinIdx((u16) -drawAngle), FX_CosIdx((u16) -drawAngle));
    } else {
        MTX_RotZ33_(&rotationMatrix, FX_SinIdx((u16) drawAngle), FX_CosIdx((u16) drawAngle));
    }
    NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1b, &basabasa->mMapObject.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gBasabasa, basabasa->mNsbtpFrameIndex);
    DrawMapObjectModel(mapObjectList, gBasabasa, basabasa);
}

void UpdateBasabasa(void *mapObjectList, Basabasa *basabasa) {
    s32 nextFrameIndex;

    basabasa->mDrawAngleOffset += basabasa->mDrawAngleOffsetPerFrame;
    basabasa->mDrawAngleOffsetPerFrame += BASABASA_DRAW_ANGLE_SPEED_STEP;
    if (basabasa->mDrawAngleOffset == 0) {
        basabasa->mDrawAngleOffset += basabasa->mDrawAngleOffsetPerFrame;
        basabasa->mDrawAngleOffsetPerFrame += BASABASA_DRAW_ANGLE_SPEED_STEP;
    } else if (basabasa->mDrawAngleOffset >= BASABASA_DRAW_ANGLE_OFFSET_LIMIT) {
        basabasa->mDrawAngleOffsetPerFrame = BASABASA_DRAW_ANGLE_SPEED_STEP - basabasa->mDrawAngleOffsetPerFrame;
        basabasa->mRotateZNegated = basabasa->mRotateZNegated == 0;
    }
    switch (basabasa->mState) {
        case BASABASA_STATE_FALL:
            if (basabasa->mDelayTimer-- > 0) {
                break;
            }
            basabasa->mMapObject.mFlags &= ~1;
            basabasa->mMapObject.mFlags &= ~2;
            basabasa->mMapObject.mFlags &= ~8;
            basabasa->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
            basabasa->mVelocity.x += MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].x, 0x19a);
            basabasa->mVelocity.y += -0x19a;
            basabasa->mVelocity.z += MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].z, 0x19a);
            VEC_Add(&basabasa->mMapObject.mPos, &basabasa->mVelocity, &basabasa->mMapObject.mPos);
            if (basabasa->mFallTimer-- <= 0) {
                basabasa->mState = BASABASA_STATE_SLOW_FALL;
            }
            break;
        case BASABASA_STATE_SLOW_FALL:
            basabasa->mVelocity.x += MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].x, 0x19a);
            basabasa->mVelocity.y += 0x19a;
            basabasa->mVelocity.z += MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].z, 0x19a);
            VEC_Add(&basabasa->mMapObject.mPos, &basabasa->mVelocity, &basabasa->mMapObject.mPos);
            if (basabasa->mVelocity.y > 0) {
                basabasa->mVelocity.y = 0;
                basabasa->mState = BASABASA_STATE_GLIDE;
            }
            break;
        case BASABASA_STATE_GLIDE:
            VEC_Add(&basabasa->mMapObject.mPos, &basabasa->mVelocity, &basabasa->mMapObject.mPos);
            if (basabasa->mGlideTimer-- <= 0) {
                basabasa->mState = BASABASA_STATE_CLIMB;
            }
            break;
        case BASABASA_STATE_CLIMB:
            basabasa->mVelocity.x -= MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].x, 0xcd);
            basabasa->mVelocity.y += 0x1000;
            basabasa->mVelocity.z -= MUL_FIXED12_NO_ROUND(basabasa->mMapObject.mMatrix.mRows[2].z, 0xcd);
            VEC_Add(&basabasa->mMapObject.mPos, &basabasa->mVelocity, &basabasa->mMapObject.mPos);
            if (basabasa->mMapObject.mPos.y >= 0x1b8000) {
                ParkMapObject(&basabasa->mMapObject);
            }
            break;
    }
    if (basabasa->mDelayTimer > 0) {
        return;
    }
    nextFrameIndex = basabasa->mNsbtpFrameIndex + 1;
    if (nextFrameIndex >= GetMapObjectModelNsbtpFrameCount(gBasabasa)) {
        nextFrameIndex = 0;
    }
    basabasa->mNsbtpFrameIndex = nextFrameIndex;
    if (basabasa->mSoundRequested == 0) {
        return;
    }
    StartMapObjectSoundWhileRequested(&basabasa->mMapObject, 0x165);
}

MapObjectKindData *CreateBasabasaKindData(void) {
    return CreateMapObjectKindData(&CollideKartWithBasabasa, NULL, NULL, 1, 0);
}

static inline u16 BasabasaMapObjectRandomBelowU16(u32 limit) {
    RandomState64 *mapObjectRandom;
    u32 limitU16;
    u32 value;

    if (limit == 0x10000) {
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        return ((mapObjectRandom->mValue >> 32) * 0x10000) >> 32;
    } else {
        mapObjectRandom = GetMapObjectRandom();
        limitU16 = (u16) limit;
        if (limitU16 == 0) {
            value = 0;
        } else {
            mapObjectRandom->mValue =
                mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            if (limitU16 == 0) {
                value = mapObjectRandom->mValue >> 32;
            } else {
                value = ((mapObjectRandom->mValue >> 32) * limitU16) >> 32;
            }
        }
    }
    return value;
}

MapObjectList *CreateBasabasaDrawList(void) {
    return CreateMapObjectDrawList2(CreateBasabasa, DrawBasabasa, SetupDrawBasabasa);
}

MapObjectList *CreateBasabasaUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateBasabasa, NULL);
}

void StartBasabasa(u32 glideTimerBase, const Vec3 *startPos, const Vec3 *velocity, u32 fallTimerBase,
                   s32 soundRequested, u16 subScreenCellKind) {
    Basabasa *basabasa;
    RandomState64 *mapObjectRandom;
    u32 timerRange;
    u16 randomOffset;

    basabasa = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BASABASA));
    if (basabasa == NULL) {
        return;
    }
    basabasa->mMapObject.mFlags |= gBasabasaDisabledFlag;
    basabasa->mMapObject.mFlags |= gBasabasaSkipViewTestFlag;
    basabasa->mMapObject.mFlags |= gBasabasaSkipListCallbackFlag;
    basabasa->mSoundRequested = soundRequested;
    basabasa->mRaceHudSubScreenCellKind = subScreenCellKind;
    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    basabasa->mDelayTimer = (u16) (((mapObjectRandom->mValue >> 32) * 30) >> 32);
    timerRange = TO_FIXED12(fallTimerBase) >> 16;
    randomOffset = BasabasaMapObjectRandomBelowU16(timerRange);
    basabasa->mFallTimer = fallTimerBase + randomOffset;
    timerRange = TO_FIXED12(glideTimerBase) >> 16;
    randomOffset = BasabasaMapObjectRandomBelowU16(timerRange);
    basabasa->mGlideTimer = glideTimerBase + randomOffset;
    basabasa->mMapObject.mPos = *startPos;
    basabasa->mVelocity = *velocity;
    basabasa->mState = BASABASA_STATE_FALL;
    basabasa->mHitKartMask = 0;
}

const u16 gBasabasaSkipListCallbackFlag = 8;
const u16 gBasabasaSkipViewTestFlag = 2;
const u16 gBasabasaDisabledFlag = 1;
