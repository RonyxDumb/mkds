#pragma once

#include "types.h"
#include "Main/Unknown/code_020467d0.h" // StateMachine
#include "Main/Unknown/code_020f2dac.h" // BouncingItemObject
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021052fc.h"

struct ModelEffect;

// Object of item kind 9, element of gItemPools[9].
typedef struct ItemBomb {
    /* 000 */ BouncingItemObject mUnk_000;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mReflectFactor;
    /* 138 */ struct ModelEffect *mModelEffect;
    /* 13c */ MtxFx43 mUnk_13c;
    /* 16c */ BOOL mHitSpinsKart;
    /* 170 */ s32 mTimer;
    /* 174 */ s32 mModelFrameTimer;
    /* 178 */ u16 mNearestKartIndex;
    /* 17a */ u8 mUnk_17a[2];
    /* 17c */ s32 mNearestKartDistanceSquared;
    /* 180 */ s32 mTimerEndBlockTimer;
    /* 184 */ StateMachine mStateMachine;
    /* 198 */ ItemBox *mPooledMapObject;
    /* 19c */ s32 mMapObjectOffsetY;
    /* 1a0 */ BOOL mVisible;
} ItemBomb;

void RequestItemBombState1(ItemBomb *bomb);
int RequestItemBombState2(ItemBomb *bomb);
void DrawItemBomb(ItemBomb *bomb, Vec3 *viewAxis, NsbmdModel *model);
void InitItemBombFromData(ItemBomb *bomb);
void *CopyItemBombData(void *cursor, ItemBomb *bomb, void *toData);
void AdvanceItemBomb(ItemBomb *bomb);
void AdvanceItemBombWithMapObject(ItemBomb *bomb, ItemBomb *bombAlias, ItemBox *pooledMapObject);
void ClampItemBombTimerByDistance(ItemBomb *bomb);
void AdvanceItemBombNearestKart(ItemBomb *bomb);
void UpdateItemBombState2(ItemBomb *bomb);
void EnterItemBombState2(ItemBomb *bomb);
void UpdateItemBombState1(ItemBomb *bomb);
