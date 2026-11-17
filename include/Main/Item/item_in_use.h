#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/Graphics/model_animation.h" // ModelAnimation
#include "Main/Kart/shadow_model.h" // ShadowModel
#include "Main/Course/course_color_blend.h" // CourseColorBlend
#include "Main/MapObjects/pendulum.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Graphics/model_animation.h"

#define KART_TIRE_COUNT 4

// The offsets of a kart model: the tire name, the scale of the first tires, the tire offsets and the offsets for each
// character.
typedef struct KartOffsetData {
    /* 00 */ char mTireName[0x10];
    /* 10 */ s32 mFirstTiresScale;
    /* 14 */ Vec3 mTireOffsets[KART_TIRE_COUNT];
    /* 44 */ Vec3 mCharacterOffsets[13];
} KartOffsetData;

// The translations of the four tires of a kart model.
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
// mBlendProgress runs 0 to this (0x1000 = 1.0).
#define KART_MODEL_COLOR_BLEND_PROGRESS_END 0x1000

// The colour fade of a kart model: diffuse, emission and ambient colours, each with a start and the difference to the
// target per channel, and mBlendProgress.
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

// The state of a character animation: the turn frame offset with the middle frame and its reciprocal, the change timer
// and the next animation to play.
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

// The models of one kart and its character: animations, shadow, tire translations, hidden flags and color blends.
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
    /* 054 */ KartTireTranslations *mTireTranslations;
    /* 058 */ s32 mKartModelHidden;
    /* 05c */ s32 mCharacterHidden;
    // TRUE for a kart behind the camera, past the first distance limit, and always for the entry kart; hides the tire
    // material of the body model
    /* 060 */ BOOL mFarFromCamera;
    /* 064 */ BOOL mStarModelsSet;
    /* 068 */ u16 mVariant;
    /* 06a */ KartModelColorBlend mColorBlend;
    /* 098 */ ModelAnimationFrameLoop mKillerItemAnimation;
    /* 0ac */ BOOL mFaceAnimationRemoved;
    /* 0b0 */ s32 mRegion;
} KartModelsEntry;

// Slots of each row of ItemInUse.mHopHeightHistory (a ring; the mask picks the slot) and how many slots back each row
// is read.
#define ITEM_IN_USE_HOP_HISTORY_SIZE 0x10
#define ITEM_IN_USE_HOP_HISTORY_MASK 0xf
#define ITEM_IN_USE_HOP_HISTORY_DELAY 6
// Kart speed (ItemInUse.mKartVelocityLength) below which a bouncing item box that is not thrown forward is dropped with
// no velocity.
#define ITEM_THROW_ZERO_VELOCITY_KART_SPEED 0x1000
// Kart speeds (ItemInUse.mKartVelocityLength) below which a thrown item gets a random offset in x and z of its
// direction, and below which an item thrown backwards from a hop, while its scale.z is below 0xccd, is moved up and
// back from the kart.
#define ITEM_THROW_RANDOM_OFFSET_KART_SPEED 0x3000
#define ITEM_THROW_HOP_OFFSET_KART_SPEED 0x2000
// ItemInUse.mCircleAngleSpeed at the start of a circle item, the value below which the speed still grows, and its
// increase per call.
#define ITEM_IN_USE_CIRCLE_START_SPEED 0x258
#define ITEM_IN_USE_CIRCLE_MAX_SPEED 0x578
#define ITEM_IN_USE_CIRCLE_SPEED_STEP 0x46
// Age (frames) of the first object of an item in use after which its scale grows.
#define ITEM_IN_USE_OBJECT_GROW_AGE 0xc
// Start value of ItemInUse.mKartMovementWeights and the amount it drops each time the trail position is pulled back to
// the largest gap.
#define ITEM_IN_USE_MOVEMENT_WEIGHT_START 0xee1
#define ITEM_IN_USE_MOVEMENT_WEIGHT_DECREASE 0x3d
// The two values of ItemInUse.mObjectHeight (the first for object kind 8).
#define ITEM_IN_USE_OBJECT_HEIGHT_BOUNCING_ITEM_BOX 0xb400
#define ITEM_IN_USE_OBJECT_HEIGHT 0x4333

// ItemInUse.mObjectStartFramesLeft: set to the start value and counted down; one object leaves on each launch frame.
#define ITEM_IN_USE_OBJECT_START_FRAMES 10
#define ITEM_IN_USE_FIRST_LAUNCH_FRAME 8
#define ITEM_IN_USE_SECOND_LAUNCH_FRAME 4
#define ITEM_IN_USE_THIRD_LAUNCH_FRAME 0

// An item a kart is using: its objects, the kart state it follows and the positions it keeps behind the kart.
typedef struct ItemInUse {
    /* 000 */ vs32 mObjectKind;
    /* 004 */ s32 mItemInfoIndex;
    // ItemUseKind; 5 when nothing is in use.
    /* 008 */ s32 mUseKind;
    /* 00c */ struct KartItems *mKartItems;
    /* 010 */ Kart *mKart;
    /* 014 */ ItemObject *mObjects[3];
    // Counts down as objects leave the record.
    /* 020 */ s32 mObjectCount;
    // Set to 10 to start the objects one by one at 8, 4 and 0.
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
    // Which of three places around the circle each object takes.
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

// Indexed by ItemInUse.mUseKind (entry 0 is empty).
extern void (*gItemInUseAdvanceTable[5])(ItemInUse *);
extern void (*gItemInUseRemoveTable[5])(ItemInUse *, s32, ItemObject *);
extern void (*gItemInUseStartTable[5])(ItemInUse *);
