#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020846c0.h" // Nsbmd
#include "Main/Unknown/code_0207adf8.h" // ShadowModel
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02087d0c.h"

// The object behind the word at 0x20 of a KartModelsEntry: the vectors from 0x48.
typedef struct KartOffsetData {
    /* 00 */ char field0[0x10];
    /* 10 */ s32 field10;
    /* 14 */ Vec3 field14[4];
    /* 44 */ u8 field44[4];
    /* 48 */ Vec3 field48[1];
} KartOffsetData;

// The object behind the word at 0x590 of a Kart from its first byte:
// the halfword at 0x40.
// The object behind the word at 0x08 of a KartModelsEntry: the halfword at 0x1a.
typedef struct KartModelAnimationView {
    /* 00 */ u8 field0[2];
    /* 02 */ u16 field2;
    /* 04 */ u8 field4[8];
    /* 0c */ s32 fieldC;
    /* 10 */ u8 field10[8];
    /* 18 */ u16 field18;
    /* 1a */ u16 field1A;
    /* 1c */ s32 **field1C;
} KartModelAnimationView;

// The object behind the word at 0x54 of a KartModelsEntry.
typedef struct Unk0206bcb0_590_54 {
    union {
        Vec3 mUnk_v[4];
        struct {
            /* 00 */ s32 field0;
            /* 04 */ u8 field4[8];
            /* 0c */ s32 fieldC;
            /* 10 */ u8 field10[8];
            /* 18 */ s32 field18;
            /* 1c */ u8 field1C[8];
            /* 24 */ s32 field24;
        };
    };
} Unk0206bcb0_590_54;

// Halfwords at 0x6a of a KartModelsEntry: three packed colours (0x00, 0x02, 0x04), per-channel start values and
// differences, and a step at 0x2a.
typedef struct KartModelColorBlend {
    /* 00 */ u16 mDiffColor;
    /* 02 */ u16 mEmiColor;
    /* 04 */ u16 mAmbColor;
    /* 06 */ s16 field6;
    /* 08 */ s16 field8;
    /* 0a */ s16 fieldA;
    /* 0c */ s16 fieldC;
    /* 0e */ s16 fieldE;
    /* 10 */ s16 field10;
    /* 12 */ s16 field12;
    /* 14 */ s16 field14;
    /* 16 */ s16 field16;
    /* 18 */ s16 field18;
    /* 1a */ s16 field1A;
    /* 1c */ s16 field1C;
    /* 1e */ s16 field1E;
    /* 20 */ s16 field20;
    /* 22 */ s16 field22;
    /* 24 */ s16 field24;
    /* 26 */ s16 field26;
    /* 28 */ s16 field28;
    /* 2a */ s16 mBlendProgress;
} KartModelColorBlend;

// Words and halfwords from 0x24 of a KartModelsEntry.
typedef struct CharacterAnimationState {
    /* 00 */ s32 mTurnFrameOffset;
    /* 04 */ BOOL mAnimationChangeTimerSet;
    /* 08 */ s32 mMiddleFrame;
    /* 0c */ u8 fieldC[4];
    /* 10 */ s16 mAnimationChangeTimer;
    /* 12 */ u8 field12[2];
    /* 14 */ BOOL mNextAnimationPending;
    /* 18 */ s16 mNextAnimationIndex;
} CharacterAnimationState;

struct Nsbmd;

typedef struct KartModelsEntry {
    /* 000 */ s32 mCharacterIndex;
    /* 004 */ s32 mKartIndex;
    /* 008 */ KartModelAnimationView *mCharacterAnimation;
    /* 00c */ KartModelAnimationView *mFaceAnimation;
    /* 10 */ Nsbmd *mModels[3];
    /* 01c */ ShadowModel *mShadowModel;
    /* 020 */ KartOffsetData *mKartOffsetData;
    /* 024 */ s32 mTurnFrameOffset;
    /* 028 */ u8 field28[4];
    /* 02c */ s32 mMiddleFrame;
    /* 030 */ s32 mMiddleFrameReciprocal;
    /* 034 */ u8 field34[0xc];
    /* 040 */ u16 field40;
    /* 042 */ u8 field42[0x12];
    /* 054 */ Unk0206bcb0_590_54 *field54;
    /* 058 */ s32 field58;
    /* 05c */ s32 field5C;
    /* 060 */ BOOL field60;
    /* 064 */ BOOL mStarModelsSet;
    /* 068 */ u16 mVariant;
    /* 06a */ KartModelColorBlend mColorBlend;
    /* 096 */ u8 field96[2];
    /* 098 */ u8 field98[0xc];
    /* 0a4 */ s32 fieldA4;
    /* 0a8 */ u8 fieldA8[4];
    /* 0ac */ BOOL mFaceAnimationRemoved;
    /* 0b0 */ s32 fieldB0;
} KartModelsEntry;

// Three vectors at 0x00, 0x0c and 0x18.
typedef struct {
    /* 00 */ Vec3 field0;
    /* 0c */ Vec3 fieldC;
    /* 18 */ Vec3 field18;
} KartOrientation;
// The item a kart is using: its objects and how they are carried. (replaces the two-line comment above the struct)

// Object at 0x58 of a KartItems (that KartItems at 0x0c), passed first to the function pointers in the
// it_sItemParams entries: three ItemObject pointers at 0x14, vectors from 0x2c to 0x0e4.
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
    /* 02a */ u8 field2A[2];
    /* 02c */ KartOrientation mKartOrientation;
    /* 050 */ Vec3 mKartDrawMatrixPos;
    /* 05c */ Vec3 mKartVelocity;
    /* 068 */ s32 mKartVelocityLength;
    /* 06c */ Vec3 mKartMovement;
    /* 078 */ s32 field78;
    /* 07c */ s32 mKartHopHeight;
    /* 080 */ s32 mMovingForward;
    /* 084 */ Vec3 mKartScaleFactorTimesBase;
    /* 090 */ Vec3 field90;
    /* 09c */ Vec3 mBehindDirection;
    /* 0a8 */ Vec3 mBehindPos;
    /* 0b4 */ Vec3 fieldB4;
    /* 0c0 */ Vec3 fieldC0;
    /* 0cc */ s32 fieldCC[3];
    /* 0d8 */ Vec3 fieldD8;
    /* 0e4 */ s32 fieldE4;
    /* 0e8 */ s32 fieldE8;
    /* 0ec */ s32 fieldEC[2][16];
    /* 16c */ s32 field16C;
    /* 170 */ void *field170;
    /* 174 */ u16 mCircleAngle;
    /* 176 */ u16 mCircleAngleSpeed;
    /* 178 */ s32 mCircleRadius;
    /* 17c */ s32 field17C;
    /* 180 */ Vec3 mCircleCenter;
    // Which of three places around the circle each object takes. (above mCircleSlots)
    /* 18c */ u16 mCircleSlots[3];
} ItemInUse;

void DrawItemObjectModel(ItemObject *object, NsbmdModel *model, Vec3 *viewAxis);
void it_20ED718(ItemPool *pool, void *callbackArg, void (*drawCallback)(void *, void *, void *));
void it_20ED79C(ItemPool *pool, Vec3 *viewAxis);
void *BuildItemObjectMatrix(ItemObject *object, Vec3 *viewAxis);
void RemoveItemInUseObject(ItemInUse *itemInUse, ItemObject *object);
void StartItemInUseObjectCountdown(ItemInUse *itemInUse);
void it_destroyDragItem(ItemInUse *itemInUse);
s32 ComputeItemThrowBackward(ItemInUse *itemInUse, s32 speed, s32 speedFactor, s32 forwardWeight, Vec3 *outDirection);
s32 ComputeItemThrowForward(ItemInUse *itemInUse, s32 baseSpeed, s32 speedFactor, s32 forwardWeight,
                            Vec3 *outDirection);
void AdvanceItemInUse(ItemInUse *itemInUse);
void it_20EE2E4(ItemInUse *itemInUse, HeldItem *heldItem);
BOOL CopyKartToItemInUse(ItemInUse *itemInUse);
void UpdateItemInUseObjects(ItemInUse *itemInUse);
void CollideItemObjects(ItemObject *object, ItemObject *other);
BOOL IsItemObjectNearPoint(ItemObject *object, Vec3 *point, s32 radius);
