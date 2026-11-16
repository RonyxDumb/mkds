#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_objects_and_race_progress.h"

s32 GetTeresaOffsetYDivisor(void);

typedef struct NsbmdModel NsbmdModel;
typedef struct ItemTeresa ItemTeresa;

// Values of ItemTeresa.mItemObjectKind besides a real ItemObjectKind: nothing carried (no model drawn), and an item
// taken that was none or that nobody held.
#define ITEM_TERESA_KIND_EMPTY ITEM_OBJECT_KIND_COUNT
#define ITEM_TERESA_KIND_TOOK_NOTHING ITEM_OBJECT_KIND_NONE
// Value of ItemTeresa.mTakenItemInfoIndex and mGivenItemInfoIndex while no item has arrived; the count is
// ITEM_TERESA_COUNT_NOT_RECEIVED then.
#define ITEM_TERESA_NOT_RECEIVED ITEM_INFO_COUNT
#define ITEM_TERESA_COUNT_NOT_RECEIVED 0xffffffff
// ItemTeresa.mPendingPickedKartIndex while no picked kart was received.
#define ITEM_TERESA_NO_PENDING_PICK 0xffffffff
// Selector of the Teresa packets (SetItemTeresaFromPacket, the third byte AddItemDataItemIdAndBytes sends): the picked
// kart, the state the sender reports, the item taken from the picked kart (item index * 4 + count), and the item given
// back.
#define ITEM_TERESA_PACKET_PICKED_KART 0
#define ITEM_TERESA_PACKET_STATE 1
#define ITEM_TERESA_PACKET_TAKEN_ITEM 2
#define ITEM_TERESA_PACKET_GIVEN_ITEM 3
// Points of the path the Boo follows when it took nothing, and the index it starts from.
#define ITEM_TERESA_PATH_POINT_COUNT 11
#define ITEM_TERESA_PATH_START_INDEX 3
// State frames: the frame of the take-item state at which the dip (drop and rise of the offset) starts, the frames of
// the fade-in at the picked kart after which a Boo without a picked kart gives up, and the frames the Boo may stall
// waiting for the taken item.
#define ITEM_TERESA_DIP_START_FRAME 0x12
#define ITEM_TERESA_NO_PICK_LIMIT_FRAMES 0x6e
#define ITEM_TERESA_STALL_LIMIT_FRAMES 0x3c
// ItemTeresa.mOffsetAccelerationY after the item was taken, going down and then going up.
#define ITEM_TERESA_TAKE_DROP_ACCELERATION (-0x1ae)
#define ITEM_TERESA_TAKE_RISE_ACCELERATION 0x133

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
void UpdateItemTeresaFadeOutEnd(void *stateObject);

void EnterItemTeresaFadeOutEnd(void *stateObject);

void UpdateItemTeresaFadeInAtOwner(void *stateObject);
void EnterItemTeresaFadeInAtOwner(void *stateObject);
void RestoreItemTeresaPosPointer(ItemTeresa *teresa);

void SetItemTeresaPosPointerToDrawPos(ItemTeresa *teresa);

void UpdateItemTeresaWaitDelay(void *stateObject);
void EnterItemTeresaWaitDelay(void *stateObject);
void UpdateItemTeresaTakeItem(void *stateObject);

// ItemTeresa.mPickedKartIndex while no kart is picked (one past the last kart index).
#define ITEM_TERESA_NO_KART ITEM_NO_KART_INDEX

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
    /* 166 */ u8 mLayoutBncl[0x2];
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
void EnterItemTeresaFadeInAtPicked(void *stateObject);
s32 AdvanceItemTeresaFadeIn(ItemTeresa *teresa, s32 shiftAlongCameraSide, s32 nextState);
BOOL AdvanceItemTeresaFadeOut(ItemTeresa *teresa, s32 shiftAlongCameraSide, s32 nextState);
void AdvanceItemTeresaPath(ItemTeresa *teresa);
void EnterItemTeresaFadeOutAtOwner(void *stateObject);
void PlaceItemTeresaAtKart(ItemTeresa *teresa, s32 shiftAlongCameraSide);
void UpdateItemTeresaFadeOutAtOwner(void *stateObject);
void EnterItemTeresaWaitPickedKart(void *stateObject);
void UpdateItemTeresaWaitPickedKart(void *stateObject);
void PickItemTeresaKartBattle(ItemTeresa *teresa, s32 teamIndex);
void PickItemTeresaKartByRank(ItemTeresa *teresa, s32 teamIndex);
void UpdateItemTeresaFadeInAtPicked(void *stateObject);
void AdvanceItemTeresa(ItemTeresa *teresa);
void InitItemTeresa(ItemInUse *inUse, ItemTeresa *teresa);

void EnterItemTeresaTakeItem(void *stateObject);

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
