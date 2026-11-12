#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx33
#include "Main/Item/held_item.h" // BouncingItemObject
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/dram.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/MapObjects/choropu.h" // CollisionMapObject
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

extern MtxFx33 gItemFBoxRotation;

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

extern const MapObjectKindData gMissionRunBoxKindData;
extern StateCallbacks gDramStateTable[6];

extern const u16 data_0215a030;
extern const u16 gItemObjectExcludedUntilCourseHitBit;
extern const MapObjectKindDescriptor data_usa_0215a034;
