#pragma once

#include "types.h"

/* creates the pooled object hidden (parks it with mobj_setInvisible); the spawner later takes it with
 * mobj_acquireFreeObject */
void sblln_init(u32 arg0);
