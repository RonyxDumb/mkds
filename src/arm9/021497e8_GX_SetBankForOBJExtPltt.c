/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
void GX_SetBankForOBJExtPltt(s32 objextpltt){
    gGXState.lcdc = (u16)(~objextpltt & (gGXState.lcdc | gGXState.objExtPltt));
    gGXState.objExtPltt = (u16)objextpltt;
    switch (objextpltt)
    {
    case 32:
        reg_GX_DISPCNT |= 0x80000000;
        reg_GX_VRAMCNT_F = 0x85;
        break;
    case 64:
        reg_GX_DISPCNT |= 0x80000000;
        reg_GX_VRAMCNT_G = 0x85;
        break;
    case 0:
        reg_GX_DISPCNT &= ~0x80000000;
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
