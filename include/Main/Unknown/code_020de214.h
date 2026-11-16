#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;
typedef struct WanwanChainObject WanwanChainObject;
typedef struct MapObjectList MapObjectList;
typedef struct MapObjectDrawList MapObjectDrawList;
typedef struct MapObjectKindData MapObjectKindData;

void epipe_init(Unk020e43a8 *pipe);
MapObjectKindData *wwchn_setupCollision(void);
MapObjectDrawList *wwchn_setupRenderPart(void);
MapObjectList *wwchn_setupLogicPart(void);
void wwchn_render(void *unused, WanwanChainObject *chainObject, s32 c, u16 d);
void wwchn_update(void *unused, WanwanChainObject *chainObject);
