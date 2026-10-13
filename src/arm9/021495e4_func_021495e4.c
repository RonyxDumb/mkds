/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#define GX_SetBankForTex func_021495e4
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
void GX_SetBankForTex(s32 tex){
    gGXState.lcdc = (u16)(~tex & (gGXState.lcdc | gGXState.tex));
    gGXState.tex = (u16)tex;
    if (tex == 0)
    {
        reg_G3X_DISP3DCNT &= 0x0000CFFE;
    }
    else
    {
        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~0x3000) | 0x1);
        switch (tex)
        {
        case 5:
            reg_GX_VRAMCNT_A = 0x83;
            reg_GX_VRAMCNT_C = 0x8B;
            break;
        case 9:
            reg_GX_VRAMCNT_A = 0x83;
            reg_GX_VRAMCNT_D = 0x8B;
            break;
        case 10:
            reg_GX_VRAMCNT_B = 0x83;
            reg_GX_VRAMCNT_D = 0x8B;
            break;
        case 11:
            reg_GX_VRAMCNT_A = 0x83;
            reg_GX_VRAMCNT_B = 0x8B;
            reg_GX_VRAMCNT_D = 0x93;
            break;
        case 13:
            reg_GX_VRAMCNT_A = 0x83;
            reg_GX_VRAMCNT_C = 0x8B;
            reg_GX_VRAMCNT_D = 0x93;
            break;
        case 8:
            reg_GX_VRAMCNT_D = 0x83;
            break;
        case 12:
            reg_GX_VRAMCNT_D = 0x8B;
        case 4:
            reg_GX_VRAMCNT_C = 0x83;
            break;
        case 14:
            reg_GX_VRAMCNT_D = 0x93;
        case 6:
            reg_GX_VRAMCNT_C = 0x8B;
        case 2:
            reg_GX_VRAMCNT_B = 0x83;
            break;
        case 15:
            reg_GX_VRAMCNT_D = 0x9B;
        case 7:
            reg_GX_VRAMCNT_C = 0x93;
        case 3:
            reg_GX_VRAMCNT_B = 0x8B;
        case 1:
            reg_GX_VRAMCNT_A = 0x83;
            break;
        }
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
