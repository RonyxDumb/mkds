#include "Main/Kart/kart_effects_ahead.h"

#include "Main/Unknown/unk_02155000.h"
#include "Main/System/wvr_state.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020800f4.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_ai.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020808d4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Unknown/code_02080adc.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_02080cc0.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Graphics/effects.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0201c528.h"
#include "Main/Kart/karts.h"

void StartKartAheadEffectIfSelectedEntry(Kart *kart) {
    ParticleEmitter *effect;

    if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
        return;
    }
    if (gKartAheadEffects[kart->mIndex] != NULL) {
        return;
    }
    gKartAheadEffects[kart->mIndex] = StartEffect(0x80, &gKartEffectVec3Zero);
    effect = gKartAheadEffects[kart->mIndex];
    effect->mUnk_98_24 = kart->mIndex;
    effect->mUnk_94 = 0;
    effect->mCallback = AdvanceKartAheadEffect;
}

void StopKartAheadEffect(Kart *kart) {
    ParticleEmitter *effect = gKartAheadEffects[kart->mIndex];

    if (effect == NULL) {
        return;
    }
    effect->mUnk_98_16 = 0;
    effect->mUnk_98_8 = 3;
    effect->mCallback = AdvanceKartAheadEffectWithLimit;
    gKartAheadEffects[kart->mIndex] = NULL;
}

void ReleaseKartAheadEffect(Kart *kart) {
    if (gKartAheadEffects[kart->mIndex] == NULL) {
        return;
    }
    DeleteEffect(gKartAheadEffects[kart->mIndex]);
    gKartAheadEffects[kart->mIndex] = NULL;
}

void StartKartNearRankEffect(Kart *kart) {
    ParticleEmitter *effect;

    if (gKartNearRankEffects[kart->mIndex] != NULL) {
        return;
    }
    gKartNearRankEffects[kart->mIndex] = StartEffect(0x7f, &gKartEffectVec3Zero);
    effect = gKartNearRankEffects[kart->mIndex];
    effect->mUnk_98_24 = kart->mIndex;
    effect->mUnk_94 = (void *) 1;
    effect->mCallback = AdvanceKartAheadEffect;
}

void StopKartNearRankEffect(Kart *kart) {
    ParticleEmitter *effect = gKartNearRankEffects[kart->mIndex];

    if (effect == NULL) {
        return;
    }
    effect->mUnk_98_16 = 0;
    effect->mUnk_98_8 = 5;
    effect->mCallback = AdvanceKartAheadEffectWithLimit;
    gKartNearRankEffects[kart->mIndex] = NULL;
}

void ReleaseKartNearRankEffect(Kart *kart) {
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
    VEC_Subtract(linkCursor->mLink->mPoint, position, &offset);
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
        VEC_Subtract(position, linkPosition, &offset);
        if (Vec3DotUnrounded(&linkCursor->mDirection, &offset) > 0) {
            result = TRUE;
        }
    }
    return result;
}

void InitRacePointLinkCursor(PointLinkCursor *racePointLinkCursor, u16 kartIndex) {
    racePointLinkCursor->mLink = gCourseMap->mRaceRoute0FirstLink;
    racePointLinkCursor->mPreviousLink = racePointLinkCursor->mLink->mPreviousLinks[0];
    racePointLinkCursor->mDirection = gPointLinkVec3Zero;
    VEC_Subtract(racePointLinkCursor->mLink->mPoint, racePointLinkCursor->mPreviousLink->mPoint,
                 &racePointLinkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&racePointLinkCursor->mDirection, &racePointLinkCursor->mDirection);
    racePointLinkCursor->mRequestedLink = NULL;
    racePointLinkCursor->mUnk_18 = FALSE;
    racePointLinkCursor->mKartIndex = kartIndex;
    racePointLinkCursor->mUnk_1e = 0;
}

void ResetPointLinkCursor(PointLinkCursor *linkCursor, RacePointLink *pointLink) {
    linkCursor->mLink = pointLink;
    linkCursor->mPreviousLink = linkCursor->mLink->mPreviousLinks[0];
    linkCursor->mRequestedLink = NULL;
    linkCursor->mUnk_18 = FALSE;
    linkCursor->mDirection = gPointLinkVec3Zero;
    VEC_Subtract(linkCursor->mLink->mPoint, linkCursor->mPreviousLink->mPoint, &linkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&linkCursor->mDirection, &linkCursor->mDirection);
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
    VEC_Subtract(link->mPoint, position, &offset);
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
        VEC_Subtract(position, linkPosition, &offset);
        if (Vec3DotUnrounded(&pointLinkCursor->mDirection, &offset) > 0) {
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

    if (!(GetKart(pointLinkCursor->mKartIndex)->mEffectFlags & KART_EFFECT_KILLER)) {
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
    VEC_Subtract(pointLinkCursor->mLink->mPoint, pointLinkCursor->mPreviousLink->mPoint, &pointLinkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&pointLinkCursor->mDirection, &pointLinkCursor->mDirection);
}

void AdvancePointLinkCursorTo(PointLinkCursor *linkCursor, RacePointLink *pointLink) {
    linkCursor->mPreviousLink = linkCursor->mLink;
    linkCursor->mLink = pointLink;
    VEC_Subtract(linkCursor->mLink->mPoint, linkCursor->mPreviousLink->mPoint, &linkCursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&linkCursor->mDirection, &linkCursor->mDirection);
}

void SetRequestedLinkToPreviousIfNone(PointLinkCursor *linkCursor) {
    if (linkCursor->mRequestedLink == NULL) {
        linkCursor->mRequestedLink = linkCursor->mPreviousLink;
        linkCursor->mUnk_18 = FALSE;
    }
}

void ResetBattlePointLinkCursorNear(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 unused) {
    PointLink *bestLink = NULL;
    u16 pointIndex;
    u16 candidateIndex;
    s32 slot;
    s32 bestDot;
    s32 value;
    PointLink *firstLink = gCourseMap->mFirstBattlePointLink;
    PointLink *nearestLinks[3] = {0, 0, 0};
    s32 nearestDistances[3];
    Vec3 offset;
    Vec3 directionToLink;

    nearestDistances[0] = nearestDistances[1] = nearestDistances[2] = 0xc8000;
    bestDot = -0x1000;
    for (pointIndex = 0; pointIndex < gCourseMap->mBattlePointCount; pointIndex++) {
        VEC_Subtract(&gCourseMap->mBattlePoints[pointIndex].mPos, position, &offset);
        value = VEC_Mag(&offset);
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
            VEC_Subtract(nearestLinks[candidateIndex]->mPoint, position, &directionToLink);
            if ((s64) directionToLink.x * directionToLink.x + (s64) directionToLink.y * directionToLink.y +
                    (s64) directionToLink.z * directionToLink.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&directionToLink, &directionToLink);
            }
            value = Vec3DotUnrounded(&directionToLink, direction);
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
    linkCursor->mUnk_18 = FALSE;
}

void ResetBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mPreviousLink = pointLink;
    linkCursor->mLink = linkCursor->mPreviousLink;
    linkCursor->mDirection = gPointLinkVec3Zero;
    linkCursor->mRequestedLink = NULL;
    linkCursor->mUnk_18 = FALSE;
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
            VEC_Subtract(&targetShine->mPos, &GetKart(kartIndex)->mPos, &directionToTargetShine);
            if ((s64) directionToTargetShine.x * directionToTargetShine.x +
                    (s64) directionToTargetShine.y * directionToTargetShine.y +
                    (s64) directionToTargetShine.z * directionToTargetShine.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&directionToTargetShine, &directionToTargetShine);
            }
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink == ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex]) {
                    continue;
                }
                VEC_Subtract(linkCursor->mLink->mLinks[linkIndex]->mPoint, &GetKart(kartIndex)->mPos, &directionToLink);
                if ((s64) directionToLink.x * directionToLink.x + (s64) directionToLink.y * directionToLink.y +
                        (s64) directionToLink.z * directionToLink.z >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&directionToLink, &directionToLink);
                }
                directionDot = Vec3DotUnrounded(&directionToLink, direction);
                if (directionDot >= -0x800) {
                    targetDot = VEC_DotProduct(&directionToTargetShine, &directionToLink);
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
            if (GetKart(targetKartIndex)->mEffectFlags & KART_EFFECT_STAR) {
                targetFlagged = TRUE;
            } else {
                targetFlagged = FALSE;
            }
            kart = GetKart(kartIndex);
            VEC_Subtract(&GetKart(targetKartIndex)->mPos, &kart->mPos, &directionToTargetKart);
            if ((s64) directionToTargetKart.x * directionToTargetKart.x +
                    (s64) directionToTargetKart.y * directionToTargetKart.y +
                    (s64) directionToTargetKart.z * directionToTargetKart.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&directionToTargetKart, &directionToTargetKart);
            }
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink == ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex]) {
                    continue;
                }
                VEC_Subtract(linkCursor->mLink->mLinks[linkIndex]->mPoint, &GetKart(kartIndex)->mPos,
                             &directionToCandidateLink);
                if ((s64) directionToCandidateLink.x * directionToCandidateLink.x +
                        (s64) directionToCandidateLink.y * directionToCandidateLink.y +
                        (s64) directionToCandidateLink.z * directionToCandidateLink.z >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&directionToCandidateLink, &directionToCandidateLink);
                }
                directionDot = Vec3DotUnrounded(&directionToCandidateLink, direction);
                if (directionDot >= -0x800) {
                    if (targetFlagged == FALSE) {
                        targetDot = VEC_DotProduct(&directionToTargetKart, &directionToCandidateLink);
                        if (targetDot > bestTargetDot || bestCount == 0) {
                            bestTargetDot = targetDot;
                            nextLink = linkCursor->mLink->mLinks[linkIndex];
                            bestCount++;
                        }
                    } else {
                        targetDot = VEC_DotProduct(&directionToTargetKart, &directionToCandidateLink);
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
                        VEC_Subtract(openLinks[pairIndex]->mPoint, linkCursor->mLink->mPoint,
                                     &directionsToCandidates[pairIndex]);
                        if ((s64) directionsToCandidates[pairIndex].x * directionsToCandidates[pairIndex].x +
                                (s64) directionsToCandidates[pairIndex].y * directionsToCandidates[pairIndex].y +
                                (s64) directionsToCandidates[pairIndex].z * directionsToCandidates[pairIndex].z >=
                            0x10) {
                            Vec3NormalizeAndGetLengthUnchecked(&directionsToCandidates[pairIndex],
                                                               &directionsToCandidates[pairIndex]);
                        }
                    }
                    if (Vec3DotUnrounded(&directionsToCandidates[0], direction) <
                        Vec3DotUnrounded(&directionsToCandidates[1], direction)) {
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
                                VEC_Subtract(neighborLink->mLinks[neighborLinkIndex]->mPoint, neighborLink->mPoint,
                                             &neighborLinkDirection);
                                if ((s64) neighborLinkDirection.x * (s64) neighborLinkDirection.x +
                                        (s64) neighborLinkDirection.y * (s64) neighborLinkDirection.y +
                                        (s64) neighborLinkDirection.z * (s64) neighborLinkDirection.z >=
                                    0x10) {
                                    Vec3NormalizeAndGetLengthUnchecked(&neighborLinkDirection, &neighborLinkDirection);
                                }
                                break;
                            }
                        }
                        directionDot = Vec3DotUnrounded(&neighborLinkDirection, direction);
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
    VEC_Subtract(linkCursor->mLink->mPoint, linkCursor->mPreviousLink->mPoint, &linkCursor->mDirection);
    if ((s64) linkCursor->mDirection.x * linkCursor->mDirection.x +
            (s64) linkCursor->mDirection.y * linkCursor->mDirection.y +
            (s64) linkCursor->mDirection.z * linkCursor->mDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&linkCursor->mDirection, &linkCursor->mDirection);
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
    VEC_Subtract(linkCursor->mLink->mPoint, linkCursor->mPreviousLink->mPoint, &linkCursor->mDirection);
    if ((s64) linkCursor->mDirection.x * linkCursor->mDirection.x +
            (s64) linkCursor->mDirection.y * linkCursor->mDirection.y +
            (s64) linkCursor->mDirection.z * linkCursor->mDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&linkCursor->mDirection, &linkCursor->mDirection);
    }
}

void SetupPointLinkCursor(PointLinkCursor *cursor, u32 kartIndex, struct RacePointLink *link) {
    cursor->mDirection = gPointLinkVec3Zero;
    cursor->mPreviousLink = link;
    cursor->mLink = cursor->mPreviousLink->mNextLinks[0];
    VEC_Subtract(cursor->mLink->mPoint, cursor->mPreviousLink->mPoint, &cursor->mDirection);
    Vec3NormalizeAndGetLengthUnchecked(&cursor->mDirection, &cursor->mDirection);
    cursor->mRequestedLink = NULL;
    cursor->mUnk_18 = 0;
    cursor->mKartIndex = kartIndex;
}
