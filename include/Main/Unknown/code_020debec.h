#pragma once

#include "types.h"
#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_020de214.h"

void mibox_globalInitLogic(void);
MapObjectKindData *ibox_setupCollision(void);
MapObjectDrawList *ibox_setupBoxRenderPart(void);
MapObjectDrawList *ibox_setupQuestionRenderPart(void);
MapObjectDrawList *ibox_setupShadowRenderPart(void);
MapObjectList *ibox_setupLogicPart(void);
void ibox_applyBoxMaterial(void);
void ibox_renderBox(void *unused0, ItemBox *itemBox, void *unused1, u16 d);
void ibox_applyQuestionMaterial(void);
void ibox_renderQuestion(void *unused0, ItemBox *itemBox, void *unused1, u16 d);
void ibox_globalPreRenderShadow(void);
void ibox_renderShadow(void *unused, ItemBox *itemBox, u32 c, u32 d);
void ibox_update(void *unused, ItemBox *itemBox);
