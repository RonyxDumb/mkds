/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#define GX_SetBankForBG func_02149b20
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
void GX_SetBankForBG(s32 bg){
    gGXState.lcdc = (u16)(~bg & (gGXState.lcdc | gGXState.bg));
    gGXState.bg = (u16)bg;
    switch (bg)
    {
    case 8:
        reg_GX_VRAMCNT_D = 0x81;
        break;
    case 12:
        reg_GX_VRAMCNT_D = 0x89;
    case 4:
        reg_GX_VRAMCNT_C = 0x81;
        break;
    case 14:
        reg_GX_VRAMCNT_D = 0x91;
    case 6:
        reg_GX_VRAMCNT_C = 0x89;
    case 2:
        reg_GX_VRAMCNT_B = 0x81;
        break;
    case 15:
        reg_GX_VRAMCNT_D = 0x99;
    case 7:
        reg_GX_VRAMCNT_C = 0x91;
    case 3:
        reg_GX_VRAMCNT_B = 0x89;
    case 1:
        reg_GX_VRAMCNT_A = 0x81;
        break;
    case 11:
        reg_GX_VRAMCNT_A = 0x81;
        reg_GX_VRAMCNT_B = 0x89;
        reg_GX_VRAMCNT_D = 0x91;
        break;
    case 13:
        reg_GX_VRAMCNT_D = 0x91;
    case 5:
        reg_GX_VRAMCNT_A = 0x81;
        reg_GX_VRAMCNT_C = 0x89;
        break;
    case 9:
        reg_GX_VRAMCNT_A = 0x81;
        reg_GX_VRAMCNT_D = 0x89;
        break;
    case 10:
        reg_GX_VRAMCNT_B = 0x81;
        reg_GX_VRAMCNT_D = 0x89;
        break;
    case 112:
        reg_GX_VRAMCNT_G = 0x99;
    case 48:
        reg_GX_VRAMCNT_F = 0x91;
    case 16:
        reg_GX_VRAMCNT_E = 0x81;
        break;
    case 80:
        reg_GX_VRAMCNT_G = 0x91;
        reg_GX_VRAMCNT_E = 0x81;
        break;
    case 96:
        reg_GX_VRAMCNT_G = 0x89;
    case 32:
        reg_GX_VRAMCNT_F = 0x81;
        break;
    case 64:
        reg_GX_VRAMCNT_G = 0x81;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
