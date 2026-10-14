/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#define GX_SetBankForClearImage func_021493b0
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
#pragma thumb off
void GX_SetBankForClearImage(s32 clearimage){
    gGXState.lcdc = (u16)(~clearimage & (gGXState.lcdc | gGXState.clrImg));
    gGXState.clrImg = (u16)clearimage;
    switch (clearimage)
    {
    case 3:
        reg_GX_VRAMCNT_A = 0x93;
    case 2:
        reg_GX_VRAMCNT_B = 0x9B;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 12:
        reg_GX_VRAMCNT_C = 0x93;
    case 8:
        reg_GX_VRAMCNT_D = 0x9B;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0:
        reg_G3X_DISP3DCNT &= ~0x4000;
        break;
    case 1:
        reg_GX_VRAMCNT_A = 0x9B;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 4:
        reg_GX_VRAMCNT_C = 0x9B;
        reg_G3X_DISP3DCNT |= 0x4000;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
