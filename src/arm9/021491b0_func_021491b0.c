/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#define GX_SetBankForSubOBJ func_021491b0
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
#pragma thumb off
void GX_SetBankForSubOBJ(s32 subobj){
    gGXState.lcdc = (u16)(~subobj & (gGXState.lcdc | gGXState.sub_obj));
    gGXState.sub_obj = (u16)subobj;
    switch (subobj)
    {
    case 8:
        reg_GX_VRAMCNT_D = 0x84;
        break;
    case 256:
        reg_GX_VRAMCNT_I = 0x82;
        break;
    case 0: //needed to match
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
