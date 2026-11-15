#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/MapObjects/pendulum.h"

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

extern const MapObjectList gWanwanChainUpdateListData;
extern const MapObjectDrawList gWanwanChainDrawListData;
extern const MapObjectKindData gWanwanChainKindData;
extern MapObjectDrawList *gWanwanChainDrawList;
extern struct NsbmdModel *gWanwanChain;
extern MapObjectList *gWanwanChainUpdateList;
extern struct NsbmdModel *gWanwanKui;
