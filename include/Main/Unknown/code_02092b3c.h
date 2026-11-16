#pragma once

#include "types.h"

typedef struct Unk020919e8 Unk020919e8;
typedef struct MapObjectList MapObjectList;

void baspw_setupLogicPart(void);
void baspw_update(void *a, Unk020919e8 *p);
s16 baspw_FX_CosIdx(s32 angle);
s32 baspw_FX_TRUNC_MUL(s32 a, s32 b);
s16 baspw_FX_SinIdx(s32 angle);
void baspw_globalInitLogic(MapObjectList *mapObjectList);
void baspw_init(u32 arg0);
