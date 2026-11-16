#include "01/MapObjects/donketu.h"
#include "Main/Graphics/model_effects.h"
#include "01/MapObjects/donketu_step_effects.h"
#include "01/MapObjects/lld.h"
#include "01/MapObjects/donketu_repeat_jumps.h"
#include "01/MapObjects/mission_run_repeats_and_counter.h"
#include "01/MapObjects/mission_run_repeats_remaining.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/MapObjects/mission_run_motion_setters.h"
#include "01/MapObjects/mission_run_state_callbacks.h"
#include "model_material_set.h"
#include "sound_archive_load.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "01/MapObjects/donketu_chase_kart_collision.h"
#include "01/MapObjects/mission_run_map_object.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/effects.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "fixed_vector_math.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Kart/camera.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/Sound/sound_start.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "01/MapObjects/donketu_fall_kart_collision.h"
#include "01/MapObjects/donketu_water_land_state.h"
#include "01/MapObjects/donketu_fall.h"
#include "01/MapObjects/donketu_water_jump_splash.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/System/heap.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"

MapObjectKindDescriptor gBossDonketuKindDescriptor = {0,
                                                      {0, 0},
                                                      0x30c,
                                                      InitDonketuSoundSource,
                                                      CreateDonketuKindData,
                                                      CreateBossDonketuDrawList,
                                                      NULL,
                                                      NULL,
                                                      CreateDonketuUpdateList,
                                                      NULL,
                                                      {NULL, NULL, NULL, NULL}};
MapObjectKindDescriptor gKingIceDonketuKindDescriptor = {0,
                                                         {0, 0},
                                                         0x30c,
                                                         InitDonketuSoundSource,
                                                         CreateDonketuKindData,
                                                         CreateKingIceDonketuDrawList,
                                                         NULL,
                                                         NULL,
                                                         CreateDonketuUpdateList,
                                                         NULL,
                                                         {NULL, NULL, NULL, NULL}};

void StartBossDonketuStepEffectFirst(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0x000008cdu, 0, 0x0000119au, 0x00000413u, 0);
}

void StartBossDonketuStepEffectSecond(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0xfffff733u, 0, 0x0000119au, 0x00000413u, 0);
}

void StartKingIceDonketuStepEffectFirst(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0xfffff000u, 0, 0x00001333u, 0x00000444u, 0);
}

void StartKingIceDonketuStepEffectSecond(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0x00001000u, 0, 0x00001333u, 0x00000444u, 0);
}

void SetDonketuStepSoundCallbacks(MissionRunMapObject *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 0x19, StartDonketuStepSoundFirst, 0x36, StartDonketuStepSoundSecond);
}

void SetDonketuStepEffectCallbacks(MissionRunMapObject *mapObject) {
    if (mapObject->mMapObject.mKind == (0x000001f5u)) {
        SetTwoAnimationFrameCallbacks(mapObject, 0x19, StartBossDonketuStepEffectFirst, 0x36,
                                      StartBossDonketuStepEffectSecond);
        return;
    }
    if (mapObject->mMapObject.mKind == (0x000001f6u)) {
        SetTwoAnimationFrameCallbacks(mapObject, 9, StartKingIceDonketuStepEffectFirst, 0x26,
                                      StartKingIceDonketuStepEffectSecond);
    }
}

void StartDonketuRepeatJumpAfterHitState(MissionRunMapObject *mapObject) {
    if (GetRepeatsRemaining(mapObject) != 0) {
        Vec3 velocity = {0, 0, 0};

        velocity.y = mapObject->mPrm->mDonketu.mHitRepeatJumpVelocityY;
        StartMapObjectState(mapObject, 5, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mDonketu.mHitRepeatJumpAnimationEntry,
                                    mapObject->mPrm->mDonketu.mHitRepeatJumpFrameStep);
        SetVelocity(mapObject, &velocity);
        SetCourseCollisionCallback(mapObject, StartDonketuRepeatJumpAfterHitState);
    } else {
        StartMapObjectState(mapObject, 0, NULL);
    }
}

void StartDonketuRepeatJumpsAfterHit(MissionRunMapObject *mapObject) {
    SetRepeatsRemaining(mapObject, mapObject->mPrm->mDonketu.mHitRepeatJumpCount);
    StopTurningMoveFollowsAngle(mapObject);
    StartDonketuRepeatJumpAfterHitState(mapObject);
}

void StartDonketuRepeatJumpState(MissionRunMapObject *mapObject) {
    if (GetRepeatsRemaining(mapObject) != 0) {
        Vec3 velocity = {0, 0, 0};

        velocity.y = mapObject->mPrm->mDonketu.mRepeatJumpVelocityY;
        StartMapObjectState(mapObject, 5, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mDonketu.mRepeatJumpAnimationEntry,
                                    mapObject->mPrm->mDonketu.mRepeatJumpFrameStep);
        SetVelocity(mapObject, &velocity);
        SetCourseCollisionCallback(mapObject, StartDonketuRepeatJumpState);
    } else {
        StartMapObjectState(mapObject, 0, NULL);
    }
}

void StartDonketuRepeatJumps(MissionRunMapObject *mapObject) {
    SetRepeatsRemaining(mapObject, mapObject->mPrm->mDonketu.mRepeatJumpCount);
    StopTurningMoveFollowsAngle(mapObject);
    StartDonketuRepeatJumpState(mapObject);
}

void DonketuKartCollisionCallback(MissionRunMapObject *donketu, Kart *kart) {
    s32 scale;

    if ((GetKart(kart->mIndex)->mDriveFlags & KART_DRIVE_BOOST) && kart->mBoostTimer > 0) {
        if (IsStateNumberBelow(donketu, 8)) {
            if (donketu->mPrm->mDonketu.mHitBoostedVelocityY > 0 ||
                donketu->mPrm->mDonketu.mHitBoostedKartVelocityScale > 0) {
                Vec3 velocityWhenBoosted = {0, 0, 0};
                velocityWhenBoosted.x = kart->mVelocity.x;
                velocityWhenBoosted.z = kart->mVelocity.z;
                if ((s64) velocityWhenBoosted.z * velocityWhenBoosted.z +
                        ((s64) velocityWhenBoosted.x * velocityWhenBoosted.x +
                         (s64) velocityWhenBoosted.y * velocityWhenBoosted.y) >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&velocityWhenBoosted, &velocityWhenBoosted);
                }
                scale = donketu->mPrm->mDonketu.mHitBoostedKartVelocityScale;
                velocityWhenBoosted.x = MUL_FIXED12_NO_ROUND(velocityWhenBoosted.x, scale);
                velocityWhenBoosted.y = MUL_FIXED12_NO_ROUND(velocityWhenBoosted.y, scale);
                velocityWhenBoosted.z = MUL_FIXED12_NO_ROUND(velocityWhenBoosted.z, scale);
                velocityWhenBoosted.y = donketu->mPrm->mDonketu.mHitBoostedVelocityY;
                StartMapObjectState(donketu, DONKETU_STATE_AFTER_KART_LAUNCH, NULL);
                StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mHitBoostedAnimationEntry,
                                            donketu->mPrm->mDonketu.mHitBoostedFrameStep);
                SpinAngleStopMoveAngle(donketu, donketu->mPrm->mDonketu.mHitBoostedAnglePerCall, 0x270f000);
                SetVelocity(donketu, &velocityWhenBoosted);
                SetStoppedCallback(donketu, StartDonketuRepeatJumpsAfterHit);
                SetSpeedAndClearTarget(donketu, 0);
            }
            {
                Vec3 effectPosition;

                VEC_Subtract(&donketu->mMapObject.mPos, &kart->mCollisionCenter, &effectPosition);
                if ((s64) effectPosition.z * effectPosition.z + SQUARE_SUM2(effectPosition.x, effectPosition.y) >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&effectPosition, &effectPosition);
                }
                VEC_MultAdd(kart->mRadius, &effectPosition, &kart->mCollisionCenter, &effectPosition);
                if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
                    donketu->mMapObject.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                    StopSound(&donketu->mMapObject.mSound->mSoundSource, 0x214);
                    StartMapObjectSound(&donketu->mMapObject, 0x211);
                    StartEffect(0x3e9, &effectPosition);
                    StartEffect(0x3e8, &effectPosition);
                    StartEffect(0x3ea, &effectPosition);
                    StartEffectAtRowHeight(donketu, 0x99a, 0, 0x75c, 0x3f3, 0);
                    StartEffectAtRowHeight(donketu, -0x99a, 0, 0x75c, 0x3f3, 0);
                } else if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
                    donketu->mMapObject.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                    StopSound(&donketu->mMapObject.mSound->mSoundSource, 0x245);
                    StartMapObjectSound(&donketu->mMapObject, 0x23f);
                    StartEffect(0x3fa, &effectPosition);
                    StartEffect(0x3fb, &effectPosition);
                    StartEffect(0x3fc, &effectPosition);
                    StartEffectAtRowHeight(donketu, -0x11ec, 0, 0x1800, 0x445, 0);
                    StartEffectAtRowHeight(donketu, 0x11ec, 0, 0x1800, 0x445, 0);
                }
            }
        }
    } else if (IsStateNumberBelow(donketu, DONKETU_STATE_AFTER_KART_LAUNCH)) {
        if (donketu->mPrm->mDonketu.mHitNotBoostedVelocityY > 0 ||
            donketu->mPrm->mDonketu.mHitNotBoostedKartVelocityScale > 0) {
            Vec3 velocityWhenNotBoosted = {0, 0, 0};
            velocityWhenNotBoosted.x = kart->mVelocity.x;
            velocityWhenNotBoosted.z = kart->mVelocity.z;
            if ((s64) velocityWhenNotBoosted.z * velocityWhenNotBoosted.z +
                    ((s64) velocityWhenNotBoosted.x * velocityWhenNotBoosted.x +
                     (s64) velocityWhenNotBoosted.y * velocityWhenNotBoosted.y) >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&velocityWhenNotBoosted, &velocityWhenNotBoosted);
            }
            scale = donketu->mPrm->mDonketu.mHitNotBoostedKartVelocityScale;
            velocityWhenNotBoosted.x = MUL_FIXED12_NO_ROUND(velocityWhenNotBoosted.x, scale);
            velocityWhenNotBoosted.y = MUL_FIXED12_NO_ROUND(velocityWhenNotBoosted.y, scale);
            velocityWhenNotBoosted.z = MUL_FIXED12_NO_ROUND(velocityWhenNotBoosted.z, scale);
            velocityWhenNotBoosted.y = donketu->mPrm->mDonketu.mHitNotBoostedVelocityY;
            StartMapObjectState(donketu, DONKETU_STATE_AFTER_KART_LAUNCH, NULL);
            StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mHitNotBoostedAnimationEntry,
                                        donketu->mPrm->mDonketu.mHitNotBoostedFrameStep);
            SpinAngleStopMoveAngle(donketu, donketu->mPrm->mDonketu.mHitNotBoostedAnglePerCall, 0x270f000);
            SetVelocity(donketu, &velocityWhenNotBoosted);
            SetStoppedCallback(donketu, NULL);
            SetSpeedAndClearTarget(donketu, 0);
        }
    }
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY_HALT;
}

void DonketuChaseKartCollisionCallback(MissionRunMapObject *donketu, Kart *kart) {
    Vec3 velocityWhenBoosted;
    Vec3 effectPosition;
    Vec3 velocityWhenNotBoosted;

    if ((GetKart(kart->mIndex)->mDriveFlags & KART_DRIVE_BOOST) && kart->mBoostTimer > 0) {
        if (IsStateNumberBelow(donketu, 8)) {
            if (donketu->mPrm->mDonketu.mChaseHitBoostedVelocityY > 0 ||
                donketu->mPrm->mDonketu.mChaseHitBoostedHorizontalSpeed > 0) {
                velocityWhenBoosted.x = MUL_FIXED12_NO_ROUND(-donketu->mPrm->mDonketu.mChaseHitBoostedHorizontalSpeed,
                                                             FX_SinIdx((u16) donketu->mMoveAngle));
                velocityWhenBoosted.y = donketu->mPrm->mDonketu.mChaseHitBoostedVelocityY;
                velocityWhenBoosted.z = MUL_FIXED12_NO_ROUND(-donketu->mPrm->mDonketu.mChaseHitBoostedHorizontalSpeed,
                                                             FX_CosIdx((u16) donketu->mMoveAngle));
                StartMapObjectState(donketu, DONKETU_STATE_AFTER_KART_LAUNCH, NULL);
                StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mChaseHitBoostedAnimationEntry,
                                            donketu->mPrm->mDonketu.mChaseHitBoostedFrameStep);
                SpinAngleStopMoveAngle(donketu, donketu->mPrm->mDonketu.mChaseHitBoostedAnglePerCall, 0x270f000);
                SetVelocity(donketu, &velocityWhenBoosted);
                SetStoppedCallback(donketu, StartDonketuRepeatJumpsAfterHit);
                SetSpeedAndClearTarget(donketu, 0);
            }
            VEC_Subtract(&donketu->mMapObject.mPos, &kart->mCollisionCenter, &effectPosition);
            if (SQUARE_SUM3(effectPosition.x, effectPosition.y, effectPosition.z) >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&effectPosition, &effectPosition);
            }
            VEC_MultAdd(kart->mRadius, &effectPosition, &kart->mCollisionCenter, &effectPosition);
            if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
                donketu->mMapObject.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                StopSound(&donketu->mMapObject.mSound->mSoundSource, 0x214);
                StartMapObjectSound(&donketu->mMapObject, 0x211);
                StartEffect(0x3e9, &effectPosition);
                StartEffect(0x3e8, &effectPosition);
                StartEffect(0x3ea, &effectPosition);
                StartEffectAtRowHeight(donketu, 0x99a, 0, 0x75c, 0x3f3, 0);
                StartEffectAtRowHeight(donketu, -0x99a, 0, 0x75c, 0x3f3, 0);
            } else if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
                donketu->mMapObject.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                StopSound(&donketu->mMapObject.mSound->mSoundSource, 0x245);
                StartMapObjectSound(&donketu->mMapObject, 0x23f);
                StartEffect(0x3fa, &effectPosition);
                StartEffect(0x3fb, &effectPosition);
                StartEffect(0x3fc, &effectPosition);
                StartEffectAtRowHeight(donketu, -0x11ec, 0, 0x1800, 0x445, 0);
                StartEffectAtRowHeight(donketu, 0x11ec, 0, 0x1800, 0x445, 0);
            }
            donketu->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(donketu->mPrm->mDonketu.mChaseHitBoostedPosStep,
                                                                  FX_SinIdx((u16) donketu->mMoveAngle));
            donketu->mMapObject.mPosStep.y = 0;
            donketu->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(donketu->mPrm->mDonketu.mChaseHitBoostedPosStep,
                                                                  FX_CosIdx((u16) donketu->mMoveAngle));
            donketu->mMapObject.mPos.x -= donketu->mMapObject.mPosStep.x;
            donketu->mMapObject.mPos.y -= donketu->mMapObject.mPosStep.y;
            donketu->mMapObject.mPos.z -= donketu->mMapObject.mPosStep.z;
        }
    } else if (IsStateNumberBelow(donketu, DONKETU_STATE_AFTER_KART_LAUNCH)) {
        if (donketu->mPrm->mDonketu.mChaseHitNotBoostedVelocityY > 0 ||
            donketu->mPrm->mDonketu.mChaseHitNotBoostedHorizontalSpeed > 0) {
            velocityWhenNotBoosted.x = MUL_FIXED12_NO_ROUND(-donketu->mPrm->mDonketu.mChaseHitNotBoostedHorizontalSpeed,
                                                            FX_SinIdx((u16) donketu->mMoveAngle));
            velocityWhenNotBoosted.y = donketu->mPrm->mDonketu.mChaseHitNotBoostedVelocityY;
            velocityWhenNotBoosted.z = MUL_FIXED12_NO_ROUND(-donketu->mPrm->mDonketu.mChaseHitNotBoostedHorizontalSpeed,
                                                            FX_CosIdx((u16) donketu->mMoveAngle));
            StartMapObjectState(donketu, DONKETU_STATE_AFTER_KART_LAUNCH, NULL);
            StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mChaseHitNotBoostedAnimationEntry,
                                        donketu->mPrm->mDonketu.mChaseHitNotBoostedFrameStep);
            SpinAngleStopMoveAngle(donketu, donketu->mPrm->mDonketu.mChaseHitNotBoostedAnglePerCall, 0x270f000);
            SetVelocity(donketu, &velocityWhenNotBoosted);
            SetStoppedCallback(donketu, StartDonketuRepeatJumps);
            SetSpeedAndClearTarget(donketu, 0);
        }
        donketu->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(donketu->mPrm->mDonketu.mChaseHitNotBoostedPosStep,
                                                              FX_SinIdx((u16) donketu->mMoveAngle));
        donketu->mMapObject.mPosStep.y = 0;
        donketu->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(donketu->mPrm->mDonketu.mChaseHitNotBoostedPosStep,
                                                              FX_CosIdx((u16) donketu->mMoveAngle));
        donketu->mMapObject.mPos.x -= donketu->mMapObject.mPosStep.x;
        donketu->mMapObject.mPos.y -= donketu->mMapObject.mPosStep.y;
        donketu->mMapObject.mPos.z -= donketu->mMapObject.mPosStep.z;
        donketu->mMapObject.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
        StartMapObjectSound(&donketu->mMapObject, 0x213);
    }
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY_HALT;
    StartCameraWobbleAtDistance(donketu->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK, 0x1000);
}

void DonketuFallKartCollisionCallback(MissionRunMapObject *donketu, Kart *kart) {
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mKartResponse = KART_MAP_OBJECT_RESPONSE_SCALE_EFFECT;
}

void StartDonketuWaterLandState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, DONKETU_STATE_AFTER_KART_LAUNCH, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mDonketu.mWaterLandAnimationEntry,
                                  donketu->mPrm->mDonketu.mWaterLandFrameStep, NULL);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x411, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x412, 0);
    StartMapObjectSound(&donketu->mMapObject, 0x242);
    StartCameraWobbleAtDistance(donketu->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK, 0x1000);
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_HUD_XLU;
}

s32 UpdateDonketuFall(MissionRunMapObject *donketu) {
    if (donketu->mVelocity.y < 0) {
        SetKartCollisionCallback(donketu, DonketuFallKartCollisionCallback);
        donketu->mStateNumber = DONKETU_STATE_AFTER_KART_LAUNCH;
        donketu->mStateFunction = NULL;
    }
    return 0;
}

s32 UpdateDonketuWaterJumpSplash(MissionRunMapObject *donketu) {
    if (donketu->mMapObject.mPos.y >= -GetHeightAboveWaterOrEfct(0)) {
        StartModelEffectAtWaterHeight(donketu, MODEL_EFFECT_DONKETU_WATER_SPLASH, 0);
        StartMapObjectSound(&donketu->mMapObject, 0x241);
        donketu->mStateFunction = UpdateDonketuFall;
    }
    return 0;
}

void StartDonketuWaterJumpState(MissionRunMapObject *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->mDonketu.mWaterJumpVelocityY;
    StartMapObjectState(donketu, 8, UpdateDonketuWaterJumpSplash);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mWaterJumpAnimationEntry,
                                donketu->mPrm->mDonketu.mWaterJumpFrameStep);
    SetVelocity(donketu, &velocity);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mDonketu.mWaterJumpSpeedTarget,
                             donketu->mPrm->mDonketu.mWaterJumpSpeedPerCall);
    SetCourseCollisionCallback(donketu, StartDonketuWaterLandState);
    donketu->mMapObject.mFlags |= gDonketuWaterFlag;
}

void StartDonketuWaterWalkState(MissionRunMapObject *donketu) {
    u32 targetAndPerCall;
    StartMapObjectState(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mWaterWalkAnimationEntry,
                                donketu->mPrm->mDonketu.mWaterWalkFrameStep);
    targetAndPerCall = donketu->mPrm->mDonketu.mWaterWalkAnglePerCall;
    TurnToPointMoveFollowsAngle(donketu, targetAndPerCall, targetAndPerCall);
    SetAnglePointAndMoveAnglePoint(donketu, &donketu->mMapObject.mCourseMapRow->mPosition);
    targetAndPerCall = donketu->mPrm->mDonketu.mWaterWalkSpeed;
    SetSpeedTargetAndPerCall(donketu, targetAndPerCall, targetAndPerCall);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mDonketu.mWaterWalkFrameCount, &StartDonketuWaterJumpState);
}

void StartDonketuWaterSinkState(MissionRunMapObject *donketu) {
    Vec3 velocity;
    s32 scale;

    velocity.x = donketu->mMapObject.mPos.x;
    velocity.y = 0;
    velocity.z = donketu->mMapObject.mPos.z;
    if ((s64) velocity.z * velocity.z + SQUARE_SUM2(velocity.x, velocity.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&velocity, &velocity);
    }
    scale = donketu->mPrm->mDonketu.mWaterSinkHorizontalSpeed;
    velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, scale);
    velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, scale);
    velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, scale);
    velocity.y = -donketu->mPrm->mDonketu.mWaterSinkDescentSpeed;
    StartMapObjectState(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mWaterSinkAnimationEntry,
                                donketu->mPrm->mDonketu.mWaterSinkFrameStep);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    SetVelocity(donketu, &velocity);
    DisableMissionRunMapObjectGravity(donketu);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mDonketu.mWaterSinkFrameCount, StartDonketuWaterWalkState);
    StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x423, 0);
    StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x425, 0);
    StartModelEffectAtWaterHeight(donketu, MODEL_EFFECT_DONKETU_WATER_SPLASH, 0);
    StartMapObjectSound(&donketu->mMapObject, 0x244);
    donketu->mMapObject.mFlags |= gDonketuWaterFlag;
}

void StartDonketuKartNotEliminatedState(MissionRunMapObject *donketu) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mKartNotEliminatedAnimationEntry,
                                donketu->mPrm->mDonketu.mKartNotEliminatedFrameStep);
    SetVelocity(donketu, &velocity);
    DisableMissionRunMapObjectGravity(donketu);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x423, 0);
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x425, 0);
    } else if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x423, 0);
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x425, 0);
    }
    {
        SoundStartParams soundRequest = {0x212, 0, 0xc, 0};

        soundRequest.mPositionSource = &donketu->mMapObject.mPos;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&donketu->mMapObject.mPos);
        StartSndHandleSoundUnchecked(&soundRequest, GetSecondSndHandleSlot());
    }
    donketu->mMapObject.mFlags |= gDonketuWaterFlag;
}

void StartDonketuJumpLandState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 5, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mDonketu.mJumpLandAnimationEntry,
                                  donketu->mPrm->mDonketu.mJumpLandFrameStep, NULL);
    SetSpeedAndClearTarget(donketu, 0);
}

u32 UpdateDonketuJumpSound(MissionRunMapObject *donketu) {
    StartMapObjectSoundWhileRequested(&donketu->mMapObject, 0x00000243u);
    return 0;
}

void StartDonketuJumpState(MissionRunMapObject *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->mDonketu.mJumpVelocityY;
    StartMapObjectState(donketu, 5, (s32(*)(MissionRunMapObject *)) UpdateDonketuJumpSound);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mJumpAnimationEntry,
                                donketu->mPrm->mDonketu.mJumpFrameStep);
    SpinAngleStopMoveAngle(donketu, donketu->mPrm->mDonketu.mJumpAnglePerCall,
                           donketu->mPrm->mDonketu.mJumpAnglePerCall);
    SetVelocity(donketu, &velocity);
    SetCourseCollisionCallback(donketu, StartDonketuJumpLandState);
}

void StartDonketuJumpWaitState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 5, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mDonketu.mJumpWaitAnimationEntry,
                                  donketu->mPrm->mDonketu.mJumpWaitFrameStep, NULL);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mDonketu.mJumpWaitFrameCount, &StartDonketuJumpState);
    SetSpeedAndClearTarget(donketu, 0);
}

s32 UpdateDonketuChaseStop(MissionRunMapObject *donketu) {
    SetAnglePointAndMoveAnglePoint(donketu, &GetKart((u16) gRaceSetup->mEntryIndex)->mPos);
    if (donketu->mSpeed < donketu->mPrm->mDonketu.mChaseStopCollisionSpeed) {
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
        SetDonketuStepSoundCallbacks(donketu);
    }
    return 0;
}

void StartDonketuChaseStopState(MissionRunMapObject *donketu) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(donketu, 2, UpdateDonketuChaseStop);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mChaseStopAnimationEntry,
                                donketu->mPrm->mDonketu.mChaseStopFrameStep);
    TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mDonketu.mChaseStopAnglePerCall,
                                donketu->mPrm->mDonketu.mChaseStopAnglePerCall);
    SetAnglePointAndMoveAnglePoint(donketu, &kart->mPos);
    StopMoveAngleTurning(donketu);
    SetSpeedTargetAndPerCall(donketu, 0, donketu->mPrm->mDonketu.mChaseStopSpeedPerCall);
    SetStoppedCallback(donketu, StartDonketuRepeatJumps);
    SetKartCollisionCallback(donketu, DonketuChaseKartCollisionCallback);
    if (donketu->mSpeed < donketu->mPrm->mDonketu.mChaseStopSpeedPerCall) {
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    }
    SetDonketuStepEffectCallbacks(donketu);
}

void StartDonketuChaseRunState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mChaseRunAnimationEntry,
                                donketu->mPrm->mDonketu.mChaseRunFrameStep);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mDonketu.mChaseRunSpeedTarget,
                             donketu->mPrm->mDonketu.mChaseRunSpeedPerCall);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mDonketu.mChaseRunFrameCount, &StartDonketuChaseStopState);
    SetKartCollisionCallback(donketu, DonketuChaseKartCollisionCallback);
    SetDonketuStepEffectCallbacks(donketu);
}

void StartDonketuChaseWaitState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mChaseWaitAnimationEntry,
                                donketu->mPrm->mDonketu.mChaseWaitFrameStep);
    StopTurningMoveFollowsAngle(donketu);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mDonketu.mChaseWaitFrameCount, &StartDonketuChaseRunState);
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuChaseRunAtStart(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mChaseRunAtStartAnimationEntry,
                                donketu->mPrm->mDonketu.mChaseRunAtStartFrameStep);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mDonketu.mChaseRunAtStartSpeedTarget,
                             donketu->mPrm->mDonketu.mChaseRunAtStartSpeedPerCall);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mDonketu.mChaseRunAtStartFrameCount,
                                 &StartDonketuChaseStopState);
    SetKartCollisionCallback(donketu, DonketuChaseKartCollisionCallback);
    SetDonketuStepEffectCallbacks(donketu);
}

void StartDonketuChaseKartState(MissionRunMapObject *donketu) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(donketu, 3, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mChaseKartAnimationEntry,
                                donketu->mPrm->mDonketu.mChaseKartFrameStep);
    TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mDonketu.mChaseKartAnglePerCall,
                                donketu->mPrm->mDonketu.mChaseKartAnglePerCall);
    SetAnglePointAndMoveAnglePoint(donketu, &kart->mPos);
    SetSpeedAndClearTarget(donketu, donketu->mPrm->mDonketu.mChaseKartSpeed);
    SetPointInRangeCallback(donketu, 0, donketu->mPrm->mDonketu.mChaseKartWaitHalfAngle, &kart->mPos,
                            StartDonketuChaseWaitState);
    if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
        StartMapObjectSound(&donketu->mMapObject, 0x214);
    } else if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        StartMapObjectSound(&donketu->mMapObject, 0x245);
    }
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuWalkToCourseMapRow(MissionRunMapObject *donketu) {
    if (IsPointInRange(donketu, &donketu->mMapObject.mCourseMapRow->mPosition,
                       (donketu->mPrm->mDonketu.mCourseMapRowRadius + 0x28), 0)) {
        StartMapObjectState(donketu, 3, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mWalkToCourseMapRowAnimationEntry,
                                    donketu->mPrm->mDonketu.mWalkToCourseMapRowFrameStep);
        TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mDonketu.mWalkToCourseMapRowAnglePerCall, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->mMapObject.mCourseMapRow->mPosition);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mDonketu.mWalkToCourseMapRowSpeedTarget,
                                 donketu->mPrm->mDonketu.mWalkToCourseMapRowSpeedPerCall);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mDonketu.mWalkToCourseMapRowFrameCount, NULL);
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    } else {
        StartMapObjectState(donketu, 3, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mWalkToCourseMapRowAnimationEntry,
                                    donketu->mPrm->mDonketu.mWalkToCourseMapRowFrameStep << 2);
        TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mDonketu.mWalkToCourseMapRowAnglePerCall, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->mMapObject.mCourseMapRow->mPosition);
        SetSpeedTargetAndPerCall(donketu, -donketu->mPrm->mDonketu.mWalkToCourseMapRowSpeedTarget,
                                 donketu->mPrm->mDonketu.mWalkToCourseMapRowSpeedPerCall);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mDonketu.mWalkToCourseMapRowFrameCount, NULL);
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    }
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuWalkState(MissionRunMapObject *donketu) {
    DonketuPrm *prm;

    prm = &donketu->mPrm->mDonketu;
    if (IsPointInRange(donketu, &GetCurrentGroupEntry(donketu)->mPos, prm->mWalkRangeRadius,
                       prm->mWalkRangeHalfAngle)) {
        StartMapObjectState(donketu, 1, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mWalkInRangeAnimationEntry,
                                    donketu->mPrm->mDonketu.mWalkInRangeFrameStep);
        TurnSidewaysMoveFollowsAngle(donketu, donketu->mPrm->mDonketu.mWalkInRangeAnglePerCall,
                                     donketu->mPrm->mDonketu.mWalkInRangeAnglePerCall, 0);
        SetAnglePointAndMoveAnglePoint(donketu, &GetCurrentGroupEntry(donketu)->mPos);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mDonketu.mWalkInRangeSpeed,
                                 donketu->mPrm->mDonketu.mWalkInRangeSpeed);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mDonketu.mWalkInRangeFrameCount, NULL);
    } else {
        IncrementEntryIndex(donketu);
        StartMapObjectState(donketu, 1, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mWalkToNextEntryAnimationEntry,
                                    donketu->mPrm->mDonketu.mWalkToNextEntryFrameStep);
        TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mDonketu.mWalkToNextEntryAnglePerCall,
                                    donketu->mPrm->mDonketu.mWalkToNextEntryAnglePerCall);
        SetAnglePointAndMoveAnglePoint(donketu, &GetCurrentGroupEntry(donketu)->mPos);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mDonketu.mWalkToNextEntrySpeed,
                                 donketu->mPrm->mDonketu.mWalkToNextEntrySpeed);
        prm = &donketu->mPrm->mDonketu;
        SetPointInRangeCallback(donketu, prm->mWalkRangeRadius, prm->mWalkRangeHalfAngle,
                                &GetCurrentGroupEntry(donketu)->mPos, NULL);
    }
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuWaterFallState(MissionRunMapObject *donketu) {
    StartDonketuWaterSinkState(donketu);
    IncrementHitCountAndCheckLimit(donketu);
}

void StartDonketuKartEliminatedState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mKartEliminatedAnimationEntry,
                                donketu->mPrm->mDonketu.mKartEliminatedFrameStep);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
}

void DonketuStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

int UpdateDonketuWaitForRaceStart(MissionRunMapObject *donketu) {
    if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        if (GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 2 ||
            GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 3) {
            ReleaseEffects(donketu);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            StartMapObjectSound(&donketu->mMapObject, 0x240);
        }
    }
    if (IsRaceStarted() == 1) {
        StartDonketuChaseRunAtStart(donketu);
    }
    return 0;
}

int UpdateDonketuStartupEffects(MissionRunMapObject *donketu) {
    if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        if (GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 2) {
            ReleaseEffects(donketu);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            StartMapObjectSound(&donketu->mMapObject, 0x240);
        }
    } else if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
        if (GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 0x2b ||
            GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 0x48) {
            ReleaseEffects(donketu);
            StartEffectAtRowHeight(donketu, 0, 0, 0, 0x410, 0);
        }
    }
    return 0;
}

s32 UpdateDonketuKingIceEffects(MissionRunMapObject *donketu) {
    int nsbcaFrameIndex;
    if ((donketu->mMapObject.mKind == 0x000001f6u) &&
        (nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd), nsbcaFrameIndex == 2)) {
        ReleaseEffects(donketu);
        StartEffectWithRotatedDirection(donketu, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000428u, 0);
        StartEffectWithRotatedDirection(donketu, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000429u, 0);
        StartEffectWithRotatedDirection(donketu, 0x00001000u, 0, 0, 0, 0x00000800u, 0xfffff000u, 0x0000042au, 0);
        StartMapObjectSound(&donketu->mMapObject, 0x00000240u);
    }
    return 0;
}

void StartDonketuWaitForRaceStart(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, &UpdateDonketuWaitForRaceStart);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mHead.mWaitForRaceStartAnimationEntry,
                                donketu->mPrm->mHead.mWaitForRaceStartFrameStep);
}

void StartDonketuStartupSecond(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, &UpdateDonketuStartupEffects);
    if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mHead.mStartupSecondAnimationEntry,
                                    donketu->mPrm->mHead.mStartupSecondFrameStep);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mHead.mWaitForRaceStartDelayFrames,
                                     &StartDonketuWaitForRaceStart);
        return;
    }
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mHead.mStartupSecondAnimationEntry,
                                  donketu->mPrm->mHead.mStartupSecondFrameStep, &StartDonketuWaitForRaceStart);
}

void StartDonketuStartupFirst(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, UpdateDonketuKingIceEffects);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mHead.mStartupFirstAnimationEntry,
                                donketu->mPrm->mHead.mStartupFirstFrameStep);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mHead.mStartupFirstFrameCount, &StartDonketuStartupSecond);
}

void StartDonketuChainStartupSecond(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, UpdateDonketuKingIceEffects);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mHead.mChainStartupSecondAnimationEntry,
                                donketu->mPrm->mHead.mChainStartupSecondFrameStep);
}

void StartDonketuChainStartupFirst(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, UpdateDonketuKingIceEffects);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mHead.mChainStartupFirstAnimationEntry,
                                donketu->mPrm->mHead.mChainStartupFirstFrameStep);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mHead.mChainStartupFirstFrameCount,
                                 &StartDonketuChainStartupSecond);
}

void InitDonketuObjects(MapObjectList *list) {
    s32 objectIndex;
    MissionRunMapObject *donketu;

    if (list != NULL) {
        for (objectIndex = 0; objectIndex < list->mMapObjectCount && (donketu = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            DecrementEntryIndexSkipZero(donketu);
            donketu->mMapObject.mCourseMapRow->mPosition.x = 0;
            donketu->mMapObject.mCourseMapRow->mPosition.z = 0;
            if (GetRaceUseChainCameras() != 0) {
                StartDonketuChainStartupFirst(donketu);
            } else {
                StartDonketuStartupFirst(donketu);
            }
            SetUnusedCallback(donketu, StartDonketuChaseRunAtStart);
        }
    }
    SetStandingsEndCallback((void (*)(void)) DonketuStandingsEndCallback);
}

void UpdateDonketu(u32 mapObjectList, MissionRunMapObject *donketu) {
    DonketuPrm *prm;
    Kart *kart;

    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (IsStateNumberBelow(donketu, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
                StartDonketuKartEliminatedState(donketu);
            } else {
                StartDonketuKartNotEliminatedState(donketu);
            }
        }
    } else {
        if (IsStateNumberBelow(donketu, 8) != 0) {
            if (IsNotRisingWithBelowZeroBit(donketu) != FALSE) {
                StartDonketuWaterFallState(donketu);
            }
        }
        if (IsStateNumberBelow(donketu, 5) != 0) {
            prm = &donketu->mPrm->mDonketu;
            if (GetAbsoluteCounter(donketu) >= prm->mJumpMinAbsoluteCounter) {
                prm = &donketu->mPrm->mDonketu;
                if (GetEntryKartInRange(donketu, prm->mJumpKartRadius, prm->mJumpKartHalfAngle) != NULL) {
                    prm = &donketu->mPrm->mDonketu;
                    kart = GetEntryKartFacingObject(donketu, prm->mJumpKartFacingRadius, prm->mJumpKartFacingHalfAngle);
                    if (kart != NULL) {
                        if ((GetKart(kart->mIndex)->mDriveFlags & KART_DRIVE_KINOKO_BOOST) != 0 &&
                            kart->mBoostTimer > 0) {
                            StartDonketuJumpWaitState(donketu);
                        }
                    }
                }
            }
        }
        if (IsStateNumberBelow(donketu, 3) != 0) {
            if (IsPointInRange(donketu, &donketu->mMapObject.mCourseMapRow->mPosition,
                               donketu->mPrm->mDonketu.mCourseMapRowRadius, 0) == FALSE) {
                StartDonketuWalkToCourseMapRow(donketu);
            }
        }
        if (IsStateNumberBelow(donketu, 2) != 0) {
            prm = &donketu->mPrm->mDonketu;
            if (GetEntryKartInRange(donketu, prm->mChaseKartRadius, prm->mChaseKartHalfAngle) != NULL) {
                StartDonketuChaseKartState(donketu);
            }
        }
        if (IsStateNumberBelow(donketu, 1) != 0) {
            StartDonketuWalkState(donketu);
        }
    }
    AdvanceMissionRunMapObject(mapObjectList, donketu);
}

void InitDonketuSoundSource(MissionRunMapObject *donketu) {
    donketu->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(SoundSource));
    InitSoundSource(&donketu->mMapObject.mSound->mSoundSource, 0xc, &donketu->mMapObject.mPos);
    donketu->mMapObject.mFarDistanceSquared = gSoundFalloffs[12].mFarDistanceSquared;
}

void InitBossDonketu(MapObjectList *list) {
    MissionRunMapObject *donketu;
    s32 objectIndex;

    if (list != NULL) {
        for (objectIndex = 0; objectIndex < list->mMapObjectCount && (donketu = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(donketu);
            }
            InitMissionRunMapObject(list, donketu, "boss_donketu.nsbmd", "boss_donketu.nsbca", "boss_donketu.prm");
            LoadMissionRunMapObjectShadow(list, donketu, "sh_circle.nsbmd");
            SetCollisionOffsetAndExtent(donketu, donketu->mPrm->mHead.mCollisionOffsetY,
                                        donketu->mPrm->mHead.mCollisionExtentXZ, 0);
            SetShadowOffsetYAndScale(donketu, 0, 0x11000);
            SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
            donketu->mCourseCollisionMode = MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY_NO_BITS;
        }
    }
}

void InitKingIceDonketu(MapObjectList *list) {
    MissionRunMapObject *donketu;
    s32 objectIndex;

    if (list != NULL) {
        for (objectIndex = 0; objectIndex < list->mMapObjectCount && (donketu = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(donketu);
            }
            InitMissionRunMapObject(list, donketu, "king_ice_donketu.nsbmd", "king_ice_donketu.nsbca",
                                    "king_ice_donketu.prm");
            LoadMissionRunMapObjectShadow(list, donketu, "sh_circle.nsbmd");
            SetCollisionOffsetAndExtent(donketu, donketu->mPrm->mHead.mCollisionOffsetY,
                                        donketu->mPrm->mHead.mCollisionExtentXZ, 0);
            SetShadowOffsetYAndScale(donketu, 0, 0x21000);
            SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
        }
    }
}

void DrawDonketu(void *mapObjectList, MissionRunMapObject *donketu) {
    DrawMissionRunMapObject(mapObjectList, donketu);
    DrawMissionRunMapObjectShadow(mapObjectList, donketu, 0);
}

MapObjectKindData *CreateDonketuKindData(void) {
    u32 soundId = 0x23eu;
    void *kartCollisionCallback = &CollideKartWithMissionRunMapObject;
    void *itemCollisionCallback = &CollideItemWithMissionRunMapObject;
    void *sphereHitCallback = &ComputeSphereHitOnMissionRunMapObject;
    return CreateMapObjectKindDataWithSoundIds(kartCollisionCallback, itemCollisionCallback, sphereHitCallback, 0x2u,
                                               0x1u, soundId, 0x0u);
}

MapObjectList *CreateBossDonketuDrawList(void) {
    return CreateMapObjectDrawList1(InitBossDonketu, DrawDonketu, ToggleShadowScale);
}

MapObjectList *CreateKingIceDonketuDrawList(void) {
    return CreateMapObjectDrawList1(InitKingIceDonketu, DrawDonketu, ToggleShadowScale);
}

MapObjectList *CreateDonketuUpdateList(void) {
    return CreateMapObjectUpdateList(InitDonketuObjects, UpdateDonketu, NULL);
}

const u16 gDonketuWaterFlag = 0x20;
const u16 gCoinHiddenFlag = 1;
const u32 gDonketuSkipKindSoundFlag = 0x40000000;
