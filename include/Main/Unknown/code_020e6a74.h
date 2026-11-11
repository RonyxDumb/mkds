#pragma once

#include "types.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_0217b000.h"

void QueueViewMatrix(void);
void SetNsbmdModelFixedAttributes(NsbmdModel *model);
Vec3 *GetViewTransposeMatrixAxis2(void);
Vec3 *GetViewTransposeMatrixAxis0(void);
MtxFx43 *GetViewTransposeMatrix(void);
MtxFx43 *GetViewRotatedMatrix(void);
