#include "Main/Kart/kart_participant_record.h"
#include "Main/Race/race_end_condition.h"
#include "Main/MapObjects/attractor.h"
#include "01/Race/mission_run_state.h"
#include "ITCM/kart_motion.h"
#include "ITCM/collision_slots.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Kart/kart_matrix.h"
#include "Main/Kart/camera.h"
#include "Main/Kart/kart_reset.h"
#include "Main/Kart/kart_point_link_effects.h"
#include "Main/Kart/kart_ai_battle.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/Sound/sound_start.h"
#include "Main/Sound/kart_thunder_track_params.h"
#include "Main/Sound/kart_track_params_reset.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_pool.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/Race/race_clock.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_course_colors.h"
#include "Main/Kart/kart_killer_effect.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Graphics/model_animation_loop.h"
#include "Main/Kart/kart_level.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/rock.h"
#include "Main/Race/race_progress_lap.h"
#include "Main/Kart/kart_ai.h"
#include "Main/Item/bouncing_item_box.h"
#include "Main/Item/item_link_following.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/sound_falloffs.h"
#include "Main/Sound/kart_sound_queue.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Kart/kart_name_tags.h"
#include "sound_archive_load_result.h"
#include "Main/Race/kart.h"
#include "Main/Kart/kart_start_placement.h"
#include "Main/Graphics/model_animation_loop_mode.h"
#include "Main/Kart/kart_call.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/seq_row.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/kart_spin_follow_effect_release.h"
#include "Main/Kart/kart_surface_effects.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Kart/kart_ai_staff_roll_advance.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/System/backup_net_camera_work.h"
#include "linked_list_ops.h"
#include "matrix_4x3_basic.h"
#include "ITCM/sphere_collision.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/sound_mode.h"
#include "Main/Kart/kart_surface_effects.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u32 gKartSurfaceKind1Effects[8] = {0, 0, 0, 4, 0, 0, 0, 0};
const u32 gKartSurfaceStopEffects[8] = {0, 0, 0, 0, 0, 0, 0, 0};
const s16 gKartRaceStartBoostFrameCounts[6] = {8, 0xf, 0x1e, 0x32, 0x64, 0};
const s32 gKartModelScaleZBumpTable[15] = {0xccd, 0xdfa, 0xf4a, 0x1088, 0x1182, 0x1205, 0x11a9, 0x1093,
                                           0xf61, 0xeb2, 0xea5, 0xede,  0xf3f,  0xfa9,  0x1000};
const s32 gKartModelScaleYHardLandTable[15] = {0xccd,  0xe9f,  0x1072, 0x119a, 0x120c, 0x1239, 0x122d, 0x11f4,
                                               0x119a, 0x10a7, 0xf42,  0xe66,  0xe94,  0xf4a,  0x1000};
const s32 gKartModelOffsetYHardLandTable[15] = {-77,  -94,  -117, -137, -144, -128, -59, 0x34,
                                                0x9c, 0xcd, 0x3f, -102, -102, -51,  0};
const s16 gThunderShrinkTimerByRank[8] = {0x1fe, 0x1c2, 0x186, 0x14a, 0x10e, 0xd2, 0x96, 0x5a};
const Vec3 gKartStartPlacementHeadingAxis = {0, 0x1000, 0};
const s32 gKartModelScaleXBumpTable[15] = {0x1400, 0x12a9, 0x112d, 0xfc3,  0xea5,  0xe0b,  0xe67, 0xf91,
                                           0x10da, 0x1193, 0x119a, 0x1154, 0x10e3, 0x1066, 0x1000};
const u32 gKartSurfaceKind6Effects[8] = {0, 5, 0, 0, 0, 0, 0, 0};
const u32 gKartSurfaceKind10Effects[8] = {1, 2, 0, 7, 0, 0, 0, 0};
const s32 gKartModelScaleYLandTable[15] = {0xd9a,  0xed1,  0x1008, 0x10cd, 0x1117, 0x112f, 0x1123, 0x10fe,
                                           0x10cd, 0x1053, 0xfa1,  0xf33,  0xf4a,  0xfa5,  0x1000};
const s32 gKartOffsetCycleY[8] = {0x1000, 0x100e, 0x102d, 0x104c, 0x105b, 0x104c, 0x102d, 0x100e};
const s32 gKartOffsetCycleX[8] = {0x1052, 0x103d, 0x1015, 0x1000, 0x1009, 0x101d, 0x1035, 0x1049};
const u32 gKartSurfaceKind3Effects[8] = {1, 5, 3, 2, 6, 7, 0, 0};
const u32 gKartSurfaceKind5Effects[8] = {1, 5, 3, 2, 8, 0, 0, 0};
const u32 gKartSurfaceKind20Effects[8] = {0, 0, 0, 0, 0, 0, 0, 0};
const u32 gKartSurfaceKind17Effects[8] = {4, 4, 4, 0, 0, 0, 0, 0};
const u32 gKartSurfaceKind2Effects[8] = {2, 4, 7, 1, 0, 0, 0, 0};
const s32 gKartOffsetCycleZ[8] = {0x26, 0x20, 0x13, 6, 0, 6, 0x13, 0x20};
const s32 gKartModelOffsetYLandAndBumpTable[15] = {-77,  -80,  -86,  -91, -90, -77, -38, 0x15,
                                                   0x4c, 0x66, 0x20, -51, -51, -25, 0};
const s32 gKartRespawnOffsets[8][2] = {{0, 0},       {-0x1000, 0},       {0x1000, 0},        {0, -0x1000},
                                       {0, 0x1000}, {-0x1000, -0x1000}, {0x1000, -0x1000}, {-0x1000, 0x1000}};
int (*const gKartSurfaceFunctions[22])(Kart *) = {ApplyKartSurfaceStopEffects,
                                                  ApplyKartSurfaceKind1,
                                                  ApplyKartSurfaceKind2,
                                                  ApplyKartSurfaceKind3,
                                                  ApplyKartSurfaceStopEffects,
                                                  ApplyKartSurfaceKind5,
                                                  ApplyKartSurfaceKind6,
                                                  ApplyKartSurfaceBoost,
                                                  ApplyKartSurfaceStopEffects,
                                                  ApplyKartSurfaceStopEffects,
                                                  ApplyKartSurfaceKind10,
                                                  ApplyKartSurfaceStopEffects,
                                                  ApplyKartSurfaceJumpPad,
                                                  ApplyKartSurfaceStopEffects,
                                                  ApplyKartSurfaceStopEffects,
                                                  ApplyKartSurfaceKeyedPlacement,
                                                  ApplyKartSurfaceStopEffects,
                                                  ApplyKartSurfaceKind17,
                                                  ApplyKartSurfaceBoostWithSpeedFloor,
                                                  ApplyKartSurfaceBoostHeld,
                                                  ApplyKartSurfaceKind20,
                                                  ApplyKartSurfaceStopEffects};
const s32 gKartScaleFactorXTable[25] = {0x800,  0x6d9,  0x68d,  0x7a3,  0x8e6,  0xa4c,  0xbc8,  0xd4f, 0xed4,
                                        0x104c, 0x11ac, 0x12e7, 0x13f2, 0x14c0, 0x13f0, 0x119e, 0x1000, 0xfdd,
                                        0x1040, 0x10c6, 0x1109, 0x10ec, 0x10a5, 0x104f, 0x1000};
const s32 gKartScaleFactorYTable[25] = {0x800,  0x8e2,  0xa56,  0xd61,  0x10ee, 0x1389, 0x1520, 0x168c, 0x17bb,
                                        0x189d, 0x191e, 0x192e, 0x160a, 0x1213, 0x10c1, 0x1032, 0x1000, 0x1014,
                                        0x1071, 0x10d8, 0x1109, 0x10ec, 0x10a5, 0x104f, 0x1000};
const s32 gKartScaleFactorZTable[25] = {0x800,  0x89f,  0x8ff,  0x8db,  0x8c9,  0x94e,  0xa8d,  0xc2c, 0xdf0,
                                        0xfa0,  0x1101, 0x11d9, 0x11de, 0x112f, 0x1030, 0xf44,  0xed0, 0xf15,
                                        0xfce,  0x1096, 0x1109, 0x1101, 0x10b8, 0x1056, 0x1000};

void StructMQRacerEntry_SomeFn_0(Kart *kart, int spinCount, int skipSound) {
    int direction = 1;

    StructMQRacerEntry_SomeFn_1(kart, KART_STATE_SPIN);
    if (kart->mMotionFlags & (KART_MOTION_HOPPING | KART_MOTION_DRIFTING)) {
        if (kart->mTurnDirection == 1) {
            direction = -1;
        }
    } else if (kart->mTurnRatio < 0) {
        direction = -1;
    }
    kart->mYRotationAnglePerFrame = KART_SPIN_ANGLE_PER_FRAME;
    kart->mYRotationAnglePerFrame = kart->mYRotationAnglePerFrame * direction;
    kart->mYRotationAngle = 0;
    kart->mYRotationAngleSum = 0;
    kart->mYRotationCount = spinCount;
    kart->mEffectFlags |= KART_EFFECT_Y_SPIN;
    StartKartItemInUseOneCountdown(&(gKartItems)[kart->mIndex]);
    if (g_GlobalCO->mMode == MODE_MISSION_RUN && g_GlobalCO->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
    }
    if (skipSound != 0) {
        return;
    }
    if (kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT)) {
        return;
    }
    StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 1);
}

void AdvanceKartSpin(Kart *kart) {
    if (kart->mEffectFlags & KART_EFFECT_Y_SPIN) {
        return;
    }
    kart->mDriveFlags |= KART_DRIVE_STATE_END_TIMER | KART_DRIVE_INPUT_LOCKED;
    kart->mStateEndTimer = KART_SPIN_END_LOCK_FRAMES;
    kart->mState = KART_STATE_NORMAL;
    kart->mEffectFlags &= ~(KART_EFFECT_TUMBLING | KART_EFFECT_Y_SPIN);
    kart->mDriveFlags &= ~KART_DRIVE_HIT_STATE;
    StructMQRacerEntry_SomeFn_32(kart, 0, 1);
    kart->mMotionFlags |= KART_MOTION_STATE_RESET;
    if ((kart->mEntryFlags & KART_ENTRY_CPU) && g_GlobalCO->mMode == MODE_BATTLE &&
        g_GlobalCO->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
}

BOOL TryStartKartLaunchDoubleFlip(Kart *kart) {
    if (!TryStartKartState(kart, KART_STATE_LAUNCH_DOUBLE_FLIP)) {
        return FALSE;
    }
    StructMQRacerEntry_SomeFn(kart);
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_LAUNCH_DOUBLE_FLIP;
    }
    return TRUE;
}

void StructMQRacerEntry_SomeFn(Kart *kart) {
    kart->mForwardSpeed = 0;
    kart->mTurnAngle = 0;
    kart->mDriveFlags &= ~(KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST | KART_DRIVE_MINI_TURBO |
                           KART_DRIVE_KINOKO_BOOST | KART_DRIVE_ITEM_BOOST);
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        if (!(kart->mEffectFlags & KART_EFFECT_KILLER) && !(kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        kart->mEffectFlags &= ~KART_EFFECT_AHEAD_BOOST;
        kart->mAheadSpeedLimitFactor = TO_FIXED12(1);
        if (!(kart->mEffectFlags & KART_EFFECT_GESSO)) {
            StructMQRacerEntry_SomeFn_2(kart);
        }
        StructMQRacerEntry_SomeFn_3(kart);
    }
    kart->mState = KART_STATE_LAUNCH_DOUBLE_FLIP;
    kart->mEffectFlags |= KART_EFFECT_TUMBLING;
    kart->mVerticalSpeed = KART_LAUNCH_FLIP_VERTICAL_SPEED;
    kart->mRotationAngleSum = 0;
    kart->mRotationAngle = 0;
    kart->mRotationAnglePerFrame = KART_LAUNCH_FLIP_ANGLE_PER_FRAME;
    kart->mRotationEndFrames = 0;
    GetMQRacerVector444(kart, &kart->mRotationAxis);
    GetMQRacerVector333(kart, &kart->mLaunchForward);
    kart->mLaunchAxisSwing = 0;
    kart->mLaunchAxisSwingAngle = 0;
    kart->mLaunchAxisSwingAngleSum = 0;
    kart->mUnk_344 = 0;
    kart->mLaunchStartY = kart->mPos.y;
    kart->mLaunchFrames = 0;
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (g_GlobalCO->mMode == MODE_MISSION_RUN && g_GlobalCO->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
    }
    if (!(kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
        StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 2);
    }
    kart->mEffectFlags &= ~KART_EFFECT_LAUNCH_ENDING;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        SetCameraHeightHold(1);
    }
}

void AdvanceKartLaunchDoubleFlip(Kart *kart) {
    Vec3 launchAxis;
    s32 value;
    u16 swingAngle;

    if (kart->mRotationEndFrames == 0) {
        MtxFx33 swingMtx;

        kart->mForwardSpeed = 0;
        if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) < 0x1ffff) {
            kart->mRotationAngle = kart->mRotationAngle - kart->mRotationAnglePerFrame;
            kart->mRotationAngleSum = kart->mRotationAngleSum + kart->mRotationAnglePerFrame;
            value = kart->mRotationAnglePerFrame;
            if (value <= KART_LAUNCH_FLIP_ANGLE_PER_FRAME_MIN) {
                kart->mRotationAnglePerFrame = KART_LAUNCH_FLIP_ANGLE_PER_FRAME_MIN;
            } else {
                kart->mRotationAnglePerFrame = MUL_FIXED12_NO_ROUND(value, KART_LAUNCH_FLIP_ANGLE_DECAY);
            }
        } else {
            kart->mRotationAngle = 0;
        }
        if (kart->mMotionFlags & KART_MOTION_LANDED) {
            if (kart->mRotationAngleSum < KART_LAUNCH_FLIP_LANDING_ROTATION_LIMIT) {
                kart->mVerticalSpeed += 0x1800;
            }
        }
        if ((kart->mLaunchAxisSwingAngleSum > 0 ? kart->mLaunchAxisSwingAngleSum : -kart->mLaunchAxisSwingAngleSum) >=
            0xffff) {
            kart->mLaunchAxisSwingAngle = 0;
            kart->mLaunchAxisSwing = 0;
        } else {
            kart->mLaunchAxisSwingAngle += 0x3e8;
            kart->mLaunchAxisSwingAngleSum += 0x3e8;
            kart->mLaunchAxisSwing = FX_SinIdx(kart->mLaunchAxisSwingAngle);
        }
        swingAngle = MUL_FIXED12_NO_ROUND(kart->mLaunchAxisSwing, 0xce4);
        MTX_RotAxis33(&swingMtx, &kart->mLaunchForward, FX_SinIdx(swingAngle), FX_CosIdx(swingAngle));
        MTX_MultVec33(&kart->mRotationAxis, &swingMtx, &launchAxis);
        QuaternionFromAxisAngle(&launchAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
    } else {
        Vec4 targetQuaternion;

        targetQuaternion = gKartLaunchDoubleFlipTargetQuaternion;
        QuaternionBlend(&kart->mRotationQuaternion, &targetQuaternion, &kart->mRotationQuaternion, 0x266);
    }
    QuaternionNormalize(&kart->mRotationQuaternion, &kart->mRotationQuaternion);
    if (!(kart->mEffectFlags & KART_EFFECT_LAUNCH_ENDING)) {
        if ((u32) kart->mLaunchFrames > KART_LAUNCH_FLIP_END_MIN_FRAMES &&
            (kart->mLaunchStartY >= kart->mPos.y || (kart->mMotionFlags & KART_MOTION_ON_GROUND))) {
            if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
                SetCameraHeightHold(0);
            }
            if (kart->mRotationEndFrames != 0) {
                return;
            }
            kart->mCollisionStepFrames = KART_LAUNCH_FLIP_COLLISION_STEP_FRAMES;
            value = kart->mRotationEndFrames;
            kart->mDriveFlags |= KART_DRIVE_STATE_END_TIMER | KART_DRIVE_INPUT_LOCKED;
            kart->mStateEndTimer = value;
            kart->mEffectFlags |= KART_EFFECT_LAUNCH_ENDING;
            return;
        }
        kart->mLaunchFrames = kart->mLaunchFrames + 1;
        return;
    }
    kart->mRotationEndFrames++;
    if (kart->mRotationEndFrames < KART_LAUNCH_FLIP_ROTATION_END_FRAMES) {
        return;
    }
    kart->mState = KART_STATE_NORMAL;
    kart->mEffectFlags &= ~(KART_EFFECT_TUMBLING | KART_EFFECT_Y_SPIN);
    kart->mDriveFlags &= ~KART_DRIVE_HIT_STATE;
    StructMQRacerEntry_SomeFn_32(kart, 0, 1);
    kart->mMotionFlags |= KART_MOTION_STATE_RESET;
    if ((kart->mEntryFlags & KART_ENTRY_CPU) && g_GlobalCO->mMode == MODE_BATTLE &&
        g_GlobalCO->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
    kart->mEffectFlags &= ~(KART_EFFECT_TUMBLING | KART_EFFECT_LAUNCH_ENDING);
    if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
        kart->mTurnAngle = 0;
    }
}

BOOL StructMQRacerEntry_SomeFn_65(Kart *kart) {
    BOOL allowed;
    BOOL blocked;
    BOOL hasOtherState;
    int state;
    u32 flags = kart->mEffectFlags;

    if (flags & KART_EFFECT_BLINK_GUARD) {
        allowed = FALSE;
    } else if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING) &&
            !(flags & KART_EFFECT_STAR_OR_KILLER)) {
            allowed = TRUE;
        } else {
            allowed = FALSE;
        }
    } else {
        blocked = TRUE;
        if (!(flags & KART_EFFECT_STAR_OR_KILLER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING)) {
            state = kart->mState;
            hasOtherState = FALSE;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                hasOtherState = TRUE;
            }
            if (hasOtherState == FALSE) {
                blocked = FALSE;
            }
        }
        allowed = blocked == FALSE;
    }
    if (!allowed) {
        return FALSE;
    }
    StructMQRacerEntry_SomeFn_56(kart);
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_FLIP;
    }
    return TRUE;
}

void StructMQRacerEntry_SomeFn_56(Kart *kart) {
    Vec3 forward;

    StructMQRacerEntry_SomeFn_1(kart, KART_STATE_FLIP);
    kart->mEffectFlags |= KART_EFFECT_TUMBLING;
    kart->mRotationAngle = 0;
    kart->mRotationAnglePerFrame = KART_FLIP_ANGLE_PER_FRAME;
    kart->mVerticalSpeedStepCount = 0;
    kart->mRotationEndFrames = 0;
    kart->mRotationAngleSum = 0;
    kart->mForwardSpeed = kart->mForwardSpeed + 0x800;
    GetMQRacerVector444(kart, &kart->mRotationAxis);
    GetMQRacerVector333(kart, &forward);
    VecFx32_AddScale1(0x2e2, &forward, &kart->mRotationAxis, &kart->mRotationAxis);
    Vector3_MaybeNormalize(&kart->mRotationAxis, &kart->mRotationAxis);
    QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
    kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, 0x99a);
    if (kart->mKartModelsEntry->mKartModelHidden == 0) {
        StartEffect(0xc, &kart->mPos);
        StartEffect(0xd, &kart->mPos);
        StartEffect(0xe, &kart->mPos);
    }
    if (!(kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
        StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 2);
    }
    StartKartItemInUseOneCountdown(&(gKartItems)[kart->mIndex]);
    if (g_GlobalCO->mMode == MODE_MISSION_RUN && g_GlobalCO->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
    }
}

void AdvanceKartFlip(Kart *kart) {
    s16 endFrames;

    if (kart->mRotationAngleSum == 0) {
        kart->mVerticalSpeed = gKartFlipStartVerticalSpeed;
    } else if (kart->mMotionFlags & KART_MOTION_LANDED) {
        switch (kart->mVerticalSpeedStepCount) {
            case 0:
                kart->mVerticalSpeed = gKartFlipFirstLandVerticalSpeed;
                break;
            case 1:
                kart->mVerticalSpeed = gKartFlipSecondLandVerticalSpeed;
                break;
        }
        kart->mVerticalSpeedStepCount++;
    }
    if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) <= 0xffff) {
        kart->mRotationAngleSum = kart->mRotationAngleSum + kart->mRotationAnglePerFrame;
        if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) > 0xffff) {
            kart->mRotationAngle = 0;
        } else {
            kart->mRotationAngle = kart->mRotationAngle + kart->mRotationAnglePerFrame;
        }
        kart->mRotationAnglePerFrame = kart->mRotationAnglePerFrame - 0xa;
        QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
        QuaternionNormalize(&kart->mRotationQuaternion, &kart->mRotationQuaternion);
        return;
    }
    endFrames = kart->mRotationEndFrames;
    if (endFrames == 0) {
        kart->mDriveFlags |= KART_DRIVE_STATE_END_TIMER | KART_DRIVE_INPUT_LOCKED;
        kart->mStateEndTimer = endFrames;
        kart->mEffectFlags &= ~KART_EFFECT_TUMBLING;
    }
    kart->mRotationEndFrames++;
    if (kart->mRotationEndFrames < gKartFlipEndFrameCount) {
        return;
    }
    kart->mState = KART_STATE_NORMAL;
    kart->mEffectFlags &= ~(KART_EFFECT_TUMBLING | KART_EFFECT_Y_SPIN);
    kart->mDriveFlags &= ~KART_DRIVE_HIT_STATE;
    StructMQRacerEntry_SomeFn_32(kart, 0, 1);
    kart->mMotionFlags |= KART_MOTION_STATE_RESET;
    if ((kart->mEntryFlags & KART_ENTRY_CPU) && g_GlobalCO->mMode == MODE_BATTLE &&
        g_GlobalCO->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
}

BOOL TryStartKartPushFlipFromMapObject(Kart *kart, MapObject *mapObject) {
    Vec3 pushDirection;
    Vec3 offset;
    Vec3 cross;
    BOOL allowed;
    BOOL blocked;
    BOOL hasOtherState;
    int state;
    u32 flags = kart->mEffectFlags;

    if (flags & KART_EFFECT_BLINK_GUARD) {
        allowed = FALSE;
    } else if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING) &&
            !(flags & KART_EFFECT_STAR_OR_KILLER)) {
            allowed = TRUE;
        } else {
            allowed = FALSE;
        }
    } else {
        blocked = TRUE;
        if (!(flags & KART_EFFECT_STAR_OR_KILLER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING)) {
            state = kart->mState;
            hasOtherState = FALSE;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                hasOtherState = TRUE;
            }
            if (hasOtherState == FALSE) {
                blocked = FALSE;
            }
        }
        allowed = blocked == FALSE;
    }
    if (!allowed) {
        return FALSE;
    }
    pushDirection = mapObject->mMatrix.mRows[0];
    VecFx32_Subtract(&kart->mPos, &mapObject->mPos, &offset);
    VecFx32_CrossProduct(&mapObject->mMatrix.mRows[2], &offset, &cross);
    if (Vector3_DotProduct(&cross, &mapObject->mMatrix.mRows[1]) < 0) {
        pushDirection.x = -pushDirection.x;
        pushDirection.y = -pushDirection.y;
        pushDirection.z = -pushDirection.z;
    }
    StructMQRacerEntry_SomeFn_59(kart, &pushDirection, 0);
    return TRUE;
}

void StructMQRacerEntry_SomeFn_59(Kart *kart, const Vec3 *pushDirection, s32 record) {
    Vec3 unitY;
    s32 dot;
    s32 pushX;
    s32 pushY;
    s32 pushZ;

    StructMQRacerEntry_SomeFn_1(kart, KART_STATE_PUSH_FLIP);
    kart->mEffectFlags |= KART_EFFECT_TUMBLING;
    kart->mRotationAngle = 0;
    kart->mRotationAngleSum = 0;
    kart->mRotationAnglePerFrame = gKartPushFlipStartAnglePerFrame;
    kart->mVerticalSpeedStepCount = 0;
    kart->mRotationEndFrames = 0;
    unitY = g_UnitY_VecFx32;
    Vector3_Cross(&unitY, pushDirection, &kart->mRotationAxis);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (g_GlobalCO->mMode == MODE_MISSION_RUN && g_GlobalCO->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
    }
    if (!(kart->mEntryFlags & KART_ENTRY_WIFI_PEER)) {
        pushX = MUL_FIXED12_NO_ROUND(pushDirection->x, 0x1b33);
        pushY = MUL_FIXED12_NO_ROUND(pushDirection->y, 0x1b33);
        pushZ = MUL_FIXED12_NO_ROUND(pushDirection->z, 0x1b33);
        kart->mHitVelocity.x += pushX;
        kart->mHitVelocity.z += pushZ;
        kart->mVerticalSpeed += pushY;
        dot = VecFx32_CrossProduct_0(&kart->mTurnedForward, pushDirection);
        if (dot <= 0) {
            kart->mForwardSpeed = 0;
        } else {
            kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, dot) >> 2;
        }
    }
    QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
    if (kart->mKartModelsEntry->mKartModelHidden == 0) {
        StartEffect(0xc, &kart->mPos);
        StartEffect(0xd, &kart->mPos);
        StartEffect(0xe, &kart->mPos);
    }
    kart->mEffectFlags |= KART_EFFECT_PUSH_FLIP_STATE;
    if (!(kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
        StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 2);
    }
    if (record == 0) {
        return;
    }
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_PUSH_FLIP;
    }
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mPushDirection = *pushDirection;
        kart->mParticipantRecordData->mStartedStateKind = KART_STATE_PUSH_FLIP;
    }
}

void AdvanceKartPushFlip(Kart *kart) {
    s16 endFrames;

    if (kart->mRotationAngleSum == 0) {
        kart->mVerticalSpeed = gKartPushFlipStartVerticalSpeed;
    }
    if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) <= 0xffff) {
        kart->mRotationAngleSum = kart->mRotationAngleSum + kart->mRotationAnglePerFrame;
        if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) > 0xffff) {
            kart->mRotationAngle = 0;
            kart->mEffectFlags &= ~KART_EFFECT_PUSH_FLIP_STATE;
        } else {
            kart->mRotationAngle = kart->mRotationAngle + kart->mRotationAnglePerFrame;
        }
        kart->mRotationAnglePerFrame =
            kart->mRotationAnglePerFrame -
            (kart->mRotationAnglePerFrame > 0 ? gKartPushFlipAngleDecay : -gKartPushFlipAngleDecay);
        QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
        QuaternionNormalize(&kart->mRotationQuaternion, &kart->mRotationQuaternion);
        return;
    }
    endFrames = kart->mRotationEndFrames;
    if (endFrames == 0) {
        kart->mDriveFlags |= KART_DRIVE_STATE_END_TIMER | KART_DRIVE_INPUT_LOCKED;
        kart->mStateEndTimer = endFrames;
        kart->mEffectFlags &= ~KART_EFFECT_TUMBLING;
    }
    kart->mRotationEndFrames++;
    if (kart->mRotationEndFrames < KART_PUSH_FLIP_ROTATION_END_FRAMES) {
        return;
    }
    kart->mState = KART_STATE_NORMAL;
    kart->mEffectFlags &= ~(KART_EFFECT_TUMBLING | KART_EFFECT_Y_SPIN);
    kart->mDriveFlags &= ~KART_DRIVE_HIT_STATE;
    StructMQRacerEntry_SomeFn_32(kart, 0, 1);
    kart->mMotionFlags |= KART_MOTION_STATE_RESET;
    if ((kart->mEntryFlags & KART_ENTRY_CPU) && g_GlobalCO->mMode == MODE_BATTLE &&
        g_GlobalCO->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
    if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
        kart->mTurnAngle = 0;
    }
}

s32 StructMQRacerEntry_SomeFn_4(Kart *kart, const Vec3 *pushDirection, s32 record) {
    Vec3 flatDirection;
    Vec3 unitY;
    s32 value;
    s32 pushX;
    s32 pushY;
    s32 pushZ;

    StructMQRacerEntry_SomeFn_1(kart, KART_STATE_PUSH_DOUBLE_FLIP);
    flatDirection = *pushDirection;
    flatDirection.y = 0;
    if (LENGTH_SQUARED(flatDirection) >= 16) {
        value = Vector3_MaybeNormalize(&flatDirection, &flatDirection);
    } else {
        value = 0;
    }
    if (value == 0) {
        flatDirection = g_UnitX_VecFx32;
    }
    kart->mEffectFlags |= KART_EFFECT_TUMBLING;
    kart->mRotationAngle = 0;
    kart->mRotationAngleSum = 0;
    kart->mRotationAnglePerFrame = gKartPushDoubleFlipStartAnglePerFrame;
    kart->mVerticalSpeedStepCount = 0;
    kart->mRotationEndFrames = 0;
    unitY = g_UnitY_VecFx32;
    Vector3_Cross(&unitY, &flatDirection, &kart->mRotationAxis);
    if (!(kart->mEntryFlags & KART_ENTRY_WIFI_PEER)) {
        pushX = ((s64) flatDirection.x << 14) >> 12;
        pushY = ((s64) flatDirection.y << 14) >> 12;
        pushZ = ((s64) flatDirection.z << 14) >> 12;
        kart->mHitVelocity.x += pushX;
        kart->mHitVelocity.z += pushZ;
        kart->mVerticalSpeed += pushY;
        value = VecFx32_CrossProduct_0(&kart->mTurnedForward, &flatDirection);
        if (value <= 0) {
            kart->mForwardSpeed = 0;
        } else {
            kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, value) >> 2;
        }
    }
    QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (g_GlobalCO->mMode == MODE_MISSION_RUN && g_GlobalCO->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
    }
    if (kart->mKartModelsEntry->mKartModelHidden == 0) {
        StartEffect(0xc, &kart->mPos);
        StartEffect(0xd, &kart->mPos);
        StartEffect(0xe, &kart->mPos);
    }
    if (!(kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
        StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 2);
    }
    kart->mEffectFlags |= KART_EFFECT_PUSH_FLIP_STATE;
    if (record != 0) {
        if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_PUSH_DOUBLE_FLIP;
        }
        if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            kart->mParticipantRecordData->mPushDirection = *pushDirection;
            kart->mParticipantRecordData->mStartedStateKind = KART_STATE_PUSH_DOUBLE_FLIP;
        }
    }
    return 1;
}

void AdvanceKartPushDoubleFlip(Kart *kart) {
    s16 endFrames;

    if (kart->mRotationAngleSum == 0) {
        kart->mVerticalSpeed = gKartPushFlipStartVerticalSpeed;
    } else if (kart->mMotionFlags & KART_MOTION_LANDED) {
        if (kart->mVerticalSpeedStepCount == 0) {
            kart->mVerticalSpeed = gKartPushDoubleFlipLandVerticalSpeed;
        }
        kart->mVerticalSpeedStepCount++;
    }
    if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) <= 0x1fffe) {
        kart->mRotationAngleSum = kart->mRotationAngleSum + kart->mRotationAnglePerFrame;
        if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) > 0x1fffe) {
            kart->mRotationAngle = 0;
            kart->mEffectFlags &= ~KART_EFFECT_PUSH_FLIP_STATE;
        } else {
            kart->mRotationAngle = kart->mRotationAngle + kart->mRotationAnglePerFrame;
        }
        kart->mRotationAnglePerFrame =
            kart->mRotationAnglePerFrame -
            (kart->mRotationAnglePerFrame > 0 ? gKartPushFlipAngleDecay : -gKartPushFlipAngleDecay);
        QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
        QuaternionNormalize(&kart->mRotationQuaternion, &kart->mRotationQuaternion);
        return;
    }
    endFrames = kart->mRotationEndFrames;
    if (endFrames == 0) {
        kart->mDriveFlags |= KART_DRIVE_STATE_END_TIMER | KART_DRIVE_INPUT_LOCKED;
        kart->mStateEndTimer = endFrames;
        kart->mEffectFlags &= ~KART_EFFECT_TUMBLING;
    }
    kart->mRotationEndFrames++;
    if (kart->mRotationEndFrames < KART_PUSH_DOUBLE_FLIP_ROTATION_END_FRAMES) {
        return;
    }
    kart->mState = KART_STATE_NORMAL;
    kart->mEffectFlags &= ~(KART_EFFECT_TUMBLING | KART_EFFECT_Y_SPIN);
    kart->mDriveFlags &= ~KART_DRIVE_HIT_STATE;
    StructMQRacerEntry_SomeFn_32(kart, 0, 1);
    kart->mMotionFlags |= KART_MOTION_STATE_RESET;
    if ((kart->mEntryFlags & KART_ENTRY_CPU) && g_GlobalCO->mMode == MODE_BATTLE &&
        g_GlobalCO->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
    if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
        kart->mTurnAngle = 0;
    }
}

void StructMQRacerEntry_SomeFn_26(Kart *kart) {
    KartItemEffectState *itemEffect = &kart->mItemEffectData;

    if (kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) {
        return;
    }
    if (kart->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED) {
        return;
    }
    if (kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_KEYED_PLACEMENT)) {
        return;
    }
    itemEffect->mThunderShrinkTimer = gThunderShrinkTimerByRank[GetSomeRacerFlags(kart->mIndex) - 1];
    itemEffect->mThunderShrinkFrameIndex = 0;
    kart->mShrinkFactor = FIXED12_RATIO(7, 10);
    kart->mEffectFlags |= KART_EFFECT_THUNDER_SHRINK;
    StructMQRacerEntry_SomeFn_27(kart, 2, 1);
    StructMQRacerEntry_SomeFn_28(kart);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (g_GlobalCO->mMode == MODE_MISSION_RUN && g_GlobalCO->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
    }
    kart->mScaleFactor.x = TO_FIXED12(1);
    kart->mScaleFactor.y = TO_FIXED12(1);
    kart->mScaleFactor.z = TO_FIXED12(1);
    StructMQRacerEntry_SomeFn_29(kart);
    if (kart->mIndex == g_GlobalCO->mEntryIndex) {
        SetThunderShrinkSoundFlag(1);
    }
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_THUNDER_SHRINK;
    }
}

void StructMQRacerEntry_SomeFn_82(Kart *kart) {
    KartItemEffectState *itemEffect = &kart->mItemEffectData;

    if (itemEffect->mThunderShrinkTimer <= 0) {
        if (itemEffect->mThunderShrinkFrameIndex == 0) {
            StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xed, 0x7f, 0);
        }
        itemEffect->mThunderShrinkFrameIndex = itemEffect->mThunderShrinkFrameIndex + 1;
        if (itemEffect->mThunderShrinkFrameIndex >= KART_SCALE_RESTORE_STEPS) {
            kart->mScaleBase.x = TO_FIXED12(1);
            kart->mScaleBase.y = TO_FIXED12(1);
            kart->mScaleBase.z = TO_FIXED12(1);
            kart->mScaleFactor.x = TO_FIXED12(1);
            kart->mScaleFactor.y = TO_FIXED12(1);
            kart->mScaleFactor.z = TO_FIXED12(1);
            kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
            kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
            kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
            kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
            if (itemEffect->mThunderShrinkFrameIndex > KART_SCALE_RESTORE_STEPS) {
                kart->mEffectFlags &= ~KART_EFFECT_THUNDER_SHRINK;
                if (!(kart->mEffectFlags & (KART_EFFECT_THUNDER_SHRINK | KART_EFFECT_SCALE_TABLE))) {
                    kart->mShrinkFactor = TO_FIXED12(1);
                }
                if (kart->mIndex == g_GlobalCO->mEntryIndex) {
                    SetThunderShrinkSoundFlag(0);
                }
                ResetKartTrackParamsFunction(kart);
                return;
            }
            kart->mEffectFlags |= KART_EFFECT_SHRINK_ANIMATING;
            return;
        }
        kart->mEffectFlags |= KART_EFFECT_SHRINK_ANIMATING;
        kart->mScaleFactor.x = gKartScaleFactorXTable[itemEffect->mThunderShrinkFrameIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[itemEffect->mThunderShrinkFrameIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[itemEffect->mThunderShrinkFrameIndex];
        kart->mScaleBase.x = TO_FIXED12(1);
        kart->mScaleBase.y = TO_FIXED12(1);
        kart->mScaleBase.z = TO_FIXED12(1);
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
        return;
    }
    itemEffect->mThunderShrinkTimer = itemEffect->mThunderShrinkTimer - 1;
    if (kart->mScaleBase.y > 0x800) {
        s32 scale = kart->mScaleBase.y;

        if (scale < 0x800) {
            scale += 0x29;
            if (scale > 0x800) {
                scale = 0x800;
            }
        } else {
            scale -= 0x29;
            if (scale <= 0x800) {
                scale = 0x800;
            }
        }
        kart->mScaleBase.y = scale;
        kart->mScaleBase.z = kart->mScaleBase.y;
        kart->mScaleBase.x = kart->mScaleBase.z;
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
    }
    nullsub_16();
}

BOOL TryStartKartScaleTableEffect(Kart *kart) {
    KartItemEffectState *effectState;
    s32 mode;

    effectState = &kart->mItemEffectData;
    if ((kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || (kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT)) {
        return FALSE;
    }
    effectState->mScaleTableIndex = 0;
    effectState->mScaleEffectTimer = KART_SCALE_EFFECT_FRAMES;
    kart->mScaleFactor.x = TO_FIXED12(1);
    kart->mScaleFactor.y = TO_FIXED12(1);
    kart->mScaleFactor.z = TO_FIXED12(1);
    kart->mTireSpinAngle = 0;
    kart->mEffectFlags |= KART_EFFECT_SCALE_TABLE;
    kart->mDriveFlags |= KART_DRIVE_SCALE_TABLE_EFFECT;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        SetCameraHalfFovAngleGoal(0x1f40);
    }
    kart->mShrinkFactor = FIXED12_RATIO(7, 10);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    mode = g_GlobalCO->mMode;
    if (mode == MODE_MISSION_RUN) {
        if (mode == MODE_MISSION_RUN) {
            AddMissionRunPendingDropOnKartHit();
        }
    }
    if (!(kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
        StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 0);
    }
    return TRUE;
}

void StructMQRacerEntry_SomeFn_81(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->mItemEffectData;
    if (effectState->mScaleEffectTimer <= 0) {
        if (effectState->mScaleTableIndex == 0) {
            StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xed, 0x7f, 0);
        }
        effectState->mScaleTableIndex++;
        if (effectState->mScaleTableIndex >= KART_SCALE_RESTORE_STEPS) {
            kart->mUnk_398 = TO_FIXED12(1);
            kart->mScaleYFactor = TO_FIXED12(1);
            kart->mScaleFactor.x = TO_FIXED12(1);
            kart->mScaleFactor.y = TO_FIXED12(1);
            kart->mScaleFactor.z = TO_FIXED12(1);
            kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
            kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
            kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
            kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
            if (effectState->mScaleTableIndex > KART_SCALE_RESTORE_STEPS) {
                kart->mEffectFlags &= ~KART_EFFECT_SCALE_TABLE;
                if (!(kart->mEffectFlags & (KART_EFFECT_THUNDER_SHRINK | KART_EFFECT_SCALE_TABLE))) {
                    kart->mShrinkFactor = TO_FIXED12(1);
                }
                return;
            }
            kart->mEffectFlags |= KART_EFFECT_SHRINK_ANIMATING;
            return;
        }
        kart->mUnk_398 = TO_FIXED12(1);
        kart->mEffectFlags |= KART_EFFECT_SHRINK_ANIMATING;
        kart->mScaleFactor.x = gKartScaleFactorXTable[effectState->mScaleTableIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[effectState->mScaleTableIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[effectState->mScaleTableIndex];
        kart->mScaleYFactor = TO_FIXED12(1);
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
        return;
    }
    effectState->mScaleEffectTimer--;
    if (effectState->mScaleEffectTimer == KART_SCALE_EFFECT_DRIVE_FLAG_CLEAR_TIMER) {
        kart->mDriveFlags &= ~KART_DRIVE_SCALE_TABLE_EFFECT;
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            ResetCameraHalfFovAngleGoal();
        }
    }
    if (kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT) {
        kart->mForwardSpeed = 0;
    }
    if (kart->mScaleYFactor > 0.3f / 4096.0f) {
        kart->mScaleYFactor -= FIXED12_RATIO(3, 10);
        if (kart->mScaleYFactor < 0.3f / 4096.0f) {
            kart->mScaleYFactor = FIXED12_RATIO(3, 10);
        }
    }
    kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
    kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
    kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
    kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
}

void StructMQRacerEntry_SomeFn_60(Kart *kart) {
    kart->mUnk_398 = TO_FIXED12(1);
    kart->mScaleYFactor = TO_FIXED12(1);
    kart->mScale.y = TO_FIXED12(1);
    kart->mEffectFlags &= ~KART_EFFECT_SCALE_TABLE;
    if (kart->mEffectFlags & KART_EFFECT_THUNDER_SHRINK) {
        kart->mEffectFlags &= ~KART_EFFECT_THUNDER_SHRINK;
        kart->mScaleBase.x = TO_FIXED12(1);
        kart->mScaleBase.y = TO_FIXED12(1);
        kart->mScaleBase.z = TO_FIXED12(1);
        if (kart->mIndex == g_GlobalCO->mEntryIndex) {
            SetThunderShrinkSoundFlag(0);
        }
        ResetKartTrackParamsFunction(kart);
    }
    kart->mScale.x = TO_FIXED12(1);
    kart->mScale.y = TO_FIXED12(1);
    kart->mScale.z = TO_FIXED12(1);
    kart->mScaleFactor.x = TO_FIXED12(1);
    kart->mScaleFactor.y = TO_FIXED12(1);
    kart->mScaleFactor.z = TO_FIXED12(1);
    if (!(kart->mEffectFlags & (KART_EFFECT_THUNDER_SHRINK | KART_EFFECT_SCALE_TABLE))) {
        kart->mShrinkFactor = TO_FIXED12(1);
    }
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        ResetCameraHalfFovAngleGoal();
    }
}

void StructMQRacerEntry_SomeFn_58(Kart *kart) {
    u16 kartIndex;
    u32 bit200;

    kartIndex = 0;
    StartFadeFog();
    StartEffectsAtOtherKarts(kart->mIndex);
    bit200 = kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL;
    if (bit200 != 0) {
        if (bit200 != 0) {
            kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_THUNDER;
        }
        return;
    }
    for (; kartIndex < (u32) g_GlobalCO->mKartCount; kartIndex++) {
        if (kartIndex != kart->mIndex) {
            StructMQRacerEntry_SomeFn_26(GetRacerMQEntry(kartIndex));
        }
    }
}

void StructMQRacerEntry_SomeFn_57(Kart *kart) {
    StructMQRacerEntry_SomeFn_74(kart, KART_BOOST_ITEM_OR_SURFACE, KART_KINOKO_BOOST_FRAMES);
    kart->mDriveFlags |= KART_DRIVE_KINOKO_BOOST;
    kart->mItemEffectData.mKinokoBoostTimer = KART_KINOKO_BOOST_FRAMES;
    if (g_GlobalCO->mMode != MODE_BATTLE) {
        return;
    }
    ClearStandingsHitSeenFromKart(kart->mIndex);
}

void StructMQRacerEntry_SomeFn_55(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->mItemEffectData;
    if (kart->mEffectFlags & KART_EFFECT_KILLER) {
        return;
    }
    if (kart->mEntryFlags & KART_ENTRY_TERESA) {
        kart->mEntryFlags &= ~KART_ENTRY_TERESA;
        kart->mEntryFlags &= ~(KART_ENTRY_TRANSLUCENT | KART_ENTRY_NOT_DRAWN);
        kart->mItemEffect = KART_ITEM_EFFECT_NONE;
        if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
            ShowKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else {
            StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        SetTeresaSoundFlag(0, (kart->mEntryFlags & KART_ENTRY_SELECTED) ? 1 : 0);
    }
    if (kart->mEffectFlags & KART_EFFECT_GESSO) {
        kart->mEffectFlags &= ~(KART_EFFECT_COURSE_COLORED | KART_EFFECT_GESSO);
        if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
            StructMQRacerEntry_SomeFn_36(kart);
        }
        StructAD00Sub_SomeFn_3(kart->mKartModelsEntry);
    }
    SkipOrthoQuadsHold(kart->mIndex);
    effectState->mStarFrames = 0;
    kart->mEffectFlags |= KART_EFFECT_STAR;
    kart->mItemEffect = KART_ITEM_EFFECT_STAR;
    StructMQRacerEntry_SomeFn_67(kart);
    StartKartStarEffects(kart->mIndex);
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
        StartKartStarSeq();
    }
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        nullsub_8(kart->mIndex);
    }
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_STAR;
    }
    StructMQRacerEntry_SomeFn_32(kart, 2, 1);
}

// Teresa: the Boo item (KART_ITEM_EFFECT_TERESA).
void StructMQRacerEntry_SomeFn_54(Kart *kart) {
    KartItemEffectState *effectState;
    KartItemEffectState *effectStateAgain;
    u32 kartBits;

    effectState = &kart->mItemEffectData;
    effectState->mTeresaFrames = 0;
    if (kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) {
        kart->mEffectFlags &= ~KART_EFFECT_STAR;
        StopKartStarModels(kart);
        kart->mItemEffect = KART_ITEM_EFFECT_NONE;
        StopKartStarEffects(kart->mIndex);
        StructMQRacerEntry_SomeFn_32(kart, 0, 1);
        if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
            StopKartStarSeq();
        }
        if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
            StructMQRacerEntry_SomeFn_36(kart);
        }
    }
    kart->mEntryFlags |= KART_ENTRY_TERESA;
    kart->mItemEffect = KART_ITEM_EFFECT_TERESA;
    SkipOrthoQuadsHold(kart->mIndex);
    kartBits = kart->mEffectFlags;
    if (!(kartBits & KART_EFFECT_COURSE_COLORED) && (kartBits & KART_EFFECT_GESSO)) {
        effectStateAgain = &kart->mItemEffectData;
        if (effectStateAgain->mGessoFrames <= KART_GESSO_COLORED_FRAME) {
            effectStateAgain->mGessoFrames = KART_GESSO_COLORED_FRAME;
            kart->mEffectFlags |= KART_EFFECT_COURSE_COLORED;
            StartKartModelColorBlend(kart->mKartModelsEntry, GetKartCourseDiffColor(), GetKartCourseEmiColor(),
                                     GetKartCourseAmbColor());
        }
    }
    SetTeresaSoundFlag(1, (kart->mEntryFlags & KART_ENTRY_SELECTED) ? 1 : 0);
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        kart->mEntryFlags |= KART_ENTRY_TRANSLUCENT;
    } else {
        effectState->mTeresaToggleDivisor = KART_TERESA_START_TOGGLE_DIVISOR;
        effectState->mTeresaStepFrames = 0;
        effectState->mTeresaStepLimit = KART_TERESA_START_STEP_LIMIT;
        effectState->mTeresaToggleFrames = 0;
        effectState->mTeresaDivisorStep = 1;
    }
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_TERESA;
    }
}

void StructMQRacerEntry_SomeFn_80(Kart *kart) {
    KartItemEffectState *effectState;
    Vec3 entryPos;
    Vec3 kartPos;
    u32 kartBits;
    s32 diffX;
    s32 diffY;
    s32 diffZ;

    kartBits = kart->mEntryFlags;
    if (kartBits & KART_ENTRY_PARKED) {
        return;
    }
    effectState = &kart->mItemEffectData;
    if (!(kartBits & KART_ENTRY_SELECTED)) {
        if (effectState->mTeresaToggleFrames < KART_TERESA_TOGGLE_END_FRAMES) {
            effectState->mTeresaToggleFrames++;
            effectState->mTeresaStepFrames++;
            if (effectState->mTeresaStepFrames > effectState->mTeresaStepLimit) {
                effectState->mTeresaStepFrames = 0;
                effectState->mTeresaToggleDivisor = effectState->mTeresaToggleDivisor + effectState->mTeresaDivisorStep;
                effectState->mTeresaStepLimit = effectState->mTeresaStepLimit + effectState->mTeresaDivisorStep * 5;
            }
            if (effectState->mTeresaToggleFrames % effectState->mTeresaToggleDivisor == 0) {
                kart->mEntryFlags &= ~KART_ENTRY_NOT_DRAWN;
            } else {
                kart->mEntryFlags |= KART_ENTRY_NOT_DRAWN;
            }
            if (effectState->mTeresaToggleFrames >= KART_TERESA_TOGGLE_END_FRAMES) {
                kart->mEntryFlags |= KART_ENTRY_NOT_DRAWN;
            }
        }
        if (effectState->mTeresaFrames == KART_TERESA_DIVISOR_TURN_FRAMES) {
            effectState->mTeresaDivisorStep = -1;
            effectState->mTeresaToggleFrames = 0;
        }
        HideKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    }
    effectState->mTeresaFrames++;
    if (effectState->mTeresaFrames > KART_TERESA_MAX_FRAMES && (kart->mEntryFlags & KART_ENTRY_TERESA)) {
        kart->mEntryFlags &= ~KART_ENTRY_TERESA;
        kart->mEntryFlags &= ~(KART_ENTRY_TRANSLUCENT | KART_ENTRY_NOT_DRAWN);
        kart->mItemEffect = KART_ITEM_EFFECT_NONE;
        if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
            ShowKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else {
            StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        SetTeresaSoundFlag(0, (kart->mEntryFlags & KART_ENTRY_SELECTED) ? 1 : 0);
    }
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        return;
    }
    LoadRacerMQVectorB(&entryPos, (u16) g_GlobalCO->mEntryIndex);
    LoadRacerMQVectorB(&kartPos, kart->mIndex);
    diffX = FROM_FIXED12(entryPos.x - kartPos.x);
    diffY = FROM_FIXED12(entryPos.y - kartPos.y);
    diffZ = FROM_FIXED12(entryPos.z - kartPos.z);
    SetMinKartDistanceSquared(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

// Killer: the Bullet Bill item (KART_ITEM_EFFECT_KILLER).
void StructMQRacerEntry_SomeFn_42(Kart *kart) {
    KartItemEffectState *effectState;
    KartKillerEndRankOffsets rankOffsets;
    KartFollowEffectIds effectIds;
    s32 effectIndex;
    u8 kartCount;

    rankOffsets = gKartKillerEndRankOffsets;
    effectState = &kart->mItemEffectData;
    effectState->mKillerFrames = 0;
    effectState->mUnk_20 = 0;
    effectState->mKillerEnding = FALSE;
    SetupKartKillerCursor(&effectState->mKillerCursor, kart->mIndex);
    kart->mEffectFlags |= KART_EFFECT_KILLER;
    kartCount = g_GlobalCO->mKartCount;
    effectState->mKillerEndRank = GetSomeRacerFlags(kart->mIndex) - rankOffsets.mOffsets[kartCount - 1];
    if (effectState->mKillerEndRank <= 0) {
        effectState->mKillerEndRank = 1;
    }
    kart->mKartModelsEntry->mKillerItemAnimation.mFrameIndex = 0;
    if (kart->mEntryFlags & KART_ENTRY_TERESA) {
        kart->mEntryFlags &= ~KART_ENTRY_TERESA;
        kart->mEntryFlags &= ~(KART_ENTRY_TRANSLUCENT | KART_ENTRY_NOT_DRAWN);
        kart->mItemEffect = KART_ITEM_EFFECT_NONE;
        if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
            ShowKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else {
            StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        SetTeresaSoundFlag(0, (kart->mEntryFlags & KART_ENTRY_SELECTED) ? 1 : 0);
    }
    if (kart->mEffectFlags & KART_EFFECT_GESSO) {
        kart->mEffectFlags &= ~(KART_EFFECT_COURSE_COLORED | KART_EFFECT_GESSO);
        if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
            StructMQRacerEntry_SomeFn_36(kart);
        }
        StructAD00Sub_SomeFn_3(kart->mKartModelsEntry);
    }
    SkipOrthoQuadsHoldAndSetVelocities(kart->mIndex);
    if (kart->mEffectFlags & KART_EFFECT_STAR) {
        kart->mEffectFlags &= ~KART_EFFECT_STAR;
        StopKartStarModels(kart);
        kart->mItemEffect = KART_ITEM_EFFECT_NONE;
        StopKartStarEffects(kart->mIndex);
        StructMQRacerEntry_SomeFn_32(kart, 0, 1);
        if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
            StopKartStarSeq();
        }
        if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
            StructMQRacerEntry_SomeFn_36(kart);
        }
    }
    kart->mItemEffect = KART_ITEM_EFFECT_KILLER;
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        kart->mEffectFlags &= ~KART_EFFECT_AHEAD_BOOST;
        kart->mAheadSpeedLimitFactor = TO_FIXED12(1);
        if (!(kart->mEffectFlags & KART_EFFECT_GESSO)) {
            StructMQRacerEntry_SomeFn_2(kart);
        }
        StructMQRacerEntry_SomeFn_3(kart);
    }
    if (kart->mKartModelsEntry->mKartModelHidden == 0) {
        effectIds = gKartFollowEffectIds;
        for (effectIndex = 0; effectIndex < 3; effectIndex++) {
            SetupKartFollowEffect(StartEffect(effectIds.mEffectIds[effectIndex], &kart->mPos), kart->mIndex, 0x14);
        }
    }
    StartKartKillerEffect(kart->mIndex);
    StructMQRacerEntry_SomeFn_60(kart);
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_KILLER;
    }
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        SetCameraHalfFovAngleGoal(0x1d4c);
    }
}

void StructMQRacerEntry_SomeFn_79(Kart *kart) {
    KartItemEffectState *effectState;
    KartItemEffectState *effectStateAgain;
    s32 effectIndex;
    BOOL rankReached;
    BOOL endEarly;
    KartFollowEffectIds effectIds;

    effectState = &kart->mItemEffectData;
    effectState->mKillerFrames++;
    if (!(kart->mEntryFlags & KART_ENTRY_WIFI_PEER)) {
        if (AdvanceKartKillerCursor(&effectState->mKillerCursor) != 0) {
            effectStateAgain = &kart->mItemEffectData;
            if ((kart->mEffectFlags & KART_EFFECT_KILLER) && effectStateAgain->mKillerEnding == FALSE) {
                effectStateAgain->mKillerEnding = TRUE;
                if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
                    kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_KILLER_ENDING;
                }
            }
        }
    }
    StructAM_SomeFn_7(&kart->mKartModelsEntry->mKillerItemAnimation);
    if (effectState->mKillerEnding != FALSE) {
        kart->mRadiusFactor -= FIXED12_RATIO(2, 100);
        if (kart->mRadiusFactor > TO_FIXED12(1)) {
            return;
        }
        kart->mEffectFlags &= ~KART_EFFECT_KILLER;
        ResetKartActiveItemAfterKiller(kart->mIndex);
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            ResetCameraHalfFovAngleGoal();
        }
        kart->mRadiusFactor = TO_FIXED12(1);
        kart->mSurfaceGroup = -1;
        effectIndex = 0;
        kart->mItemEffect = KART_ITEM_EFFECT_NONE;
        if (kart->mKartModelsEntry->mKartModelHidden == 0) {
            effectIds = gKartFollowEffectIds;
            for (effectIndex = 0; effectIndex < 3; effectIndex++) {
                SetupKartFollowEffect(StartEffect(effectIds.mEffectIds[effectIndex], &kart->mPos), kart->mIndex, 0x14);
            }
        }
        StopKartKillerEffect(kart->mIndex);
        StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xfd, 0x7f, 0);
        return;
    }
    kart->mRadiusFactor += FIXED12_RATIO(2, 100);
    if (kart->mRadiusFactor > FIXED12_RATIO(7, 5)) {
        kart->mRadiusFactor = FIXED12_RATIO(7, 5);
    }
    if (effectState->mKillerEnding != FALSE) {
        return;
    }
    rankReached = FALSE;
    endEarly = FALSE;
    if (!(kart->mEntryFlags & KART_ENTRY_WIFI_PEER)) {
        if (GetSomeRacerFlags(kart->mIndex) == 1) {
            rankReached = TRUE;
        } else if ((s32) GetSomeRacerFlags(kart->mIndex) <= effectState->mKillerEndRank) {
            rankReached = TRUE;
        }
        if (effectState->mKillerFrames > KART_KILLER_RANK_END_FRAMES && rankReached != FALSE) {
            endEarly = TRUE;
        }
    }
    if (effectState->mKillerFrames <= KART_KILLER_MAX_FRAMES && endEarly == FALSE) {
        return;
    }
    effectState->mKillerEnding = TRUE;
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_KILLER_ENDING;
    }
}

void StructMQRacerEntry_SomeFn_38(Kart *kart, u32 orthoQuadCount) {
    u32 kartBits;

    if (kart->mEntryFlags & KART_ENTRY_WIFI_PEER) {
        return;
    }
    if (IsRacerFinishedRace(kart->mIndex) != 0) {
        return;
    }
    kartBits = kart->mEntryFlags;
    if (kartBits & (KART_ENTRY_REMOVED | KART_ENTRY_HIDDEN)) {
        return;
    }
    if (kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) {
        return;
    }
    if (kartBits & KART_ENTRY_TERESA) {
        return;
    }
    kart->mItemEffectData.mGessoFrames = 0;
    kart->mEffectFlags |= KART_EFFECT_GESSO;
    kart->mEffectFlags &= ~KART_EFFECT_COURSE_COLORED;
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        StructMQRacerEntry_SomeFn_2(kart);
    }
    StartKartModelColorBlend(kart->mKartModelsEntry, 0, 0x1084, 0);
    if (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) {
        StructMQRacerEntry_SomeFn_7(kart, 1, 0);
        StructAD00Sub_SomeFn_1(kart->mKartModelsEntry, 1);
    }
    if (!(kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
        StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 0);
    }
    StartOrthoQuadsGesoSumi(kart->mIndex, orthoQuadCount);
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_GESSO;
    }
}

void StructMQRacerEntry_SomeFn_40(Kart *kart) {
    KartItemEffectState *effectState;
    u32 kartBits;

    kartBits = kart->mEffectFlags;
    effectState = &kart->mItemEffectData;
    if (!(kartBits & KART_EFFECT_STAR)) {
        if (effectState->mGessoFrames == KART_GESSO_COLORED_FRAME && !(kartBits & KART_EFFECT_COURSE_COLORED) &&
            (kartBits & KART_EFFECT_GESSO) && effectState->mGessoFrames <= KART_GESSO_COLORED_FRAME) {
            effectState->mGessoFrames = KART_GESSO_COLORED_FRAME;
            kart->mEffectFlags |= KART_EFFECT_COURSE_COLORED;
            StartKartModelColorBlend(kart->mKartModelsEntry, GetKartCourseDiffColor(), GetKartCourseEmiColor(),
                                     GetKartCourseAmbColor());
        }
        AdvanceKartModelColorBlend(kart->mKartModelsEntry,
                                   (kart->mEffectFlags & KART_EFFECT_COURSE_COLORED) ? 0x52 : 0x19a);
    }
    effectState->mGessoFrames++;
    if (effectState->mGessoFrames <= KART_GESSO_END_FRAME) {
        return;
    }
    if (!(kart->mEffectFlags & KART_EFFECT_GESSO)) {
        return;
    }
    kart->mEffectFlags &= ~(KART_EFFECT_COURSE_COLORED | KART_EFFECT_GESSO);
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        StructMQRacerEntry_SomeFn_36(kart);
    }
    StructAD00Sub_SomeFn_3(kart->mKartModelsEntry);
}

void StructMQRacerEntry_SomeFn_39(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->mItemEffectData;
    effectState->mAheadBoostFrames = 0;
    effectState->mAheadCount = 0;
    kart->mAheadSpeedLimitFactor = gKartAheadSpeedLimitStartFactor;
    kart->mEffectFlags &= ~KART_EFFECT_AHEAD_BUILD_UP;
    if (!(kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST)) {
        kart->mEffectFlags |= KART_EFFECT_AHEAD_BOOST;
        if (!(kart->mEffectFlags & KART_EFFECT_GESSO)) {
            StructMQRacerEntry_SomeFn_36(kart);
        }
    }
    if (kart->mEffectFlags & (KART_EFFECT_NEAR_PLAYER_RANK | KART_EFFECT_ONE_RANK_BEHIND_PLAYER)) {
        StructMQRacerEntry_SomeFn_62(kart);
    }
    StructMQRacerEntry_SomeFn_69(kart);
    StructMQRacerEntry_SomeFn_70(kart);
    if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
        StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xa4, 0x7f, 0);
    }
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_AHEAD_BOOST;
    }
}

void StructMQRacerEntry_SomeFn_34(Kart *kart) {
    StructMQRacerEntry_SomeFn_35(kart, 1);
    kart->mEntryFlags |= KART_ENTRY_REMOVED_BY_PROGRESS;
}

// Takes the kart out of play unless it is out already; returns whether it did.
BOOL StructMQRacerEntry_SomeFn_35(Kart *kart, s32 fromRaceProgress) {
    BOOL removed;
    u32 kartBits;
    NNSSndSeqPlayer **seqPlayerHandle;

    removed = FALSE;
    if (fromRaceProgress != 0) {
        kartBits = kart->mEntryFlags;
        if (!(kartBits & KART_ENTRY_REMOVED_BY_PROGRESS)) {
            removed = TRUE;
        }
    } else {
        kartBits = kart->mEntryFlags;
        if (!(kartBits & (KART_ENTRY_REMOVED | KART_ENTRY_BATTLE_END_DONE | KART_ENTRY_REMOVED_BY_PROGRESS))) {
            removed = TRUE;
        }
    }
    if (removed != FALSE) {
        if (!(kartBits & KART_ENTRY_REMOVAL_COUNTED)) {
            DecrementKartAiNonCpuCount(kart->mIndex);
            kart->mEntryFlags |= KART_ENTRY_REMOVAL_COUNTED;
        }
        kart->mEntryFlags |= KART_ENTRY_REMOVED;
        if (kart->mCollisionSlot != -1) {
            kart->mCollisionSlot = FreeCollisionSlot(kart->mCollisionSlot);
        }
        if (kart->mSecondCollisionSlot != -1) {
            kart->mSecondCollisionSlot = FreeCollisionSlot(kart->mSecondCollisionSlot);
        }
        if (g_GlobalCO->mMode == MODE_BATTLE && fromRaceProgress == 0) {
            StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xd3, 0x7f, 0);
            if (g_GlobalCO->mBattleKind == BATTLE_KIND_BALLOON && (gRaceSoundKind & 1)) {
                seqPlayerHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                if (gSoundModeHolder.mSeqStartEnabled != 0) {
                    if (seqPlayerHandle[0] != NULL) {
                        NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
                    }
                    if (seqPlayerHandle[0] != NULL) {
                        NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
                    }
                    PlaySseqFromSarc(seqPlayerHandle, 0, 0x4c);
                }
            }
        }
        kart->mFramesSinceRemovalOrReset = 0;
        StructMQRacerEntry_SomeFn_16(kart);
    }
    return removed;
}

BOOL StructMQRacerEntry_HasFlags0x60(Kart *kart) {
    return (kart->mEntryFlags & (KART_ENTRY_REMOVED | KART_ENTRY_HIDDEN)) != 0;
}

void StructMQRacerEntry_SomeFn_53(Kart *kart) {
    u32 kartBits;
    s32 value;
    BOOL winnerDecidedAndEndReached;
    vu32 *bitsPointer;
    u32 currentBits;
    vu32 *bitsPointerAgain;
    s32 scaleIndex;
    Vec3 *collisionCenter;

    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_HIDDEN) != 0) {
        if ((kartBits & KART_ENTRY_BATTLE_REMOVAL) == 0) {
            return;
        }
        if ((kartBits & KART_ENTRY_REMOVED_BY_PROGRESS) != 0) {
            return;
        }
    }
    value = kart->mFramesSinceRemovalOrReset;
    if (value >= 0x19 || (kartBits & KART_ENTRY_GHOST) != 0) {
        winnerDecidedAndEndReached = FALSE;
        if (g_GlobalCO->mMode == MODE_BATTLE) {
            if (IsWinnerDecidedAndEndReached() != 0) {
                winnerDecidedAndEndReached = TRUE;
            }
        }
        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_HIDDEN;
        bitsPointer = &kart->mEntryFlags;
        currentBits = *bitsPointer;
        if ((currentBits & 0x800006) == 0 && winnerDecidedAndEndReached == FALSE && (currentBits & 0x40000) != 0) {
            if (kart->mFramesSinceRemovalOrReset >= KART_BATTLE_RESPAWN_FRAMES) {
                *bitsPointer = *bitsPointer | KART_ENTRY_BATTLE_RESPAWNED;
                RespawnKartAndToggleEventFlag(kart);
                collisionCenter = g_GlobalCO->mMode == MODE_WIFI ? &kart->mPointAlongUp : &kart->mCollisionCenter;
                if (kart->mCollisionSlot == -1) {
                    kart->mCollisionSlot =
                        CreateCollisionSlot(collisionCenter, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
                }
                if (kart->mSecondCollisionSlot == -1) {
                    value = kart->mPhysicalParam->mRadius;
                    kart->mSecondCollisionSlot =
                        CreateCollisionSlot(&kart->mSecondCollisionCenter, (s64) value << 15 >> 12, 0x800, kart);
                }
                bitsPointerAgain = &kart->mEntryFlags;
                kart->mEntryFlags =
                    kart->mEntryFlags & ~(KART_ENTRY_REMOVED | KART_ENTRY_HIDDEN | KART_ENTRY_OUT_OF_ROUND);
                kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_PARKED;
                if ((kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
                    *bitsPointerAgain = *bitsPointerAgain | KART_ENTRY_NOT_DRAWN_PARKED;
                }
                if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
                    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_TRANSLUCENT;
                } else {
                    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_NOT_DRAWN;
                }
                ReleaseEliminatedKartItems(kart->mIndex);
                if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
                    StartKartRemovalSeqEffect();
                }
                SetKartStartSeqNop(kart);
                return;
            }
            if ((currentBits & 1) != 0) {
                value = kart->mFramesSinceRemovalOrReset;
                if (value == 0x70) {
                    SetDispCapFadeFlag();
                } else if (value == 0x73) {
                    StartDispCapFadeToFaded(0x3c);
                    FadeSeqVolumeToZeroAfterKartRemoval();
                }
            }
            kart->mFramesSinceRemovalOrReset = kart->mFramesSinceRemovalOrReset + 1;
            return;
        }
        kart->mPos.x = 0x1000000;
        kart->mPos.y = 0xff000000;
        kart->mPos.z = 0x1000000;
        kart->mScale = gKartVec3Zero;
    } else {
        scaleIndex = 0x18 - value;
        kart->mScaleFactor.x = gKartScaleFactorXTable[scaleIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[scaleIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[scaleIndex];
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
        kart->mFramesSinceRemovalOrReset = kart->mFramesSinceRemovalOrReset + 1;
    }
}

void StructMQRacerEntry_SomeFn_52(Kart *kart) {
    if ((kart->mEntryFlags & KART_ENTRY_BATTLE_REMOVAL) != 0) {
        return;
    }
    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_BATTLE_REMOVAL;
    StructMQRacerEntry_SomeFn_35(kart, 0);
}

void StructMQRacerEntry_SomeFn_32(Kart *kart, s32 animationIndex, s32 useBlend) {
    u32 kartBits;
    u32 currentBits;
    KartModelsEntry *modelsEntry;
    BOOL faceFrame;
    BOOL changeAnimation;
    CharacterAnimationState *animationState;
    s32 currentAnimation;

    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0) {
        modelsEntry = kart->mKartModelsEntry;
        faceFrame = FALSE;
        animationState = &modelsEntry->mAnimationState;
        currentAnimation = modelsEntry->mCharacterAnimation->mCurrentIndex;
        changeAnimation = TRUE;
        if (animationState->mNextAnimationPending != 0) {
            if (currentAnimation != 0) {
                StructAM_SetSomeValueAt(modelsEntry->mCharacterAnimation, (u16) currentAnimation, 1);
            }
            animationState->mNextAnimationPending = 0;
        }
        if (animationIndex == 1) {
            animationIndex = 1;
            faceFrame = TRUE;
        } else {
            currentBits = kart->mEntryFlags;
            if ((currentBits & KART_ENTRY_RESULT_WON) != 0) {
                if (currentAnimation == animationIndex) {
                    changeAnimation = FALSE;
                }
                animationIndex = 2;
            } else if ((currentBits & KART_ENTRY_RESULT_LOST) != 0) {
                if (currentAnimation == animationIndex) {
                    changeAnimation = FALSE;
                }
                animationIndex = 3;
                faceFrame = TRUE;
            }
        }
        if (changeAnimation != FALSE) {
            StructAD00Sub_SomeFn_0(kart->mKartModelsEntry, animationIndex, useBlend);
        }
        StructAD00Sub_SomeFn_1(kart->mKartModelsEntry, faceFrame);
    } else {
        faceFrame = FALSE;
        if (animationIndex == 1 || (kartBits & KART_ENTRY_RESULT_LOST) != 0) {
            faceFrame = TRUE;
        }
        StructAD00Sub_SomeFn_1(kart->mKartModelsEntry, faceFrame);
    }
}

// Animation, face frame and voice of a kart that was robbed of its item or hit by an object.
void StructMQRacerEntry_SomeFn_10(Kart *kart) {
    if ((kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0) {
        StructMQRacerEntry_SomeFn_7(kart, 1, 0);
        StructAD00Sub_SomeFn_1(kart->mKartModelsEntry, 1);
    }
    if ((kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT)) != 0) {
        return;
    }
    StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 0);
}

void StructMQRacerEntry_SomeFn_31(Kart *kart) {
    QueueKartSound(kart, kart->mSoundIndex);
}

void StructMQRacerEntry_SomeFn_15(Kart *kart) {
    s32 endKind;
    u32 kartBits;
    u32 finishResult;

    if ((kart->mEntryFlags & KART_ENTRY_MISSION_END_DONE) != 0) {
        return;
    }
    kart->mEntryFlags = kart->mEntryFlags | (KART_ENTRY_ENDED | KART_ENTRY_MISSION_END_DONE);
    kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_SLOWING_STOP;
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        if (IsRacerFinishedRace((u16) g_GlobalCO->mEntryIndex) != 0) {
            endKind = g_GlobalMV->mEntryEndKind;
        } else {
            endKind = RACE_END_KIND_NOT_ENDED;
        }
        switch (endKind) {
            case RACE_END_KIND_GOAL:
                StartEntryCameraMissionRun();
                StructMQRacerEntry_SomeFn_14(kart, 1, 1);
                break;
            case RACE_END_KIND_TIME_UP:
            case RACE_END_KIND_KART_STATE:
            case RACE_END_KIND_CONTACT:
            case RACE_END_KIND_FAILED:
            case RACE_END_KIND_UNUSED:
            case RACE_END_KIND_NOT_ENDED:
            default:
                if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
                    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                        EliminateKartAndCheckWinner(kart->mIndex);
                    }
                    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_RESULT_LOST;
                    StructMQRacerEntry_SomeFn_32(kart, 3, 1);
                }
                break;
        }
        if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
            RaceModeBattle_OrMissionRun_SomeFn();
        }
    }
    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_SELECTED) == 0) {
        return;
    }
    if (g_GlobalCO->mMode == MODE_BATTLE || g_GlobalCO->mMode == MODE_MISSION_RUN) {
        finishResult = FINISH_RESULT_NEITHER;
        if ((kartBits & KART_ENTRY_RESULT_WON) != 0) {
            finishResult = FINISH_RESULT_WON;
        } else if ((kartBits & KART_ENTRY_RESULT_LOST) != 0) {
            finishResult = FINISH_RESULT_LOST;
        }
        SetEntryKartFinishResult(finishResult);
    }
}

void StructMQRacerEntry_SomeFn_25(Kart *kart, s32 isWinner) {
    Vec3 startPos;
    Vec3 forward;
    Vec3 startAngles;
    Vec3 *collisionCenter;
    s32 radius;
    u32 kartBits;
    u32 finishResult;
    vu32 *bitsPointer;

    if ((kart->mEntryFlags & KART_ENTRY_BATTLE_END_DONE) != 0) {
        return;
    }
    ReleaseItemsAtFinish();
    if (isWinner != 0) {
        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_WINNER;
    }
    kart->mEntryFlags = kart->mEntryFlags | (KART_ENTRY_BATTLE_END_MARK | KART_ENTRY_BATTLE_END_DONE);
    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_ENDED;
    kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_SLOWING_STOP;
    kart->mEntryFlags =
        kart->mEntryFlags & ~(KART_ENTRY_TERESA | KART_ENTRY_TRANSLUCENT | KART_ENTRY_NOT_DRAWN | KART_ENTRY_PARKED);
    if ((kart->mEntryFlags & KART_ENTRY_REMOVED) != 0) {
        GetCourseMapKartStartPlacement(&startPos, &startAngles, kart->mIndex);
        kart->mHeadingAngle = (u32) (startAngles.y * 0xb6) >> 12;
        QuaternionFromAxisAngle(&g_UnitY_VecFx32, kart->mHeadingAngle, &kart->mHeadingQuaternion);
        Matrix4x3FromQuaternion(&kart->mRotationMatrix, &kart->mHeadingQuaternion);
        GetMQRacerVector333(kart, &forward);
        StructMQRacerEntry_SomeFn_63(kart, &startPos, &forward, NULL);
        collisionCenter = g_GlobalCO->mMode == MODE_WIFI ? &kart->mPointAlongUp : &kart->mCollisionCenter;
        if (kart->mCollisionSlot == -1) {
            kart->mCollisionSlot =
                CreateCollisionSlot(collisionCenter, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
        }
        if (kart->mSecondCollisionSlot == -1) {
            radius = kart->mPhysicalParam->mRadius;
            kart->mSecondCollisionSlot =
                CreateCollisionSlot(&kart->mSecondCollisionCenter, (s64) radius << 15 >> 12, 0x800, kart);
        }
        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_SCALING_IN;
        kart->mEntryFlags = kart->mEntryFlags & ~(KART_ENTRY_REMOVED | KART_ENTRY_HIDDEN);
        kart->mScale = gKartVec3Zero;
    }
    bitsPointer = &kart->mEntryFlags;
    kart->mEntryFlags = kart->mEntryFlags & ~KART_ENTRY_SCALING_IN;
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
        *bitsPointer = *bitsPointer | KART_ENTRY_HIDDEN;
    } else {
        StartEntryCameraAngleStart();
    }
    StructMQRacerEntry_SomeFn_14(kart, 0, isWinner);
    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_SELECTED) != 0) {
        if (g_GlobalCO->mMode == MODE_BATTLE || g_GlobalCO->mMode == MODE_MISSION_RUN) {
            finishResult = FINISH_RESULT_NEITHER;
            if ((kartBits & KART_ENTRY_RESULT_WON) != 0) {
                finishResult = FINISH_RESULT_WON;
            } else if ((kartBits & KART_ENTRY_RESULT_LOST) != 0) {
                finishResult = FINISH_RESULT_LOST;
            }
            SetEntryKartFinishResult(finishResult);
        }
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
        return;
    }
    StartBattleWinOrLoseSound(kart->mSoundIndex, isWinner);
}

void StructMQRacerEntry_SomeFn_14(Kart *kart, s32 useCourseMapRecord, s32 isWinner) {
    KartRaceEndPlacement placement;
    s32 savedForwardSpeed;
    BOOL hasCourseData;
    CourseMap *courseMap;

    savedForwardSpeed = kart->mForwardSpeed;
    placement.mOldPos = kart->mPos;
    if (useCourseMapRecord != 0) {
        courseMap = g_GlobalPE;
        if (courseMap->mRaceEndPlacements == NULL) {
            hasCourseData = FALSE;
        } else {
            placement.mRecordPos = courseMap->mRaceEndPlacements->mPos;
            placement.mRecordRotation = courseMap->mRaceEndPlacements->mRotation;
            placement.mKeepSpeedFlag = courseMap->mRaceEndPlacements->mKeepSpeedFlag;
            hasCourseData = TRUE;
        }
        if (hasCourseData == FALSE) {
            return;
        }
    }
    StructMQRacerEntry_SomeFn_16(kart);
    StructAD00Sub_SomeFn_3(kart->mKartModelsEntry);
    kart->mSlotFunctions[1](kart);
    kart->mEntryFlags = kart->mEntryFlags & ~(KART_ENTRY_TERESA | KART_ENTRY_TRANSLUCENT | KART_ENTRY_NOT_DRAWN);
    StopOrthoQuads(kart->mIndex);
    StructMQRacerEntry_MaybeInitializePosition(kart, useCourseMapRecord);
    kart->mPos.y = kart->mPos.y - 0x1000;
    if (useCourseMapRecord != 0) {
        if (placement.mKeepSpeedFlag != 0) {
            kart->mForwardSpeed = savedForwardSpeed;
            kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_SLOWING_STOP;
        }
    }
    kart->mMotionFlags = kart->mMotionFlags | KART_MOTION_ON_GROUND;
    if ((kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0) {
        if (isWinner != 0) {
            kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_RESULT_WON;
            StructMQRacerEntry_SomeFn_32(kart, 2, 1);
        } else {
            kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_RESULT_LOST;
            StructMQRacerEntry_SomeFn_32(kart, 3, 1);
        }
    }
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        VecFx32_Subtract(&kart->mPos, &placement.mOldPos, &placement.mPosChange);
        CallStandingsKartOffsetCallback(kart->mIndex, &placement.mPosChange);
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
        return;
    }
    StartDispCapFadeToClear(0);
    ReleaseJg();
}

void StructMQRacerEntry_SomeFn_73(Kart *kart, s32 charge) {
    KartTurnEffects *turnEffects;

    kart->mDriftCharge = charge;
    if (kart->mDriftCharge != KART_DRIFT_CHARGE_LEVEL_2) {
        return;
    }
    turnEffects = GetKartTurnEffects(kart->mIndex);
    StartKartLevel2Effects(turnEffects, (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0 ? 1 : 0);
    StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xd2, 0x7f, 0);
}

void StructMQRacerEntry_SomeFn_33(Kart *kart) {
    KartTurnEffects *turnEffects;
    u16 *leftTurnCounts;
    u16 *rightTurnCounts;
    u32 pressedBits;
    enum { ENTRY_INDEX_FIRST } entryIndex;

    if ((kart->mEntryFlags & (KART_ENTRY_CPU | KART_ENTRY_WIFI_PEER)) == 0) {
        if (kart->mDriftCharge >= KART_DRIFT_CHARGE_LEVEL_3) {
            return;
        }
        kart->mTurnCountTimer = kart->mTurnCountTimer - 1;
        if (kart->mTurnCountTimer > 0) {
            return;
        }
        entryIndex = kart->mEntryIndex;
        pressedBits = g_GlobalCYT[entryIndex].mPressedBits;
        if ((u16) (pressedBits & PAD_KEY_LEFT) != 0) {
            leftTurnCounts = &kart->mLeftTurnCount;
            if (kart->mAwayTurnCounter == leftTurnCounts) {
                if (leftTurnCounts[1] == leftTurnCounts[0]) {
                    leftTurnCounts[0]++;
                    kart->mTurnCountTimer = KART_TURN_COUNT_INTERVAL_FRAMES;
                }
            } else if (leftTurnCounts[1] > leftTurnCounts[0]) {
                leftTurnCounts[0]++;
                kart->mDriftCharge = kart->mDriftCharge + 1;
                kart->mTurnCountTimer = KART_TURN_COUNT_INTERVAL_FRAMES;
                if (kart->mDriftCharge == KART_DRIFT_CHARGE_LEVEL_2) {
                    turnEffects = GetKartTurnEffects(kart->mIndex);
                    StartKartLevel2Effects(turnEffects,
                                           (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0 ? 1 : 0);
                    StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xd2, 0x7f, 0);
                }
            }
        } else if ((u16) (pressedBits & PAD_KEY_RIGHT) != 0) {
            rightTurnCounts = &kart->mRightTurnCount;
            if (kart->mTowardTurnCounter == rightTurnCounts) {
                leftTurnCounts = &kart->mLeftTurnCount;
                if (leftTurnCounts[0] > leftTurnCounts[1]) {
                    rightTurnCounts[0] = rightTurnCounts[0] + 1;
                    kart->mDriftCharge = kart->mDriftCharge + 1;
                    kart->mTurnCountTimer = KART_TURN_COUNT_INTERVAL_FRAMES;
                    if (kart->mDriftCharge == KART_DRIFT_CHARGE_LEVEL_2) {
                        turnEffects = GetKartTurnEffects(kart->mIndex);
                        StartKartLevel2Effects(turnEffects,
                                               (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0 ? 1 : 0);
                        StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xd2, 0x7f, 0);
                    }
                }
            } else {
                leftTurnCounts = &kart->mLeftTurnCount;
                if (leftTurnCounts[1] == leftTurnCounts[0]) {
                    rightTurnCounts[0] = rightTurnCounts[0] + 1;
                    kart->mTurnCountTimer = KART_TURN_COUNT_INTERVAL_FRAMES;
                }
            }
        }
    }
    if (kart->mDriftCharge != KART_DRIFT_CHARGE_LEVEL_3) {
        return;
    }
    turnEffects = GetKartTurnEffects(kart->mIndex);
    if ((kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK) != 0) {
        StopKartTurnStartEffects(turnEffects);
        RequestKartLevel4EffectsRestart(turnEffects);
        StartKartLevel3Effects(turnEffects, (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0 ? 1 : 0);
    } else {
        StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    }
    kart->mDriftCharge = kart->mDriftCharge + 1;
}

// A response-table entry with nothing to do: stores 0 and returns 0.
s32 CollideKartWithMapObjectNoResponse(Kart *kart, s32 *outValue) {
    *outValue = 0;
    return 0;
}

void MapObjectResponseNop(void) {}

void StructMQRacerEntry_SomeFn_72(Kart *kart, const Vec3 *direction) {
    s32 canStart;
    BOOL isBlocked;
    s32 inOtherState;
    BOOL started;
    u32 kartBits;
    s32 state;

    kartBits = kart->mEffectFlags;
    if ((kartBits & KART_EFFECT_BLINK_GUARD) != 0) {
        canStart = 0;
    } else if ((kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) != 0) {
        if (kart->mState == KART_STATE_NORMAL && (kart->mDriveFlags & KART_DRIVE_RESPAWNING) == 0 &&
            (kartBits & KART_EFFECT_STAR_OR_KILLER) == 0) {
            canStart = 1;
        } else {
            canStart = 0;
        }
    } else {
        isBlocked = TRUE;
        if ((kartBits & KART_EFFECT_STAR_OR_KILLER) == 0 && (kart->mDriveFlags & KART_DRIVE_RESPAWNING) == 0) {
            inOtherState = 0;
            state = kart->mState;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                inOtherState = isBlocked;
            }
            if (inOtherState == 0) {
                isBlocked = FALSE;
            }
        }
        canStart = isBlocked == FALSE ? 1 : 0;
    }
    if (canStart != 0) {
        StructMQRacerEntry_SomeFn_59(kart, direction, 0);
        started = TRUE;
    } else {
        started = FALSE;
    }
    if (started == FALSE) {
        return;
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        GetGlobalRK()->mMapObjectHitCount++;
    }
    kart->mDriveFlags |= KART_DRIVE_HIT_STATE;
}

void StartKartPushFlipOnHitByMapObject(Kart *kart, s32 direction, MapObject *mapObject) {
    if (TryStartKartPushFlipFromMapObject(kart, mapObject) == FALSE) {
        return;
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        GetGlobalRK()->mMapObjectHitCount++;
    }
    kart->mDriveFlags |= KART_DRIVE_HIT_STATE;
}

void StartKartPushDoubleFlipOnHit(Kart *kart, const Vec3 *direction) {
    s32 canStart;
    BOOL isBlocked;
    s32 inOtherState;
    BOOL started;
    u32 kartBits;
    s32 state;

    kartBits = kart->mEffectFlags;
    if ((kartBits & KART_EFFECT_BLINK_GUARD) != 0) {
        canStart = 0;
    } else if ((kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) != 0) {
        if (kart->mState == KART_STATE_NORMAL && (kart->mDriveFlags & KART_DRIVE_RESPAWNING) == 0 &&
            (kartBits & KART_EFFECT_STAR_OR_KILLER) == 0) {
            canStart = 1;
        } else {
            canStart = 0;
        }
    } else {
        isBlocked = TRUE;
        if ((kartBits & KART_EFFECT_STAR_OR_KILLER) == 0 && (kart->mDriveFlags & KART_DRIVE_RESPAWNING) == 0) {
            inOtherState = 0;
            state = kart->mState;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                inOtherState = isBlocked;
            }
            if (inOtherState == 0) {
                isBlocked = FALSE;
            }
        }
        canStart = isBlocked == FALSE ? 1 : 0;
    }
    if (canStart != 0) {
        StructMQRacerEntry_SomeFn_4(kart, direction, 0);
        started = TRUE;
    } else {
        started = FALSE;
    }
    if (started == FALSE) {
        return;
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        GetGlobalRK()->mMapObjectHitCount++;
    }
    kart->mDriveFlags |= KART_DRIVE_HIT_STATE;
}

s32 CollideKartWithMapObjectResponse0(Kart *kart, s32 *output) {
    *output = 0;
    return 0;
}

s32 CollideKartWithMapObjectResponse2(Kart *kart, s32 *output) {
    *output = 2;
    return 0xb;
}

int CollideKartWithMapObjectResponse3(Kart *kart, s32 *result, MapObject *mapObject) {
    if (kart->mVelocityLength > KART_MAP_OBJECT_SPIN_MIN_SPEED ||
        (mapObject->mFlags & MAP_OBJECT_FLAG_HIT_AT_ANY_SPEED)) {
        if (StructMQRacerEntry_SomeFn_27(kart, 1, 0)) {
            if (kart->mKartModelsEntry->mKartModelHidden == 0) {
                StartEffect(0xc, &kart->mPos);
                StartEffect(0xd, &kart->mPos);
                StartEffect(0xe, &kart->mPos);
            }
            if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
                GetGlobalRK()->mMapObjectHitCount++;
            }
        }
        *result = 3;
    } else {
        *result = 2;
    }
    return 0xb;
}

int CollideKartWithMapObjectResponse4(Kart *kart, s32 *result, MapObject *mapObject) {
    if (kart->mVelocityLength > KART_MAP_OBJECT_SPIN_MIN_SPEED ||
        (mapObject->mFlags & MAP_OBJECT_FLAG_HIT_AT_ANY_SPEED)) {
        if (StructMQRacerEntry_SomeFn_27(kart, 2, 0)) {
            if (kart->mKartModelsEntry->mKartModelHidden == 0) {
                StartEffect(0xc, &kart->mPos);
                StartEffect(0xd, &kart->mPos);
                StartEffect(0xe, &kart->mPos);
            }
            if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
                GetGlobalRK()->mMapObjectHitCount++;
            }
        }
        *result = 4;
    } else {
        *result = 2;
    }
    return 0xb;
}

int CollideKartWithMapObjectResponse6(Kart *kart, s32 *result, MapObject *mapObject) {
    if (kart->mVelocityLength > KART_MAP_OBJECT_SPIN_MIN_SPEED ||
        (mapObject->mFlags & MAP_OBJECT_FLAG_HIT_AT_ANY_SPEED)) {
        if (StructMQRacerEntry_SomeFn_27(kart, 2, 0)) {
            if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
                GetGlobalRK()->mMapObjectHitCount++;
            }
            StartKartSpinSideEffects(kart->mIndex);
        }
        *result = 4;
    } else {
        *result = 0;
    }
    return 0;
}

int CollideKartWithMapObjectResponse5(Kart *kart, s32 *result) {
    if (StructMQRacerEntry_SomeFn_27(kart, 2, 0)) {
        if (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) {
            SetupKartFollowEffectWithVelocity(StartEffect(0x4f, &kart->mPos), kart->mIndex, 0x46);
        }
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            GetGlobalRK()->mMapObjectHitCount++;
        }
    }
    *result = 5;
    return 0;
}

int CollideKartWithMapObjectResponse7(Kart *kart, s32 *result) {
    if (StructMQRacerEntry_SomeFn_65(kart)) {
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            GetGlobalRK()->mMapObjectHitCount++;
        }
        kart->mDriveFlags |= KART_DRIVE_HIT_STATE;
    }
    *result = 7;
    return 2;
}

int CollideKartWithMapObjectResponse8(Kart *kart, s32 *output) {
    *output = 8;
    return 2;
}

int CollideKartWithMapObjectResponse9(Kart *kart, s32 *output) {
    *output = 9;
    return 2;
}

int CollideKartWithMapObjectResponse10(Kart *kart, s32 *output) {
    *output = 0xa;
    return 2;
}

int CollideKartWithMapObjectResponse12(Kart *kart, s32 *output) {
    *output = 0xc;
    return 5;
}

s32 CollideKartWithMapObjectResponse13(Kart *kart, s32 *output) {
    *output = 0xc;
    kart->mDriveFlags &= ~(KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST | KART_DRIVE_MINI_TURBO |
                           KART_DRIVE_KINOKO_BOOST | KART_DRIVE_ITEM_BOOST);
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        if ((kart->mEffectFlags & KART_EFFECT_KILLER) == 0 &&
            (kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT) == 0) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    kart->mForwardSpeed = 0;
    return 5;
}

s32 CollideKartWithMapObjectResponse14(Kart *kart, s32 *output) {
    *output = 0xc;
    kart->mDriveFlags &= ~(KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST | KART_DRIVE_MINI_TURBO |
                           KART_DRIVE_KINOKO_BOOST | KART_DRIVE_ITEM_BOOST);
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        if ((kart->mEffectFlags & KART_EFFECT_KILLER) == 0 &&
            (kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT) == 0) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    if (StructMQRacerEntry_SomeFn_27(kart, 1, 0) != FALSE) {
        StartKartSpinFollowEffect(kart->mIndex);
    }
    return 5;
}

s32 CollideKartWithMapObjectResponse11(Kart *kart, s32 *output, s32 mapObject) {
    if (TryStartKartScaleTableEffect(kart) != FALSE && kart->mScaleEffectMapObject != (struct MapObject *) mapObject &&
        (kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        GetGlobalRK()->mMapObjectHitCount++;
    }
    *output = 0;
    return 0;
}

s32 ApplyKartSurfaceStopEffects(Kart *kart) {
    ApplyKartSurfaceEffect(gKartSurfaceStopEffects[kart->mSurfaceVariant], kart);
    return 0;
}

s32 ApplyKartSurfaceKind20(Kart *kart) {
    ApplyKartSurfaceEffect(gKartSurfaceKind20Effects[kart->mSurfaceVariant], kart);
    return 0;
}

s32 ApplyKartSurfaceKind1(Kart *kart) {
    ApplyKartSurfaceEffect(gKartSurfaceKind1Effects[kart->mSurfaceVariant], kart);
    return 5;
}

s32 ApplyKartSurfaceKind2(Kart *kart) {
    IncrementEntryKartSurfaceCount(kart);
    ApplyKartSurfaceEffect(gKartSurfaceKind2Effects[kart->mSurfaceVariant], kart);
    return 2;
}

s32 ApplyKartSurfaceKind3(Kart *kart) {
    IncrementEntryKartSurfaceCount(kart);
    ApplyKartSurfaceEffect(gKartSurfaceKind3Effects[kart->mSurfaceVariant], kart);
    return 3;
}

s32 ApplyKartSurfaceKind5(Kart *kart) {
    IncrementEntryKartSurfaceCount(kart);
    ApplyKartSurfaceEffect(gKartSurfaceKind5Effects[kart->mSurfaceVariant], kart);
    return 4;
}

s32 ApplyKartSurfaceKind6(Kart *kart) {
    ApplyKartSurfaceEffect(gKartSurfaceKind6Effects[kart->mSurfaceVariant], kart);
    return 6;
}

s32 ApplyKartSurfaceBoost(Kart *kart) {
    KartSurfaceSoundIds soundIds;
    PlayingSound *sound;

    if (kart->mSurfaceGroup != KART_SURFACE_GROUP_BOOST_A || (kart->mMotionFlags & KART_MOTION_STATE_RESET) != 0) {
        StructMQRacerEntry_SomeFn_74(kart, KART_BOOST_ITEM_OR_SURFACE, KART_SURFACE_BOOST_FRAMES);
        soundIds = gKartSurfaceSoundIds;
        if (kart->mSurfaceVariant > 0 && (kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
            sound = StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, soundIds.mSoundIds[kart->mSurfaceVariant - 1], 0x7f, 0);
            if (sound != NULL) {
                sound->mFlags = sound->mFlags | 0x10;
            }
        }
    } else {
        kart->mBoostTimer = KART_SURFACE_BOOST_FRAMES;
    }
    StopKartCurrentEffects(kart);
    return 8;
}

s32 ApplyKartSurfaceJumpPad(Kart *kart) {
    if (kart->mSurfaceGroup != KART_SURFACE_GROUP_BOOST_A || (kart->mMotionFlags & KART_MOTION_STATE_RESET) != 0) {
        if (g_GlobalCO->mCourseId == COURSE_ID_OLD_KOOPA_AGB || g_GlobalCO->mCourseId == COURSE_ID_OLD_SKY_AGB) {
            StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0x15e, 0x7f, 0);
        }
    }
    kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_JUMP_PAD;
    kart->mVerticalSpeed = gKartJumpPadVerticalSpeeds[kart->mSurfaceVariant];
    kart->mSurfaceSpeedLimitGoal = gKartJumpPadSpeedLimitGoals[kart->mSurfaceVariant];
    StopKartCurrentEffects(kart);
    return 8;
}

s32 ApplyKartSurfaceBoostWithSpeedFloor(Kart *kart) {
    KartSurfaceSoundIds soundIds;
    PlayingSound *sound;

    if (kart->mSurfaceGroup != KART_SURFACE_GROUP_BOOST_A || (kart->mMotionFlags & KART_MOTION_STATE_RESET) != 0) {
        StructMQRacerEntry_SomeFn_74(kart, KART_BOOST_ITEM_OR_SURFACE, KART_SURFACE_BOOST_FRAMES);
        soundIds = gKartSurfaceSoundIds;
        if (kart->mSurfaceVariant > 0 && (kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
            sound = StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, soundIds.mSoundIds[kart->mSurfaceVariant - 1], 0x7f, 0);
            if (sound != NULL) {
                sound->mFlags = sound->mFlags | 0x10;
            }
        }
    } else {
        kart->mBoostTimer = KART_SURFACE_BOOST_FRAMES;
    }
    StopKartCurrentEffects(kart);
    kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_BOOST_SPEED_FLOOR;
    return 8;
}

s32 ApplyKartSurfaceKeyedPlacement(Kart *kart) {
    u16 surfaceVariant;

    ApplyKartSurfaceEffect(0, kart);
    if ((kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT) == 0) {
        surfaceVariant = kart->mSurfaceVariant;
        if (g_GlobalCO->mMode == MODE_BATTLE || g_GlobalCO->mMode == MODE_MISSION_RUN) {
            PlaceKartAtKeyedPlacement(kart, surfaceVariant);
        } else {
            kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_KEYED_PLACEMENT;
            ResetKartMotionState(kart, 0);
        }
    }
    return 9;
}

s32 ApplyKartSurfaceKind17(Kart *kart) {
    ApplyKartSurfaceEffect(gKartSurfaceKind17Effects[kart->mSurfaceVariant], kart);
    return 0xa;
}

s32 ApplyKartSurfaceBoostHeld(Kart *kart) {
    PlayingSound *sound;

    if (kart->mSurfaceGroup != KART_SURFACE_GROUP_BOOST_B || (kart->mMotionFlags & KART_MOTION_STATE_RESET) != 0) {
        StructMQRacerEntry_SomeFn_74(kart, KART_BOOST_ITEM_OR_SURFACE, KART_SURFACE_BOOST_FRAMES);
        if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
            sound = StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0x1b9, 0x7f, 0);
            if (sound != NULL) {
                sound->mFlags = sound->mFlags | 0x10;
            }
        }
    } else {
        kart->mBoostTimer = KART_SURFACE_BOOST_FRAMES;
    }
    kart->mDriveFlags = kart->mDriveFlags | (KART_DRIVE_ON_BOOST_SURFACE | KART_DRIVE_BOOST_SURFACE_HELD);
    StopKartCurrentEffects(kart);
    return 0xb;
}

s32 ApplyKartSurfaceKind10(Kart *kart) {
    ApplyKartSurfaceEffect(gKartSurfaceKind10Effects[kart->mSurfaceVariant], kart);
    return 0;
}

u32 StructMQRacerEntry_SomeFn_51(Kart *kart) {
    KartTurnEffects *turnEffects;
    u32 level4Present;

    turnEffects = GetKartTurnEffects(kart->mIndex);
    if (turnEffects->mLevel4StopRequested != FALSE) {
        level4Present = 0;
    } else {
        level4Present = turnEffects->mLevel4Present;
    }
    return (turnEffects->mLevel3Present | (turnEffects->mTurnStartPresent | level4Present)) != 0 ? 1 : 0;
}

void AdvanceKartAi(Kart *kart) {
    Vec3 offset;
    Kart *entryKart;
    u32 kartBits;

    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_CPU) == 0) {
        return;
    }
    if ((kartBits & KART_ENTRY_DID_NOT_FINISH) != 0) {
        return;
    }
    if (IsAwardOrStaffRoll() != 1) {
        return;
    }
    if (g_GlobalPE->mRaceRouteCount == 0 && g_GlobalPE->mBattleRouteCount == 0) {
        return;
    }
    CallKartAiAdvance(kart->mAi);
    if (kart->mIndex != GetRaceUpdateFramesMod8()) {
        return;
    }
    if (g_GlobalCO->mMode != MODE_GRAND_PRIX) {
        return;
    }
    entryKart = GetRacerMQEntry(g_GlobalCO->mEntryIndex);
    VecFx32_Subtract(&kart->mPos, &entryKart->mPos, &offset);
    offset.x = FROM_FIXED12(offset.x);
    offset.y = FROM_FIXED12(offset.y);
    offset.z = FROM_FIXED12(offset.z);
    if (offset.x * offset.x + offset.y * offset.y + offset.z * offset.z > 0x271000) {
        kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_FAR_FROM_ENTRY;
    } else {
        kart->mDriveFlags = kart->mDriveFlags & ~KART_DRIVE_FAR_FROM_ENTRY;
    }
}

void StructMQRacerEntry_SomeFn_21(Kart *kart) {
    RaceSetup *raceSetup;
    CourseMap *courseMap;
    KartEntryPlayer *player;
    u32 value;
    s32 soundOffset;
    u16 index;
    u32 framesSinceEntryEnd;
    KartItemEffectState *effectState;
    u32 flag;

    if ((kart->mEntryFlags & KART_ENTRY_RACE_END_STARTED) != 0) {
        return;
    }
    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_RACE_END_STARTED;
    if ((kart->mEntryFlags & KART_ENTRY_WIFI_PEER) == 0) {
        courseMap = g_GlobalPE;
        if ((courseMap->mRaceRouteCount != 0 || courseMap->mBattleRouteCount != 0) && IsRacerFinishedRace(kart->mIndex) != 0) {
            raceSetup = g_GlobalCO;
            index = kart->mIndex;
            player = &raceSetup->mCurrentEntries[index].mPlayer;
            value = 0;
            if (player->mKind <= PLAYER_KIND_PEER && ((1 << player->mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                value = 1;
            }
            if (value != 0) {
                value = kart->mEntryFlags;
                if ((value & (KART_ENTRY_CPU | KART_ENTRY_GHOST)) == 0 && (value & KART_ENTRY_ENDED) == 0) {
                    g_GlobalCYT[kart->mEntryIndex].mSourceKind = INPUT_SOURCE_REQUESTED_BITS;
                    if (g_GlobalMV->mKarts[kart->mIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
                        CallKartAiSetup(kart->mAi, kart->mIndex);
                        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_CPU;
                        if ((kart->mEntryFlags & KART_ENTRY_CPU) != 0) {
                            for (index = 0; index < 12; index++) {
                                if (index != 0) {
                                    kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[index] =
                                        kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[index] << 2;
                                    if (kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[index] >
                                        kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[0]) {
                                        kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[index] =
                                            kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[0];
                                    }
                                }
                            }
                        }
                    } else {
                        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_ENDED;
                    }
                }
            } else if (raceSetup->mRuleKind == RULE_KIND_WIN_COUNT &&
                       g_GlobalMV->mKarts[kart->mIndex].mStatus != RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
                kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_DID_NOT_FINISH;
            } else if (raceSetup->mMode == MODE_MISSION_RUN) {
                kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_DID_NOT_FINISH;
                kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_SLOWING_STOP;
            }
            if ((kart->mEntryFlags & KART_ENTRY_GHOST) != 0) {
                StructMQRacerEntry_SomeFn_35(kart, 0);
            }
        }
    }
    StructMQRacerEntry_SomeFn_37(kart);
    StopOrthoQuads(kart->mIndex);
    ReleaseKartStarEffects(kart->mIndex);
    if ((kart->mEffectFlags & KART_EFFECT_STAR) != 0) {
        kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_STAR;
        StopKartStarModels(kart);
        kart->mItemEffect = KART_ITEM_EFFECT_NONE;
        StopKartStarEffects(kart->mIndex);
        StructMQRacerEntry_SomeFn_32(kart, 0, 1);
        if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0 && g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
            StopKartStarSeq();
        }
        if ((kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) != 0) {
            StructMQRacerEntry_SomeFn_36(kart);
        }
    }
    effectState = &kart->mItemEffectData;
    if ((kart->mEffectFlags & KART_EFFECT_KILLER) != 0 && effectState->mKillerEnding == FALSE) {
        effectState->mKillerEnding = TRUE;
        if ((kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) != 0) {
            kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_KILLER_ENDING;
        }
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        SetRaceUpdateFramesAtEntryEnd();
        raceSetup = g_GlobalCO;
        if (raceSetup->mMode != MODE_GRAND_PRIX && raceSetup->mMode != MODE_TIME_ATTACK &&
            ((raceSetup->mRuleKind == RULE_KIND_WIN_COUNT &&
              g_GlobalMV->mKarts[kart->mIndex].mStatus != RACE_PROGRESS_KART_STATUS_GOAL_REACHED) ||
             ((index = raceSetup->mKartCount) > 1 && (value = GetSomeRacerFlags(kart->mIndex), value == index)))) {
            DisableEntryCameraUpdate();
        } else {
            StartEntryCameraAngleStart();
            SwitchCourseCameraEffectsToCurrentCamera();
        }
    } else if (g_GlobalCO->mMode == MODE_VS || g_GlobalCO->mMode == MODE_WIFI) {
        if (g_GlobalMV->mKarts[kart->mIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
            framesSinceEntryEnd = 0;
            if (TryGetRaceUpdateFramesSinceEntryEnd(&framesSinceEntryEnd) != 0 &&
                framesSinceEntryEnd > 0xb4) {
                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x45);
            }
        }
    }
    raceSetup = g_GlobalCO;
    if (raceSetup->mMode == MODE_BATTLE) {
        return;
    }
    flag = 1;
    if (gSoundModeHolder.mMode != SCENE_SOUND_MODE_PLAYING &&
        gSoundModeHolder.mMode != SCENE_SOUND_MODE_MAIN_SEQUENCE_ONLY) {
        flag = 0;
    }
    if (flag == 0) {
        return;
    }
    if (kart->mIndex == raceSetup->mEntryIndex) {
        value = GetRaceEndResultKind();
        switch (value) {
            case RACE_END_RESULT_BEST:
                soundOffset = 9;
                break;
            case RACE_END_RESULT_WON:
                soundOffset = 0xa;
                break;
            case RACE_END_RESULT_LOST:
                soundOffset = 0xb;
                break;
        }
        StartKartSeqArcSoundWithVolume(kart->mSoundIndex, soundOffset, 0x6e, 7, -1);
        return;
    }
    soundOffset = GetKartSeqArcSoundOffsetByRank(GetSomeRacerFlags(kart->mIndex));
    if ((kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT)) != 0) {
        return;
    }
    StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, soundOffset);
}

void StructMQRacerEntry_SomeFn_77(Kart *kart) {
    MtxFx43 rotationMatrix;
    s32 angleAmplitude;
    s32 angleValue;
    u16 angle;
    s32 amplitudeDelta;

    kart->mWobbleAngle = kart->mWobbleAngle + gKartWobbleAnglePerCall;
    kart->mWobbleSine = FX_SinIdx(kart->mWobbleAngle);
    if (kart->mWobbleAmplitude > 0) {
        kart->mWobbleAmplitude = MUL_FIXED12_ROUNDED(kart->mWobbleAmplitude, gKartWobbleAmplitudeDecay);
        kart->mWobbleAmplitude = kart->mWobbleAmplitude - 0x64;
        if ((kart->mMotionFlags & KART_MOTION_ON_GROUND) == 0 ||
            (kart->mForwardSpeed > 0 ? kart->mForwardSpeed : -kart->mForwardSpeed) < 0x3000) {
            kart->mWobbleAmplitude = MUL_FIXED12_ROUNDED(kart->mWobbleAmplitude, 0xe66);
        }
        if (kart->mWobbleAmplitude < 0) {
            kart->mWobbleAmplitude = 0;
        }
    }
    amplitudeDelta = kart->mWobbleDirection * kart->mWobbleAmplitude - kart->mWobbleEasedAmplitude;
    kart->mWobbleEasedAmplitude =
        kart->mWobbleEasedAmplitude + MUL_FIXED12_ROUNDED(amplitudeDelta, gKartWobbleEaseFactor);
    angleAmplitude = MUL_FIXED12_ROUNDED(kart->mWobbleEasedAmplitude, gKartWobbleAngleFactor);
    angleValue = MUL_FIXED12_ROUNDED(angleAmplitude, kart->mWobbleSine);
    angle = angleValue;
    MTX_RotY43__from_thumb(&rotationMatrix, FX_SinIdx(angle), FX_CosIdx(angle));
    MTX_Concat43(&rotationMatrix, &kart->mDrawBaseMatrix, &kart->mWobbleMatrix);
    if ((kart->mWobbleEasedAmplitude > 0 ? kart->mWobbleEasedAmplitude : -kart->mWobbleEasedAmplitude) >= 0x29) {
        return;
    }
    kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_WOBBLE;
    kart->mWobbleAngle = 0;
    kart->mWobbleSine = 0;
    kart->mWobbleAmplitude = 0;
    kart->mWobbleDirection = 0;
}

// Applies the newest record of a peer kart, or queues it for its frame, and turns its bits into key requests.
void StructMQRacerEntry_SomeFn_78(Kart *kart) {
    ParticipantKartRecordState *state;
    ParticipantKartRecordNode *node;
    ParticipantKartRecordState *stateAgain;
    WiFiRaceSyncEntry *entry;
    ParticipantKartRecord *record;
    s32 difference;
    s32 appliedNow;
    s16 negatedDifference;
    u32 participantSyncFrames;
    ParticipantKartRecordNode *pendingNode;
    ParticipantKartRecordNode *nextNode;

    state = kart->mParticipantRecordData;
    appliedNow = 0;
    participantSyncFrames = GetParticipantSyncFrames(((u8 *) g_GlobalRE)[kart->mIndex & 0xff]);
    state->mPosBlendFactor = IsAwardOrStaffRoll() == 1 ? 0x333 : appliedNow;
    if (participantSyncFrames > state->mLastSyncCount) {
        entry =
            GetParticipantEntryAtSyncFrames(((u8 *) g_GlobalRE)[kart->mIndex & 0xff], participantSyncFrames);
        record = entry != NULL ? &entry->mKartRecord : 0;
        if (record != NULL) {
            difference = g_GlobalAA->mSyncFrames - participantSyncFrames;
            if (difference < 0) {
                negatedDifference = -difference;
                node = IntrusiveListWrapper_GetAtIndex(&state->mFreeRecords, 0);
                if (node != NULL) {
                    IntrusiveListWrapper_RemoveItem(&state->mFreeRecords, node);
                    node->mRecord = *record;
                    node->mApplyTimer = negatedDifference + 1;
                    IntrusiveListWrapper_InsertLast(&state->mPendingRecords, node);
                }
                stateAgain = kart->mParticipantRecordData;
                stateAgain->mEasedTurnAngle =
                    stateAgain->mEasedTurnAngle +
                    MUL_FIXED12_ROUNDED(stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle, 0x333);
                kart->mTurnAngle = stateAgain->mEasedTurnAngle;
            } else {
                if (difference > 0x19) {
                    difference = 0x19;
                }
                StructMQRacerEntry_SomeFn_19(kart, record, difference);
                appliedNow = 1;
            }
        }
        state->mLastSyncCount = participantSyncFrames;
    } else {
        stateAgain = kart->mParticipantRecordData;
        stateAgain->mEasedTurnAngle =
            stateAgain->mEasedTurnAngle +
            MUL_FIXED12_ROUNDED(stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle, 0x333);
        kart->mTurnAngle = stateAgain->mEasedTurnAngle;
    }
    stateAgain = kart->mParticipantRecordData;
    pendingNode = IntrusiveListWrapper_NextItem(&stateAgain->mPendingRecords, NULL);
    while (pendingNode != NULL) {
        nextNode = IntrusiveListWrapper_NextItem(&stateAgain->mPendingRecords, pendingNode);
        pendingNode->mApplyTimer = pendingNode->mApplyTimer - 1;
        if (pendingNode->mApplyTimer <= 0) {
            if (appliedNow == 0) {
                StructMQRacerEntry_SomeFn_19(kart, &pendingNode->mRecord, 0);
            }
            IntrusiveListWrapper_RemoveItem(&stateAgain->mPendingRecords, pendingNode);
            IntrusiveListWrapper_InsertLast(&stateAgain->mFreeRecords, pendingNode);
            if (nextNode == NULL) {
                break;
            }
            pendingNode = nextNode;
        }
        pendingNode = IntrusiveListWrapper_NextItem(&stateAgain->mPendingRecords, pendingNode);
    }
    if ((kart->mParticipantRecordData->mRecordBits & KART_DRIVE_ACCEL_HELD) != 0) {
        RequestBits(kart->mEntryIndex, PAD_KEY_A);
    }
    if ((kart->mParticipantRecordData->mRecordBits & KART_DRIVE_BRAKE_HELD) != 0) {
        RequestBits(kart->mEntryIndex, PAD_KEY_B);
    }
    if ((kart->mParticipantRecordData->mRecordBits & KART_DRIVE_TURN_LEFT) != 0) {
        RequestBits(kart->mEntryIndex, PAD_KEY_LEFT);
    }
    if ((kart->mParticipantRecordData->mRecordBits & KART_DRIVE_TURN_RIGHT) != 0) {
        RequestBits(kart->mEntryIndex, PAD_KEY_RIGHT);
    }
    if ((kart->mParticipantRecordData->mRecordBits & KART_DRIVE_ON_BOOST_SURFACE) != 0) {
        kart->mMotionFlags = kart->mMotionFlags | KART_MOTION_ON_GROUND;
    }
    if ((kart->mParticipantRecordData->mRecordBits & KART_DRIVE_BOOST) != 0) {
        kart->mBoostTimer = KART_RECORDED_BOOST_FRAMES;
        kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_BOOST;
    } else {
        kart->mBoostTimer = 0;
        kart->mDriveFlags = kart->mDriveFlags & ~KART_DRIVE_BOOST;
    }
}

static inline void SetSideSignedDirection(Kart *entryKart, Kart *sourceKart, Vec3 *direction) {
    Vec3 offset;
    Vec3 crossProduct;

    *direction = sourceKart->mRotationRow0;
    VecFx32_Subtract(&entryKart->mPos, &sourceKart->mPos, &offset);
    VecFx32_CrossProduct(&sourceKart->mRotationRow2, &offset, &crossProduct);
    if (Vector3_DotProduct(&crossProduct, &sourceKart->mRotationRow1) < 0) {
        direction->x = -direction->x;
        direction->y = -direction->y;
        direction->z = -direction->z;
    }
}

void StructMQRacerEntry_SomeFn_19(Kart *kart, ParticipantKartRecord *record, s32 stepCount) {
    Vec3 newPos;
    Vec3 moveStep;
    Vec3 headingAxis;
    Vec3 axisOffset;
    Vec3 collisionOffset;
    Vec3 prevPos;
    MtxFx33 turnMatrix;
    MtxFx33 fixedAngleMatrix;
    u32 hitAttributes;
    u32 recordFlags;
    ParticipantKartRecordState *state;
    s32 wasOnGround;
    u16 index;
    u16 value;
    ParticipantKartRecordState *stateAgain;
    s32 scale;
    s32 startedState;
    Kart *otherKart;
    Kart *sourceKart;
    s32 flag;
    u8 byte;
    Vec3 *axis;

    recordFlags = record->mFlags;
    wasOnGround = (kart->mMotionFlags & KART_MOTION_ON_GROUND) != 0;
    state = kart->mParticipantRecordData;
    newPos.x = record->mPosX << 10;
    newPos.y = record->mPosY << 10;
    newPos.z = record->mPosZ << 10;
    kart->mForwardSpeed = record->mForwardSpeed << 2;
    kart->mHeadingAngle = record->mHeadingAngle;
    state->mRecordBits = record->mDriveFlags;
    state->mRecordKartBits = record->mMotionFlagsAndPush;
    byte = state->mRecordKartBits >> 24;
    state->mPushDirection.x = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    byte = state->mRecordKartBits >> 16;
    state->mPushDirection.y = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    byte = state->mRecordKartBits >> 8;
    state->mPushDirection.z = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    state->mRecordKartBits = state->mRecordKartBits & KART_RECORD_MOTION_BYTE_MASK;
    state->mTargetTurnAngle = record->mTurnAngle;
    kart->mTurnAngle = record->mTurnAngle;
    if (wasOnGround) {
        kart->mMotionFlags |= KART_MOTION_ON_GROUND;
    } else {
        kart->mMotionFlags &= ~KART_MOTION_ON_GROUND;
    }
    if (kart->mParticipantRecordData->mRecordKartBits & KART_MOTION_HOPPING) {
        kart->mMotionFlags |= KART_MOTION_HOPPING;
    } else {
        kart->mMotionFlags &= ~KART_MOTION_HOPPING;
    }
    if (kart->mParticipantRecordData->mRecordKartBits & KART_MOTION_DRIFTING) {
        kart->mMotionFlags |= KART_MOTION_DRIFTING;
    } else {
        kart->mMotionFlags &= ~KART_MOTION_DRIFTING;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_RESPAWN) != 0) !=
        ((recordFlags & KART_EVENT_RESPAWN) != 0)) {
        value = kart->mHeadingAngle;
        StructMQRacerEntry_SomeFn_63(kart, &newPos, 0, 0);
        kart->mHeadingAngle = value;
        headingAxis = gParticipantRecordHeadingAxis;
        QuaternionFromAxisAngle(&headingAxis, kart->mHeadingAngle, &kart->mHeadingQuaternion);
        kart->mCombinedQuaternion = kart->mHeadingQuaternion;
        if (kart->mEntryFlags & KART_ENTRY_WIFI_PEER) {
            stateAgain = kart->mParticipantRecordData;
            stateAgain->mSmoothedPos = kart->mPos;
            stateAgain->mSmoothedDrawPos = stateAgain->mSmoothedPos;
            stateAgain->mSmoothedRotation = kart->mCombinedQuaternion;
            stateAgain->mPosOffset = gKartVec3Zero;
            stateAgain->mPosOffsetIndex = 0;
        }
    }
    if ((s64) (kart->mPos.x - newPos.x) * (kart->mPos.x - newPos.x) +
            (s64) (kart->mPos.y - newPos.y) * (kart->mPos.y - newPos.y) +
            (s64) (kart->mPos.z - newPos.z) * (kart->mPos.z - newPos.z) >=
        0x15f90000000LL) {
        switch (state->mPosOffsetIndex) {
            case 0:
                axis = &kart->mRotationRow2;
                axisOffset.x = MUL_FIXED12_NO_ROUND(axis->x, -0x7000);
                axisOffset.y = MUL_FIXED12_NO_ROUND(axis->y, -0x7000);
                axisOffset.z = MUL_FIXED12_NO_ROUND(axis->z, -0x7000);
                break;
            case 1:
                axis = &kart->mRotationRow2;
                axisOffset.x = MUL_FIXED12_NO_ROUND(axis->x, 0x7000);
                axisOffset.y = MUL_FIXED12_NO_ROUND(axis->y, 0x7000);
                axisOffset.z = MUL_FIXED12_NO_ROUND(axis->z, 0x7000);
                break;
            case 2:
                axis = &kart->mRotationRow0;
                axisOffset.x = MUL_FIXED12_NO_ROUND(axis->x, 0x7000);
                axisOffset.y = MUL_FIXED12_NO_ROUND(axis->y, 0x7000);
                axisOffset.z = MUL_FIXED12_NO_ROUND(axis->z, 0x7000);
                break;
            case 3:
            default:
                axis = &kart->mRotationRow0;
                axisOffset.x = MUL_FIXED12_NO_ROUND(axis->x, -0x7000);
                axisOffset.y = MUL_FIXED12_NO_ROUND(axis->y, -0x7000);
                axisOffset.z = MUL_FIXED12_NO_ROUND(axis->z, -0x7000);
                break;
        }
        state->mPosOffset = axisOffset;
        newPos.y += 0x14000;
        VecFx32_Add(&newPos, &axisOffset, &newPos);
        kart->mPos = newPos;
        kart->mPrevPos = kart->mPos;
        kart->mDrawMatrixPos = kart->mPrevPos;
        state->mSmoothedPos = kart->mDrawMatrixPos;
        kart->mUnk_25c = gKartVec3Zero;
        ComputeKartPointAlongUp(&kart->mCollisionCenter, &newPos, 0x400, kart);
        SetKartPrevCollisionCenter(kart);
        state->mPosOffsetIndex++;
        if (state->mPosOffsetIndex > 3) {
            state->mPosOffsetIndex = 0;
        }
    } else if (!(kart->mDriveFlags & KART_DRIVE_HIT_STATE)) {
        prevPos = kart->mPrevPos;
        VecFx32_Add(&newPos, &state->mPosOffset, &newPos);
        FindCollisionSlotsAroundPos(&newPos, stepCount * 0xd000 + kart->mRadius, 0x8000);
        for (index = 0; index < stepCount; index++) {
            if (kart->mDriveFlags & KART_DRIVE_SINKING) {
                kart->mPos.y -= 0x19a;
            } else {
                if (index < 3 && index < stepCount / 2) {
                    AdvanceKartTurnHeading(kart, ApplyKartTurnInput(kart, 0));
                }
                QuaternionFromAxisAngle(&g_UnitY_VecFx32, kart->mHeadingAngle, &kart->mHeadingQuaternion);
                QuaternionMultiply(&kart->mTiltQuaternion, &kart->mHeadingQuaternion, &kart->mCombinedQuaternion);
                Matrix4x3FromQuaternion(&kart->mRotationMatrix, &kart->mCombinedQuaternion);
                stateAgain = kart->mParticipantRecordData;
                stateAgain->mEasedTurnAngle =
                    stateAgain->mEasedTurnAngle +
                    MUL_FIXED12_ROUNDED(stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle, 0x333);
                kart->mTurnAngle = stateAgain->mEasedTurnAngle;
                MTX_RotAxis33(&turnMatrix, &kart->mRotationRow1, FX_SinIdx((u16) kart->mTurnAngle),
                              FX_CosIdx((u16) kart->mTurnAngle));
                if (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) {
                    MTX_RotAxis33(&fixedAngleMatrix, &kart->mRotationRow0, SIN_OF_ANGLE(0x5d0), COS_OF_ANGLE(0x5d0));
                    MTX_Concat33(&fixedAngleMatrix, &turnMatrix, &turnMatrix);
                }
                MTX_MultVec33(&kart->mForward, &turnMatrix, &kart->mTurnedForward);
                scale = kart->mForwardSpeed;
                moveStep.x = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.x, scale);
                moveStep.y = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.y, scale);
                moveStep.z = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.z, scale);
                VecFx32_Add(&newPos, &moveStep, &newPos);
                VecFx32_Add(&newPos, &kart->mHitVelocity, &newPos);
                VecFx32_Add(&kart->mVelocity, &kart->mHitVelocity, &kart->mVelocity);
                if (kart->mParticipantRecordData->mRecordBits & KART_DRIVE_ON_BOOST_SURFACE) {
                    kart->mVerticalSpeed = 0;
                }
                scale = (kart->mMotionFlags & KART_MOTION_ON_GROUND) ? 0xee1 : 0xfae;
                kart->mHitVelocity.x = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.x, scale);
                kart->mHitVelocity.y = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.y, scale);
                kart->mHitVelocity.z = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.z, scale);
                if ((s64) kart->mHitVelocity.x * kart->mHitVelocity.x +
                        (s64) kart->mHitVelocity.y * kart->mHitVelocity.y +
                        (s64) kart->mHitVelocity.z * kart->mHitVelocity.z >=
                    0xa429) {
                    kart->mMotionFlags |= KART_MOTION_HIT_VELOCITY;
                } else {
                    kart->mHitVelocity = gKartVec3Zero;
                    kart->mMotionFlags &= ~KART_MOTION_HIT_VELOCITY;
                }
            }
            if (CollideSphereWithCourse(&newPos, &prevPos, 0, kart->mRadius, 1, kart->mCollisionSlot, &collisionOffset,
                                        0, 0, &hitAttributes, 0, 0, 0, 0)) {
                VecFx32_Add(&newPos, &collisionOffset, &newPos);
            }
            prevPos = newPos;
        }
    }
    if (kart->mDriveFlags & KART_DRIVE_SINKING) {
        goto storeAppliedFlags;
    }
    kart->mPos.x = newPos.x;
    kart->mPos.z = newPos.z;
    startedState = 0;
    if (((kart->mParticipantRecordData->mAppliedFlags & 1) != 0) != ((recordFlags & 1) != 0) &&
        (kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        stateAgain = ((volatile Kart *) kart)->mParticipantRecordData;
        stateAgain->mHopSpeed = KART_HOP_SPEED;
        stateAgain->mHopHeight = 0;
        kart->mVerticalSpeed += KART_HOP_VERTICAL_SPEED;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_LAUNCH_DOUBLE_FLIP) != 0) !=
        ((recordFlags & KART_EVENT_LAUNCH_DOUBLE_FLIP) != 0)) {
        StructMQRacerEntry_SomeFn(kart);
        startedState = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_SPIN_SINGLE) != 0) !=
        ((recordFlags & KART_EVENT_SPIN_SINGLE) != 0)) {
        StructMQRacerEntry_SomeFn_0(kart, 1, 0);
        startedState = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_SPIN_DOUBLE) != 0) !=
        ((recordFlags & KART_EVENT_SPIN_DOUBLE) != 0)) {
        StructMQRacerEntry_SomeFn_0(kart, 2, 0);
        startedState = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_FLIP) != 0) !=
        ((recordFlags & KART_EVENT_FLIP) != 0)) {
        StructMQRacerEntry_SomeFn_56(kart);
        startedState = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_STAR) != 0) !=
        ((recordFlags & KART_EVENT_STAR) != 0)) {
        StructMQRacerEntry_SomeFn_55(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_THUNDER) != 0) !=
        ((recordFlags & KART_EVENT_THUNDER) != 0)) {
        index = 0;
        StartFadeFog();
        StartEffectsAtOtherKarts(kart->mIndex);
        flag = kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL;
        if (flag) {
            if (flag) {
                kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_THUNDER;
            }
        } else {
            for (; index < (u32) g_GlobalCO->mKartCount; index++) {
                if (index != kart->mIndex) {
                    StructMQRacerEntry_SomeFn_26(GetRacerMQEntry(index));
                }
            }
        }
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_THUNDER_SHRINK) != 0) !=
        ((recordFlags & KART_EVENT_THUNDER_SHRINK) != 0)) {
        StructMQRacerEntry_SomeFn_26(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_KILLER) != 0) !=
        ((recordFlags & KART_EVENT_KILLER) != 0)) {
        StructMQRacerEntry_SomeFn_42(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_KILLER_ENDING) != 0) !=
        ((recordFlags & KART_EVENT_KILLER_ENDING) != 0)) {
        kart->mItemEffectData.mKillerEnding = TRUE;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_TERESA) != 0) !=
        ((recordFlags & KART_EVENT_TERESA) != 0)) {
        StructMQRacerEntry_SomeFn_54(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_DOUBLE_FLIP) != 0) !=
        ((recordFlags & KART_EVENT_PUSH_DOUBLE_FLIP) != 0)) {
        if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || kart->mState == KART_STATE_PUSH_FLIP) {
                goto skipPushBackStart;
            }
        } else if (kart->mState == KART_STATE_PUSH_DOUBLE_FLIP) {
            goto skipPushBackStart;
        }
        StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xe8, 0x7f, 0);
        StructMQRacerEntry_SomeFn_4(kart, &state->mPushDirection, 0);
    skipPushBackStart:
        if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_HIT_SOUND) != 0) !=
            ((recordFlags & KART_EVENT_HIT_SOUND) != 0)) {
            StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xe8, 0x7f, 0);
        }
    } else if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_FLIP) != 0) !=
               ((recordFlags & KART_EVENT_PUSH_FLIP) != 0)) {
        if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || kart->mState == KART_STATE_PUSH_FLIP) {
                goto skipFlipBackStart;
            }
        } else if (kart->mState == KART_STATE_PUSH_FLIP) {
            goto skipFlipBackStart;
        }
        StructMQRacerEntry_SomeFn_59(kart, &state->mPushDirection, 0);
    skipFlipBackStart:
        if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_HIT_SOUND) != 0) !=
            ((recordFlags & KART_EVENT_HIT_SOUND) != 0)) {
            StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0xe8, 0x7f, 0);
        }
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_AHEAD_BOOST) != 0) !=
        ((recordFlags & KART_EVENT_AHEAD_BOOST) != 0)) {
        StructMQRacerEntry_SomeFn_39(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_GESSO) != 0) !=
        ((recordFlags & KART_EVENT_GESSO) != 0)) {
        kart->mItemEffectData.mGessoFrames = 0;
        kart->mEffectFlags |= KART_EFFECT_GESSO;
        kart->mEffectFlags &= ~KART_EFFECT_COURSE_COLORED;
        if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
            StructMQRacerEntry_SomeFn_2(kart);
        }
        StartKartModelColorBlend(kart->mKartModelsEntry, 0, 0x1084, 0);
        if (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) {
            StructMQRacerEntry_SomeFn_7(kart, 1, 0);
            StructAD00Sub_SomeFn_1(kart->mKartModelsEntry, 1);
        }
        if (!(kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
            StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 0);
        }
        StartOrthoQuadsGesoSumi(kart->mIndex, 0);
    }
    if (startedState) {
        otherKart = GetRacerMQEntry((u16) ((recordFlags & KART_EVENT_SOURCE_KART_MASK) >> KART_EVENT_SOURCE_KART_SHIFT));
        if (otherKart != kart) {
            otherKart->mEffectFlags |= KART_EFFECT_START_SOUND_PENDING;
        }
    }
    otherKart = GetRacerMQEntry(g_GlobalCO->mEntryIndex);
    flag = 0;
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_DOUBLE_FLIP_HIT_FIRST) != 0) !=
            ((recordFlags & KART_EVENT_PUSH_DOUBLE_FLIP_HIT_FIRST) != 0) &&
        otherKart->mIndex == 0) {
        Vec3 direction;

        value = kart->mIndex;
        direction = g_UnitX_VecFx32;
        sourceKart = GetRacerMQEntry(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto markFirstKartPushed;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto markFirstKartPushed;
        }
        SetSideSignedDirection(otherKart, sourceKart, &direction);
        StructMQRacerEntry_SomeFn_8(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StructMQRacerEntry_SomeFn_4(otherKart, &direction, 0);
    markFirstKartPushed:
        flag = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_DOUBLE_FLIP_HIT_SECOND) != 0) !=
            ((recordFlags & KART_EVENT_PUSH_DOUBLE_FLIP_HIT_SECOND) != 0) &&
        otherKart->mIndex == 1) {
        Vec3 direction;

        value = kart->mIndex;
        direction = g_UnitX_VecFx32;
        sourceKart = GetRacerMQEntry(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto markSecondKartPushed;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto markSecondKartPushed;
        }
        SetSideSignedDirection(otherKart, sourceKart, &direction);
        StructMQRacerEntry_SomeFn_8(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StructMQRacerEntry_SomeFn_4(otherKart, &direction, 0);
    markSecondKartPushed:
        flag = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_DOUBLE_FLIP_HIT_THIRD) != 0) !=
            ((recordFlags & KART_EVENT_PUSH_DOUBLE_FLIP_HIT_THIRD) != 0) &&
        otherKart->mIndex == 2) {
        Vec3 direction;

        value = kart->mIndex;
        direction = g_UnitX_VecFx32;
        sourceKart = GetRacerMQEntry(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto markThirdKartPushed;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto markThirdKartPushed;
        }
        SetSideSignedDirection(otherKart, sourceKart, &direction);
        StructMQRacerEntry_SomeFn_8(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StructMQRacerEntry_SomeFn_4(otherKart, &direction, 0);
    markThirdKartPushed:
        flag = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_DOUBLE_FLIP_HIT_FOURTH) != 0) !=
            ((recordFlags & KART_EVENT_PUSH_DOUBLE_FLIP_HIT_FOURTH) != 0) &&
        otherKart->mIndex == 3) {
        Vec3 direction;

        value = kart->mIndex;
        direction = g_UnitX_VecFx32;
        sourceKart = GetRacerMQEntry(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto markFourthKartPushed;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto markFourthKartPushed;
        }
        SetSideSignedDirection(otherKart, sourceKart, &direction);
        StructMQRacerEntry_SomeFn_8(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StructMQRacerEntry_SomeFn_4(otherKart, &direction, 0);
    markFourthKartPushed:
        flag = 1;
    }
    if (flag) {
        goto storeAppliedFlags;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_FLIP_HIT_FIRST) != 0) !=
            ((recordFlags & KART_EVENT_PUSH_FLIP_HIT_FIRST) != 0) &&
        otherKart->mIndex == 0) {
        Vec3 direction;

        value = kart->mIndex;
        direction = g_UnitX_VecFx32;
        sourceKart = GetRacerMQEntry(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto skipFirstKartFlip;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto skipFirstKartFlip;
        }
        VecFx32_Subtract(&otherKart->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if (LENGTH_SQUARED(direction) >= 0x10) {
            Vector3_MaybeNormalize(&direction, &direction);
        }
        StructMQRacerEntry_SomeFn_8(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StructMQRacerEntry_SomeFn_59(otherKart, &direction, 0);
    skipFirstKartFlip:
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_FLIP_HIT_SECOND) != 0) !=
            ((recordFlags & KART_EVENT_PUSH_FLIP_HIT_SECOND) != 0) &&
        otherKart->mIndex == 1) {
        Vec3 direction;

        value = kart->mIndex;
        direction = g_UnitX_VecFx32;
        sourceKart = GetRacerMQEntry(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto skipSecondKartFlip;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto skipSecondKartFlip;
        }
        VecFx32_Subtract(&otherKart->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if (LENGTH_SQUARED(direction) >= 0x10) {
            Vector3_MaybeNormalize(&direction, &direction);
        }
        StructMQRacerEntry_SomeFn_8(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StructMQRacerEntry_SomeFn_59(otherKart, &direction, 0);
    skipSecondKartFlip:
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_FLIP_HIT_THIRD) != 0) !=
            ((recordFlags & KART_EVENT_PUSH_FLIP_HIT_THIRD) != 0) &&
        otherKart->mIndex == 2) {
        Vec3 direction;

        value = kart->mIndex;
        direction = g_UnitX_VecFx32;
        sourceKart = GetRacerMQEntry(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto skipThirdKartFlip;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto skipThirdKartFlip;
        }
        VecFx32_Subtract(&otherKart->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if (LENGTH_SQUARED(direction) >= 0x10) {
            Vector3_MaybeNormalize(&direction, &direction);
        }
        StructMQRacerEntry_SomeFn_8(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StructMQRacerEntry_SomeFn_59(otherKart, &direction, 0);
    skipThirdKartFlip:
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & KART_EVENT_PUSH_FLIP_HIT_FOURTH) != 0) !=
            ((recordFlags & KART_EVENT_PUSH_FLIP_HIT_FOURTH) != 0) &&
        otherKart->mIndex == 3) {
        Vec3 direction;

        value = kart->mIndex;
        direction = g_UnitX_VecFx32;
        sourceKart = GetRacerMQEntry(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto skipFourthKartFlip;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto skipFourthKartFlip;
        }
        VecFx32_Subtract(&otherKart->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if (LENGTH_SQUARED(direction) >= 0x10) {
            Vector3_MaybeNormalize(&direction, &direction);
        }
        StructMQRacerEntry_SomeFn_8(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StructMQRacerEntry_SomeFn_59(otherKart, &direction, 0);
    skipFourthKartFlip:
    }
storeAppliedFlags:
    kart->mParticipantRecordData->mAppliedFlags = recordFlags;
}
