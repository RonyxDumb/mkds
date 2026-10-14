/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
#pragma thumb off
void GX_SetBankForSubOBJExtPltt(s32 subobjextpltt){
    gGXState.lcdc = (u16)(~subobjextpltt & (gGXState.lcdc | gGXState.sub_objExtPltt));
    gGXState.sub_objExtPltt = (u16)subobjextpltt;
    switch (subobjextpltt)
    {
        case 256:
            reg_GXS_DB_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_I = 0x83;
            break;
        case 0:
            reg_GXS_DB_DISPCNT &= ~0x80000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
