#pragma once

#include "types.h"
#include "Main/MapObjects/wanwan_chain.h"
#include "Main/MapObjects/group_item_box.h"
#include "Main/MapObjects/code_020e005c.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Graphics/model_animation.h"
#include "Main/MapObjects/attractor.h"

void UpdateKoopaBlockState2(KoopaBlock *koopaBlock);
void DrawAllKoopaBlocks(void *viewMatrix);
BOOL IsKoopaBlockKind(u32 kind);
s32 GetKoopaBlockProgress(KoopaBlock *koopaBlock);
void CreateKoopaBlock(void);
void InitKoopaBlock(KoopaBlock *koopaBlock, CourseMapRow *courseRow);
MapObjectKindData *CreateMkdEfBubbleKindData(void);
MapObjectList *CreateMkdEfBubbleDrawList(void);
MapObjectList *CreateMkdEfBubbleUpdateList(void);
/* writes the polygon alpha cap (mAlphaCap of its mShadowMatrix), read only by draw routines */
void DrawMkdEfBubble(void *unused0, MkdEfBubbleObject *bubble, void *unused1, s32 alpha);
void AdvanceMkdEfBubbleAnimation(void);
void UpdateMkdEfBubble(void *unused,
                       MkdEfBubbleObject *bubble); /* skipped for objects with mFlags & 4 (parked pool objects) */
void EnterMkdEfBubbleState0(MkdEfBubbleObject *bubble);
void UpdateMkdEfBubbleState0(MkdEfBubbleObject *bubble);

extern StateCallbacks gKoopaBlockStateTable[3];

extern struct Nsbmd *gMkdEfBubble;
extern MkdEfBubbleUpdateList *gMkdEfBubbleUpdateList;
extern struct Nsbmd *gKoopaBlock;
extern MapObjectDrawList *gMkdEfBubbleDrawList;
extern struct ModelAnimation *gMkdEfBubbleNsbta;

extern const u16 gMkdEfBubbleState1Flag;
extern const u16 gMkdEfBubbleState1SecondFlag;
extern const MkdEfBubbleUpdateList gMkdEfBubbleUpdateListData;
extern const MapObjectDrawList gMkdEfBubbleDrawListData;
extern const MapObjectKindData gMkdEfBubbleKindData;
