#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine

// Row of the array at 0x00 of the object behind gCourseMap.
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
#include "Main/Race/data_020f36d8.h"
#include "Main/Sound/data_0210b000.h" // SoundDistanceSquaredChange

// Stack object of InitItemKouraWFromData: the two vectors Vec3NormalizeAndGetLengthUnchecked and
// QuaternionFromYAxisToVec3 write.
typedef struct DirectionQuaternion {
    /* 00 */ Vec3 mDirection;
    /* 0c */ Quaternion mQuaternion;
    /* 1c */ u8 mUnk_1c[4];
} DirectionQuaternion;

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
    /* 264 */ s32 mUnk_264;
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
    /* 284 */ s32 mUnk_284;
    /* 288 */ u16 mAngleStep;
    /* 28a */ u8 mUnk_28a[2];
    /* 28c */ Vec3 mPreviousDirection;
    /* 298 */ Vec3 mSmoothedDirectionDelta;
    /* 2a4 */ Vec3 mEasedDirection;
    /* 2b0 */ struct ModelEffect *mModelEffect;
    /* 2b4 */ MtxFx43 mUnk_2b4;
    /* 2e4 */ s32 mHitSpinsKart;
    /* 2e8 */ StateMachine mStateMachine;
    /* 2fc */ s32 mReverse;
    /* 300 */ SoundDistanceSquaredChange mSoundDistanceSquaredChange;
    /* 310 */ u8 mUnk_310[0xc];
} ItemKouraW;

typedef struct ItemKouraW ItemKouraW;

#include "Main/Item/item_object_throw.h"

#include "Main/Item/code_020f6be8.h"
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
void InitItems(void);
void StartCourseMapItemObjects(void);
// Takes an object of the given kind from its pool, reserves, starts and places it; returns 0 when the pool is full
// (mLimit - mReservedCount <= 0).
void *StartItemObjectOrZero(s32 kind, u16 kartIndex, void *pos, void *normal);
struct ItemObject *GetCollidedItemObject(u32 index);
s32 CollideKartWithItemObjects(Kart *kart);
void StartItemSlotForKart(s32 kartIndex, s32 forcedRowHandle, s32 shortSpin);
void DrawItems(void *unused);
// Per-frame item step: mode-5 sync, the object pools whose mUnk_14 is set, every kart's record, the item timers, two
// map-object steps
void UpdateItems(void);
void ReleaseItemsAtFinish(void);
BOOL TryReleaseItemObjectsForItemInfo(s32 itemInfoIndex);
BOOL ReplaceUnavailableItem(s32 *itemInfoIndexPointer);
BOOL IsItemInfoObjectCountFree(s32 itemInfoIndex);
void SetupItemKouraWKind(void);
Vec3 *GetItemKouraWState7Info(ItemKouraW *item, s32 *stateFrames, s32 *scaleRatio);
BOOL IsItemKouraWState7(ItemKouraW *item);
s32 RequestItemKouraWState7(ItemKouraW *item);
void DrawItemKouraW(ItemKouraW *item, Vec3 *viewAxis, s32 model);
void DrawItemKouraWModel(ItemKouraW *item, Vec3 *viewAxis, s32 model);
void InitItemKouraWFromData(ItemKouraW *item);
void *CopyItemKouraWData(void *cursor, ItemKouraW *item, void *toData);
void UpdateItemKouraWState7(ItemKouraW *item);
void EnterItemKouraWState7(ItemKouraW *item);
void UpdateItemKouraWState6(ItemKouraW *item);
void EnterItemKouraWState6(ItemKouraW *item);
void UpdateItemKouraWState5(ItemKouraW *item);
void EnterItemKouraWState5(ItemKouraW *item);
void UpdateItemKouraWState4(ItemKouraW *item);
void EnterItemKouraWState4(ItemKouraW *item);
void UpdateItemKouraWState2(ItemKouraW *item);
void UpdateItemKouraWState3(ItemKouraW *item);
void EnterItemKouraWState3(ItemKouraW *item);
void UpdateItemKouraWState1(ItemKouraW *item);
void UpdateItemKouraWState0(ItemKouraW *item);
void AdvanceItemKouraW(ItemKouraW *item);
void UpdateItemKouraWOrientation(ItemKouraW *item, Vec3 *direction, s32 followDelta, Vec3 *normal);
void UpdateItemKouraWDrawPos(ItemKouraW *item);
s32 InitItemKouraW(ItemInUse *itemInUse, ItemKouraW *item);
void SetItemKouraWKartItemsAndStateIfNone(ItemKouraW *item, s32 kartIndex);
void InitItemKouraWCommon(ItemKouraW *item);
void ResetItemKouraW(ItemKouraW *item);
void MarkItemInUseAsActiveItem(ItemInUse *itemInUse);

extern Vec3 gKouraWVec3UnitY;
extern Vec3 gCourseMapItemVec3UnitY;

extern char gKouraWNsbmdName[];

extern char gKouraWNsbtxName[];
extern StateCallbacks gItemKouraWStateTable[8];
extern volatile s32 gKouraWState7MaxRadiusSquared;
extern Nsbmd *gKouraW;
extern s32 gKouraWState7ScaleStep;
extern struct ItemObject **gCollidedItemObjects;
extern s32 gKouraWState7ScaleLimit;
extern s32 gKouraWState7InverseLimit;
