#include "Main/Kart/kart_reset.h"
#include "Main/System/input_slots.h"
#include "Main/Race/race_score.h"
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

#include "Main/Kart/kart_participant_record.h"
#include "ITCM/kart_ground_contact.h"
#include "ITCM/collision_slots.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/rock.h"
#include "Main/Kart/kart_point_link_effects.h"
#include "Main/Kart/kart_ai_battle.h"
#include "Main/Sound/sound_handle_pool.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Kart/kart_name_tags.h"
#include "matrix_3x3_basic.h"
#include "matrix_4x3_basic.h"
#include "fixed_vector_math.h"
#include "fixed_arctangent.h"
#include "sound_archive_load_result.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Item/item_in_use.h"
#include "Main/Kart/camera.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Kart/kart_level.h"
#include "Main/Graphics/stem_sets.h"
#include "Main/Sound/sound_start.h"
#include "Main/Sound/kart_request_sort.h"
#include "Main/Sound/kart_sound_queue.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Sound/kart_sound_callbacks.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "Main/System/heap.h"
#include "linked_list_init.h"
#include "Main/Race/entry_race_ended.h"
#include "linked_list_ops.h"
#include "ITCM/kart_motion.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Kart/kart_course_colors.h"
#include "Main/Kart/kart_contact_effect_release.h"
#include "Main/Kart/kart_spin_follow_effect_release.h"
#include "Main/Kart/kart_killer_effect.h"
#include "Main/Kart/first_base_speed_limit.h"
#include "Main/Kart/kart_ai_staff_roll_advance.h"
#include "Main/Item/item_link_following.h"
#include "Main/Item/bouncing_item_box.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Sound/kart_track_params_reset.h"
#include "Main/Sound/seq_queue.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Kart/kart_call.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

const Vec3 g_UnitX_VecFx32 = {0x1000, 0, 0};
const Vec3 g_UnitY_VecFx32 = {0, 0x1000, 0};
const Vec3 g_UnitZ_VecFx32 = {0, 0, 0x1000};
const Vec3 gKartOffsetCycleStartAmount = {0x1000, 0x1000, 0x1000};
const Vec3 gKartVec3Zero = {0, 0, 0};

void AdvanceKartScaleFactor(Kart *kart) {
    s32 frameIndex;
    enum { ENTRY_INDEX_FIRST } entryIndex;

    entryIndex = kart->mEntryIndex;
    g_GlobalCYT[entryIndex].mBitMask = PAD_KEYS_NO_START;
    if (kart->mEntryFlags & KART_ENTRY_REMOVED) {
        StructMQRacerEntry_SomeFn_53(kart);
        return;
    }
    kart->mFramesSinceRemovalOrReset = kart->mFramesSinceRemovalOrReset + 1;
    frameIndex = kart->mFramesSinceRemovalOrReset;
    if (frameIndex >= 0x19) {
        kart->mEntryFlags &= ~KART_ENTRY_SCALING_IN;
        return;
    }
    kart->mScaleFactor.x = gKartScaleFactorXTable[frameIndex];
    kart->mScaleFactor.y = gKartScaleFactorYTable[frameIndex];
    kart->mScaleFactor.z = gKartScaleFactorZTable[frameIndex];
    kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
    kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
    kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
    kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
}

void StructMQRacerEntry_Fn6(Kart *kart) {
    Vec3 respawnPos;
    Vec3 respawnForward;
    Vec3 respawnAngles;
    Vec3 sideDirection;
    MtxFx33 rotationMatrix;
    PointLink *respawnLink;
    s32 value;
    s32 forwardOffset;
    s32 index;
    KartItems *kartItems;
    s64 sinValue;

    if (kart->mRespawnSlot == -1) {
        index = kart->mIndex;
        if (g_GlobalCO->mMode == MODE_BATTLE) {
            index = GetCourseCpoiRespawnId(0);
        } else {
            index = GetCourseCpoiRespawnId(g_GlobalMV->mKarts[index].mCheckpoint);
        }
        kart->mRespawnSlot = index;
    }
    index = (u16) kart->mRespawnSlot;
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        respawnLink = GetCourseMapRespawnBattlePointLink(index, &respawnPos, &respawnAngles);
    } else {
        respawnLink = GetCourseMapRespawnRacePointLink(index, &respawnPos, &respawnAngles);
    }
    index = DEG_TO_ANGLE_TRUNCATED(respawnAngles.y);
    MTX_RotY33__from_thumb(&rotationMatrix, SIN_OF_ANGLE(index), COS_OF_ANGLE(index));
    MTX_MultVec33(&g_UnitZ_VecFx32, &rotationMatrix, &respawnForward);
    if (g_GlobalCO->mMode != MODE_BATTLE && g_GlobalPE->mItemRouteCount != 0) {
        (kartItems = &gKartItems[kart->mIndex])->mItemLink.mLink =
            GetCourseMapRespawnItemPointLink(kart->mRespawnSlot);
        kartItems->mItemLink.mNextLinksUsed = 1;
    }
    if (g_GlobalCO->mMode != MODE_TIME_ATTACK) {
        value = gKartRespawnOffsets[kart->mIndex][0];
        forwardOffset = ((const s32 (*)[2]) &gKartRespawnOffsets[0][1])[kart->mIndex][0];
        Vector3_Cross(&g_UnitY_VecFx32, &respawnForward, &sideDirection);
        VecFx32_AddScale1(MUL_FIXED12_NO_ROUND(gKartRespawnOffsetScale, value), &sideDirection, &respawnPos, &respawnPos);
        VecFx32_AddScale1(MUL_FIXED12_NO_ROUND(gKartRespawnOffsetScale, forwardOffset), &respawnForward, &respawnPos,
                    &respawnPos);
        if (respawnAngles.x != 0 && forwardOffset != 0) {
            sinValue = SIN_OF_ANGLE(DEG_TO_ANGLE_TRUNCATED(respawnAngles.x));
            index = (sinValue * -forwardOffset + 0x800) >> 12;
            respawnPos.y += MUL_FIXED12_ROUNDED(index, gKartRespawnOffsetScale);
        }
        if (respawnAngles.z != 0 && value != 0) {
            sinValue = SIN_OF_ANGLE(DEG_TO_ANGLE_TRUNCATED(respawnAngles.z));
            index = (sinValue * value + 0x800) >> 12;
            respawnPos.y += MUL_FIXED12_ROUNDED(index, gKartRespawnOffsetScale);
        }
    }
    respawnPos.y += 0x28000;
    value = kart->mDriveFlags;
    if (value & KART_DRIVE_FALL_SOUND_A) {
        SetupKartFollowEffect(StartEffect(0x71, &respawnPos), kart->mIndex, 0x32);
    } else if (value & KART_DRIVE_FALL_SOUND_B) {
        SetupKartFollowEffect(StartEffect(0x70, &respawnPos), kart->mIndex, 0x32);
    }
    StructMQRacerEntry_SomeFn_63(kart, &respawnPos, &respawnForward, respawnLink);
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        GetGlobalRK()->mRespawnCount++;
    } else {
        ResetSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange);
    }
    kart->mEffectFlags |= KART_EFFECT_RESPAWN_BOOST_WINDOW | KART_EFFECT_RESPAWN_DROP;
    kart->mDriveFlags |= KART_DRIVE_RESPAWN_LANDING;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        StartDispCapFadeToClear(0x3c);
        SetEntryCameraUpdateHold(0);
    }
}

s32 AdvanceKartRespawnWait(Kart *kart, s32 *outVelocityScale) {
    BOOL finished;
    u32 flags;

    flags = kart->mEffectFlags;
    finished = FALSE;
    if (flags & KART_EFFECT_WATER_FALL) {
        if (kart->mRespawnWaitVelocityScale > KART_WATER_FALL_WAIT_MIN_SCALE) {
            kart->mRespawnWaitVelocityScale = MUL_FIXED12_NO_ROUND(kart->mRespawnWaitVelocityScale, 0xe66LL);
        }
        *outVelocityScale = kart->mRespawnWaitVelocityScale;
    } else if (flags & KART_EFFECT_RESPAWN_WAIT_SET) {
        if (kart->mRespawnWaitVelocityScale > KART_RESPAWN_WAIT_MIN_SCALE) {
            kart->mRespawnWaitVelocityScale = MUL_FIXED12_NO_ROUND(kart->mRespawnWaitVelocityScale, 0xe66LL);
        }
        *outVelocityScale = kart->mRespawnWaitVelocityScale;
    }
    kart->mRespawnFrames = kart->mRespawnFrames + 1;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        if (kart->mRespawnFrames == KART_RESPAWN_FADE_FLAG_FRAME) {
            SetDispCapFadeFlag();
        } else if (kart->mRespawnFrames == KART_RESPAWN_FADE_OUT_FRAME) {
            StartDispCapFadeToFaded(0x3c);
        }
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && kart->mRespawnFrames == KART_RESPAWN_FOLLOW_KART_FRAME) {
        SetJgFollowKart();
    } else if (kart->mRespawnFrames > KART_RESPAWN_END_FRAME) {
        RespawnKartAndToggleEventFlag(kart);
        finished = TRUE;
    }
    return finished;
}

void StructMQRacerEntry_SomeFn_63(Kart *kart, const Vec3 *position, const Vec3 *forward, PointLink *link) {
    ParticipantKartRecordState *recordState;
    Vec3 axis;

    StructMQRacerEntry_SomeFn_16(kart);
    StructAD00Sub_SomeFn_3(kart->mKartModelsEntry);
    kart->mSlotFunctions[1](kart);
    kart->mEntryFlags &= ~(KART_ENTRY_TERESA | KART_ENTRY_TRANSLUCENT | KART_ENTRY_NOT_DRAWN);
    StopOrthoQuads(kart->mIndex);
    kart->mDriveFlags |= KART_DRIVE_SINKING | KART_DRIVE_OBJECTS_SKIP;
    kart->mPos = *position;
    if (kart->mEntryFlags & KART_ENTRY_WIFI_PEER) {
        recordState = kart->mParticipantRecordData;
        recordState->mSmoothedPos = kart->mPos;
        recordState->mSmoothedDrawPos = recordState->mSmoothedPos;
        recordState->mSmoothedRotation = kart->mCombinedQuaternion;
        recordState->mPosOffset = gKartVec3Zero;
        recordState->mPosOffsetIndex = 0;
    }
    if (forward != NULL) {
        kart->mHeadingAngle = FROM_FIXED12(MUL_FIXED12_NO_ROUND(FX_Atan2(forward->x, forward->z), 0x28be60dLL));
        axis = gKartPlacementHeadingAxis;
        QuaternionFromAxisAngle(&axis, kart->mHeadingAngle, &kart->mHeadingQuaternion);
    }
    Matrix4x3FromQuaternion(&kart->mRotationMatrix, &kart->mHeadingQuaternion);
    GetMQRacerVector333(kart, &kart->mForward);
    kart->mTurnedForward = kart->mForward;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mPrevCollisionCenter = kart->mPos;
    kart->mCollisionCenter = kart->mPos;
    kart->mLastGroundY = kart->mPos.y;
    if (kart->mEntryFlags & KART_ENTRY_CPU) {
        if (link != NULL) {
            CallKartAiReset(kart->mAi, link);
        } else {
            CallKartAiSetup(kart->mAi, kart->mIndex);
        }
    }
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        ResetCameraBehind(position, &kart->mHeadingQuaternion);
        ResetCameraHalfFovAngle();
        nullsub_7();
        SetCameraHeightHold(0);
    }
}

void StructMQRacerEntry_SomeFn_16(Kart *kart) {
    s32 effectIndex;
    KartFollowEffectIds effectIds;

    ReleaseKartItems(&gKartItems[kart->mIndex]);
    StructMQRacerEntry_SomeFn_17(kart);
    ReleaseKartStarEffects(kart->mIndex);
    ReleaseKartKillerEffect(kart->mIndex);
    ReleaseKartContactEffect(kart->mIndex);
    ReleaseKartSpinFollowEffect(kart->mIndex);
    StructMQRacerEntry_SomeFn_22(kart);
    StructMQRacerEntry_SomeFn_23(kart);
    ReleaseKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    StructMQRacerEntry_SomeFn_24(kart);
    if (kart->mIndex == g_GlobalCO->mEntryIndex) {
        SetThunderShrinkSoundFlag(0);
    }
    ResetKartTrackParamsFunction(kart);
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        StructMQRacerEntry_SomeFn_2(kart);
    }
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
    if (kart->mEffectFlags & KART_EFFECT_KILLER) {
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
}

void StructMQRacerEntry_Fn7(Kart *kart) {
    Vec3 startPos;
    Vec3 forward;
    Vec3 startAngles;
    Vec3 *collisionPos;

    if (!(kart->mEntryFlags & KART_ENTRY_REMOVED)) {
        return;
    }
    GetCourseMapKartStartPlacement(&startPos, &startAngles, kart->mIndex);
    kart->mHeadingAngle = (u32) (startAngles.y * 0xb6) >> 12;
    QuaternionFromAxisAngle(&g_UnitY_VecFx32, kart->mHeadingAngle, &kart->mHeadingQuaternion);
    Matrix4x3FromQuaternion(&kart->mRotationMatrix, &kart->mHeadingQuaternion);
    GetMQRacerVector333(kart, &forward);
    StructMQRacerEntry_SomeFn_63(kart, &startPos, &forward, NULL);
    if (g_GlobalCO->mMode == MODE_WIFI) {
        collisionPos = &kart->mPointAlongUp;
    } else {
        collisionPos = &kart->mCollisionCenter;
    }
    if (kart->mCollisionSlot == -1) {
        kart->mCollisionSlot = CreateCollisionSlot(collisionPos, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
    }
    if (kart->mSecondCollisionSlot == -1) {
        kart->mSecondCollisionSlot = CreateCollisionSlot(
            &kart->mSecondCollisionCenter, ((s64) kart->mPhysicalParam->mRadius << 15) >> 12, 0x800, kart);
    }
    kart->mEntryFlags |= KART_ENTRY_SCALING_IN;
    kart->mEntryFlags &= ~(KART_ENTRY_REMOVED | KART_ENTRY_HIDDEN);
    kart->mScale = gKartVec3Zero;
}

void StructMQRacerEntry_SomeFn_43(Kart *kart) {
    s32 factor;
    s32 adjustment;
    s16 surfaceIndex;
    KartPhysicalParam *physicalParam;
    s32 *charPhysicalParam;

    kart->mPhysicalParam = GetKartPhysicalParam(kart->mIndex);
    factor = 0x1000;
    adjustment = 0;
    if (IsAwardOrStaffRoll_0() == 0) {
        switch (g_GlobalCO->mEngineIndex) {
            case ENGINE_CLASS_SLOW:
                factor = 0xb33;
                adjustment = -0x28;
                break;
            case ENGINE_CLASS_MEDIUM:
                factor = 0xd9a;
                adjustment = -0x14;
                break;
        }
    }
    kart->mPhysicalParam->mBaseSpeedLimit = MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mBaseSpeedLimit, factor);
    kart->mPhysicalParam->mDriftTurnRate = kart->mPhysicalParam->mDriftTurnRate + adjustment;
    kart->mSpeedLimitFactorPerDepth = TO_FIXED12(1) - kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4];
    kart->mSpeedLimitFactorPerDepth = FX_Div(kart->mSpeedLimitFactorPerDepth, kart->mPhysicalParam->mRadius << 1);
    kart->mCharPhysicalParam = GetCharacterPhysicalParam(kart->mIndex);
    physicalParam = kart->mPhysicalParam;
    charPhysicalParam = kart->mCharPhysicalParam;
    for (surfaceIndex = 0; surfaceIndex < 12; surfaceIndex++) {
        factor = physicalParam->mSurfaceSpeedLimitFactors[surfaceIndex];
        if (factor < 0x1000) {
            physicalParam->mSurfaceSpeedLimitFactors[surfaceIndex] = MUL_FIXED12_ROUNDED(factor, *charPhysicalParam);
        }
    }
}

void StructMQRacerEntry_SomeFn_11(Kart *kart) {
    Vec3 zeroVector;

    kart->mSpeedLimitGroundFactor = TO_FIXED12(1);
    kart->mAheadSpeedLimitFactor = TO_FIXED12(1);
    kart->mSpeedLimitFactor = TO_FIXED12(1);
    kart->mSpeedLimitHitFactor = TO_FIXED12(1);
    zeroVector = gKartVec3Zero;
    kart->mUnk_25c = zeroVector;
    kart->mAttractorPullDirection = zeroVector;
    kart->mAttractorPullSpeed = 0;
    kart->mForward = zeroVector;
    kart->mHopStartForward = zeroVector;
    kart->mHitVelocity = zeroVector;
    kart->mPrevHitVelocity = zeroVector;
    kart->mPrevPrevHitVelocity = zeroVector;
    kart->mUnk_25c = zeroVector;
    kart->mAirborneFrames = 0;
    kart->mTurnAngle = 0;
    kart->mDriftHeadingAnglePerFrame = 0;
    kart->mTurnedForwardEaseFactor = TO_FIXED12(1);
    kart->mHeadingAnglePerFrame = 0;
}

void StructMQRacerEntry_Fn1(Kart *kart) {
    Vec3 zeroVector;
    u16 slotIndex;

    StructAD00Sub_SomeFn_2(kart->mKartModelsEntry);
    kart->mMotionFlags = 0;
    kart->mDriveFlags = 0;
    kart->mEffectFlags = 0;
    zeroVector = gKartVec3Zero;
    kart->mDrawMatrixPos = zeroVector;
    kart->mPrevPos = kart->mDrawMatrixPos;
    kart->mPos = kart->mPrevPos;
    kart->mVelocity = zeroVector;
    kart->mVelocityDirection = zeroVector;
    kart->mScale.x = TO_FIXED12(1);
    kart->mScale.y = TO_FIXED12(1);
    kart->mScale.z = TO_FIXED12(1);
    kart->mScaleFactor.x = TO_FIXED12(1);
    kart->mScaleFactor.y = TO_FIXED12(1);
    kart->mScaleFactor.z = TO_FIXED12(1);
    kart->mScaleBase.x = TO_FIXED12(1);
    kart->mScaleBase.y = TO_FIXED12(1);
    kart->mScaleBase.z = TO_FIXED12(1);
    kart->mScaleYFactor = TO_FIXED12(1);
    kart->mGravity = -0x2b9;
    kart->mSpeedLimitGoal = 0;
    kart->mSpeedLimit = KART_START_SPEED_LIMIT;
    kart->mSpeedLimitGroundFactor = TO_FIXED12(1);
    kart->mAheadSpeedLimitFactor = TO_FIXED12(1);
    kart->mState = KART_STATE_NORMAL;
    ClearKartItemEffectState(&kart->mItemEffectData);
    MTX_Identity43_(&kart->mRotationMatrix);
    MTX_Identity43_(&kart->mDrawBaseMatrix);
    MTX_Identity43_(&kart->mWobbleMatrix);
    kart->mPointAlongUp = zeroVector;
    kart->mPrevPointAlongUp = kart->mPointAlongUp;
    kart->mPrevCollisionCenter = kart->mPrevPointAlongUp;
    kart->mCollisionCenter = kart->mPrevCollisionCenter;
    kart->mSecondCollisionCenter = zeroVector;
    kart->mPointMotion = zeroVector;
    kart->mSpeedLimitFactor = TO_FIXED12(1);
    kart->mHeadingQuaternion = gKartResetHeadingQuaternion;
    kart->mTiltQuaternion = gKartResetSecondQuaternion;
    kart->mAirTiltQuaternion = gKartResetThirdQuaternion;
    kart->mCombinedQuaternion = gKartResetFourthQuaternion;
    kart->mAirTiltAngle = 0;
    kart->mHeadingAngle = 0;
    kart->mBoostTimer = 0;
    kart->mStateEndTimer = 0;
    kart->mMiniTurboTimer = 0;
    kart->mTurnedForwardEaseFactor = TO_FIXED12(1);
    kart->mGroundNormal = g_UnitY_VecFx32;
    kart->mCourseContactNormal = zeroVector;
    kart->mUnk_25c = zeroVector;
    kart->mAttractorPullDirection = zeroVector;
    kart->mAttractorPullSpeed = 0;
    kart->mForward = zeroVector;
    kart->mHopStartForward = zeroVector;
    kart->mTurnedForward = zeroVector;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mVelocityLengthRatio = 0;
    kart->mVelocityLength = 0;
    kart->mForwardSpeed = 0;
    kart->mLastGroundY = 0;
    kart->mTestedKartMask = 0;
    kart->mNearKartMask = 0;
    kart->mPrevNearKartMask = 0;
    kart->mItemEffect = KART_ITEM_EFFECT_NONE;
    kart->mHopSpeed = 0;
    kart->mHopHeight = 0;
    kart->mHopTiltAngle = 0;
    kart->mTurnDirection = 0;
    kart->mTurnRatio = 0;
    kart->mHitVelocity = zeroVector;
    kart->mLaunchAxisSwing = 0;
    kart->mLaunchAxisSwingAngle = 0;
    kart->mLaunchAxisSwingAngleSum = 0;
    kart->mUnk_344 = 0;
    kart->mLaunchStartY = kart->mPos.y;
    kart->mLaunchFrames = 0;
    kart->mDriftCharge = KART_DRIFT_CHARGE_NONE;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTowardTurnCounter = NULL;
    kart->mAwayTurnCounter = kart->mTowardTurnCounter;
    kart->mTurnCountTimer = 0;
    kart->mRotationAngle = 0;
    kart->mRotationAngleSum = 0;
    kart->mRotationAxis = zeroVector;
    kart->mRotationQuaternion = gKartResetRotationQuaternion;
    kart->mRotationEndFrames = 0;
    kart->mRotationAnglePerFrame = 0;
    kart->mYRotationAngle = 0;
    kart->mYRotationAnglePerFrame = 0;
    kart->mYRotationCount = 0;
    kart->mYRotationAngleSum = 0;
    kart->mVerticalSpeedStepCount = 0;
    kart->mCollisionPushVelocity = zeroVector;
    kart->mAirborneFrames = 0;
    kart->mVisible = KART_VISIBLE_ALL;
    kart->mHeadingAnglePerFrame = 0;
    kart->mTurnAngle = 0;
    kart->mDriftHeadingAnglePerFrame = 0;
    kart->mSpeedLimitHitFactor = TO_FIXED12(1);
    kart->mShrinkFactor = TO_FIXED12(1);
    kart->mMapObjectVectorLength = 0;
    kart->mMapObjectVectorForwardDot = 0;
    kart->mTireSpinAngle = 0;
    kart->mQuaternionBlendFactor = FIXED12_RATIO(12, 100);
    kart->mSinkFrames = 0;
    kart->mVelocity = zeroVector;
    kart->mUnk_3bc = 0;
    kart->mRaceStartFrameCount = 0;
    kart->mRespawnFrames = 0;
    kart->mRespawnSlot = -1;
    kart->mFramesSinceRemovalOrReset = 0;
    kart->mKartCollisionTimer = 0;
    kart->mKartCollisionDelayTimer = 0;
    kart->mSurfaceGroup = -1;
    kart->mSurfaceKind = 0;
    kart->mSurfaceVariant = 0;
    kart->mAirTiltAngleOffset = 0;
    kart->mTurnHeadingAnglePerFrameGoal = 0;
    kart->mTurnHeadingAnglePerFrame = 0;
    kart->mVelocityScaleFactor = TO_FIXED12(1);
    kart->mModelScaleKind = KART_MODEL_SCALE_LAND;
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = 0;
    kart->mModelScaleY = TO_FIXED12(1);
    kart->mModelScaleX = TO_FIXED12(1);
    kart->mModelScaleZ = TO_FIXED12(1);
    for (slotIndex = 0; slotIndex < 2; slotIndex++) {
        kart->mPrevTouchingMapObjects[slotIndex] = NULL;
        kart->mMapObjectSoundFrames[slotIndex] = 0;
        kart->mMapObjectSoundPlayed[slotIndex] = 0;
    }
    kart->mScaleEffectMapObject = NULL;
    kart->mModelOffsetY = 0;
    kart->mRespawnLandRaceFrame = 0;
    kart->mRespawnPressRaceFrame = 0;
    kart->mRespawnWaitVelocityScale = 0;
    kart->mCourseHitAttributeBit = 0;
    kart->mSurfaceSpeedLimitGoal = 0;
    kart->mRadiusFactor = TO_FIXED12(1);
    kart->mCollisionStepFrames = 0;
    kart->mRevLevel = 0;
    kart->mAttractorIndex = -1;
    kart->mLandingTimer = 0;
    kart->mCourseHitTimer = 0;
    kart->mHeadingAngleOffset = 0;
    kart->mHeadingAngleOffsetPerFrame = 0;
    kart->mHeadingAngleOffsetDirection = 1;
    kart->mHeadingAngleOffsetCount = 0;
    kart->mOffsetCyclePhase = 0;
    kart->mOffsetCyclePhaseStep = KART_OFFSET_CYCLE_START_PHASE_STEP;
    kart->mOffsetCycleAmount = gKartOffsetCycleStartAmount;
    kart->mOffsetCycleAmount.z = 0;
    kart->mOffsetCycleIndex = 0;
    kart->mWaterDepth = 0;
    kart->mBlinkCycleFrames = 0;
    kart->mBlinkFrames = kart->mBlinkCycleFrames;
    kart->mWobbleEasedAmplitude = 0;
    kart->mWobbleAmplitude = kart->mWobbleEasedAmplitude;
    kart->mWobbleAngle = 0;
    kart->mRank = 0;
    StructMQRacerEntry_SomeFn_32(kart, 0, 0);
    kart->mTireTurnAngle = 0;
}

// Free-list nodes of one kart's participant record state and the bytes of each.
#define PARTICIPANT_RECORD_NODE_COUNT 0x1e
#define PARTICIPANT_RECORD_NODE_SIZE 0x24

void StructMQRacerEntry_InitializeSub(Kart *kart, void *heap) {
    ParticipantKartRecordState *recordState;
    Vec3 zeroVector;
    u16 recordIndex;
    u8 *entries;

    recordState = kart->mParticipantRecordData;
    if (recordState == NULL) {
        return;
    }
    recordState->mSmoothedPos = kart->mPos;
    recordState->mSmoothedDrawPos = recordState->mSmoothedPos;
    recordState->mSmoothedHeadingAngle = kart->mHeadingAngle;
    recordState->mHeadingAngleAtReset = recordState->mSmoothedHeadingAngle;
    recordState->mUnk_1c = 0;
    recordState->mLastSyncCount = 0;
    recordState->mPosBlendFactor = 0;
    recordState->mUnk_28 = 0;
    recordState->mAppliedFlags = 0;
    recordState->mEventToggleFlags = recordState->mAppliedFlags;
    zeroVector = gKartVec3Zero;
    recordState->mUnk_34 = zeroVector;
    recordState->mRecordBits = 0;
    recordState->mRecordKartBits = 0;
    recordState->mTargetTurnAngle = 0;
    recordState->mEasedTurnAngle = 0;
    recordState->mHopHeight = 0;
    recordState->mHopSpeed = 0;
    recordState->mPushDirection = zeroVector;
    recordState->mPosOffset = zeroVector;
    recordState->mPosOffsetIndex = 0;
    IntrusiveListWrapper_InitializeEmpty(&recordState->mPendingRecords, 0);
    IntrusiveListWrapper_InitializeEmpty(&recordState->mFreeRecords, 0);
    entries = Mem_AllocateHeap(heap, PARTICIPANT_RECORD_NODE_COUNT * PARTICIPANT_RECORD_NODE_SIZE);
    for (recordIndex = 0; recordIndex < PARTICIPANT_RECORD_NODE_COUNT; recordIndex++) {
        IntrusiveListWrapper_InsertLast(&recordState->mFreeRecords, entries + recordIndex * PARTICIPANT_RECORD_NODE_SIZE);
    }
}

void StructMQRacerEntry_SomeFn_48(Kart *kart) {
    ParticipantKartRecordState *recordState;

    if (!(kart->mEntryFlags & KART_ENTRY_WIFI_PEER)) {
        return;
    }
    recordState = kart->mParticipantRecordData;
    recordState->mSmoothedPos = kart->mPos;
    recordState->mSmoothedDrawPos = recordState->mSmoothedPos;
    recordState->mSmoothedRotation = kart->mCombinedQuaternion;
    recordState->mPosOffset = gKartVec3Zero;
    recordState->mPosOffsetIndex = 0;
}

void StructMQRacerEntry_SomeFn_44(Kart *kart) {
    kart->mEntryFlags = 0;
    if (kart->mIndex == g_GlobalCO->mEntryIndex) {
        kart->mEntryFlags |= KART_ENTRY_SELECTED;
        if (g_GlobalCO->mMode == MODE_WIFI) {
            kart->mEntryFlags |= KART_ENTRY_WIFI_LOCAL;
            if (GetEntryRaceEnded() != 0) {
                kart->mEntryFlags &= ~KART_ENTRY_WIFI_LOCAL;
                kart->mEntryFlags |= KART_ENTRY_WIFI_PEER;
            }
        }
    } else if (g_GlobalCO->mMode == MODE_WIFI) {
        kart->mEntryFlags |= KART_ENTRY_WIFI_PEER;
    }
    if (g_GlobalCO->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
        kart->mEntryFlags |= KART_ENTRY_GHOST;
        kart->mVisible = 0;
    }
    if (kart->mKartModelsEntry->mCharacterAnimation != NULL) {
        kart->mEntryFlags |= KART_ENTRY_HAS_CHARACTER_ANIMATION;
    }
    if (g_GlobalCO->mMode == MODE_TIME_ATTACK || IsAwardOrStaffRoll_0() != 0) {
        kart->mEntryFlags |= KART_ENTRY_SKIP_KART_HITS;
    }
}

void ClearKartItemEffectState(KartItemEffectState *itemEffectState) {
    itemEffectState->mKinokoBoostTimer = 0;
    itemEffectState->mThunderShrinkTimer = 0;
    itemEffectState->mThunderShrinkFrameIndex = 0;
    itemEffectState->mStarFrames = 0;
    itemEffectState->mAheadCount = 0;
    itemEffectState->mAheadBoostFrames = 0;
    itemEffectState->mScaleTableIndex = 0;
    itemEffectState->mScaleEffectTimer = 0;
    itemEffectState->mTeresaToggleDivisor = 0;
    itemEffectState->mTeresaStepFrames = 0;
    itemEffectState->mTeresaToggleFrames = 0;
    itemEffectState->mTeresaStepLimit = 0;
    itemEffectState->mGessoFrames = 0;
    itemEffectState->mKillerFrames = 0;
    itemEffectState->mUnk_20 = 0;
    itemEffectState->mKillerEnding = FALSE;
    itemEffectState->mKillerEndRank = 0;
}

void StructMQRacerEntry_SomeFn_49(Kart *kart) {
    StructMQRacerEntry_SomeFn_45(&kart->mSoundSource, 0, kart->mPosSource);
    StructMQRacerEntry_SomeFn_76(kart, &kart->mSound);
    StructMQRacerEntry_SomeFn_24(kart);
    switch (kart->mKartModelsEntry->mCharacterIndex) {
        case CHARACTER_MARIO:
            kart->mSoundIndex = KART_SOUND_SET_MARIO;
            break;
        case CHARACTER_DONKEY:
            kart->mSoundIndex = KART_SOUND_SET_DONKEY;
            break;
        case CHARACTER_KINOPIO:
            kart->mSoundIndex = KART_SOUND_SET_KINOPIO;
            break;
        case CHARACTER_KOOPA:
            kart->mSoundIndex = KART_SOUND_SET_KOOPA;
            break;
        case CHARACTER_PEACH:
            kart->mSoundIndex = KART_SOUND_SET_PEACH;
            break;
        case CHARACTER_WARIO:
            kart->mSoundIndex = KART_SOUND_SET_WARIO;
            break;
        case CHARACTER_YOSHI:
            kart->mSoundIndex = KART_SOUND_SET_YOSHI;
            break;
        case CHARACTER_LUIGI:
            kart->mSoundIndex = KART_SOUND_SET_LUIGI;
            break;
        case CHARACTER_KARON:
            kart->mSoundIndex = KART_SOUND_SET_KARON;
            break;
        case CHARACTER_DAISY:
            kart->mSoundIndex = KART_SOUND_SET_DAISY;
            break;
        case CHARACTER_WALUIGI:
            kart->mSoundIndex = KART_SOUND_SET_WALUIGI;
            break;
        case CHARACTER_ROBO:
            kart->mSoundIndex = KART_SOUND_SET_ROBO;
            break;
        case CHARACTER_HEYHO:
            kart->mSoundIndex = KART_SOUND_SET_HEYHO;
            break;
    }
    kart->mKartIndexModThree = kart->mKartModelsEntry->mKartIndex % 3;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        if (!(kart->mSoundSource.mSourceFlags & 1)) {
            StructMQRacerEntry_SomeFn_47(&kart->mSoundSource, 2, 1);
        }
        if (g_GlobalCO->mRaceKind == RACE_KIND_REPLAY) {
            ResetSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange);
        }
    } else {
        if (kart->mSoundSource.mSourceFlags & 1) {
            StructMQRacerEntry_SomeFn_47(&kart->mSoundSource, 2, 1);
        }
        ResetSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange);
    }
}

void StructMQRacerEntry_SomeFn_24(Kart *kart) {
    KartSound *kartSound;
    KartSoundRow soundRow;
    s32 soundRowIndex;
    s32 soundIndex;
    s32 rowOffset;
    s32 firstSoundColumn;
    s32 secondSoundColumn;
    s32 thirdSoundColumn;
    s32 highRatioSoundId;
    s32 midRatioSoundId;
    s32 lowRatioSoundId;
    s32 lastSoundColumn;

    kart->mSound.mSoundId = KART_START_SOUND_ID;
    kartSound = &kart->mSound;
    kartSound->mVolume = KART_START_SOUND_VOLUME;
    kartSound->mPitch = -1;
    kartSound->mTargetPitch = 0;
    kartSound->mPitchPerCall = 0;
    kartSound->mPrevKeyADown = 0;
    kartSound->mPitchPerSpeedOverLimit = FX_Div(0x300000, 0xd000 - kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mPitchPerSpeedKeyA = FX_Div(0x580000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mPitchPerSpeedNoKeyA = FX_Div(0x480000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mPitchPerSpeedKeyB = FX_Div(0x280000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mLapProgressAtLastSound = 0;
    kartSound->mLapProgressSoundCount = 0;
    kartSound->mLastSeqArcSoundRaceFrame = 0;
    kartSound->mThunderShrinkRaceFrame = -1;
    kartSound->mWhileRequestedSoundId = -1;
    switch (kart->mKartModelsEntry->mKartIndex / 3) {
        case 0:
            soundIndex = 4;
            break;
        case CHARACTER_DONKEY:
            soundIndex = KART_SOUND_SET_DONKEY;
            break;
        case CHARACTER_KINOPIO:
            soundIndex = KART_SOUND_SET_KINOPIO;
            break;
        case CHARACTER_KOOPA:
            soundIndex = KART_SOUND_SET_KOOPA;
            break;
        case CHARACTER_PEACH:
            soundIndex = KART_SOUND_SET_PEACH;
            break;
        case CHARACTER_WARIO:
            soundIndex = KART_SOUND_SET_WARIO;
            break;
        case CHARACTER_YOSHI:
            soundIndex = KART_SOUND_SET_YOSHI;
            break;
        case CHARACTER_LUIGI:
            soundIndex = KART_SOUND_SET_LUIGI;
            break;
        case CHARACTER_KARON:
            soundIndex = KART_SOUND_SET_KARON;
            break;
        case CHARACTER_DAISY:
            soundIndex = KART_SOUND_SET_DAISY;
            break;
        case CHARACTER_WALUIGI:
            soundIndex = KART_SOUND_SET_WALUIGI;
            break;
        case CHARACTER_ROBO:
            soundIndex = KART_SOUND_SET_ROBO;
            break;
        case CHARACTER_HEYHO:
            soundIndex = KART_SOUND_SET_HEYHO;
            break;
    }
    kartSound->mSoundIndex = soundIndex;
    soundRowIndex = GetKartSoundTableRow(kart->mKartModelsEntry->mKartIndex);
    rowOffset = soundRowIndex * 0x1c;
    firstSoundColumn = *OFFSET_PTR(s32, &gKartSoundRowSoundIds[0][0], rowOffset);
    secondSoundColumn = *OFFSET_PTR(s32, &gKartSoundRowSoundIds[0][1], rowOffset);
    thirdSoundColumn = *OFFSET_PTR(s32, &gKartSoundRowSoundIds[0][2], rowOffset);
    highRatioSoundId = *OFFSET_PTR(s32, &gKartSoundRowSoundIds[0][3], rowOffset);
    midRatioSoundId = *OFFSET_PTR(s32, &gKartSoundRowSoundIds[0][4], rowOffset);
    lowRatioSoundId = *OFFSET_PTR(s32, &gKartSoundRowSoundIds[0][5], rowOffset);
    lastSoundColumn = *OFFSET_PTR(s32, &gKartSoundRowSoundIds[0][6], rowOffset);
    soundRow.mSoundRowIndex = soundRowIndex;
    soundRow.mPitchedSoundId = firstSoundColumn;
    soundRow.mSecondSoundColumn = secondSoundColumn;
    soundRow.mThirdSoundColumn = thirdSoundColumn;
    soundRow.mHighRatioSoundId = highRatioSoundId;
    soundRow.mMidRatioSoundId = midRatioSoundId;
    soundRow.mLowRatioSoundId = lowRatioSoundId;
    soundRow.mClampedPitchSoundId = lastSoundColumn;
    if (kart->mIndex != g_GlobalCO->mEntryIndex) {
        secondSoundColumn = thirdSoundColumn;
    }
    if (kart->mIndex != g_GlobalCO->mEntryIndex) {
        firstSoundColumn = thirdSoundColumn;
    }
    soundRow.mKeyAHighRatioSoundId = secondSoundColumn;
    soundRow.mKeyALowRatioSoundId = firstSoundColumn;
    kartSound->mSoundRow = soundRow;
}

PlayingSound *StartSoundFullVolume(SoundSource *soundSource, u32 soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    volume = 0x7fu;
    pitch = 0u;
    return StructMQRacerEntry_SomeFn_8(sourceCopy, soundIdCopy, volume, pitch);
}

void StartSoundWhileRequestedFullVolume(SoundSource *soundSource, u32 soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 unusedValue;
    volume = 0x7fu;
    pitch = 0u;
    StartSoundWhileRequested(sourceCopy, soundIdCopy, volume, pitch);
}

void StartKartSurfaceSoundWhileRequestedFromKart(void *kart, int entryIndex) {
    StartKartSurfaceSoundWhileRequested(kart, entryIndex, ((Kart *) kart)->mSurfaceKind,
                                        ((Kart *) kart)->mSurfaceVariant, ((Kart *) kart)->mWaterDepth);
}

void StartSurfaceSoundFromKart(Kart *kart, s32 entryIndex) {
    StartSurfaceSound(&kart->mSoundSource, entryIndex, kart->mSurfaceKind, kart->mSurfaceVariant, kart->mWaterDepth);
}

void KartStartSoundFullVolume(void *soundSource, int soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 unusedValue;
    volume = 0x7fu;
    pitch = 0u;
    StructMQRacerEntry_SomeFn_8(sourceCopy, soundIdCopy, volume, pitch);
}

void StartKartSoundWhileRequested(void *kart, int soundId) {
    if (StartSoundWhileRequested(kart, soundId, 0x7f, 0) != NULL) {
        ((Kart *) kart)->mSound.mWhileRequestedSoundId = soundId;
    }
}

void RequestKartSound(void *kart, int soundId) {
    int sortKeyBase;

    sortKeyBase = GetAED0PlayerUnk(((Kart *) kart)->mIndex);
    AddSoundRequest(&gSoundRequestQueues[3], sortKeyBase + GetKartSoundRequestSortOffset(),
                    StartKartSoundWhileRequested, kart, soundId);
}

void StartKartSeqArcSoundOffset7(Kart *kart) {
    if (kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT)) {
        return;
    }
    StructMQRacerEntry_SomeFn_5(kart, kart->mSoundIndex, 7);
}

void StructMQRacerEntry_SomeFn_85(Kart *kart) {
    kart->mModelScaleFrameIndex++;
    if (kart->mModelScaleFrameIndex >= kart->mModelScaleFrameCount) {
        kart->mModelScaleFrameIndex = 0;
        kart->mEffectFlags &= ~KART_EFFECT_MODEL_SCALE_ANIM;
        return;
    }
    if (kart->mModelScaleKind == KART_MODEL_SCALE_LAND) {
        kart->mModelScaleY = gKartModelScaleYLandTable[kart->mModelScaleFrameIndex];
        kart->mModelOffsetY = gKartModelOffsetYLandAndBumpTable[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = TO_FIXED12(1);
        kart->mModelScaleX = kart->mModelScaleZ;
    } else if (kart->mModelScaleKind == KART_MODEL_SCALE_HARD_LAND) {
        kart->mModelScaleY = gKartModelScaleYHardLandTable[kart->mModelScaleFrameIndex];
        kart->mModelOffsetY = gKartModelOffsetYHardLandTable[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = TO_FIXED12(1);
        kart->mModelScaleX = kart->mModelScaleZ;
    } else if (kart->mModelScaleKind == KART_MODEL_SCALE_BUMP) {
        kart->mModelScaleY = TO_FIXED12(1);
        kart->mModelOffsetY = gKartModelOffsetYLandAndBumpTable[kart->mModelScaleFrameIndex];
        kart->mModelScaleX = gKartModelScaleXBumpTable[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = gKartModelScaleZBumpTable[kart->mModelScaleFrameIndex];
    }
}

void AdvanceKartOffsetCycle(Kart *kart) {
    s32 fraction;
    u16 tableIndex;
    u16 nextTableIndex;
    s32 keyALevel;
    s32 amountScale;
    s32 value;

    kart->mOffsetCyclePhase = kart->mOffsetCyclePhase + kart->mOffsetCyclePhaseStep;
    value = kart->mOffsetCyclePhase - 0x8000;
    if (value >= 0) {
        kart->mOffsetCyclePhase = value;
    }
    fraction = kart->mOffsetCyclePhase & FIXED12_FRACTION_MASK;
    tableIndex = FROM_FIXED12(kart->mOffsetCyclePhase);
    nextTableIndex = tableIndex + 1;
    if (nextTableIndex >= 8) {
        nextTableIndex = 0;
    }
    kart->mOffsetCycleAmount.x =
        gKartOffsetCycleX[tableIndex] +
        MUL_FIXED12_NO_ROUND((gKartOffsetCycleX[nextTableIndex] - gKartOffsetCycleX[tableIndex]) >> 1, fraction);
    kart->mOffsetCycleAmount.y =
        gKartOffsetCycleY[tableIndex] +
        MUL_FIXED12_NO_ROUND((gKartOffsetCycleY[nextTableIndex] - gKartOffsetCycleY[tableIndex]) >> 1, fraction);
    kart->mOffsetCycleAmount.z =
        gKartOffsetCycleZ[tableIndex] +
        MUL_FIXED12_NO_ROUND((gKartOffsetCycleZ[nextTableIndex] - gKartOffsetCycleZ[tableIndex]) >> 1, fraction);
    keyALevel = kart->mRevLevel;
    amountScale = MUL_FIXED12_NO_ROUND(keyALevel, 0x333);
    if (keyALevel > 0xf33) {
        value = MUL_FIXED12_NO_ROUND((keyALevel - 0xf33) * 0x32, 0x19a);
        if (value > 0x19a) {
            value = 0x19a;
        }
        value = value + 0x333;
        amountScale = MUL_FIXED12_NO_ROUND(keyALevel, value);
    } else if (keyALevel > 0xd9a) {
        value = MUL_FIXED12_NO_ROUND((keyALevel - 0xd9a) * 0x32, 0x52);
        if (value > 0x52) {
            value = 0x52;
        }
        value = value + 0x333;
        amountScale = MUL_FIXED12_NO_ROUND(keyALevel, value);
    }
    kart->mOffsetCycleAmount.x =
        kart->mOffsetCycleAmount.x + MUL_FIXED12_NO_ROUND(kart->mOffsetCycleAmount.x, amountScale);
    kart->mOffsetCycleAmount.y =
        kart->mOffsetCycleAmount.y + MUL_FIXED12_NO_ROUND(kart->mOffsetCycleAmount.y, amountScale);
    kart->mOffsetCycleAmount.z =
        kart->mOffsetCycleAmount.z + MUL_FIXED12_NO_ROUND(kart->mOffsetCycleAmount.z, amountScale);
}

void AdvanceKartHeadingSwing(Kart *kart) {
    s32 offset;

    if (kart->mHeadingAngleOffsetCount <= KART_HEADING_SWING_LAST_COUNT) {
        kart->mHeadingAngleOffsetPerFrame =
            kart->mHeadingAngleOffsetDirection * 0x3c + kart->mHeadingAngleOffsetPerFrame;
        if (kart->mHeadingAngleOffsetPerFrame > KART_HEADING_SWING_MAX_PER_FRAME) {
            kart->mHeadingAngleOffsetPerFrame = KART_HEADING_SWING_MAX_PER_FRAME;
        } else if (kart->mHeadingAngleOffsetPerFrame < -KART_HEADING_SWING_MAX_PER_FRAME) {
            kart->mHeadingAngleOffsetPerFrame = -KART_HEADING_SWING_MAX_PER_FRAME;
        }
        kart->mHeadingAngleOffset = kart->mHeadingAngleOffset + kart->mHeadingAngleOffsetPerFrame;
        offset = kart->mHeadingAngleOffset;
        if ((offset > 0 ? offset : -offset) > 0x1770) {
            if ((offset > 0 && kart->mHeadingAngleOffsetDirection > 0) ||
                (offset < 0 && kart->mHeadingAngleOffsetDirection < 0)) {
                kart->mHeadingAngleOffsetDirection *= -1;
                kart->mHeadingAngleOffsetCount = kart->mHeadingAngleOffsetCount + 1;
            }
        }
        kart->mRevLevel = TO_FIXED12(1);
    } else {
        kart->mHeadingAngleOffsetPerFrame =
            kart->mHeadingAngleOffsetDirection * 0x3c + kart->mHeadingAngleOffsetPerFrame;
        if (kart->mHeadingAngleOffsetPerFrame > KART_HEADING_SWING_SETTLE_MAX_PER_FRAME) {
            kart->mHeadingAngleOffsetPerFrame = KART_HEADING_SWING_SETTLE_MAX_PER_FRAME;
        } else if (kart->mHeadingAngleOffsetPerFrame < -KART_HEADING_SWING_SETTLE_MAX_PER_FRAME) {
            kart->mHeadingAngleOffsetPerFrame = -KART_HEADING_SWING_SETTLE_MAX_PER_FRAME;
        }
        kart->mHeadingAngleOffset = kart->mHeadingAngleOffset + kart->mHeadingAngleOffsetPerFrame;
        kart->mRevLevel = MUL_FIXED12_NO_ROUND(kart->mRevLevel, 0xf5c);
        offset = kart->mHeadingAngleOffset;
        if ((offset > 0 && kart->mHeadingAngleOffsetDirection > 0) ||
            (offset < 0 && kart->mHeadingAngleOffsetDirection < 0)) {
            kart->mHeadingAngleOffset = 0;
            kart->mEffectFlags &= ~KART_EFFECT_HEADING_SWING;
            StructMQRacerEntry_SomeFn_32(kart, 0, 1);
            kart->mMotionFlags |= KART_MOTION_START_DONE;
        }
    }
}

void StartKartModelScaleAnimation(Kart *kart, s32 mode) {
    s32 state;

    state = kart->mState;
    if (state != KART_STATE_NORMAL && state != KART_STATE_LAUNCH_DOUBLE_FLIP) {
        return;
    }
    if (mode == KART_MODEL_SCALE_BUMP) {
        kart->mModelScaleKind = KART_MODEL_SCALE_BUMP;
    } else if (kart->mMotionFlags & KART_MOTION_HOPPING) {
        kart->mModelScaleKind = KART_MODEL_SCALE_HARD_LAND;
    } else if (kart->mAirborneFrames > KART_HARD_LAND_AIRBORNE_FRAMES) {
        kart->mModelScaleKind = KART_MODEL_SCALE_HARD_LAND;
    } else {
        kart->mModelScaleKind = KART_MODEL_SCALE_LAND;
    }
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = KART_MODEL_SCALE_FRAMES;
    kart->mEffectFlags |= KART_EFFECT_MODEL_SCALE_ANIM;
}

void ResetKartMotionState(Kart *kart, s32 flag) {
    NNSSndSeqPlayer **sndHandleSlot;
    PlayingSound *playingSound;

    if (flag == 0) {
        kart->mDriveFlags |= KART_DRIVE_INPUT_LOCKED;
        kart->mMotionFlags &= ~KART_MOTION_ON_GROUND;
    }
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
    StructMQRacerEntry_SomeFn_22(kart);
    kart->mMotionFlags &=
        ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_HOP_STEER);
    kart->mTurnDirection = 0;
    kart->mDriftCharge = KART_DRIFT_CHARGE_NONE;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    kart->mState = KART_STATE_NORMAL;
    kart->mEffectFlags &= ~(KART_EFFECT_TUMBLING | KART_EFFECT_Y_SPIN);
    kart->mDriveFlags &= ~KART_DRIVE_HIT_STATE;
    StructMQRacerEntry_SomeFn_32(kart, 0, 1);
    kart->mMotionFlags |= KART_MOTION_STATE_RESET;
    StructMQRacerEntry_SomeFn_11(kart);
    StructMQRacerEntry_SomeFn_12(kart);
    if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
        return;
    }
    StartCameraWobbleByCourse();
    switch (g_GlobalCO->mCourseId) {
        case COURSE_ID_AIRSHIP:
            StartTimedQuadFromTable(0);
            playingSound = StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0x15c, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= PLAYING_SOUND_FLAG_SKIP_SHRINK_PITCH;
            }
            sndHandleSlot = GetSndHandleSlot(7);
            if (!(gRaceSoundKind & 1)) {
                return;
            }
            if (gSoundModeHolder.mSeqStartEnabled == 0) {
                return;
            }
            if (sndHandleSlot[0] != NULL) {
                NNS_SndPlayerStopSeq(sndHandleSlot, 0);
            }
            if (sndHandleSlot[0] != NULL) {
                NNS_SndPlayerStopSeq(sndHandleSlot, 0);
            }
            PlaySseqFromSarc(sndHandleSlot, 0, 0x1d2);
            break;
        case COURSE_ID_PINBALL:
            playingSound = StructMQRacerEntry_SomeFn_8(&kart->mSoundSource, 0x15b, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= PLAYING_SOUND_FLAG_SKIP_SHRINK_PITCH;
            }
            break;
    }
}

void StructMQRacerEntry_SomeFn_12(Kart *kart) {
    s32 effectIdsOther[2];
    Vec3 effectPos;
    Vec3 effectIdsSelected;
    Camera *currentCamera;
    Vec3 *cameraPos;
    BOOL cameraOutsideBox;
    s32 effectCount;
    s32 effectIndex;
    s32 *nextEffectId;
    s32 *effectIdsOtherPtr;

    effectPos = gFixedPositionEffectPos;
    cameraOutsideBox = TRUE;
    currentCamera = GetGlobalHD4();
    cameraPos = &currentCamera->mPos;
    if (cameraPos->x > -0x64f000) {
        if (cameraPos->x < -0x3cb000) {
            if (cameraPos->z > -0x1ad7000) {
                if (cameraPos->z < -0x164d000) {
                    cameraOutsideBox = FALSE;
                }
            }
        }
    }
    if (cameraOutsideBox != FALSE) {
        effectIdsSelected = gFixedPositionSelectedEffectIds;
        effectIdsOtherPtr = effectIdsOther;
        effectIdsOther[0] = gFixedPositionOtherEffectIds[0];
        effectIdsOther[1] = gFixedPositionOtherEffectIds[1];
        effectCount = 3;
        nextEffectId = (s32 *) &effectIdsSelected;
        if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
            effectCount = 2;
            nextEffectId = effectIdsOtherPtr;
        }
        for (effectIndex = 0; effectIndex < effectCount; effectIndex++) {
            StartEffect(*nextEffectId, &effectPos);
            nextEffectId++;
        }
    } else {
        StartEffect((kart->mEntryFlags & KART_ENTRY_SELECTED) ? 0x47 : 0x52, &effectPos);
    }
}

static inline s32 NormalizeLengthOrZero(Vec3 *src, Vec3 *dst) {
    if (LENGTH_SQUARED(*src) < 0x10) {
        return 0;
    }
    return Vector3_MaybeNormalize(src, dst);
}

void AdvanceKartToKeyedPlacement(Kart *kart) {
    KartItemEffectState *itemEffectState;
    u16 placementIndex;
    s32 distance;
    s32 angleIndex;
    s32 speed;
    u32 flags;
    Vec3 placementPos;
    Vec3 placementAngles;
    Vec3 groundNormal;
    Vec3 toTarget;
    Vec3 placementForward;
    Vec3 side;
    Vec3 toKart;
    Vec3 flatForward;
    Vec3 sideVector;
    MtxFx43 placementMatrix;
    MtxFx33 rotationMatrix;
    Vec3 axis;

    placementAngles = gKartVec3Zero;
    placementIndex = *g_GlobalPE->mKeyedPlacementIndexByKey;
    placementPos.x = g_GlobalPE->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = g_GlobalPE->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = g_GlobalPE->mKeyedPlacements[placementIndex].mPos.z;
    placementAngles.x = g_GlobalPE->mKeyedPlacements[*g_GlobalPE->mKeyedPlacementIndexByKey].mRotation.x;
    placementAngles.y = g_GlobalPE->mKeyedPlacements[*g_GlobalPE->mKeyedPlacementIndexByKey].mRotation.y;
    placementAngles.z = g_GlobalPE->mKeyedPlacements[*g_GlobalPE->mKeyedPlacementIndexByKey].mRotation.z;
    angleIndex = (u16) (((s64) placementAngles.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >> 4;
    MTX_RotY33__from_thumb(&rotationMatrix, g_SinFx16Table_AndCos[angleIndex * 2], g_SinFx16Table_AndCos[angleIndex * 2 + 1]);
    MTX_MultVec33(&g_UnitZ_VecFx32, &rotationMatrix, &placementForward);
    SkipOrthoQuadsHoldAndSetVelocities(kart->mIndex);

    flags = kart->mEffectFlags;
    if (!(flags & KART_EFFECT_COURSE_COLORED) && (flags & KART_EFFECT_GESSO)) {
        itemEffectState = &kart->mItemEffectData;
        if (itemEffectState->mGessoFrames <= KART_GESSO_COLORED_FRAME) {
            itemEffectState->mGessoFrames = KART_GESSO_COLORED_FRAME;
            kart->mEffectFlags |= KART_EFFECT_COURSE_COLORED;
            StartKartModelColorBlend(kart->mKartModelsEntry, GetKartCourseDiffColor(), GetKartCourseEmiColor(),
                                     GetKartCourseAmbColor());
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_GESSO) {
        StructMQRacerEntry_SomeFn_40(kart);
    }
    flags = kart->mEffectFlags;
    if (flags & KART_EFFECT_KILLER) {
        StructMQRacerEntry_SomeFn_79(kart);
    } else {
        if (flags & KART_EFFECT_THUNDER_SHRINK) {
            StructMQRacerEntry_SomeFn_82(kart);
        }
        if (kart->mEffectFlags & KART_EFFECT_SCALE_TABLE) {
            StructMQRacerEntry_SomeFn_81(kart);
        }
        if (kart->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED) {
            StructMQRacerEntry_SomeFn_80(kart);
        }
    }

    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        itemEffectState = &kart->mItemEffectData;
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            AddSoundRequest(gSoundRequestQueues, GetAED0PlayerUnk(kart->mIndex), RequestKartSound, kart,
                            0xa3);
        }
        itemEffectState->mAheadBoostFrames++;
        if (itemEffectState->mAheadBoostFrames > KART_KILLER_RANK_END_FRAMES &&
            (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST)) {
            kart->mEffectFlags &= ~KART_EFFECT_AHEAD_BOOST;
            kart->mAheadSpeedLimitFactor = TO_FIXED12(1);
            if (!(kart->mEffectFlags & KART_EFFECT_GESSO)) {
                StructMQRacerEntry_SomeFn_2(kart);
            }
            StructMQRacerEntry_SomeFn_3(kart);
        }
    }

    if (kart->mEffectFlags & KART_EFFECT_STAR) {
        itemEffectState = &kart->mItemEffectData;
        AdvanceKartStarEffects(kart->mIndex);
        if ((kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) &&
            kart->mKartModelsEntry->mCharacterAnimation->mCurrentIndex == 0) {
            StructMQRacerEntry_SomeFn_32(kart, KART_CHARACTER_ANIMATION_ALTERNATE, 1);
        }
        itemEffectState->mStarFrames++;
        if (itemEffectState->mStarFrames > KART_TERESA_MAX_FRAMES) {
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
    }

    g_GlobalCYT[kart->mEntryIndex].mBitMask = PAD_KEY_Y | PAD_KEY_X | PAD_KEY_L | PAD_KEY_SELECT;
    Vector3_Cross(&g_UnitY_VecFx32, &placementForward, &side);
    VecFx32_Subtract(&kart->mPos, &placementPos, &toKart);
    toKart.y = 0;
    VecFx32_AddScale1(VecFx32_CrossProduct_0(&side, &toKart), &side, &placementPos, &placementPos);
    VecFx32_CrossProduct_0(&side, &toKart);
    VecFx32_Subtract(&placementPos, &kart->mPos, &toTarget);
    distance = NormalizeLengthOrZero(&toTarget, &toTarget);

    if (VecFx32_CrossProduct_0(&toTarget, &placementForward) <= 0) {
        StopDispCapBlend();
        kart->mDriveFlags &= ~KART_DRIVE_KEYED_PLACEMENT;
        AdvanceKartQuaternionBlendFactor(kart, &kart->mGroundNormal);
        kart->mDriveFlags &= ~KART_DRIVE_INPUT_LOCKED;
        kart->mAirTiltAngleOffset = (s16) FROM_FIXED12(MUL_FIXED12_NO_ROUND(placementAngles.x, 0x4000)) + 0x32;
        if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && g_GlobalCO->mCourseId == COURSE_ID_AIRSHIP) {
            NNS_SndPlayerStopSeq(GetSndHandleSlot(7), 0x14);
        }
    } else {
        if (distance > 0x64000) {
            kart->mTurnedForward = toTarget;
        }
        flatForward = kart->mTurnedForward;
        flatForward.y = 0;
        kart->mQuaternionBlendFactor = TO_FIXED12(1);
        NormalizeLengthOrZero(&flatForward, &flatForward);
        kart->mHeadingAngle = FROM_FIXED12(MUL_FIXED12_NO_ROUND(FX_Atan2(flatForward.x, flatForward.z), 0x28be60d));
        axis = gKartPlacementHeadingAxis;
        QuaternionFromAxisAngle(&axis, kart->mHeadingAngle, &kart->mHeadingQuaternion);
        Vector3_Cross(&g_UnitY_VecFx32, &kart->mTurnedForward, &sideVector);
        Vector3_Cross(&kart->mTurnedForward, &sideVector, &groundNormal);
        if (kart->mAirTiltAngle > -5000) {
            kart->mAirTiltAngle -= 300;
            if (kart->mAirTiltAngle < -5000) {
                kart->mAirTiltAngle = -5000;
            }
        }
        MTX_RotAxis33(&placementMatrix.mAxes, &kart->mRotationRow0, FX_SinIdx((u16) kart->mAirTiltAngle),
                      FX_CosIdx((u16) kart->mAirTiltAngle));
        MTX_MultVec33(&groundNormal, &placementMatrix.mAxes, &groundNormal);
        kart->mGroundNormal = groundNormal;
        AdvanceKartOrientation(kart, &groundNormal);
    }

    kart->mForwardSpeed = KART_RESPAWN_PLACEMENT_FORWARD_SPEED;
    speed = kart->mForwardSpeed;
    placementMatrix.mRows[3].x = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.x, speed);
    placementMatrix.mRows[3].y = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.y, speed);
    placementMatrix.mRows[3].z = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.z, speed);
    kart->mEasedTurnedForward = kart->mTurnedForward;
    if (distance < 0x3e8000) {
        speed = MUL_FIXED12_NO_ROUND(distance, 0x29) + 0x14000;
        if (kart->mForwardSpeed > speed) {
            kart->mForwardSpeed = speed;
        }
    }
    kart->mVelocity = placementMatrix.mRows[3];
    VecFx32_Add(&kart->mPos, &kart->mVelocity, &kart->mPos);
}

void PlaceKartAtKeyedPlacement(Kart *kart, u32 key) {
    Vec3 placementPos;
    Vec3 placementForward;
    MtxFx33 rotationMatrix;
    Vec3 offset;
    Vec3 axis;
    NNSSndSeqPlayer **sndHandle;
    u16 placementIndex;
    s32 angleIndex;

    ResetKartMotionState(kart, 1);
    kart->mVerticalSpeed = KART_KEYED_PLACEMENT_VERTICAL_SPEED;
    placementIndex = g_GlobalPE->mKeyedPlacementIndexByKey[key];
    placementPos.x = g_GlobalPE->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = g_GlobalPE->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = g_GlobalPE->mKeyedPlacements[placementIndex].mPos.z;
    angleIndex = (u16) (((s64) g_GlobalPE->mKeyedPlacements[g_GlobalPE->mKeyedPlacementIndexByKey[key]].mRotation.y *
                             0xb60b60b60bLL +
                         0x80000000LL) >>
                        44) >>
                 4;
    MTX_RotY33__from_thumb(&rotationMatrix, g_SinFx16Table_AndCos[angleIndex * 2], g_SinFx16Table_AndCos[angleIndex * 2 + 1]);
    MTX_MultVec33(&g_UnitZ_VecFx32, &rotationMatrix, &placementForward);
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        VecFx32_Subtract(&placementPos, &kart->mPos, &offset);
        CallStandingsKartOffsetCallback(kart->mIndex, &offset);
    }
    kart->mPos = placementPos;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mForwardSpeed = KART_KEYED_PLACEMENT_FORWARD_SPEED;
    kart->mTurnedForward = placementForward;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mHeadingAngle =
        FROM_FIXED12(MUL_FIXED12_NO_ROUND(FX_Atan2(placementForward.x, placementForward.z), 0x28be60dLL));
    axis = gKartPlacementHeadingAxis;
    QuaternionFromAxisAngle(&axis, kart->mHeadingAngle, &kart->mHeadingQuaternion);
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        SetupCameraBehindKart();
        if (gRaceSoundKind & 1) {
            sndHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (sndHandle[0] != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                if (sndHandle[0] != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                PlaySseqFromSarc(sndHandle, 0, 0x159);
            }
        }
    }
    if (!(kart->mEntryFlags & KART_ENTRY_CPU)) {
        return;
    }
    if (g_GlobalCO->mMode != MODE_BATTLE) {
        return;
    }
    ResetBattleKartAiAtPointLink(kart->mAi, GetKeyedPlacementBattlePointLink(key));
}

void StructMQRacerEntry_SomeFn_88(Kart *kart, Vec4 *quaternion) {
    MtxFx43 headingMatrix;
    MtxFx43 tiltMatrix;
    Vec3 tiltAxis;
    Vec3 tiltedUp;
    s32 dot;
    u16 headingAngle;
    u16 airTiltAngle;

    if (kart->mVelocityLength < KART_AIR_TILT_MIN_SPEED) {
        return;
    }
    if (VecFx32_CrossProduct_0(&kart->mRotationRow1, &g_UnitY_VecFx32) <= 0) {
        return;
    }
    kart->mAirTiltAngle = kart->mAirTiltAngle + kart->mAirTiltAngleOffset;
    headingAngle = kart->mHeadingAngle;
    airTiltAngle = kart->mAirTiltAngle;
    MTX_RotY43__from_thumb(&headingMatrix, FX_SinIdx(headingAngle), FX_CosIdx(headingAngle));
    MTX_MultVec43(&g_UnitX_VecFx32, &headingMatrix, &tiltAxis);
    MTX_RotAxis43(&tiltMatrix, &tiltAxis, FX_SinIdx(airTiltAngle), FX_CosIdx(airTiltAngle));
    MTX_MultVec43(&g_UnitY_VecFx32, &tiltMatrix, &tiltedUp);
    TryQuaternionFromVectors(quaternion, &g_UnitY_VecFx32, &tiltedUp);
    if (kart->mDriveFlags & KART_DRIVE_QUATERNION_FLIPPED) {
        quaternion->x = -quaternion->x;
        quaternion->y = -quaternion->y;
        quaternion->z = -quaternion->z;
        quaternion->wComponent = -quaternion->wComponent;
    }
    if (kart->mMotionFlags & KART_MOTION_HOPPING) {
        return;
    }
    dot = VecFx32_CrossProduct_0(&kart->mVelocityDirection, &kart->mRotationRow2);
    if (dot <= 0) {
        dot = -dot;
    }
    kart->mVelocityScaleFactor = dot;
    if (kart->mVelocityScaleFactor < FIXED12_RATIO(7, 10)) {
        kart->mVelocityScaleFactor = FIXED12_RATIO(7, 10);
    }
}

BOOL TryHoldKartStill(Kart *kart, u32 collisionBits, void *hitListPtr) {
    u32 flags;

    flags = kart->mMotionFlags;
    if (!(flags & (KART_MOTION_COURSE_PUSH | KART_MOTION_HIT_VELOCITY | KART_MOTION_MOVED_BY_OBJECT |
                   KART_MOTION_NEAR_KART_HELD)) &&
        !(kart->mEntryFlags & KART_ENTRY_WIFI_PEER)) {
        if (!(flags & (KART_MOTION_MOVED_BY_OBJECT | KART_MOTION_NEAR_KART_HELD)) &&
            !(kart->mEffectFlags & KART_EFFECT_SHRINK_ANIMATING) && kart->mPointMotion.x == 0 &&
            kart->mPointMotion.y == 0 && kart->mPointMotion.z == 0 && kart->mAttractorPullSpeed == 0 &&
            kart->mCollisionStepFrames >= KART_COLLISION_STEP_FRAMES_FULL) {
            kart->mPos.x = kart->mPrevPos.x;
            kart->mPos.z = kart->mPrevPos.z;
        } else {
            UpdateCollisionHitLink(hitListPtr, collisionBits, kart->mCollisionHitLink, &kart->mPos, NULL);
        }
        kart->mVelocity = gKartVec3Zero;
        kart->mVelocityLength = 0;
        kart->mMotionFlags |= KART_MOTION_STILL_HOLD;
        return TRUE;
    }
    return FALSE;
}
