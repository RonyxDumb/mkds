#pragma once

#include "types.h"
#include "Main/Unknown/code_020a826c.h" // Unk020a826c

// Array of object pointers: pointer to the array and the number of entries (mobj0008_initLogicPart).
typedef struct Unk020a8a6c {
    /* 00 */ Unk020a826c **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
} Unk020a8a6c;

void mobj0008_initLogicPart(Unk020a8a6c *a);
