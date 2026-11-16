#pragma once

#include "types.h"

typedef struct KartAiItemUseEntry KartAiItemUseEntry;
typedef struct KartAiItemUse KartAiItemUse;

struct CourseMapCamera;
struct KartAiItemUse;
struct KartAi;
struct KartAiItemUseEntry;

// Four points, a parameter (0x1000 = one segment) and two words at 0x34 and 0x38. The camera position is blended from
// the four points.
typedef struct PosCurve {
    /* 00 */ Vec3 mPoints[4];
    /* 30 */ s32 mParam;
    /* 34 */ s32 field34;
    /* 38 */ s32 field38;
} PosCurve;

struct KartAi;

extern void (*data_0217ae3c)(KartAiItemUse *a, struct KartAi *b);
extern void (*data_0217ae40)(KartAiItemUse *a, struct KartAi *b);
extern void (*data_0217ae44)(KartAiItemUse *a, struct KartAi *b);
extern void (*data_0217ae48)(KartAiItemUse *a, struct KartAi *b);

typedef struct KartAiItemUse KartAiItemUse;

struct KartAiRaceSpeedLimit;
struct KartAi;

extern KartAiItemUseEntry enit_sDragItemParams[];
extern KartAiItemUseEntry enit_sSlotItemParamsMedium[];
extern KartAiItemUseEntry enit_sSlotItemParamsHard[];
extern KartAiItemUseEntry enit_sSlotItemParamsEasy[];

// Writes to a the point of the curve b at parameter mParam (0 to 0x1000): the four control points of mPoints weighted
// by the uniform cubic B-spline basis.
void interpolateCubicSpline(Vec3 *point, PosCurve *posCurve);
// Adds d to the curve parameter (0x1000 = one segment); past 0x1000 it shifts the four control points on to the next
// point of the entry's group (clamped after the last) and writes the point on the curve to a. cam_updateCameRoutePos
// calls it for groups of four or more points.
void camr_updateRoute(Vec3 *point, PosCurve *posCurve, struct CourseMapCamera *mapCamera, s32 paramStep);
void camr_initRouteStatReversed(PosCurve *posCurve, struct CourseMapCamera *mapCamera);
// Restarts the curve a on the entry b: clears its parameter and counters and, when the entry's group has four or more
// points, loads the first four as its control points (nothing is loaded for fewer).
void camr_initRouteStat(PosCurve *posCurve, struct CourseMapCamera *mapCamera);
void enit_notifyDragItemChanged(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
s32 enit_updateDragItemTimeout(struct KartAiItemUse *itemUse);
void enit_beginDragItemTimeout(struct KartAiItemUse *itemUse, struct KartAiItemUseEntry *unusedEntry);
s32 enit_updateSlotItemTimeout(struct KartAiItemUse *itemUse);
void enit_beginSlotItemTimeout(struct KartAiItemUse *itemUse);
void enit_notifySlotItemChanged(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_updateForRace(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_update(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_init(KartAiItemUse *itemUse);
void enit_deployDragItemBackwards(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_deployDragItemForwards(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_deployDragItem(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_deploySlotItem(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_setupFunctions(void);
void func_0207c8d8(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0207c978(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_dragItemBananaBombUpdate(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_dragItemKouraGRUpdate(KartAiItemUse *itemUse, struct KartAi *kartAi);
unsigned int enit_dragItemDummyUpdate(unsigned int value);
void enit_slotItemTripleKinokoKinokoPUpdate(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_slotItemSingleKinokoUpdate(KartAiItemUse *itemUse, struct KartAi *kartAi);
void RequestItemBitsByKartRank(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRank(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByRankAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_slotItemSingleKouraRFBoxBombUpdateHard(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_slotItemSingleKouraGBananaUpdateMedium(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_slotItemSingleKouraGBananaUpdateHard(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enit_slotItemKouraWThunderStarKillerGessoTeresaIboxUpdate(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0207d5b8(KartAiItemUse *itemUse, struct KartAi *kartAi);
void enrb_updateForAwardStaffRoll(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
