/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G3X_InitMtxStack G3X_InitializeMatrixStack
#define G3X_InitTable G3X_InitializeTable
#define G3X_Init G3X_Initialize
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void G3X_ClearFifo();
extern void G3X_InitMtxStack();
extern void G3X_InitTable();
#pragma thumb off
void G3X_Init(){
    G3X_ClearFifo();
    reg_G3_END_VTXS = 0x0;
    while (reg_G3X_GXSTAT & 0x8000000) {} //wait for geometry engine to not be busy
    reg_G3X_DISP3DCNT = 0x0;
    reg_G3X_GXSTAT = 0x0;
    reg_G2_BG0OFS = 0x0;
    reg_G3X_DISP3DCNT |= 0x2000;
    reg_G3X_DISP3DCNT |= 0x1000;
    reg_G3X_DISP3DCNT &= ~0x3002;
    reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~0x3000) | 0x10);
    reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT & (u16)~0x3004);
    reg_G3X_GXSTAT |= 0x8000;
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xC0000000) | 0x80000000;
    G3X_InitMtxStack();
    reg_G3X_CLEAR_COLOR = 0x0;
    reg_G3X_CLEAR_DEPTH = 0x7FFF;
    reg_G3X_CLRIMAGE_OFFSET = 0x0;
    reg_G3X_FOG_COLOR = 0x0;
    reg_G3X_FOG_OFFSET = 0x0;
    reg_G2_BG0CNT &= ~0x3;
    G3X_InitTable();
    reg_G3_POLYGON_ATTR = 0x1F0080;
    reg_G3_TEXIMAGE_PARAM = 0x0;
    reg_G3_TEXPLTT_BASE = 0x0;
}
