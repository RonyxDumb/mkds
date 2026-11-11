#pragma once

#include "types.h"

typedef struct PushedObject PushedObject;
typedef struct WanwanChainObject WanwanChainObject;
typedef struct MapObjectList MapObjectList;
typedef struct MapObjectDrawList MapObjectDrawList;
typedef struct MapObjectKindData MapObjectKindData;

void InitEarthenPipe(PushedObject *pipe);
MapObjectKindData *CreateWanwanChainKindData(void);
MapObjectDrawList *CreateWanwanChainDrawList(void);
MapObjectList *CreateWanwanChainUpdateList(void);
void DrawWanwanChain(void *unused, WanwanChainObject *chainObject, s32 unusedValue, u16 maxAlpha);
void UpdateWanwanChain(void *unused, WanwanChainObject *chainObject);
