#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f36d8.h" // ItemKind, ItemInfo

// Element of gItemPools[8]: 0x14c bytes (the size in gItemKinds[8]), handled by AdvanceBouncingItemBox to
// StartBouncingItemBox: the BouncingItemObject part, words at 0x130 and 0x138, the ItemBox at 0x134, a vector
// at 0x13c and a word at 0x148.
typedef struct BouncingItemBox {
    /* 000 */ BouncingItemObject mBouncingItemObject;
    /* 130 */ s32 mThrownForward;
    /* 134 */ ItemBox *mPooledMapObject;
    /* 138 */ s32 mKartIsEntry;
    /* 13c */ Vec3 mMapObjectPos;
    /* 148 */ s32 mScaleRatio;
} BouncingItemBox;

extern struct CourseMapRow gPooledMapObjectRow;

extern const u16 gBouncingItemBoxUntilCourseHitBit;
extern const ItemInfo gItemInfoKiller;
// Default record: its only function pointer is the shared ComputeViewTest hook.
extern const ItemKind gItemKindKiller;

void CreatePooledMapObjects(void);
void StartItemKiller(ItemInUse *itemInUse, HeldItem *heldItem);
void ResetKartActiveItemAfterKiller(s32 kartIndex);
void UpdateBouncingItemBoxTimers(void);
void ReleaseEliminatedKartItems(s32 kartIndex);
void StartBouncingItemBox(BouncingItemBox *box);
void ReleaseBouncingItemBox(BouncingItemBox *box);
void CollideKartWithBouncingItemBox(BouncingItemBox *box, void *kart);
void ResetBouncingItemBox(BouncingItemBox *box);
void AdvanceBouncingItemBoxInUse(ItemInUse *itemInUse, BouncingItemBox *box);
s32 InitBouncingItemBox(ItemInUse *itemInUse, BouncingItemBox *box);
void AdvanceBouncingItemBox(BouncingItemBox *box);
