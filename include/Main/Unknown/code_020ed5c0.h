#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020846c0.h" // Nsbmd
#include "Main/Unknown/code_02087d0c.h" // ModelAnimation
#include "Main/Unknown/code_0207adf8.h" // ShadowModel
#include "Main/Unknown/code_0208ab98.h" // CourseColorBlend
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02087d0c.h"

#define KART_TIRE_COUNT 4

// The object behind the word at 0x20 of a KartModelsEntry: the vectors from 0x48.
typedef struct KartOffsetData {
    /* 00 */ char mTireName[0x10];
    /* 10 */ s32 mFirstTiresScale;
    /* 14 */ Vec3 mTireOffsets[KART_TIRE_COUNT];
    /* 44 */ Vec3 mCharacterOffsets[13];
} KartOffsetData;

// The object behind the word at 0x590 of a Kart from its first byte:
// the halfword at 0x40.
// The object behind the word at 0x54 of a KartModelsEntry.
typedef struct KartTireTranslations {
    union {
        Vec3 mTranslations[KART_TIRE_COUNT];
        struct {
            /* 00 */ s32 mFirstTireX;
            /* 04 */ u8 mUnk_04[8];
            /* 0c */ s32 mSecondTireX;
            /* 10 */ u8 mUnk_10[8];
            /* 18 */ s32 mThirdTireX;
            /* 1c */ u8 mUnk_1c[8];
            /* 24 */ s32 mFourthTireX;
        };
    };
} KartTireTranslations;

// The packed colours of KartModelColorBlend hold three 5-bit channels (red from bit 0).
#define KART_MODEL_COLOR_BLEND_CHANNEL_MASK 0x1f
#define KART_MODEL_COLOR_BLEND_GREEN_SHIFT 5
#define KART_MODEL_COLOR_BLEND_BLUE_SHIFT 10
// mBlendProgress runs 0 to this (1.0 in 20.12 fixed point).
#define KART_MODEL_COLOR_BLEND_PROGRESS_END 0x1000

// Halfwords at 0x6a of a KartModelsEntry: three packed colours (0x00, 0x02, 0x04), per-channel start values and
// differences, and a step at 0x2a.
typedef struct KartModelColorBlend {
    /* 00 */ u16 mDiffColor;
    /* 02 */ u16 mEmiColor;
    /* 04 */ u16 mAmbColor;
    /* 06 */ s16 mDiffStartR;
    /* 08 */ s16 mDiffStartG;
    /* 0a */ s16 mDiffStartB;
    /* 0c */ s16 mDiffDeltaR;
    /* 0e */ s16 mDiffDeltaG;
    /* 10 */ s16 mDiffDeltaB;
    /* 12 */ s16 mEmiStartR;
    /* 14 */ s16 mEmiStartG;
    /* 16 */ s16 mEmiStartB;
    /* 18 */ s16 mEmiDeltaR;
    /* 1a */ s16 mEmiDeltaG;
    /* 1c */ s16 mEmiDeltaB;
    /* 1e */ s16 mAmbStartR;
    /* 20 */ s16 mAmbStartG;
    /* 22 */ s16 mAmbStartB;
    /* 24 */ s16 mAmbDeltaR;
    /* 26 */ s16 mAmbDeltaG;
    /* 28 */ s16 mAmbDeltaB;
    /* 2a */ s16 mBlendProgress;
} KartModelColorBlend;

// Words and halfwords from 0x24 of a KartModelsEntry.
typedef struct CharacterAnimationState {
    /* 00 */ s32 mTurnFrameOffset;
    /* 04 */ BOOL mAnimationChangeTimerSet;
    /* 08 */ s32 mMiddleFrame;
    /* 0c */ s32 mMiddleFrameReciprocal;
    /* 10 */ s16 mAnimationChangeTimer;
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ BOOL mNextAnimationPending;
    /* 18 */ s16 mNextAnimationIndex;
} CharacterAnimationState;

struct Nsbmd;

typedef struct KartModelsEntry {
    /* 000 */ s32 mCharacterIndex;
    /* 004 */ s32 mKartIndex;
    /* 008 */ ModelAnimation *mCharacterAnimation;
    /* 00c */ ModelAnimation *mFaceAnimation;
    /* 10 */ Nsbmd *mModels[3];
    /* 01c */ ShadowModel *mShadowModel;
    /* 020 */ KartOffsetData *mKartOffsetData;
    /* 024 */ CharacterAnimationState mAnimationState;
    /* 040 */ CourseColorBlend mCourseColorBlend;
    /* 052 */ u8 mUnk_052[2];
    /* 054 */ KartTireTranslations *mTireTranslations;
    /* 058 */ s32 mKartModelHidden;
    /* 05c */ s32 mCharacterHidden;
    /* 060 */ BOOL mFarFromCamera;
    /* 064 */ BOOL mStarModelsSet;
    /* 068 */ u16 mVariant;
    /* 06a */ KartModelColorBlend mColorBlend;
    /* 096 */ u8 mUnk_096[2];
    /* 098 */ Unk02087b78 mKillerItemAnimation;
    /* 0ac */ BOOL mFaceAnimationRemoved;
    /* 0b0 */ s32 mRegion;
} KartModelsEntry;

// The item a kart is using: its objects and how they are carried. (replaces the two-line comment above the struct)

// Slots of each row of ItemInUse.mHopHeightHistory (a ring; the mask picks the slot) and how many slots back the
// second row reads.
#define ITEM_IN_USE_HOP_HISTORY_SIZE 0x10
#define ITEM_IN_USE_HOP_HISTORY_MASK 0xf
#define ITEM_IN_USE_HOP_HISTORY_DELAY 6
// Start value and per-frame decrease of ItemInUse.mKartMovementWeights.
#define ITEM_IN_USE_MOVEMENT_WEIGHT_START 0xee1
#define ITEM_IN_USE_MOVEMENT_WEIGHT_DECREASE 0x3d
// The two values of ItemInUse.mObjectHeight (the first for object kind 8).
#define ITEM_IN_USE_OBJECT_HEIGHT_TALL 0xb400
#define ITEM_IN_USE_OBJECT_HEIGHT 0x4333

// Object at 0x58 of a KartItems (that KartItems at 0x0c), passed first to the function pointers in the
// gItemKinds entries: three ItemObject pointers at 0x14, vectors from 0x2c to 0x0e4.
typedef struct ItemInUse {
    /* 000 */ s32 mObjectKind;
    /* 004 */ s32 mItemInfoIndex;
    // ItemUseKind; 5 when nothing is in use. (above mUseKind)
    /* 008 */ s32 mUseKind;
    /* 00c */ struct KartItems *mKartItems;
    /* 010 */ Kart *mKart;
    /* 014 */ ItemObject *mObjects[3];
    // Counts down as objects leave the record. (above mObjectCount)
    /* 020 */ s32 mObjectCount;
    // Set to 10 to start the objects one by one at 8, 4 and 0. (above mObjectStartFramesLeft)
    /* 024 */ s32 mObjectStartFramesLeft;
    /* 028 */ u16 mKartIndex;
    /* 02a */ u8 mUnk_02a[2];
    /* 02c */ MtxFx33 mKartOrientation;
    /* 050 */ Vec3 mKartDrawMatrixPos;
    /* 05c */ Vec3 mKartVelocity;
    /* 068 */ s32 mKartVelocityLength;
    /* 06c */ Vec3 mKartMovement;
    /* 078 */ s32 mBehindDistance;
    /* 07c */ s32 mKartHopHeight;
    /* 080 */ s32 mMovingForward;
    /* 084 */ Vec3 mKartScaleFactorTimesBase;
    /* 090 */ Vec3 mSmoothedDirection;
    /* 09c */ Vec3 mBehindDirection;
    /* 0a8 */ Vec3 mBehindPos;
    /* 0b4 */ Vec3 mSecondBehindPos;
    /* 0c0 */ Vec3 mThirdBehindPos;
    /* 0cc */ s32 mKartMovementWeights[3];
    /* 0d8 */ Vec3 mPreviousBehindDirection;
    /* 0e4 */ s32 mSmoothedHopHeight;
    /* 0e8 */ s32 mObjectHeight;
    /* 0ec */ s32 mHopHeightHistory[2][ITEM_IN_USE_HOP_HISTORY_SIZE];
    /* 16c */ s32 mHopHeightHistoryCount;
    /* 170 */ BOOL mIsActiveItem;
    /* 174 */ u16 mCircleAngle;
    /* 176 */ u16 mCircleAngleSpeed;
    /* 178 */ s32 mCircleRadius;
    /* 17c */ s32 mCircleHopHeight;
    /* 180 */ Vec3 mCircleCenter;
    // Which of three places around the circle each object takes. (above mCircleSlots)
    /* 18c */ u16 mCircleSlots[3];
} ItemInUse;

void DrawItemObjectModel(ItemObject *object, NsbmdModel *model, Vec3 *viewAxis);
void DrawItemPoolWithCallback(ItemPool *pool, void *callbackArg, void (*drawCallback)(void *, void *, void *));
void DrawItemPoolModels(ItemPool *pool, Vec3 *viewAxis);
void *BuildItemObjectMatrix(ItemObject *object, Vec3 *viewAxis);
void RemoveItemInUseObject(ItemInUse *itemInUse, ItemObject *object);
void StartItemInUseObjectCountdown(ItemInUse *itemInUse);
void ReleaseItemInUse(ItemInUse *itemInUse);
s32 ComputeItemThrowBackward(ItemInUse *itemInUse, s32 speed, s32 speedFactor, s32 forwardWeight, Vec3 *outDirection);
s32 ComputeItemThrowForward(ItemInUse *itemInUse, s32 baseSpeed, s32 speedFactor, s32 forwardWeight,
                            Vec3 *outDirection);
void AdvanceItemInUse(ItemInUse *itemInUse);
void StartItemInUse(ItemInUse *itemInUse, HeldItem *heldItem);
BOOL CopyKartToItemInUse(ItemInUse *itemInUse);
void UpdateItemInUseObjects(ItemInUse *itemInUse);
void CollideItemObjects(ItemObject *object, ItemObject *other);
BOOL IsItemObjectNearPoint(ItemObject *object, Vec3 *point, s32 radius);
