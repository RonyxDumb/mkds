#include "Main/Kart/point_link_cursor.h"
#include "Main/Kart/kart_ai_gap_limits.h"
#include "Main/Kart/point_link_cursor_first_next.h"
#include "Main/System/wireless_vram_state.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "fixed_vector_math.h"
#include "Main/Kart/kart_ai_follow.h"
#include "Main/Kart/kart_ai.h"
#include "Main/Kart/kart_effects_ahead.h"
#include "Main/Kart/kart_ai_staff_roll_advance.h"
#include "Main/Kart/kart_call.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Kart/kart_nop_and_absolute_value.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "fixed_arctangent.h"
#include "ITCM/collision_slots.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_point_link_effects.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/kart_ai_battle.h"
#include "Main/Race/race_progress_lap.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Race/kart.h"
#include "ITCM/kart_motion.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Kart/camera.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Kart/point_link_follow_data.h"
#include "Main/System/init_after_startup.h"

const s32 gKartAiRaceStartBoostRandomLimitsIndex0[9] = {0xb33, 0, 0, 0, 0, 0, 0, 0, 0};
const s32 gKartAiRaceStartBoostRandomLimitsIndex1[9] = {0x1000, 0x1000, 0xe66, 0x800, 0x333, 0, 0, 0, 0};
const s32 gKartAiRaceStartBoostRandomLimitsIndex2[9] = {0x1000, 0x1000, 0x1000, 0x1000, 0xccd, 0x99a, 0x4cd, 0, 0};
const s32 gKartAiDriftChargeRandomLimitsIndex2[9] = {0x1000, 0xccd, 0xccd, 0xccd, 0xccd, 0xccd, 0xccd, 0xccd, 0xccd};
const s32 gKartAiRaceStartHeadingSwingRandomLimitsIndex0[9] = {0, 0, 0, 0, 0, 0x19a, 0x4cd, 0x99a, 0xb33};
const s32 gKartAiRaceStartHeadingSwingRandomLimitsIndex1[9] = {0, 0, 0, 0, 0, 0, 0, 0x333, 0x4cd};
const s32 gKartAiDriftChargeRandomLimitsIndex1[9] = {0xb33, 0x666, 0x666, 0x666, 0x666, 0x666, 0x666, 0x666, 0x666};
const s32 gKartAiDriftStartRandomLimitsIndex0[9] = {0xb33, 0x800, 0x59a, 0x333, 0x19a, 0, 0, 0, 0};
const s32 gKartAiDriftStartRandomLimitsIndex1[9] = {0x1000, 0xe66, 0xccd, 0xa66, 0x800, 0x4cd, 0x19a, 0, 0};
const s32 gKartAiDriftStartRandomLimitsIndex2[9] = {0x1000, 0x1000, 0xe66, 0xccd, 0xa66, 0x800, 0x666, 0x4cd, 0x333};
const s32 gKartAiDriftChargeRandomLimitsIndex0[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
const s32 gKartAiRaceStartHeadingSwingRandomLimitsIndex2[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
const s32 *gKartAiVelocityFactorScale;
const s32 *gKartAiRaceStartHeadingSwingRandomLimits;
void (*gAdvanceKartAiPointLinkCursor)(struct PointLinkCursor *linkCursor);
void (*gUseItemWhenCircleKindCallback)(KartAiItemUse *itemUse, struct KartAi *kartAi);
void (*gUseItemNotTrailKindCallback)(KartAiItemUse *itemUse, struct KartAi *kartAi);
void (*gUseItemTrailKindCallback)(KartAiItemUse *itemUse, struct KartAi *kartAi);
const s32 *gKartAiDriftChargeRandomLimits;
const struct KartAiItemUseEntry *gCurrentHeldItemEntries;
void (*gUseItemWhenNotCircleKindCallback)(KartAiItemUse *itemUse, struct KartAi *kartAi);
const struct KartAiItemUseEntry *gCurrentItemInUseEntries;
const s32 *gKartAiDriftStartRandomLimits;
const s32 *gKartAiGapLimitsByRank;
const s32 *gKartAiRaceStartBoostRandomLimits;
void (*gSetKartAiLinkPos)(struct KartAi *kartAi, struct PointLinkCursor *linkCursor, struct Kart *kart);

// Steps the cursor to the first next link without a choice; returns the length of the new direction.
u32 AdvancePointLinkCursorToFirstNext(PointLinkCursor *cursor) {
    cursor->mPreviousLink = cursor->mLink;
    cursor->mLink = cursor->mLink->mNextLinks[0];
    VEC_Subtract(cursor->mLink->mPoint, cursor->mPreviousLink->mPoint, &cursor->mDirection);
    return Vec3NormalizeAndGetLengthUnchecked(&cursor->mDirection, &cursor->mDirection);
}

static inline BOOL IsKartFlagMaskClear(s32 kartIndex) {
    return (GetKart(kartIndex)->mEntryFlags & (KART_ENTRY_REMOVED | KART_ENTRY_TERESA | KART_ENTRY_PARKED)) == 0;
}

static inline s32 KartAiGetCurrentTeamIndex(u32 entryIndex) {
    return *(vs32 *) &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex;
}

static inline s32 IsKartAiTargetAllowed(u32 kartIndex, u32 targetIndex) {
    BOOL result = FALSE;
    s32 playerKind;
    BOOL isHumanGhostOrPeer;

    if (gRaceSetup->mUseTeams == 0 ||
        gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex != KartAiGetCurrentTeamIndex(targetIndex)) {
        isHumanGhostOrPeer = FALSE;
        playerKind = gRaceSetup->mCurrentEntries[targetIndex].mPlayer.mKind;
        if ((u32) playerKind <= 3) {
            if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                isHumanGhostOrPeer = TRUE;
            }
        }
        if (isHumanGhostOrPeer != FALSE || GetNonCpuKartCountOutsideKartTeam(kartIndex) <= 0) {
            if (IsKartFlagMaskClear(targetIndex)) {
                result = TRUE;
            }
        }
    }
    return result;
}

void AdvanceAwardPointLinkCursor(PointLinkCursor *pointLinkCursor) {
    u32 nextLinkIndex = 0;
    Kart *kart = GetKart(pointLinkCursor->mKartIndex);
    s32 animation;

    if (pointLinkCursor->mLink->mNextCount > 1) {
        nextLinkIndex = pointLinkCursor->mKartIndex;
    }
    pointLinkCursor->mPreviousLink = pointLinkCursor->mLink;
    pointLinkCursor->mLink = pointLinkCursor->mLink->mNextLinks[nextLinkIndex];
    animation = gPointLinkAnimationIndices[pointLinkCursor->mLink->mValues[2]];
    if (animation != kart->mKartModelsEntry->mCharacterAnimation->mCurrentIndex) {
        SetKartCharacterAnimation(kart, animation, 1);
    }
    VEC_Subtract(pointLinkCursor->mLink->mPoint, pointLinkCursor->mPreviousLink->mPoint, &pointLinkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&pointLinkCursor->mDirection, &pointLinkCursor->mDirection);
}

s32 GetPointLinkSpeedRatio(PointLinkCursor *pointLinkCursor) {
    s32 fixedValue = TO_FIXED12(pointLinkCursor->mLink->mValues[1]);

    return MUL_FIXED12_ROUNDED(fixedValue, 0x29);
}

void AdvanceStaffRollPointLinkCursor(PointLinkCursor *pointLinkCursor) {
    Kart *kart = GetKart(pointLinkCursor->mKartIndex);
    u16 nextLinkIndex;
    s32 animation;

    if (pointLinkCursor->mLink->mNextCount > 1 && pointLinkCursor->mBranchChoiceCount < 2) {
        if (pointLinkCursor->mBranchChoiceCount == 0) {
            nextLinkIndex = pointLinkCursor->mKartIndex / 3;
        } else {
            nextLinkIndex = pointLinkCursor->mKartIndex % 3;
        }
        pointLinkCursor->mBranchChoiceCount++;
    } else {
        nextLinkIndex = 0;
    }
    pointLinkCursor->mPreviousLink = pointLinkCursor->mLink;
    pointLinkCursor->mLink = pointLinkCursor->mLink->mNextLinks[nextLinkIndex];
    animation = gPointLinkAnimationIndices[pointLinkCursor->mLink->mValues[2]];
    if (animation != kart->mKartModelsEntry->mCharacterAnimation->mCurrentIndex) {
        SetKartCharacterAnimation(kart, animation, 1);
    }
    if (pointLinkCursor->mKartIndex != 0) {
        if (pointLinkCursor->mLink->mValues[3] == 0) {
            kart->mEntryFlags &= ~KART_ENTRY_HIDDEN;
        } else {
            kart->mEntryFlags |= KART_ENTRY_HIDDEN;
        }
    }
    VEC_Subtract(pointLinkCursor->mLink->mPoint, pointLinkCursor->mPreviousLink->mPoint, &pointLinkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&pointLinkCursor->mDirection, &pointLinkCursor->mDirection);
}

void SetupKartAiGlobals(void) {
    gKartAiVelocityFactorScale =
        gRaceSetup->mMode == MODE_BATTLE ? &gKartAiBattleVelocityFactorScale : &gKartAiRaceVelocityFactorScale;
    switch (GetKartAiEngineOrDifficultyIndex()) {
        case KART_AI_LEVEL_LOW:
            gKartAiDriftStartRandomLimits = gKartAiDriftStartRandomLimitsIndex0;
            gKartAiDriftChargeRandomLimits = gKartAiDriftChargeRandomLimitsIndex0;
            break;
        case KART_AI_LEVEL_MEDIUM:
            gKartAiDriftStartRandomLimits = gKartAiDriftStartRandomLimitsIndex1;
            gKartAiDriftChargeRandomLimits = gKartAiDriftChargeRandomLimitsIndex1;
            break;
        case KART_AI_LEVEL_HIGH:
            gKartAiDriftStartRandomLimits = gKartAiDriftStartRandomLimitsIndex2;
            gKartAiDriftChargeRandomLimits = gKartAiDriftChargeRandomLimitsIndex2;
            break;
        default:
            gKartAiDriftStartRandomLimits = gKartAiDriftStartRandomLimitsIndex2;
            gKartAiDriftChargeRandomLimits = gKartAiDriftChargeRandomLimitsIndex2;
            break;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        gAdvanceKartAiPointLinkCursor = AdvanceAwardPointLinkCursor;
        gSetKartAiLinkPos = SetKartAiLinkPosAndClearSideOffset;
    } else if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        gAdvanceKartAiPointLinkCursor = AdvanceStaffRollPointLinkCursor;
        gSetKartAiLinkPos = SetKartAiLinkPosAndClearSideOffset;
    } else {
        gAdvanceKartAiPointLinkCursor = AdvancePointLinkCursor;
        gSetKartAiLinkPos = SetKartAiLinkPosAndAddSideOffset;
    }
}

void SetupRaceKartAi(KartAi *kartAi, Kart *kart, s32 useDefaultTable) {
    s32 value;
    RandomState64 *kartAiRandom;

    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->mIndexModFour = kartAi->mIndex % 4;
    if (useDefaultTable != 0) {
        value = 0;
    } else {
        value = GetKartAiTableIndex(kartAi->mIndex);
    }
    kartAi->mDriftStartRandomLimit = gKartAiDriftStartRandomLimits[value];
    kartAi->mDriftChargeRandomLimit = gKartAiDriftChargeRandomLimits[value];
    kartAi->mMinVelocityLength = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, 0x99a);
    InitRacePointLinkCursor(&kartAi->mPointLinkCursor, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    value = (s16) (u16) (kartAiRandom->mValue >> 52);
    kartAi->mHeadingSwingSign = value > 0x800 ? 1 : -1;
}

void ResetKartAi(KartAi *kartAi, s32 value) {
    kartAi->mLinkPosWithSideOffset = *kartAi->mPointLinkCursor.mLink->mPoint;
    kartAi->mSideOffset = gKartAiZeroSideOffset;
    kartAi->mSideOffsetFrames = 0;
    kartAi->mSideOffsetFrameLimit = 0;
    kartAi->mTurnAngleDegrees = 0;
    kartAi->mSideOffsetRatio = 0;
    kartAi->mContactStageFrames = 0;
    kartAi->mContactStageFrameLimit = 0;
    kartAi->mUnk_80 = 0;
    kartAi->mUnk_7c = 0;
    kartAi->mResetAtPointLink = value;
    kartAi->mContactStage = KART_AI_CONTACT_NONE;
    kartAi->mContactTimer = 0;
    kartAi->mTargetKart = NULL;
    kartAi->mTargetAhead = 0;
    kartAi->mTargetDistanceSquared = 0;
    kartAi->mTargetForwardDot = -0x1000;
    kartAi->mBalloonCountGoal = 0;
    kartAi->mInflateWaitFrames = 0;
    kartAi->mInflatePending = FALSE;
    kartAi->mDriftState = KART_AI_DRIFT_NONE;
    kartAi->mTurnSide = KART_AI_TURN_NONE;
    kartAi->mDriftFrames = 0;
    kartAi->mDriftChargeRollAllowed = FALSE;
    SetKartAiSideOffsetFromKart(kartAi);
}

void ResetRaceKartAiAtPointLink(KartAi *kartAi) {
    RacePointLink *pointLink;

    ResetPointLinkCursor(&kartAi->mPointLinkCursor, pointLink);
    ResetKartAi(kartAi, 1);
}

void AdvanceRaceKartAi(KartAi *kartAi) {
    Vec3 kartPos;
    Vec3 toLinkPos;
    Vec3 *kartForward;
    PointLinkCursor *linkCursor;
    Kart *kart;
    RacePointLink *requestedLink;

    AdvanceKartAiContactStages(kartAi);
    linkCursor = &kartAi->mPointLinkCursor;
    kart = kartAi->mKart;
    if (kartAi->mDriftState == KART_AI_DRIFT_HOLDING) {
        kartForward = &kart->mTurnedForward;
    } else {
        kartForward = &kart->mRotationRow2;
    }
    requestedLink = linkCursor->mRequestedLink;
    GetKartPos(&kartPos, kartAi->mIndex);
    AdvanceKartAiAlongLinks(kartAi, linkCursor, kart, requestedLink, &kartPos, kartForward);
    if (kart->mState == KART_STATE_NORMAL) {
        RequestBits(kartAi->mKart->mEntryIndex, PAD_KEY_A);
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kartPos, &toLinkPos);
        AdvanceKartAiHeading(kartAi, &toLinkPos, kartForward);
    }
    AdvanceKartAiDrift(kartAi);
    PickKartAiTargetKart(kartAi);
}

void AdvanceKartAiAlongLinks(KartAi *kartAi, PointLinkCursor *linkCursor, Kart *kart, RacePointLink *requestedLink,
                             Vec3 *kartPos, Vec3 *kartForward) {
    Vec3 toLinkPos;
    Vec3 crossProduct;
    Vec3 *planeNormal;
    s32 normalComponent;
    s32 crossLength;
    s32 angle;
    s32 angleDegrees;
    s32 isLinkReached;

    if (requestedLink != NULL && linkCursor->mLink != requestedLink) {
        PickKartAiDriftAtLink(kartAi);
        AdvancePointLinkCursorTo(linkCursor, requestedLink);
        gSetKartAiLinkPos(kartAi, linkCursor, kart);
        return;
    }
    if (GetRaceUpdateFramesMod8() == kartAi->mIndex) {
        if (kartAi->mKart->mMotionFlags & KART_MOTION_HIT_VELOCITY) {
            SetKartAiSideOffsetFromKart(kartAi);
        }
        planeNormal = &kart->mRotationRow1;
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kart->mPos, &toLinkPos);
        normalComponent = VEC_DotProduct(planeNormal, &toLinkPos);
        toLinkPos.x = toLinkPos.x - MUL_FIXED12_NO_ROUND(kart->mRotationRow1.x, normalComponent);
        toLinkPos.y = toLinkPos.y - MUL_FIXED12_NO_ROUND(planeNormal->y, normalComponent);
        toLinkPos.z = toLinkPos.z - MUL_FIXED12_NO_ROUND(planeNormal->z, normalComponent);
        Vec3CrossUnrounded(kartForward, &toLinkPos, &crossProduct);
        crossLength = VEC_Mag(&crossProduct);
        angle = FX_Atan2(crossLength, Vec3DotUnrounded(kartForward, &toLinkPos));
        angleDegrees = ((s64) angle * 0x394bb834c8LL + 0x80000000LL) >> 32;
        if (Vec3DotUnrounded(&crossProduct, planeNormal) < 0) {
            angleDegrees *= -1;
        }
        kartAi->mTurnAngleDegrees = GetAbsoluteValue(angleDegrees);
    }
    isLinkReached = IsPastPointLink(linkCursor, kartPos);
    if (isLinkReached == 0 && (kart->mDriveFlags & KART_DRIVE_BOOST_SURFACE_HELD) == 0) {
        isLinkReached = IsWithinPointLinkDistance(linkCursor, kartPos);
    }
    if (isLinkReached == 0) {
        return;
    }
    PickKartAiDriftAtLink(kartAi);
    gAdvanceKartAiPointLinkCursor(linkCursor);
    gSetKartAiLinkPos(kartAi, linkCursor, kart);
    linkCursor->mRequestedLink = NULL;
    linkCursor->mRequestedLinkFound = FALSE;
}

void SetKartAiLinkPosAndAddSideOffset(KartAi *kartAi, PointLinkCursor *linkCursor, Kart *kart) {
    kartAi->mLinkPosWithSideOffset = *linkCursor->mLink->mPoint;
    if (kart->mDriveFlags & KART_DRIVE_BOOST_SURFACE_HELD) {
        return;
    }
    if (GetRaceUpdateFrames() > 0xb4) {
        if (kartAi->mDriftState == KART_AI_DRIFT_HOLDING) {
            kartAi->mSideOffset = gKartAiZeroSideOffset;
            kartAi->mSideOffsetRatio = 0;
        } else {
            AdvanceKartAiSideOffset(kartAi);
        }
    }
    VEC_Add(&kartAi->mLinkPosWithSideOffset, &kartAi->mSideOffset, &kartAi->mLinkPosWithSideOffset);
}

void SetKartAiLinkPosAndClearSideOffset(KartAi *kartAi, PointLinkCursor *linkCursor, Kart *kart) {
    kartAi->mLinkPosWithSideOffset = *linkCursor->mLink->mPoint;
    kartAi->mSideOffset = gKartAiZeroSideOffset;
    kartAi->mSideOffsetRatio = 0;
}

BOOL IsKartTargetable(s32 kartIndex) {
    return IsKartFlagMaskClear(kartIndex);
}

s32 ShouldKartAiTargetKart(u32 kartIndex, u32 targetIndex) {
    BOOL result = FALSE;
    s32 playerKind;
    BOOL isHumanGhostOrPeer;

    if (gRaceSetup->mUseTeams == 0 ||
        gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex != KartAiGetCurrentTeamIndex(targetIndex)) {
        isHumanGhostOrPeer = FALSE;
        playerKind = gRaceSetup->mCurrentEntries[targetIndex].mPlayer.mKind;
        if ((u32) playerKind <= 3) {
            if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                isHumanGhostOrPeer = TRUE;
            }
        }
        if (isHumanGhostOrPeer != FALSE || GetNonCpuKartCountOutsideKartTeam(kartIndex) <= 0) {
            if ((GetKart(targetIndex)->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) == 0) {
                result = TRUE;
            }
        }
    }
    return result;
}

void PickKartAiTargetKart(KartAi *kartAi) {
    u32 value;
    BOOL foundAhead;
    s32 behindKartIndex;
    s32 aheadKartIndex;
    u32 ownKartIndex;

    kartAi->mTargetKart = NULL;
    kartAi->mTargetAhead = 0;
    ownKartIndex = kartAi->mIndex;
    value = ownKartIndex;
    if (value != GetRaceUpdateFramesMod8()) {
        return;
    }
    if (gRaceSetup->mCpuDifficulty != CPU_DIFFICULTY_HARD) {
        return;
    }
    value = GetKartRank(value);
    if (value <= 1) {
        return;
    }
    aheadKartIndex = GetKartAtRank(value - 1);
    foundAhead = FALSE;
    if (aheadKartIndex >= 0) {
        aheadKartIndex = GetKartAtRank(value - 1);
        if (IsKartAiTargetAllowed(kartAi->mIndex, (u16) aheadKartIndex) != 0) {
            kartAi->mTargetKart = GetKart(aheadKartIndex);
            foundAhead = TRUE;
            kartAi->mTargetAhead = 1;
        }
    }
    if (foundAhead != FALSE) {
        return;
    }
    if (value >= gRaceSetup->mKartCount) {
        return;
    }
    behindKartIndex = GetKartAtRank(value + 1);
    if (behindKartIndex < 0) {
        return;
    }
    behindKartIndex = GetKartAtRank(value + 1);
    if (IsKartAiTargetAllowed(kartAi->mIndex, (u16) behindKartIndex) != 0) {
        kartAi->mTargetKart = GetKart(behindKartIndex);
    }
}

void PickKartAiDriftAtLink(KartAi *kartAi) {
    Vec3 linkPos;
    Vec3 sideAxis;
    Vec3 kartOffset;
    Vec3 linkPoint;
    Vec3 sideDirection;
    Vec3 kartOffsetFromLink;
    Vec3 unitY;
    Vec3 upVector;
    s32 linkValue = GetPointLinkFirstValue(&kartAi->mPointLinkCursor);
    BOOL conditionsMet;
    s32 sideRange;
    s32 sidewaysDistance;
    RandomState64 *kartAiRandom;
    s32 randomValue;

    if (kartAi->mDriftState == KART_AI_DRIFT_NONE && linkValue >= 1 && linkValue <= 4) {
        conditionsMet = FALSE;
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        if (randomValue <= kartAi->mDriftStartRandomLimit &&
            kartAi->mKart->mVelocityLength >= kartAi->mMinVelocityLength) {
            linkPos = *kartAi->mPointLinkCursor.mLink->mPoint;
            unitY = gPointLinkVec3UnitY;
            Vec3CrossUnrounded(&kartAi->mPointLinkCursor.mDirection, &unitY, &sideAxis);
            VEC_Subtract(&kartAi->mKart->mPos, &linkPos, &kartOffset);
            sidewaysDistance = Vec3DotUnrounded(&kartOffset, &sideAxis);
            sideRange = kartAi->mPointLinkCursor.mLink->mRadius;
            if (GetAbsoluteValue(sidewaysDistance) < sideRange) {
                conditionsMet = TRUE;
            }
        }
        if (conditionsMet != FALSE) {
            switch (linkValue) {
                case KART_AI_DRIFT_LINK_LEFT_ROLL:
                    kartAi->mDriftState = KART_AI_DRIFT_HOP_PENDING;
                    kartAi->mTurnSide = KART_AI_TURN_LEFT;
                    kartAi->mDriftFrames = 0;
                    kartAi->mDriftChargeRollAllowed = TRUE;
                    break;
                case KART_AI_DRIFT_LINK_LEFT_NO_ROLL:
                    kartAi->mDriftState = KART_AI_DRIFT_HOP_PENDING;
                    kartAi->mTurnSide = KART_AI_TURN_LEFT;
                    kartAi->mDriftFrames = 0;
                    kartAi->mDriftChargeRollAllowed = FALSE;
                    break;
                case KART_AI_DRIFT_LINK_RIGHT_ROLL:
                    kartAi->mDriftState = KART_AI_DRIFT_HOP_PENDING;
                    kartAi->mTurnSide = KART_AI_TURN_RIGHT;
                    kartAi->mDriftFrames = 0;
                    kartAi->mDriftChargeRollAllowed = TRUE;
                    break;
                case KART_AI_DRIFT_LINK_RIGHT_NO_ROLL:
                    kartAi->mDriftState = KART_AI_DRIFT_HOP_PENDING;
                    kartAi->mTurnSide = KART_AI_TURN_RIGHT;
                    kartAi->mDriftFrames = 0;
                    kartAi->mDriftChargeRollAllowed = FALSE;
                    break;
            }
        }
    }
    if (kartAi->mDriftState != KART_AI_DRIFT_HOLDING) {
        return;
    }
    if (linkValue != 5) {
        return;
    }
    kartAi->mDriftState = KART_AI_DRIFT_RELEASE_PENDING;
    linkPoint = *kartAi->mPointLinkCursor.mLink->mPoint;
    upVector = gPointLinkVec3UnitY;
    Vec3CrossUnrounded(&kartAi->mPointLinkCursor.mDirection, &upVector, &sideDirection);
    VEC_Subtract(&kartAi->mKart->mPos, &linkPoint, &kartOffsetFromLink);
    kartAi->mSideOffsetRatio = FX_Div(Vec3DotUnrounded(&kartOffsetFromLink, &sideDirection),
                                      kartAi->mPointLinkCursor.mLink->mRadius + TO_FIXED12(1));
    if (GetAbsoluteValue(kartAi->mSideOffsetRatio) > TO_FIXED12(1)) {
        if (kartAi->mSideOffsetRatio > 0) {
            kartAi->mSideOffsetRatio = TO_FIXED12(1);
        }
        kartAi->mSideOffsetRatio = -TO_FIXED12(1);
    }
    kartAi->mSideOffsetRatio = kartAi->mSideOffsetRatio >> 1;
}

void AdvanceKartAiDrift(KartAi *kartAi) {
    Vec3 offsetToLink;
    Vec3 flatOffsetToLink;
    Vec3 kartUp;
    Vec3 sideCross;
    Vec3 offsetOnUpPlane;
    Vec3 turnCross;
    Kart *kart;
    Kart *aiKart;
    Vec3 *kartForward;
    Vec3 *planeNormal;
    s32 dotProduct;
    s32 angle;
    BOOL chargeRollPassed;

    GetPointLinkFirstValue(&kartAi->mPointLinkCursor);
    kart = kartAi->mKart;
    if (kartAi->mDriftState == KART_AI_DRIFT_HOP_PENDING) {
        RequestBits(kart->mEntryIndex, PAD_KEY_R);
        kartAi->mDriftState = KART_AI_DRIFT_HOLDING;
    }
    if (kartAi->mDriftState == KART_AI_DRIFT_COUNTER_STEER) {
        if (kart->mMotionFlags & KART_MOTION_HOPPING) {
            if (kartAi->mTurnSide == KART_AI_TURN_LEFT) {
                kart->mDriveFlags &= ~KART_DRIVE_TURN_RIGHT;
                kart->mDriveFlags |= KART_DRIVE_TURN_LEFT;
            } else if (kartAi->mTurnSide == KART_AI_TURN_RIGHT) {
                kart->mDriveFlags &= ~KART_DRIVE_TURN_LEFT;
                kart->mDriveFlags |= KART_DRIVE_TURN_RIGHT;
            }
        } else {
            kartAi->mDriftState = KART_AI_DRIFT_NONE;
            kartAi->mTurnSide = KART_AI_TURN_NONE;
        }
    }
    if (kartAi->mDriftState == KART_AI_DRIFT_RELEASE_PENDING && (kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        planeNormal = &kart->mRotationRow1;
        kartForward = &kart->mRotationRow2;
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kart->mPos, &flatOffsetToLink);
        dotProduct = VEC_DotProduct(planeNormal, &flatOffsetToLink);
        flatOffsetToLink.x -= MUL_FIXED12_NO_ROUND(planeNormal->x, dotProduct);
        flatOffsetToLink.y -= MUL_FIXED12_NO_ROUND(planeNormal->y, dotProduct);
        flatOffsetToLink.z -= MUL_FIXED12_NO_ROUND(planeNormal->z, dotProduct);
        Vec3CrossUnrounded(kartForward, &flatOffsetToLink, &turnCross);
        angle = VEC_Mag(&turnCross);
        angle = FX_Atan2(angle, Vec3DotUnrounded(kartForward, &flatOffsetToLink));
        angle = ((s64) angle * 0x394bb834c8LL + 0x80000000LL) >> 32;
        dotProduct = Vec3DotUnrounded(&turnCross, planeNormal);
        if (dotProduct < 0) {
            dotProduct = -1;
            angle = angle * dotProduct;
        }
        kartAi->mTurnAngleDegrees = GetAbsoluteValue(angle);
        kartAi->mDriftState = KART_AI_DRIFT_NONE;
        kartAi->mTurnSide = KART_AI_TURN_NONE;
        kartAi->mDriftFrames = 0;
        kartAi->mDriftChargeRollAllowed = FALSE;
        EndKartDrift(kart);
        if (GetAbsoluteValue(kartAi->mTurnAngleDegrees) <= 0x32000) {
            return;
        }
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kart->mPos, &offsetToLink);
        kartAi->mDriftState = KART_AI_DRIFT_COUNTER_STEER;
        aiKart = kartAi->mKart;
        GetKartUp(aiKart, &kartUp);
        dotProduct = VEC_DotProduct(&kartUp, &offsetToLink);
        offsetOnUpPlane.x = offsetToLink.x - MUL_FIXED12_NO_ROUND(kartUp.x, dotProduct);
        offsetOnUpPlane.y = offsetToLink.y - MUL_FIXED12_NO_ROUND(kartUp.y, dotProduct);
        offsetOnUpPlane.z = offsetToLink.z - MUL_FIXED12_NO_ROUND(kartUp.z, dotProduct);
        Vec3CrossUnrounded(&aiKart->mRotationRow2, &offsetOnUpPlane, &sideCross);
        angle = Vec3DotUnrounded(&kartUp, &sideCross);
        if (angle > 0) {
            angle = 1;
        } else {
            angle = -1;
        }
        if (angle > 0) {
            kartAi->mTurnSide = KART_AI_TURN_LEFT;
        } else {
            kartAi->mTurnSide = KART_AI_TURN_RIGHT;
        }
        kart->mMotionFlags |= KART_MOTION_AI_DRIFT_REQUEST;
        return;
    }
    if (kartAi->mDriftState != KART_AI_DRIFT_HOLDING) {
        return;
    }
    if (kart->mMotionFlags & KART_MOTION_HOPPING) {
        if (kartAi->mTurnSide == KART_AI_TURN_LEFT) {
            kart->mDriveFlags &= ~KART_DRIVE_TURN_RIGHT;
            kart->mDriveFlags |= KART_DRIVE_TURN_LEFT;
        } else if (kartAi->mTurnSide == KART_AI_TURN_RIGHT) {
            kart->mDriveFlags &= ~KART_DRIVE_TURN_LEFT;
            kart->mDriveFlags |= KART_DRIVE_TURN_RIGHT;
        }
    }
    RequestBits(kart->mEntryIndex, PAD_KEY_R);
    kartAi->mDriftFrames++;
    chargeRollPassed = FALSE;
    if (kartAi->mDriftFrames == KART_AI_DRIFT_CHARGE_ROLL_FRAMES && kartAi->mDriftChargeRollAllowed != FALSE) {
        RandomState64 *kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        if ((s16) (u16) (kartAiRandom->mValue >> 52) <= kartAi->mDriftChargeRandomLimit) {
            chargeRollPassed = TRUE;
        }
    }
    if (chargeRollPassed != FALSE) {
        SetKartDriftCharge(kart, KART_DRIFT_CHARGE_LEVEL_3);
    }
    kartAi->mSideOffset = gKartAiZeroSideOffset;
    kartAi->mSideOffsetRatio = 0;
    if (!(kart->mMotionFlags & (KART_MOTION_OBJECT_CONTACT | KART_MOTION_COURSE_CONTACT | KART_MOTION_MOVED_BY_OBJECT |
                                KART_MOTION_NEAR_KART_HELD))) {
        dotProduct = kart->mVelocityLength;
        if (dotProduct > MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mBaseSpeedLimit, 0x8cd)) {
            return;
        }
    }
    kartAi->mDriftState = KART_AI_DRIFT_NONE;
    kartAi->mTurnSide = KART_AI_TURN_NONE;
    kartAi->mDriftFrames = 0;
    kartAi->mDriftChargeRollAllowed = FALSE;
}

s32 ComputeAngleToPositionDegrees(Vec3 *targetPos, Vec3 *originPos, Vec3 *planeNormal, Vec3 *forward) {
    Vec3 flatOffset;
    Vec3 crossProduct;
    s32 dotProduct;
    s32 crossLength;
    s32 angleDegrees;

    VEC_Subtract(targetPos, originPos, &flatOffset);
    dotProduct = VEC_DotProduct(planeNormal, &flatOffset);
    flatOffset.x -= MUL_FIXED12_NO_ROUND(planeNormal->x, dotProduct);
    flatOffset.y -= MUL_FIXED12_NO_ROUND(planeNormal->y, dotProduct);
    flatOffset.z -= MUL_FIXED12_NO_ROUND(planeNormal->z, dotProduct);
    Vec3CrossUnrounded(forward, &flatOffset, &crossProduct);
    crossLength = VEC_Mag(&crossProduct);
    angleDegrees = FX_Atan2(crossLength, Vec3DotUnrounded(forward, &flatOffset));
    angleDegrees = ((s64) angleDegrees * 0x394bb834c8LL + 0x80000000LL) >> 32;
    dotProduct = Vec3DotUnrounded(&crossProduct, planeNormal);
    if (dotProduct < 0) {
        dotProduct = -1;
        angleDegrees = angleDegrees * dotProduct;
    }
    return angleDegrees;
}

void AdvanceKartAiSideOffset(KartAi *kartAi) {
    Vec3 unitY = gPointLinkVec3UnitY;
    s32 sideDistance;

    Vec3CrossUnrounded(&kartAi->mPointLinkCursor.mDirection, &unitY, &kartAi->mSideOffset);
    kartAi->mSideOffsetFrames++;
    if (kartAi->mSideOffsetFrames > kartAi->mSideOffsetFrameLimit) {
        RandomState64 *kartAiRandom;
        s32 randomValue;
        s32 newSideOffsetRatio;

        kartAi->mSideOffsetFrames = 0;
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        kartAi->mSideOffsetFrameLimit = 0;
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        newSideOffsetRatio =
            kartAi->mSideOffsetRatio + MUL_FIXED12_NO_ROUND(MUL_FIXED12_NO_ROUND(randomValue, 0x2000) - 0x1000, 0x267);
        if (GetAbsoluteValue(newSideOffsetRatio) > 0xb36) {
            if (newSideOffsetRatio > 0) {
                newSideOffsetRatio = 0xb36;
            } else {
                newSideOffsetRatio = -0xb36;
            }
        }
        kartAi->mSideOffsetRatio = newSideOffsetRatio;
    }
    sideDistance = MUL_FIXED12_NO_ROUND(kartAi->mSideOffsetRatio, kartAi->mPointLinkCursor.mLink->mRadius);
    kartAi->mSideOffset.x = MUL_FIXED12_NO_ROUND(kartAi->mSideOffset.x, sideDistance);
    kartAi->mSideOffset.y = MUL_FIXED12_NO_ROUND(kartAi->mSideOffset.y, sideDistance);
    kartAi->mSideOffset.z = MUL_FIXED12_NO_ROUND(kartAi->mSideOffset.z, sideDistance);
}

void SetKartAiSideOffsetFromKart(KartAi *kartAi) {
    Vec3 linkPos;
    Vec3 upVector;
    Vec3 linkPosCopy;
    Vec3 sideAxis;
    Vec3 kartOffset;
    Vec3 unitYCopy;
    Vec3 unitY;
    s32 scale;

    linkPos = *kartAi->mPointLinkCursor.mLink->mPoint;
    linkPosCopy = *kartAi->mPointLinkCursor.mLink->mPoint;
    unitY = gPointLinkVec3UnitY;
    unitYCopy = *(Vec3 *) &gPointLinkVec3UnitY;
    Vec3CrossUnrounded(&kartAi->mPointLinkCursor.mDirection, &unitYCopy, &sideAxis);
    VEC_Subtract(&kartAi->mKart->mPos, &linkPosCopy, &kartOffset);
    scale = Vec3DotUnrounded(&kartOffset, &sideAxis);
    kartAi->mSideOffsetRatio = FX_Div(scale, kartAi->mPointLinkCursor.mLink->mRadius + TO_FIXED12(1));
    if (GetAbsoluteValue(kartAi->mSideOffsetRatio) > TO_FIXED12(1)) {
        if (kartAi->mSideOffsetRatio > 0) {
            kartAi->mSideOffsetRatio = TO_FIXED12(1);
        }
        kartAi->mSideOffsetRatio = -TO_FIXED12(1);
    }
    upVector = unitY;
    Vec3CrossUnrounded(&kartAi->mPointLinkCursor.mDirection, &upVector, &kartAi->mSideOffset);
    scale = MUL_FIXED12_NO_ROUND(kartAi->mSideOffsetRatio, kartAi->mPointLinkCursor.mLink->mRadius);
    kartAi->mSideOffset.x = MUL_FIXED12_NO_ROUND(kartAi->mSideOffset.x, scale);
    kartAi->mSideOffset.y = MUL_FIXED12_NO_ROUND(kartAi->mSideOffset.y, scale);
    kartAi->mSideOffset.z = MUL_FIXED12_NO_ROUND(kartAi->mSideOffset.z, scale);
    VEC_Add(&linkPos, &kartAi->mSideOffset, &kartAi->mLinkPosWithSideOffset);
}

void AdvanceKartAiContactStages(KartAi *kartAi) {
    BOOL limitReached = FALSE;
    BOOL timerActive = FALSE;
    Kart *kart;

    kartAi->mContactTimer--;
    if (kartAi->mContactTimer <= 0) {
        kartAi->mContactTimer = 0;
    } else {
        timerActive = TRUE;
    }
    kart = kartAi->mKart;
    {
        BOOL isTriggered;
        if ((kart->mMotionFlags & (KART_MOTION_OBJECT_CONTACT | KART_MOTION_COURSE_CONTACT)) &&
            kart->mVelocityLength < KART_AI_CONTACT_MAX_SPEED) {
            isTriggered = TRUE;
        } else {
            isTriggered = FALSE;
        }
        if (isTriggered != FALSE) {
            kartAi->mContactTimer = KART_AI_CONTACT_TIMER_FRAMES;
            timerActive = TRUE;
        }
    }
    if (timerActive != FALSE) {
        kartAi->mContactStageFrames++;
        if (kartAi->mContactStageFrames >= kartAi->mContactStageFrameLimit) {
            kartAi->mContactStageFrames = 0;
            limitReached = TRUE;
        }
    } else if (kartAi->mContactTimer <= 0) {
        kartAi->mContactStageFrames = 0;
        kartAi->mContactStage = KART_AI_CONTACT_NONE;
        kartAi->mContactStageFrameLimit = KART_AI_CONTACT_FRAMES_NONE;
    }
    if (limitReached == FALSE) {
        return;
    }
    switch (kartAi->mContactStage) {
        case KART_AI_CONTACT_NONE:
            kartAi->mContactStage = KART_AI_CONTACT_STEER_FLAT;
            kartAi->mContactStageFrameLimit = KART_AI_CONTACT_FRAMES_STEER_FLAT;
            break;
        case KART_AI_CONTACT_STEER_FLAT:
            if (gRaceSetup->mMode == MODE_BATTLE) {
                kartAi->mContactStage = KART_AI_CONTACT_REQUEST_LINK;
                CallKartAiRequestLink(kartAi->mKart->mAi);
                kartAi->mContactStageFrameLimit = KART_AI_CONTACT_FRAMES_REQUEST_LINK;
            } else {
                kartAi->mContactStage = KART_AI_CONTACT_SLOW;
                kartAi->mContactStageFrameLimit = KART_AI_CONTACT_FRAMES_SLOW;
                SetRequestedLinkToPreviousIfNone(&kartAi->mPointLinkCursor);
            }
            break;
        case KART_AI_CONTACT_SLOW:
            kartAi->mContactStage = KART_AI_CONTACT_REQUEST_LINK;
            CallKartAiRequestLink(kartAi->mKart->mAi);
            kartAi->mContactStageFrameLimit = KART_AI_CONTACT_FRAMES_REQUEST_LINK;
            break;
        case KART_AI_CONTACT_REQUEST_LINK:
            kartAi->mContactStage = KART_AI_CONTACT_KART_CALLED;
            KartAiRespawnKartAndToggleEventFlag(kartAi->mKart);
            break;
    }
}

BOOL IsTargetKartSet(KartAi *kartAi) {
    return kartAi->mTargetKart != NULL;
}

u32 GetTargetAhead(struct KartAi *kartAi) {
    return kartAi->mTargetAhead;
}

void SetupAwardMissionRunKartAi(struct KartAi *kartAi, struct Kart *kart, s32 unusedValue) {
    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->mIndexModFour = kartAi->mIndex % 4;
    kartAi->mDriftStartRandomLimit = TO_FIXED12(1);
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        kartAi->mDriftChargeRandomLimit = 0;
    } else {
        kartAi->mDriftChargeRandomLimit = TO_FIXED12(1);
    }
    kartAi->mMinVelocityLength = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, 0x99a);
    InitRacePointLinkCursor(&kartAi->mPointLinkCursor, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAi->mHeadingSwingSign = 1;
}

void ResetAwardMissionRunKartAi(struct KartAi *kartAi, struct RacePointLink *pointLink) {
    ResetPointLinkCursor(&kartAi->mPointLinkCursor, pointLink);
    ResetKartAi(kartAi, 1);
    ResetKartAi(kartAi, 1);
}

void AdvanceAwardMissionRunKartAi(struct KartAi *kartAi) {
    Vec3 kartPos;
    Vec3 toLinkPos;
    PointLinkCursor *linkCursor;
    Kart *kart;
    Vec3 *kartForward;
    RacePointLink *requestedLink;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AdvanceKartAiContactStages(kartAi);
    }
    linkCursor = &kartAi->mPointLinkCursor;
    kart = kartAi->mKart;
    if (kartAi->mDriftState == KART_AI_DRIFT_HOLDING) {
        kartForward = &kart->mTurnedForward;
    } else {
        kartForward = &kart->mRotationRow2;
    }
    requestedLink = linkCursor->mRequestedLink;
    GetKartPos(&kartPos, kartAi->mIndex);
    AdvanceKartAiAlongLinks(kartAi, linkCursor, kart, requestedLink, &kartPos, kartForward);
    if (kart->mState == KART_STATE_NORMAL) {
        RequestBits(kartAi->mKart->mEntryIndex, PAD_KEY_A);
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kartPos, &toLinkPos);
        AdvanceKartAiHeading(kartAi, &toLinkPos, kartForward);
    }
    AdvanceKartAiDrift(kartAi);
}

void SetupStaffRollKartAi(struct KartAi *kartAi, struct Kart *kart, s32 unusedValue) {
    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->mIndexModFour = kartAi->mIndex % 4;
    kartAi->mDriftStartRandomLimit = TO_FIXED12(1);
    kartAi->mDriftChargeRandomLimit = 0;
    kartAi->mMinVelocityLength = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, 0x99a);
    InitRacePointLinkCursor(&kartAi->mPointLinkCursor, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAi->mHeadingSwingSign = 1;
}

void AdvanceStaffRollKartAi(struct KartAi *kartAi) {
    Vec3 kartPos;
    Vec3 toLinkPos;
    PointLinkCursor *linkCursor = &kartAi->mPointLinkCursor;
    Kart *kart = kartAi->mKart;
    Vec3 *kartForward;
    RacePointLink *requestedLink;

    if (kartAi->mDriftState == KART_AI_DRIFT_HOLDING) {
        kartForward = &kart->mTurnedForward;
    } else {
        kartForward = &kart->mRotationRow2;
    }
    requestedLink = linkCursor->mRequestedLink;
    GetKartPos(&kartPos, kartAi->mIndex);
    AdvanceKartAiAlongLinks(kartAi, linkCursor, kart, requestedLink, &kartPos, kartForward);
    if (kart->mState == KART_STATE_NORMAL) {
        RequestBits(kartAi->mKart->mEntryIndex, PAD_KEY_A);
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kartPos, &toLinkPos);
        AdvanceKartAiHeading(kartAi, &toLinkPos, kartForward);
    }
    AdvanceKartAiDrift(kartAi);
}

void InitKartAiTables(void) {
    s32 cpuAndGhostKartCount;

    switch (GetKartAiEngineOrDifficultyIndex()) {
        case KART_AI_LEVEL_LOW:
            gKartAiRaceStartBoostRandomLimits = gKartAiRaceStartBoostRandomLimitsIndex0;
            gKartAiRaceStartHeadingSwingRandomLimits = gKartAiRaceStartHeadingSwingRandomLimitsIndex0;
            break;
        case KART_AI_LEVEL_MEDIUM:
            gKartAiRaceStartBoostRandomLimits = gKartAiRaceStartBoostRandomLimitsIndex1;
            gKartAiRaceStartHeadingSwingRandomLimits = gKartAiRaceStartHeadingSwingRandomLimitsIndex1;
            break;
        case KART_AI_LEVEL_HIGH:
        default:
            gKartAiRaceStartBoostRandomLimits = gKartAiRaceStartBoostRandomLimitsIndex2;
            gKartAiRaceStartHeadingSwingRandomLimits = gKartAiRaceStartHeadingSwingRandomLimitsIndex2;
            break;
    }
    gKartAiRankOffset = 3;
    cpuAndGhostKartCount = gRaceSetup->mKartCount - gRaceSetup->mHumanAndPeerKartCount;
    if (cpuAndGhostKartCount > 1) {
        if (cpuAndGhostKartCount <= 3) {
            gKartAiRankOffset = cpuAndGhostKartCount - 1;
        }
    }
    gKartAiGapLimitsByRank = gKartAiGapLimitTables[cpuAndGhostKartCount];
}

u32 SetupRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    raceSpeedLimit->mBaseSpeedLimit = kartAi->mKart->mPhysicalParam->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimitBeforeTurn = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mTableIndex = GetKartAiTableIndex(kartAi->mIndex);
    raceSpeedLimit->mTableIndexOrRank = raceSpeedLimit->mTableIndex;
    raceSpeedLimit->mProgressGapLimit = 0;
    raceSpeedLimit->mSpeedLimit = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimitAddition = 0;
    raceSpeedLimit->mTurnSpeedLimit = 0;
    raceSpeedLimit->mSpeedLimitBeforeTurn = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mRank = -1;
    raceSpeedLimit->mSpeedLimitReduced = 0;
    return -1;
}

void ResetRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    raceSpeedLimit->mSpeedLimit = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimitAddition = 0x0u;
    raceSpeedLimit->mTurnSpeedLimit = 0x0u;
    raceSpeedLimit->mSpeedLimitBeforeTurn = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mRank = -1;
    raceSpeedLimit->mSpeedLimitReduced = 0x0u;
}

// Rolls the race start of a CPU kart: a race start boost with its choice, or the flag in mUnk_28.
void PickKartAiRaceStart(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    BOOL isHumanGhostOrPeer = FALSE;
    u32 playerKind;
    BOOL boostChosen;
    s32 tableIndex;
    s32 randomValue;
    s32 randomLimit;
    RandomState64 *kartAiRandom;
    KartAi *kartAiOfKart;

    playerKind = gRaceSetup->mCurrentEntries[kartAi->mIndex].mPlayer.mKind;
    if (playerKind <= 3) {
        if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
    }
    if (isHumanGhostOrPeer != FALSE) {
        return;
    }
    boostChosen = FALSE;
    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
    tableIndex = GetKartAiTableIndex(kartAi->mIndex);
    kartAiOfKart = GetKart(kartAi->mIndex)->mAi;
    if (kartAiOfKart->mListedCpu != 0) {
        tableIndex = boostChosen;
    }
    randomLimit = gKartAiRaceStartBoostRandomLimits[tableIndex];
    if (randomValue < randomLimit || randomLimit >= 0x1000) {
        raceSpeedLimit->mBoostsAtRaceStart = 1;
        raceSpeedLimit->mRaceStartBoostChoice = PickKartAiRaceStartBoost(kartAiOfKart->mListedCpu);
        boostChosen = TRUE;
    }
    if (boostChosen != FALSE) {
        return;
    }
    randomLimit = gKartAiRaceStartHeadingSwingRandomLimits[tableIndex];
    if (randomValue >= randomLimit) {
        if (!(randomLimit >= 1.0f)) {
            return;
        }
    }
    raceSpeedLimit->mHeadingSwingAtRaceStart = 1;
}

// Every eighth frame, on this kart's turn, recomputes the CPU speed limit; every call sets the kart's limit from it.
void AdvanceRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    BOOL isHumanGhostOrPeer;
    u32 playerKind;
    s32 speedLimit;
    s32 turnExcessRatio;
    Kart *kart;

    if (kartAi->mIndex == GetRaceUpdateFramesMod8()) {
        raceSpeedLimit->mSpeedLimitAddition = 0;
        raceSpeedLimit->mSpeedLimitReduced = 0;
        isHumanGhostOrPeer = FALSE;
        playerKind = gRaceSetup->mCurrentEntries[kartAi->mIndex].mPlayer.mKind;
        if (playerKind <= 3) {
            if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                isHumanGhostOrPeer = TRUE;
            }
        }
        if (isHumanGhostOrPeer != FALSE) {
            raceSpeedLimit->mRank = GetKartRank(kartAi->mIndex);
        } else {
            raceSpeedLimit->mRank = GetKartRankAmongCpuKarts(kartAi->mIndex);
        }
        raceSpeedLimit->mSpeedLimitAddition = GetKartAiParamRow()->mSpeedLimitAddition;
        if (IsOneKartNotHumanOrPeer() != 0) {
            raceSpeedLimit->mSpeedLimitAddition = raceSpeedLimit->mSpeedLimitAddition >> 1;
        }
        kart = kartAi->mKart;
        speedLimit = raceSpeedLimit->mSpeedLimitAddition + kart->mSpeedLimitGoal;
        if (kartAi->mContactStage == KART_AI_CONTACT_SLOW) {
            speedLimit = 0x3000;
        }
        if (speedLimit > 0xa000) {
            speedLimit = 0xa000;
        }
        if (kart->mEffectFlags & KART_EFFECT_GESSO) {
            speedLimit = MUL_FIXED12_ROUNDED(speedLimit, 0xb33);
        }
        if (kartAi->mDriftState == KART_AI_DRIFT_NONE) {
            raceSpeedLimit->mTurnSpeedLimit = speedLimit;
            if (kartAi->mTurnAngleDegrees > KART_AI_TURN_SLOWDOWN_START_ANGLE) {
                turnExcessRatio =
                    MUL_FIXED12_NO_ROUND(kartAi->mTurnAngleDegrees - KART_AI_TURN_SLOWDOWN_START_ANGLE, 0x5b);
                if (turnExcessRatio > 0x1000) {
                    turnExcessRatio = 0x1000;
                }
                raceSpeedLimit->mTurnSpeedLimit =
                    MUL_FIXED12_NO_ROUND(0x1000 - MUL_FIXED12_NO_ROUND(turnExcessRatio, 0x668), 0xa000);
            }
            AdvanceKartAiSpeedLimitByRank(raceSpeedLimit, kartAi, speedLimit);
            speedLimit = raceSpeedLimit->mSpeedLimitBeforeTurn;
        }
        if (raceSpeedLimit->mTurnSpeedLimit < speedLimit) {
            speedLimit = raceSpeedLimit->mTurnSpeedLimit;
        }
        if (speedLimit > 0xa000) {
            speedLimit = 0xa000;
        }
        raceSpeedLimit->mSpeedLimit = speedLimit;
    }
    kart = kartAi->mKart;
    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    if (kart->mEffectFlags & KART_EFFECT_KILLER) {
        return;
    }
    if ((kart->mDriveFlags & (KART_DRIVE_BOOST | KART_DRIVE_JUMP_PAD)) == 0) {
        kart->mSpeedLimitGoal = raceSpeedLimit->mSpeedLimit;
    }
}

void AdvanceKartAiSpeedLimitByRank(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi,
                                   s32 speedLimitCap) {
    s32 rank = raceSpeedLimit->mRank;
    u16 kartIndex = kartAi->mIndex;
    u16 rankIndex;
    BOOL isHumanGhostOrPeer;
    s32 value;
    s32 otherKartIndex;
    s32 *tableIndices = &raceSpeedLimit->mTableIndex;
    KartAiParamRow *kartAiParamRow = GetKartAiParamRow();
    s32 gap;
    s32 progress;
    const s32 *limitTable;

    raceSpeedLimit->mSpeedLimitReduced = 0;
    isHumanGhostOrPeer = FALSE;
    value = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
    if ((u32) value <= 3) {
        if ((1 << value) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
    }
    if (isHumanGhostOrPeer != FALSE) {
        return;
    }
    if (tableIndices[0] > 2) {
        if (rank > 2) {
            tableIndices[1] = rank;
        }
    }
    if (tableIndices[0] == 1) {
        if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
            if (GetKartRaceProgressScaled(kartIndex) >= 0x28f) {
                if (GetKartRank(kartIndex) >= 4) {
                    for (rankIndex = 1; rankIndex < 4; rankIndex++) {
                        otherKartIndex = GetKartIndexAtRank(rankIndex);
                        if (otherKartIndex >= 0) {
                            KartAi *otherKartAi = GetKart(otherKartIndex)->mAi;
                            KartAiRaceSpeedLimit *otherRaceSpeedLimit = &otherKartAi->mRaceSpeedLimit;

                            if (otherKartAi->mListedCpu != 0) {
                                if (otherRaceSpeedLimit->mTableIndex == 2) {
                                    tableIndices[0] = 2;
                                    tableIndices[1] = tableIndices[0];
                                    otherRaceSpeedLimit->mTableIndexOrRank = 1;
                                    otherRaceSpeedLimit->mTableIndex = otherRaceSpeedLimit->mTableIndexOrRank;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    gap = tableIndices[1];
    if (IsKartEnded(kartIndex) != 0) {
        limitTable = gKartAiEndedGapLimits;
    } else {
        limitTable = gKartAiGapLimitsByRank;
    }
    value = limitTable[rank - 1];
    tableIndices[2] = MUL_FIXED12_NO_ROUND(value, kartAiParamRow->mGapTableScale);
    if (IsOneKartNotHumanOrPeer() != 0) {
        rank = kartAiParamRow->mGapTableScale;
        otherKartIndex = GetKartAtNonCpuRank();
        if (otherKartIndex >= 0) {
            gap = GetKartRaceProgressScaled(kartAi->mIndex);
            gap -= GetKartRaceProgressScaled(otherKartIndex);
            if (IsKartEnded(kartAi->mIndex) != 0) {
                limitTable = gKartAiEndedGapLimits;
            } else {
                limitTable = gKartAiGapLimitsByRank;
            }
            value = limitTable[GetKartRank((s32) (u16) otherKartIndex)];
            if (gap > MUL_FIXED12_NO_ROUND(value, rank)) {
                raceSpeedLimit->mSpeedLimitBeforeTurn =
                    MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xf85);
                raceSpeedLimit->mSpeedLimitReduced = 1;
            }
        }
    } else if (rank < gap) {
        raceSpeedLimit->mSpeedLimitBeforeTurn = MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xe66);
        raceSpeedLimit->mSpeedLimitReduced = 1;
    } else if (rank == gap) {
        if (rank == 1) {
            otherKartIndex = GetCpuKartByRankPlusOffset((u16) rank, gKartAiRankOffset);
            if (otherKartIndex >= 0) {
                progress = GetKartRaceProgressScaled(kartIndex);
                progress -= GetKartRaceProgressScaled(otherKartIndex);
                if (progress > GetKart(otherKartIndex)->mAi->mRaceSpeedLimit.mProgressGapLimit) {
                    raceSpeedLimit->mSpeedLimitBeforeTurn =
                        MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xf85);
                    raceSpeedLimit->mSpeedLimitReduced = 1;
                }
            }
        } else {
            progress = GetKartRaceProgressScaled(kartIndex);
            otherKartIndex = GetFirstCpuKartByRank();
            if (otherKartIndex >= 0) {
                gap = GetKartRaceProgressScaled(otherKartIndex) - progress;
                gap -= MUL_FIXED12_NO_ROUND(tableIndices[2], GetFirstRankProgressRatio());
                if (gap > 0) {
                    raceSpeedLimit->mSpeedLimitBeforeTurn =
                        raceSpeedLimit->mSpeedLimitBeforeTurn + MUL_FIXED12_NO_ROUND(gap, 0x3000);
                } else {
                    otherKartIndex = GetCpuKartAheadOfRank(rank);
                    if (otherKartIndex >= 0) {
                        Kart *otherKart = GetKart(otherKartIndex);
                        s32 rowValue = kartAiParamRow->mSpeedLimitFloor;

                        if (otherKart->mAi->mRaceSpeedLimit.mSpeedLimit > MUL_FIXED12_NO_ROUND(rowValue, 0xcd0)) {
                            gap = GetKartRaceProgressScaled(otherKartIndex) - progress;
                            if (gap < MUL_FIXED12_NO_ROUND(tableIndices[2], GetFirstRankProgressRatio())) {
                                raceSpeedLimit->mSpeedLimitBeforeTurn =
                                    MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xfae);
                                raceSpeedLimit->mSpeedLimitReduced = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (raceSpeedLimit->mSpeedLimitReduced == 0) {
        raceSpeedLimit->mSpeedLimitBeforeTurn = MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0x10cd);
        if (raceSpeedLimit->mSpeedLimitBeforeTurn >= speedLimitCap) {
            raceSpeedLimit->mSpeedLimitBeforeTurn = speedLimitCap;
        }
    } else {
        if (raceSpeedLimit->mSpeedLimitBeforeTurn < kartAiParamRow->mSpeedLimitFloor) {
            raceSpeedLimit->mSpeedLimitBeforeTurn = kartAiParamRow->mSpeedLimitFloor;
        }
    }
}

// Returns the race start boost choice (1 to 5) of a CPU kart: three candidates by difficulty, picked at random, or the
// last one when a is non-zero.
u16 PickKartAiRaceStartBoost(s32 pickLast) {
    u16 choices[9];
    u16 *difficultyChoices;
    s32 choiceIndex;
    RandomState64 *kartAiRandom;

    choices[0] = gKartAiRaceStartBoostEasyChoices[0];
    choices[1] = gKartAiRaceStartBoostEasyChoices[1];
    choices[2] = gKartAiRaceStartBoostEasyChoices[2];
    choices[3] = gKartAiRaceStartBoostNormalChoices[0];
    choices[4] = gKartAiRaceStartBoostNormalChoices[1];
    choices[5] = gKartAiRaceStartBoostNormalChoices[2];
    choices[6] = gKartAiRaceStartBoostHardChoices[0];
    choices[7] = gKartAiRaceStartBoostHardChoices[1];
    choices[8] = gKartAiRaceStartBoostHardChoices[2];
    difficultyChoices = &choices[6];
    if (pickLast != 0) {
        choiceIndex = 2;
    } else {
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        choiceIndex = (u16) (((kartAiRandom->mValue >> 32) * 3) >> 32);
    }
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            difficultyChoices = &choices[0];
            break;
        case CPU_DIFFICULTY_NORMAL:
            difficultyChoices = &choices[3];
            break;
    }
    return difficultyChoices[choiceIndex];
}

void InitKartAiRaceSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    s32 speedRatio;

    raceSpeedLimit->mBaseSpeedLimit = kartAi->mKart->mPhysicalParam->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimit = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimitAddition = 0;
    raceSpeedLimit->mTurnSpeedLimit = 0;
    raceSpeedLimit->mSpeedLimitBeforeTurn = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mRank = -1;
    raceSpeedLimit->mSpeedLimitReduced = 0;
    raceSpeedLimit->mSpeedLimitBeforeTurn = 0;
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        kartAi->mKart->mForwardSpeed = raceSpeedLimit->mBaseSpeedLimit;
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        speedRatio = GetPointLinkSpeedRatio(&kartAi->mPointLinkCursor);
        kartAi->mKart->mForwardSpeed = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, speedRatio);
        kartAi->mKart->mSpeedLimitGoal = kartAi->mKart->mForwardSpeed;
        kartAi->mKart->mSpeedLimit = kartAi->mKart->mSpeedLimitGoal;
        return;
    }
    PickKartAiRaceStart(raceSpeedLimit, kartAi);
}

void ResetAwardMissionRunKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    raceSpeedLimit->mSpeedLimit = (u32) (((u32) raceSpeedLimit->mBaseSpeedLimit));
    raceSpeedLimit->mSpeedLimitAddition = 0x0u;
    raceSpeedLimit->mTurnSpeedLimit = 0x0u;
    raceSpeedLimit->mSpeedLimitBeforeTurn = (u32) (((u32) raceSpeedLimit->mBaseSpeedLimit));
    raceSpeedLimit->mRank = (u32) ((~(0x0u)));
    raceSpeedLimit->mSpeedLimitReduced = 0x0u;
    raceSpeedLimit->mSpeedLimitBeforeTurn = 0x0u;
}

void AdvanceKartAiTurnSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    s32 turnSpeedLimit;
    s32 turnAngle;
    s32 limit;
    s32 ratio;

    if (GetRaceUpdateFramesMod8() == kartAi->mIndex) {
        raceSpeedLimit->mSpeedLimitAddition = 0;
        limit = kartAi->mKart->mSpeedLimitGoal;
        if (limit > 0xa000) {
            limit = 0xa000;
        }
        raceSpeedLimit->mTurnSpeedLimit = limit;
        turnAngle = kartAi->mTurnAngleDegrees;
        if (turnAngle > 0x5000) {
            ratio = MUL_FIXED12_NO_ROUND(turnAngle - 0x5000, 0x5b);
            if (ratio > 0x1000) {
                ratio = 0x1000;
            }
            ratio = MUL_FIXED12_NO_ROUND(ratio, 0x668);
            raceSpeedLimit->mTurnSpeedLimit = MUL_FIXED12_NO_ROUND(0x1000 - ratio, 0xa000);
        }
        turnSpeedLimit = raceSpeedLimit->mTurnSpeedLimit;
        if (turnSpeedLimit < limit) {
            limit = turnSpeedLimit;
        }
        if (limit > 0xa000) {
            limit = 0xa000;
        }
        raceSpeedLimit->mSpeedLimit = limit;
    }
    if (kartAi->mKart->mState != KART_STATE_NORMAL) {
        return;
    }
    if ((kartAi->mKart->mDriveFlags & (KART_DRIVE_BOOST | KART_DRIVE_JUMP_PAD)) != 0) {
        return;
    }
    ratio = GetPointLinkSpeedRatio(&kartAi->mPointLinkCursor);
    kartAi->mKart->mSpeedLimitGoal = MUL_FIXED12_ROUNDED(raceSpeedLimit->mSpeedLimit, ratio);
}

void TrailOrCircleUseItemAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

void UseItemAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}
void UseItemByTargetOrRankOrEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RaceSetup *raceSetup;
    u16 kartIndex;

    raceSetup = gRaceSetup;
    kartIndex = kartAi->mIndex;
    if ((raceSetup->mCurrentEntries[kartIndex].mPlayer.mListedCpuFlags & KART_ENTRY_LISTED_CPU_FLAG) != 0) {
        if (itemUse->mRandomValue <= FIXED12_RATIO(3, 4)) {
            itemUse->mItemBitsEveryCall = 1;
            return;
        }
    }
    UseItemByTargetOrRankAfterHeld(itemUse, kartAi);
}
void UseItemByRankOrEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RaceSetup *raceSetup;
    u16 kartIndex;

    raceSetup = gRaceSetup;
    kartIndex = kartAi->mIndex;
    if ((raceSetup->mCurrentEntries[kartIndex].mPlayer.mListedCpuFlags & KART_ENTRY_LISTED_CPU_FLAG) != 0) {
        if (itemUse->mRandomValue <= FIXED12_RATIO(1, 4)) {
            itemUse->mItemBitsEveryCall = 1;
            return;
        }
    }
    {
        BOOL timerRanOut;

        timerRanOut = FALSE;
        itemUse->mHeldItemTimer--;
        if (itemUse->mHeldItemTimer <= 0) {
            itemUse->mHeldItemTimer = 0;
            timerRanOut = TRUE;
        }
        if (timerRanOut == FALSE) {
            return;
        }
    }
    RequestItemBitsByKartRank(itemUse, kartAi);
}

void UseItemByTargetOrRankAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    UseItemByTargetOrRank(itemUse, kartAi);
}

void UseItemByRankAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    RequestItemBitsByKartRank(itemUse, kartAi);
}
void UseItemByTargetOrRank(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    if (IsTargetKartSet(kartAi) != FALSE) {
        if (GetTargetAhead(kartAi) != 0) {
            RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
            itemUse->mThrowForwardPending = 1;
            itemUse->mThrowForwardTimer = KART_AI_THROW_TIMER_FRAMES;
            itemUse->mItemBitsEveryCall = 0;
            if (itemUse->mItemInUseEntry == NULL) {
                return;
            }
            randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
            random = GetKartAiRandom();
            if (randomLimit == 0) {
                randomPart = 0;
            } else {
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
            }
            itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
            return;
        } else {
            RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
            itemUse->mThrowBehindPending = 1;
            itemUse->mThrowBehindTimer = KART_AI_THROW_TIMER_FRAMES;
            itemUse->mItemBitsEveryCall = 0;
            if (itemUse->mItemInUseEntry == NULL) {
                return;
            }
            randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
            random = GetKartAiRandom();
            if (randomLimit == 0) {
                randomPart = 0;
            } else {
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
            }
            itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
            return;
        }
    } else {
        RequestItemBitsByKartRank(itemUse, kartAi);
    }
}
// First place sends the bit 0x80, last place ITEM_THROW_FORWARD_BIT, the places between follow mThenBitKind.
void RequestItemBitsByKartRank(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    s32 rank;
    u16 randomLimit;
    u32 randomPart;

    rank = GetKartRank(kartAi->mIndex);
    if (rank == 1) {
        RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
        itemUse->mThrowBehindPending = 1;
        itemUse->mThrowBehindTimer = KART_AI_THROW_TIMER_FRAMES;
        itemUse->mItemBitsEveryCall = 0;
        if (itemUse->mItemInUseEntry == NULL) {
            return;
        }
        randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
        random = GetKartAiRandom();
        if (randomLimit == 0) {
            randomPart = 0;
        } else {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                            : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
        }
        itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
        return;
    } else if ((u32) rank >= 2 && rank <= gRaceSetup->mKartCount - 1) {
        switch (itemUse->mHeldItemEntry->mThenBitKind) {
            case KART_AI_THEN_BIT_NONE:
                RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
                itemUse->mItemBitsEveryCall = 0;
                if (itemUse->mItemInUseEntry == NULL) {
                    return;
                }
                randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
                random = GetKartAiRandom();
                if (randomLimit == 0) {
                    randomPart = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                    : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
                }
                itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
                return;
            case KART_AI_THEN_BIT_THROW_FORWARD:
                RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
                itemUse->mThrowForwardPending = 1;
                itemUse->mThrowForwardTimer = KART_AI_THROW_TIMER_FRAMES;
                itemUse->mItemBitsEveryCall = 0;
                if (itemUse->mItemInUseEntry == NULL) {
                    return;
                }
                randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
                random = GetKartAiRandom();
                if (randomLimit == 0) {
                    randomPart = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                    : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
                }
                itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
                return;
            case KART_AI_THEN_BIT_THROW_BEHIND:
                RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
                itemUse->mThrowBehindPending = 1;
                itemUse->mThrowBehindTimer = KART_AI_THROW_TIMER_FRAMES;
                itemUse->mItemBitsEveryCall = 0;
                if (itemUse->mItemInUseEntry == NULL) {
                    return;
                }
                randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
                random = GetKartAiRandom();
                if (randomLimit == 0) {
                    randomPart = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                    : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
                }
                itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
                return;
            default:
                return;
        }
    } else {
        RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
        itemUse->mThrowForwardPending = 1;
        itemUse->mThrowForwardTimer = KART_AI_THROW_TIMER_FRAMES;
        itemUse->mItemBitsEveryCall = 0;
        if (itemUse->mItemInUseEntry == NULL) {
            return;
        }
        randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
        random = GetKartAiRandom();
        if (randomLimit == 0) {
            randomPart = 0;
        } else {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                            : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
        }
        itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
        return;
    }
}

void UseItemAfterHeldIfTurnUnder20(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= KART_AI_ITEM_TURN_ANGLE_LIMIT_WIDE) {
        return;
    }
    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

void UseItemIfTurnUnder20ResetHeldTimer(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= KART_AI_ITEM_TURN_ANGLE_LIMIT_WIDE) {
        return;
    }
    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mHeldItemEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mHeldItemEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mHeldItemTimer = itemUse->mHeldItemEntry->mTimerBase + (u16) randomPart;
}

void RaceItemInUseNop(KartAiItemUse *itemUse, struct KartAi *kartAi) {}

void UseItemAfterInUseByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (gKartItems[kartAi->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_CIRCLE) {
        gUseItemWhenCircleKindCallback(itemUse, kartAi);
    } else {
        gUseItemWhenNotCircleKindCallback(itemUse, kartAi);
    }
}

void UseItemAfterInUseByTrailKind(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (gKartItems[kartAi->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_TRAIL) {
        gUseItemTrailKindCallback(itemUse, kartAi);
    } else {
        gUseItemNotTrailKindCallback(itemUse, kartAi);
    }
}

void UseItemByTargetOrRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;

    timerRanOut = FALSE;
    itemUse->mItemInUseTimer--;
    if (itemUse->mItemInUseTimer <= 0) {
        itemUse->mItemInUseTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    UseItemByTargetOrRank(itemUse, kartAi);
}

void UseItemByRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;

    timerRanOut = FALSE;
    itemUse->mItemInUseTimer--;
    if (itemUse->mItemInUseTimer <= 0) {
        itemUse->mItemInUseTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    RequestItemBitsByKartRank(itemUse, kartAi);
}

void UseItemByTargetOrRankAfterEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    KartItems *kartItems;
    s32 heldItemIndex;
    BOOL timerRanOut;

    kartItems = &gKartItems[kartAi->mIndex];
    heldItemIndex = kartItems->mHeldItem.mItemInfoIndex;
    if (itemUse->mItemBitsEveryCall != 0) {
        if (heldItemIndex != ITEM_INFO_NONE) {
            itemUse->mHeldItemSeen = 1;
        }
        if (itemUse->mHeldItemSeen == 0) {
            return;
        }
        timerRanOut = FALSE;
        itemUse->mItemInUseTimer--;
        if (itemUse->mItemInUseTimer <= 0) {
            itemUse->mItemInUseTimer = 0;
            timerRanOut = TRUE;
        }
        if (timerRanOut == FALSE) {
            return;
        }
        UseItemByTargetOrRank(itemUse, kartAi);
    } else {
        UseItemByTargetOrRank(itemUse, kartAi);
    }
}

void UseItemByRankAfterEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    KartItems *kartItems;
    s32 heldItemIndex;
    BOOL timerRanOut;

    kartItems = &gKartItems[kartAi->mIndex];
    heldItemIndex = kartItems->mHeldItem.mItemInfoIndex;
    if (itemUse->mItemBitsEveryCall != 0) {
        if (heldItemIndex != ITEM_INFO_NONE) {
            itemUse->mHeldItemSeen = 1;
        }
        if (itemUse->mHeldItemSeen == 0) {
            return;
        }
        timerRanOut = FALSE;
        itemUse->mItemInUseTimer--;
        if (itemUse->mItemInUseTimer <= 0) {
            itemUse->mItemInUseTimer = 0;
            timerRanOut = TRUE;
        }
        if (timerRanOut == FALSE) {
            return;
        }
        RequestItemBitsByKartRank(itemUse, kartAi);
    } else {
        RequestItemBitsByKartRank(itemUse, kartAi);
    }
}

void SetupRaceItemEntries(void) {
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            gCurrentHeldItemEntries = gRaceEasyHeldItemEntries;
            gCurrentItemInUseEntries = gRaceItemInUseEntries;
            gUseItemWhenCircleKindCallback = UseItemByRankAfterInUse;
            gUseItemWhenNotCircleKindCallback = UseItemByRankAfterEveryCall;
            gUseItemTrailKindCallback = UseItemByRankAfterInUse;
            gUseItemNotTrailKindCallback = UseItemByRankAfterEveryCall;
            break;
        case CPU_DIFFICULTY_NORMAL:
            gCurrentHeldItemEntries = gRaceNormalHeldItemEntries;
            gCurrentItemInUseEntries = gRaceItemInUseEntries;
            gUseItemWhenCircleKindCallback = UseItemByRankAfterInUse;
            gUseItemWhenNotCircleKindCallback = UseItemByRankAfterEveryCall;
            gUseItemTrailKindCallback = UseItemByRankAfterInUse;
            gUseItemNotTrailKindCallback = UseItemByRankAfterEveryCall;
            break;
        case CPU_DIFFICULTY_HARD:
        default:
            gCurrentHeldItemEntries = gRaceHardHeldItemEntries;
            gCurrentItemInUseEntries = gRaceItemInUseEntries;
            gUseItemWhenCircleKindCallback = UseItemByTargetOrRankAfterInUse;
            gUseItemWhenNotCircleKindCallback = UseItemByTargetOrRankAfterEveryCall;
            gUseItemTrailKindCallback = UseItemByTargetOrRankAfterInUse;
            gUseItemNotTrailKindCallback = UseItemByTargetOrRankAfterEveryCall;
            break;
    }
}

// Also stops the every-call request of the item bits.
void UseItemAndResetHeldTimer(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mHeldItemEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mHeldItemEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mHeldItemTimer = itemUse->mHeldItemEntry->mTimerBase + (u16) randomPart;
}

// Also stops the every-call request of the item bits.
void UseItemAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

// Also stops the every-call request of the item bits.
void UseItemForwardAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mThrowForwardPending = 1;
    itemUse->mThrowForwardTimer = KART_AI_THROW_TIMER_FRAMES;
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

// Also stops the every-call request of the item bits.
void UseItemBehindAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mThrowBehindPending = 1;
    itemUse->mThrowBehindTimer = KART_AI_THROW_TIMER_FRAMES;
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

void ClearKartAiItemUse(KartAiItemUse *itemUse) {
    itemUse->mHeldItemTimer = 0x0u;
    itemUse->mItemInUseTimer = 0x0u;
    itemUse->mHeldItemEntry = NULL;
    itemUse->mItemInUseEntry = NULL;
    itemUse->mHeldItemSeen = 0x0u;
    itemUse->mItemBitsEveryCall = 0x0u;
    itemUse->mThrowForwardPending = 0x0u;
    itemUse->mThrowBehindPending = 0x0u;
    itemUse->mThrowForwardTimer = 0x0u;
    itemUse->mThrowBehindTimer = 0x0u;
    itemUse->mRandomValue = 0x0u;
}

// On the call whose kart index matches the race frame count mod 8, runs the entry function or sends ITEM_BITS; on
// the other calls sends the pending bit 0x40 (ITEM_THROW_FORWARD_BIT) or 0x80.
void AdvanceItemBitRequests(struct KartAiItemUse *itemUse, struct KartAi *kartAi) {
    u16 kartIndex;
    KartItems *kartItems;

    if (IsKartNotNormalOrFlagged(kartAi->mKart) != FALSE) {
        return;
    }
    kartIndex = kartAi->mIndex;
    if (kartIndex == GetRaceUpdateFramesMod8()) {
        kartItems = &gKartItems[kartIndex];
        if (kartItems->mItemInUse.mObjectKind != ITEM_OBJECT_KIND_NONE && itemUse->mItemInUseEntry != NULL) {
            itemUse->mItemInUseEntry->mHandler(itemUse, kartAi);
        } else if ((itemUse->mHeldItemEntry != 0) & (kartItems->mHeldItem.mItemInfoIndex != ITEM_INFO_NONE)) {
            itemUse->mHeldItemEntry->mHandler(itemUse, kartAi);
        } else {
            RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
        }
    } else if (itemUse->mThrowForwardPending != 0) {
        RequestBits(kartAi->mKart->mEntryIndex, ITEM_THROW_FORWARD_BIT);
        itemUse->mThrowForwardTimer--;
        if (itemUse->mThrowForwardTimer <= 0) {
            itemUse->mThrowForwardPending = 0;
        }
    } else if (itemUse->mThrowBehindPending != 0) {
        RequestBits(kartAi->mKart->mEntryIndex, PAD_KEY_DIRECTION_DOWN);
        itemUse->mThrowBehindTimer--;
        if (itemUse->mThrowBehindTimer <= 0) {
            itemUse->mThrowBehindPending = 0;
        }
    }
    if (itemUse->mItemBitsEveryCall != 0) {
        RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    }
}

void AdvanceRaceItemBitRequests(struct KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (IsKartEnded(kartAi->mIndex) != 0) {
        return;
    }
    if (gKartItems[kartAi->mIndex].mHeldItem.mItemInfoIndex == ITEM_INFO_KILLER) {
        if (kartAi->mPointLinkCursor.mLink->mNextCount > 1) {
            return;
        }
    }
    AdvanceItemBitRequests(itemUse, kartAi);
}

void SetupHeldItemEntry(struct KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;
    enum { HELD_ITEM_INDEX_FIRST } heldItemIndex;

    heldItemIndex = gKartItems[kartAi->mIndex].mHeldItem.mItemInfoIndex;
    itemUse->mHeldItemEntry = &gCurrentHeldItemEntries[heldItemIndex];
    random = GetKartAiRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    itemUse->mRandomValue = (s16) (u16) (random->mValue >> 52);
    if (itemUse->mHeldItemEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mHeldItemEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mHeldItemTimer = itemUse->mHeldItemEntry->mTimerBase + (u16) randomPart;
}

void ResetHeldItemTimer(struct KartAiItemUse *itemUse) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    if (itemUse->mHeldItemEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mHeldItemEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mHeldItemTimer = itemUse->mHeldItemEntry->mTimerBase + (u16) randomPart;
}

// Counts the held-item timer down; returns TRUE once it has run out.
s32 DecrementHeldItemTimer(struct KartAiItemUse *itemUse) {
    BOOL timerRanOut = FALSE;

    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    return timerRanOut;
}

void ResetItemInUseTimer(struct KartAiItemUse *itemUse, const struct KartAiItemUseEntry *unusedEntry) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

// Counts the item-in-use timer down; returns TRUE once it has run out.
s32 DecrementItemInUseTimer(struct KartAiItemUse *itemUse) {
    BOOL timerRanOut = FALSE;

    itemUse->mItemInUseTimer--;
    if (itemUse->mItemInUseTimer <= 0) {
        itemUse->mItemInUseTimer = 0;
        timerRanOut = TRUE;
    }
    return timerRanOut;
}

void SetupItemInUseEntry(struct KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;
    enum { OBJECT_KIND_FIRST } objectKind;

    objectKind = gKartItems[kartAi->mIndex].mItemInUse.mObjectKind;
    itemUse->mItemInUseEntry = &gCurrentItemInUseEntries[objectKind];
    itemUse->mHeldItemSeen = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

void SetupPosCurve(PosCurve *posCurve, struct CourseMapCamera *mapCamera) {
    CourseMapEntryGroup *entryGroup = &gCourseMap->mEntryGroups[mapCamera->mEntryGroupIndex];
    u16 pointIndex;

    posCurve->mParam = 0;
    posCurve->mEntryIndex = 0;
    posCurve->mReverseLastEntryIndex = 0;
    if (entryGroup->mEntryCount < 4) {
        return;
    }
    for (pointIndex = 0; pointIndex < 4; pointIndex++) {
        posCurve->mPoints[pointIndex] = GetCourseMapGroupEntry(mapCamera->mEntryGroupIndex, pointIndex)->mPos;
        posCurve->mEntryIndex = pointIndex;
    }
}

void SetupReversePosCurve(PosCurve *posCurve, struct CourseMapCamera *mapCamera) {
    s16 entryIndex;
    s16 pointIndex;
    CourseMapEntryGroup *entryGroup = &gCourseMap->mEntryGroups[mapCamera->mEntryGroupIndex];

    posCurve->mParam = 0;
    posCurve->mEntryIndex = 0;
    posCurve->mReverseLastEntryIndex = 0;
    if (entryGroup->mEntryCount < 4) {
        return;
    }
    posCurve->mReverseLastEntryIndex = entryGroup->mEntryCount - 1;
    posCurve->mEntryIndex = 2;
    entryIndex = 2;
    for (pointIndex = 0; pointIndex < 3; pointIndex++) {
        *GetPosCurvePoint(posCurve, pointIndex) = GetCourseMapGroupEntry(mapCamera->mEntryGroupIndex, entryIndex)->mPos;
        entryIndex--;
    }
    posCurve->mPoints[3] = GetCourseMapGroupEntry(mapCamera->mEntryGroupIndex, entryGroup->mEntryCount - 1)->mPos;
}

void UpdatePosCurve(Vec3 *point, PosCurve *posCurve, struct CourseMapCamera *mapCamera, s32 paramStep) {
    CourseMapEntryGroup *entryGroup;
    CourseMapGroupEntry *groupEntry;
    u16 pointIndex;

    entryGroup = &gCourseMap->mEntryGroups[mapCamera->mEntryGroupIndex];
    posCurve->mParam += paramStep;
    if (posCurve->mParam > TO_FIXED12(1)) {
        posCurve->mEntryIndex++;
        if (posCurve->mEntryIndex >= entryGroup->mEntryCount) {
            posCurve->mEntryIndex = entryGroup->mEntryCount;
            posCurve->mParam = TO_FIXED12(1);
        } else {
            groupEntry = GetCourseMapGroupEntry(mapCamera->mEntryGroupIndex, posCurve->mEntryIndex);
            for (pointIndex = 0; pointIndex < 3; pointIndex++) {
                posCurve->mPoints[pointIndex] = posCurve->mPoints[pointIndex + 1];
            }
            posCurve->mPoints[3] = groupEntry->mPos;
            posCurve->mParam -= 0x1000;
        }
    }
    ComputePosCurvePoint(point, posCurve);
}

void ComputePosCurvePoint(Vec3 *point, PosCurve *posCurve) {
    s32 param;
    s32 paramSquared;
    s32 paramCubed;
    s32 paramRemaining;
    s32 weight0;
    s32 weight1;
    s32 weight2;
    s32 weight3;
    Vec3 *controlPoints[4];
    s32 pointIndex;

    param = posCurve->mParam;
    paramRemaining = 0x1000 - param;
    paramSquared = MUL_FIXED12_ROUNDED(param, param);
    paramCubed = MUL_FIXED12_ROUNDED(paramSquared, param);
    weight0 = MUL_FIXED12_ROUNDED(MUL_FIXED12_ROUNDED(paramRemaining, 0x2ab),
                                  MUL_FIXED12_ROUNDED(paramRemaining, paramRemaining));
    weight1 = MUL_FIXED12_ROUNDED(
        MUL_FIXED12_ROUNDED(paramCubed, 0x3000) - MUL_FIXED12_ROUNDED(0x6000, paramSquared) + 0x4000, 0x2ab);
    weight2 = MUL_FIXED12_ROUNDED(MUL_FIXED12_ROUNDED(param + (paramSquared - paramCubed), 0x3000) + 0x1000, 0x2ab);
    weight3 = MUL_FIXED12_ROUNDED(paramCubed, 0x2ab);
    for (pointIndex = 0; pointIndex < 4; pointIndex++) {
        controlPoints[pointIndex] = &posCurve->mPoints[pointIndex];
    }
    point->x = MUL_FIXED12_ROUNDED(controlPoints[0]->x, weight0) + MUL_FIXED12_ROUNDED(controlPoints[1]->x, weight1) +
               MUL_FIXED12_ROUNDED(controlPoints[2]->x, weight2) + MUL_FIXED12_ROUNDED(controlPoints[3]->x, weight3);
    point->y = MUL_FIXED12_ROUNDED(controlPoints[0]->y, weight0) + MUL_FIXED12_ROUNDED(controlPoints[1]->y, weight1) +
               MUL_FIXED12_ROUNDED(controlPoints[2]->y, weight2) + MUL_FIXED12_ROUNDED(controlPoints[3]->y, weight3);
    point->z = MUL_FIXED12_ROUNDED(controlPoints[0]->z, weight0) + MUL_FIXED12_ROUNDED(controlPoints[1]->z, weight1) +
               MUL_FIXED12_ROUNDED(controlPoints[2]->z, weight2) + MUL_FIXED12_ROUNDED(controlPoints[3]->z, weight3);
}
