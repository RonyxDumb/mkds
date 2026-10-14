/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
#pragma thumb off
void GX_SetBankForSubBGExtPltt(s32 subbgextpltt){
    gGXState.lcdc = (u16)(~subbgextpltt & (gGXState.lcdc | gGXState.sub_bgExtPltt));
    gGXState.sub_bgExtPltt = (u16)subbgextpltt;
    switch (subbgextpltt)
    {
        case 128:
            reg_GXS_DB_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_H = 0x82;
            break;
        case 0:
            reg_GXS_DB_DISPCNT &= ~0x40000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
