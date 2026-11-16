#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

MtxFx43 *bbm_20E6B58(Vec3 *position);
MtxFx43 *bbm_20E6B94(Vec3 *position);
MtxFx43 *bbm_getCustomUpAxisBillboardAtPos(Vec3 *position);
void bbm_20E6C0C(void);
MtxFx43 *bbm_getYBillboardAtPosTransformed(Vec3 *position, s32 horizontalFactor, s32 yOffset);
MtxFx43 *bbm_getYBillboardAtPos(Vec3 *position);
MtxFx43 *bbm_getBillboardAtPos(Vec3 *position);
s32 bbm_20E6D34(Vec3 *yAxis, MtxFx43 *matrix);
s32 bbm_setupCustomUpAxisBillboard(Vec3 *yAxis);
void bbm_updateBaseMatrices(MtxFx43 *viewMatrix);
