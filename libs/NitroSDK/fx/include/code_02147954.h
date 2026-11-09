#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_021479b4.h" // MtxFx44

void MTX_Identity44_(MtxFx44 *dst);
void MTX_Copy44To43_(const s32 *src, MtxFx43 *dst);
