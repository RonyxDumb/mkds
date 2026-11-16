#pragma once

#include "types.h"
#include "texture_resource_type.h"

u32 NNS_G3dPlttGetRequiredSize(const NNSG3dResTex *pTex);
void NNS_G3dTexReleaseTexKey(NNSG3dResTex *pTex, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key);
