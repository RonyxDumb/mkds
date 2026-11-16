#pragma once

#include "types.h"
#include "Main/Unknown/code_020a7000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObjectList

void sanbo_update(void *a, Sanbo *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 sanbo_FX_MulInline(s32 a, s32 b);
s32 sanbo_FX_SinIdx(s32 a);
void sanbo_globalLogicInit(MapObjectList *l);
void sanbo_render(void *a, Sanbo *p);
