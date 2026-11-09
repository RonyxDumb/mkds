#pragma once

#include "types.h"

// Four rows of four words.
typedef struct MtxFx44 {
    /* 00 */ Vec4 mUnk_00[4];
} MtxFx44;

void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
