#include "Main/MapObjects/fireball2.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/picture_puddle.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Sound/sound_handle_slots_and_other_kart_falloff.h"
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Menu/keyboard_char_tables.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "fixed_vector_math.h"
#include "sound_archive_load_result.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/puddle_kind_data.h"

MapObjectKindDescriptor gFireball2KindDescriptor = {0,
                                             {0, 0},
                                             0x19e8,
                                             InitFireball2,
                                             CreateFireball2KindData,
                                             CreateFireball2DrawList,
                                             0,
                                             0,
                                             CreateFireball2UpdateList};
MapObjectModel *gFireball2;

const u16 gSunFireballInitMapObjectFlag = 0x200;
const u32 gFireball2SkipSoundFlag = 0x40000000;
MapObjectList *CreatePuddleDrawList(void) {
    return CreateMapObjectDrawList2(CreatePuddle, DrawPuddle, SetupDrawPuddle);
}

void InitFireball2(Fireball2 *fireball2) {
    fireball2->mMapObject.mFlags |= gFireball2InitMapObjectFlag;
    fireball2->mRowCount = fireball2->mMapObject.mCourseMapRow->mSettings[0];
    fireball2->mRowElementCount = fireball2->mMapObject.mCourseMapRow->mSettings[3] + 1;
    CreateMapObjectSoundSourceFalloff2(&fireball2->mMapObject);
    fireball2->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
    fireball2->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_NO_VIEW_TEST;
    fireball2->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_SKIP_LIST_CALLBACK;
    fireball2->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
}

u8 CollideKartWithFireball2(Fireball2 *fireball2, Kart *kart, u8 *firstResponse, u8 *response) {
    u8 responseValue;

    responseValue = *response;
    if (fireball2->mKartHitTimers[kart->mIndex] == 0) {
        if (kart->mItemEffect == KART_ITEM_EFFECT_STAR || kart->mItemEffect == KART_ITEM_EFFECT_KILLER) {
            fireball2->mMapObject.mDistanceSquaredAndFlags |= gFireball2SkipSoundFlag;
        }
        StartSoundIfKartStarOrKiller(&fireball2->mMapObject, kart);
    }
    fireball2->mKartHitTimers[kart->mIndex] = FIREBALL2_KART_HIT_FRAMES;
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
    return SQUARE_SUM3(deltaX, deltaY, deltaZ) < (s64) radius * radius;
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
        if (SQUARE_SUM3(deltaX, deltaY, deltaZ) <
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
        if (fireball2->mElements[rowIndex][0].mAngle >= ANGLE_QUARTER_TURN &&
            fireball2->mElements[rowIndex][0].mAngle < ANGLE_MINUS_QUARTER_TURN) {
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
        if (fireball2->mElements[rowIndex][0].mAngle >= ANGLE_QUARTER_TURN &&
            fireball2->mElements[rowIndex][0].mAngle < ANGLE_MINUS_QUARTER_TURN) {
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
        fireball2->mRowAngleSpacing = ANGLE_FULL_TURN / fireball2->mRowCount;
        fireball2->mElementRadiusSpacing = fireball2->mRadius / fireball2->mRowElementCount;
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        randomBits = mapObjectRandom->mValue >> 32;
        fireball2->mCenterRotationAngle = (randomBits * ANGLE_FULL_TURN) >> 32;
        for (elementIndex = 0; elementIndex < fireball2->mRowElementCount; elementIndex++) {
            for (rowIndex = 0; rowIndex < fireball2->mRowCount; rowIndex++) {
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                randomBits = mapObjectRandom->mValue >> 32;
                fireball2->mElements[rowIndex][elementIndex].mRotationAngle = (randomBits * ANGLE_FULL_TURN) >> 32;
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
