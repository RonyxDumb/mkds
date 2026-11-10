#pragma once

#include "types.h"
#include "Main/Unknown/code_020ffc4c.h"
#include "Main/Unknown/unk_02158000.h" // MapObjectDrawList

extern MapObjectKindData gMissionRunBoxKindData;

extern MapObjectDrawList *gDramDrawList;

extern MapObjectDrawList data_0215a100;

extern MapObjectList *gDramUpdateList;

extern MapObjectList data_0215a12c;

MapObjectKindData *CreateDramKindData(void);
MapObjectDrawList *CreateDramDrawList(void);
MapObjectList *CreateDramUpdateList(void);
void DrawDram(void *unusedFirst, Dram *dram, void *unusedThird, s32 maxAlpha);
void PickDramAngleChoices(MapObjectList *list);
