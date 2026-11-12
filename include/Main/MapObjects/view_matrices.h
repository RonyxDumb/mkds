#pragma once

#include "types.h"
#include "code_02012b30.h"

void InitMatrices(void);

extern struct MtxFx43 *gViewRotatedMatrix;
extern struct MtxFx43 *gTranslationMatrix;
extern struct MtxFx43 *gViewTransposeMatrix;
extern struct MtxFx43 *gYAxisMatrix;
extern struct MtxFx43 *gViewRotationXMatrix;
extern struct MtxFx43 *gViewMatrix;
extern struct MtxFx33 *gRotationZMatrix;
extern struct MtxFx43 *gViewAxis2Matrix;
