/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G3X_ResetMtxStack_2 G3X_ResetMatrixStack2
#define G3X_ResetMtxStack G3X_ResetMatrixStack
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void G3X_ResetMtxStack_2();
#pragma thumb off
void G3X_ResetMtxStack(){
    while (reg_G3X_GXSTAT & 0x8000000) {}
    reg_G3X_GXSTAT |= 0x8000;
    reg_G3X_DISP3DCNT |= 0x2000;
    reg_G3X_DISP3DCNT |= 0x1000;
    G3X_ResetMtxStack_2();
    reg_G3_POLYGON_ATTR = 0x1F0080;
    reg_G3_TEXIMAGE_PARAM = 0x0;
    reg_G3_TEXPLTT_BASE = 0x0;
}
