#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h" // BouncingItemObject
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021052fc.h"

struct ModelEffect;

// Object of item kind 9, element of it_sItemsets[9].
typedef struct ItemBomb {
    /* 000 */ BouncingItemObject field0;
    /* 130 */ s32 field130;
    /* 134 */ s32 field134;
    /* 138 */ struct ModelEffect *mModelEffect;
    /* 13c */ u8 field13C[0x30];
    /* 16c */ BOOL field16C;
    /* 170 */ s32 mTimer;
    /* 174 */ s32 field174;
    /* 178 */ u16 mNearestKartIndex;
    /* 17a */ u8 field17A[2];
    /* 17c */ s32 mNearestKartDistanceSquared;
    /* 180 */ s32 field180;
    /* 184 */ u8 field184[4];
    /* 188 */ s32 mStateFrames;
    /* 18c */ u8 field18C[6];
    /* 192 */ u16 mState;
    /* 194 */ u16 mNextState;
    /* 196 */ u16 mNextStateRequested;
    /* 198 */ PooledMapObject *mPooledMapObject;
    /* 19c */ s32 mMapObjectOffsetY;
    /* 1a0 */ BOOL mVisible;
} ItemBomb;

void itbomb_20FD83C(ItemBomb *bomb);
int itbomb_20FD8B0(ItemBomb *bomb);
void itbomb_20FD938(ItemBomb *bomb, Vec3 *a, NsbmdModel *model);
void itbomb_20FD9D8(ItemBomb *bomb);
void *itbomb_20FDA50(void *cursor, ItemBomb *bomb, void *toData);
void AdvanceItemBomb(ItemBomb *bomb);
void AdvanceItemBombWithMapObject(ItemBomb *bomb, ItemBomb *bombAlias, PooledMapObject *pooledMapObject);
void ClampItemBombTimerByDistance(ItemBomb *bomb);
void AdvanceItemBombNearestKart(ItemBomb *bomb);
void itbomb_20FDF64(ItemBomb *bomb);
void itbomb_20FE00C(ItemBomb *bomb);
void itbomb_20FE120(ItemBomb *bomb);
