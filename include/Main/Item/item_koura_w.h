#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine

// One map object row of the course map: position, rotation, scale, kind, group, settings and time attack flags.
typedef struct CourseMapRow {
    /* 00 */ Vec3 mPosition;
    /* 0c */ Vec3 mRotationDegrees;
    /* 18 */ Vec3 mScale;
    /* 24 */ u16 mKind;
    /* 26 */ s16 mGroupIndex;
    /* 28 */ s16 mSettings[8];
    /* 38 */ u16 mTimeAttackFlags;
    /* 3a */ u8 mUnk_3a[2];
} CourseMapRow;

#include "Main/Item/item_link_following.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Sound/sound_distance_squared_change.h" // SoundDistanceSquaredChange

// Values of ItemKouraW's state machine states, in the order of gItemKouraWStateTable.
enum {
    ITEM_KOURA_W_STATE_STRAIGHT,
    ITEM_KOURA_W_STATE_PICK_TARGET,
    ITEM_KOURA_W_STATE_FOLLOW_LINK,
    ITEM_KOURA_W_STATE_STEER_TO_TARGET,
    ITEM_KOURA_W_STATE_CIRCLE_TARGET,
    ITEM_KOURA_W_STATE_RISE,
    ITEM_KOURA_W_STATE_FALL,
    ITEM_KOURA_W_STATE_BURST,
    ITEM_KOURA_W_STATE_COUNT,
};

// Stack object of InitItemKouraWFromData: the two vectors Vector3_MaybeNormalize and
// QuaternionFromYAxisToVec3 write.
typedef struct DirectionQuaternion {
    /* 00 */ Vec3 mDirection;
    /* 0c */ Quaternion mQuaternion;
    /* 1c */ u8 mUnk_1c[4];
} DirectionQuaternion;

// Sound ids of ItemKouraW.mSoundId: the one set at reset, and the one the entry kart's shell takes when it starts
// to steer to its target.
#define ITEM_KOURA_W_SOUND_ID_DEFAULT 0xdc
#define ITEM_KOURA_W_SOUND_ID_ENTRY_STEERING 0xdd
// ItemKouraW.mSpeed at reset, the speed the following and steering states move it toward (by the step each frame),
// and its value when the rise starts.
#define ITEM_KOURA_W_START_SPEED 0x1a000
#define ITEM_KOURA_W_CRUISE_SPEED 0xd000
#define ITEM_KOURA_W_SPEED_STEP 0xccd
#define ITEM_KOURA_W_RISE_START_SPEED 0x3000
// ItemKouraW.mLift at reset, at the start of the rise and fall, and where the rise ends.
#define ITEM_KOURA_W_START_LIFT 0x32000
#define ITEM_KOURA_W_HOVER_LIFT 0x28000
#define ITEM_KOURA_W_RISE_LIFT_LIMIT 0x2d000
// ItemKouraW.mAngleStep when the circling starts, and the circle angles (65536 is a full turn): the first half turn
// and the end of the part where the shell follows the course normal.
#define ITEM_KOURA_W_CIRCLE_START_ANGLE_STEP 0x3e8
#define ITEM_KOURA_W_CIRCLE_HALF_ANGLE 0x8000
#define ITEM_KOURA_W_CIRCLE_NORMAL_END_ANGLE 0x11f40
// State frame of the pick-target state at which the shell starts its position strip, and the state frame after which
// it stops looking for a target.
#define ITEM_KOURA_W_POS_STRIP_FRAME 8
#define ITEM_KOURA_W_PICK_TARGET_LIMIT_FRAMES 0xa8c

// Object of item kind 5, element of gItemPools[5].
typedef struct ItemKouraW {
    /* 000 */ LinkFollowingItemObject mLinkFollowingItemObject;
    /* 228 */ struct KartItems *mKartItems;
    /* 22c */ Vec3 mKartForward;
    /* 238 */ Vec3 mToTarget;
    /* 244 */ Vec3 mKartDrawPos;
    /* 250 */ Vec3 mAnglePointOffset;
    /* 25c */ s32 mAngle;
    /* 260 */ s32 mLift;
    /* 264 */ s32 mBobAmplitudeOrGain;
    /* 268 */ u16 mDrawOffsetAngle;
    /* 26a */ u8 mUnk_26a[2];
    /* 26c */ struct PosStrip *mPosStrip;
    /* 270 */ s32 mSoundId;
    /* 274 */ u16 mRank;
    /* 276 */ u16 mRankKartIndex;
    /* 278 */ s32 mRankTargetSkipped;
    /* 27c */ s32 mSpeed;
    /* 280 */ u16 mKartMask;
    /* 282 */ u8 mUnk_282[2];
    /* 284 */ s32 mRadiusOrEaseFactor;
    /* 288 */ u16 mAngleStep;
    /* 28a */ u8 mUnk_28a[2];
    /* 28c */ Vec3 mPreviousDirection;
    /* 298 */ Vec3 mSmoothedDirectionDelta;
    /* 2a4 */ Vec3 mEasedDirection;
    /* 2b0 */ struct ModelEffect *mModelEffect;
    /* 2b4 */ MtxFx43 mMatrix;
    /* 2e4 */ s32 mHitSpinsKart;
    /* 2e8 */ StateMachine mStateMachine;
    /* 2fc */ s32 mReverse;
    /* 300 */ SoundDistanceSquaredChange mSoundDistanceSquaredChange;
} ItemKouraW;

typedef struct ItemKouraW ItemKouraW;

#include "Main/Item/item_object_throw.h"

#include "Main/Item/item_object_fade_out.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Kart/kart_drift.h"

void CreateItemObjectCollisionSlotExact(ItemObject *item);
void CreateItemObjectCollisionSlot(ItemObject *item);
BOOL EaseItemObjectScale(ItemObject *item);
BOOL SwingItemObjectScale(ItemObject *item);
void SetItemObjectScaleByRatios(ItemObject *objectParam, s32 xRatio, s32 yRatio);
void RefreshItemObjectScaleExact(ItemObject *item);
void RefreshItemObjectScale(ItemObject *item);
s32 GrowItemObjectScale(ItemObject *item, s32 limit, s32 step);
s32 GetItemDataSize(s32 itemKind, s32 messageKind);
void MaybeLoadSlotListAndRacerPrs_from_thumb(void);
void StartCourseMapItemObjects(void);
// Takes an object of the given kind from its pool, reserves, starts and places it; returns 0 when the pool is full
// (mLimit - mReservedCount <= 0).
void *StartItemObjectOrZero(s32 kind, u16 kartIndex, void *pos, void *normal);
struct ItemObject *GetCollidedItemObject(u32 index);
s32 CollideKartWithItemObjects(Kart *kart);
void StartItemSlotForKart(s32 kartIndex, s32 forcedRowHandle, s32 shortSpin);
void DrawItems(void *unused);
// Per-frame item step: mode-5 sync, the object pools whose mActiveCount is not 0, every kart's record, the item timers,
// two map-object steps
void UpdateItems(void);
void ReleaseItemsAtFinish(void);
BOOL TryReleaseItemObjectsForItemInfo(s32 itemInfoIndex);
BOOL ReplaceUnavailableItem(s32 *itemInfoIndexPointer);
BOOL IsItemInfoObjectCountFree(s32 itemInfoIndex);
void SetupItemKouraWKind(void);
Vec3 *GetItemKouraWBurstInfo(ItemKouraW *item, s32 *stateFrames, s32 *scaleRatio);
BOOL IsItemKouraWBurst(ItemKouraW *item);
s32 RequestItemKouraWBurst(ItemKouraW *item);
void DrawItemKouraW(ItemKouraW *item, Vec3 *viewAxis, s32 model);
void DrawItemKouraWModel(ItemKouraW *item, Vec3 *viewAxis, s32 model);
void InitItemKouraWFromData(ItemKouraW *item);
void *CopyItemKouraWData(void *cursor, ItemKouraW *item, void *toData);
void UpdateItemKouraWBurst(void *stateObject);
void EnterItemKouraWBurst(void *stateObject);
void UpdateItemKouraWFall(void *stateObject);
void EnterItemKouraWFall(void *stateObject);
void UpdateItemKouraWRise(void *stateObject);
void EnterItemKouraWRise(void *stateObject);
void UpdateItemKouraWCircleTarget(void *stateObject);
void EnterItemKouraWCircleTarget(void *stateObject);
void UpdateItemKouraWFollowLink(void *stateObject);
void UpdateItemKouraWSteerToTarget(void *stateObject);
void EnterItemKouraWSteerToTarget(void *stateObject);
void UpdateItemKouraWPickTarget(void *stateObject);
void UpdateItemKouraWStraight(void *stateObject);
void AdvanceItemKouraW(ItemKouraW *item);
void UpdateItemKouraWOrientation(ItemKouraW *item, Vec3 *direction, s32 followDelta, Vec3 *normal);
void UpdateItemKouraWDrawPos(ItemKouraW *item);
s32 InitItemKouraW(ItemInUse *itemInUse, ItemKouraW *item);
void SetItemKouraWKartItemsAndStateIfNone(ItemKouraW *item, s32 kartIndex);
void InitItemKouraWCommon(ItemKouraW *item);
void ResetItemKouraW(ItemKouraW *item);
void MarkItemInUseAsActiveItem(ItemInUse *itemInUse);

extern Vec3 gKouraWVec3UnitY;

extern StateCallbacks gItemKouraWStateTable[8];
extern volatile s32 gKouraWBurstMaxRadiusSquared;
extern Nsbmd *gKouraW;
extern s32 gKouraWBurstScaleStep;
extern struct ItemObject **gCollidedItemObjects;
extern s32 gKouraWBurstScaleLimit;
extern s32 gKouraWBurstInverseLimit;

extern const u16 gItemObjectNoOwnerBit;
extern const ItemInfo gItemInfoKouraW;
extern const ItemKind gItemKindKouraW;
