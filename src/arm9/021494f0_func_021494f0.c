/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#define GX_SetBankForTexPltt func_021494f0
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
extern struct GX_State gGXState;
#pragma thumb off
void GX_SetBankForTexPltt(s32 texpltt){
    gGXState.lcdc = (u16)(~texpltt & (gGXState.lcdc | gGXState.texPltt));
    gGXState.texPltt = (u16)texpltt;
    switch (texpltt)
    {
    case 0: //needed to match
        break;
    case 96:
        reg_GX_VRAMCNT_G = 0x8B;
    case 32:
        reg_GX_VRAMCNT_F = 0x83;
        break;
    case 112:
        reg_GX_VRAMCNT_G = 0x9B;
    case 48:
        reg_GX_VRAMCNT_F = 0x93;
    case 16:
        reg_GX_VRAMCNT_E = 0x83;
        break;
    case 64:
        reg_GX_VRAMCNT_G = 0x83;
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
