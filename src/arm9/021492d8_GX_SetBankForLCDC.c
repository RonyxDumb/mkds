/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define gGXState SDK_data_021802b0
#define GX_VRAMCNT_SetLCDC_ SDK_data_02149dd8
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern struct GX_State gGXState;
extern void GX_VRAMCNT_SetLCDC_(u32 mask);
#pragma thumb off
void GX_SetBankForLCDC(s32 lcdc){
    gGXState.lcdc |= lcdc;
    GX_VRAMCNT_SetLCDC_((u32)lcdc);
}
