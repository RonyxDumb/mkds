#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/Item/item_objects_and_race_progress.h"

// Target scales (0x1000 = 1.0) of an ItemGesso step: taller than wide when the target velocity Y is above 0, wider than
// tall otherwise except the plain-scale step, a larger scale at the step ITEM_GESSO_STEP_WIDE_SCALE and half size at
// ITEM_GESSO_STEP_HALF_SCALE.
#define ITEM_GESSO_TALL_SCALE_X 0xe66
#define ITEM_GESSO_TALL_SCALE_Y 0x1266
#define ITEM_GESSO_SQUAT_SCALE_X 0x1333
#define ITEM_GESSO_SQUAT_SCALE_Y 0xc29
#define ITEM_GESSO_LARGE_SCALE_X 0x199a
#define ITEM_GESSO_LARGE_SCALE_Y 0x119a
#define ITEM_GESSO_HALF_SCALE 0x800

// Steps of the gItemGessoSteps table, by what the code does at them: the table has ITEM_GESSO_STEP_COUNT rows. Step 2
// and the last step fade the gesso out (mFadesOut); step 4 has the plain scale; WIDE_SCALE and HALF_SCALE set their
// own target scales; a kart that is removed, has the star, respawn-drop or killer effect or keyed placement sends
// steps 4 to 0xc to HALF_SCALE.
#define ITEM_GESSO_STEP_COUNT 0x11
#define ITEM_GESSO_STEP_FADES_OUT_FIRST 2
#define ITEM_GESSO_STEP_PLAIN_SCALE 4
#define ITEM_GESSO_STEP_WIDE_SCALE 0xc
#define ITEM_GESSO_STEP_HALF_SCALE 0xd
// The step after ITEM_GESSO_STEP_HALF_SCALE: its start plays no sound.
#define ITEM_GESSO_STEP_NO_SOUND 0xe
#define ITEM_GESSO_STEP_FADES_OUT_LAST 0x10
// ItemGesso.mShear is kept within plus and minus this.
#define ITEM_GESSO_SHEAR_LIMIT 0x266
// Most ortho quads one kart gets (ItemGesso.mOrthoQuadCounts).
#define ITEM_GESSO_MAX_QUADS_PER_KART 4

// Object of item kind 10, element of gItemPools[10].
typedef struct ItemGesso {
    /* 000 */ ItemObject mItemObject;
    /* 12c */ Kart *mKart;
    /* 130 */ u8 mOrthoQuadCounts[0x8];
    /* 138 */ s32 mStepIndex;
    /* 13c */ Vec3 mViewOffset;
    /* 148 */ s32 mVelocityX;
    /* 14c */ s32 mVelocityY;
    /* 150 */ s32 mUnk_150;
    /* 154 */ s32 mTargetVelocityX;
    /* 158 */ s32 mTargetVelocityY;
    /* 15c */ s32 mUnk_15c;
    /* 160 */ BOOL mEnded;
    /* 164 */ s32 mApproachRate;
    /* 168 */ s32 mDamping;
    /* 16c */ s32 mStepTimer;
    /* 170 */ s32 mDampFrameCount;
    /* 174 */ s32 mTargetScaleX;
    /* 178 */ s32 mTargetScaleY;
    /* 17c */ s32 mUnk_17c;
    /* 180 */ s32 mScaleX;
    /* 184 */ Vec3 mScaleYAndApproachRate;
    /* 190 */ u8 mUnk_190[0x4];
    /* 194 */ s32 mFadesOut;
    /* 198 */ BOOL mVisible;
    /* 19c */ s32 mShear;
    /* 1a0 */ u8 mUnk_1a0[0x14];
} ItemGesso;

// One step of the gesso item's motion: target velocity, approach rate, damping and their frame counts.
typedef struct ItemGessoStep {
    /* 00 */ s16 mTargetVelocityX;
    /* 02 */ s16 mTargetVelocityY;
    /* 04 */ s16 mApproachRate;
    /* 06 */ s16 mDamping;
    /* 08 */ u16 mApproachFrameCount;
    /* 0a */ u16 mDampFrameCount;
} ItemGessoStep;

void CreateItemTeresaFrameScaleTable(void);
void ComputeItemGessoFrameCount(void);
void InitItemGessoFromData(ItemGesso *gesso);
void CopyItemGessoData(void *data, ItemGesso *gesso, void *toData);
void DrawItemGesso(ItemGesso *gesso, s32 unusedSecond, NsbmdModel *model);
void AdvanceItemGesso(ItemGesso *gesso);

typedef struct ItemInUse ItemInUse;
typedef struct ItemGesso ItemGesso;

unsigned int InitItemGesso(ItemInUse *itemInUse, ItemGesso *gesso);

unsigned int SetupItemGesso(ItemGesso *gesso, s32 fromData);
BOOL SetupNextItemGessoStep(ItemGesso *gesso);
void ResetItemGesso(ItemGesso *gesso);

void GessoMarkItemInUseAsActiveItem(ItemInUse *itemInUse);

extern const ItemGessoStep gItemGessoSteps[ITEM_GESSO_STEP_COUNT];
extern s32 gItemGessoFrameCount;
extern u16 *gItemTeresaFrameScales;

extern const ItemKind gItemKindGesso;
extern const ItemInfo gItemInfoGesso;
