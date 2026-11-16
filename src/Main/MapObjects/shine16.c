#include "Main/MapObjects/shine16.h"

#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/balloon.h"
#include "Main/MapObjects/balloon_velocity.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/trophy.h"
#include "Main/MapObjects/balloon_target.h"
#include "Main/MapObjects/balloon_draw.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Kart/camera.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/MapObjects/bound.h"
#include "Main/Kart/kart_effects.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/balloon_park.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/map_object_sound_starts_and_queues.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/shine_battle.h"
#include "fixed_vector_math.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/MapObjects/woodbox.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "ITCM/sphere_collision.h"
#include "Main/Sound/shine16_track_params.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Menu/keyboard_char_tables.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

MapObjectKindDescriptor gShine16KindDescriptor = {0,
                                             {0, 0},
                                             0xec,
                                             InitShine16,
                                             CreateShine16KindData,
                                             CreateShine16DrawList,
                                             CreateShine16ShadowDrawList,
                                             0,
                                             CreateShine16UpdateList};
u16 gShine16ShadowAngleIndex;
MapObjectModel *gShine16;

const u16 gShine16ShadowAngles[4] = {0, 0xe38, 0x1c71, 0};
void InitShine16(MapObject *mapObject) {
    ParkMapObject(mapObject);
    mapObject->mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(SoundSource));
    InitSoundSource(&mapObject->mSound->mSoundSource, 0xb, &mapObject->mPos);
    SetShine16TrackParamsNop(&mapObject->mSound->mSoundSource);
    mapObject->mFarDistanceSquared = gSoundFalloffs[0xb].mFarDistanceSquared;
}

u32 CollideKartWithShine16(Shine16 *shine16, Kart *kart, u8 *firstResponse, u8 *response) {
    u8 firstResponseValue;
    u8 responseValue;
    s32 isEntryKart;
    u16 highestBalloonOrShineCount;
    s32 balloonOrShineCount;

    firstResponseValue = *firstResponse;
    responseValue = *response;
    if (kart->mState != KART_STATE_NORMAL || (kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) != 0 ||
        IsKartEliminated(kart->mIndex) != FALSE) {
        return 0;
    }
    if (firstResponseValue == 1) {
        if ((kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) != 0) {
            return responseValue;
        }
        if (shine16->mPickupTimer > 0) {
            return responseValue;
        }
        shine16->mMapObject.mFlags |= gShine16HitFlag;
        shine16->mPickupTimer = SHINE16_PICKUP_FRAMES;
        shine16->mMapObject.mPos.x = kart->mPos.x;
        shine16->mMapObject.mPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) + 0x7800;
        shine16->mMapObject.mPos.z = kart->mPos.z;
        shine16->mHeightAboveKart = 0;
        shine16->mMapObject.mPosStep.x = 0;
        shine16->mMapObject.mPosStep.y = 0x3000;
        shine16->mMapObject.mPosStep.z = 0;
        shine16->mDrawScale = 0;
        shine16->mState = SHINE16_STATE_COLLECTED_BY_KART;
        shine16->mKartIndex = kart->mIndex;
        shine16->mHitByKartIndex = kart->mIndex;
        AddBalloonsLeftToMake(kart->mIndex, 1);
        AddBalloonOrShineCountAndMoveRank(kart->mIndex, 1);
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex ? 1 : 0;
        highestBalloonOrShineCount = GetHighestBalloonOrShineCount();
        balloonOrShineCount = GetBalloonOrShineCount(kart->mIndex);
        QueueShine16Sound(shine16->mMapObject.mSound,
                          GetShine16SoundId(0, isEntryKart, highestBalloonOrShineCount, balloonOrShineCount));
        shine16->mEffect = StartEffect(0x7d, &shine16->mMapObject.mPos);
        shine16->mEffectTimer = SHINE16_EFFECT_FRAMES;
    }
    return responseValue;
}

void CreateShine16(void *mapObjectList) {
    gShine16 = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "shine16.nsbmd", "shine16.nsbtp");
    SetMapObjectModelPolygonId(gShine16, 0x3f);
}

void SetupDrawShine16(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gShine16);
}

void DrawShine16(void *mapObjectList, Shine16 *shine16) {
    s32 gxParam;
    Vec3 scaleVector;
    s32 drawScale;

    if (shine16->mDrawScale <= 0) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&shine16->mMapObject.mPos), 0xc);
    drawScale = shine16->mDrawScale;
    if (drawScale != SHINE16_DRAW_SCALE_FULL) {
        scaleVector.x = drawScale;
        scaleVector.y = drawScale;
        scaleVector.z = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, &scaleVector, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &shine16->mMapObject.mScale, 3);
    SetMapObjectModelMirror(gShine16, shine16->mMirror, 0);
    SetMapObjectModelNsbtpFrameIndex(gShine16, shine16->mNsbtpFrameIndex);
    DrawMapObjectModel(mapObjectList, gShine16, shine16);
}

u16 *ResetShine16ShadowAngleIndex(void) {
    gShine16ShadowAngleIndex = 0;
    return &gShine16ShadowAngleIndex;
}

void AdvanceShine16ShadowAngleIndex(void) {
    s32 nextAngleIndex;

    nextAngleIndex = gShine16ShadowAngleIndex + 1;
    if (nextAngleIndex >= 3) {
        nextAngleIndex = 0;
    }
    gShine16ShadowAngleIndex = nextAngleIndex;
}

void DrawShine16Shadow(void *mapObjectList, Shine16 *shine16, void *unused, s32 maxAlpha) {
    s32 gxParam;
    MtxFx33 rotateYMatrix;
    Vec3 drawScaleVector;
    Vec3 shadowScaleVector;
    s32 drawScale;

    if (shine16->mDrawScale <= 0) {
        return;
    }
    if (shine16->mState == SHINE16_STATE_COLLECTED_BY_KART) {
        return;
    }
    if (shine16->mState == SHINE16_STATE_RISING_FROM_KART) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&shine16->mMapObject.mPos), 0xc);
    drawScale = shine16->mDrawScale;
    if (drawScale < SHINE16_DRAW_SCALE_FULL) {
        drawScaleVector.x = drawScale;
        drawScaleVector.y = drawScale;
        drawScaleVector.z = drawScale;
        NNS_G3dGeBufferOP_N(0x1b, &drawScaleVector, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &shine16->mMapObject.mScale, 3);
    MTX_RotY33_(&rotateYMatrix, COS_OF_ANGLE(gShine16ShadowAngles[gShine16ShadowAngleIndex]),
                SIN_OF_ANGLE(gShine16ShadowAngles[gShine16ShadowAngleIndex]));
    NNS_G3dGeBufferOP_N(0x1a, &rotateYMatrix, 9);
    shadowScaleVector.x = 0x2000;
    shadowScaleVector.y = 0x2000;
    shadowScaleVector.z = 0x2000;
    NNS_G3dGeBufferOP_N(0x1b, &shadowScaleVector, 3);
    DrawJgShadow(8, maxAlpha);
}

void UpdateShine16(void *mapObjectList, Shine16 *shine16) {
    Vec3 probePos;
    Vec3 pushOut;
    Vec3 firstNormal;
    Vec3 secondNormal;
    u32 hitFlags;
    Kart *kart;
    s32 battlePointIndex;
    CourseMapPoint *forwardBattlePoint;
    s32 distance;
    s32 deltaX;
    s32 deltaZ;
    s32 savedVelocityY;
    u16 randomAngle;
    s32 randomRadius;
    RandomState64 *randomState;

    switch (shine16->mState) {
        case SHINE16_STATE_DROPPING:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= SHINE16_NSBTP_FRAME_STEP_LIMIT) {
                shine16->mNsbtpFrameStepProgress -= SHINE16_NSBTP_FRAME_STEP_LIMIT;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= SHINE16_NSBTP_MIRROR_FRAMES) {
                    shine16->mNsbtpFramesSinceMirror -= SHINE16_NSBTP_MIRROR_FRAMES;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += SHINE16_DRAW_SCALE_STEP;
            if (shine16->mDrawScale >= SHINE16_DRAW_SCALE_FULL) {
                shine16->mDrawScale = SHINE16_DRAW_SCALE_FULL;
            }
            shine16->mMapObject.mPosStep.y -= 0x19a;
            VEC_Add(&shine16->mMapObject.mPos, &shine16->mMapObject.mPosStep, &shine16->mMapObject.mPos);
            if (shine16->mMapObject.mPos.y > shine16->mFloorY) {
                return;
            }
            shine16->mMapObject.mPos.y = shine16->mFloorY;
            shine16->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.y, -0x333);
            if (shine16->mMapObject.mPosStep.y < 0x1000) {
                shine16->mMapObject.mPosStep.y = 0;
                shine16->mState = SHINE16_STATE_RESTING;
            }
            QueueShine16Sound(shine16->mMapObject.mSound, SHINE16_SOUND_BASE + SHINE16_SOUND_BOUNCED);
            return;
        case SHINE16_STATE_RESTING:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= SHINE16_NSBTP_FRAME_STEP_LIMIT) {
                shine16->mNsbtpFrameStepProgress -= SHINE16_NSBTP_FRAME_STEP_LIMIT;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= SHINE16_NSBTP_MIRROR_FRAMES) {
                    shine16->mNsbtpFramesSinceMirror -= SHINE16_NSBTP_MIRROR_FRAMES;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += SHINE16_DRAW_SCALE_STEP;
            if (shine16->mDrawScale >= SHINE16_DRAW_SCALE_FULL) {
                shine16->mDrawScale = SHINE16_DRAW_SCALE_FULL;
            }
            QueueShine16SoundWhileRequested(shine16->mMapObject.mSound, 0x14e);
            return;
        case SHINE16_STATE_SHRINKING:
            shine16->mNsbtpFrameStepProgress += 4;
            if (shine16->mNsbtpFrameStepProgress >= SHINE16_NSBTP_FRAME_STEP_LIMIT) {
                shine16->mNsbtpFrameStepProgress -= SHINE16_NSBTP_FRAME_STEP_LIMIT;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= SHINE16_NSBTP_MIRROR_FRAMES) {
                    shine16->mNsbtpFramesSinceMirror -= SHINE16_NSBTP_MIRROR_FRAMES;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale -= SHINE16_DRAW_SCALE_STEP;
            if (shine16->mDrawScale > 0) {
                return;
            }
            shine16->mDrawScale = 0;
            ParkMapObject(&shine16->mMapObject);
            AddShineCount(-1);
            if (shine16->mSpawnObjectIndex < 0) {
                return;
            }
            ClearShineBattleObjectShine(shine16->mSpawnObjectIndex);
            return;
        case SHINE16_STATE_COLLECTED_BY_KART:
            shine16->mNsbtpFrameStepProgress += 4;
            if (shine16->mNsbtpFrameStepProgress >= SHINE16_NSBTP_FRAME_STEP_LIMIT) {
                shine16->mNsbtpFrameStepProgress -= SHINE16_NSBTP_FRAME_STEP_LIMIT;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= SHINE16_NSBTP_MIRROR_FRAMES) {
                    shine16->mNsbtpFramesSinceMirror -= SHINE16_NSBTP_MIRROR_FRAMES;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            kart = GetKart(shine16->mKartIndex);
            shine16->mHeightAboveKart += shine16->mMapObject.mPosStep.y;
            shine16->mMapObject.mPos = *GetKartStandingPos(shine16->mKartIndex);
            shine16->mMapObject.mPos.y += shine16->mHeightAboveKart + (GetKartBalloonOrShineHeight(kart) + 0x7800);
            shine16->mMapObject.mPosStep.y -= 0x333;
            if (shine16->mPickupTimer-- <= 0) {
                shine16->mPickupTimer = 0;
                shine16->mDrawScale -= SHINE16_DRAW_SCALE_STEP;
                if (shine16->mDrawScale <= 0) {
                    shine16->mDrawScale = 0;
                    ParkMapObject(&shine16->mMapObject);
                    AddShineCount(-1);
                    if (shine16->mSpawnObjectIndex >= 0) {
                        ClearShineBattleObjectShine(shine16->mSpawnObjectIndex);
                    }
                }
                if (shine16->mDrawScale <= 0) {
                    SetupKartFollowEffect(StartEffect(0x7c, &kart->mPos), kart->mIndex, 0x16);
                }
            } else {
                shine16->mDrawScale += SHINE16_DRAW_SCALE_STEP;
                if (shine16->mDrawScale >= SHINE16_DRAW_SCALE_FULL) {
                    shine16->mDrawScale = SHINE16_DRAW_SCALE_FULL;
                }
            }
            if (shine16->mEffect == NULL) {
                return;
            }
            PlaceEffect(shine16->mEffect, &shine16->mMapObject.mPos);
            shine16->mEffectTimer--;
            if (shine16->mEffectTimer >= 0) {
                return;
            }
            StopEffectAndClearPointer(&shine16->mEffect);
            return;
        case SHINE16_STATE_RISING_FROM_KART:
            shine16->mNsbtpFrameStepProgress += 4;
            if (shine16->mNsbtpFrameStepProgress >= SHINE16_NSBTP_FRAME_STEP_LIMIT) {
                shine16->mNsbtpFrameStepProgress -= SHINE16_NSBTP_FRAME_STEP_LIMIT;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= SHINE16_NSBTP_MIRROR_FRAMES) {
                    shine16->mNsbtpFramesSinceMirror -= SHINE16_NSBTP_MIRROR_FRAMES;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            for (battlePointIndex = 0; battlePointIndex < 2; battlePointIndex++) {
                forwardBattlePoint = MoveToRandomForwardBattlePoint();
                distance = forwardBattlePoint->mPos.y - GetKartStandingPos(shine16->mKartIndex)->y;
                if (distance <= 0) {
                    distance = -distance;
                }
                if (distance < 0x14000) {
                    deltaX = FROM_FIXED12(forwardBattlePoint->mPos.x - GetKartStandingPos(shine16->mHitByKartIndex)->x);
                    deltaZ = FROM_FIXED12(forwardBattlePoint->mPos.z - GetKartStandingPos(shine16->mHitByKartIndex)->z);
                    distance = deltaX * deltaX + deltaZ * deltaZ;
                    if (shine16->mHitByKartIndex == shine16->mKartIndex) {
                        if (distance < SHINE16_TARGET_DISTANCE_LIMIT_SQUARED &&
                            distance > shine16->mTargetDistanceSquared) {
                            shine16->mTargetDistanceSquared = distance;
                            shine16->mTargetPos.x = forwardBattlePoint->mPos.x;
                            shine16->mTargetPos.y = forwardBattlePoint->mPos.y;
                            shine16->mTargetPos.z = forwardBattlePoint->mPos.z;
                            shine16->mTargetPickCount++;
                        }
                    } else {
                        if (distance < SHINE16_TARGET_DISTANCE_LIMIT_SQUARED &&
                            distance < shine16->mTargetDistanceSquared) {
                            shine16->mTargetDistanceSquared = distance;
                            shine16->mTargetPos.x = forwardBattlePoint->mPos.x;
                            shine16->mTargetPos.y = forwardBattlePoint->mPos.y;
                            shine16->mTargetPos.z = forwardBattlePoint->mPos.z;
                            shine16->mTargetPickCount++;
                        }
                    }
                }
            }
            shine16->mHeightAboveKart += shine16->mMapObject.mPosStep.y;
            shine16->mMapObject.mPos = *GetKartStandingPos(shine16->mKartIndex);
            shine16->mMapObject.mPos.y +=
                shine16->mHeightAboveKart + (GetKartBalloonOrShineHeight(GetKart(shine16->mKartIndex)) + 0x7800);
            shine16->mMapObject.mPosStep.y -= 0x52;
            shine16->mDrawScale += SHINE16_DRAW_SCALE_STEP;
            if (shine16->mDrawScale >= SHINE16_DRAW_SCALE_FULL) {
                shine16->mDrawScale = SHINE16_DRAW_SCALE_FULL;
            }
            if (shine16->mMapObject.mPosStep.y > 0) {
                return;
            }
            if (shine16->mTargetPickCount > 0) {
                randomState = &gRaceProgress->mRandom;
                randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                randomAngle = RANDOM_BELOW_U64(randomState, ANGLE_FULL_TURN);
                randomState = &gRaceProgress->mRandom;
                randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                randomRadius = RANDOM_BELOW_U64(randomState, 0x14000);
                deltaX = shine16->mTargetPos.x + MUL_FIXED12_NO_ROUND(randomRadius, FX_SinIdx(randomAngle)) -
                         shine16->mMapObject.mPos.x;
                deltaZ = shine16->mTargetPos.z + MUL_FIXED12_NO_ROUND(randomRadius, FX_CosIdx(randomAngle)) -
                         shine16->mMapObject.mPos.z;
                shine16->mState = SHINE16_STATE_FLYING_TO_TARGET;
                shine16->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(deltaX, 0x25);
                shine16->mMapObject.mPosStep.y = 0x5000;
                shine16->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(deltaZ, 0x25);
                shine16->mDrawScale = SHINE16_DRAW_SCALE_FULL;
                shine16->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
                return;
            }
            shine16->mState = SHINE16_STATE_LAUNCHED_UP;
            shine16->mMapObject.mPosStep.x = 0;
            shine16->mMapObject.mPosStep.y = 0x5000;
            shine16->mMapObject.mPosStep.z = 0;
            shine16->mDrawScale = SHINE16_DRAW_SCALE_FULL;
            shine16->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
            return;
        case SHINE16_STATE_LAUNCHED_UP:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= SHINE16_NSBTP_FRAME_STEP_LIMIT) {
                shine16->mNsbtpFrameStepProgress -= SHINE16_NSBTP_FRAME_STEP_LIMIT;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= SHINE16_NSBTP_MIRROR_FRAMES) {
                    shine16->mNsbtpFramesSinceMirror -= SHINE16_NSBTP_MIRROR_FRAMES;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += SHINE16_DRAW_SCALE_STEP;
            if (shine16->mDrawScale >= SHINE16_DRAW_SCALE_FULL) {
                shine16->mDrawScale = SHINE16_DRAW_SCALE_FULL;
            }
            shine16->mMapObject.mPosStep.y -= 0x19a;
            VEC_Add(&shine16->mMapObject.mPos, &shine16->mMapObject.mPosStep, &shine16->mMapObject.mPos);
            if (shine16->mMapObject.mPosStep.y >= 0) {
                return;
            }
            shine16->mState = SHINE16_STATE_SHRINKING;
            shine16->mMapObject.mFlags |= gShine16HitFlag;
            return;
        case SHINE16_STATE_FLYING_TO_TARGET:
            shine16->mNsbtpFrameStepProgress += 1;
            if (shine16->mNsbtpFrameStepProgress >= SHINE16_NSBTP_FRAME_STEP_LIMIT) {
                shine16->mNsbtpFrameStepProgress -= SHINE16_NSBTP_FRAME_STEP_LIMIT;
                shine16->mNsbtpFrameIndex++;
                if (shine16->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(gShine16)) {
                    shine16->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(gShine16);
                }
                shine16->mNsbtpFramesSinceMirror++;
                if (shine16->mNsbtpFramesSinceMirror >= SHINE16_NSBTP_MIRROR_FRAMES) {
                    shine16->mNsbtpFramesSinceMirror -= SHINE16_NSBTP_MIRROR_FRAMES;
                    shine16->mMirror = shine16->mMirror == 0;
                }
            }
            shine16->mDrawScale += SHINE16_DRAW_SCALE_STEP;
            if (shine16->mDrawScale >= SHINE16_DRAW_SCALE_FULL) {
                shine16->mDrawScale = SHINE16_DRAW_SCALE_FULL;
            }
            shine16->mMapObject.mPosStep.y -= 0x19a;
            VEC_Add(&shine16->mMapObject.mPos, &shine16->mMapObject.mPosStep, &shine16->mMapObject.mPos);
            if (shine16->mMapObject.mPosStep.y < 0 &&
                shine16->mMapObject.mPos.y <= shine16->mTargetPos.y + shine16->mMapObject.mExtent.x) {
                if (GetMapObjectHitResponse(&shine16->mMapObject, 0, &pushOut)) {
                    savedVelocityY = shine16->mMapObject.mPosStep.y;
                    VEC_Add(&shine16->mMapObject.mPos, &pushOut, &shine16->mMapObject.mPos);
                    BounceVelocityOffUnnormalizedSurface(&shine16->mMapObject.mPosStep, &pushOut, 0x1000, 0x1000, 0x800,
                                                         &shine16->mMapObject.mPosStep);
                    shine16->mMapObject.mPosStep.y = 0;
                    if ((s64) shine16->mMapObject.mPosStep.x * shine16->mMapObject.mPosStep.x +
                            (s64) shine16->mMapObject.mPosStep.y * shine16->mMapObject.mPosStep.y +
                            (s64) shine16->mMapObject.mPosStep.z * shine16->mMapObject.mPosStep.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&shine16->mMapObject.mPosStep,
                                                           &shine16->mMapObject.mPosStep);
                    }
                    shine16->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.x, 0x1000);
                    shine16->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.y, 0x1000);
                    shine16->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.z, 0x1000);
                    shine16->mMapObject.mPosStep.y = savedVelocityY;
                }
                probePos.x = shine16->mMapObject.mPos.x;
                probePos.y = shine16->mMapObject.mExtent.x + (shine16->mMapObject.mPos.y - 0x14000);
                probePos.z = shine16->mMapObject.mPos.z;
                if (CollideSphereWithCourse(&probePos, NULL, 0, shine16->mMapObject.mExtent.x, 8, -2, &pushOut,
                                            &firstNormal, &secondNormal, &hitFlags, NULL, NULL, NULL, NULL)) {
                    VEC_Add(&shine16->mMapObject.mPos, &pushOut, &shine16->mMapObject.mPos);
                    if (hitFlags & COURSE_HIT_WALL) {
                        savedVelocityY = shine16->mMapObject.mPosStep.y;
                        BounceVelocityOffSurface(&shine16->mMapObject.mPosStep, &secondNormal, 0x1000, 0x1000, 0x800,
                                                 &shine16->mMapObject.mPosStep);
                        shine16->mMapObject.mPosStep.y = 0;
                        if ((s64) shine16->mMapObject.mPosStep.x * shine16->mMapObject.mPosStep.x +
                                (s64) shine16->mMapObject.mPosStep.y * shine16->mMapObject.mPosStep.y +
                                (s64) shine16->mMapObject.mPosStep.z * shine16->mMapObject.mPosStep.z >=
                            0x10) {
                            Vec3NormalizeAndGetLengthUnchecked(&shine16->mMapObject.mPosStep,
                                                               &shine16->mMapObject.mPosStep);
                        }
                        shine16->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.x, 0x1000);
                        shine16->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.y, 0x1000);
                        shine16->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.z, 0x1000);
                        shine16->mMapObject.mPosStep.y = savedVelocityY;
                    }
                    if (hitFlags & COURSE_HIT_GROUND) {
                        shine16->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.x, 0x19a);
                        shine16->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.y, -0x333);
                        shine16->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(shine16->mMapObject.mPosStep.z, 0x19a);
                        if (shine16->mMapObject.mPosStep.y < 0x1000) {
                            shine16->mMapObject.mPosStep.y = 0;
                            shine16->mState = SHINE16_STATE_RESTING;
                        }
                        QueueShine16Sound(shine16->mMapObject.mSound, SHINE16_SOUND_BASE + SHINE16_SOUND_BOUNCED);
                    }
                    if (hitFlags & 0x1000000) {
                        shine16->mMapObject.mFlags |= gShine16CollisionFlag;
                    } else {
                        shine16->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_HUD_XLU;
                    }
                }
            }
            if (shine16->mMapObject.mPos.y >= 0) {
                return;
            }
            shine16->mState = SHINE16_STATE_SHRINKING;
            shine16->mMapObject.mFlags |= gShine16HitFlag;
            return;
    }
}

MapObjectKindData *CreateShine16KindData(void) {
    MapObjectKindData *mapObjectKindData;

    mapObjectKindData = CreateMapObjectKindData(CollideKartWithShine16, NULL, NULL, 1, 0);
    mapObjectKindData->mHeightRangeMax = SHINE16_HEIGHT_RANGE_MAX;
    mapObjectKindData->mHeightRangeMin = -0x190000;
    return mapObjectKindData;
}

MapObjectList *CreateShine16DrawList(void) {
    return CreateMapObjectDrawList2(CreateShine16, DrawShine16, SetupDrawShine16);
}

MapObjectList *CreateShine16ShadowDrawList(void) {
    return CreateMapObjectDrawList1(ResetShine16ShadowAngleIndex, DrawShine16Shadow, AdvanceShine16ShadowAngleIndex);
}

MapObjectList *CreateShine16UpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateShine16, NULL);
}

// Parks each map object of kind 0x6a (Shine16) that is not already parked.
void ParkShine16Objects(void) {
    s32 mapObjectIndex;
    MapObject *mapObject;
    MapObjectList *mapObjectList;

    mapObjectList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16);
    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (mapObject = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if ((mapObject->mFlags & MAP_OBJECT_FLAG_PARKED) == 0) {
            ParkMapObject(mapObject);
        }
    }
}

// Unparks a Shine16 at the position; a nonzero last argument drops it from above, zero leaves it resting.
void StartShine16(Vec3 *position, s32 spawnObjectIndex, s32 dropFromAbove) {
    Shine16 *shine16;

    shine16 = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16));
    if (shine16 == NULL) {
        return;
    }
    if (dropFromAbove != 0) {
        shine16->mMapObject.mPos.x = position->x;
        shine16->mMapObject.mPos.y = position->y + 0x32000;
        shine16->mMapObject.mPos.z = position->z;
        shine16->mMapObject.mPosStep.x = 0;
        shine16->mMapObject.mPosStep.y = 0x2800;
        shine16->mMapObject.mPosStep.z = 0;
        shine16->mHeightAboveKart = 0;
        shine16->mFloorY = position->y + 0x14000;
        shine16->mState = SHINE16_STATE_DROPPING;
    } else {
        shine16->mMapObject.mPos.x = position->x;
        shine16->mMapObject.mPos.y = position->y + 0x14000;
        shine16->mMapObject.mPos.z = position->z;
        shine16->mMapObject.mPosStep.x = 0;
        shine16->mMapObject.mPosStep.y = 0;
        shine16->mMapObject.mPosStep.z = 0;
        shine16->mHeightAboveKart = 0;
        shine16->mFloorY = 0;
        shine16->mState = SHINE16_STATE_RESTING;
    }
    shine16->mDrawScale = 0;
    shine16->mPickupTimer = 0;
    shine16->mSpawnObjectIndex = spawnObjectIndex;
    shine16->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
    shine16->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_HUD_XLU;
    AddShineCount(1);
    QueueShine16Sound(shine16->mMapObject.mSound, SHINE16_SOUND_BASE + SHINE16_SOUND_SPAWNED);
}

void StartShine16FromKart(Kart *hitKart, Kart *hitByKart) {
    Shine16 *shine16;
    s32 isEntryKart;
    u16 highestBalloonOrShineCount;
    s32 balloonOrShineCount;

    shine16 = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16));
    if (shine16 == NULL) {
        return;
    }
    shine16->mMapObject.mFlags = shine16->mMapObject.mFlags | gShine16HitFlag;
    shine16->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_HUD_XLU;
    shine16->mMapObject.mPos.x = hitKart->mPos.x;
    shine16->mMapObject.mPos.y = hitKart->mPos.y;
    shine16->mMapObject.mPos.z = hitKart->mPos.z;
    shine16->mMapObject.mPosStep.x = 0;
    shine16->mMapObject.mPosStep.y = 0x1000;
    shine16->mMapObject.mPosStep.z = 0;
    shine16->mKartIndex = hitKart->mIndex;
    shine16->mHitByKartIndex = hitByKart->mIndex;
    shine16->mHeightAboveKart = 0;
    shine16->mFloorY = 0;
    shine16->mDrawScale = 0;
    shine16->mPickupTimer = 0;
    shine16->mState = SHINE16_STATE_RISING_FROM_KART;
    shine16->mTargetPos = hitByKart->mPos;
    if (hitByKart == hitKart) {
        shine16->mTargetDistanceSquared = 0;
    } else {
        shine16->mTargetDistanceSquared = SHINE16_TARGET_DISTANCE_LIMIT_SQUARED;
    }
    shine16->mTargetPickCount = 0;
    shine16->mSpawnObjectIndex = -1;
    AddShineCount(1);
    isEntryKart = hitKart->mIndex == gRaceSetup->mEntryIndex ? 1 : 0;
    highestBalloonOrShineCount = GetHighestBalloonOrShineCount();
    balloonOrShineCount = GetBalloonOrShineCount(hitKart->mIndex);
    QueueShine16Sound(shine16->mMapObject.mSound,
                      GetShine16SoundId(1, isEntryKart, highestBalloonOrShineCount, balloonOrShineCount));
}

const u16 gShine16HitFlag = 1;
const u16 gBalloonHideThirdFlag = 8;
const u16 gBalloonHideSecondFlag = 2;
const u16 gBalloonHideFirstFlag = 4;
