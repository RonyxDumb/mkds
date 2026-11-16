#pragma once

#include "types.h"
#include "Main/Race/race_setup_block.h" // MinuteSecondMillisecondTime
#include "touch_panel_sampling.h"
#include "Main/Kart/point_link_cursor_advance.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/MapObjects/map_object_kind_update_list.h" // MapObjectList, MapObjectKindData

// Values of Sman.mState: at rest, the top part goes up and down, wait with the top low, both parts come back.
enum {
    SMAN_STATE_REST,
    SMAN_STATE_TOP_FLIGHT,
    SMAN_STATE_WAIT_LOW,
    SMAN_STATE_COME_BACK,
};

// A Sman map object in two parts (top and bottom models): a hit sends the top up and down, then both parts come back.
typedef struct Sman {
    /* 00 */ MapObject mMapObject;
    // The angle changes only while this is non-zero (states 0 and 3).
    /* a0 */ s32 mAngleZEnabled;
    /* a4 */ s32 mAngleZ;
    /* a8 */ s32 mAngleZPerFrame;
    // Counted in states 2 and 3 only.
    /* ac */ s32 mStateFrames;
    /* b0 */ s32 mTopRiseProgress;
    /* b4 */ s32 mBottomScale;
    /* b8 */ s32 mTopHeight;
    /* bc */ s32 mTopHeightPerFrame;
    /* c0 */ s32 mTopStartHeight;
    /* c4 */ s32 mTopLowHeight;
    // State of UpdateSman: 0 at rest, 1 top goes up and down, 2 waits, 3 both parts come back;
    // CollideKartWithSman and CollideItemObjectWithSman set 1.
    /* c8 */ s32 mState;
} Sman;

// The list of Sman map objects: the mSmans array and mSmanCount.
typedef struct SmanList {
    /* 00 */ Sman **mSmans;
    /* 04 */ u16 mSmanCount;
} SmanList;

void SetupBattleItemEntries(void);
BOOL AdvanceKartKillerEndCount(KartKillerCursor *kartKillerCursor);
void TurnKartKillerTowardPointLink(KartKillerCursor *kartKillerCursor);
void AdvanceKartKillerAlongPointLinks(KartKillerCursor *kartKillerCursor);
BOOL AdvanceKartKillerCursor(KartKillerCursor *kartKillerCursor);
void ResetKartKillerCursorTo(KartKillerCursor *kartKillerCursor, RacePointLink *link);
void SetupKartKillerCursor(KartKillerCursor *kartKillerCursor, u32 kartIndex);
BOOL IsTimeLessThanStaffGhostTime(u32 entryNumber, MinuteSecondMillisecondTime *time);
void LoadStaffGhostTime(void *heap);
BOOL IsAllGrandPrixRecordsTopRank(void);
// Values GetStaffRollKindAfterGp returns.
#define STAFF_ROLL_AFTER_GP_NONE 0
#define STAFF_ROLL_AFTER_GP_NORMAL 1
#define STAFF_ROLL_AFTER_GP_TRUE 2
s32 GetStaffRollKindAfterGp(void);
u32 SetSecretMessageFlagsFromCups3And7(void);
u32 SetSecretMessageFlagsPerEngineClass(void);
u32 SetSecretMessageFlags(void);
u32 SetSecretMessageFlagsWrapper(void);
u32 SetAndWriteSecretMessageFlags(void);
MapObjectList *CreateSmanUpdateList(void);
MapObjectList *CreateSmanBottomDrawList(void);
MapObjectList *CreateSmanTopDrawList(void);
MapObjectKindData *CreateSmanKindData(void);
void UpdateSman(void *mapObjectList, Sman *sman); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitSmanObjects(SmanList *smanList);
void DrawSmanBottom(void *mapObjectList, Sman *sman);
void SetupDrawSmanBottom(void *mapObjectList);
void CreateSmanBottom(void *mapObjectList);
void DrawSmanTop(void *mapObjectList, Sman *sman);
void SetupDrawSmanTop(void *mapObjectList);
void CreateSmanTop(void *mapObjectList);

extern const KartAiItemUseEntry gBattleNormalHeldItemEntries[18];
extern const KartAiItemUseEntry gBattleEasyHeldItemEntries[18];
extern const KartAiItemUseEntry gBattleNormalItemInUseEntries[14];
extern const KartAiItemUseEntry gBattleHardItemInUseEntries[14];
extern const KartAiItemUseEntry gBattleHardHeldItemEntries[18];
extern const KartAiItemUseEntry gBattleEasyItemInUseEntries[14];
extern s32 *gStaffGhostTime;

extern const KartAiItemUseEntry *gBattleHeldItemEntries;
extern void (*gUseItemNotCircleKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
extern void (*gUseItemCircleKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
extern void (*gThrowItemNotCircleKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
// Particle effect ids StartKartWaterSplashEffects starts with a kind 2 object; -1 marks an unused entry.
extern const KartAiItemUseEntry *gBattleItemInUseEntries;
extern void (*gThrowItemCircleKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
extern void (*gThrowItemNotTrailKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
extern void (*gThrowItemTrailKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);

// The killer kart of the staff roll: its forward speed, the frames of contact that reset the end count timer hold and
// the end count it ends at.
#define KART_KILLER_STAFF_FORWARD_SPEED 0xa800
#define KART_KILLER_END_HOLD_FRAMES 5
#define KART_KILLER_END_COUNT_FRAMES 0x78
