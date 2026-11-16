#pragma once

#include "types.h"
#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_020df48c.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/unk_02158000.h"

void kblock_slowDownStateUpdate(Unk020e005c *koopaBlock);
void kblock_renderAll(void *viewMatrix);
u32 kblock_isKoopaBlock(u32 kind);
s32 kblock_getRouteProgress(Unk020e005c *koopaBlock);
void kblock_loadModel(void);
void kblock_init(Unk020e005c *koopaBlock, CourseMapRow *courseRow);
MapObjectKindData *efbub_setupConfig(void);
MapObjectDrawList *efbub_setupRenderPart(void);
Unk020dfc44 *efbub_setupLogicPart(void);
/* writes the polygon alpha cap (field30 of its effect record), read only by draw routines */
void efbub_render(void *a, MkdEfBubbleObject *bubble, void *c, s32 alpha);
void efbub_globalPreUpdate(void);
void efbub_update(void *a,
                       MkdEfBubbleObject *bubble); /* skipped for objects with mFlags & 4 (parked pool objects) */
void efbub_state0Init(MkdEfBubbleObject *bubble);
void efbub_state0Update(MkdEfBubbleObject *bubble);
