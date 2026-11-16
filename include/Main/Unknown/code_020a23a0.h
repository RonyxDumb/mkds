#pragma once

#include "types.h"

typedef struct Kart Kart;

s32 mgcnt_20A23A0(Kart *kart);
void trophy_render(void);
void trophy_update(void);
s32 trophy_FX_MulInline(s32 a, s32 b);
s16 trophy_FX_SinIdx(s32 angle);
void trophy_init(s32 modelIndex, u32 rankIndex);
void trophy_init3d(void);
