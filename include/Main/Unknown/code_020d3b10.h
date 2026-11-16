#pragma once

#include "types.h"

u16 mobj_getCyclicPolygonId(void);
u16 mobj_getStaticPolygonId(void);
u16 mobj_getInstanceCountWithId(u32 kind);
void mobj_deactivateObjsBeforeCountdown(void);
void mobj_activateObjsAfterCountdown(void);
