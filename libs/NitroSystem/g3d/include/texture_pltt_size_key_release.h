#pragma once

#include "types.h"
#include "texture_resource_type.h"

u32 Tex0Block_GetPaletteDataSize(const NNSG3dResTex *pTex);
void Tex0_CleanGetKeys(NNSG3dResTex *pTex, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key);
