#include "Main/Unknown/code_0207ffa4.h"

#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020800f4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020808d4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02080adc.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_02080cc0.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02077bc0.h"

void rptc_startSlipstreamBeginEffect(Kart *kart) {
    Unk0201ca6c *effect;

    if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    if (rptc_sDriverSlipstreamBeginEmitters[kart->mIndex] != NULL) {
        return;
    }
    rptc_sDriverSlipstreamBeginEmitters[kart->mIndex] = ptcm_createEmitter(0x80, &rptc_sEmitterPos);
    effect = rptc_sDriverSlipstreamBeginEmitters[kart->mIndex];
    effect->field98_24 = kart->mIndex;
    effect->field94 = 0;
    effect->field90 = AdvanceKartAheadEffect;
}

void rptc_stopSlipstreamBeginEffect(Kart *kart) {
    Unk0201ca6c *effect = rptc_sDriverSlipstreamBeginEmitters[kart->mIndex];

    if (effect == NULL) {
        return;
    }
    effect->field98_16 = 0;
    effect->field98_8 = 3;
    effect->field90 = AdvanceKartAheadEffectWithLimit;
    rptc_sDriverSlipstreamBeginEmitters[kart->mIndex] = NULL;
}

void rptc_stopSlipstreamBeginEffectDirect(Kart *kart) {
    if (rptc_sDriverSlipstreamBeginEmitters[kart->mIndex] == NULL) {
        return;
    }
    ptcm_killEmitterDirect(rptc_sDriverSlipstreamBeginEmitters[kart->mIndex]);
    rptc_sDriverSlipstreamBeginEmitters[kart->mIndex] = NULL;
}

void rptc_startSlipstreamEffect(Kart *kart) {
    Unk0201ca6c *effect;

    if (rptc_sDriverSlipstreamEmitters[kart->mIndex] != NULL) {
        return;
    }
    rptc_sDriverSlipstreamEmitters[kart->mIndex] = ptcm_createEmitter(0x7f, &rptc_sEmitterPos);
    effect = rptc_sDriverSlipstreamEmitters[kart->mIndex];
    effect->field98_24 = kart->mIndex;
    effect->field94 = (void *) 1;
    effect->field90 = AdvanceKartAheadEffect;
}

void rptc_stopSlipstreamEffect(Kart *kart) {
    Unk0201ca6c *effect = rptc_sDriverSlipstreamEmitters[kart->mIndex];

    if (effect == NULL) {
        return;
    }
    effect->field98_16 = 0;
    effect->field98_8 = 5;
    effect->field90 = AdvanceKartAheadEffectWithLimit;
    rptc_sDriverSlipstreamEmitters[kart->mIndex] = NULL;
}

void rptc_stopSlipstreamEffectDirect(Kart *kart) {
    if (rptc_sDriverSlipstreamEmitters[kart->mIndex] == NULL) {
        return;
    }
    ptcm_killEmitterDirect(rptc_sDriverSlipstreamEmitters[kart->mIndex]);
    rptc_sDriverSlipstreamEmitters[kart->mIndex] = NULL;
}

void func_02080e88(Unk0201ca6c *effect, Kart *kart) {
    effect->field6C = (s16) kart->mScale.z;
}

BOOL mepo_isPointInMepo(LinkCursor *linkCursor, Vec3 *position) {
    Vec3 offset;
    s32 radius;
    BOOL result = FALSE;

    radius = linkCursor->mLink->field24;
    VEC_Subtract(linkCursor->mLink->field20, position, &offset);
    offset.y = result;
    if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z < (s64) radius * radius) {
        result = TRUE;
    }
    return result;
}

BOOL mepo_2080DBC(LinkCursor *linkCursor, Vec3 *position) {
    Vec3 offset;
    Vec3 *linkPosition = linkCursor->mLink->field20;
    BOOL result = FALSE;

    if (linkCursor->mDirection.x != 0 || linkCursor->mDirection.y != 0 || linkCursor->mDirection.z != 0) {
        VEC_Subtract(position, linkPosition, &offset);
        if (vec_dotProduct(&linkCursor->mDirection, &offset) > 0) {
            result = TRUE;
        }
    }
    return result;
}

void epoi_2080D34(Unk02080d34 *racePointLinkCursor, u16 kartIndex) {
    racePointLinkCursor->mLinkCursor.mLink = gMapData->mRaceRoute0FirstLink;
    racePointLinkCursor->mLinkCursor.mPreviousLink = racePointLinkCursor->mLinkCursor.mLink->fieldC;
    racePointLinkCursor->mLinkCursor.mDirection = data_021557ec;
    VEC_Subtract(racePointLinkCursor->mLinkCursor.mLink->field18,
                 racePointLinkCursor->mLinkCursor.mPreviousLink->field18, &racePointLinkCursor->mLinkCursor.mDirection);
    vec_normalize(&racePointLinkCursor->mLinkCursor.mDirection,
                                       &racePointLinkCursor->mLinkCursor.mDirection);
    racePointLinkCursor->mLinkCursor.mRequestedLink = NULL;
    racePointLinkCursor->mLinkCursor.field18 = FALSE;
    racePointLinkCursor->mKartIndex = kartIndex;
    racePointLinkCursor->field1E = 0;
}

void epoi_2080CD0(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mLink = pointLink;
    linkCursor->mPreviousLink = linkCursor->mLink->fieldC;
    linkCursor->mRequestedLink = NULL;
    linkCursor->field18 = FALSE;
    linkCursor->mDirection = data_021557ec;
    VEC_Subtract(linkCursor->mLink->field18, linkCursor->mPreviousLink->field18, &linkCursor->mDirection);
    vec_normalize(&linkCursor->mDirection, &linkCursor->mDirection);
}

s16 epoi_getDriftSetting(LinkCursor *linkCursor) {
    return *(s16 *) linkCursor->mLink->field20;
}

BOOL IsWithinPointLinkDistance(PointLinkCursor *pointLinkCursor, Vec3 *position) {
    Vec3 offset;
    s32 radius;
    BOOL result;
    Unk02080b1c_00 *link = pointLinkCursor->mLink;

    result = FALSE;
    radius = link->field1C;
    VEC_Subtract(link->field18, position, &offset);
    offset.y = result;
    if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z < (s64) radius * radius) {
        result = TRUE;
    }
    return result;
}

BOOL IsPastPointLink(PointLinkCursor *pointLinkCursor, Vec3 *position) {
    Vec3 offset;
    BOOL result;
    Vec3 *linkPosition = pointLinkCursor->mLink->field18;

    result = FALSE;
    if (pointLinkCursor->mDirection.x != 0 || pointLinkCursor->mDirection.y != 0 ||
        pointLinkCursor->mDirection.z != 0) {
        VEC_Subtract(position, linkPosition, &offset);
        if (vec_dotProduct(&pointLinkCursor->mDirection, &offset) > 0) {
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

    if (!(driver_getById(pointLinkCursor->mKartIndex)->field4C & 0x10000000)) {
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
    pointLinkCursor->mLink = pointLinkCursor->mLink->field0[nextIndex];
    VEC_Subtract(pointLinkCursor->mLink->field18, pointLinkCursor->mPreviousLink->field18,
                 &pointLinkCursor->mDirection);
    vec_normalize(&pointLinkCursor->mDirection, &pointLinkCursor->mDirection);
}

void AdvancePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mPreviousLink = linkCursor->mLink;
    linkCursor->mLink = pointLink;
    VEC_Subtract(linkCursor->mLink->field18, linkCursor->mPreviousLink->field18, &linkCursor->mDirection);
    vec_normalize(&linkCursor->mDirection, &linkCursor->mDirection);
}

void SetRequestedLinkToPreviousIfNone(LinkCursor *linkCursor) {
    if (linkCursor->mRequestedLink == NULL) {
        linkCursor->mRequestedLink = linkCursor->mPreviousLink;
        linkCursor->field18 = FALSE;
    }
}

void ResetBattlePointLinkCursorNear(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 c) {
    PointLink *bestLink = NULL;
    u16 pointIndex;
    u16 candidateIndex;
    s32 slot;
    s32 bestDot;
    s32 d;
    PointLink *firstLink = gMapData->mFirstBattlePointLink;
    PointLink *nearestLinks[3] = {0, 0, 0};
    s32 nearestDistances[3];
    Vec3 offset;
    Vec3 directionToLink;

    nearestDistances[0] = nearestDistances[1] = nearestDistances[2] = 0xc8000;
    bestDot = -0x1000;
    for (pointIndex = 0; pointIndex < gMapData->mBattlePointCount; pointIndex++) {
        VEC_Subtract(&gMapData->mBattlePoints[pointIndex].mPos, position, &offset);
        d = VEC_Mag(&offset);
        if (d < 0xc8000) {
            for (slot = 0; slot < 3; slot++) {
                if (d < nearestDistances[slot]) {
                    nearestDistances[slot] = d;
                    nearestLinks[slot] = &firstLink[pointIndex];
                    break;
                }
            }
        }
    }
    for (candidateIndex = 0; candidateIndex < 3; candidateIndex++) {
        if (nearestLinks[candidateIndex] != NULL) {
            VEC_Subtract(nearestLinks[candidateIndex]->field20, position, &directionToLink);
            if ((s64) directionToLink.x * directionToLink.x + (s64) directionToLink.y * directionToLink.y +
                    (s64) directionToLink.z * directionToLink.z >=
                0x10) {
                vec_normalize(&directionToLink, &directionToLink);
            }
            d = vec_dotProduct(&directionToLink, direction);
            if (d >= bestDot) {
                bestLink = nearestLinks[candidateIndex];
                bestDot = d;
            }
        }
    }
    linkCursor->mLink = bestLink;
    linkCursor->mPreviousLink = bestLink;
    linkCursor->mDirection = data_021557ec;
    linkCursor->mRequestedLink = NULL;
    linkCursor->field18 = FALSE;
}

void ResetBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mPreviousLink = pointLink;
    linkCursor->mLink = linkCursor->mPreviousLink;
    linkCursor->mDirection = data_021557ec;
    linkCursor->mRequestedLink = NULL;
    linkCursor->field18 = FALSE;
}

void AdvanceBattlePointLinkCursor(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 kartIndex,
                                  MapObject *targetShine, s32 targetKartIndex) {
    s32 bestFallbackDot;
    PointLink *nextLink;
    s32 lowestTargetDot;
    PointLink *currentLink = linkCursor->mLink;
    u16 fallbackCount = 0;
    PointLink *candidateLinks[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    u16 n1;
    s32 bestTargetDot;
    Kart *kart;
    PointLink *neighborLink;
    s32 targetDot;
    u16 candidateCount;
    u16 chosenIndex;
    u16 pairIndex;
    u32 randomValue;
    BOOL v3;
    PointLink *fallbackLink;
    u16 n0;
    s32 directionDot;
    u16 linkIndex;
    u8 neighborLinkIndex;
    RandomState64 *kartAiRandom;
    u16 k;
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
        PointLink *v4[2] = {0, 0};

        candidateCount = 0;
        n1 = 0;
        n1 = n1;
        n0 = 0;
        if (targetShine != NULL) {
            k = 0;
            VEC_Subtract(&targetShine->mPos, &driver_getById(kartIndex)->mPos, &directionToTargetShine);
            if ((s64) directionToTargetShine.x * directionToTargetShine.x +
                    (s64) directionToTargetShine.y * directionToTargetShine.y +
                    (s64) directionToTargetShine.z * directionToTargetShine.z >=
                0x10) {
                vec_normalize(&directionToTargetShine, &directionToTargetShine);
            }
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink == ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex]) {
                    continue;
                }
                VEC_Subtract(linkCursor->mLink->mLinks[linkIndex]->field20, &driver_getById(kartIndex)->mPos,
                             &directionToLink);
                if ((s64) directionToLink.x * directionToLink.x + (s64) directionToLink.y * directionToLink.y +
                        (s64) directionToLink.z * directionToLink.z >=
                    0x10) {
                    vec_normalize(&directionToLink, &directionToLink);
                }
                directionDot = vec_dotProduct(&directionToLink, direction);
                if (directionDot >= -0x800) {
                    targetDot = VEC_DotProduct(&directionToTargetShine, &directionToLink);
                    if (targetDot > bestTargetDot || k == 0) {
                        bestTargetDot = targetDot;
                        k++;
                        nextLink = linkCursor->mLink->mLinks[linkIndex];
                    }
                } else if (directionDot >= bestFallbackDot || fallbackCount == 0) {
                    bestFallbackDot = directionDot;
                    fallbackLink = linkCursor->mLink->mLinks[linkIndex];
                    fallbackCount++;
                }
            }
        } else if (targetKartIndex != -1) {
            n1 = (u16) n1;
            if (driver_getById(targetKartIndex)->field4C & 0x40) {
                v3 = TRUE;
            } else {
                v3 = FALSE;
            }
            kart = driver_getById(kartIndex);
            VEC_Subtract(&driver_getById(targetKartIndex)->mPos, &kart->mPos, &directionToTargetKart);
            if ((s64) directionToTargetKart.x * directionToTargetKart.x +
                    (s64) directionToTargetKart.y * directionToTargetKart.y +
                    (s64) directionToTargetKart.z * directionToTargetKart.z >=
                0x10) {
                vec_normalize(&directionToTargetKart, &directionToTargetKart);
            }
            for (linkIndex = 0; linkIndex < linkCursor->mLink->mLinkCount; linkIndex++) {
                if (linkCursor->mPreviousLink == ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex]) {
                    continue;
                }
                VEC_Subtract(linkCursor->mLink->mLinks[linkIndex]->field20, &driver_getById(kartIndex)->mPos,
                             &directionToCandidateLink);
                if ((s64) directionToCandidateLink.x * directionToCandidateLink.x +
                        (s64) directionToCandidateLink.y * directionToCandidateLink.y +
                        (s64) directionToCandidateLink.z * directionToCandidateLink.z >=
                    0x10) {
                    vec_normalize(&directionToCandidateLink, &directionToCandidateLink);
                }
                directionDot = vec_dotProduct(&directionToCandidateLink, direction);
                if (directionDot >= -0x800) {
                    if (v3 == FALSE) {
                        targetDot = VEC_DotProduct(&directionToTargetKart, &directionToCandidateLink);
                        if (targetDot > bestTargetDot || n0 == 0) {
                            bestTargetDot = targetDot;
                            nextLink = linkCursor->mLink->mLinks[linkIndex];
                            n0++;
                        }
                    } else {
                        targetDot = VEC_DotProduct(&directionToTargetKart, &directionToCandidateLink);
                        if (targetDot < lowestTargetDot || n1 == 0) {
                            lowestTargetDot = targetDot;
                            nextLink = linkCursor->mLink->mLinks[linkIndex];
                            n1++;
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
                    !(linkCursor->mLink->field2E & (1 << (u8) linkIndex))) {
                    v4[n0] = ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex];
                    n0++;
                    n1 = 1;
                }
            }
            if (n1 != 0) {
                chosenIndex = 0;
                if (n0 > 1) {
                    for (pairIndex = 0; pairIndex < 2; pairIndex++) {
                        VEC_Subtract(v4[pairIndex]->field20, linkCursor->mLink->field20,
                                     &directionsToCandidates[pairIndex]);
                        if ((s64) directionsToCandidates[pairIndex].x * directionsToCandidates[pairIndex].x +
                                (s64) directionsToCandidates[pairIndex].y * directionsToCandidates[pairIndex].y +
                                (s64) directionsToCandidates[pairIndex].z * directionsToCandidates[pairIndex].z >=
                            0x10) {
                            vec_normalize(&directionsToCandidates[pairIndex],
                                                               &directionsToCandidates[pairIndex]);
                        }
                    }
                    if (vec_dotProduct(&directionsToCandidates[0], direction) <
                        vec_dotProduct(&directionsToCandidates[1], direction)) {
                        chosenIndex = 1;
                    }
                }
                candidateLinks[0] = v4[chosenIndex];
                candidateCount = 1;
            } else {
                for (linkIndex = 0; linkIndex < ((const PointLink *) linkCursor->mLink)->mLinkCount; linkIndex++) {
                    if (linkCursor->mPreviousLink != ((const LinkCursor *) linkCursor)->mLink->mLinks[linkIndex] &&
                        (linkCursor->mLink->field2E & (1 << (u8) linkIndex))) {
                        neighborLinkDirection = data_021557ec;
                        neighborLink = linkCursor->mLink->mLinks[linkIndex];
                        for (neighborLinkIndex = 0; neighborLinkIndex < neighborLink->mLinkCount; neighborLinkIndex++) {
                            if (!(neighborLink->field2E & (1 << neighborLinkIndex)) &&
                                ((const LinkCursor *) linkCursor)->mLink != neighborLink->mLinks[neighborLinkIndex]) {
                                VEC_Subtract(neighborLink->mLinks[neighborLinkIndex]->field20, neighborLink->field20,
                                             &neighborLinkDirection);
                                if ((s64) neighborLinkDirection.x * (s64) neighborLinkDirection.x +
                                        (s64) neighborLinkDirection.y * (s64) neighborLinkDirection.y +
                                        (s64) neighborLinkDirection.z * (s64) neighborLinkDirection.z >=
                                    0x10) {
                                    vec_normalize(&neighborLinkDirection, &neighborLinkDirection);
                                }
                                break;
                            }
                        }
                        directionDot = vec_dotProduct(&neighborLinkDirection, direction);
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
                    k = 0;
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
                    k = randomValue;
                }
                nextLink = candidateLinks[k];
            }
        }
    }
    linkCursor->mLink = nextLink;
    linkCursor->mPreviousLink = currentLink;
    linkCursor->mDirection = data_021557ec;
    VEC_Subtract(linkCursor->mLink->field20, linkCursor->mPreviousLink->field20, &linkCursor->mDirection);
    if ((s64) linkCursor->mDirection.x * linkCursor->mDirection.x +
            (s64) linkCursor->mDirection.y * linkCursor->mDirection.y +
            (s64) linkCursor->mDirection.z * linkCursor->mDirection.z >=
        0x10) {
        vec_normalize(&linkCursor->mDirection, &linkCursor->mDirection);
    }
}

s32 GetBattlePointLinkSpeedLimit(LinkCursor *linkCursor) {
    s32 result = 0;
    s16 unscaledSpeedLimit = *linkCursor->mLink->field28;

    if (unscaledSpeedLimit != 0) {
        result = ((s64) unscaledSpeedLimit * 0x28f5c) >> 12;
    }
    return result;
}

void AdvanceBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink) {
    linkCursor->mPreviousLink = linkCursor->mLink;
    linkCursor->mLink = pointLink;
    linkCursor->mDirection = data_021557ec;
    VEC_Subtract(linkCursor->mLink->field20, linkCursor->mPreviousLink->field20, &linkCursor->mDirection);
    if ((s64) linkCursor->mDirection.x * linkCursor->mDirection.x +
            (s64) linkCursor->mDirection.y * linkCursor->mDirection.y +
            (s64) linkCursor->mDirection.z * linkCursor->mDirection.z >=
        0x10) {
        vec_normalize(&linkCursor->mDirection, &linkCursor->mDirection);
    }
}

void SetupPointLinkCursor(PointLinkCursor *cursor, u32 kartIndex, Unk02080b1c_00 *link) {
    cursor->mDirection = data_021557ec;
    cursor->mPreviousLink = link;
    cursor->mLink = cursor->mPreviousLink->field0[0];
    VEC_Subtract(cursor->mLink->field18, cursor->mPreviousLink->field18, &cursor->mDirection);
    vec_normalize(&cursor->mDirection, &cursor->mDirection);
    cursor->field14 = 0;
    cursor->field18 = 0;
    cursor->mKartIndex = kartIndex;
}
