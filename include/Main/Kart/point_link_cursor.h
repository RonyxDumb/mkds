#pragma once

#include "types.h"

typedef struct KartAiItemUseEntry KartAiItemUseEntry;
typedef struct KartAiItemUse KartAiItemUse;

struct CourseMapCamera;
struct KartAiItemUse;
struct KartAi;
struct Kart;
struct PointLinkCursor;
struct KartAiItemUseEntry;

// Four points, a parameter (0x1000 = one segment) and two words at 0x34 and 0x38. The camera position is blended from
// the four points.
typedef struct PosCurve {
    /* 00 */ Vec3 mPoints[4];
    /* 30 */ s32 mParam;
    /* 34 */ s32 mEntryIndex;
    /* 38 */ s32 mUnk_38;
} PosCurve;
extern const s32 gKartAiRaceStartBoostRandomLimitsIndex0[9];
extern const s32 gKartAiRaceStartBoostRandomLimitsIndex1[9];
extern const s32 gKartAiRaceStartBoostRandomLimitsIndex2[9];
extern const s32 gKartAiDriftChargeRandomLimitsIndex2[9];
extern const s32 gKartAiRaceStartHeadingSwingRandomLimitsIndex0[9];
extern const s32 gKartAiRaceStartHeadingSwingRandomLimitsIndex1[9];
extern const s32 gKartAiDriftChargeRandomLimitsIndex1[9];
extern const s32 gKartAiDriftStartRandomLimitsIndex0[9];
extern const s32 gKartAiDriftStartRandomLimitsIndex1[9];
extern const s32 gKartAiDriftStartRandomLimitsIndex2[9];
extern const s32 gKartAiDriftChargeRandomLimitsIndex0[9];
extern const s32 gKartAiRaceStartHeadingSwingRandomLimitsIndex2[9];
extern const s32 *gKartAiVelocityFactorScale;
extern const s32 *gKartAiRaceStartHeadingSwingRandomLimits;
extern void (*gAdvanceKartAiPointLinkCursor)(struct PointLinkCursor *p);
extern void (*gUseItemWhenCircleKindCallback)(KartAiItemUse *a, struct KartAi *b);
extern void (*gUseItemNotTrailKindCallback)(KartAiItemUse *a, struct KartAi *b);
extern void (*gUseItemTrailKindCallback)(KartAiItemUse *a, struct KartAi *b);
extern const s32 *gKartAiDriftChargeRandomLimits;
extern const struct KartAiItemUseEntry *gCurrentHeldItemEntries;
extern void (*gUseItemWhenNotCircleKindCallback)(KartAiItemUse *a, struct KartAi *b);
extern const struct KartAiItemUseEntry *gCurrentItemInUseEntries;
extern const s32 *gKartAiDriftStartRandomLimits;
extern const s32 *gKartAiGapLimitsByRank;
extern const s32 *gKartAiRaceStartBoostRandomLimits;
extern void (*gSetKartAiLinkPos)(struct KartAi *p, struct PointLinkCursor *q, struct Kart *r);

static inline Vec3 *GetPosCurvePoint(PosCurve *posCurve, u16 pointIndex) {
    return &posCurve->mPoints[pointIndex];
}

struct KartAiRaceSpeedLimit;

extern const KartAiItemUseEntry gRaceItemInUseEntries[14];
extern const KartAiItemUseEntry gRaceNormalHeldItemEntries[18];
extern const KartAiItemUseEntry gRaceHardHeldItemEntries[18];
extern const KartAiItemUseEntry gRaceEasyHeldItemEntries[18];

// Writes to a the point of the curve b at parameter mParam (0 to 0x1000): the four control points of mPoints weighted
// by the uniform cubic B-spline basis.
void ComputePosCurvePoint(Vec3 *point, PosCurve *posCurve);
// Adds d to the curve parameter (0x1000 = one segment); past 0x1000 it shifts the four control points on to the next
// point of the entry's group (clamped after the last) and writes the point on the curve to a. UpdateCameraPosCurve
// calls it for groups of four or more points.
void UpdatePosCurve(Vec3 *point, PosCurve *posCurve, struct CourseMapCamera *mapCamera, s32 paramStep);
void SetupReversePosCurve(PosCurve *posCurve, struct CourseMapCamera *mapCamera);
// Restarts the curve a on the entry b: clears its parameter and counters and, when the entry's group has four or more
// points, loads the first four as its control points (nothing is loaded for fewer).
void SetupPosCurve(PosCurve *posCurve, struct CourseMapCamera *mapCamera);
void SetupItemInUseEntry(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
s32 DecrementItemInUseTimer(struct KartAiItemUse *itemUse);
void ResetItemInUseTimer(struct KartAiItemUse *itemUse, const struct KartAiItemUseEntry *unusedEntry);
s32 DecrementHeldItemTimer(struct KartAiItemUse *itemUse);
void ResetHeldItemTimer(struct KartAiItemUse *itemUse);
void SetupHeldItemEntry(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void AdvanceRaceItemBitRequests(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void AdvanceItemBitRequests(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void ClearKartAiItemUse(KartAiItemUse *itemUse);
void UseItemBehindAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemForwardAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAndResetHeldTimer(KartAiItemUse *itemUse, struct KartAi *kartAi);
void SetupRaceItemEntries(void);
void UseItemByRankAfterEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRankAfterEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterInUseByTrailKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterInUseByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
void RaceItemInUseNop(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemIfTurnUnder20ResetHeldTimer(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterHeldIfTurnUnder20(KartAiItemUse *itemUse, struct KartAi *kartAi);
void RequestItemBitsByKartRank(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRank(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByRankAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRankAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByRankOrEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRankOrEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void TrailOrCircleUseItemAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void AdvanceKartAiTurnSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);

void ResetAwardMissionRunKartAiSpeedLimit(struct KartAiRaceSpeedLimit *p0, struct KartAi *kartAi);

struct Kart;
struct RacePointLink;

void InitKartAiRaceSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
u16 PickKartAiRaceStartBoost(s32 pickLast);
void AdvanceKartAiSpeedLimitByRank(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi,
                                   s32 speedLimitCap);
void AdvanceRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
void PickKartAiRaceStart(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
void ResetRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
u32 SetupRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
void InitKartAiTables(void);
void AdvanceStaffRollKartAi(struct KartAi *kartAi);
void SetupStaffRollKartAi(struct KartAi *kartAi, struct Kart *kart, s32 unusedValue);
void AdvanceAwardMissionRunKartAi(struct KartAi *kartAi);
void ResetAwardMissionRunKartAi(struct KartAi *kartAi, struct RacePointLink *pointLink);
void SetupAwardMissionRunKartAi(struct KartAi *kartAi, struct Kart *kart, s32 unusedValue);

unsigned int GetTargetAhead(struct KartAi *p0);
