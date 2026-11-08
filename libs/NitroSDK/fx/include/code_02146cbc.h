#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_02146d78.h" // MtxFx33

void MTX_Identity33_(MtxFx33 *dst);
void MTX_Copy33To43_(const MtxFx33 *src, MtxFx43 *dst);
void MTX_Transpose33_(const void *src, void *dst);
void MTX_RotX33_(MtxFx33 *dst, s32 sinVal, s32 cosVal);
void MTX_RotY33_(MtxFx33 *dst, s32 sinVal, s32 cosVal);
void MTX_RotZ33_(MtxFx33 *dst, s32 sinVal, s32 cosVal);
