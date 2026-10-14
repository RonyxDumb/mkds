/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#define GX_SetBankForOBJ func_021499b4
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
void GX_SetBankForOBJ(s32 obj){
    gGXState.lcdc = (u16)(~obj & (gGXState.lcdc | gGXState.obj));
    gGXState.obj = (u16)obj;
    switch (obj)
    {
    case 3:
        reg_GX_VRAMCNT_B = 0x8A;
    case 1:
        reg_GX_VRAMCNT_A = 0x82;
    case 0:  //needed to match
        break;
    case 2:
        reg_GX_VRAMCNT_B = 0x82;
        break;
    case 112:
        reg_GX_VRAMCNT_G = 0x9A;
    case 48:
        reg_GX_VRAMCNT_F = 0x92;
    case 16:
        reg_GX_VRAMCNT_E = 0x82;
        break;
    case 80:
        reg_GX_VRAMCNT_G = 0x92;
        reg_GX_VRAMCNT_E = 0x82;
        break;
    case 96:
        reg_GX_VRAMCNT_G = 0x8A;
    case 32:
        reg_GX_VRAMCNT_F = 0x82;
        break;
    case 64:
        reg_GX_VRAMCNT_G = 0x82;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
