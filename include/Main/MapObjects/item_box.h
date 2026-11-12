#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/MapObjects/wanwan_chain.h"
#include "Main/Item/item_koura_w.h" // CourseMapRow

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
