#pragma once

#include "types.h"

void blln_init(
    u32 balloon); /* marks the balloon unowned (fieldA4 = -1) and parks the pooled object (mobj_setInvisible) */
