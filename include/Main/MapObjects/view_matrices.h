#pragma once

#include "types.h"
#include "model_material_set.h"

void AllocateSomeDtcmBuffers_from_thumb(void);

extern struct MtxFx43 *gViewRotatedMatrix;
extern struct MtxFx43 *gTranslationMatrix;
extern struct MtxFx43 *gViewTransposeMatrix;
extern struct MtxFx43 *gYAxisMatrix;
extern struct MtxFx43 *gViewRotationXMatrix;
extern struct MtxFx43 *gViewMatrix;
extern struct MtxFx33 *gRotationZMatrix;
extern struct MtxFx43 *gViewAxis2Matrix;
