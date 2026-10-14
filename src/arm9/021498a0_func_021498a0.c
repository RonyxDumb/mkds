/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#define GX_SetBankForBGExtPltt func_021498a0
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
void GX_SetBankForBGExtPltt(s32 bgextpltt){
    gGXState.lcdc = (u16)(~bgextpltt & (gGXState.lcdc | gGXState.bgExtPltt));
    gGXState.bgExtPltt = (u16)bgextpltt;
    switch (bgextpltt)
    {
    case 0x10:
        reg_GX_DISPCNT |= 0x40000000;
        reg_GX_VRAMCNT_E = 0x84;
        break;
    case 0x40:
        reg_GX_DISPCNT |= 0x40000000;
        reg_GX_VRAMCNT_G = 0x8C;
        break;
    case 0x60:
        reg_GX_VRAMCNT_G = 0x8C;
    case 0x20:
        reg_GX_VRAMCNT_F = 0x84;
        reg_GX_DISPCNT |= 0x40000000;
        break;
    case 0:
        reg_GX_DISPCNT &= ~0x40000000;
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
