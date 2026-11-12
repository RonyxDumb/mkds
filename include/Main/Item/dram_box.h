#pragma once

#include "types.h"
#include "Main/Item/held_item.h" // BouncingItemObject
#include "code_02146d78.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Unknown/code_020ffc4c.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020ffdd4.h"
#include "Main/MapObjects/choropu.h" // CollisionMapObject

// Object of InitMissionRunBoxMapObject: 0x144 bytes.
typedef struct MissionRunBox {
    /* 000 */ CollisionMapObject mCollisionMapObject;
} MissionRunBox;

// Object of item kind 7, element of gItemPools[7].
typedef struct ItemFBox {
    /* 000 */ BouncingItemObject mBouncingItemObject;
    /* 130 */ Vec3 mPushDirection;
    /* 13c */ s32 mThrownForward;
    /* 140 */ ItemBox *mPooledMapObject;
} ItemFBox;

void SetupItemFBoxAfterLaunch(ItemFBox *fbox);
s32 ItemFBoxFadeOutCallback(ItemFBox *fbox);
void AdvanceItemFBox(ItemFBox *fbox);
u32 InitItemFBox(ItemInUse *inUse, ItemFBox *fbox);
void AdvanceItemFBoxInUse(ItemInUse *inUse, ItemFBox *fbox);
void StartItemFBox(ItemFBox *fbox);
void ResetItemFBox(ItemFBox *fbox);
void SetItemFBoxPushedDrawMatrix(ItemFBox *fbox, MtxFx43 *out);
void SetItemFBoxDrawMatrix(ItemFBox *fbox, MtxFx43 *out);
void InitMissionRunBoxMapObject(MissionRunBox *object);
BOOL IsMissionRunBoxKind(u32 kind);
MapObjectKindData *CreateMissionRunBoxKindData(void);
void InitDram(Dram *dram, struct CourseMapRow *courseRow);
void CreateDram(void);
