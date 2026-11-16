#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f36d8.h" // ItemKind, ItemInfo

// Element of it_sItemsets[8]: 0x14c bytes (the size in it_sItemParams[8]), handled by AdvanceBouncingItemBox to
// StartBouncingItemBox: the BouncingItemObject part, words at 0x130 and 0x138, the PooledMapObject at 0x134, a vector
// at 0x13c and a word at 0x148.
typedef struct BouncingItemBox {
    /* 000 */ BouncingItemObject mUnk_000;
    /* 130 */ s32 mThrownForward;
    /* 134 */ PooledMapObject *mPooledMapObject;
    /* 138 */ s32 mKartIsEntry;
    /* 13c */ Vec3 mMapObjectPos;
    /* 148 */ s32 mScaleRatio;
} BouncingItemBox;

extern Vec3 data_0217c748;

extern Vec3 data_0217c73c;

extern struct CourseMapRow gPooledMapObjectRow;

extern const u16 data_0215a584;
extern const ItemInfo it_sKillerConfig;
// Default record: its only function pointer is the shared mobj_calcVisibilityFlags2d hook.
extern const ItemKind it_sKillerDef;

void CreatePooledMapObjects(void);
void StartItemKiller(ItemInUse *itemInUse, HeldItem *heldItem);
void func_0210515c(s32 kartIndex);
void UpdateBouncingItemBoxTimers(void);
void func_02104f84(s32 kartIndex);
void StartBouncingItemBox(BouncingItemBox *box);
void ReleaseBouncingItemBox(BouncingItemBox *box);
void CollideKartWithBouncingItemBox(BouncingItemBox *box, void *a);
void ResetBouncingItemBox(BouncingItemBox *box);
void AdvanceBouncingItemBoxInUse(ItemInUse *itemInUse, BouncingItemBox *box);
s32 InitBouncingItemBox(ItemInUse *itemInUse, BouncingItemBox *box);
void AdvanceBouncingItemBox(BouncingItemBox *box);
