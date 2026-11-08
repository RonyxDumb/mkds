#pragma once

#include "types.h"

typedef struct Unk020ec538 Unk020ec538;
typedef struct WanwanChainObject WanwanChainObject;
typedef struct MapObjectList MapObjectList;
typedef struct MapObjectDrawList MapObjectDrawList;
typedef struct MapObjectKindData MapObjectKindData;

void InitEarthenPipe(Unk020ec538 *pipe);
MapObjectKindData *CreateWanwanChainKindData(void);
MapObjectDrawList *CreateWanwanChainDrawList(void);
MapObjectList *CreateWanwanChainUpdateList(void);
void DrawWanwanChain(void *unused, WanwanChainObject *chainObject, s32 c, u16 d);
void UpdateWanwanChain(void *unused, WanwanChainObject *chainObject);
