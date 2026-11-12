#pragma once

#include "types.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/MapObjects/wanwan_chain.h"

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
