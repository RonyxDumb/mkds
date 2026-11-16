#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/MapObjects/wanwan_chain.h"
#include "Main/Item/item_koura_w.h" // CourseMapRow
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"

#define ITEM_BOX_SHADOW_MODE_REFRESH_FAILED 2

#define ITEM_BOX_BOX_ALPHA 0x1a
#define ITEM_BOX_QUESTION_ALPHA 0x14
#define ITEM_BOX_BOX_ROTATION_STEPS 0x12c
#define ITEM_BOX_QUESTION_ROTATION_STEPS 0x82

typedef struct ItemBox ItemBox;

void SetItemBoxFramesSinceHitMax(ItemBox *itemBox);

typedef struct Kart Kart;

u8 CollideKartWithItemBox(ItemBox *itemBox, Kart *kart, void *firstResponsePtr, u8 *secondResponsePtr);
u32 GetItemBoxMaxGroupDistance(ItemBox *itemBox);

void StartItemSlotAndEffects(Vec3 *position, Kart *kart, u32 forcedRowHandle, int skipEffects, u32 shortSpin);

void InitGroupItemBoxObjects(void);
MapObjectKindData *CreateItemBoxKindData(void);
MapObjectList *CreateBoxDrawList(void);
MapObjectList *CreateQuestionDrawList(void);
MapObjectList *CreateItemBoxShadowDrawList(void);
MapObjectList *CreateItemBoxUpdateList(void);
void SetupDrawBox(void);
void DrawBox(void *unused0, ItemBox *itemBox, void *unused1, u16 maxAlpha);
void SetupDrawQuestion(void);
void DrawQuestion(void *unused0, ItemBox *itemBox, void *unused1, u16 maxAlpha);
void SetupDrawItemBoxShadow(void);
void DrawItemBoxShadow(void *unused, ItemBox *itemBox, u32 unusedArg, u32 maxAlpha);
void UpdateItemBox(void *unused, ItemBox *itemBox);

void InitGroupItemBox(ItemBox *itemBox, CourseMapRow *row);

extern const u16 gItemBoxHitFlag;
extern const MapObjectList gItemBoxUpdateListData;
extern const MapObjectDrawList gQuestionDrawListData;
extern const MapObjectDrawList gItemBoxShadowDrawListData;
extern const MapObjectDrawList gBoxDrawListData;
extern const MapObjectKindData gItemBoxKindData;
