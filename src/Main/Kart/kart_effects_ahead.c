#include "Main/Kart/kart_effects_ahead.h"

#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/System/wireless_vram_state.h"
#include "fixed_vector_math.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_ai.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/point_link_cursor_advance.h"
#include "Main/Kart/kart_point_link_effects.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Graphics/effects.h"
#include "Main/System/backup_net_camera_work.h"
#include "particle_instance.h"
#include "Main/Kart/karts.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/System/init_after_startup.h"

const Vec3 gPointLinkVec3Zero = {0, 0, 0};

void StartKartAheadEffectIfSelectedEntry(Kart *kart) {
    ParticleEmitter *effect;

    if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
        return;
    }
    if (gKartAheadEffects[kart->mIndex] != NULL) {
        return;
    }
    gKartAheadEffects[kart->mIndex] = StartEffect(0x80, &g_SomeVec);
    effect = gKartAheadEffects[kart->mIndex];
    effect->mKartIndex = kart->mIndex;
    effect->mCallbackData = 0;
    effect->mCallback = AdvanceKartAheadEffect;
}

void StructMQRacerEntry_SomeFn_69(Kart *kart) {
    ParticleEmitter *effect = gKartAheadEffects[kart->mIndex];

    if (effect == NULL) {
        return;
    }
    effect->mStepCount = 0;
    effect->mStepLimit = KART_AHEAD_EFFECT_STOP_STEPS;
    effect->mCallback = AdvanceKartAheadEffectWithLimit;
    gKartAheadEffects[kart->mIndex] = NULL;
}

void StructMQRacerEntry_SomeFn_22(Kart *kart) {
    if (gKartAheadEffects[kart->mIndex] == NULL) {
        return;
    }
    DeleteEffect(gKartAheadEffects[kart->mIndex]);
    gKartAheadEffects[kart->mIndex] = NULL;
}

void StructMQRacerEntry_SomeFn_62(Kart *kart) {
    ParticleEmitter *effect;

    if (gKartNearRankEffects[kart->mIndex] != NULL) {
        return;
    }
    gKartNearRankEffects[kart->mIndex] = StartEffect(0x7f, &g_SomeVec);
    effect = gKartNearRankEffects[kart->mIndex];
    effect->mKartIndex = kart->mIndex;
    effect->mCallbackData = (void *) 1;
    effect->mCallback = AdvanceKartAheadEffect;
}

void StructMQRacerEntry_SomeFn_3(Kart *kart) {
    ParticleEmitter *effect = gKartNearRankEffects[kart->mIndex];

    if (effect == NULL) {
        return;
    }
    effect->mStepCount = 0;
    effect->mStepLimit = KART_NEAR_RANK_EFFECT_STOP_STEPS;
    effect->mCallback = AdvanceKartAheadEffectWithLimit;
    gKartNearRankEffects[kart->mIndex] = NULL;
}

void StructMQRacerEntry_SomeFn_23(Kart *kart) {
    if (gKartNearRankEffects[kart->mIndex] == NULL) {
        return;
    }
    DeleteEffect(gKartNearRankEffects[kart->mIndex]);
    gKartNearRankEffects[kart->mIndex] = NULL;
}

void SetEffectScaleFromKartScaleZ(ParticleEmitter *effect, Kart *kart) {
    effect->mSizeScale = (s16) kart->mScale.z;
}

BOOL IsWithinBattlePointLinkDistance(LinkCursor *linkCursor, Vec3 *position) {
    Vec3 offset;
    s32 radius;
    BOOL result = FALSE;

    radius = linkCursor->mLink->mRadius;
    VecFx32_Subtract(linkCursor->mLink->mPoint, position, &offset);
    offset.y = result;
    if (LENGTH_SQUARED(offset) < (s64) radius * radius) {
        result = TRUE;
    }
    return result;
}

BOOL IsPastBattlePointLink(LinkCursor *linkCursor, Vec3 *position) {
    Vec3 offset;
    Vec3 *linkPosition = linkCursor->mLink->mPoint;
    BOOL result = FALSE;

    if (linkCursor->mDirection.x != 0 || linkCursor->mDirection.y != 0 || linkCursor->mDirection.z != 0) {
        VecFx32_Subtract(position, linkPosition, &offset);
        if (VecFx32_CrossProduct_0(&linkCursor->mDirection, &offset) > 0) {
            result = TRUE;
        }
    }
    return result;
}

void InitRacePointLinkCursor(PointLinkCursor *racePointLinkCursor, u16 kartIndex) {
    racePointLinkCursor->mLink = g_GlobalPE->mRaceRoute0FirstLink;
    racePointLinkCursor->mPreviousLink = racePointLinkCursor->mLink->mPreviousLinks[0];
    racePointLinkCursor->mDirection = gPointLinkVec3Zero;
    VecFx32_Subtract(racePointLinkCursor->mLink->mPoint, racePointLinkCursor->mPreviousLink->mPoint,
                 &racePointLinkCursor->mDirection);
    Vector3_MaybeNormalize(&racePointLinkCursor->mDirection, &racePointLinkCursor->mDirection);
    racePointLinkCursor->mRequestedLink = NULL;
    racePointLinkCursor->mRequestedLinkFound = FALSE;
    racePointLinkCursor->mKartIndex = kartIndex;
    racePointLinkCursor->mBranchChoiceCount = 0;
}

void ResetPointLinkCursor(PointLinkCursor *linkCursor, RacePointLink *pointLink) {
    linkCursor->mLink = pointLink;
    linkCursor->mPreviousLink = linkCursor->mLink->mPreviousLinks[0];
    linkCursor->mRequestedLink = NULL;
    linkCursor->mRequestedLinkFound = FALSE;
    linkCursor->mDirection = gPointLinkVec3Zero;
    VecFx32_Subtract(linkCursor->mLink->mPoint, linkCursor->mPreviousLink->mPoint, &linkCursor->mDirection);
    Vector3_MaybeNormalize(&linkCursor->mDirection, &linkCursor->mDirection);
}

s16 GetPointLinkFirstValue(PointLinkCursor *linkCursor) {
    return linkCursor->mLink->mValues[0];
}

BOOL IsWithinPointLinkDistance(PointLinkCursor *pointLinkCursor, Vec3 *position) {
    Vec3 offset;
    s32 radius;
    BOOL result;
    RacePointLink *link = pointLinkCursor->mLink;

    result = FALSE;
    radius = link->mRadius;
    VecFx32_Subtract(link->mPoint, position, &offset);
    offset.y = result;
    if (LENGTH_SQUARED(offset) < (s64) radius * radius) {
        result = TRUE;
    }
    return result;
}

BOOL IsPastPointLink(PointLinkCursor *pointLinkCursor, Vec3 *position) {
    Vec3 offset;
    BOOL result;
    Vec3 *linkPosition = pointLinkCursor->mLink->mPoint;

    result = FALSE;
    if (pointLinkCursor->mDirection.x != 0 || pointLinkCursor->mDirection.y != 0 ||
        pointLinkCursor->mDirection.z != 0) {
        VecFx32_Subtract(position, linkPosition, &offset);
        if (VecFx32_CrossProduct_0(&pointLinkCursor->mDirection, &offset) > 0) {
            result = TRUE;
        }
    }
    return result;
}

void AdvancePointLinkCursor(PointLinkCursor *pointLinkCursor) {
    u16 nextIndex = 0;
    u16 nextLinkCount;
    u32 randomValue;
    RandomState64 *kartAiRandom;

    if (!(GetRacerMQEntry(pointLinkCursor->mKartIndex)->mEffectFlags & KART_EFFECT_KILLER)) {
        nextLinkCount = pointLinkCursor->mLink->mNextCount;
        if (nextLinkCount > 1) {
            kartAiRandom = GetKartAiRandom();
            if (nextLinkCount == 0) {
                randomValue = 0;
            } else {
                kartAiRandom->mValue =
                    (s64) kartAiRandom->mMultiplier * (s64) kartAiRandom->mValue + kartAiRandom->mIncrement;
                randomValue = (nextLinkCount == 0) ? (u32) (kartAiRandom->mValue >> 32)
                                                   : (u32) (((kartAiRandom->mValue >> 32) * (u32) nextLinkCount) >> 32);
            }
            nextIndex = randomValue;
        }
    }
    pointLinkCursor->mPreviousLink = pointLinkCursor->mLink;
    pointLinkCursor->mLink = pointLinkCursor->mLink->mNextLinks[nextIndex];
    VecFx32_Subtract(pointLinkCursor->mLink->mPoint, pointLinkCursor->mPreviousLink->mPoint, &pointLinkCursor->mDirection);
    Vector3_MaybeNormalize(&pointLinkCursor->mDirection, &pointLinkCursor->mDirection);
}

void AdvancePointLinkCursorTo(PointLinkCursor *linkCursor, RacePointLink *pointLink) {
    linkCursor->mPreviousLink = linkCursor->mLink;
    linkCursor->mLink = pointLink;
    VecFx32_Subtract(linkCursor->mLink->mPoint, linkCursor->mPreviousLink->mPoint, &linkCursor->mDirection);
    Vector3_MaybeNormalize(&linkCursor->mDirection, &linkCursor->mDirection);
}

void SetRequestedLinkToPreviousIfNone(PointLinkCursor *linkCursor) {
    if (linkCursor->mRequestedLink == NULL) {
        linkCursor->mRequestedLink = linkCursor->mPreviousLink;
        linkCursor->mRequestedLinkFound = FALSE;
    }
}

void ResetBattlePointLinkCursorNear(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 unused) {
    PointLink *bestLink = NULL;
    u16 pointIndex;
    u16 candidateIndex;
    s32 slot;
    s32 bestDot;
    s32 value;
    PointLink *firstLink = g_GlobalPE->mFirstBattlePointLink;
    PointLink *nearestLinks[3] = {0, 0, 0};
    s32 nearestDistances[3];
    Vec3 offset;
    Vec3 directionToLink;

    nearestDistances[0] = nearestDistances[1] = nearestDistances[2] = 0xc8000;
    bestDot = -0x1000;
    for (pointIndex = 0; pointIndex < g_GlobalPE->mBattlePointCount; pointIndex++) {
        VecFx32_Subtract(&g_GlobalPE->mBattlePoints[pointIndex].mPos, position, &offset);
        value = VecFx32_Norm(&offset);
        if (value < 0xc8000) {
            for (slot = 0; slot < 3; slot++) {
                if (value < nearestDistances[slot]) {
                    nearestDistances[slot] = value;
                    nearestLinks[slot] = &firstLink[pointIndex];
                    break;
                }
            }
        }
    }
    for (candidateIndex = 0; candidateIndex < 3; candidateIndex++) {
        if (nearestLinks[candidateIndex] != NULL) {
            VecFx32_Subtract(nearestLinks[candidateIndex]->mPoint, position, &directionToLink);
            if (SQUARE_SUM3(directionToLink.x, directionToLink.y, directionToLink.z) >=
                0x10) {
                Vector3_MaybeNormalize(&directionToLink, &directionToLink);
            }
            value = VecFx32_CrossProduct_0(&directionToLink, direction);
            if (value >= bestDot) {
                bestLink = nearestLinks[candidateIndex];
                bestDot = value;
            }
        }
    }
    linkCursor->mLink = bestLink;
    linkCursor->mPreviousLink = bestLink;
    linkCursor->mDirection = gPointLinkVec3Zero;
    linkCursor->mRequestedLink = NULL;
    linkCursor->mRequestPending = FALSE;
}

void ResetBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mPreviousLink = pointLink;
    linkCursor->mLink = linkCursor->mPreviousLink;
    linkCursor->mDirection = gPointLinkVec3Zero;
    linkCursor->mRequestedLink = NULL;
    linkCursor->mRequestPending = FALSE;
}

void AdvanceBattlePointLinkCursor(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 kartIndex,
                                  MapObject *targetShine, s32 targetKartIndex) {
    s32 bestFallbackDot;
    PointLink *nextLink;
    s32 lowestTargetDot;
    PointLink *currentLink = linkCursor->mLink;
    u16 fallbackCount = 0;
    PointLink *candidateLinks[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    u16 lowestCount;
    s32 bestTargetDot;
    Kart *kart;
    PointLink *neighborLink;
    s32 targetDot;
    u16 candidateCount;
    u16 chosenIndex;
    u16 pairIndex;
    u32 randomValue;
    BOOL targetFlagged;
    PointLink *fallbackLink;
    u16 bestCount;
    s32 directionDot;
    u16 linkIndex;
    u8 neighborLinkIndex;
    RandomState64 *kartAiRandom;
    u16 shineCount;
    Vec3 directionToTargetShine;
    Vec3 directionToLink;
    Vec3 directionToTargetKart;
    Vec3 directionToCandidateLink;
    Vec3 directionsToCandidates[2];
    Vec3 neighborLinkDirection;

    bestFallbackDot = -0x1000;
    lowestTargetDot = 0x1000;
    nextLink = NULL;
    bestTargetDot = bestFallbackDot;
    fallbackLink = NULL;
    if (linkCursor->mLink->mLinkCount == 1) {
        nextLink = linkCursor->mLink->mLinks[0];
    } else {
        PointLink *openLinks[2] = {0, 0};

        candidateCount = 0;
        lowestCount = 0;
        lowestCount = lowestCount;
        bestCount = 0;
        if (targetShine != NULL) {
            shineCount = 0;
            VecFx32_Subtract(&targetShine->mPos, &GetRacerMQEntry(kartIndex)->mPos, &directionToTargetShine);
            if ((s64) directionToTargetShine.x * directionToTargetShine.x +
                    (s64) directionToTargetShine.y * directionToTargetShine.y +
                    (s64) directionToTargetShine.z * directionToTargetShine.z >=
                0x10) {
                Vector3_MaybeNormalize(&directionToTargetShine, &directionToTargetShine);
            }
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink == ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex]) {
                    continue;
                }
                VecFx32_Subtract(linkCursor->mLink->mLinks[linkIndex]->mPoint, &GetRacerMQEntry(kartIndex)->mPos, &directionToLink);
                if (SQUARE_SUM3(directionToLink.x, directionToLink.y, directionToLink.z) >=
                    0x10) {
                    Vector3_MaybeNormalize(&directionToLink, &directionToLink);
                }
                directionDot = VecFx32_CrossProduct_0(&directionToLink, direction);
                if (directionDot >= -0x800) {
                    targetDot = Vector3_DotProduct(&directionToTargetShine, &directionToLink);
                    if (targetDot > bestTargetDot || shineCount == 0) {
                        bestTargetDot = targetDot;
                        shineCount++;
                        nextLink = linkCursor->mLink->mLinks[linkIndex];
                    }
                } else if (directionDot >= bestFallbackDot || fallbackCount == 0) {
                    bestFallbackDot = directionDot;
                    fallbackLink = linkCursor->mLink->mLinks[linkIndex];
                    fallbackCount++;
                }
            }
        } else if (targetKartIndex != -1) {
            lowestCount = (u16) lowestCount;
            if (GetRacerMQEntry(targetKartIndex)->mEffectFlags & KART_EFFECT_STAR) {
                targetFlagged = TRUE;
            } else {
                targetFlagged = FALSE;
            }
            kart = GetRacerMQEntry(kartIndex);
            VecFx32_Subtract(&GetRacerMQEntry(targetKartIndex)->mPos, &kart->mPos, &directionToTargetKart);
            if ((s64) directionToTargetKart.x * directionToTargetKart.x +
                    (s64) directionToTargetKart.y * directionToTargetKart.y +
                    (s64) directionToTargetKart.z * directionToTargetKart.z >=
                0x10) {
                Vector3_MaybeNormalize(&directionToTargetKart, &directionToTargetKart);
            }
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink == ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex]) {
                    continue;
                }
                VecFx32_Subtract(linkCursor->mLink->mLinks[linkIndex]->mPoint, &GetRacerMQEntry(kartIndex)->mPos,
                             &directionToCandidateLink);
                if ((s64) directionToCandidateLink.x * directionToCandidateLink.x +
                        (s64) directionToCandidateLink.y * directionToCandidateLink.y +
                        (s64) directionToCandidateLink.z * directionToCandidateLink.z >=
                    0x10) {
                    Vector3_MaybeNormalize(&directionToCandidateLink, &directionToCandidateLink);
                }
                directionDot = VecFx32_CrossProduct_0(&directionToCandidateLink, direction);
                if (directionDot >= -0x800) {
                    if (targetFlagged == FALSE) {
                        targetDot = Vector3_DotProduct(&directionToTargetKart, &directionToCandidateLink);
                        if (targetDot > bestTargetDot || bestCount == 0) {
                            bestTargetDot = targetDot;
                            nextLink = linkCursor->mLink->mLinks[linkIndex];
                            bestCount++;
                        }
                    } else {
                        targetDot = Vector3_DotProduct(&directionToTargetKart, &directionToCandidateLink);
                        if (targetDot < lowestTargetDot || lowestCount == 0) {
                            lowestTargetDot = targetDot;
                            nextLink = linkCursor->mLink->mLinks[linkIndex];
                            lowestCount++;
                        }
                    }
                } else if (directionDot >= bestFallbackDot || fallbackCount == 0) {
                    bestFallbackDot = directionDot;
                    fallbackLink = linkCursor->mLink->mLinks[linkIndex];
                    fallbackCount++;
                }
            }
        } else {
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink != ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex] &&
                    !(linkCursor->mLink->mRouteLinkMask & (1 << (u8) linkIndex))) {
                    openLinks[bestCount] = ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex];
                    bestCount++;
                    lowestCount = 1;
                }
            }
            if (lowestCount != 0) {
                chosenIndex = 0;
                if (bestCount > 1) {
                    for (pairIndex = 0; pairIndex < 2; pairIndex++) {
                        VecFx32_Subtract(openLinks[pairIndex]->mPoint, linkCursor->mLink->mPoint,
                                     &directionsToCandidates[pairIndex]);
                        if ((s64) directionsToCandidates[pairIndex].x * directionsToCandidates[pairIndex].x +
                                (s64) directionsToCandidates[pairIndex].y * directionsToCandidates[pairIndex].y +
                                (s64) directionsToCandidates[pairIndex].z * directionsToCandidates[pairIndex].z >=
                            0x10) {
                            Vector3_MaybeNormalize(&directionsToCandidates[pairIndex],
                                                               &directionsToCandidates[pairIndex]);
                        }
                    }
                    if (VecFx32_CrossProduct_0(&directionsToCandidates[0], direction) <
                        VecFx32_CrossProduct_0(&directionsToCandidates[1], direction)) {
                        chosenIndex = 1;
                    }
                }
                candidateLinks[0] = openLinks[chosenIndex];
                candidateCount = 1;
            } else {
                for (linkIndex = 0; linkIndex < ((const PointLink *) linkCursor->mLink)->mLinkCount; linkIndex++) {
                    if (linkCursor->mPreviousLink != ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex] &&
                        (linkCursor->mLink->mRouteLinkMask & (1 << (u8) linkIndex))) {
                        neighborLinkDirection = gPointLinkVec3Zero;
                        neighborLink = linkCursor->mLink->mLinks[linkIndex];
                        for (neighborLinkIndex = 0; neighborLinkIndex < neighborLink->mLinkCount; neighborLinkIndex++) {
                            if (!(neighborLink->mRouteLinkMask & (1 << neighborLinkIndex)) &&
                                ((const LinkCursor *) linkCursor)->mLink != neighborLink->mLinks[neighborLinkIndex]) {
                                VecFx32_Subtract(neighborLink->mLinks[neighborLinkIndex]->mPoint, neighborLink->mPoint,
                                             &neighborLinkDirection);
                                if ((s64) neighborLinkDirection.x * (s64) neighborLinkDirection.x +
                                        (s64) neighborLinkDirection.y * (s64) neighborLinkDirection.y +
                                        (s64) neighborLinkDirection.z * (s64) neighborLinkDirection.z >=
                                    0x10) {
                                    Vector3_MaybeNormalize(&neighborLinkDirection, &neighborLinkDirection);
                                }
                                break;
                            }
                        }
                        directionDot = VecFx32_CrossProduct_0(&neighborLinkDirection, direction);
                        if (directionDot >= -0x800) {
                            candidateLinks[candidateCount] = linkCursor->mLink->mLinks[linkIndex];
                            candidateCount++;
                        } else if (directionDot >= bestFallbackDot || fallbackCount == 0) {
                            bestFallbackDot = directionDot;
                            fallbackLink = linkCursor->mLink->mLinks[linkIndex];
                            fallbackCount++;
                        }
                    }
                }
            }
        }
        if (nextLink == NULL) {
            if (candidateCount == 0) {
                nextLink = fallbackLink;
            } else {
                if (candidateCount == 1) {
                    shineCount = 0;
                } else {
                    kartAiRandom = GetKartAiRandom();
                    if (candidateCount == 0) {
                        randomValue = 0;
                    } else {
                        kartAiRandom->mValue =
                            kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
                        if (candidateCount == 0) {
                            randomValue = kartAiRandom->mValue >> 32;
                        } else {
                            randomValue = ((kartAiRandom->mValue >> 32) * (u32) candidateCount) >> 32;
                        }
                    }
                    shineCount = randomValue;
                }
                nextLink = candidateLinks[shineCount];
            }
        }
    }
    linkCursor->mLink = nextLink;
    linkCursor->mPreviousLink = currentLink;
    linkCursor->mDirection = gPointLinkVec3Zero;
    VecFx32_Subtract(linkCursor->mLink->mPoint, linkCursor->mPreviousLink->mPoint, &linkCursor->mDirection);
    if ((s64) linkCursor->mDirection.x * linkCursor->mDirection.x +
            (s64) linkCursor->mDirection.y * linkCursor->mDirection.y +
            (s64) linkCursor->mDirection.z * linkCursor->mDirection.z >=
        0x10) {
        Vector3_MaybeNormalize(&linkCursor->mDirection, &linkCursor->mDirection);
    }
}

s32 GetBattlePointLinkSpeedLimit(LinkCursor *linkCursor) {
    s32 result = 0;
    s16 unscaledSpeedLimit = *linkCursor->mLink->mValues;

    if (unscaledSpeedLimit != 0) {
        result = MUL_FIXED12_NO_ROUND(unscaledSpeedLimit, 0x28f5c);
    }
    return result;
}

void AdvanceBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mPreviousLink = linkCursor->mLink;
    linkCursor->mLink = pointLink;
    linkCursor->mDirection = gPointLinkVec3Zero;
    VecFx32_Subtract(linkCursor->mLink->mPoint, linkCursor->mPreviousLink->mPoint, &linkCursor->mDirection);
    if ((s64) linkCursor->mDirection.x * linkCursor->mDirection.x +
            (s64) linkCursor->mDirection.y * linkCursor->mDirection.y +
            (s64) linkCursor->mDirection.z * linkCursor->mDirection.z >=
        0x10) {
        Vector3_MaybeNormalize(&linkCursor->mDirection, &linkCursor->mDirection);
    }
}

void SetupPointLinkCursor(PointLinkCursor *cursor, u32 kartIndex, struct RacePointLink *link) {
    cursor->mDirection = gPointLinkVec3Zero;
    cursor->mPreviousLink = link;
    cursor->mLink = cursor->mPreviousLink->mNextLinks[0];
    VecFx32_Subtract(cursor->mLink->mPoint, cursor->mPreviousLink->mPoint, &cursor->mDirection);
    Vector3_MaybeNormalize(&cursor->mDirection, &cursor->mDirection);
    cursor->mRequestedLink = NULL;
    cursor->mRequestedLinkFound = 0;
    cursor->mKartIndex = kartIndex;
}
