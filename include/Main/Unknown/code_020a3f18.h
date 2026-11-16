#pragma once

#include "types.h"

void blln_init(
    u32 balloon); /* marks the balloon unowned (mUnk_a4 = -1) and parks the pooled object (mobj_setInvisible) */
