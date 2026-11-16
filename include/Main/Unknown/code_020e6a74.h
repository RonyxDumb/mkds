#pragma once

#include "types.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_0217b000.h"

void bbm_restoreCameraMtx(void);
void bbm_setDefaultMatParams(NsbmdModel *model);
Vec3 *bbm_getBillboardForwardVec(void);
Vec3 *bbm_getBillboardRightVec(void);
void *bbm_getBillboardMtx(void);
MtxFx43 *bbm_getYBillboardMtx(void);
