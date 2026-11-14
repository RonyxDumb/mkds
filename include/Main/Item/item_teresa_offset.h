#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_in_use.h"
#include "Main/Race/data_020f36d8.h"

s32 GetTeresaOffsetYDivisor(void);

typedef struct NsbmdModel NsbmdModel;
typedef struct ItemTeresa ItemTeresa;

// Values of ItemTeresa.mItemObjectKind besides a real ItemObjectKind: nothing carried (no model drawn), and an item
// taken that was none or that nobody held.
#define ITEM_TERESA_KIND_EMPTY ITEM_OBJECT_KIND_COUNT
#define ITEM_TERESA_KIND_TOOK_NOTHING ITEM_OBJECT_KIND_NONE
// Value of ItemTeresa.mTakenItemInfoIndex and mGivenItemInfoIndex while no item has arrived (the count is -1).
#define ITEM_TERESA_NOT_RECEIVED ITEM_INFO_COUNT

// Values of the ItemTeresa state machine states, which gItemTeresaStateTable follows, and so of
// ItemTeresa.mReportedState. FINISHED is the value after the last state; NONE means nothing reported yet.
enum {
    ITEM_TERESA_STATE_FADE_OUT_AT_OWNER,
    ITEM_TERESA_STATE_WAIT_PICKED_KART,
    ITEM_TERESA_STATE_FADE_IN_AT_PICKED,
    ITEM_TERESA_STATE_TAKE_ITEM,
    ITEM_TERESA_STATE_WAIT_DELAY,
    ITEM_TERESA_STATE_FADE_IN_AT_OWNER,
    ITEM_TERESA_STATE_FADE_OUT_END,
    ITEM_TERESA_STATE_FINISHED,
};
#define ITEM_TERESA_STATE_NONE 0xffffffff

void DrawItemTeresa(ItemTeresa *teresa, s32 unusedValue, NsbmdModel *model);
void SetItemTeresaFromPacket(ItemTeresa *teresa, u32 sel, s32 value);
void InitItemTeresaFromData(ItemTeresa *teresa);
void CopyItemTeresaData(void *cursor, ItemTeresa *teresa, void *toData);
void ResetItemTeresaOwnerActiveItem(ItemTeresa *teresa);
void UpdateItemTeresaState6(ItemTeresa *teresa);

unsigned int EnterItemTeresaState6(unsigned int value);

void UpdateItemTeresaState5(ItemTeresa *teresa);
void EnterItemTeresaState5(ItemTeresa *teresa);
void RestoreItemTeresaPosPointer(ItemTeresa *teresa);

void SetItemTeresaPosPointerToDrawPos(ItemTeresa *teresa);

void UpdateItemTeresaState4(ItemTeresa *teresa);
void EnterItemTeresaState4(ItemTeresa *teresa);
void UpdateItemTeresaState3(ItemTeresa *teresa);

// Object of item kind 11, element of gItemPools[11].
typedef struct ItemTeresa {
    /* 000 */ ItemObject mItemObject;
    /* 12c */ StateMachine mStateMachine;
    /* 140 */ s32 mPickedKartIndex;
// TRUE once the followed kart is hurt or the owner lost the Boo; the Boo then moves on the saved kart velocity.
    /* 144 */ BOOL mFollowEnded;
    /* 148 */ BOOL mPicksAheadFirst;
    /* 14c */ s32 mSavedOffsetY;
    /* 150 */ s32 mSavedOffsetVelocityY;
    /* 154 */ s32 mItemInfoIndex;
    /* 158 */ s32 mItemCount;
    /* 15c */ BOOL mFollowsPath;
    /* 160 */ s32 mItemObjectKind;
    /* 164 */ s16 mItemModelAlpha;
    /* 166 */ u8 mUnk_166[0x2];
    /* 168 */ Kart *mKart;
    /* 16c */ union {
        Vec3 mOffset;
        struct {
            /* 16c */ s32 mOffsetX;
            /* 170 */ s32 mOffsetY;
            /* 174 */ s32 mOffsetZ;
        };
    };
    /* 178 */ s32 mOffsetVelocityX;
    /* 17c */ s32 mOffsetVelocityY;
    /* 180 */ s32 mOffsetVelocityZ;
    /* 184 */ Vec3 mKartDrawMatrixPos;
    /* 190 */ Vec3 mKartVelocity;
    /* 19c */ s32 mOffsetAccelerationY;
    /* 1a0 */ s32 mStartOffsetVelocityY;
    /* 1a4 */ SegmentPoints mPathSegmentPoints;
    /* 248 */ s32 mPointIndex;
    /* 24c */ BOOL mActsLocally;
    /* 250 */ s32 mPendingPickedKartIndex;
    /* 254 */ s32 mTakenItemInfoIndex;
    /* 258 */ s32 mTakenItemCount;
    /* 25c */ s32 mGivenItemInfoIndex;
    /* 260 */ s32 mGivenItemCount;
    /* 264 */ u32 mReportedState;
    /* 268 */ s32 mDelayTimer;
    /* 26c */ BOOL mStalled;
    /* 270 */ s32 mStallFrames;
} ItemTeresa;

s32 RemoveItemTeresaPickedKartItem(ItemTeresa *teresa);
void EnterItemTeresaState2(ItemTeresa *teresa);
s32 AdvanceItemTeresaFadeIn(ItemTeresa *teresa, s32 param_2, s32 param_3);
BOOL AdvanceItemTeresaFadeOut(ItemTeresa *teresa, s32 param_2, s32 param_3);
void AdvanceItemTeresaPath(ItemTeresa *teresa);
void EnterItemTeresaState0(ItemTeresa *teresa);
void PlaceItemTeresaAtKart(ItemTeresa *teresa, s32 param_2);
void UpdateItemTeresaState0(ItemTeresa *teresa);
void EnterItemTeresaState1(ItemTeresa *teresa);
void UpdateItemTeresaState1(ItemTeresa *teresa);
void PickItemTeresaKartBattle(ItemTeresa *teresa, s32 param_2);
void PickItemTeresaKartByRank(ItemTeresa *teresa, s32 param_2);
void UpdateItemTeresaState2(ItemTeresa *teresa);
void AdvanceItemTeresa(ItemTeresa *teresa);
void InitItemTeresa(ItemInUse *inUse, ItemTeresa *teresa);

void EnterItemTeresaState3(ItemTeresa *teresa);

void ResetItemTeresa(ItemTeresa *teresa);
typedef struct ItemInUse ItemInUse;

void TeresaMarkItemInUseAsActiveItem(ItemInUse *itemInUse);

extern const Vec3 gItemTeresaItemOffsets[4];
extern const Vec3 gItemTeresaPathPoints[11];
extern StateCallbacks gItemTeresaStateTable[7];

extern const u16 gItemTeresaPickWeights[8];
extern const u8 gItemTeresaBattleKartOrder[16];
extern const ItemInfo gItemInfoTeresa;

extern const ItemKind gItemKindTeresa;
