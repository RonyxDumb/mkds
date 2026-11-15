#include "Main/Kart/kart_reset.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Race/race_score.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"

#include "Main/Kart/kart_participant_record.h"
#include "ITCM/kart_ground_contact.h"
#include "ITCM/collision_slots.h"
#include "ITCM/code_01ffd000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/rock.h"
#include "Main/Kart/code_02080cd0.h"
#include "Main/Kart/kart_ai_battle.h"
#include "Main/Sound/sound_handle_pool.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/data_02154000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Menu/data_0217d000.h"
#include "Main/Sound/sound_system.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Kart/kart_name_tags.h"
#include "fx_mtx33.h"
#include "fx_mtx43.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "code_0212df7c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/data_0206a000.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Item/item_in_use.h"
#include "Main/Kart/camera.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Kart/kart_level.h"
#include "Main/Graphics/stem_sets.h"
#include "Main/Sound/sound_start.h"
#include "Main/Sound/kart_request_sort.h"
#include "Main/Sound/code_0210ab48.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Sound/kart_sound_callbacks.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Kart/data_02161000.h"
#include "Main/System/heap.h"
#include "code_0201750c.h"
#include "Main/Race/entry_race_ended.h"
#include "code_020172d0.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Kart/code_0207a104.h"
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
#include "Main/Item/data_027e0000.h"
#include "Main/Kart/kart_call.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

const Vec3 gKartVec3UnitX = {0x1000, 0, 0};
const Vec3 gKartVec3UnitY = {0, 0x1000, 0};
const Vec3 gKartVec3UnitZ = {0, 0, 0x1000};
const Vec3 gKartOffsetCycleStartAmount = {0x1000, 0x1000, 0x1000};
const Vec3 gKartVec3Zero = {0, 0, 0};

void AdvanceKartScaleFactor(Kart *kart) {
    s32 frameIndex;
    enum { K0 } entryIndex;

    entryIndex = kart->mEntryIndex;
    gInputSlots[entryIndex].mBitMask = PAD_KEYS_NO_START;
    if (kart->mEntryFlags & KART_ENTRY_REMOVED) {
        AdvanceKartRemovalShrink(kart);
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

void ResetKartToRespawnPoint(Kart *kart) {
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
        if (gRaceSetup->mMode == MODE_BATTLE) {
            index = GetCourseMapRespawnSlot(0);
        } else {
            index = GetCourseMapRespawnSlot(gRaceProgress->mKarts[index].mCheckpoint);
        }
        kart->mRespawnSlot = index;
    }
    index = (u16) kart->mRespawnSlot;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        respawnLink = GetCourseMapRespawnBattlePointLink(index, &respawnPos, &respawnAngles);
    } else {
        respawnLink = GetCourseMapRespawnRacePointLink(index, &respawnPos, &respawnAngles);
    }
    index = DEG_TO_ANGLE_TRUNCATED(respawnAngles.y);
    MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE(index), COS_OF_ANGLE(index));
    MTX_MultVec33(&gKartVec3UnitZ, &rotationMatrix, &respawnForward);
    if (gRaceSetup->mMode != MODE_BATTLE && gCourseMap->mItemRouteCount != 0) {
        (kartItems = &gKartItems[kart->mIndex])->mItemLink.mLink =
            GetCourseMapRespawnItemPointLink((u16) kart->mRespawnSlot);
        kartItems->mItemLink.mNextLinksUsed = 1;
    }
    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        value = gKartRespawnOffsets[kart->mIndex][0];
        forwardOffset = ((const s32 (*)[2]) &gKartRespawnOffsets[0][1])[kart->mIndex][0];
        Vec3CrossUnrounded(&gKartVec3UnitY, &respawnForward, &sideDirection);
        VEC_MultAdd(MUL_FIXED12_NO_ROUND(gKartRespawnOffsetScale, value), &sideDirection, &respawnPos, &respawnPos);
        VEC_MultAdd(MUL_FIXED12_NO_ROUND(gKartRespawnOffsetScale, forwardOffset), &respawnForward, &respawnPos,
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
    ResetKartAndSetPos(kart, &respawnPos, &respawnForward, respawnLink);
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        GetEntryKartCounters()->mRespawnCount++;
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
        if (kart->mRespawnWaitVelocityScale > 0x19a) {
            kart->mRespawnWaitVelocityScale = MUL_FIXED12_NO_ROUND(kart->mRespawnWaitVelocityScale, 0xe66LL);
        }
        *outVelocityScale = kart->mRespawnWaitVelocityScale;
    } else if (flags & KART_EFFECT_RESPAWN_WAIT_SET) {
        if (kart->mRespawnWaitVelocityScale > 0x666) {
            kart->mRespawnWaitVelocityScale = MUL_FIXED12_NO_ROUND(kart->mRespawnWaitVelocityScale, 0xe66LL);
        }
        *outVelocityScale = kart->mRespawnWaitVelocityScale;
    }
    kart->mRespawnFrames = kart->mRespawnFrames + 1;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        if (kart->mRespawnFrames == 0x16) {
            SetDispCapFadeFlag();
        } else if (kart->mRespawnFrames == 0x19) {
            StartDispCapFadeToFaded(0x3c);
        }
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && kart->mRespawnFrames == 0x55) {
        SetJgState4();
    } else if (kart->mRespawnFrames > 0x78) {
        CallKartSlot6AndToggleFlag(kart);
        finished = TRUE;
    }
    return finished;
}

void ResetKartAndSetPos(Kart *kart, const Vec3 *position, const Vec3 *forward, PointLink *link) {
    ParticipantKartRecordState *recordState;
    Vec3 axis;

    StopKartItemsAndEffects(kart);
    SetKartModelsEntryCourseColors(kart->mKartModelsEntry);
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
    GetKartForward(kart, &kart->mForward);
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
        ReturnArgument(((u32(*)(void)) ResetCameraHalfFovAngle)());
        SetCameraHeightHold(0);
    }
}

void StopKartItemsAndEffects(Kart *kart) {
    s32 effectIndex;
    KartFollowEffectIds effectIds;

    ReleaseKartItems(&gKartItems[kart->mIndex]);
    ReleaseKartSurfaceEffects(kart);
    ReleaseKartStarEffects(kart->mIndex);
    ReleaseKartKillerEffect(kart->mIndex);
    ReleaseKartContactEffect(kart->mIndex);
    ReleaseKartSpinFollowEffect(kart->mIndex);
    ReleaseKartAheadEffect(kart);
    ReleaseKartNearRankEffect(kart);
    ReleaseKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    InitKartSoundParams(kart);
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        SetThunderShrinkSoundFlag(0);
    }
    ResetKartTrackParamsFunction(kart);
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        ResetKartModelsCourseColors(kart);
    }
    if (kart->mEffectFlags & KART_EFFECT_STAR) {
        kart->mEffectFlags &= ~KART_EFFECT_STAR;
        StopKartStarModels(kart);
        kart->mItemEffect = 0;
        StopKartStarEffects(kart->mIndex);
        SetKartCharacterAnimation(kart, 0, 1);
        if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
            StopKartStarSeq();
        }
        if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
            SetKartModelsGrayColors(kart);
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
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->mKartModelHidden == 0) {
            effectIds = gKartFollowEffectIds;
            for (effectIndex = 0; effectIndex < 3; effectIndex++) {
                SetupKartFollowEffect(StartEffect(effectIds.mEffectIds[effectIndex], &kart->mPos), kart->mIndex, 0x14);
            }
        }
        StopKartKillerEffect(kart->mIndex);
        StartSound(&kart->mSoundSource, 0xfd, 0x7f, 0);
    }
    if (kart->mEntryFlags & KART_ENTRY_TERESA) {
        kart->mEntryFlags &= ~KART_ENTRY_TERESA;
        kart->mEntryFlags &= ~(KART_ENTRY_TRANSLUCENT | KART_ENTRY_NOT_DRAWN);
        kart->mItemEffect = 0;
        if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
            ShowKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else {
            StartSound(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        SetTeresaSoundFlag(0, (kart->mEntryFlags & KART_ENTRY_SELECTED) ? 1 : 0);
    }
}

void ResetKartToStartPlacement(Kart *kart) {
    Vec3 startPos;
    Vec3 forward;
    Vec3 startAngles;
    Vec3 *collisionPos;

    if (!(kart->mEntryFlags & KART_ENTRY_REMOVED)) {
        return;
    }
    GetCourseMapKartStartPlacement(&startPos, &startAngles, kart->mIndex);
    kart->mHeadingAngle = (u32) (startAngles.y * 0xb6) >> 12;
    QuaternionFromAxisAngle(&gKartVec3UnitY, kart->mHeadingAngle, &kart->mHeadingQuaternion);
    Matrix4x3FromQuaternion(&kart->mRotationMatrix, &kart->mHeadingQuaternion);
    GetKartForward(kart, &forward);
    ResetKartAndSetPos(kart, &startPos, &forward, NULL);
    if (gRaceSetup->mMode == MODE_WIFI) {
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

void InitKartPhysicalParams(Kart *kart) {
    s32 factor;
    s32 adjustment;
    s16 surfaceIndex;
    KartPhysicalParam *physicalParam;
    s32 *charPhysicalParam;

    kart->mPhysicalParam = GetKartPhysicalParam(kart->mIndex);
    factor = 0x1000;
    adjustment = 0;
    if (IsRaceAwardOrStaffRoll() == 0) {
        switch (gRaceSetup->mEngineIndex) {
            case 0:
                factor = 0xb33;
                adjustment = -0x28;
                break;
            case 1:
                factor = 0xd9a;
                adjustment = -0x14;
                break;
        }
    }
    kart->mPhysicalParam->mBaseSpeedLimit = MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mBaseSpeedLimit, factor);
    kart->mPhysicalParam->mDriftTurnRate = kart->mPhysicalParam->mDriftTurnRate + adjustment;
    kart->mSpeedLimitFactorPerDepth = 0x1000 - kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4];
    kart->mSpeedLimitFactorPerDepth = FX_Div(kart->mSpeedLimitFactorPerDepth, kart->mPhysicalParam->mRadius << 1);
    kart->mCharPhysicalParam = GetCharPhysicalParam(kart->mIndex);
    physicalParam = kart->mPhysicalParam;
    charPhysicalParam = kart->mCharPhysicalParam;
    for (surfaceIndex = 0; surfaceIndex < 12; surfaceIndex++) {
        factor = physicalParam->mSurfaceSpeedLimitFactors[surfaceIndex];
        if (factor < 0x1000) {
            physicalParam->mSurfaceSpeedLimitFactors[surfaceIndex] = MUL_FIXED12_ROUNDED(factor, *charPhysicalParam);
        }
    }
}

void ResetKartMotionVectorsAndFactors(Kart *kart) {
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
    kart->mTurnedForwardEaseFactor = 0x1000;
    kart->mHeadingAnglePerFrame = 0;
}

void ResetKart(Kart *kart) {
    Vec3 zeroVector;
    u16 slotIndex;

    ClearCharacterTurnAndNextAnimation(kart->mKartModelsEntry);
    kart->mMotionFlags = 0;
    kart->mDriveFlags = 0;
    kart->mEffectFlags = 0;
    zeroVector = gKartVec3Zero;
    kart->mDrawMatrixPos = zeroVector;
    kart->mPrevPos = kart->mDrawMatrixPos;
    kart->mPos = kart->mPrevPos;
    kart->mVelocity = zeroVector;
    kart->mVelocityDirection = zeroVector;
    kart->mScale.x = 0x1000;
    kart->mScale.y = 0x1000;
    kart->mScale.z = 0x1000;
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    kart->mScaleBase.x = 0x1000;
    kart->mScaleBase.y = 0x1000;
    kart->mScaleBase.z = 0x1000;
    kart->mScaleYFactor = TO_FIXED12(1);
    kart->mGravity = -0x2b9;
    kart->mSpeedLimitGoal = 0;
    kart->mSpeedLimit = 0xd000;
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
    kart->mTurnedForwardEaseFactor = 0x1000;
    kart->mGroundNormal = gKartVec3UnitY;
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
    kart->mItemEffect = 0;
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
    kart->mDriftCharge = 0;
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
    kart->mVisible = 0xffff;
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
    kart->mModelScaleKind = 0;
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = 0;
    kart->mModelScaleY = 0x1000;
    kart->mModelScaleX = 0x1000;
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
    kart->mOffsetCyclePhaseStep = 0x1000;
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
    SetKartCharacterAnimation(kart, 0, 0);
    kart->mTireTurnAngle = 0;
}

void InitParticipantKartRecordState(Kart *kart, void *heap) {
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
    recordState->mUnk_0c = recordState->mSmoothedHeadingAngle;
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
    NNS_FndInitList(&recordState->mPendingRecords, 0);
    NNS_FndInitList(&recordState->mFreeRecords, 0);
    entries = HeapAlloc(heap, 0x438);
    for (recordIndex = 0; recordIndex < 0x1e; recordIndex++) {
        NNS_FndAppendListObject(&recordState->mFreeRecords, entries + recordIndex * 0x24);
    }
}

void ResetParticipantKartRecordPos(Kart *kart) {
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

void InitKartFlags(Kart *kart) {
    kart->mEntryFlags = 0;
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        kart->mEntryFlags |= KART_ENTRY_SELECTED;
        if (gRaceSetup->mMode == MODE_WIFI) {
            kart->mEntryFlags |= KART_ENTRY_WIFI_LOCAL;
            if (GetEntryRaceEnded() != 0) {
                kart->mEntryFlags &= ~KART_ENTRY_WIFI_LOCAL;
                kart->mEntryFlags |= KART_ENTRY_WIFI_PEER;
            }
        }
    } else if (gRaceSetup->mMode == MODE_WIFI) {
        kart->mEntryFlags |= KART_ENTRY_WIFI_PEER;
    }
    if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
        kart->mEntryFlags |= KART_ENTRY_GHOST;
        kart->mVisible = 0;
    }
    if (kart->mKartModelsEntry->mCharacterAnimation != NULL) {
        kart->mEntryFlags |= KART_ENTRY_HAS_CHARACTER_ANIMATION;
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK || IsRaceAwardOrStaffRoll() != 0) {
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

void InitKartSound(Kart *kart) {
    InitSoundSource(&kart->mSoundSource, 0, kart->mPosSource);
    InitKartSoundCallbacks(kart, &kart->mSound);
    InitKartSoundParams(kart);
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
            SetSoundSourceFlagBit(&kart->mSoundSource, 2, 1);
        }
        if (gRaceSetup->mRaceKind == RACE_KIND_REPLAY) {
            ResetSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange);
        }
    } else {
        if (kart->mSoundSource.mSourceFlags & 1) {
            SetSoundSourceFlagBit(&kart->mSoundSource, 2, 1);
        }
        ResetSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange);
    }
}

void InitKartSoundParams(Kart *kart) {
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

    kart->mSound.mSoundId = 0xa5;
    kartSound = &kart->mSound;
    kartSound->mVolume = 0x64;
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
    firstSoundColumn = *(s32 *) ((u8 *) &gKartSoundRowSoundIds[0][0] + rowOffset);
    secondSoundColumn = *(s32 *) ((u8 *) &gKartSoundRowSoundIds[0][1] + rowOffset);
    thirdSoundColumn = *(s32 *) ((u8 *) &gKartSoundRowSoundIds[0][2] + rowOffset);
    highRatioSoundId = *(s32 *) ((u8 *) &gKartSoundRowSoundIds[0][3] + rowOffset);
    midRatioSoundId = *(s32 *) ((u8 *) &gKartSoundRowSoundIds[0][4] + rowOffset);
    lowRatioSoundId = *(s32 *) ((u8 *) &gKartSoundRowSoundIds[0][5] + rowOffset);
    lastSoundColumn = *(s32 *) ((u8 *) &gKartSoundRowSoundIds[0][6] + rowOffset);
    soundRow.mSoundRowIndex = soundRowIndex;
    soundRow.mPitchedSoundId = firstSoundColumn;
    soundRow.mUnk_08 = secondSoundColumn;
    soundRow.mUnk_0c = thirdSoundColumn;
    soundRow.mHighRatioSoundId = highRatioSoundId;
    soundRow.mMidRatioSoundId = midRatioSoundId;
    soundRow.mLowRatioSoundId = lowRatioSoundId;
    soundRow.mClampedPitchSoundId = lastSoundColumn;
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
        secondSoundColumn = thirdSoundColumn;
    }
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
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
    return StartSound(sourceCopy, soundIdCopy, volume, pitch);
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
    StartSound(sourceCopy, soundIdCopy, volume, pitch);
}

void StartKartSoundWhileRequested(void *kart, int soundId) {
    if (StartSoundWhileRequested(kart, soundId, 0x7f, 0) != NULL) {
        ((Kart *) kart)->mSound.mWhileRequestedSoundId = soundId;
    }
}

void RequestKartSound(void *kart, int soundId) {
    int sortKeyBase;

    sortKeyBase = GetKartCameraDistanceSquared(((Kart *) kart)->mIndex);
    AddSoundRequest(&gSoundRequestQueues[3], sortKeyBase + GetKartSoundRequestSortOffset(),
                    StartKartSoundWhileRequested, kart, soundId);
}

void StartKartSeqArcSoundOffset7(Kart *kart) {
    if (kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT)) {
        return;
    }
    StartKartSeqArcSound(kart, kart->mSoundIndex, 7);
}

void AdvanceKartModelScaleAnimation(Kart *kart) {
    kart->mModelScaleFrameIndex++;
    if (kart->mModelScaleFrameIndex >= kart->mModelScaleFrameCount) {
        kart->mModelScaleFrameIndex = 0;
        kart->mEffectFlags &= ~KART_EFFECT_MODEL_SCALE_ANIM;
        return;
    }
    if (kart->mModelScaleKind == 0) {
        kart->mModelScaleY = gKartModelScaleYKind0Table[kart->mModelScaleFrameIndex];
        kart->mModelOffsetY = gKartModelOffsetYKind0And2Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = TO_FIXED12(1);
        kart->mModelScaleX = kart->mModelScaleZ;
    } else if (kart->mModelScaleKind == 1) {
        kart->mModelScaleY = gKartModelScaleYKind1Table[kart->mModelScaleFrameIndex];
        kart->mModelOffsetY = gKartModelOffsetYKind1Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = TO_FIXED12(1);
        kart->mModelScaleX = kart->mModelScaleZ;
    } else if (kart->mModelScaleKind == 2) {
        kart->mModelScaleY = 0x1000;
        kart->mModelOffsetY = gKartModelOffsetYKind0And2Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleX = gKartModelScaleXKind2Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = gKartModelScaleZKind2Table[kart->mModelScaleFrameIndex];
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
    fraction = kart->mOffsetCyclePhase & 0xfff;
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

    if (kart->mHeadingAngleOffsetCount <= 2) {
        kart->mHeadingAngleOffsetPerFrame =
            kart->mHeadingAngleOffsetDirection * 0x3c + kart->mHeadingAngleOffsetPerFrame;
        if (kart->mHeadingAngleOffsetPerFrame > 0x17c) {
            kart->mHeadingAngleOffsetPerFrame = 0x17c;
        } else if (kart->mHeadingAngleOffsetPerFrame < -0x17c) {
            kart->mHeadingAngleOffsetPerFrame = -0x17c;
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
        kart->mRevLevel = 0x1000;
    } else {
        kart->mHeadingAngleOffsetPerFrame =
            kart->mHeadingAngleOffsetDirection * 0x3c + kart->mHeadingAngleOffsetPerFrame;
        if (kart->mHeadingAngleOffsetPerFrame > 0xd2) {
            kart->mHeadingAngleOffsetPerFrame = 0xd2;
        } else if (kart->mHeadingAngleOffsetPerFrame < -0xd2) {
            kart->mHeadingAngleOffsetPerFrame = -0xd2;
        }
        kart->mHeadingAngleOffset = kart->mHeadingAngleOffset + kart->mHeadingAngleOffsetPerFrame;
        kart->mRevLevel = MUL_FIXED12_NO_ROUND(kart->mRevLevel, 0xf5c);
        offset = kart->mHeadingAngleOffset;
        if ((offset > 0 && kart->mHeadingAngleOffsetDirection > 0) ||
            (offset < 0 && kart->mHeadingAngleOffsetDirection < 0)) {
            kart->mHeadingAngleOffset = 0;
            kart->mEffectFlags &= ~KART_EFFECT_HEADING_SWING;
            SetKartCharacterAnimation(kart, 0, 1);
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
    if (mode == 2) {
        kart->mModelScaleKind = 2;
    } else if (kart->mMotionFlags & KART_MOTION_HOPPING) {
        kart->mModelScaleKind = 1;
    } else if (kart->mAirborneFrames > 0xa) {
        kart->mModelScaleKind = 1;
    } else {
        kart->mModelScaleKind = 0;
    }
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = 0xf;
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
            ResetKartModelsCourseColors(kart);
        }
        StopKartNearRankEffect(kart);
    }
    ReleaseKartAheadEffect(kart);
    kart->mMotionFlags &=
        ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_HOP_STEER);
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    kart->mState = KART_STATE_NORMAL;
    kart->mEffectFlags &= ~(KART_EFFECT_TUMBLING | KART_EFFECT_Y_SPIN);
    kart->mDriveFlags &= ~KART_DRIVE_HIT_STATE;
    SetKartCharacterAnimation(kart, 0, 1);
    kart->mMotionFlags |= KART_MOTION_STATE_RESET;
    ResetKartMotionVectorsAndFactors(kart);
    StartFixedPositionEffects(kart);
    if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
        return;
    }
    StartCameraWobbleByCourse();
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_AIRSHIP:
            StartTimedQuadFromTable(0);
            playingSound = StartSound(&kart->mSoundSource, 0x15c, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= 0x10;
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
            NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x1d2);
            break;
        case COURSE_ID_PINBALL:
            playingSound = StartSound(&kart->mSoundSource, 0x15b, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= 0x10;
            }
            break;
    }
}

void StartFixedPositionEffects(Kart *kart) {
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
    currentCamera = GetCurrentCamera();
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
    return Vec3NormalizeAndGetLengthUnchecked(src, dst);
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
    placementIndex = *gCourseMap->mKeyedPlacementIndexByKey;
    placementPos.x = gCourseMap->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = gCourseMap->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = gCourseMap->mKeyedPlacements[placementIndex].mPos.z;
    placementAngles.x = gCourseMap->mKeyedPlacements[*gCourseMap->mKeyedPlacementIndexByKey].mRotation.x;
    placementAngles.y = gCourseMap->mKeyedPlacements[*gCourseMap->mKeyedPlacementIndexByKey].mRotation.y;
    placementAngles.z = gCourseMap->mKeyedPlacements[*gCourseMap->mKeyedPlacementIndexByKey].mRotation.z;
    angleIndex = (u16) (((s64) placementAngles.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >> 4;
    MTX_RotY33_(&rotationMatrix, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
    MTX_MultVec33(&gKartVec3UnitZ, &rotationMatrix, &placementForward);
    SkipOrthoQuadsHoldAndSetVelocities(kart->mIndex);

    flags = kart->mEffectFlags;
    if (!(flags & KART_EFFECT_COURSE_COLORED) && (flags & KART_EFFECT_GESSO)) {
        itemEffectState = &kart->mItemEffectData;
        if (itemEffectState->mGessoFrames <= 0x190) {
            itemEffectState->mGessoFrames = 0x190;
            kart->mEffectFlags |= KART_EFFECT_COURSE_COLORED;
            StartKartModelColorBlend(kart->mKartModelsEntry, GetKartCourseDiffColor(), GetKartCourseEmiColor(),
                                     GetKartCourseAmbColor());
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_GESSO) {
        AdvanceKartGesso(kart);
    }
    flags = kart->mEffectFlags;
    if (flags & KART_EFFECT_KILLER) {
        AdvanceKartKiller(kart);
    } else {
        if (flags & KART_EFFECT_THUNDER_SHRINK) {
            AdvanceKartThunderShrink(kart);
        }
        if (kart->mEffectFlags & KART_EFFECT_SCALE_TABLE) {
            AdvanceKartScaleTableEffect(kart);
        }
        if (kart->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED) {
            AdvanceKartTeresa(kart);
        }
    }

    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        itemEffectState = &kart->mItemEffectData;
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            AddSoundRequest(gSoundRequestQueues, GetKartCameraDistanceSquared(kart->mIndex), RequestKartSound, kart,
                            0xa3);
        }
        itemEffectState->mAheadBoostFrames++;
        if (itemEffectState->mAheadBoostFrames > KART_KILLER_RANK_END_FRAMES &&
            (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST)) {
            kart->mEffectFlags &= ~KART_EFFECT_AHEAD_BOOST;
            kart->mAheadSpeedLimitFactor = TO_FIXED12(1);
            if (!(kart->mEffectFlags & KART_EFFECT_GESSO)) {
                ResetKartModelsCourseColors(kart);
            }
            StopKartNearRankEffect(kart);
        }
    }

    if (kart->mEffectFlags & KART_EFFECT_STAR) {
        itemEffectState = &kart->mItemEffectData;
        AdvanceKartStarEffects(kart->mIndex);
        if ((kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) &&
            kart->mKartModelsEntry->mCharacterAnimation->mCurrentIndex == 0) {
            SetKartCharacterAnimation(kart, 2, 1);
        }
        itemEffectState->mStarFrames++;
        if (itemEffectState->mStarFrames > KART_TERESA_MAX_FRAMES) {
            kart->mEffectFlags &= ~KART_EFFECT_STAR;
            StopKartStarModels(kart);
            kart->mItemEffect = 0;
            StopKartStarEffects(kart->mIndex);
            SetKartCharacterAnimation(kart, 0, 1);
            if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                StopKartStarSeq();
            }
            if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
                SetKartModelsGrayColors(kart);
            }
        }
    }

    gInputSlots[kart->mEntryIndex].mBitMask = PAD_KEY_Y | PAD_KEY_X | PAD_KEY_L | PAD_KEY_SELECT;
    Vec3CrossUnrounded(&gKartVec3UnitY, &placementForward, &side);
    VEC_Subtract(&kart->mPos, &placementPos, &toKart);
    toKart.y = 0;
    VEC_MultAdd(Vec3DotUnrounded(&side, &toKart), &side, &placementPos, &placementPos);
    Vec3DotUnrounded(&side, &toKart);
    VEC_Subtract(&placementPos, &kart->mPos, &toTarget);
    distance = NormalizeLengthOrZero(&toTarget, &toTarget);

    if (Vec3DotUnrounded(&toTarget, &placementForward) <= 0) {
        StopDispCapBlend();
        kart->mDriveFlags &= ~KART_DRIVE_KEYED_PLACEMENT;
        AdvanceKartQuaternionBlendFactor(kart, &kart->mGroundNormal);
        kart->mDriveFlags &= ~KART_DRIVE_INPUT_LOCKED;
        kart->mAirTiltAngleOffset = (s16) FROM_FIXED12(MUL_FIXED12_NO_ROUND(placementAngles.x, 0x4000)) + 0x32;
        if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && gRaceSetup->mCourseId == COURSE_ID_AIRSHIP) {
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
        Vec3CrossUnrounded(&gKartVec3UnitY, &kart->mTurnedForward, &sideVector);
        Vec3CrossUnrounded(&kart->mTurnedForward, &sideVector, &groundNormal);
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

    kart->mForwardSpeed = 0x1e000;
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
    VEC_Add(&kart->mPos, &kart->mVelocity, &kart->mPos);
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
    kart->mVerticalSpeed = 0x3000;
    placementIndex = gCourseMap->mKeyedPlacementIndexByKey[key];
    placementPos.x = gCourseMap->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = gCourseMap->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = gCourseMap->mKeyedPlacements[placementIndex].mPos.z;
    angleIndex = (u16) (((s64) gCourseMap->mKeyedPlacements[gCourseMap->mKeyedPlacementIndexByKey[key]].mRotation.y *
                             0xb60b60b60bLL +
                         0x80000000LL) >>
                        44) >>
                 4;
    MTX_RotY33_(&rotationMatrix, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
    MTX_MultVec33(&gKartVec3UnitZ, &rotationMatrix, &placementForward);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        VEC_Subtract(&placementPos, &kart->mPos, &offset);
        CallStandingsKartOffsetCallback(kart->mIndex, &offset);
    }
    kart->mPos = placementPos;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mForwardSpeed = 0x5000;
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
                NNS_SndArcPlayerStartSeqArc(sndHandle, 0, 0x159);
            }
        }
    }
    if (!(kart->mEntryFlags & KART_ENTRY_CPU)) {
        return;
    }
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    ResetBattleKartAiAtPointLink(kart->mAi, GetKeyedPlacementBattlePointLink(key));
}

void ComputeKartAirTiltQuaternion(Kart *kart, Vec4 *quaternion) {
    MtxFx43 headingMatrix;
    MtxFx43 tiltMatrix;
    Vec3 tiltAxis;
    Vec3 tiltedUp;
    s32 dot;
    u16 headingAngle;
    u16 airTiltAngle;

    if (kart->mVelocityLength < 0x1000) {
        return;
    }
    if (Vec3DotUnrounded(&kart->mRotationRow1, &gKartVec3UnitY) <= 0) {
        return;
    }
    kart->mAirTiltAngle = kart->mAirTiltAngle + kart->mAirTiltAngleOffset;
    headingAngle = kart->mHeadingAngle;
    airTiltAngle = kart->mAirTiltAngle;
    MTX_RotY43_(&headingMatrix, FX_SinIdx(headingAngle), FX_CosIdx(headingAngle));
    MTX_MultVec43(&gKartVec3UnitX, &headingMatrix, &tiltAxis);
    MTX_RotAxis43(&tiltMatrix, &tiltAxis, FX_SinIdx(airTiltAngle), FX_CosIdx(airTiltAngle));
    MTX_MultVec43(&gKartVec3UnitY, &tiltMatrix, &tiltedUp);
    TryQuaternionFromVectors(quaternion, &gKartVec3UnitY, &tiltedUp);
    if (kart->mDriveFlags & KART_DRIVE_QUATERNION_FLIPPED) {
        quaternion->x = -quaternion->x;
        quaternion->y = -quaternion->y;
        quaternion->z = -quaternion->z;
        quaternion->w = -quaternion->w;
    }
    if (kart->mMotionFlags & KART_MOTION_HOPPING) {
        return;
    }
    dot = Vec3DotUnrounded(&kart->mVelocityDirection, &kart->mRotationRow2);
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
            kart->mCollisionStepFrames >= 0x64) {
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
