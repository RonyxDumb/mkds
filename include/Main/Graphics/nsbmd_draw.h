#pragma once

#include "types.h"

typedef struct Nsbmd Nsbmd;
typedef struct NNSG3dRenderObj NNSG3dRenderObj;

void DrawRenderObjWrapper(NNSG3dRenderObj *object);
void DrawNsbmd1Mat1Shp(Nsbmd *nsbmd);

extern void (*const gNsbmdDrawFunctions[2])(void *param_1);
